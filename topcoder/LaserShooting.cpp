// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There is a laser cannon at coordinates (0, 0) on the cartesian plane. There are also several targets on the plane. Each target is a vertical line segment, and the endpoints of the i-th target are at coordinates (x[i], y1[i]) and (x[i], y2[i]). A random angle between -Pi/2 and Pi/2, inclusive, is chosen, and a single shot is fired. The angle -Pi/2 is straight down vertically, 0 is straight to the right horizontally, and Pi/2 is straight up vertically. A shot is a straight ray of infinite length starting from the point (0, 0). A shot hits a target if there is a common point between them. Return the expected number of targets that will be hit by the single shot. Hitting a target doesn't change the direction of the laser shot.

DEFINITION
Class:LaserShooting
Method:numberOfHits
Parameters:vector <int>, vector <int>, vector <int>
Returns:double
Method signature:double numberOfHits(vector <int> x, vector <int> y1, vector <int> y2)


NOTES
-A return value with either an absolute or relative error of less than 1.0e-9 is considered correct.


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-All elements of x will be distinct.
-x, y1 and y2 will contain the same number of elements.
-Each element of x will be between 1 and 1,000, inclusive.
-Each element of y1 and y2 will be between -1,000 and 1,000, inclusive.
-All targets will have positive lengths.


EXAMPLES

0)
{1}
{-1}
{1}

Returns: 0.5

The only one target will be hit with probability 1/2.

1)
{1,2}
{-1,-2}
{1,2}

Returns: 1.0

Both targets will be hit with probability 1/2.

2)
{3,4,7,1}
{1,2,3,4}
{4,3,2,1}

Returns: 0.4623163952488826



3)
{134,298,151,942}
{-753,-76,19,568}
{440,689,-39,672}

Returns: 1.444210260641501



*/
// END CUT HERE
#line 68 "LaserShooting.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class LaserShooting {
	public:
	double numberOfHits(vector <int> x, vector <int> y1, vector <int> y2) {
		vector<pair<double, int> > th;
		REP(i, x.size()) {
			if(y1[i]>y2[i]) swap(y1[i], y2[i]);
			th.push_back(make_pair(atan((double)y1[i]/x[i]),  1));
			th.push_back(make_pair(atan((double)y2[i]/x[i]), -1));
		}
		sort(ALL(th));
		int co=0;
		double ans=0;
		REP(i, th.size()-1) {
			co+=th[i].second;
			ans += co * (th[i+1].first-th[i].first);
		}
		ans/=M_PI;
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.5; verify_case(0, Arg3, numberOfHits(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.0; verify_case(1, Arg3, numberOfHits(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {3,4,7,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,3,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.4623163952488826; verify_case(2, Arg3, numberOfHits(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {134,298,151,942}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-753,-76,19,568}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {440,689,-39,672}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.444210260641501; verify_case(3, Arg3, numberOfHits(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	LaserShooting ___test;

	___test.run_test(-1);

}

// END CUT HERE
