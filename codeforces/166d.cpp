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

/////////////////////// minimumCostFlow
#define INF 1000000
typedef int Weight;
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

void add_edge(GraphWC& g, int s, int e, int cap, int w) {
	g[s].push_back(EdgeWC(s, e, cap,  w));
	g[e].push_back(EdgeWC(e, s, 0,   -w));
}
#undef RESIDUE
#undef RCOST
/////////////////////// minimumCostFlow

#define inf 2000000000

int main() {
	int N,M;
	cin>>N;
	vector<PII> S(N);
	REP(i, N) {
		cin>>S[i].second>>S[i].first;
	}
	sort(ALL(S));
	cin>>M;
	cout<<S<<endl;
	GraphWC g(N+M+2);
	REP(i, M) {
		int D, L;
		cin>>D>>L;
		int j0 = distance(S.begin(), upper_bound(ALL(S), MP(L, 0)));
		int j1 = distance(S.begin(), upper_bound(ALL(S), MP(L+1, inf)));
		cout<<j0<<" "<<j1<<endl;
		for(int j=j0;j<j1;j++) {
			if(S[j].second<=D) {
				add_edge(g, i, M+j, 1, -S[j].second);
				cout<<"edge "<<j<<" "<<S[j].second<<endl;
			}
		}
		add_edge(g, M+N, i, inf, -inf);
	}
	REP(i, N) {
		add_edge(g, M+i, M+N+1, inf, -inf);
	}
	cout<<minimumCostFlow(g, M+N, M+N+1)<<endl;
	
	return 0;
}
