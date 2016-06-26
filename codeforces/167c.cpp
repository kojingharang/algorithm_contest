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
#include <numeric>
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
	string A, B;
	cin>>A>>B;
	
	VI hB(26);
	REP(i, B.size()) {
		hB[B[i]-'a']++;
	}
	cout<<hB<<endl;
	
	ll ans=0;
	for(int i0=0;i0<A.size();i0++) {
		for(int i1=i0;i1<A.size();i1++) {
			VI hA(26);
			for(int j=i0;j<=i1;j++) {
				hA[A[j]-'a']++;
			}
			//string s(A.substr(i0, i1-i0+1));
			//if(used[s]) continue;
			cout<<A.substr(i0, i1-i0+1)<<endl;
			//cout<<hA<<endl;
			ll lans = 1;
			REP(i, 26) {
				lans = (lans * comb(hB[i], hA[i])) % MOD;
			}
			ans = (lans + ans) % MOD;
			cout<<"lans "<<lans<<" "<<ans<<endl;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
