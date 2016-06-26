// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// You have two trees with the same number of nodes.
The nodes in each tree are labeled 0 through n-1.



You are given four vector <int>s with n-1 elements each: a, b, c, and d.
The vector <int>s a and b describe the first tree:
for each valid i, the first tree contains an edge between nodes labeled a[i] and b[i].
The vector <int>s c and d describe the second tree in the same way.



Each of the values 0 through n-1 has an assigned integer score.
These scores are given in an vector <int> score.
Note that some of the scores may be negative.



Your goal is to select a subset S of the set {0, 1, ..., n-1} with the following properties:

In the first tree, the nodes with the labels in S induce a connected subgraph (a subtree of the original tree).
In the second tree, the nodes with the labels in S also induce a connected subgraph.




Return the largest possible sum of scores assigned to the elements of such a subset S.

DEFINITION
Class:DoubleTree
Method:maximalScore
Parameters:vector <int>, vector <int>, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int maximalScore(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> score)


NOTES
-As there are only finitely many possible subsets S and the empty subset always has the desired properties, the return value is always correctly defined.


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-a and b will describe a tree with exactly n ndoes.
-c and d will describe a tree with exactly n ndoes.
-score will contain exactly n elements.
-Each element in score will be between -1,000 and 1,000, inclusive.


EXAMPLES

0)
{0,0,1}
{1,3,2}
{0,0,3}
{1,3,2}
{1000,24,100,-200}

Returns: 1024

The best subset we can choose is {0,1}.
The nodes labeled 0 and 1 are connected by an edge in each of the trees.
Note that we cannot choose {0,1,2} as in the second tree we cannot get from 0 to 2 without going through 3.

1)
{0,0,1}
{1,3,2}
{0,0,3}
{1,3,2}
{1000,24,100,200}

Returns: 1324

As in this case all scores are positive, the best solution is to select all labels.

2)
{0,0,1}
{1,3,2}
{0,0,3}
{1,3,2}
{-1000,-24,-100,-200}

Returns: 0

As in this case all scores are negative, the best solution is to select no labels at all.

3)
{0,0,1}
{1,3,2}
{0,0,3}
{1,3,2}
{-1000,24,100,200}

Returns: 200

The optimal solution is to choose the subset {3} - a single node is connected.

4)
{0,0,1,1,2,2}
{1,2,3,4,5,6}
{0,0,1,1,2,2}
{1,2,3,4,5,6}
{-3,2,2,-1,2,2,-1}

Returns: 5

In this test case the two trees are identical. The answer is the maximum score of a subtree of this tree.

5)
{0,0,1,1,2,2}
{1,2,3,4,5,6}
{0,0,0,0,0,0}
{1,2,3,4,5,6}
{-3,2,2,-1,2,2,-1}

Returns: 5



******************************/
// END CUT HERE
#line 125 "DoubleTree.cpp"
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

class DoubleTree {
	public:
	int maximalScore(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> score) {
		
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
#define END	 verify_case(_, DoubleTree().maximalScore(a, b, c, d, score));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int a_[] = {0,0,1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {1,3,2};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	int c_[] = {0,0,3};
	  vector <int> c(c_, c_+sizeof(c_)/sizeof(*c_)); 
	int d_[] = {1,3,2};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	int score_[] = {1000,24,100,-200};
	  vector <int> score(score_, score_+sizeof(score_)/sizeof(*score_)); 
	int _ = 1024; 
END
CASE(1)
	int a_[] = {0,0,1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {1,3,2};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	int c_[] = {0,0,3};
	  vector <int> c(c_, c_+sizeof(c_)/sizeof(*c_)); 
	int d_[] = {1,3,2};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	int score_[] = {1000,24,100,200};
	  vector <int> score(score_, score_+sizeof(score_)/sizeof(*score_)); 
	int _ = 1324; 
END
CASE(2)
	int a_[] = {0,0,1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {1,3,2};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	int c_[] = {0,0,3};
	  vector <int> c(c_, c_+sizeof(c_)/sizeof(*c_)); 
	int d_[] = {1,3,2};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	int score_[] = {-1000,-24,-100,-200};
	  vector <int> score(score_, score_+sizeof(score_)/sizeof(*score_)); 
	int _ = 0; 
END
CASE(3)
	int a_[] = {0,0,1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {1,3,2};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	int c_[] = {0,0,3};
	  vector <int> c(c_, c_+sizeof(c_)/sizeof(*c_)); 
	int d_[] = {1,3,2};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	int score_[] = {-1000,24,100,200};
	  vector <int> score(score_, score_+sizeof(score_)/sizeof(*score_)); 
	int _ = 200; 
END
CASE(4)
	int a_[] = {0,0,1,1,2,2};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {1,2,3,4,5,6};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	int c_[] = {0,0,1,1,2,2};
	  vector <int> c(c_, c_+sizeof(c_)/sizeof(*c_)); 
	int d_[] = {1,2,3,4,5,6};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	int score_[] = {-3,2,2,-1,2,2,-1};
	  vector <int> score(score_, score_+sizeof(score_)/sizeof(*score_)); 
	int _ = 5; 
END
CASE(5)
	int a_[] = {0,0,1,1,2,2};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {1,2,3,4,5,6};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	int c_[] = {0,0,0,0,0,0};
	  vector <int> c(c_, c_+sizeof(c_)/sizeof(*c_)); 
	int d_[] = {1,2,3,4,5,6};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	int score_[] = {-3,2,2,-1,2,2,-1};
	  vector <int> score(score_, score_+sizeof(score_)/sizeof(*score_)); 
	int _ = 5; 
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
	vector <int> a; 
	{
		int N=UNIFORM_LL(1, 51);
		a = vector <int>(N); 
		REP(i, N) {
			a[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> b; 
	{
		int N=UNIFORM_LL(1, 51);
		b = vector <int>(N); 
		REP(i, N) {
			b[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> c; 
	{
		int N=UNIFORM_LL(1, 51);
		c = vector <int>(N); 
		REP(i, N) {
			c[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> d; 
	{
		int N=UNIFORM_LL(1, 51);
		d = vector <int>(N); 
		REP(i, N) {
			d[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> score; 
	{
		int N=UNIFORM_LL(1, 51);
		score = vector <int>(N); 
		REP(i, N) {
			score[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = DoubleTree().maximalScore(a, b, c, d, score);
	int _1 = DoubleTreeRef().maximalScore(a, b, c, d, score);
	if(!verify_case(_0, _1, true)) {
print(a);
print(b);
print(c);
print(d);
print(score);
	}
}
#endif

}
// END CUT HERE
