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

// g[i][j] = MP(adj, cost) ... edge(i, adj) with cost
// S -> E までの最小コストを返す. 負閉路がある場合は minusLoop を返す.
ll BellmanFord(const vector<vector<PII>>& g, ll S, ll E, ll minusLoop) {
	ll N = g.size();
	VI p(N, INF);
	p[S] = 0;
	auto relax = [&]() {
		bool upd = false;
		REP(i, N) if(p[i] < INF) {
			REP(j, g[i].size()) {
				ll adj = g[i][j].FI;
				ll cost = g[i][j].SE;
				if(p[i]+cost < p[adj]) {
					p[adj] = p[i]+cost;
					upd = true;
				}
			}
		}
		return upd;
//		DD(p);
	};
	REP(loop, N-1) relax();
	return relax() ? minusLoop : p[E];
}

void dfs(ll cur, const VVI& g, VI& vis) {
	ll N = g.size();
	vis[cur] = 1;
	REP(i, g[cur].size()) {
		ll nxt = g[cur][i];
		if(!vis[nxt]) dfs(nxt, g, vis);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,M,P,A,B,C;
	while(cin>>N>>M>>P) {
		vector<vector<PII>> g(N);
		VVI fg(N), rg(N);
		REP(i, M) {
			cin>>A>>B>>C;
			A--;B--;
			g[A].PB(MP(B, P-C));
			fg[A].PB(B);
			rg[B].PB(A);
		}
		VI fvis(N), rvis(N);
		dfs(0, fg, fvis);
		dfs(N-1, rg, rvis);
		VI reach(N);
		REP(i, N) reach[i] = fvis[i] & rvis[i];
		vector<vector<PII>> gg(N);
		REP(i, N) if(reach[i]) {
			REP(j, g[i].size()) if(reach[g[i][j].FI]) {
				gg[i].PB(g[i][j]);
			}
		}
//		DD(fvis);
//		DD(rvis);
//		DD(g);
//		DD(gg);
		ll ans = BellmanFord(gg, 0, N-1, -INF);
		ans = ans==-INF ? -1 : max(0LL, -ans);
		cout<<ans<<endl;
	}
	
	return 0;
}
