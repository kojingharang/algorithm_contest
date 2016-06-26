// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
You are given two positive integers x and k. Return the k-th smallest positive integer y (where k is 1-based) for which the following equation holds:
x + y = x | y
where '|' denotes the bitwise OR operator.



DEFINITION
Class:BitwiseEquations
Method:kthPlusOrSolution
Parameters:int, int
Returns:long long
Method signature:long long kthPlusOrSolution(int x, int k)


CONSTRAINTS
-x will be between 1 and 2,000,000,000, inclusive.
-k will be between 1 and 2,000,000,000, inclusive.


EXAMPLES

0)
5
1

Returns: 2

The first positive integer for which the equation holds is 2.
You can check that 5+2=7 as well as 5|2=7. Both plus and bitwise OR look like the following:

 101
+ 10
 ---
 111



1)
5
5

Returns: 18

The fifth number for which the equation 5 + y = 5 | y holds is 18. The first four solutions are 2,8,10,16.
The binary sum for 18 looks like the following:

   101
+10010
 -----
 10111


2)
10
3

Returns: 5

The third solution is 5. The first two solutions are 1 and 4.


3)
1
1000000000

Returns: 2000000000



*/
// END CUT HERE
#line 77 "BitwiseEquations.cpp"

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



class BitwiseEquations {
	public:
	long long kthPlusOrSolution(int x, int k) {
		ll ans=k;
		REP(i, 31) {
			if(x&(1LL<<i)) {
				ll mask=(1<<i)-1;
				cout<<i<<"   "<<(ans&mask)<<" "<<((ans&~mask)<<1)<<endl;
				ans = ans&mask | (ans&~mask)<<1;
			}
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	//void test_case_0() { int Arg0 = 5; int Arg1 = 1; long long Arg2 = 2LL; verify_case(0, Arg2, kthPlusOrSolution(Arg0, Arg1)); }
	void test_case_0() { int Arg0 = 1073741824; int Arg1 = 1073741824; long long Arg2 = 2147483648LL; verify_case(0, Arg2, kthPlusOrSolution(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; long long Arg2 = 18LL; verify_case(1, Arg2, kthPlusOrSolution(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 3; long long Arg2 = 5LL; verify_case(2, Arg2, kthPlusOrSolution(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1000000000; long long Arg2 = 2000000000LL; verify_case(3, Arg2, kthPlusOrSolution(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	BitwiseEquations ___test;

	___test.run_test(-1);

}

// END CUT HERE
