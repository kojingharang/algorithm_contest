#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
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
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

#define MOD 1000000007LL
#define INF (1LL<<60)

string S;
ll NN;

map<pair<ll, pair<ll, pair<ll, ll> > >, ll> memo;

// prev 0 or 1
ll f(ll N, ll A, ll B, ll prev) {
	pair<ll, pair<ll, pair<ll, ll> > > key = MP(N, MP(A, MP(B, prev)));
	
	//cout<<A<<" "<<B<<" "<<prev<<endl;
	int TB = 1; // A is written
	if(A<B) {swap(A, B);TB=0;} // B is written
	
	if(A<0 || B<0) return 0;
	if(N==1) {
		S[0]='T';
		if(A==1 && B==1) {
			//cout<<"OK!"<<endl;
			return 0;
		}
		return -INF;
	}
	if(memo.count(key)) return memo[key];
	
	ll a = A-B;
	ll b = B;
	if(TB==0) swap(a, b);
	S[N-1] = TB ? 'T' : 'B';
	return memo[key] = (prev==TB) + f(N-1, a, b, TB);
}

int icount(const string& s) {
	int co=0;
	REP(i, s.size()) {
		if(i==0) continue;
		co += s[i]==s[i-1];
	}
	return co;
}
int main() {
	ll N, R;
	while(cin>>N>>R) {
		NN=N;
		memo = map<pair<ll, pair<ll, pair<ll, ll> > >, ll>();
		S=string(N, '.');
		string ansS;
		//cout<<"=================="<<endl;
		ll ans = INF;
		ll minI = -1;
		for(int i=1; i<R; i++) {
			ll r = f(N, R, i, -1);
			if(r>=0) {
				//cout<<"OK "<<i<<" "<<r<<endl;
				if(r < ans) {
					ans = r;
					ansS = S;
					minI = i;
				}
			}
		}
		memo = map<pair<ll, pair<ll, pair<ll, ll> > >, ll>();
		f(N, R, minI, -1);
		if(ans==INF) cout<<"IMPOSSIBLE"<<endl;
		else {
			string invS(ansS);
			for(int i=1;i<invS.size();i++) invS[i]=invS[i]=='T'?'B':'T';
			if(icount(invS) < icount(ansS)) ansS=invS;
			//cout<<icount(ansS)<<endl;
			cout<<ans<<endl;
			cout<<ansS<<endl;
		}
	}
	
	return 0;
}
