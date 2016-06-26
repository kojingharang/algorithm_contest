// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
John believes that the digits 4 and 7 are lucky, and all other digits are unlucky.
A positive integer is called a lucky number if its last digit is lucky.
For example, 4, 14 and 207 are lucky numbers, while 40, 741 and 3 are not lucky numbers.
John would like to represent the int n as a sum of only lucky numbers, and he would like to do this using the minimal possible number of summands.
Return the number of summands in the representation, or -1 if it is impossible to achieve the goal.



DEFINITION
Class:TheNumbersWithLuckyLastDigit
Method:find
Parameters:int
Returns:int
Method signature:int find(int n)


CONSTRAINTS
-n will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
99

Returns: 4

One?of?the?possible?representations?is?99=14+24+27+34.

1)
11

Returns: 2

11=4+7.

2)
13

Returns: -1

It is impossible to achieve the goal.

3)
1234567

Returns: 1

*/
// END CUT HERE
#line 56 "TheNumbersWithLuckyLastDigit.cpp"

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



class TheNumbersWithLuckyLastDigit {
	public:
	int find(int n) {
		int table[20] = {
			20, 5,
			11, 2,
			12, 3,
			23, 5,
			4, 1,
			15, 3,
			16, 4,
			7, 1,
			8, 2,
			19, 4,
		};
		REP(i, 20) table[i]=10000;
		REP(i, 10) {
			REP(x, 10) REP(y, 10) {
				if(4*x+7*y>0 && (4*x+7*y)%10==i && table[i*2+1]>x+y) {
					table[i*2]=4*x+7*y;
					table[i*2+1]=x+y;
				}
			}
		}
		REP(i, 10) cout<<table[i*2]<<" "<<table[i*2+1]<<endl;
		
		if(n<table[(n%10)*2]) return -1;
		else return table[(n%10)*2+1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 99; int Arg1 = 4; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 11; int Arg1 = 2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 13; int Arg1 = -1; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 1234567; int Arg1 = 1; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	TheNumbersWithLuckyLastDigit ___test;

	___test.run_test(-1);

}

// END CUT HERE
