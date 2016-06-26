// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.


You are given a white rectangular grid made up of square cells.  Some cells contain black squares, and some contain black squares that have been folded in half to form right triangles, such that one of their sides matches the grid line to the right of the cell and another side of the triangle matches the grid line to the bottom of the cell.  At most unfoldLimit of these triangles can be unfolded to become black squares. However, black squares cannot be folded to become triangles.

We are interested in forming the largest possible proper black triangle in the grid using the aforementioned operations.  A black triangle is considered proper within a grid configuration if no other black shape shares a line segment with it.  However, black shapes may still share one or more points with the triangle. The size of a triangle is defined as the number of grid cells that are currently occupied by the triangle.

The grid will be given as a vector <string>, where the j-th character of the i-th element represents the cell at row i, column j.  '.' represents an empty cell, '#' represents a cell containing a black square, and '/' represents a cell containing a black triangle.  Return the largest possible size for a proper triangle that can be formed in the given grid by unfolding at most unfoldLimit triangles. In case it is not possible to form a proper black triangle in the grid, return -1.

For example, consider the following input grid:





If unfoldLimit is greater than or equal to 3, the largest possible proper triangle size is 10:
   



If unfoldLimit is 2, the largest possible proper triangle size is 3:
   
Larger black triangles are possible, but they would not be proper triangles.

DEFINITION
Class:UnfoldingTriangles
Method:solve
Parameters:vector <string>, int
Returns:int
Method signature:int solve(vector <string> grid, int unfoldLimit)


CONSTRAINTS
-grid will contain between 1 and 50 elements, inclusive.
-Each element of grid will contain between 1 and 50 characters, inclusive.
-Each element of grid will contain the same number of characters.
-Each character in grid will be '.', '#' or '/'.
-unfoldLimit will be between 1 and 2500, inclusive.


EXAMPLES

0)
{".../",
 "../#",
 "./#/",
 "/#//"}
4

Returns: 10



1)
{".../",
 "../#",
 "./#/",
 "/#//"}
2

Returns: 3

Examples 1 and 0 were explained in the problem statement.

2)
{"////",
 "////",
 "////",
 "////"}
5

Returns: 6



3)
{".....#...",
 "....###.."}
10

Returns: -1



4)
{"#//#",
 "#//#",
 "####",
 "///#"}
4

Returns: 1



5)
{".../.../",
 "../#..//",
 "./.#.///",
 "/###...."}
3

Returns: 6



*/
// END CUT HERE
#line 113 "UnfoldingTriangles.cpp"

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



class UnfoldingTriangles {
	public:
	int solve(vector <string> g, int u) {
		int W=g[0].size();
		int H=g.size();
		int ans = -1;
		REP(y, H) {
			REP(x, W) {
				REP(h, min(H-y, x+1)) {
					int ok = 1;
					int uu = 0;
					REP(hh, h+1) {
						if(g[y+hh][x-hh]!='/') {ok=0; break;}
						REP(xx, hh) {
							if(g[y+hh][x-hh+1+xx]=='.') {ok=0; break;}
							if(g[y+hh][x-hh+1+xx]=='/') uu++;
						}
						if(x+1<W && g[y+hh][x+1]=='#') {ok=0;break;}
					}
					if(y+h+1<H) {
						REP(xx, h+1) if(g[y+h+1][x-h+xx]=='#') ok=0;
					}
					//if(ok&&uu<=u) cout<<x<<" "<<y<<" "<<h<<" -> "<<u<<endl;
					if(ok&&uu<=u) ans=max(ans, (h+1)*(h+2)/2);
				}
			}
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".../",
 "../#",
 "./#/",
 "/#//"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 10; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".../",
 "../#",
 "./#/",
 "/#//"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"////",
 "////",
 "////",
 "////"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 6; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".....#...",
 "....###.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = -1; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"#//#",
 "#//#",
 "####",
 "///#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; verify_case(4, Arg2, solve(Arg0, Arg1)); }
//	void test_case_5() { string Arr0[] = {".../.../",
// "../#..//",
// "./.#.///",
// "/###...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(5, Arg2, solve(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = 
{"/##/#/.#/.//#/./#.##",
 "#.##./#.##../.#./#./", 
 "/.#//#//#/.#.//#/.#/", 
 "#//.////#/./#/#.//.#", 
 "///#././/.//#/./#/#.", 
 "##.../.#/../.#.##.#/", 
 "/#/./#/./../####//#.", 
 "///#...#/./#/././../", 
 "..##/##../###.//..//", 
 "##//##/#/.#//####/#.", 
 "//./.#.###...#../##/", 
 "//.#/.#//...//#/.../", 
 "///.#/.#/####.##...#", 
 "#.././.##///##.#.///", 
 ".//.#.#/..#.##.#/.##", 
 "./#/../..#.#/////../", 
 "#./.#.#././/#/././##", 
 "//#..//.#.#//.#/#../", 
 "/./#.///##.###./.#.#"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 6; verify_case(5, Arg2, solve(Arg0, Arg1)); }


// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	UnfoldingTriangles ___test;

	___test.run_test(-1);
	//___test.test_case_5();

}

// END CUT HERE
