// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// The binary weight of a positive integer is the number of 1's in its binary representation. For example, the decimal number 1 has a binary weight of 1, and the decimal number 1717 (which is 11010110101 in binary) has a binary weight of 7.

Given a positive integer N, return the smallest integer greater than N that has the same binary weight as N.

DEFINITION
Class:NextNumber
Method:getNextNumber
Parameters:int
Returns:int
Method signature:int getNextNumber(int N)


NOTES
-The result is guaranteed to fit in a signed 32-bit integer.


CONSTRAINTS
-N will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
1717

Returns: 1718

Example from the problem statement.

1)
4

Returns: 8

4 is 100 in its binary representation and weighs 1. The next number is 1000(in binary) which represents 8.

2)
7

Returns: 11

The decimal 7 is binary 111, so it has binary weight of 3. The next number with the same binary weight is 11, which is 1011 in binary.

3)
12

Returns: 17

12 in decimal is 1100 in binary. The next number with the same binary weight is 10001 in binary, which is 17.

4)
555555

Returns: 555557



*/
// END CUT HERE
#line 64 "NextNumber.cpp"

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



class NextNumber {
	public:
	int getNextNumber(int N) {
		//if((N&3)==1) return (N&~3)|2;
		VI vv(4);
		vv[1]=1;
		//while(next_permutation(ALL(vv))) cout<<vv<<endl;
		int c1 = 0;
		int f0 = 0;
		REP(i, 32) {
			if(c1>0 && (N&1<<i)==0) {f0=i;break;}
			if(N&1<<i) c1++;
		}
		cout<<c1<<f0<<endl;
		return N&~((1<<f0)-1)|(1<<f0)|((1<<c1-1)-1);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1717; int Arg1 = 1718; verify_case(0, Arg1, getNextNumber(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 8; verify_case(1, Arg1, getNextNumber(Arg0)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 11; verify_case(2, Arg1, getNextNumber(Arg0)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 17; verify_case(3, Arg1, getNextNumber(Arg0)); }
	void test_case_4() { int Arg0 = 555555; int Arg1 = 555557; verify_case(4, Arg1, getNextNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	NextNumber ___test;

	___test.run_test(-1);

}

// END CUT HERE
