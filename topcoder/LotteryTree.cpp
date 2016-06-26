// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// You held a lottery and P people participated in it.
Now you want to determine who won the lottery prize.

You have decided to choose the winner using a rooted tree.
You are going to make a lottery with the tree as follows:

The participants are conveniently numbered from 1 to P, inclusive.
First, you draw the tree onto a rectangular board in such a way that the tree satisfies the following conditions:

Each node of the tree corresponds to a small circle on the board.
The circles are so small that you can ignore their size.
Each edge of the tree corresponds to a line segment connecting two circles. 
No two edges are allowed to intersect. 
The root node must be drawn on the top edge of the board.
For each node, all edges to its children must be going downwards. (In other words, the parent of a node must always be drawn above the node.)
All of the leaves must be drawn on the bottom edge of the board.



Next, you split the bottom edge of the board into P segments in such a way that each leaf belongs to exactly one segment.
For each segment, you choose a different integer between 1 and P, inclusive, and write that integer into each of the leaves that belong to that segment.

Now, you will repeat the following process:
Find an empty node X such that you have already written integers into all of its children.
If there are multiple nodes with this property, choose one uniformly at random.
Choose a child of X uniformly at random, and copy the integer written in the chosen child into X.

The process terminates once the root node contains an integer.


You are given the int P and a vector <int> tree that describes the tree you will use.
The tree has N nodes, conveniently numbered 0 through N-1.
Node 0 is the root of the tree.
For each other node, the number of its parent is smaller than its own number.
More precisely, for each i between 1 and N-1, inclusive, tree[i-1] is the parent of node i.

You want to make the lottery fair.
That is, you want to guarantee that each of the participants will have the same probability to win the lottery. 
To do that, you can choose how to draw the tree, and how to assign integers to its leaves (while following the above procedure).

Return "YES" (quotes for clarity) if you can make the lottery fair and "NO" otherwise.


DEFINITION
Class:LotteryTree
Method:isFairTree
Parameters:vector <int>, int
Returns:string
Method signature:string isFairTree(vector <int> tree, int P)


CONSTRAINTS
-tree will have between 2 and 100 elements, inclusive.
-For each i, element i (0-based index) of tree will be between 0 and i, inclusive.
-P will be between 2 and 100, inclusive.
-Each node that is not a leaf will have at least 2 children.


EXAMPLES

0)
{0, 0, 0}
3

Returns: "YES"

One of the ways to draw the tree is as follows:





1)
{0, 0, 0, 1, 1, 2, 2, 3, 3}
2

Returns: "YES"

One of the ways to draw the tree is as follows:





Note that you cannot assign integers to the leaves as follows:




2)
{0, 0, 1, 1, 2, 2, 4, 4, 4}
3

Returns: "NO"

You would be able to make this tree fair if you were allowed to assign integers to leaves arbitrarily. However, given the additional restriction that each integer must be assigned to a consecutive segment of leaves, making this tree fair is not possible.

3)
{0, 0, 1, 1, 1, 3, 3, 3}
3

Returns: "NO"



4)
{0, 0, 0, 3, 0, 0, 3, 6, 3, 1, 0, 2, 0, 4, 6, 15, 1, 15, 11, 11, 1, 4, 11, 2, 11, 2, 6}

6

Returns: "YES"



5)
{0, 1, 2, 3, 1, 1, 4, 4, 0, 1, 6, 9, 1, 12, 9, 2, 4, 8, 6, 13, 8, 5, 11, 12, 17, 
 19, 13, 9, 3, 24, 30, 29, 28, 28, 11, 27, 2, 26, 6, 14, 8, 26, 15, 25, 33, 38, 
 1, 24, 15, 43, 3, 39, 26, 8, 13, 50, 28, 8, 6, 27, 8, 38, 27, 50, 17, 50, 25, 
 40, 7, 29, 22, 40, 2, 24, 22, 30, 33, 40, 19, 14, 26, 39, 5, 43, 7, 4}
