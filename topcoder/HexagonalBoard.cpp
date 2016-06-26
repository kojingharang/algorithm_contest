// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// The pony Applejack has an N by N hexagonal board. The following picture shows the hexagonal board when N = 1, 2, 3, and 4.





She wants to color some cells of the board. You are given a vector <string> board. If the j-th character of the i-th element of board is 'X', she wants to color the cell (i, j). If she colors two cells that share an edge, she must use different colors for those cells. Return the minimal number of colors she needs.

DEFINITION
Class:HexagonalBoard
Method:minColors
Parameters:vector <string>
Returns:int
Method signature:int minColors(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain exactly N characters, where N is the number of elements in board.
-Each character in board will be either 'X' or '-'.


EXAMPLES

0)
{"---",
 "---",
 "---"}
 

Returns: 0

She won't color any cells, so she won't need any colors.

1)
{"-X--",
 "---X",
 "----",
 "-X--"}

Returns: 1

She can color all cells with the same color.

2)
{"XXXX",
 "---X",
 "---X",
 "---X"}

Returns: 2

For example, she can color cells in the following way:

Color cells (0, 0), (0, 2), (1, 3), and (3, 3) red.
Color cells (0, 1), (0, 3), and (2, 3) blue.



3)
{"XX-XX--"
,"-XX-XXX"
,"X-XX--X"
,"X--X-X-"
,"XX-X-XX"
,"-X-XX-X"
,"-XX-XX-"}

Returns: 3



*/
// END CUT HERE
#line 79 "HexagonalBoard.cpp"

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


vector <string> B;
VVI vis;
ll ans;
int N;
class HexagonalBoard {
	public:
	void dfs(int x, int y, int col) {
		if(vis[y][x]) {
			if(vis[y][x]!=col) {ans=3;return;}
			return;
		}
		vis[y][x]=col;
		int dx[] = {-1,0,1,1,0,-1};
		int dy[] = {0,-1,-1,0,1,1};
		REP(i, 6) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(0<=nx&&nx<N && 0<=ny&&ny<N && B[ny][nx]=='X') dfs(nx, ny, col==1?2:1);
		}
	}
	
	int minColors(vector <string> BB) {
		B=BB;
		N=B.size();
		vis = VVI(N, VI(N));
		ans = 0;
		REP(y, N) REP(x, N) {
			if(!vis[y][x] && B[y][x]=='X') dfs(x, y, 1);
			if(ans==3) return 3;
		}
		REP(y, N) REP(x, N) {
			ans=max(ans, vis[y][x]);
		}
		//cout<<w<<endl;
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
#define END	 verify_case(_, HexagonalBoard().minColors(board));}
int main(){

//CASE(2)
//	string board_[] = {"XXXX",
// "---X",
// "---X",
// "---X"};
//	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
//	int _ = 2; 
//END
//return 0;

CASE(0)
	string board_[] = {"---",
 "---",
 "---"}
 ;
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 0; 
END
CASE(1)
	string board_[] = {"-X--",
 "---X",
 "----",
 "-X--"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 1; 
END
CASE(1)
	string board_[] = {
"X-X",
"X-X",
"XX-"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 2; 
END
CASE(2)
	string board_[] = {"XXXX",
 "---X",
 "---X",
 "---X"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 2; 
END
CASE(3)
	string board_[] = {"XX-XX--"
,"-XX-XXX"
,"X-XX--X"
,"X--X-X-"
,"XX-X-XX"
,"-X-XX-X"
,"-XX-XX-"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 3; 
END

}
// END CUT HERE
