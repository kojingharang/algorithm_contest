// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// This problem statement contains superscripts and/or subscripts. These may not display properly outside the applet.

Manao is studying graph theory and simple cycles in particular. A simple cycle of length L ? 3 in graph G is a sequence of vertices (v0, v1, ..., vL-1) such that all v0, v1, ..., vL-1 are pairwise distinct and for each i=0..L-1, an edge between vi and v(i+1) mod L exists in G.

Manao is interested in graphs formed by connecting two trees. The connection process is as follows. Manao takes two trees composed of N vertices each. The vertices in each tree are labeled from 0 to N - 1. Then, he generates a permutation P of numbers from 0 to N - 1 uniformly at random. Finally, the graph is formed by connecting vertex i of the first tree to vertex P[i] of the second tree, for each i from 0 to N - 1. To remove ambiguity, the vertices of the first tree within the graph are referred to as A0, A1, ..., AN-1 and the vertices of the second graph are referred to as B0, B1, ..., BN-1. Manao wants to know the expected number of simple cycles of length K in the resulting graph.

You are given two vector <string>s, tree1 and tree2. Merge the elements of tree1 to obtain a single string formatted as a space-separated list of N - 1 integers describing the first tree. Let x[i] denote the i-th integer (0-based index) in the list. Then, for each i, we have 0 ? x[i] ? i and in our tree the vertices x[i] and i+1 are connected by an edge. tree2 describes the second tree in the same fashion.
Compute and return the expected number of simple cycles of length K in the graph formed by connecting the two given trees as described above. Two simple cycles are equal if one of them can be cyclically shifted, or reversed and cyclically shifted, to coincide with the second. According to this definition, (1, 2, 3, 4), (2, 3, 4, 1) and (3, 2, 1, 4) are all equal.

DEFINITION
Class:TreeUnion
Method:expectedCycles
Parameters:vector <string>, vector <string>, int
Returns:double
Method signature:double expectedCycles(vector <string> tree1, vector <string> tree2, int K)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-The concatenation of elements of tree1 will be formatted as a space-separated list of N - 1 integers, where N is between 2 and 300, inclusive.
-tree1 will contain between 1 and 50 elements, inclusive.
-Each element of tree1 will be between 1 and 50 characters long, inclusive.
-For each i, the i-th integer (0-based index) in the concatenation of elements of tree1 will be between 0 and i, inclusive, and will have no extra leading zeros.
-The concatenation of elements of tree2 will be formatted as a space-separated list of N - 1 integers, where N is between 2 and 300, inclusive.
-tree2 will contain between 1 and 50 elements, inclusive.
-Each element of tree2 will be between 1 and 50 characters long, inclusive.
-For each i, the i-th integer (0-based index) in the concatenation of elements of tree2 will be between 0 and i, inclusive, and will have no extra leading zeros.
-K will be between 3 and 7, inclusive.


EXAMPLES

0)
{"0"}
{"0"}
4

Returns: 1.0

Manao has two trees with two vertices each. He can connect them in two ways:



Either way, the resulting graph is a single cycle of length 4.

1)
{"0 1"}
{"0 1"}
4

Returns: 1.3333333333333333

Manao has two chains composed of three vertices each. There are 6 possible permutations which result in the following graphs:



Each of the two graphs shown in the topmost row contains two cycles of length 4.
(Note that in each case the two cycles share the edge A1B1.)
Each of the other four graphs only contains one cycle of length 4.
Thus the expected number of cycles of length 4 is (2+2+1+1+1+1)/6 = 8/6 = 1.3333333333.

2)
{"0 1"}
{"0 1"}
6

Returns: 0.3333333333333333

These are the same trees as in the previous example, but this time Manao is looking for simple cycles with 6 vertices. Only the topmost two graphs contain a cycle of length 6, thus the expected number of such cycles for a random permutation P is 1/3.

3)
{"0 ", "1 1 1"}
{"0 1 0 ", "1"}
5

Returns: 4.0

The corresponding trees are these:




4)
{"0 1 2 0 1 2 0 1 2 5 6 1", "0 11", " 4"}
{"0 1 1 0 2 3 4 3 4 6 6", " 10 12 12"}
7

Returns: 13.314285714285713

Do not forget to concatenate the elements of the lists first.

*/
// END CUT HERE
#line 101 "TreeUnion.cpp"

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
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class TreeUnion {
	public:
	double expectedCycles(vector <string> tree1, vector <string> tree2, int K) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//mplate<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// os << "{ ";
// for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
// os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const double& Expected, const double& Received) {
 double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, TreeUnion().expectedCycles(tree1, tree2, K));}
int main(){

CASE(0)
	string tree1_[] = {"0"};
	  vector <string> tree1(tree1_, tree1_+sizeof(tree1_)/sizeof(*tree1_)); 
	string tree2_[] = {"0"};
	  vector <string> tree2(tree2_, tree2_+sizeof(tree2_)/sizeof(*tree2_)); 
	int K = 4; 
	double _ = 1.0; 
END
CASE(1)
	string tree1_[] = {"0 1"};
	  vector <string> tree1(tree1_, tree1_+sizeof(tree1_)/sizeof(*tree1_)); 
	string tree2_[] = {"0 1"};
	  vector <string> tree2(tree2_, tree2_+sizeof(tree2_)/sizeof(*tree2_)); 
	int K = 4; 
	double _ = 1.3333333333333333; 
END
CASE(2)
	string tree1_[] = {"0 1"};
	  vector <string> tree1(tree1_, tree1_+sizeof(tree1_)/sizeof(*tree1_)); 
	string tree2_[] = {"0 1"};
	  vector <string> tree2(tree2_, tree2_+sizeof(tree2_)/sizeof(*tree2_)); 
	int K = 6; 
	double _ = 0.3333333333333333; 
END
CASE(3)
	string tree1_[] = {"0 ", "1 1 1"};
	  vector <string> tree1(tree1_, tree1_+sizeof(tree1_)/sizeof(*tree1_)); 
	string tree2_[] = {"0 1 0 ", "1"};
	  vector <string> tree2(tree2_, tree2_+sizeof(tree2_)/sizeof(*tree2_)); 
	int K = 5; 
	double _ = 4.0; 
END
CASE(4)
	string tree1_[] = {"0 1 2 0 1 2 0 1 2 5 6 1", "0 11", " 4"};
	  vector <string> tree1(tree1_, tree1_+sizeof(tree1_)/sizeof(*tree1_)); 
	string tree2_[] = {"0 1 1 0 2 3 4 3 4 6 6", " 10 12 12"};
	  vector <string> tree2(tree2_, tree2_+sizeof(tree2_)/sizeof(*tree2_)); 
	int K = 7; 
	double _ = 13.314285714285713; 
END

}
// END CUT HERE
