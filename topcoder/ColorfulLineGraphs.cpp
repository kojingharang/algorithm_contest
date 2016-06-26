// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Bob is going to create a graph with N nodes.
The graph will be constructed in two steps.
First, Bob will take N isolated vertices, label them 1 through N and color each of them using one of K colors.
Then, Bob will add some directed edges to the graph.
For each i between 2 and N, inclusive, Bob may choose a single value j < i such that the nodes i and j have different colors. If he does, he will add the edge from i to j to his graph.
Note that Bob may choose not to add any edge from node i, even if there are some valid choices of j.



Two graphs are considered the same if they have the same node colors and the same set of edges.



You are given the long longs N and K.
You are also given an int M.
Compute and return the number of different graphs Bob may construct, modulo M.


DEFINITION
Class:ColorfulLineGraphs
Method:countWays
Parameters:long long, long long, int
Returns:int
Method signature:int countWays(long long N, long long K, int M)


CONSTRAINTS
-N will be between 1 and 1,000,000,000,000 (10^12), inclusive.
-K will be between 1 and 1,000,000,000,000 (10^12), inclusive.
-M will be between 2 and 1,000,000 (10^6), inclusive. 


EXAMPLES

0)
3
2
100000

Returns: 24


The 24 different graphs are shown below. In each picture, the vertices have labels 1, 2, 3 from the left to the right.




1)
15
3
1000000

Returns: 510625



2)
100000
100000
999999

Returns: 185185



3)
1000000000000
6
1000000

Returns: 109376



4)
5000
1000000000000
314159

Returns: 202996



******************************/
// END CUT HERE
#line 91 "ColorfulLineGraphs.cpp"
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
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, I, J) REP(i, I) { REP(j, J) cout<<table[i][j]<<" "; cout<<"\n"; }
#define PRINT3(table, I, J, K) REP(i, I) { REP(j, J) { REP(k, K) cout<<table[i][j][k]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class ColorfulLineGraphs {
	public:
	int countWays(long long N, long long K, int M) {
		
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
#define END	 verify_case(_, ColorfulLineGraphs().countWays(N, K, M));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	long long N = 3LL; 
	long long K = 2LL; 
	int M = 100000; 
	int _ = 24; 
END
CASE(1)
	long long N = 15LL; 
	long long K = 3LL; 
	int M = 1000000; 
	int _ = 510625; 
END
CASE(2)
	long long N = 100000LL; 
	long long K = 100000LL; 
	int M = 999999; 
	int _ = 185185; 
END
CASE(3)
	long long N = 1000000000000LL; 
	long long K = 6LL; 
	int M = 1000000; 
	int _ = 109376; 
END
CASE(4)
	long long N = 5000LL; 
	long long K = 1000000000000LL; 
	int M = 314159; 
	int _ = 202996; 
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
// param type: long
	long long N = UNIFORM_LL(0, 100); 
// param type: long
	long long K = UNIFORM_LL(0, 100); 
// param type: int
	int M = UNIFORM_LL(0, 100); 
	int _0 = ColorfulLineGraphs().countWays(N, K, M);
	int _1 = ColorfulLineGraphsRef().countWays(N, K, M);
	if(!verify_case(_0, _1, true)) {
print(N);
print(K);
print(M);
	}
}
#endif

}
// END CUT HERE
