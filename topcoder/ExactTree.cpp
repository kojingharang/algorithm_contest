// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// In this problem, if a tree has x nodes, the nodes are numbered 0 through x-1.
Given a tree T, the distance dist(i,j) between nodes i and j is the number of edges on the unique simple path that connects them.
The sum of all pairwise distances in T, denoted S(T), is the sum of dist(i,j) over all pairs i,j such that i<j.


You are given ints n, m, and r.
We are interested in trees with the following properties:

The tree T has exactly n nodes (labeled 0 through n-1).
S(T) modulo m equals r.


If there are such trees, return the smallest possible value S(T).
Otherwise, return -1.

DEFINITION
Class:ExactTree
Method:getTree
Parameters:int, int, int
Returns:int
Method signature:int getTree(int n, int m, int r)


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-m will be between 2 and 100, inclusive.
-r will be between 0 and m-1, inclusive.


EXAMPLES

0)
4
100
9

Returns: 9

For a tree T on 4 vertices there are only two possible values of S(T): 9 and 10.
(One tree that has S(T)=9 is a tree with the edges 0-1, 0-2, and 0-3.
One tree that has S(T)=10 is a tree with the edges 0-1, 1-2, and 2-3.)

We are only interested in trees T such that S(T) modulo 100 = 9.
Given this constraint, the smallest actually possible value S(T) is 9.

1)
4
100
10

Returns: 10



2)
4
100
0

Returns: -1



3)
6
2
0

Returns: 28



4)
6
2
1

Returns: 25



5)
25
100
0

Returns: 700



6)
50
97
89

Returns: 2708



******************************/
// END CUT HERE
#line 106 "ExactTree.cpp"
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

class ExactTree {
	public:
	int getTree(int n, int m, int r) {
		
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
#define END	 verify_case(_, ExactTree().getTree(n, m, r));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int n = 4; 
	int m = 100; 
	int r = 9; 
	int _ = 9; 
END
CASE(1)
	int n = 4; 
	int m = 100; 
	int r = 10; 
	int _ = 10; 
END
CASE(2)
	int n = 4; 
	int m = 100; 
	int r = 0; 
	int _ = -1; 
END
CASE(3)
	int n = 6; 
	int m = 2; 
	int r = 0; 
	int _ = 28; 
END
CASE(4)
	int n = 6; 
	int m = 2; 
	int r = 1; 
	int _ = 25; 
END
CASE(5)
	int n = 25; 
	int m = 100; 
	int r = 0; 
	int _ = 700; 
END
CASE(6)
	int n = 50; 
	int m = 97; 
	int r = 89; 
	int _ = 2708; 
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
	int n = UNIFORM_LL(0, 100); 
// param type: int
	int m = UNIFORM_LL(0, 100); 
// param type: int
	int r = UNIFORM_LL(0, 100); 
	int _0 = ExactTree().getTree(n, m, r);
	int _1 = ExactTreeRef().getTree(n, m, r);
	if(!verify_case(_0, _1, true)) {
print(n);
print(m);
print(r);
	}
}
#endif

}
// END CUT HERE
