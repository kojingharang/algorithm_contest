// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Let A be a matrix with N rows and N columns and P be a permutation of integers from 0 to N-1. Consider the following sum: Sum(A, P) = A[0, P[0]] + A[1, P[1]] + ... + A[N-1, P[N-1]], where A[i, j] is the element of A in row i and column j (all indices in this problem are 0-based). The matrix A is called nice if Sum(A, P) is always equal to the same value disregarding of the choice of permutation P.

Fox Ciel wants to draw a nice matrix on the blackboard. She is given a vector <string> board. It contains N elements and each element contains N characters. If j-th character of board[i] is a digit '0', '1', '2', ..., '9', then A[i, j] must be equal to this digit. If j-th character of board[i] is '-', then A[i, j] can be equal to any non-negative integer (it is allowed to be greater than 9).

Let T be the number of different matrices that satisfy all Ciel's requirements (the constraints will guarantee that the number of such matrices is finite). Compute and return the value of (T modulo 1,000,000,007).


DEFINITION
Class:EqualSums
Method:count
Parameters:vector <string>
Returns:int
Method signature:int count(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain exactly N characters, where N is the number of elements in board.
-Each character in board will be one of '-', '0', '1', '2', ..., '9'.
-The number of matrices that satisfy all Ciel's requirements will be finite.


EXAMPLES

0)
{"1-",
 "-2"}

Returns: 4

The sum A[0, 1] + A[1, 0] must be equal to 3.

1)
{"123",
 "4--",
 "--9"}

Returns: 1



2)
{"9--",
 "-9-",
 "--9"}

Returns: 271



3)
{"11",
 "12"}

Returns: 0

There are no nice matrices that match the given board, so T = 0.

4)
{"-4--",
 "-0-2",
 "--1-",
 "4---"}


Returns: 10



5)
{"--2",
 "02-",
 "-10"}


Returns: 0



6)
{"----------1---------------0-----7-----------------",
 "-----4--------------------------------------------",
 "--------5-------------5-3---5---------------6-----",
 "-------2----------1-------------------------------",
 "-----4--------------------------------------------",
 "-----3--------------------------------------------",
 "-6----------5-------------------------------------",
 "-------------------------------7---5----------6---",
 "--------6-------------6-4---6---------------7-----",
 "-------------4----------------5-------------------",
 "3------------------------------------------6------",
 "3------------------------------------------6------",
 "-------------4----------------5-------------------",
 "---------------2-------------------------3--------",
 "--2------------------------------------------2----",
 "---8---------------1-------------------3----------",
 "---------------3----------------------------------",
 "----7----------------5---0-----------------------5",
 "----------------5-------------------------3-----1-",
 "----------1---------------0-----7-----------------",
 "-------------5----------------6-------------------",
 "-7----------6-------------------------------------",
 "---8---------------1-------------------3----------",
 "-----------------------3--------------------------",
 "----8----------------6---1-----------------------6",
 "------------------------------------------4-----2-",
 "-----------5---------------5----------------------",
 "-----------------------------6--------------------",
 "----8----------------6---1-----------------------6",
 "----------------5-------------------------3-----1-",
 "-------------------------------6---4--2-------5---",
 "-6----------5-------------------------------------",
 "--------5-------------5-3---5---------------6-----",
 "-------------5----------------6-------------------",
 "-----3--------------------------------------------",
 "---------------2-------------------------3--------",
 "---------4---------------------------6------------",
 "-------------------------------6---4--2-------5---",
 "------2-------------1------------22---------------",
 "--------5-------------5-3---5---------------6-----",
 "-----------5--3------------5----------------------",
 "--2------------------------------------------2----",
 "---------5---------------------------7------------",
 "-------------4----------------5-------------------",
 "-----------------5------------------4---6------2--",
 "-------------------------------6---4--2-------5---",
 "-----------------------2--------------------------",
 "----------------6-------------------------4-----2-", 
 "-------------------------------6---4--2-------5---",
 "--------5-------------5-3---5---------------6-----"}

Returns: 45094393



*/
// END CUT HERE
#line 142 "EqualSums.cpp"

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



class EqualSums {
	public:
	int count(vector <string> board) {
		
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
#define END	 verify_case(_, EqualSums().count(board));}
int main(){

CASE(0)
	string board_[] = {"1-",
 "-2"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 4; 
END
CASE(1)
	string board_[] = {"123",
 "4--",
 "--9"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 1; 
END
CASE(2)
	string board_[] = {"9--",
 "-9-",
 "--9"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 271; 
END
CASE(3)
	string board_[] = {"11",
 "12"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 0; 
END
CASE(4)
	string board_[] = {"-4--",
 "-0-2",
 "--1-",
 "4---"}
;
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 10; 
END
CASE(5)
	string board_[] = {"--2",
 "02-",
 "-10"}
;
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 0; 
END
CASE(6)
	string board_[] = {"----------1---------------0-----7-----------------",
 "-----4--------------------------------------------",
 "--------5-------------5-3---5---------------6-----",
 "-------2----------1-------------------------------",
 "-----4--------------------------------------------",
 "-----3--------------------------------------------",
 "-6----------5-------------------------------------",
 "-------------------------------7---5----------6---",
 "--------6-------------6-4---6---------------7-----",
 "-------------4----------------5-------------------",
 "3------------------------------------------6------",
 "3------------------------------------------6------",
 "-------------4----------------5-------------------",
 "---------------2-------------------------3--------",
 "--2------------------------------------------2----",
 "---8---------------1-------------------3----------",
 "---------------3----------------------------------",
 "----7----------------5---0-----------------------5",
 "----------------5-------------------------3-----1-",
 "----------1---------------0-----7-----------------",
 "-------------5----------------6-------------------",
 "-7----------6-------------------------------------",
 "---8---------------1-------------------3----------",
 "-----------------------3--------------------------",
 "----8----------------6---1-----------------------6",
 "------------------------------------------4-----2-",
 "-----------5---------------5----------------------",
 "-----------------------------6--------------------",
 "----8----------------6---1-----------------------6",
 "----------------5-------------------------3-----1-",
 "-------------------------------6---4--2-------5---",
 "-6----------5-------------------------------------",
 "--------5-------------5-3---5---------------6-----",
 "-------------5----------------6-------------------",
 "-----3--------------------------------------------",
 "---------------2-------------------------3--------",
 "---------4---------------------------6------------",
 "-------------------------------6---4--2-------5---",
 "------2-------------1------------22---------------",
 "--------5-------------5-3---5---------------6-----",
 "-----------5--3------------5----------------------",
 "--2------------------------------------------2----",
 "---------5---------------------------7------------",
 "-------------4----------------5-------------------",
 "-----------------5------------------4---6------2--",
 "-------------------------------6---4--2-------5---",
 "-----------------------2--------------------------",
 "----------------6-------------------------4-----2-", 
 "-------------------------------6---4--2-------5---",
 "--------5-------------5-3---5---------------6-----"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 45094393; 
END

}
// END CUT HERE
