#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <functional>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

#define MOD 1000000007LL
#define INF (1LL<<60)

/*
100 100
1000 950 900
1000  50
950   50
900   800
*/

map<tuple<int, int, int, int>, ll> memo;
ll naive(int zi, int wi, const VI& d, int idx, int turn) {
//	auto key = make_tuple(zi, wi, idx, turn);
	auto key = make_tuple(0, 0, idx, turn);
	if(memo.count(key)) return memo[key];

	ll N = d.size();
	if(idx>=N) return abs(d[zi]-d[wi]);

	ll ans = turn==0 ? 0 : 1LL<<60;
	RANGE(i, idx, N) {
		ll rest = naive(turn==0 ? i : zi, turn==0 ? wi : i, d, i+1, 1-turn);
		if(turn==0) ans = max(ans, rest);
		if(turn==1) ans = min(ans, rest);
	}
//	cout<<"NAIVE "<<zi<<" "<<wi<<" "<<idx<<" "<<turn<<" -> "<<ans<<endl;
	return memo[key] = ans;
}

ll f(int zi, int wi, const VI& d, int idx, int turn) {
	ll N = d.size();
	if(N==3) return abs(d[N-1]-d[wi]);
	else return max(abs(d[N-1]-d[N-2]), abs(d[N-1]-d[wi]));

	ll ans = 0;
	RANGE(zi1, N-2, N) {
		ll wans = 1LL<<60;
		if(zi1==N-1) {
			ll w = d[wi];
			ll z = d[zi1];
			wans = min(wans, abs(w-z));
		}
		RANGE(wi1, zi1+1, N) {
			ll w = d[wi1];
			ll z = 0;
			if(wi1+1==N) {
				z = d[zi1];
				wans = min(wans, abs(w-z));
			} else {
				RANGE(j, wi1+1, N) {
					z = d[j];
					wans = min(wans, abs(w-z));
				}
			}
		}
//		DD(zi1);
//		DD(wans);
		ans = max(ans, wans);
	}
	return ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	if(0)
	{
		REP(loop, 100) {
			ll z = UNIFORM_LL(1, 1000000000);
			ll w = UNIFORM_LL(1, 1000000000);
			ll N = UNIFORM_LL(1, 2000);
			VI d(N);
			REP(i, N) d[i] = UNIFORM_LL(1, 1000000000);
			DD(N);
			DD(d);
			memo.clear();
			ll ref = naive(0, 1, d, 2, 0);
			ll ans = f(0, 1, d, 2, 0);
			DD(ref);
			DD(ans);
			DD(memo.size());
			assert(ref==ans);
		}
		return 0;
	}
	ll N,Z,W;
	while(cin>>N>>Z>>W) {
		VI d(N+2);
		d[0] = Z;
		d[1] = W;
		REP(i, N) cin>>d[i+2];
		memo.clear();
//		DD(naive(0, 1, d, 2, 0));
//		ll ref = naive(0, 1, d, 2, 0);
		ll ans = f(0, 1, d, 2, 0);
//		cout<<ref<<endl;
		cout<<ans<<endl;
	}
	
	return 0;
}
