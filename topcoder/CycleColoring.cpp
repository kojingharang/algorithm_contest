// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// This problem statement contains superscripts and/or subscripts. It may not display properly outside the applet.

Today, Bob is trying to count the colorings of a strange graph. It looks like a cycle of cycles.

The graph has two types of edges -- solid edges and dashed edges.

The edges between the vertices of the original cycles are all solid edges.
The edges that connect cycles together are all dashed edges.

More precisely, the graph consists of N cycles. The cycles are labelled, in order, as C0, C1, ..., CN-1. You are given a vector <int> vertexCount with N elements. Cycle Ci has vertexCount[i] vertices.  The vertices of cycle Ci are labelled, in order, as vi, 0, vi, 1, ..., vi, vertexCount[i]-1. Note that the last vertex in this order is also connected to the first one. All of the edges that form these cycles are solid edges.

You are also given two vector <int>s fromVertex and toVertex, with N elements each. These vector <int>s describe the connection between cycle Ci and Ci+1 as follows:  The vertex in cycle Ci with label vi, fromVertex[i] and the vertex in cycle Ci+1 with label vi+1, toVertex[i] will be connected with a dashed edge.

Bob has K distinct colors.  He wants to know how many different ways there are to color the vertices of the graph under the following two rules:

  Vertices connected with a solid edge must be colored using a different color.
  Vertices connected with a dashed edge must be colored using the same color.


Two colorings are considered different if there is a vertex vi, j which has a different color in each coloring. Let C be the number of colorings that correspond to the given rules. As C can be extremely large, you should compute and return the value (C modulo 1,000,000,007).

DEFINITION
Class:CycleColoring
Method:countColorings
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:int
Method signature:int countColorings(vector <int> vertexCount, vector <int> fromVertex, vector <int> toVertex, int K)


NOTES
-i+1 is considered modulo N - hence, references to cycle CN are referring to cycle C0.


CONSTRAINTS
-vertexCount will contain between 1 and 50 elements, inclusive.
-vertexCount, fromVertex, and toVertex will all contain the same number of elements.
-Each element of vertexCount will be between 3 and 1,000,000, inclusive.
-Element fromVertex[i] will be between 0 and vertexCount[i] - 1, inclusive.
-Element toVertex[i] will be between 0 and vertexCount[i+1] - 1, inclusive.
-K will be between 2 and 1,000,000,000, inclusive.


EXAMPLES

0)
{3, 3}
{0, 0}
{0, 0}
3

Returns: 12

This graph consists of two cycles of length 3. There are two dashed edges, each connecting vertex 0 of one cycle to vertex 0 of the other cycle. These two vertices must share the same color. We have 3 possibilities for that color. Once we fix it, we have 2 possibilities how to color the rest of each cycle. Hence, the answer is 3*2*2 = 12.

1)
{6}
{4}
{1}
3

Returns: 12

This graph only has one cycle. Note that for N=1 there is still one dashed edge and it connects two vertices on the same cycle. The 12 valid colorings of the resulting graph correspond to the 12 valid colorings of the graph from Example 0.

2)
{3, 3}
{0, 1}
{1, 2}
3

Returns: 0

Vertices 0 and 2 on cycle 0 must both have the same color as vertex 1 on cycle 1. However, vertices 0 and 2 on cycle 0 are adjacent and therefore must have different colors. This is a contradiction. Therefore, there are no valid colorings of this graph.

3)
{9, 5}
{8, 3}
{0, 2}
8

Returns: 589124602



4)
{14, 15, 16, 17}
{5, 10, 4, 6}
{10, 3, 14, 10}
614

Returns: 818050159



5)
{482373, 283712, 883, 12834, 5, 5, 482734, 99912, 35881, 277590}
{59283, 49782, 0, 0, 3, 2, 84791, 40017, 2263, 461}
{150173, 709, 11108, 0, 4, 7, 5902, 712, 190232, 390331}
479360784

Returns: 763634309



******************************/
// END CUT HERE
#line 111 "CycleColoring.cpp"
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

