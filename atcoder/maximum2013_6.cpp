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
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

typedef ll Weight;
struct EdgeWC {
	int src, dst;
	int cap;
	Weight weight;
	EdgeWC(int src, int dst, int cap, Weight weight) :
		src(src), dst(dst), cap(cap), weight(weight) { }
};
bool operator < (const EdgeWC &e, const EdgeWC &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<EdgeWC> EdgesWC;
typedef vector<EdgesWC> GraphWC;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

#define RESIDUE(u,v) (capacity[u][v] - flow[u][v])
#define RCOST(u,v) (cost[u][v] + h[u] - h[v])
pair<Weight, Weight> minimumCostFlow(const GraphWC &g, int s, int t) {
  const int n = g.size();
  Matrix capacity(n, Array(n)), cost(n, Array(n)), flow(n, Array(n));
  REP(u,n) FOR(e,g[u]) {
    capacity[e->src][e->dst] += e->cap;
    cost[e->src][e->dst] += e->weight;
  }
  pair<Weight, Weight> total; // (cost, flow)
  vector<Weight> h(n);

  for (Weight F = INF; F > 0; ) { // residual flow
    vector<Weight> d(n, INF); d[s] = 0;
    vector<int> p(n, -1);
    priority_queue<EdgeWC> Q; // "e < f" <=> "e.cost > f.cost"
    for (Q.push(EdgeWC(-2, s, 0, 0)); !Q.empty(); ) {
      EdgeWC e = Q.top(); Q.pop();
      if (p[e.dst] != -1) continue;
      p[e.dst] = e.src;
      FOR(f, g[e.dst]) if (RESIDUE(f->src, f->dst) > 0) {
        if (d[f->dst] > d[f->src] + RCOST(f->src, f->dst)) {
          d[f->dst] = d[f->src] + RCOST(f->src, f->dst);
          Q.push( EdgeWC(f->src, f->dst, 0, d[f->dst]) );
        }
      }
    }
    if (p[t] == -1) break;

    Weight f = F;
    for (int u = t; u != s; u = p[u])
      f = min(f, RESIDUE(p[u], u));
    for (int u = t; u != s; u = p[u]) {
      total.first += f * cost[p[u]][u];
      flow[p[u]][u] += f; flow[u][p[u]] -= f;
    }
    F -= f;
    total.second += f;
    REP(u, n) h[u] += d[u];
  }
  return total;
}

void add_edge(GraphWC& g, int s, int e, int cap, Weight w) {
	g[s].push_back(EdgeWC(s, e, cap,  w));
	g[e].push_back(EdgeWC(e, s, 0,   -w));
}
//#undef RESIDUE(u,v)
//#undef RCOST(u,v)

struct Ma {
	ll P, X, Y;
};

bool operator<(const Ma& a, const Ma& b) {
	return a.P < b.P;
}


int main() {
	//ios::sync_with_stdio(false);
	ll N, M;
	while(cin>>N>>M) {
		string s;
		VI kx(N), ky(N);
		vector<Ma> ma(M);
		REP(i, N) {
			cin>>s>>kx[i]>>ky[i];
		}
		REP(i, M) {
			cin>>s>>ma[i].P>>ma[i].X>>ma[i].Y;
		}
		sort(ALLR(ma));
		int MM = min(N, M);
		while(MM+1<=M && ma[MM-1].P==ma[MM].P) MM++;
//		REP(mi, M) {
//			cout<<ma[mi].P<<endl;
//		}
//		cout<<"MM "<<MM<<endl;
		GraphWC g(2+N+MM);
		int S=N+MM;
		int E=S+1;
		REP(ni, N) {
			add_edge(g, S, ni, 1, 0);
		}
		REP(mi, MM) {
//			cout<<ma[mi].P<<endl;
			add_edge(g, N+mi, E, 1, 0);
		}
		REP(ni, N) REP(mi, MM) {
			ll cost = abs(kx[ni]-ma[mi].X) + abs(ky[ni]-ma[mi].Y);
			add_edge(g, ni, N+mi, 1, cost);
		}
		pair<Weight, Weight> ret = minimumCostFlow(g, S, E);
//		cout<<ret<<endl;
		cout<<ret.first<<endl;
	}
	
	return 0;
}
