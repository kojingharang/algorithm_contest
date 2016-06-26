// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// When cat Taro went to an internship, he found a strange elevator in the office's skyscraper. The skyscraper contains 58 floors. The elevator is composed of 2 boxes and these 2 boxes move together. When the lower box stops at the x-th floor, the upper box always stops at the (x+1)-th floor. The lower box stops only on odd floors (1st, 3rd, 5th, ..., 57th). The upper box stops only on even floors (2nd, 4th, 6th, ..., 58th). He is very interested by this elevator, and he wants to compute the number of possible elevators composed of N boxes in a skyscraper of height H.


The elevators must satisfy the following conditions:

For each floor, exactly one box stops at that floor.
The distance between 2 boxes is an integer and never changes. More formally, for each pair of boxes (A,B), there must be some integer d such that box B always stops at the (x+d)-th floor when box A stops at the x-th floor. If the (x+d)-th floor doesn't exist, box A must not stop at the x-th floor.


Two elevators are different if the following is true. When the bottommost box is at the first floor, there exists an i such that a box is at the i-th floor in one elevator and no box is at the i-th floor in the other elevator. You are given two integers H and N. Return the number of possible elevators that have N boxes in a skyscraper of height H, modulo 1,000,000,007.


DEFINITION
Class:StrangeElevator
Method:theCount
Parameters:int, int
Returns:int
Method signature:int theCount(int H, int N)


CONSTRAINTS
-H will be between 1 and 1,000,000,000, inclusive.
-N will be between 1 and H, inclusive.


EXAMPLES

0)
58
2

Returns: 2

The following two elevators are possible:


When the lower box stops at the 1st, 3rd, ..., 57th floor, the upper box stops at the 2nd, 4th, ..., 58th floor, respectively.
When the lower box stops at the 1st, 2nd, ..., 29th floor, the upper box stops at the 30th, 31st, ..., 58th floor, respectively.


1)
1
1

Returns: 1

The only box always stops at the 1st floor.

2)
9
3

Returns: 2

The following two elevators are possible:


When the lowest box stops at the 1st, the 4th and the 7th floor, the middle box stops at the 2nd, the 5th and the 8th floor, and the topmost box stops at the 3rd, the 6th and the 9th floor, respectively.
When the lowest box stops at the 1st, the 2nd and the 3rd floor, the middle box stops at the 4th, the 5th and the 6th floor, and the topmost box stops at the 7th, the 8th and the 9th floor, respectively.



3)
120
12

Returns: 30



4)
58585858
495

Returns: 0



*/
// END CUT HERE
#line 85 "StrangeElevator.cpp"
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define B begin()
#define E end()
#define SZ size()
#define PB(v) push_back(v)
using namespace std;
#define REP(i, n) for(int i=0, _n=(n);(i)<_n;i++)
#define FOR(i, a, b) for(int i=(a),_b=(b);(i)<_b;i++)
#define FORD(i, a, b) for(int i=(a),_b=(b);(i)>=_b;i--)
#define CLR(a) memset(a, 0, sizeof(a))
#define SORT(v) sort(v.B, v.E)
template <typename T>
void UNIQ(T& v)
{
	typename T::iterator end = unique(v.B, v.E);
	v.erase(end, v.end());
}
template <typename T0, typename T1>
std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v)
{
	for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ )
	{
		os << p->first << ": " << p->second << " ";
	}
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v)
{
	for( int i = 0; i < v.size(); i++ )
	{
		os << v[i] << " ";
	}
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const set<T>& v)
{
	vector<T> tmp(v.B, v.E);
	os << tmp;
	return os;
}

vector<vector<int> > combination(vector<int> vi, int K)
{
	sort(vi.begin(), vi.end());

	set<vector<int> > se;
	do
	{
		vector<int> tm(vi.begin(), vi.begin()+K);
		sort(tm.begin(), tm.end());
		se.insert(tm);
	}
	while(next_permutation(vi.begin(), vi.end()));
	return vector< vector<int> >(se.begin(), se.end());
}


class StrangeElevator {
	public:
	int theCount(int H, int N) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 58; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 9; int Arg1 = 3; int Arg2 = 2; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 120; int Arg1 = 12; int Arg2 = 30; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 58585858; int Arg1 = 495; int Arg2 = 0; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	StrangeElevator ___test;

	___test.run_test(-1);

}

// END CUT HERE
