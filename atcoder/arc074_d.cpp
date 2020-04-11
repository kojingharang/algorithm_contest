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
//#define INF (1LL<<60)

#define INF 1000000
typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Weight maximumFlow(const Graph &g, int s, int t) {
  int n = g.size();
  Matrix flow(n, Array(n)), capacity(n, Array(n));
  REP(u,n) FOR(e,g[u]) capacity[e->src][e->dst] += e->weight;

  Weight total = 0;
  while (1) {
    queue<int> Q; Q.push(s);
    vector<int> prev(n, -1); prev[s] = s;
    while (!Q.empty() && prev[t] < 0) {
      int u = Q.front(); Q.pop();
      FOR(e,g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
        prev[e->dst] = u;
        Q.push(e->dst);
      }
    }
    if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
    Weight inc = INF;
    for (int j = t; prev[j] != j; j = prev[j])
      inc = min(inc, RESIDUE(prev[j], j));
    for (int j = t; prev[j] != j; j = prev[j])
      flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
    VI path;
    for (int j = t; prev[j] != j; j = prev[j]) path.push_back(j);
    path.push_back(s);
    reverse(ALL(path));
    total += inc;
//    cout<<"Update "<<path<<" -> total "<<total<<endl;
  }
}
void add_edge(Graph& g, int s, int e, int w) {
	g[s].push_back(Edge(s, e, w));
	g[e].push_back(Edge(e, s, 0));
}

bool ok(char c) {
	return c=='o' || c=='S' || c=='T';
}

int main() {
	//ios::sync_with_stdio(false);
	ll W,H;
	string s;
	while(cin>>H>>W) {
		vector<string> w(H);
		ll si, ei;
		REP(i, H) {
			cin>>w[i];
//			REP(j, W) if(w[i][j]=='S') si = i*W+j;
//			REP(j, W) if(w[i][j]=='T') ei = i*W+j;
		}
//		DD(w);
//		DD(si);DD(ei);
		Graph g(W+H+2);
		ll S = W+H;
		ll E = S+1;
		bool ng=false;
		REP(y, H) REP(x, W) {
			if(w[y][x]=='o') {
				add_edge(g, x, y+W, 1);
				add_edge(g, y+W, x, 1);
			}
			if(w[y][x]=='S') {
				add_edge(g, S, y+W, INF);
				add_edge(g, S, x, INF);
			}
			if(w[y][x]=='T') {
				add_edge(g, x, E, INF);
				add_edge(g, y+W, E, INF);
			}
//			REP(xx, W) if(x!=xx && w[y][x]=='S' && w[y][xx]=='T') ng=true;
//			REP(yy, H) if(y!=yy && w[y][x]=='S' && w[yy][x]=='T') ng=true;
		}
		ll ans = maximumFlow(g, S, E);
		if(ans>=INF) ans = -1;
		cout<<ans<<endl;
	}
	
	return 0;
}
