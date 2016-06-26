// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// John and Brus have two (a, b) chess knights.
When an (a, b) knight moves, it can move a squares horizontally and b squares vertically, or b squares horizontally and a squares vertically.


John and Brus place their knights on two different cells of an n by n chessboard.
The pair of cells is chosen uniformly at random.
A chessboard cell is attacked if it is either occupied by one of the knights, or if it can be reached by one of the knights in a single move.
Return the expected number of attacked cells.


DEFINITION
Class:TheKnights
Method:find
Parameters:int, int, int
Returns:double
Method signature:double find(int n, int a, int b)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.
-Informally, the expected number of attacked cells can be seen as the average number over very many rounds of the process. See http://en.wikipedia.org/wiki/Expected_value for a formal definition.


CONSTRAINTS
-n will be between 2 and 1,000,000,000, inclusive.
-a will be between 1 and 1,000,000,000, inclusive.
-b will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
2
1
1

Returns: 3.3333333333333335

If we fix one of the knights, there are three ways to place the other one.
In two of those three cases all 4 cells on the board will be attacked.
In the last case only the 2 cells occupied by the knights will be attacked.
Thus the expected value is 4*(2/3) + 2*(1/3) =  10/3.


1)
47
7
74

Returns: 2.0

For any placement of the knights only two cells will be attacked.

2)
3
2
1

Returns: 4.888888888888889



3)
9999
999
99

Returns: 16.25885103191273



4)
10
1
6

Returns: 7.636363636363637



*/
// END CUT HERE
#line 87 "TheKnights.cpp"

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



class TheKnights {
	public:
	double find(int n, int a, int b) {
		
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
#define END	 verify_case(_, TheKnights().find(n, a, b));}
int main(){

CASE(0)
	int n = 2; 
	int a = 1; 
	int b = 1; 
	double _ = 3.3333333333333335; 
END
CASE(1)
	int n = 47; 
	int a = 7; 
	int b = 74; 
	double _ = 2.0; 
END
CASE(2)
	int n = 3; 
	int a = 2; 
	int b = 1; 
	double _ = 4.888888888888889; 
END
CASE(3)
	int n = 9999; 
	int a = 999; 
	int b = 99; 
	double _ = 16.25885103191273; 
END
CASE(4)
	int n = 10; 
	int a = 1; 
	int b = 6; 
	double _ = 7.636363636363637; 
END

}
// END CUT HERE