9

Returns: "NO"



6)
{0, 1, 0, 0, 4, 0, 2, 2, 0, 2, 6, 1, 3, 6, 5, 9, 11, 13, 1, 10, 14, 4, 7, 21,
 16, 8, 25, 4, 5, 22, 25, 14, 12, 11, 12, 26, 21, 8, 2, 38, 3, 5, 4, 38, 27, 
 35, 38, 30, 38, 9, 16, 36, 6, 10, 7, 27, 30, 33, 17, 26, 17, 10, 35, 10, 38,
 41, 15, 9, 3, 27, 8, 15, 38, 22, 41, 33, 33, 36, 30, 13, 18, 22, 18}
12

Returns: "YES"



7)
{0, 0, 2, 3, 4, 3, 2, 1, 8, 6, 8, 8, 2, 7, 14, 2, 8, 1, 11, 11, 12, 16, 12, 
 19, 20, 13, 7, 12, 26, 11, 18, 19, 18, 20, 4, 9, 1, 1, 6, 16, 1, 35, 27, 24,
 37, 30, 36, 41, 32, 36, 8, 2, 6, 14, 41, 1, 35, 6, 30, 16, 12, 2, 35, 25, 50,
 13, 1, 24, 8, 32, 26, 50, 9, 19, 9, 20, 26, 27, 6, 12, 25, 9, 37, 37, 9} 
7

Returns: "NO"



8)
{0, 0, 1, 0, 2, 3, 0, 0, 8, 5, 7, 5, 2, 12, 12, 14, 14, 13, 8, 2, 1, 7, 18,
 16, 8, 24, 18, 2, 24, 3, 11, 5, 24, 4, 34, 6, 31, 13, 38, 19, 4, 3, 22, 3,
 11, 12, 21, 34, 41, 8, 19, 4, 13, 29, 33, 8, 14, 50, 18, 45, 16, 50, 44, 50,
 38, 5, 43, 31, 29, 7, 6, 45, 38, 4, 19, 41, 50, 21, 44, 41, 43, 22, 33, 6, 8}

12

Returns: "YES"



******************************/
// END CUT HERE
#line 166 "LotteryTree.cpp"
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

class LotteryTree {
	public:
	string isFairTree(vector <int> tree, int P) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const string& Expected, const string& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, LotteryTree().isFairTree(tree, P));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int tree_[] = {0, 0, 0};
	  vector <int> tree(tree_, tree_+sizeof(tree_)/sizeof(*tree_)); 
	int P = 3; 
	string _ = "YES"; 
END
CASE(1)
	int tree_[] = {0, 0, 0, 1, 1, 2, 2, 3, 3};
	  vector <int> tree(tree_, tree_+sizeof(tree_)/sizeof(*tree_)); 
	int P = 2; 
	string _ = "YES"; 
END
CASE(2)
	int tree_[] = {0, 0, 1, 1, 2, 2, 4, 4, 4};
	  vector <int> tree(tree_, tree_+sizeof(tree_)/sizeof(*tree_)); 
	int P = 3; 
	string _ = "NO"; 
END
CASE(3)
	int tree_[] = {0, 0, 1, 1, 1, 3, 3, 3};
	  vector <int> tree(tree_, tree_+sizeof(tree_)/sizeof(*tree_)); 
	int P = 3; 
	string _ = "NO"; 
END
CASE(4)
	int tree_[] = {0, 0, 0, 3, 0, 0, 3, 6, 3, 1, 0, 2, 0, 4, 6, 15, 1, 15, 11, 11, 1, 4, 11, 2, 11, 2, 6}
;
	  vector <int> tree(tree_, tree_+sizeof(tree_)/sizeof(*tree_)); 
	int P = 6; 
	string _ = "YES"; 
