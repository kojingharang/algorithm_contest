// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// The Angel and the Demon are playing a game on an undirected simple graph G.
G contains n nodes numbered 0 through n-1.
You are given a vector <string> G: its adjacency matrix.
That is, for any i and j, nodes i and j are connected by an edge if and only if G[i][j] is 'Y'.


You are also given two ints: A and D.
The game is played as follows:
The Angel chooses some unordered pairs of nodes and at the same time the Demon chooses some unordered pairs of nodes.
The Angel must choose between 0 and A pairs, inclusive, and the Demon must choose between 0 and D pairs, inclusive.
Then, both players reveal their choices.
Next, the graph G is modified as follows:



For each pair of nodes i != j:
	If the Demon chose the pair (i, j), there will be no edge (i, j) in the new graph.
	Otherwise:
		If the Angel chose the pair (i, j), there will be an edge (i, j) in the new graph.
		Otherwise:
			The state of the edge (i, j) remains the same.
                        That is, it is in the new graph if and only if it is in the old graph G.



Finally, the game is evaluated.
If the new graph contains a path between nodes 0 and n-1, the Angel wins.
Otherwise, the Demon wins.


We say that a player has a winning strategy if they can make a valid choice such that they are guaranteed to win the game regardless of the set of edges chosen by their opponent.
If the Angel has a winning strategy, return "Angel".
If the Demon has a winning strategy, return "Demon".
Otherwise, return "Unknown".

DEFINITION
Class:AngelDemonGame
Method:winner
Parameters:vector <string>, int, int
Returns:string
Method signature:string winner(vector <string> G, int A, int D)


CONSTRAINTS
-n will be between 3 and 50, inclusive.
-G will contain exactly n elements.
-Each element in G will contain exactly n characters.
-Each character in G will be 'Y' or 'N'.
-For each i and j, G[i][j] = G[j][i].
-For each i, G[i][i] = 'N'.
-A and D will be between 2 and n*(n-1)/2, inclusive.


EXAMPLES

0)
{"NYNY",
 "YNYY",
 "NYNN",
 "YYNN"}
2
2

Returns: "Angel"

G is a graph with 4 nodes and 4 edges:

  1
 /|\
0 - 3
  |
  2

A winning strategy for the Angel is to choose the pairs (0, 2) and (2, 3).
It can be shown that with this choice the Angel will win regardless of the choice made by the Demon.

1)
{"NYNY",
 "YNYY",
 "NYNN",
 "YYNN"}
6
6

Returns: "Demon"

The graph G is the same but now each player can choose up to 6 pairs.
This means that the Demon can select all possible unordered pairs of nodes.
If the Demon does so, the new graph will have no edges and thus there will be no path between nodes 0 and 3.

2)
{"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"}
2
2

Returns: "Unknown"

It can be proved that in this case no player has a winning strategy.

3)
{"NYNNNY",
 "YNNYNN",
 "NNNNYN",
 "NYNNNN",
 "NNYNNN",
 "YNNNNN"}
4
4

Returns: "Unknown"



4)
{"NYNNNY",
 "YNNYNN",
 "NNNNYN",
 "NYNNNN",
 "NNYNNN",
 "YNNNNN"}
8
4

Returns: "Angel"



5)
{"NYNNNY",
 "YNNYNN",
 "NNNNYN",
 "NYNNNN",
 "NNYNNN",
 "YNNNNN"}
4
8

Returns: "Demon"



*/
// END CUT HERE
#line 151 "AngelDemonGame.cpp"

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

using Flow = int;
using Cost = int;
const int MAX_V = 100000;
const Cost INF = std::numeric_limits<Cost>::max() / 8;

struct PrimalDual {
    struct Edge {
        int d;
        Flow c, f;
        Cost w;
        int r, is_r;
        Edge(int d_, Flow c_, Flow f_, Cost w_, int r_, bool is_r_)
            : d(d_), c(c_), f(f_), w(w_), r(r_), is_r(is_r_) {}
    };

    int n;
    std::vector<std::vector<Edge> > g;
    PrimalDual(int n_) : n(n_), g(std::vector<std::vector<Edge> >(n_)) {}

    void add_edge(int src, int dst, Flow cap, Cost cost) {  // 有向辺
        int rsrc = g[dst].size();
        int rdst = g[src].size();
        g[src].emplace_back(dst, cap, 0, cost, rsrc, false);
        g[dst].emplace_back(src, cap, cap, -cost, rdst, true);
    }

