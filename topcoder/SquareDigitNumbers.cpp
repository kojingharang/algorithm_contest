// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You enjoy working with numbers that contain only square digits (namely, 0, 1, 4 and 9).  The sequence containing only these digits is 0, 1, 4, 9, 10, 11, 14...   Return the n-th term (indexed from 0) in this sequence.

DEFINITION
Class:SquareDigitNumbers
Method:getNumber
Parameters:int
Returns:int
Method signature:int getNumber(int n)


CONSTRAINTS
-n will be between 0 and 1000, inclusive.


EXAMPLES

0)
0

Returns: 0

The first square digit number is 0.

1)
5

Returns: 11



2)
16

Returns: 100



3)
121

Returns: 1941



4)
123

Returns: 1949



*/
// END CUT HERE
#line 58 "SquareDigitNumbers.cpp"
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define REP(i, n) for(int i=0, _n=(n);(i)<_n;i++)
#define FOR(i, a, b) for(int i=(a),_b=(b);(i)<_b;i++)
#define FORD(i, a, b) for(int i=(a),_b=(b);(i)>=_b;i--)
#define CLR(a) memset(a, 0, sizeof(a))
class SquareDigitNumbers {
	public:
	int getNumber(int n) {
		cout<<n<<endl;
		char buf[100];
		int v = 0;
		int fo = -1;
		REP(i, 100000)
		{
			sprintf(buf, "%d", v);
			int ok = 1;
			REP(l, strlen(buf))
			{
				if(buf[l]!='0' && buf[l]!='1' && buf[l]!='4' && buf[l]!='9') {ok = 0;}
			}
			if(ok)
			{
				fo++;
				if(fo==n) return v;
			}
			v++;
		}
		return -1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 11; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { int Arg0 = 16; int Arg1 = 100; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { int Arg0 = 121; int Arg1 = 1941; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { int Arg0 = 123; int Arg1 = 1949; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	SquareDigitNumbers ___test;

	___test.run_test(-1);

}

// END CUT HERE