END
CASE(5)
	int tree_[] = {0, 1, 2, 3, 1, 1, 4, 4, 0, 1, 6, 9, 1, 12, 9, 2, 4, 8, 6, 13, 8, 5, 11, 12, 17, 
 19, 13, 9, 3, 24, 30, 29, 28, 28, 11, 27, 2, 26, 6, 14, 8, 26, 15, 25, 33, 38, 
 1, 24, 15, 43, 3, 39, 26, 8, 13, 50, 28, 8, 6, 27, 8, 38, 27, 50, 17, 50, 25, 
 40, 7, 29, 22, 40, 2, 24, 22, 30, 33, 40, 19, 14, 26, 39, 5, 43, 7, 4};
	  vector <int> tree(tree_, tree_+sizeof(tree_)/sizeof(*tree_)); 
	int P = 9; 
	string _ = "NO"; 
END
CASE(6)
	int tree_[] = {0, 1, 0, 0, 4, 0, 2, 2, 0, 2, 6, 1, 3, 6, 5, 9, 11, 13, 1, 10, 14, 4, 7, 21,
 16, 8, 25, 4, 5, 22, 25, 14, 12, 11, 12, 26, 21, 8, 2, 38, 3, 5, 4, 38, 27, 
 35, 38, 30, 38, 9, 16, 36, 6, 10, 7, 27, 30, 33, 17, 26, 17, 10, 35, 10, 38,
 41, 15, 9, 3, 27, 8, 15, 38, 22, 41, 33, 33, 36, 30, 13, 18, 22, 18};
	  vector <int> tree(tree_, tree_+sizeof(tree_)/sizeof(*tree_)); 
	int P = 12; 
	string _ = "YES"; 
END
CASE(7)
	int tree_[] = {0, 0, 2, 3, 4, 3, 2, 1, 8, 6, 8, 8, 2, 7, 14, 2, 8, 1, 11, 11, 12, 16, 12, 
 19, 20, 13, 7, 12, 26, 11, 18, 19, 18, 20, 4, 9, 1, 1, 6, 16, 1, 35, 27, 24,
 37, 30, 36, 41, 32, 36, 8, 2, 6, 14, 41, 1, 35, 6, 30, 16, 12, 2, 35, 25, 50,
 13, 1, 24, 8, 32, 26, 50, 9, 19, 9, 20, 26, 27, 6, 12, 25, 9, 37, 37, 9} ;
	  vector <int> tree(tree_, tree_+sizeof(tree_)/sizeof(*tree_)); 
	int P = 7; 
	string _ = "NO"; 
END
CASE(8)
	int tree_[] = {0, 0, 1, 0, 2, 3, 0, 0, 8, 5, 7, 5, 2, 12, 12, 14, 14, 13, 8, 2, 1, 7, 18,
 16, 8, 24, 18, 2, 24, 3, 11, 5, 24, 4, 34, 6, 31, 13, 38, 19, 4, 3, 22, 3,
 11, 12, 21, 34, 41, 8, 19, 4, 13, 29, 33, 8, 14, 50, 18, 45, 16, 50, 44, 50,
 38, 5, 43, 31, 29, 7, 6, 45, 38, 4, 19, 41, 50, 21, 44, 41, 43, 22, 33, 6, 8}
;
	  vector <int> tree(tree_, tree_+sizeof(tree_)/sizeof(*tree_)); 
	int P = 12; 
	string _ = "YES"; 
END
#if 0  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10;loop++) {
// param type: int
start_time=clock();
	vector <int> tree; 
	{
		int N=UNIFORM_LL(1, 50);
		tree = vector <int>(N); 
		REP(i, N) {
			tree[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
start_time=clock();
	int P = UNIFORM_LL(0, 100); 
	string _0 = LotteryTree().isFairTree(tree, P);
	string _1 = LotteryTreeTry().isFairTree(tree, P);
	if(!verify_case(_0, _1, true)) {
print(tree);
print(P);
	}
}
#endif

}
// END CUT HERE
