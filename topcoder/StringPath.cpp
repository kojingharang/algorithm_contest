// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Manao has a rectangular board divided into n times m cells.
The rows of the board are numbered from 1 to n and the columns are numbered from 1 to m.
The cell in row i, column j is referred to as (i, j).
Each cell contains an uppercase letter of the English alphabet.

Having such a board, Manao likes to traverse it.
The traversal always starts in the cell (1, 1).
In each step of the traversal Manao moves either one cell down or one cell to the right.
That is, from any cell (x, y) Manao will move either to (x+1, y) or to (x, y+1).
The traversal always ends in the cell (n, m).
During the traversal Manao records the letters in the visited cells (including the first and the last cell).
The obtained string is called a string path for the given board.

You are given the ints n and m, and two distinct strings A and B.
Manao claims that he performed two different traversals of his n x m board and obtained the string paths A and B.
Compute the number of different boards for which this is possible.
Return this number modulo 1,000,000,009.


DEFINITION
Class:StringPath
Method:countBoards
Parameters:int, int, string, string
Returns:int
Method signature:int countBoards(int n, int m, string A, string B)


CONSTRAINTS
-n will be between 1 and 8, inclusive.
-m will be between 1 and 8, inclusive.
-A and B will be exactly n+m-1 characters long.
-A and B will consist of uppercase letters ('A'-'Z') only.
-A and B will be distinct.


EXAMPLES

0)
2
2
"ABC"
"ADC"

Returns: 2

The two possible boards are:


AB  AD
DC  BC


1)
2
2
"ABC"
"ABD"

Returns: 0

It is impossible for two string paths to have a different last letter.

2)
3
4
"ABCDDE"
"ACCBDE"

Returns: 1899302



3)
8
8
"ZZZZZZZZZZZZZZZ"
"ZABCDEFGHIJKLMZ"

Returns: 120390576



******************************/
// END CUT HERE
#line 89 "StringPath.cpp"
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

class StringPath {
	public:
	int countBoards(int n, int m, string A, string B) {
		
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
#define END	 verify_case(_, StringPath().countBoards(n, m, A, B));}
int main(){

CASE(0)
	int n = 2; 
	int m = 2; 
	string A = "ABC"; 
	string B = "ADC"; 
	int _ = 2; 
END
CASE(1)
	int n = 2; 
	int m = 2; 
	string A = "ABC"; 
	string B = "ABD"; 
	int _ = 0; 
END
CASE(2)
	int n = 3; 
	int m = 4; 
	string A = "ABCDDE"; 
	string B = "ACCBDE"; 
	int _ = 1899302; 
END
CASE(3)
	int n = 8; 
	int m = 8; 
	string A = "ZZZZZZZZZZZZZZZ"; 
	string B = "ZABCDEFGHIJKLMZ"; 
	int _ = 120390576; 
END

}
// END CUT HERE
