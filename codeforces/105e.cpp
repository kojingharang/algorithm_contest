#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(ll i=0,_n=(n);(i)<(int)_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

#define MOD 1000000007LL
#define MAXN 100003
int dp[1024][1024];
int b[MAXN];

int lucky(ll x) {
	for(;x>0;x/=10) if(x%10!=4 && x%10!=7) return 0;
	return 1;
}

ll modpow(ll v, int p) {
	//cout<<"modpow "<<v<<" "<<p<<endl;
	if(p==1) return v;
	ll vv = modpow(v, p/2);
	vv = (vv * vv) % MOD;
	if(p&1) vv = (vv * v) % MOD;
	return vv;
}

ll comb(int n, int k) {
	ll c=1;
	for(int i=1;i<=k;i++) {
		c = (c * (n-i+1)) % MOD;
		c = (c * modpow(i, MOD-2)) % MOD;
		//cout<<i<<" "<<modpow(i, MOD-2)<<endl;
	}
	//cout<<"comb "<<n<<" "<<k<<" "<<c<<endl;
	return c;
}

int main() {
	int N,K;
	cin>>N>>K;
	memset(dp, 0, sizeof(dp));
	
	map<ll, int> hi;
	VI lu;
	int rest=0;
	REP(i, N) {
		int v;
		//cin>>v;
		scanf("%d",&v);
		if(lucky(v)) {
			if(hi[v]==0) lu.PB(v);
			hi[v]++;
		}
		else rest++;
	}
	//cout<<lu<<endl;
	//cout<<hi<<endl;
	int nl=hi.size();
	//cout<<"nl "<<nl<<endl;
	
	dp[0][0] = 1;
	for(int y=1;y<=nl;y++) {
		dp[y][0] = 1;
		for(int x=1;x<=nl;x++) {
			dp[y][x] = ( dp[y-1][x] + ((ll)dp[y-1][x-1] * hi[lu[y-1]])%MOD ) % MOD;
		}
	}
	//cout<<"dp"<<endl;
	//REP(y, nl+1) {
	//	REP(x, nl+1) cout<<dp[y][x]<<" ";
	//	cout<<endl;
	//}
	//cout<<"dp end"<<endl;
	
	b[0]=1;
	for(int i=1;i<=rest;++i){
		b[i]=1LL*b[i-1]*(rest-i+1)%MOD*modpow(i, MOD-2)%MOD;
	}
	//for(int i=1;i<=rest;++i) {
	//	int tr  = b[i];
	//	int ref = comb(rest, i);
	//	if(tr!=ref) cout<<i<<" "<<tr<<" "<<ref<<endl;
	//}
	
	
	ll ans = 0;
	REP(i, nl+1) {
		int lrest = K-i;
		if(lrest < 0 || rest < lrest ) continue;
		//cout<<"+ lucky use "<<i<<" "<<comb(rest, K-i) << " "<<dp[nl][i]<<endl;
		//ans += comb(rest, lrest) * dp[nl][i];
		ans += (ll)b[lrest] * dp[nl][i];
		ans = ans % MOD;
	}
	cout<<ans<<endl;
	
	return 0;
}
