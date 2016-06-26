// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// MaxMinTreeGame is a game for two players.
The game is played on a tree.
The tree has N nodes, labeled 0 through N-1.
Each node of the tree also has an integer cost.

The players take alternating turns.
In her turn, the current player starts by choosing one edge of the tree and erasing it.
This necessarily divides the tree into two components.
The current player then decides which of the components to keep, and erases the other component completely.

The game ends when there is only one node left.
The cost of that node is the result of the game.
The first player (i.e., the one that starts the game) wants to maximize the result.
Naturally, the second player's goal is to minimize the result.

You are given a vector <int> edges that describes the structure of the tree.
For each i between 0 and N-2, inclusive, the tree contains an edge between the vertices i+1 and edges[i].
You are also given a vector <int> costs.
For each i between 0 and N-1, inclusive, the cost of vertex i is costs[i].

Return the result of the game, assuming that both players play optimally.

DEFINITION
Class:MaxMinTreeGame
Method:findend
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int findend(vector <int> edges, vector <int> costs)


CONSTRAINTS
-The number of nodes in the tree N will be between 2 and 50, inclusive.
-edges will contain exactly N-1 elements.
-For each i, edges[i] will be between 0 and i, inclusive.
-costs will contain exactly N elements.
-Each element of costs will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
{0}
{4,6}

Returns: 6

There is only one edge in this tree and the first player will choose it. After that she will keep the component containing the node with cost 6.


1)
{0,1}
{4,6,5}

Returns: 5

One of the optimal moves for the first player is to remove the edge between nodes 0 and 1 and to keep the component containing nodes 1 and 2. The second player will then remove the remaining edge and keep the node with cost 5.


2)
{0,1,2,3}
{0,1,0,1,0}

Returns: 0



3)
{0,0,0}
{5,1,2,3}

Returns: 3



4)
{0,0}
{3,2,5}

Returns: 5



******************************/
// END CUT HERE
#line 89 "MaxMinTreeGame.cpp"
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

class MaxMinTreeGame {
	public:
	int findend(vector <int> E, vector <int> C) {
		int N=C.size();
		ll Mx=0;
		VVI w(N, VI(N));
		REP(i, N-1) {
			w[i+1][E[i]]++;
			w[E[i]][i+1]++;
		}
		REP(i, N) {
			if(accumulate(ALL(w[i]), 0)==1) Mx=max(Mx, (ll)C[i]);
		}
		ll Mn = 1<<30;
		REP(ex, N-1) {
			VVI w(N, VI(N));
			REP(i, N-1) {
				if(ex==i) continue;
				w[i+1][E[i]]++;
				w[E[i]][i+1]++;
			}
			REP(i, N) {
				if(accumulate(ALL(w[i]), 0)==1) Mn=min(Mn, (ll)C[i]);
			}
		}
		if(Mn==1<<30) Mn=0;
		return max(Mx, Mn);
	}
};

int N, wht[110],mrk[110];
const int neg=0xc0c0c0c0;
class MaxMinTreeGameTry {
	public:
	int findend(vector <int> E, vector <int> C) {
		N=C.size();
		E.PB(0);
		REP(i, N) {wht[i]=C[i];mrk[i]=0;}
		RANGE(i, 1, N) {
			int u=i,v=E[i];
			mrk[u]++;mrk[v]++;
		}
		int ret=neg;
		REP(i, N) if(mrk[i]==1)ret=max(ret, wht[i]);
		return ret;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, MaxMinTreeGame().findend(edges, costs));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int edges_[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
	  vector <int> edges(edges_, edges_+sizeof(edges_)/sizeof(*edges_)); 
	int costs_[] = {1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,};
	  vector <int> costs(costs_, costs_+sizeof(costs_)/sizeof(*costs_)); 
	int _ = 1000000000; 
END
CASE(0)
	int edges_[] = {0};
	  vector <int> edges(edges_, edges_+sizeof(edges_)/sizeof(*edges_)); 
	int costs_[] = {4,6};
	  vector <int> costs(costs_, costs_+sizeof(costs_)/sizeof(*costs_)); 
	int _ = 6; 
END
CASE(1)
	int edges_[] = {0,1};
	  vector <int> edges(edges_, edges_+sizeof(edges_)/sizeof(*edges_)); 
	int costs_[] = {4,6,5};
	  vector <int> costs(costs_, costs_+sizeof(costs_)/sizeof(*costs_)); 
	int _ = 5; 
END
CASE(2)
	int edges_[] = {0,1,2,3};
	  vector <int> edges(edges_, edges_+sizeof(edges_)/sizeof(*edges_)); 
	int costs_[] = {0,1,0,1,0};
	  vector <int> costs(costs_, costs_+sizeof(costs_)/sizeof(*costs_)); 
	int _ = 0; 
END
CASE(3)
	int edges_[] = {0,0,0};
	  vector <int> edges(edges_, edges_+sizeof(edges_)/sizeof(*edges_)); 
	int costs_[] = {5,1,2,3};
	  vector <int> costs(costs_, costs_+sizeof(costs_)/sizeof(*costs_)); 
	int _ = 3; 
END
CASE(4)
	int edges_[] = {0,0};
	  vector <int> edges(edges_, edges_+sizeof(edges_)/sizeof(*edges_)); 
	int costs_[] = {3,2,5};
	  vector <int> costs(costs_, costs_+sizeof(costs_)/sizeof(*costs_)); 
	int _ = 5; 
END
#if 01  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10000;loop++) {
// param type: int
start_time=clock();
	vector <int> edges; 
	int N=UNIFORM_LL(2, 50);
	{
		edges = vector <int>(N-1); 
		REP(i, N-1) {
			edges[i] = UNIFORM_LL(0, i+1);
		}
	}
// param type: int
start_time=clock();
	vector <int> costs; 
	{
		costs = vector <int>(N); 
		REP(i, N) {
			costs[i] = UNIFORM_LL(0, 1000000000);
		}
	}
	int _0 = MaxMinTreeGame().findend(edges, costs);
	int _1 = MaxMinTreeGameTry().findend(edges, costs);
	if(!verify_case(_0, _1, true)) {
print(edges);
print(costs);
	}
}
#endif

}
// END CUT HERE
