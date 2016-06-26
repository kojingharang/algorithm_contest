// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Circles Country is a country that contains several circular-shaped districts.  Some districts may be situated inside other districts, but their borders do not intersect or touch.  Qatam is a resident of Circles Country.  When he travels between two locations, he always tries to cross the fewest number of district borders as possible because crossing borders is usually a laborious task.

Imagine Circles Country as an infinite plane.  You are given vector <int>s X, Y and R, where (X[i], Y[i]) are the coordinates of the i-th district's center and R[i] is its radius.  Qatam is currently at point (x1,y1) and he needs to get to point (x2,y2).  Neither of these points lies on a district border.  Return the minimal number of district borders he must cross to get to his destination.


DEFINITION
Class:CirclesCountry
Method:leastBorders
Parameters:vector <int>, vector <int>, vector <int>, int, int, int, int
Returns:int
Method signature:int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2)


CONSTRAINTS
-X will contain between 1 and 50 elements, inclusive.
-X, Y and R will each contain the same number of elements.
-Each element of X and Y will be between -1000 and 1000, inclusive.
-Each element of R will be between 1 and 1000, inclusive.
-x1, y1, x2 and y2 will be between -1000 and 1000, inclusive.
-No two circumferences will have common points.
-The points (x1,y1) and (x2,y2) will not lie on any of the circumferences.


EXAMPLES

0)
{0}
{0}
{2}
-5
1
5
1

Returns: 0



1)
{0,-6,6}
{0,1,2}
{2,2,2}
-5
1
5
1

Returns: 2



2)
{1,-3,2,5,-4,12,12}
{1,-1,2,5,5,1,1}
{8,1,2,1,1,1,2}
-5
1
12
1

Returns: 3



3)
{-3,2,2,0,-4,12,12,12}
{-1,2,3,1,5,1,1,1}
{1,3,1,7,1,1,2,3}
2
3
13
2

Returns: 5



4)
{-107,-38,140,148,-198,172,-179,148,176,153,-56,-187}
{175,-115,23,-2,-49,-151,-52,42,0,68,109,-174}
{135,42,70,39,89,39,43,150,10,120,16,8}
102
16
19
-108

Returns: 3

*/
// END CUT HERE
#line 95 "CirclesCountry.cpp"

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


int inside(int x1, int y1, int X, int Y, int R) {
	return (x1-X)*(x1-X)+(y1-Y)*(y1-Y)<=R*R;
}

class CirclesCountry {
	public:
	int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2) {
		int ans = 0;
		REP(i, X.size()) {
			ans += inside(x1, y1, X[i], Y[i], R[i]) ^ inside(x2, y2, X[i], Y[i], R[i]);
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -5; int Arg4 = 1; int Arg5 = 5; int Arg6 = 1; int Arg7 = 0; verify_case(0, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arr0[] = {0,-6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -5; int Arg4 = 1; int Arg5 = 5; int Arg6 = 1; int Arg7 = 2; verify_case(1, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arr0[] = {1,-3,2,5,-4,12,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,-1,2,5,5,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8,1,2,1,1,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -5; int Arg4 = 1; int Arg5 = 12; int Arg6 = 1; int Arg7 = 3; verify_case(2, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arr0[] = {-3,2,2,0,-4,12,12,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,2,3,1,5,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3,1,7,1,1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 3; int Arg5 = 13; int Arg6 = 2; int Arg7 = 5; verify_case(3, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arr0[] = {-107,-38,140,148,-198,172,-179,148,176,153,-56,-187}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {175,-115,23,-2,-49,-151,-52,42,0,68,109,-174}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {135,42,70,39,89,39,43,150,10,120,16,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 102; int Arg4 = 16; int Arg5 = 19; int Arg6 = -108; int Arg7 = 3; verify_case(4, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	CirclesCountry ___test;

	___test.run_test(-1);

}

// END CUT HERE