    Cost solve(int s, int t, Flow f) {
        Cost res = 0;

        static Cost h[MAX_V + 10], dist[MAX_V];
        static int prevv[MAX_V + 10], preve[MAX_V + 10];
        // std::vector<Cost> h(g.size()), dist(g.size());
        // std::vector<int> prevv(g.size()), preve(g.size());

        using pcv = std::pair<Cost, int>;
        std::priority_queue<pcv, std::vector<pcv>, std::greater<pcv> > q;
        std::fill(h, h + n, 0);
        while (f > 0) {
            std::fill(dist, dist + n, INF);
            dist[s] = 0;
            q.emplace(0, s);
            while (q.size()) {
                Cost cd;
                int v;
                std::tie(cd, v) = q.top();
                q.pop();
                if (dist[v] < cd) continue;
                for (int i = 0; i < (int)(g[v].size()); ++i) {
                    Edge &e = g[v][i];
                    if (residue(e) == 0) continue;
                    if (dist[e.d] + h[e.d] > cd + h[v] + e.w) {
                        dist[e.d] = dist[v] + e.w + h[v] - h[e.d];
                        prevv[e.d] = v;
                        preve[e.d] = i;
                        q.emplace(dist[e.d], e.d);
                    }
                }
            }

            if (dist[t] == INF) return -1;  // 経路が見つからなかった

            // s-t 間最短路に沿って目一杯流す
            for (int i = 0; i < n; ++i) h[i] += dist[i];
            Flow d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = std::min(d, residue(g[prevv[v]][preve[v]]));
            }
            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                Edge &e = g[prevv[v]][preve[v]];
                e.f += d;
                g[v][e.r].f -= d;
            }
        }
        return res;
    }

    Flow residue(const Edge &e) { return e.c - e.f; }

    // 流量を表示
    void show() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (int)(g[i].size()); ++j) {
                Edge &e = g[i][j];
                if (e.is_r) continue;
                printf("%3d->%3d (flow:%d)\n", i, e.d, e.f);
            }
        }
    }
};

class AngelDemonGame {
	public:
	string winner(vector <string> G, int A, int D) {
		int N=G.size();
		if(D>=N-1) return "Demon";
		PrimalDual g(N);
		REP(i, N) REP(j, N) {
			g.add_edge(i, j, 1, G[i][j]!='Y');
		}
		// D消せるので最小カットがD+1になるように流す。そのときのコストがA以内なら最小カットがD+1にできるのでA勝ち
		int cost = g.solve(0, N-1, D+1);
//		DD(cost);
//		bool v = min<ll>(N, A+minCut)-D > 0;
		if(cost<=A) return "Angel";
		return "Unknown";
//		return v ? "Angel" : "Demon";
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const string& Expected, const string& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, AngelDemonGame().winner(G, A, D));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string G_[] = {"NYNY",
 "YNYY",
 "NYNN",
 "YYNN"};
	  vector <string> G(G_, G_+sizeof(G_)/sizeof(*G_)); 
	int A = 2; 
	int D = 2; 
	string _ = "Angel"; 
END
CASE(1)
	string G_[] = {"NYNY",
 "YNYY",
 "NYNN",
 "YYNN"};
	  vector <string> G(G_, G_+sizeof(G_)/sizeof(*G_)); 
	int A = 6; 
	int D = 6; 
	string _ = "Demon"; 
END
CASE(2)
	string G_[] = {"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"};
	  vector <string> G(G_, G_+sizeof(G_)/sizeof(*G_)); 
	int A = 2; 
	int D = 2; 
	string _ = "Unknown"; 
END
CASE(3)
	string G_[] = {"NYNNNY",
 "YNNYNN",
 "NNNNYN",
 "NYNNNN",
 "NNYNNN",
 "YNNNNN"};
	  vector <string> G(G_, G_+sizeof(G_)/sizeof(*G_)); 
	int A = 4; 
	int D = 4; 
	string _ = "Unknown"; 
END
CASE(4)
	string G_[] = {"NYNNNY",
 "YNNYNN",
 "NNNNYN",
 "NYNNNN",
 "NNYNNN",
 "YNNNNN"};
	  vector <string> G(G_, G_+sizeof(G_)/sizeof(*G_)); 
	int A = 8; 
	int D = 4; 
	string _ = "Angel"; 
END
CASE(5)
	string G_[] = {"NYNNNY",
 "YNNYNN",
 "NNNNYN",
 "NYNNNN",
 "NNYNNN",
 "YNNNNN"};
	  vector <string> G(G_, G_+sizeof(G_)/sizeof(*G_)); 
	int A = 4; 
	int D = 8; 
	string _ = "Demon"; 
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
// param type: String
	vector <string> G; 
	{
		int N=UNIFORM_LL(1, 51);
		G = vector <string>(N); 
		REP(i, N) {
			G[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int A = UNIFORM_LL(0, 100); 
// param type: int
	int D = UNIFORM_LL(0, 100); 
	string _0 = AngelDemonGame().winner(G, A, D);
	string _1 = AngelDemonGameRef().winner(G, A, D);
	if(!verify_case(_0, _1, true)) {
print(G);
print(A);
print(D);
	}
}
#endif

}
// END CUT HERE
