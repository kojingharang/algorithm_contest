// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Please note that this problem has a non-standard time limit: 4 seconds.

Dimas is very fond of trees, he really enjoys solving problems on trees. Recently, his professor Rohit gave him a very difficult task to solve. This is it:



You're given a tree on N vertices. (A tree is an undirected connected graph with no cycles.) Different edges of the tree may have different lengths. Initially, all vertices are white.
You now have to process Q queries. There are two types of queries:

type 1: Given a node x, paint it blue.
type 2: Given a node x, compute the sum of all distances between x and a blue node.





You are given the ints N, Q, startSeed, threshold, and maxDist. Use the algorithm given below as pseudocode to generate both the tree and the sequence of queries you should process.


int curValue = startSeed;

int genNextRandom() {
    curValue = (curValue * 1999 + 17) % 1000003;
    return curValue;
}

void generateInput() {
    for (int i = 0; i < N-1; i++) {
        distance[i] = genNextRandom() % maxDist;
	parent[i] = genNextRandom();
        if (parent[i] < threshold) {
            parent[i] = i;
        } else {
            parent[i] = parent[i] % (i + 1);
        }
    }

    for (int i = 0; i < Q; i++) {
        queryType[i] = genNextRandom() % 2 + 1;
        queryNode[i] = genNextRandom() % N;
    }
}


The output of the above pseudocode are four arrays: parent, distance, queryType, and queryNode.

The arrays parent and distance have N-1 elements each. For each valid i, our tree contains an edge between the vertices (i+1) and parent[i].
The length of that edge is distance[i]. Note that parent[i] will always be between 0 and i, inclusive.

The arrays queryType and queryNode have Q elements each. For each valid i, the i-th query (0-based index) you should process has the type queryType[i], and should be applied to the vertex queryNode[i].
The queries must be processed in the given order.

Return the bitwise XOR of the answers to all type 2 queries.

DEFINITION
Class:TreeColoring
Method:color
Parameters:int, int, int, int, int
Returns:long long
Method signature:long long color(int N, int Q, int startSeed, int threshold, int maxDist)


NOTES
-The intended solution does not rely on any properties of the tree and queries generator provided in the problem statement. It can process 100,000 queries on any tree containing up to 100,000 vertices. It is also able to calculate individual answers to each type 2 query (not just bitwise XOR of all answers).


CONSTRAINTS
-N will be between 2 and 100,000, inclusive.
-Q will be between 1 and 100,000, inclusive.
-startSeed will be between 0 and 1,000,002, inclusive.
-threshold will be between 0 and 1,000,003, inclusive.
-maxDist will be between 1 and 1,000,003, inclusive.


EXAMPLES

0)
4
6
15
2
5

Returns: 7


parent = {0,1,2}
distance = {2,1,3}
queryType = {2,1,2,2,2,1}
queryNode = {2,3,2,3,1,3}

Here are our responses to the 6 queries:

There are no blue nodes so the answer is clearly zero.
We paint the node #3 blue.
The distance between node #2 and node #3 is 3.
The distance between node #3 and itself is 0.
The distance between node #1 and node #3 is 4.
As the node #3 is already blue, we just ignore this query.


1)
4
5
2
9
10

Returns: 30

Here are the edges of the tree you should generate: 0-1 (length 5), 0-3 (length 4), and 1-2 (length 6).


For query 0 we return 0 because there are no blue nodes yet.
Queries 1 and 2 instruct us to color vertices 0 and 3 blue.
Then, query 3 asks us to compute the sum of distances between the vertex 2 and each of the blue nodes. The distance between 2 and 0 is 11, and the distance between 2 and 3 is 15. Hence the sum of all distances is 11+15 = 26.
Similarly we can compute that the answer to the last query is 4+0 = 4.


2)
8
8
3
5
7

Returns: 6



3)
14750
50
29750
1157
21610

Returns: 2537640



4)
100000
100000
123456
500000
474747

Returns: 726915029831



5)
100000
100000
654321
1000003
1000003

Returns: 562600687570528



******************************/
// END CUT HERE
#line 170 "TreeColoring.cpp"
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

class TreeColoring {
	public:
	long long color(int N, int Q, int startSeed, int threshold, int maxDist) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const long long& Expected, const long long& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, TreeColoring().color(N, Q, startSeed, threshold, maxDist));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int N = 4; 
	int Q = 6; 
	int startSeed = 15; 
	int threshold = 2; 
	int maxDist = 5; 
	long long _ = 7LL; 
END
CASE(1)
	int N = 4; 
	int Q = 5; 
	int startSeed = 2; 
	int threshold = 9; 
	int maxDist = 10; 
	long long _ = 30LL; 
END
CASE(2)
	int N = 8; 
	int Q = 8; 
	int startSeed = 3; 
	int threshold = 5; 
	int maxDist = 7; 
	long long _ = 6LL; 
END
CASE(3)
	int N = 14750; 
	int Q = 50; 
	int startSeed = 29750; 
	int threshold = 1157; 
	int maxDist = 21610; 
	long long _ = 2537640LL; 
END
CASE(4)
	int N = 100000; 
	int Q = 100000; 
	int startSeed = 123456; 
	int threshold = 500000; 
	int maxDist = 474747; 
	long long _ = 726915029831LL; 
END
CASE(5)
	int N = 100000; 
	int Q = 100000; 
	int startSeed = 654321; 
	int threshold = 1000003; 
	int maxDist = 1000003; 
	long long _ = 562600687570528LL; 
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
	int N = UNIFORM_LL(0, 100); 
// param type: int
	int Q = UNIFORM_LL(0, 100); 
// param type: int
	int startSeed = UNIFORM_LL(0, 100); 
// param type: int
	int threshold = UNIFORM_LL(0, 100); 
// param type: int
	int maxDist = UNIFORM_LL(0, 100); 
	long long _0 = TreeColoring().color(N, Q, startSeed, threshold, maxDist);
	long long _1 = TreeColoringRef().color(N, Q, startSeed, threshold, maxDist);
	if(!verify_case(_0, _1, true)) {
print(N);
print(Q);
print(startSeed);
print(threshold);
print(maxDist);
	}
}
#endif

}
// END CUT HERE
