// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Mr. Dengklek has a rectangular farm conveniently divided into a grid of unit squares. At this moment, each unit square contains at most one duck. Moreover, each row and column of the farm also contains at most one duck. You are given a vector <string> grid. The j-th character of the i-th element of grid will be 'o' if there is exactly one duck in square (i, j), i.e., row i column j, or '.' if there is no duck in that square. 

Today, Mr. Dengklek wants to align the ducks so that the ducks form a contiguous line. More precisely, assume that there are N ducks on the farm. After the alignment, the ducks must either occupy N contiguous squares in some row or N contiguous squares in some column. To accomplish that, he will move the ducks one at a time. To move a duck in square (a, b) to another empty square (c, d), he needs |a-c| + |b-d| seconds, where |x| denotes the absolute value of x. Mr. Dengklek can always move any duck to any empty square he desires - the other ducks are not obstacles.

Return the minimum time in seconds Mr. Dengklek needs to align the ducks. Note that restrictions imposed on the initial placement of ducks guarantee that a proper alignment is always possible.

DEFINITION
Class:DucksAlignment
Method:minimumTime
Parameters:vector <string>
Returns:int
Method signature:int minimumTime(vector <string> grid)


CONSTRAINTS
-grid will contain between 1 and 50 elements, inclusive.
-Each element of grid will contain between 1 and 50 characters, inclusive.
-All elements of grid will contain the same number of characters.
-Each character of grid will be either 'o' or '.'.
-Each row in grid will contain at most one character 'o'.
-Each column in grid will contain at most one character 'o'.
-grid will contain at least one character 'o'.


EXAMPLES

0)
{".o",
 "o."}

Returns: 1

Move either duck to an adjacent empty square.

1)
{".o...",
 "..o..",
 "....o"}

Returns: 3

One of the solutions is: move the the duck in the first row one square to the right, and then move the duck in the last row two squares to the left.

2)
{"o..........",
 "..o........",
 ".......o...",
 "...........",
 "...........",
 "...........",
 "........o..",
 "..........."}

Returns: 16

Align all ducks in the second row.

3)
{".........",
 "....o....",
 "........."}

Returns: 0



4)
{"...o..........................",
 "............................o.",
 ".o............................",
 "............o.................",
 ".................o............",
 "......................o.......",
 "......o.......................",
 "....o.........................",
 "...............o..............",
 ".......................o......",
 "...........................o..",
 ".......o......................"}

Returns: 99



*/
// END CUT HERE
#line 91 "DucksAlignment.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }





class DucksAlignment {
	public:
	int minimumTime(vector <string> grid) {
		int N=0;
		int H=grid.size();
		int W=grid[0].size();
		VI v0, v1;
		REP(y, H) {
			REP(x, W) {
				if(grid[y][x]=='o') {
					v0.push_back(x);
					v1.push_back(y);
					N++;
				}
			}
		}
		sort(ALL(v0));
		int ans = 100000000;
		REP(ii, 2) {
			int L=ii==0?H:W;
			FOR(ai, v0) {
				int lans = 0;
				FOR(v, v0) {
					lans += abs(*ai-*v);
				}
				int lans2=1000000;
				REP(be, L-N+1) {
					int llans2=0;
					REP(i, N) {
						llans2 += abs(be+i - v1[i]);
					}
					lans2 = min(lans2, llans2);
				}
				ans = min(ans, lans+lans2);
			}
			swap(v0, v1);
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".o",
 "o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimumTime(Arg0)); }
	void test_case_1() { string Arr0[] = {".o...",
 "..o..",
 "....o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, minimumTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"o..........",
 "..o........",
 ".......o...",
 "...........",
 "...........",
 "...........",
 "........o..",
 "..........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(2, Arg1, minimumTime(Arg0)); }
	void test_case_3() { string Arr0[] = {".........",
 "....o....",
 "........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, minimumTime(Arg0)); }
	void test_case_4() { string Arr0[] = {"...o..........................",
 "............................o.",
 ".o............................",
 "............o.................",
 ".................o............",
 "......................o.......",
 "......o.......................",
 "....o.........................",
 "...............o..............",
 ".......................o......",
 "...........................o..",
 ".......o......................"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 99; verify_case(4, Arg1, minimumTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	DucksAlignment ___test;

	___test.run_test(-1);

}

// END CUT HERE
