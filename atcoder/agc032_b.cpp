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

void dfs(ll prev, ll cur, VVI& g, VI& vis) {
	vis[cur]=1;
	for(auto nxt : g[cur]) if(nxt!=prev && !vis[nxt]) dfs(cur, nxt, g, vis);
};
bool connect(VVI& g) {
	ll N = g.size();
	VI vis(N);
	dfs(-1, 0, g, vis);
//	DD(vis);
	return 0 < *min_element(ALL(vis));
}

bool adjSum(const VVI& g) {
	ll N = g.size();
	VI rv(N);
	REP(i, N) rv[i] = accumulate(ALL(g[i]), 0LL) + g[i].size();
	REP(i, N) if(rv[i]!=rv[0]) return false;
//	DD(rv);
	return true;
}

void test(ll N) {
	ll M = (N-1)*N/2;
	REP(bi, 1<<M) {
		VVI g(N);
		ll si = 0;
		REP(i, N) RANGE(j, i+1, N) {
			if(bi>>si&1) {
				g[i].PB(j);
				g[j].PB(i);
			}
			si++;
		}
//		DD(g);
		if(connect(g) && adjSum(g)) {
			DD("ok");
			DD(N);
			DD(g);
		}
	}
}

VVI mk(ll n) {
//	DD(n);
	VVI g(n);
	if(n&1) {
		REP(i, n) {
			VI w;
			if(i==n-1) REP(i, n-1) w.PB(i);
			else REP(j, n) if(j!=i && j!=n-2-i) w.PB(j);
			REP(j, w.size()) g[i].PB(w[j]);
		}
	} else {
		REP(i, n) {
			VI w;
			REP(j, n) if(j!=i && j!=n-1-i) w.PB(j);
			REP(j, w.size()) g[i].PB(w[j]);
		}
	}
//	DD(g);
	if(connect(g) && adjSum(g)) {
//		DD("ok");
		ll M = 0;
		REP(i, n) M += g[i].size();
		cout<<M/2<<endl;
		REP(i, n) REP(j, g[i].size()) if(i<g[i][j]) cout<<i+1<<" "<<g[i][j]+1<<endl;
	} else {
//		DD("BAD");
		assert(false);
	}
	return g;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
//	RANGE(n, 3, 10) test(n);
//	return 0;
//	RANGE(n, 3, 101) mk(n);

	ll N;
	while(cin>>N) {
		mk(N);
	}
	
	return 0;
}
