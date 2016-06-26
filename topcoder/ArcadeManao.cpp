// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You might remember the old computer arcade games. Here is one about Manao.

The game level is an NxM grid of equal cells. The bottom of some cells has a platform at which Manao can stand. All the cells in the bottommost row contain a platform, thus covering the whole ground of the level. The rows of the grid are numbered from 1 to N starting from the top and the columns are numbered from 1 to M starting from the left. Exactly one cell contains a coin and Manao needs to obtain it.

Initially, Manao is standing on the ground, i.e., in the bottommost row. He can move between two horizontally adjacent cells if both contain a platform. Also, Manao has a ladder which he can use to climb. He can use the ladder to climb both up and down. If the ladder is L units long, Manao can climb between two cells (i1, j) and (i2, j) if both contain a platform and |i1-i2| <= L. Note that Manao carries the ladder along, so he can use it multiple times. You need to determine the minimum ladder length L which is sufficient to acquire the coin.

Take a look at the following picture. On this level, Manao will manage to get the coin with a ladder of length 2.



You are given a vector <int> level containing N elements. The j-th character in the i-th row of level is 'X' if cell (i+1, j+1) contains a platform and '.' otherwise. You are also given ints coinRow and coinColumn. The coin which Manao seeks is located in cell (coinRow, coinColumn) and it is guaranteed that this cell contains a platform.

Return the minimum L such that ladder of length L is enough to get the coin. If Manao can perform the task without using the ladder, return 0.

DEFINITION
Class:ArcadeManao
Method:shortestLadder
Parameters:vector <string>, int, int
Returns:int
Method signature:int shortestLadder(vector <string> level, int coinRow, int coinColumn)


NOTES
-Manao is not allowed to fall. The only way in which he may change his vertical coordinate is by using the ladder.


CONSTRAINTS
-level will contain N elements, where N is between 1 and 50, inclusive.
-Each element of level will be M characters long, where M is between 1 and 50, inclusive.
-Each element of level will consist of '.' and 'X' characters only.
-The last element of level will be entirely filled with 'X'.
-coinRow will be between 1 and N, inclusive.
-coinColumn will be between 1 and M, inclusive.
-level[coinRow - 1][coinColumn - 1] will be 'X'.


EXAMPLES

0)
{"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"}
2
4

Returns: 2

The example from the problem statement.

1)
{"XXXX",
 "...X",
 "XXXX"}
1
1

Returns: 1

Manao can use the ladder to climb from the ground to cell (2, 4), then to cell (1, 4) and then he can walk right to the coin.

2)
{"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"}
1
3

Returns: 4

With a ladder of length 4, Manao can first climb to cell (5, 3) and then right to (1, 3).

3)
{"X"}
1
1

Returns: 0

Manao begins in the same cell as the coin.

4)
{"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"}
1
1

Returns: 2



*/
// END CUT HERE
#line 108 "ArcadeManao.cpp"

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



class ArcadeManao {
	public:
	int W,H;
	int gx,gy;
	vector <string> lvl;
	VVI vis;
	int LL;
	int f(int x, int y) {
		//cout<<"f "<<x<<" "<<y<<endl;
		vis[y][x]=1;
		if(gx==x&&gy==y) return 1;
		int dx[] = {-1,1};
		int dy[] = {-1,1};
		REP(dir, 2) {
			int nx = x + dx[dir];
			int ny = y;
			//cout<<"nn "<<nx<<" "<<ny<<endl;
			if(0<=nx && nx<W && 0<=ny && ny<H && lvl[ny][nx]=='X' && !vis[ny][nx]) {
				if(f(nx, ny)) return 1;
			}
		}
		REP(dir, 2) {
			RANGE(l, 1, LL+1) {
				int nx = x;
				int ny = y + dy[dir] * l;
				if(0<=nx && nx<W && 0<=ny && ny<H && lvl[ny][nx]=='X' && !vis[ny][nx]) {
					if(f(nx, ny)) return 1;
				}
			}
		}
		return 0;
	}
	int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
		lvl = level;
		H=lvl.size();
		W=lvl[0].size();
		gx=coinColumn-1;
		gy=coinRow-1;
		REP(L, H) {
			LL=L;
			//cout<<"L "<<L<<endl;
			vis = VVI(H, VI(W, 0));
			if(f(0, H-1)) return L;
		}
		return -1;
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
#define END	 verify_case(_, ArcadeManao().shortestLadder(level, coinRow, coinColumn));}
int main(){

CASE(0)
	string level_[] = {
 "XXXX....",
 "........",
 "........",
 "........",
 "XXXXXXXX"};
	  vector <string> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
	int coinRow = 1; 
	int coinColumn = 1; 
	int _ = 5; 
END

CASE(0)
	string level_[] = {"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"};
	  vector <string> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
	int coinRow = 2; 
	int coinColumn = 4; 
	int _ = 2; 
END
//return 0;
CASE(1)
	string level_[] = {"XXXX",
 "...X",
 "XXXX"};
	  vector <string> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
	int coinRow = 1; 
	int coinColumn = 1; 
	int _ = 1; 
END
CASE(2)
	string level_[] = {"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"};
	  vector <string> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
	int coinRow = 1; 
	int coinColumn = 3; 
	int _ = 4; 
END
CASE(3)
	string level_[] = {"X"};
	  vector <string> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
	int coinRow = 1; 
	int coinColumn = 1; 
	int _ = 0; 
END
CASE(4)
	string level_[] = {"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"};
	  vector <string> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
	int coinRow = 1; 
	int coinColumn = 1; 
	int _ = 2; 
END

}
// END CUT HERE
