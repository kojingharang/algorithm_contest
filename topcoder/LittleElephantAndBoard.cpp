// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Little Elephant from the Zoo of Lviv has a board with 2 rows and M columns. Each cell of the board must be painted in one of three colors: red, green, or blue.




The board is called magical if and only if it has the following properties:


No two adjacent cells share the same color. (Two cells are adjacent if they share an edge.)


Every 2x2 block contains at least one cell of each of the three colors.




You are given four ints M, R, G and B. Let X be the total number of different magical boards with 2 rows and M columns that contain exactly R red cells, G green cells, and B blue cells. Return the value (X modulo 1,000,000,007).



DEFINITION
Class:LittleElephantAndBoard
Method:getNumber
Parameters:int, int, int, int
Returns:int
Method signature:int getNumber(int M, int R, int G, int B)


CONSTRAINTS
-M will be between 2 and 1,000,000, inclusive.
-R, G and B will each be between 0 and 1,000,000, inclusive.
-R+G+B will be equal to 2M.


EXAMPLES

0)
2
2
1
1

Returns: 4

The following 4 different magical boards are possible in this case:







1)
2
2
2
0

Returns: 0

No magical board is possible in this case.

2)
10
7
7
6

Returns: 496



3)
474
250
300
398

Returns: 969878317



******************************/
// END CUT HERE
#line 90 "LittleElephantAndBoard.cpp"
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

class LittleElephantAndBoard {
	public:
	int getNumber(int M, int R, int G, int B) {
		
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
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, LittleElephantAndBoard().getNumber(M, R, G, B));}
int main(){

CASE(0)
	int M = 2; 
	int R = 2; 
	int G = 1; 
	int B = 1; 
	int _ = 4; 
END
CASE(1)
	int M = 2; 
	int R = 2; 
	int G = 2; 
	int B = 0; 
	int _ = 0; 
END
CASE(2)
	int M = 10; 
	int R = 7; 
	int G = 7; 
	int B = 6; 
	int _ = 496; 
END
CASE(3)
	int M = 474; 
	int R = 250; 
	int G = 300; 
	int B = 398; 
	int _ = 969878317; 
END

}
// END CUT HERE
