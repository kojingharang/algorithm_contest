// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// An out-of-control robot is placed on a plane, and it takes n random steps.  At each step, the robot chooses one of four directions randomly and moves one unit in that direction. The probabilities of the robot choosing north, south, east or west are north, south, east and west percent, respectively.

The robot's path is considered simple if it never visits the same point more than once.  (The robot's starting point is always the first visited point.)  Return a double containing the probability that the robot's path is simple.  For example, "EENE" and "ENW" are simple, but "ENWS" and "WWWWSNE" are not ('E', 'W', 'N' and 'S' represent east, west, north and south, respectively).

DEFINITION
Class:CrazyBot
Method:getProbability
Parameters:int, int, int, int, int
Returns:double
Method signature:double getProbability(int n, int east, int west, int south, int north)


NOTES
-Your return must have relative or absolute error less than 1E-9.


CONSTRAINTS
-n will be between 1 and 14, inclusive.
-east will be between 0 and 100, inclusive.
-west will be between 0 and 100, inclusive.
-south will be between 0 and 100, inclusive.
-north will be between 0 and 100, inclusive.
-The sum of east, west, south and north will be 100.


EXAMPLES

0)
1
25
25
25
25

Returns: 1.0

The robot only takes one step, so it never visits a point more than once.

1)
2
25
25
25
25

Returns: 0.75

The robot will visit its starting point twice only if the two moves are in opposite directions.

2)
7
50
0
0
50

Returns: 1.0

Here, the only possible directions are north and east, so the robot will never visit the same point twice.

3)
14
50
50
0
0

Returns: 1.220703125E-4

Here, the only possible directions are east and west. The only two available paths are "EEEEEEEEEEEEEE" and "WWWWWWWWWWWWWW". The probability is equal to 2 / (2^14).

4)
14
25
25
25
25

Returns: 0.008845493197441101

The probability is quite small for n=14.

*/
// END CUT HERE
#line 89 "CrazyBot.cpp"

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
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

VVI w(29, VI(29, 0));
int n;
double ans, _e,_w,_s,_n;
void dfs(int step, int x, int y, double prob) {
	if(w[y+14][x+14]) return;
	if(step==n) {ans+=prob; return;}
	w[y+14][x+14]=1;
	dfs(step+1, x+1, y+0, prob*_e);
	dfs(step+1, x-1, y+0, prob*_w);
	dfs(step+1, x+0, y+1, prob*_s);
	dfs(step+1, x+0, y-1, prob*_n);
	w[y+14][x+14]=0;
}

class CrazyBot {
	public:
	double getProbability(int N, int east, int west, int south, int north) {
		ans=0;
		n=N;
		_e=east/100.;
		_w=west/100.;
		_s=south/100.;
		_n=north/100.;
		dfs(0, 0, 0, 1.0);
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 1.0; verify_case(0, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 0.75; verify_case(1, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 50; int Arg2 = 0; int Arg3 = 0; int Arg4 = 50; double Arg5 = 1.0; verify_case(2, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 14; int Arg1 = 50; int Arg2 = 50; int Arg3 = 0; int Arg4 = 0; double Arg5 = 1.220703125E-4; verify_case(3, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 14; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 0.008845493197441101; verify_case(4, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	CrazyBot ___test;

	___test.run_test(-1);
	//___test.test_case_1();

}

// END CUT HERE