class CycleColoring {
	public:
	int countColorings(vector <int> vertexCount, vector <int> fromVertex, vector <int> toVertex, int K) {
		
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
#define END	 verify_case(_, CycleColoring().countColorings(vertexCount, fromVertex, toVertex, K));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int vertexCount_[] = {3, 3};
	  vector <int> vertexCount(vertexCount_, vertexCount_+sizeof(vertexCount_)/sizeof(*vertexCount_)); 
	int fromVertex_[] = {0, 0};
	  vector <int> fromVertex(fromVertex_, fromVertex_+sizeof(fromVertex_)/sizeof(*fromVertex_)); 
	int toVertex_[] = {0, 0};
	  vector <int> toVertex(toVertex_, toVertex_+sizeof(toVertex_)/sizeof(*toVertex_)); 
	int K = 3; 
	int _ = 12; 
END
CASE(1)
	int vertexCount_[] = {6};
	  vector <int> vertexCount(vertexCount_, vertexCount_+sizeof(vertexCount_)/sizeof(*vertexCount_)); 
	int fromVertex_[] = {4};
	  vector <int> fromVertex(fromVertex_, fromVertex_+sizeof(fromVertex_)/sizeof(*fromVertex_)); 
	int toVertex_[] = {1};
	  vector <int> toVertex(toVertex_, toVertex_+sizeof(toVertex_)/sizeof(*toVertex_)); 
	int K = 3; 
	int _ = 12; 
END
CASE(2)
	int vertexCount_[] = {3, 3};
	  vector <int> vertexCount(vertexCount_, vertexCount_+sizeof(vertexCount_)/sizeof(*vertexCount_)); 
	int fromVertex_[] = {0, 1};
	  vector <int> fromVertex(fromVertex_, fromVertex_+sizeof(fromVertex_)/sizeof(*fromVertex_)); 
	int toVertex_[] = {1, 2};
	  vector <int> toVertex(toVertex_, toVertex_+sizeof(toVertex_)/sizeof(*toVertex_)); 
	int K = 3; 
	int _ = 0; 
END
CASE(3)
	int vertexCount_[] = {9, 5};
	  vector <int> vertexCount(vertexCount_, vertexCount_+sizeof(vertexCount_)/sizeof(*vertexCount_)); 
	int fromVertex_[] = {8, 3};
	  vector <int> fromVertex(fromVertex_, fromVertex_+sizeof(fromVertex_)/sizeof(*fromVertex_)); 
	int toVertex_[] = {0, 2};
	  vector <int> toVertex(toVertex_, toVertex_+sizeof(toVertex_)/sizeof(*toVertex_)); 
	int K = 8; 
	int _ = 589124602; 
END
CASE(4)
	int vertexCount_[] = {14, 15, 16, 17};
	  vector <int> vertexCount(vertexCount_, vertexCount_+sizeof(vertexCount_)/sizeof(*vertexCount_)); 
	int fromVertex_[] = {5, 10, 4, 6};
	  vector <int> fromVertex(fromVertex_, fromVertex_+sizeof(fromVertex_)/sizeof(*fromVertex_)); 
	int toVertex_[] = {10, 3, 14, 10};
	  vector <int> toVertex(toVertex_, toVertex_+sizeof(toVertex_)/sizeof(*toVertex_)); 
	int K = 614; 
	int _ = 818050159; 
END
CASE(5)
	int vertexCount_[] = {482373, 283712, 883, 12834, 5, 5, 482734, 99912, 35881, 277590};
	  vector <int> vertexCount(vertexCount_, vertexCount_+sizeof(vertexCount_)/sizeof(*vertexCount_)); 
	int fromVertex_[] = {59283, 49782, 0, 0, 3, 2, 84791, 40017, 2263, 461};
	  vector <int> fromVertex(fromVertex_, fromVertex_+sizeof(fromVertex_)/sizeof(*fromVertex_)); 
	int toVertex_[] = {150173, 709, 11108, 0, 4, 7, 5902, 712, 190232, 390331};
	  vector <int> toVertex(toVertex_, toVertex_+sizeof(toVertex_)/sizeof(*toVertex_)); 
	int K = 479360784; 
	int _ = 763634309; 
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
	vector <int> vertexCount; 
	{
		int N=UNIFORM_LL(1, 51);
		vertexCount = vector <int>(N); 
		REP(i, N) {
			vertexCount[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> fromVertex; 
	{
		int N=UNIFORM_LL(1, 51);
		fromVertex = vector <int>(N); 
		REP(i, N) {
			fromVertex[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> toVertex; 
	{
		int N=UNIFORM_LL(1, 51);
		toVertex = vector <int>(N); 
		REP(i, N) {
			toVertex[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int K = UNIFORM_LL(0, 100); 
	int _0 = CycleColoring().countColorings(vertexCount, fromVertex, toVertex, K);
	int _1 = CycleColoringRef().countColorings(vertexCount, fromVertex, toVertex, K);
	if(!verify_case(_0, _1, true)) {
print(vertexCount);
print(fromVertex);
print(toVertex);
print(K);
	}
}
#endif

}
// END CUT HERE
