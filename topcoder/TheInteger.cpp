// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
There is nothing more beautiful than just an integer number.



You are given an integer n.  Return the smallest integer greater than or equal to n that contains exactly k distinct digits in decimal notation.



DEFINITION
Class:TheInteger
Method:find
Parameters:long long, int
Returns:long long
Method signature:long long find(long long n, int k)


CONSTRAINTS
-n will be between 1 and 10^18, inclusive.
-k will be between 1 and 10, inclusive.


EXAMPLES

0)
47
1

Returns: 55

Here, k is 1, so we're looking for a number whose digits are all equal.  The smallest such number that is greater than or equal to 47 is 55.

1)
7
3

Returns: 102

We need three distinct digits here.

2)
69
2

Returns: 69

69 already consists of two different digits.

3)
12364
3

Returns: 12411

*/
// END CUT HERE
#line 61 "TheInteger.cpp"

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



class TheInteger {
	public:
	long long find(long long n, int k) {
		int a=~0;
		cout<<a<<endl;
		return 0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 47LL; int Arg1 = 1; long long Arg2 = 55LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 7LL; int Arg1 = 3; long long Arg2 = 102LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 69LL; int Arg1 = 2; long long Arg2 = 69LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 12364LL; int Arg1 = 3; long long Arg2 = 12411LL; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	TheInteger ___test;

	___test.run_test(-1);

}

// END CUT HERE
