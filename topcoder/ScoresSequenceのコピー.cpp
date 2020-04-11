// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
A tournament is a directed graph on n vertices that can be obtained by taking an undirected complete graph on n vertices and assigning a direction to each edge.
The outdegree of a vertex is the number of directed edges that start at that vertex.
The score of a tournament is the list of the outdegrees of its vertices, in no particular order.



Alice used to have a tournament T but she lost it.
She only remembers its score.
You are given the score of T in the vector <int> s.



Determine and return the number of pairs of vertices (u,v) such that in the tournament T the vertex v was reachable from the vertex u.
Note that each vertex is reachable from itself.


You may assume that the answer can always be uniquely determined.


DEFINITION
Class:ScoresSequence
Method:count
Parameters:vector <int>
Returns:int
Method signature:int count(vector <int> s)


CONSTRAINTS
-s will contain between 1 and 100 elements, inclusive.
-s will be a valid score of some tournament.


EXAMPLES

0)
{2, 0, 1}

Returns: 6


There are three vertices. Let's call them A, B, and C, in the order in which they are mentioned in the score.
As the outdegree of A is 2, the tournament must contain the edges A -> B and A -> C.
As the outdegree of B is 0, the tournament must also contain the edge C -> B.



There are six pairs of vertices (u,v) such that there is a path from u to v.
These are the pairs (A,A), (B,B), (C,C), (A,B), (A,C), and (B,C).


1)
{1, 0, 2}

Returns: 6



2)
{1, 1, 1}

Returns: 9

This tournament must clearly be a cycle.
Hence, each vertex is reachable from each vertex.


3)
{0, 2, 8, 4, 3, 9, 1, 5, 7, 6}

Returns: 55



4)
{22,20,14,13,17,15,12,18,23,15,21,26,33,5,19,9,37,0,25,28,4,12,35,32,25,7,31,6,2,29,10,33,36,27,39,28,40,3,8,38,3}

Returns: 1422



*/
// END CUT HERE
#line 88 "ScoresSequence.cpp"

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

//#define INF (1LL<<60)

struct bipartite_matching {
	VVI g;
	VI match;
	VI used;
	
	bipartite_matching(int N) {
		g = VVI(N);
	}
	
	int dfs(int v) {
		used[v]=1;
		for(int i=0;i<(int)g[v].size();i++) {
			int u=g[v][i], w=match[u];
			if(w<0 || (!used[w] && dfs(w))) {
				match[v]=u;
				match[u]=v;
				return 1;
			}
		}
		return 0;
	}
	
	int run() {
		int res=0;
		match=VI(g.size(), -1);
		for(int v=0;v<(int)g.size();v++){
			if(match[v]<0) {
				used=VI(g.size());
				if(dfs(v)) res++;
			}
		}
		return res;
	}
	
	void add_edge(int u, int v){
		g[u].push_back(v);
		g[v].push_back(u);
	}
};

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
    cout<<"Update "<<path<<" -> total "<<total<<endl;
  }
}
void add_edge(Graph& g, int s, int e, int w) {
	g[s].push_back(Edge(s, e, w));
	g[e].push_back(Edge(e, s, 0));
}


class ScoresSequence {
	public:
	int count(vector <int> s) {
		int N = s.size();

		ll M = N*(N-1)/2;
		VI srcNode(M);
		VI dstNode(M);
		{
			ll cnt = 0;
			ll cntS = 0;
			REP(i, N) {
				REP(j, N-1-s[i]) dstNode[cnt++] = i;
				REP(j, s[i]) srcNode[cntS++] = i;
			}
			assert(cnt==M);
			assert(cntS==M);
			DD(srcNode);
			DD(dstNode);
		}
		Graph g(M*2+N+2, Edges());
//		bipartite_matching bm(M*2);
		REP(i, M) {
			REP(k, M) if(srcNode[i]!=dstNode[k]) {
//				bm.add_edge(i, M+k);
				g.add_edge(i, M+k);
			}
		}
		ll S = M*2+N;
		REP(i, M) g.add_edge(S, i);
		REP(i, M) REP(j, N) g.add_edge(i+M+2*M+j);
		REP(i, N) g.add_edge(i, E);
		ll E = S+1;
		maximumFlow(g, S, E);
		int matched=bm.run();
		DD(matched);
		{
			vector<int> og(N);
			vector<int> ig(N, N-1);
			REP(i, M) {
				ll j = bm.match[i]-M;
				assert(0<=j && j<M);
				cout<<srcNode[i]<<" -> "<<dstNode[j]<<endl;
				og[srcNode[i]]++;
				ig[dstNode[j]]--;
			}
			DD(og);
			DD(ig);
			assert(og==s);
			assert(ig==s);
		}
		assert(matched==M);
//		DD(bm.match);

		VVI w(N, VI(N, INF)); // [i][j] i -> j
		REP(i, N) w[i][i] = 0;
		REP(i, M) {
			ll j = bm.match[i]-M;
			assert(0<=j && j<M);
			w[srcNode[i]][dstNode[j]]=1;
		}

		DD(w);
		{
			vector<int> og(N);
			REP(i, N) REP(j, N) if(i!=j && w[i][j]<INF) og[i]++;
			DD(og);
			assert(og==s);
		}
		REP(k, N) REP(i, N) REP(j, N) w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
//		DD(w);
		ll ans = 0;
		REP(i, N) REP(j, N) if(w[i][j]<INF) ans++;
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, ScoresSequence().count(s));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int s_[] = {2, 0, 1};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 6; 
END
//return 0;
CASE(1)
	int s_[] = {1, 0, 2};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 6; 
END
CASE(2)
	int s_[] = {1, 1, 1};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 9; 
END
CASE(3)
	int s_[] = {0, 2, 8, 4, 3, 9, 1, 5, 7, 6};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 55; 
END
return 0;
CASE(4)
	int s_[] = {22,20,14,13,17,15,12,18,23,15,21,26,33,5,19,9,37,0,25,28,4,12,35,32,25,7,31,6,2,29,10,33,36,27,39,28,40,3,8,38,3};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 1422; 
END
#if 0  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: int
	vector <int> s; 
	{
		int N=UNIFORM_LL(1, 51);
		s = vector <int>(N); 
		REP(i, N) {
			s[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = ScoresSequence().count(s);
	int _1 = ScoresSequenceRef().count(s);
	if(!verify_case(_0, _1, true)) {
print(s);
	}
}
#endif

}
// END CUT HERE
