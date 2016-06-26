// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Fox Ciel has an unweighted undirected connected graph G with N vertices.
The vertices are numbered 0 through N-1.
The graph has a special structure.
You are given its description in two vector <int>s V and sizes.
V contains a sequence of vertex numbers.
Note that some vertex numbers may occur in V multiple times.

For each valid i, let S[i] be the sum of the first i elements of sizes.
For example, if sizes={10,20,30} then S[0]=0, S[1]=10, S[2]=10+20=30, and S[3]=10+20+30=60.

The graph G that is described by V and sizes looks as follows:
For each valid i, consider all pairs (j,k) such that S[i] <= j < k < S[i+1].
For each such pair (j,k), our graph G contains an edge between the vertices V[j] and V[k].
There are no other edges in G, only those defined above.
You may assume that V and sizes are always such that the resulting graph G is connected.

For each pair of vertices, compute their distance.
Return the sum of all those distances.

DEFINITION
Class:CliqueGraph
Method:calcSum
Parameters:int, vector <int>, vector <int>
Returns:long long
Method signature:long long calcSum(int N, vector <int> V, vector <int> sizes)


NOTES
-For some test cases, the correct return value may overflow a signed 32-bit integer variable.


CONSTRAINTS
-N will be between 2 and 2,500, inclusive.
-V will contain between 1 and 5,000 elements, inclusive.
-Each element of V will be between 0 and N-1, inclusive.
-sizes will contain between 1 and 2,500 elements, inclusive.
-Each element of sizes will be between 2 and N, inclusive.
-The sum of all elements of sizes will be equal to the number of elements in V.
-For each valid i, the elements V[S[i]], V[S[i]+1], ..., V[S[i+1]-1] will be distinct. (See the problem statement for the definition of S[i].)
-The graph G described by V and sizes will be connected.


EXAMPLES

0)
4
{0,1,2,0,3}
{3,2}

Returns: 8

The graph looks as follows:

The distance between vertex 0 and vertex 1 : 1
The distance between vertex 0 and vertex 2 : 1
The distance between vertex 0 and vertex 3 : 1
The distance between vertex 1 and vertex 2 : 1
The distance between vertex 1 and vertex 3 : 2
The distance between vertex 2 and vertex 3 : 2
The sum is 8.

1)
5
{0,1,2,3,1,2,4}
{4,3}

Returns: 12

The graph looks as follows:



2)
15
{1,3,5,7,9,11,13,0
,2,3,6,7,10,11,14,0
,4,5,6,7,12,13,14,0
,8,9,10,11,12,13,14,0}
{8,8,8,8}

Returns: 130



******************************/
// END CUT HERE
#line 91 "CliqueGraph.cpp"
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

/*
V[section..]は完全グラフ。

*/
class CliqueGraph {
	public:
	long long calcSum(int N, vector <int> V, vector <int> si) {
		
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
#define END	 verify_case(_, CliqueGraph().calcSum(N, V, sizes));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int N = 4; 
	int V_[] = {0,1,2,0,3};
	  vector <int> V(V_, V_+sizeof(V_)/sizeof(*V_)); 
	int sizes_[] = {3,2};
	  vector <int> sizes(sizes_, sizes_+sizeof(sizes_)/sizeof(*sizes_)); 
	long long _ = 8LL; 
END
CASE(1)
	int N = 5; 
	int V_[] = {0,1,2,3,1,2,4};
	  vector <int> V(V_, V_+sizeof(V_)/sizeof(*V_)); 
	int sizes_[] = {4,3};
	  vector <int> sizes(sizes_, sizes_+sizeof(sizes_)/sizeof(*sizes_)); 
	long long _ = 12LL; 
END
CASE(2)
	int N = 15; 
	int V_[] = {1,3,5,7,9,11,13,0
,2,3,6,7,10,11,14,0
,4,5,6,7,12,13,14,0
,8,9,10,11,12,13,14,0};
	  vector <int> V(V_, V_+sizeof(V_)/sizeof(*V_)); 
	int sizes_[] = {8,8,8,8};
	  vector <int> sizes(sizes_, sizes_+sizeof(sizes_)/sizeof(*sizes_)); 
	long long _ = 130LL; 
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
	vector <int> V; 
	{
		int N=UNIFORM_LL(1, 51);
		V = vector <int>(N); 
		REP(i, N) {
			V[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> sizes; 
	{
		int N=UNIFORM_LL(1, 51);
		sizes = vector <int>(N); 
		REP(i, N) {
			sizes[i] = UNIFORM_LL(0, 1000);
		}
	}
	long long _0 = CliqueGraph().calcSum(N, V, sizes);
	long long _1 = CliqueGraphRef().calcSum(N, V, sizes);
	if(!verify_case(_0, _1, true)) {
print(N);
print(V);
print(sizes);
	}
}
#endif

}
// END CUT HERE
