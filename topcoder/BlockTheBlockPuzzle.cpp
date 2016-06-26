// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Block Puzzle is played on a square grid of unit cells. Some of those cells are marked as start cells, and one is marked as a goal cell.

The player begins by placing a 1x1x2 block on top of one of the start cells in such a way that the 1x1 face of the block coincides with the cell.
The goal of the game is to reach the state where the block stands with its 1x1 face covering the goal cell.
The game is played by rolling the block across the board.
Only some types of moves are allowed:
When the block stands on its 1x1 face, the player may roll the block in either of the four basic directions.
However, when the block's bottom face is 2x1, the player may only roll it onto one of its 1x1 faces.
In other words, the block must always be rolled over an edge of length 1.

All allowed moves are shown in the figure below. (The old state of the block is always semi-transparent, the new state is opaque.)



So far, the game seems trivial.
Its difficulty comes from the fact that there are holes instead of some cells.
Whenever the entire bottom face of the block stands on a hole, the block falls through the hole and the player loses the game. The block also falls off if the player rolls it across the edge of the game board.
(Note that if the block stands on a 2x1 face and only one of the two cells under the face is missing, the block is still safe.
Technically, the block would also be safe with one half of its bottom face sticking out of the game board, but obviously a move into such a configuration will never help you reach the goal.)

Bohn has been playing Block Puzzle too much. Jrus is bored, so he decided to make Bohn's game unsolvable by making more holes into his board.
Jrus can only remove cells that are neither starting nor goal. As he doesn't want to get caught, he wants to remove as few cells as possible.

You are given the current board as a vector <string> board.
The character '.' represents an ordinary cell, 'H' is a hole, 'b' is a starting cell, and '$' is the only goal cell.
Return the smallest number of cells that have to be removed in order to make the puzzle unsolvable.
If it is not possible to make the puzzle unsolvable, return -1 instead.





DEFINITION
Class:BlockTheBlockPuzzle
Method:minimumHoles
Parameters:vector <string>
Returns:int
Method signature:int minimumHoles(vector <string> board)


CONSTRAINTS
-n will be between 3 and 50, inclusive.
-board will contain exactly n elements.
-Each element of board will contain exactly n characters.
-Each character in board will be '.', 'H', 'b' or '$'.
-board will contain exactly one '$' character.
-board will contain at least one 'b' character.


EXAMPLES

0)
{"b..$",
 "....",
 "HHHH",
 "HHHH"}

Returns: 2

Remove the two cells between the start and the goal. Note that removing just one of them is not enough.

1)
{"............H..",
 "...............",
 "...............",
 "HHH$HHH.....H..",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."}

Returns: 0

This puzzle is already unsolvable.

2)
{"............H..",
 "...............",
 "...............",
 "HHH$HHH........",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."}

Returns: 1

This puzzle is solvable. The only difference between this puzzle and Example 1 is that one cell in this example was a hole in Example 1. Hence, we can easily make this puzzle unsolvable by removing that one cell.

3)
{"b..$...",
 "...H...",
 ".......",
 "b..b..b",
 "...H...",
 ".......",
 "b..b..b"}



Returns: 4

A puzzle may contain multiple starting cells. Bohn may start the game from any of them.

4)
{"b..b..b",
 "..b..b.",
 ".......",
 "b..$bbb",
 ".b.....",
 "....b..",
 "b..b..b"}


Returns: -1

You cannot replace start cells with holes.

******************************/
// END CUT HERE
#line 139 "BlockTheBlockPuzzle.cpp"
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

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
	cout<<s<<" -> "<<e<<endl;
	g[s].push_back(Edge(s, e, w));
	g[e].push_back(Edge(e, s, 0));
}


class BlockTheBlockPuzzle {
	public:
	int minimumHoles(vector <string> b) {
		int N=b.size();
		Graph g(N*N);
		int dx[]={-1,1,0,0};
		int dy[]={0,0,-1,1};
		int BIG = 1<<10;
		REP(x,N)REP(y,N)REP(d, 4) {
			int nx = x+dx[d]*3;
			int ny = y+dy[d]*3;
			if(0<=nx && nx<N && 0<=ny && ny<N) {
				int ok=1;
				REP(i, 3+1) if(b[y+dy[d]*i][x+dx[d]*i]=='H') ok=0;
				if(ok) add_edge(g, y*N+x, ny*N+nx, 1);
			}
		}
		int gx,gy;
		REP(x,N)REP(y,N)if(b[y][x]=='$')gx=x,gy=y;
		cout<<gx<<" "<<gy<<endl;
		int ans=1<<30;
		REP(x,N)REP(y,N)if(b[y][x]=='b') {
			int v = maximumFlow(g, gy*N+gx, y*N+x);
			cout<<x<<" : "<<y<<"  "<<v<<endl;
			ans = min(ans, v);
		}
		return ans*2;
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
#define END	 verify_case(_, BlockTheBlockPuzzle().minimumHoles(board));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string board_[] = {
 "b..$",
 "....",
 "HHHH",
 "HHHH"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 2; 
END
return 0;
CASE(1)
	string board_[] = {"............H..",
 "...............",
 "...............",
 "HHH$HHH.....H..",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 0; 
END
CASE(2)
	string board_[] = {"............H..",
 "...............",
 "...............",
 "HHH$HHH........",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 1; 
END
CASE(3)
	string board_[] = {"b..$...",
 "...H...",
 ".......",
 "b..b..b",
 "...H...",
 ".......",
 "b..b..b"}

;
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 4; 
END
CASE(4)
	string board_[] = {"b..b..b",
 "..b..b.",
 ".......",
 "b..$bbb",
 ".b.....",
 "....b..",
 "b..b..b"}
;
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = -1; 
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
	vector <string> board; 
	{
		int N=UNIFORM_LL(1, 51);
		board = vector <string>(N); 
		REP(i, N) {
			board[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = BlockTheBlockPuzzle().minimumHoles(board);
	int _1 = BlockTheBlockPuzzleRef().minimumHoles(board);
	if(!verify_case(_0, _1, true)) {
print(board);
	}
}
#endif

}
// END CUT HERE
