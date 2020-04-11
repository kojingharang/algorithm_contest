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
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define REPR(i,n) for(int i=(int)(n)-1;0<=(i);--i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define RANGER(i,a,b) for(int i=(int)(b)-1,_a=(int)(a);(_a)<=i;--i)
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

/*
*/
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,Q;
	string S,T,D;
	while(cin>>N>>Q>>S) {
//		DD("---");	
		VI t(Q), d(Q); // d:L->1
		REP(i, Q) {
			cin>>T>>D;
			t[i] = T[0]-'A';
			d[i] = D[0]=='L';
		}
		VI rng(2);
		REP(mode, 2) {
			// mode==1 : lo -> out hi -> in
			ll lo=-1, hi=N;
//			DD(mode);
			while(lo+1<hi) {
				ll mid = (lo+hi)/2;
				ll idx = mid;
//				DD(idx);DD(lo);DD(hi);
				assert(0<=idx&&idx<N);
				ll out=0;
				REP(qi, Q) {
					if(t[qi]==S[idx]-'A') {
						if(d[qi]==mode && idx==(mode?0:N-1)) {out=1;break;}
						idx += d[qi] ? -1 : 1;
//						DD(idx);
					}
				}
//				DD(out);
				if(mode==1) {
					if(out) lo=mid; else hi=mid;
				} else {
					if(out) hi=mid; else lo=mid;
				}
			}
			rng[mode] = mode==1 ? lo : hi;
		}
//		DD(rng);
		ll ans = 0;
		RANGE(i, rng[1]+1, rng[0]) ans++;
		cout<<ans<<endl;
	}
	
	return 0;
}
