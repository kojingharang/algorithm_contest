#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>
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
string YN(bool v) { return v ? "Yes":"No"; }
void uniq(VI& es) { sort(ALL(es)); es.erase(unique(ALL(es)), es.end()); }

#define INF (1LL<<60)

ll f(ll n) {
	if(n==0) return 0;
	ll pc = POPCOUNTLL(n);
	return 1 + f(n % pc);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	string X;
	while(cin>>N>>X) {
		ll refPC = 0;
		REP(i, N) if(X[i]=='1') refPC++;
//		DD(refPC);
		// X % pc
		VI refMod(2);
		REP(i, 2) {
			ll pc = i==0 ? refPC-1 : refPC+1;
			if(pc<=0) continue;
			ll v = 1 % pc;
			ll t = 0;
			REP(j, N) {
				if(X[N-1-j]=='1') t=(t+v)%pc;
				v = (v*2)%pc;
			}
			refMod[i] = t;
		}
		VVI m(2, VI(N));
		REP(i, 2) {
			ll pc = i==0 ? refPC-1 : refPC+1;
			if(pc<=0) continue;
			REP(j, N) {
				if(j==0) {
					m[i][N-1-j] = 1 % pc;
				} else {
					m[i][N-1-j] = (m[i][N-1-(j-1)]*2)%pc;
				}
			}
		}
//		DD(refMod);
//		DD(m);
		REP(i, N) {
			ll ans=0;
			if(X[i]=='1') {
				ll pc = refPC-1;
				if(pc==0) ans=0;
				else ans = 1+f((refMod[0]-m[0][i]+pc)%pc);
			} else {
				ll pc = refPC+1;
				ans = 1+f((refMod[1]+m[1][i]+pc)%pc);
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
