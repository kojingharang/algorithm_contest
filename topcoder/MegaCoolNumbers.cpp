// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A positive integer is called a cool number of power A if it can be separated into exactly A groups of consecutive digits, where the digits in each group form an arithmetic progression.  An arithmetic progression is a sequence of numbers in which the difference between any two consecutive numbers is the same.  A positive integer is called a mega cool number of power A if it is a cool number of power A, not a cool number of power A-1, and all its digits are in non-decreasing order.

Determine the number of mega cool numbers of power A that contain exactly N digits (with no leading zeroes).  Return this number modulo 1,000,000,007.

DEFINITION
Class:MegaCoolNumbers
Method:count
Parameters:int, int
Returns:int
Method signature:int count(int N, int A)


CONSTRAINTS
-A and N will be between 1 and 1,000, inclusive. 


EXAMPLES

0)
1
1

Returns: 9

There 9 such numbers: 1, 2, 3, 4, 5, 6, 7, 8, 9.

1)
2
1

Returns: 45

Any two-digit number with non-decreasing digits will be a mega cool number of power 1.

2)
2
2

Returns: 0

There are no such numbers.

3)
10
3

Returns: 7502



*/
// END CUT HERE
#line 57 "MegaCoolNumbers.cpp"

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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class MegaCoolNumbers {
	public:
	int count(int N, int A) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 9; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 45; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 3; int Arg2 = 7502; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	MegaCoolNumbers ___test;

	___test.run_test(-1);

}

// END CUT HERE
