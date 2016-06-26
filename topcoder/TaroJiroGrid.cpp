// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Cat Taro and Fox Jiro work with a square grid with N rows and N columns (N is even).
Each cell of the grid is painted either black or white.
You are given a vector <string> grid which represents the current state of the grid.
Each element of grid represents one row of the grid.
In grid, the character 'W' represents a white cell, and the character 'B' represents a black cell. 




Taro works with the rows of the grid.
He will take zero or more turns. In each turn he can choose any row of the grid and perform one of the following operations:



Paint all black cells of the row white.


Paint all white cells of the row black.



Jiro works with the columns of the grid.
He thinks that a column is bad if there are more than N/2 consecutive cells of the same color in the column.
He is happy only if there are no bad columns in the grid.




Return the minimum number of turns that Taro must perform in order to make Jiro happy.


DEFINITION
Class:TaroJiroGrid
Method:getNumber
Parameters:vector <string>
Returns:int
Method signature:int getNumber(vector <string> grid)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-N will be even.
-grid will contain exactly N elements.
-Each element of grid will contain exactly N characters.
-Each character in grid will be 'W' or 'B'.


EXAMPLES

0)
{"WB",
 "BB"}

Returns: 1

Initially, Jiro is not happy because all cells of the column 1 (0-based index) are black. In one operation, Taro can paint the first row white. After the operation, Jiro will be happy about the grid. Thus, the answer is 1.

1)
{"WB",
 "WW"}

Returns: 1



2)
{"WB",
 "WB"}

Returns: 2

In this case, Taro should paint the first row white, and the second one black (or vice versa). Note that it is not possible to make Jiro happy in fewer than two operations.

3)
{"WBBW",
 "WBWB",
 "WWBB",
 "BWWW"}

Returns: 2



4)
{"WBBWBB",
 "BBWBBW",
 "WWBWBW",
 "BWWBBB",
 "WBWBBW",
 "WWWBWB"}

Returns: 1



******************************/
// END CUT HERE
#line 103 "TaroJiroGrid.cpp"
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

class TaroJiroGrid {
	public:
	int getNumber(vector<string> g) {
		int N=g.size();
		int ans = 1<<30;
		REP(c0, 2) REP(c1, 2)
		REP(i, N+1) REP(j, N+1) {
			vector<string> gg(g);
			if(i<N) REP(k, N) gg[i][k]=c0?'B':'W';
			if(j<N) REP(k, N) gg[j][k]=c1?'B':'W';
			int ok=1;
			REP(x, N) {
				int con=1;
				char c=' ';
				REP(y, N) {
					if(c==gg[y][x]) con++;
					else con=1;
					c=gg[y][x];
					if(con>N/2) ok=0;
				}
			}
			if(ok) {
				ans = min(ans, (i<N)+(j<N));
//				cout<<gg<<endl;
			}
		}
		return ans;
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
#define END	 verify_case(_, TaroJiroGrid().getNumber(grid));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(2)
	string grid_[] = {"WW",
 "BB"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 0; 
END
//return 0;
CASE(0)
	string grid_[] = {"WB",
 "BB"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 1; 
END
CASE(1)
	string grid_[] = {"WB",
 "WW"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 1; 
END
CASE(2)
	string grid_[] = {"WB",
 "WB"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 2; 
END
CASE(3)
	string grid_[] = {"WBBW",
 "WBWB",
 "WWBB",
 "BWWW"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 2; 
END
CASE(4)
	string grid_[] = {"WBBWBB",
 "BBWBBW",
 "WWBWBW",
 "BWWBBB",
 "WBWBBW",
 "WWWBWB"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 1; 
END
#if 0 // DO RANDOM TESTS

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
// param type: String
	vector <string> grid; 
	{
		int N=UNIFORM_LL(1, 10)*2;
		grid = vector <string>(N, string(N, ' ')); 
		REP(i, N) REP(j, N) {
			grid[i][j] = UNIFORM_LL(0, 1000)%2 ? 'W':'B';
		}
	}
	int _0 = TaroJiroGrid().getNumber(grid);
	assert(_0<=2);
	int _1 = TaroJiroGridRef().getNumber(grid);
//	if(!verify_case(_0, _0, true)) {
	if(!verify_case(_0, _1, true)) {
print(grid);
	}
}
#endif

}
// END CUT HERE
