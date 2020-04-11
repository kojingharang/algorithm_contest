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
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define VVVI vector<vector<vector<ll>>>
#define VVVVI vector<vector<vector<vector<ll>>>>
#define REP(i,n) for(ll i=0,_n=(n);(i)<(ll)_n;++i)
#define REPR(i,n) for(ll i=(ll)(n)-1;0<=(i);--i)
#define RANGE(i,a,b) for(ll i=(ll)a,_b=(ll)(b);(i)<_b;++i)
#define RANGER(i,a,b) for(ll i=(ll)(b)-1,_a=(ll)(a);(_a)<=i;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
#define FI first
#define SE second
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}

#define MOD 1000000007LL
#define INF (1LL<<60)

bool match(char a, char b) {
	return a=='?' || b=='?' || a==b;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string a, b, c;
	while(cin>>a>>b>>c) {
		ll A = a.size();
		ll B = b.size();
		ll C = c.size();
		// exist -> aに対してbを右方向にoffsetずらしたときに置けないときはNG
		ll M=50000;
		ll offset=M/2;
		vector<bool> ab(M), ac(M), bc(M);
		REP(ai, A) REP(bi, B) if(!match(a[ai], b[bi])) ab[ai-bi+offset]=1;
		REP(ai, A) REP(ci, C) if(!match(a[ai], c[ci])) ac[ai-ci+offset]=1;
		REP(bi, B) REP(ci, C) if(!match(b[bi], c[ci])) bc[bi-ci+offset]=1;
		ll ans = 1LL<<60;
		RANGE(bi, -B-C, A+C+1) RANGE(ci, -B-C, A+B+1) {
			ll abi = bi+offset;
			ll aci = ci+offset;
			ll bci = ci-bi+offset;
			bool ok = IN(abi, 0, M) && !ab[abi] && IN(aci, 0, M) && !ac[aci] && IN(bci, 0, M) && !bc[bci];
			if(ok) {
//				cout<<bi<<" "<<ci<<endl;
				ll L = min({0LL, bi, ci});
				ll R = max({A, bi+B, ci+C});
				minUpdate(ans, R-L);
			}
		}
		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}
