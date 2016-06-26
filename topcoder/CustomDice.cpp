// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
In a Las Vegas casino, a new type of six-sided die is being introduced. These dice may have any positive integers written its sides, but no two sides of the same die can contain the same number. For each die, the casino owner wants the mean value of the numbers written on its sides to not exceed M.



Compute the total number of allowed dice. Two dice are considered different if one can't be obtained from the other using rotations. Since the resulting number may be quite large, return it modulo 1000000007.


DEFINITION
Class:CustomDice
Method:countDice
Parameters:int
Returns:int
Method signature:int countDice(int M)


CONSTRAINTS
-M will be between 1 and 1000000, inclusive.


EXAMPLES

0)
3

Returns: 0

The die with the smallest possible mean is {1,2,3,4,5,6}.  Its mean is 3.5, which is greater than M=3.

1)
4

Returns: 210

There are 30 different dice with numbers {1,2,3,4,5,6} on their sides, they each have a mean of 3.5.
There are 30 different dice with numbers {1,2,3,4,5,7} on their sides, they each have a mean of 22/6=3.(6).
There are 60 different dice with {1,2,3,4,5,8} or {1,2,3,4,6,7} on their sides, they each have a mean of 23/6=3.8(3).
There are 90 different dice with {1,2,3,4,5,9}, {1,2,3,4,6,8} or {1,2,3,5,6,7} on their sides, they each have a mean of 24/6=4.

2)
10

Returns: 863010



3)
50

Returns: 375588112



*/
// END CUT HERE
#line 60 "CustomDice.cpp"

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

#define EPS 1e-12
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



class CustomDice {
	public:
	int countDice(int M) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; verify_case(0, Arg1, countDice(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 210; verify_case(1, Arg1, countDice(Arg0)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 863010; verify_case(2, Arg1, countDice(Arg0)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 375588112; verify_case(3, Arg1, countDice(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	CustomDice ___test;

	___test.run_test(-1);

}

// END CUT HERE
