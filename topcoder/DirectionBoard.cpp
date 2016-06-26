// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A direction board is a matrix filled with arrows. Each arrow occupies one cell and points in one of the four directions: left, right, down, up. Each cell has two coordinates (row, column), starting with (0, 0) in the top left corner. Given a starting cell (r, c), you can move through the board in the following way. First, check the arrow in cell (r, c). If it points left, move left of the current cell, i.e. into cell(r, c - 1). For the right arrow, move to (r, c + 1). Up goes to (r - 1, c) and down to (r + 1, c). Each row and column of the board is cyclic, so whenever the new cell is outside the board, you appear on the other side. For example, moving left from (3, 0) on a board of size 5 by 5 results in appearing in cell (3, 4).

You need a board such that for every starting cell you always return to it during the movement process. If the given board does not satisfy this condition, you can change the direction of the arrow in any cell. For example, look at the following boards. In the left one, one only returns to the initial cell when he begins in cells (1, 1), (1, 2), (2, 0), (2, 3). After redirecting two arrows, you obtain a board with the given property.



Find the minimum number of arrow redirections which transforms the given board into a valid one.

DEFINITION
Class:DirectionBoard
Method:getMinimum
Parameters:vector <string>
Returns:int
Method signature:int getMinimum(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 15 elements, inclusive.
-Each element of board will contain between 1 and 15 characters, inclusive.
-All elements of board will be of the same length.
-Each element of board will consist of characters from the set {'L', 'R', 'U', 'D'} only.


EXAMPLES

0)
{"RRRD",
 "URDD",
 "UULD",
 "ULLL"}

Returns: 0

This board is already good. No matter which cell you start in, you always you return to it.

1)
{"RRRD",
 "URLL",
 "LRRR"}

Returns: 2

The example from the problem statement.

2)
{"RRD",
 "URD",
 "ULL"}

Returns: 2

This board is not valid, because if one starts from (1, 1), he never returns to this cell. A possible solution with only two changes:



3)
{"ULRLRD",
 "UDDLRR"}

Returns: 4



4)
{"UDLRLDLD",
 "DLDLLDLR",
 "LLLLLDLD",
 "UUURRRDD"}

Returns: 9



5)
{"UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUUDDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "RRRDLDURDURUDDR"}


Returns: 73



*/
// END CUT HERE
#line 102 "DirectionBoard.cpp"

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



class DirectionBoard {
	public:
	int getMinimum(vector <string> B) {
		int Y=B.size(), X=B[0].size();
		VVI w(Y, VI(X));
		REP(y, Y) REP(x, X) {
			int px=x, py=y;
			int ok=0;
			REP(loop, X*Y+2) {
				int dx=0,dy=0;
				if(B[py][px]=='U') dy=-1;
				if(B[py][px]=='D') dy= 1;
				if(B[py][px]=='L') dx=-1;
				if(B[py][px]=='R') dx= 1;
				px = (px+dx+X)%X;
				py = (py+dy+Y)%Y;
				if(px==x && py==y) {ok=1;break;}
			}
			w[y][x] = ok;
		}
		int co=0;
		REP(y, Y) REP(x, X) {
			int dx[]={1,-1,0,0};
			int dy[]={0,0,1,-1};
			int ok=1;
			REP(dir, 4) if(w[(y+dy[dir]+Y)%Y][(x+dx[dir]+X)%X]==0) ok=0;
			if(ok) co++;
		}
		cout<<co<<endl;
		cout<<w<<endl;
		return 0;
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
#define END	 verify_case(_, DirectionBoard().getMinimum(board));}
int main(){

CASE(0)
	string board_[] = {"RRRD",
 "URDD",
 "UULD",
 "ULLL"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 0; 
END
//return 0;
CASE(1)
	string board_[] = {"RRRD",
 "URLL",
 "LRRR"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 2; 
END
CASE(2)
	string board_[] = {"RRD",
 "URD",
 "ULL"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 2; 
END
CASE(3)
	string board_[] = {"ULRLRD",
 "UDDLRR"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 4; 
END
CASE(4)
	string board_[] = {"UDLRLDLD",
 "DLDLLDLR",
 "LLLLLDLD",
 "UUURRRDD"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 9; 
END
CASE(5)
	string board_[] = {"UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUUDDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "RRRDLDURDURUDDR"}
;
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 73; 
END

}
// END CUT HERE
