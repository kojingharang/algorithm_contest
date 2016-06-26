// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Elly has placed several (possibly none) figurines on a rectangular board with several rows and columns. Now Kristina wants to remove all figurines from the board. In a single move she selects either up to R consecutive rows, or up to C consecutive columns and removes all remaining figurines that are located there. The girl wonders what is the minimal number of moves in which she can clear the entire board.

The position of the figurines will be given to you in the vector <string> board. The j-th character of the i-th element of board will be '.' if the cell is empty, or 'X' if it contains a figurine. The maximal number of cleared rows in a single move will be given in the int R. The maximal number of cleared columns in a single move will be given in the int C. Return the minimal number of moves that is sufficient to clear the entire board.

DEFINITION
Class:EllysFigurines
Method:getMoves
Parameters:vector <string>, int, int
Returns:int
Method signature:int getMoves(vector <string> board, int R, int C)


NOTES
-In a single move the girl can only select a consecutive group of rows or columns to be cleared. In other words, in each move Kristina first decides whether she wants rows or columns, then she picks the index i of the first chosen row/column, then the number k of chosen rows/columns, and finally she removes all figurines from the rows/columns with indices i, i+1, i+2, ..., i+k-1.


CONSTRAINTS
-board will contain between 1 and 15 elements, inclusive.
-Each element of board will contain between 1 and 15 characters, inclusive.
-All elements of board will contain the same number of characters.
-Each character of board will be either '.' or 'X'.
-R will be between 1 and 15, inclusive.
-C will be between 1 and 15, inclusive.


EXAMPLES

0)
{".X.X.",
 "XX..X",
 ".XXX.",
 "...X.",
 ".X.XX"}
1
2

Returns: 3

In this case in a single move Elly can remove all figurines from a single row, all figurines from a single column or all figurines from two consecutive columns.
One way to achieve the optimal answer here would be to remove the figurines from the first and second column in the first move, then the ones from the fourth and fifth column in the second move, and finally the remaining ones on the third row in the third move.
Another solution would be to erase only columns, again using three moves.

1)
{".X.X.",
 "XX..X",
 ".X.X.",
 "...X.",
 ".X.XX"}
2
2

Returns: 2

Almost the same as the first example, but without the figurine in the middle and the number of maximal rows removed is increased by one.
This time, the only optimal solution is to clear the first two columns in one move and the last two in another move.

2)
{"XXXXXXX"}
2
3

Returns: 1

The maximal allowed number of cleared rows or columns might be greater than the corresponding dimension of the board. The optimal solution for this board is to clear the only row in one move.

3)
{"XXXXX",
 "X....",
 "XXX..",
 "X....",
 "XXXXX"}
1
1

Returns: 4

Here clearing rows 1, 3 and 5, together with column 1 yields the best result 4.

4)
{"XXX..XXX..XXX.",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X...XXX..XXX.",
 "..............",
 "...XX...XXX...",
 "....X......X..",
 "....X....XXX..",
 "....X......X..",
 "...XXX..XXX..."}
1
2

Returns: 7

Good luck in TCO 13!

*/
// END CUT HERE
#line 104 "EllysFigurines.cpp"

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






class EllysFigurines {
	public:
	int getMoves(vector<string> B, int R, int C) {
		int W=B[0].size();
		int H=B.size();
		int ans = 1<<30;
		REP(bit, 1<<H) {
			int lans=0;
			int rmy[20]={};
			int rest[20]={};
			REP(y, H) {
				if((bit>>y)&1) {
					lans++;
					REP(i, R) if(y+i<H) rmy[y+i]=1;
				}
				if(!rmy[y]) REP(x, W) if(B[y][x]=='X') rest[x]=1;
			}
			REP(x, W) {
				if(rest[x]) {
					lans++;
					x+=C-1;
				}
			}
			ans=min(ans, lans);
		}
		return ans;
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
#define END	 verify_case(_, EllysFigurines().getMoves(board, R, C));}
int main(){

CASE(0)
	string board_[] = {
".X.X.X.X.X.X.X.", 
"XXXXXXXXXXXXXXX", 
".X.X.X.X.X.X.X.", 
"XXXXXXXXXXXXXXX", 
".X.X.X.X.X.X.X.", 
"XXXXXXXXXXXXXXX", 
".X.X.X.X.X.X.X.", 
"XXXXXXXXXXXXXXX", 
".X.X.X.X.X.X.X.", 
"XXXXXXXXXXXXXXX", 
".X.X.X.X.X.X.X.", 
"XXXXXXXXXXXXXXX", 
".X.X.X.X.X.X.X.", 
"XXXXXXXXXXXXXXX", 
".X.X.X.X.X.X.X."};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int R = 1; 
	int C = 1; 
	int _ = 14; 
END
//return 0;
CASE(0)
	string board_[] = {
 ".X.X.",
 "XX..X",
 ".XXX.",
 "...X.",
 ".X.XX"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int R = 1; 
	int C = 2; 
	int _ = 3; 
END
CASE(1)
	string board_[] = {".X.X.",
 "XX..X",
 ".X.X.",
 "...X.",
 ".X.XX"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int R = 2; 
	int C = 2; 
	int _ = 2; 
END
CASE(2)
	string board_[] = {"XXXXXXX"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int R = 2; 
	int C = 3; 
	int _ = 1; 
END
CASE(3)
	string board_[] = {"XXXXX",
 "X....",
 "XXX..",
 "X....",
 "XXXXX"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int R = 1; 
	int C = 1; 
	int _ = 4; 
END
CASE(4)
	string board_[] = {"XXX..XXX..XXX.",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X...XXX..XXX.",
 "..............",
 "...XX...XXX...",
 "....X......X..",
 "....X....XXX..",
 "....X......X..",
 "...XXX..XXX..."};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int R = 1; 
	int C = 2; 
	int _ = 7; 
END

}
// END CUT HERE
