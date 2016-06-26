// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel likes to jump around in large fields.  She is currently at point (0, 0) of a field, and she wants to land at point (Tx, Ty) using exactly R jumps.

In one jump, she can move 0, 1, 2, ..., Mx units in the positive x direction and 0, 1, 2, ..., My units in the positive y direction.  All jumps must have a non-zero distance.  In addition, there are some jumps which she is not good at.  These jumps are described in the vector <int> bad.  If bad contains the number b, it means she cannot make a diagonal jump where she moves exactly b units in the positive x direction and b units in the positive y direction.  Each element of bad will be a multiple of 10.

For instance, if Mx=12, My=11, bad={10} and she is at point (0, 0), then the only points she can jump to are the green ones shown below:



Return the number of ways she can start at (0, 0), jump exactly R times, and land at (Tx, Ty), modulo 10,007. Two ways are considered to be different if there is an index i, 0 <= i < R, such that Ciel lands at different points after the i-th (0-based) jump in these ways.

DEFINITION
Class:FoxJumping
Method:getCount
Parameters:int, int, int, int, int, vector <int>
Returns:int
Method signature:int getCount(int Tx, int Ty, int Mx, int My, int R, vector <int> bad)


CONSTRAINTS
-Tx and Ty will each be between 1 and 800, inclusive.
-Mx and My will each be between 1 and 800, inclusive.
-R will be between 1 and 1,600, inclusive.
-bad will contain between 0 and 50 elements, inclusive.
-Each element of bad will be between 1 and min(Mx, My), inclusive, and be a multiple of 10.
-All elements of bad will be distinct.


EXAMPLES

0)
2
2
1
1
2
{}

Returns: 1

There is only 1 way to reach the destination.



1)
2
2
1
1
3
{}

Returns: 6

The following are the 6 ways she can reach her destination.  Note that when she jumps, she must move a distance of at least one unit.



2)
10
10
10
10
1
{}

Returns: 1

She can jump only once, so there is 1 way to reach the destination.

3)
10
10
10
10
1
{10}

Returns: 0

This case is almost the same as the previous one.  However, in this case, the required jump is a bad jump, so she cannot reach the destination in a single jump.

4)
11
11
11
11
2
{10}

Returns: 140



5)
123
456
70
80
90
{30, 40, 20, 10, 50}

Returns: 6723



*/
// END CUT HERE
#line 112 "FoxJumping.cpp"
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


class FoxJumping {
	public:
	int getCount(int Tx, int Ty, int Mx, int My, int R, vector <int> bad) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arr5[] = {}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 1; verify_case(0, Arg6, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = 3; int Arr5[] = {}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 6; verify_case(1, Arg6, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 10; int Arg3 = 10; int Arg4 = 1; int Arr5[] = {}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 1; verify_case(2, Arg6, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 10; int Arg3 = 10; int Arg4 = 1; int Arr5[] = {10}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 0; verify_case(3, Arg6, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 11; int Arg1 = 11; int Arg2 = 11; int Arg3 = 11; int Arg4 = 2; int Arr5[] = {10}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 140; verify_case(4, Arg6, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { int Arg0 = 123; int Arg1 = 456; int Arg2 = 70; int Arg3 = 80; int Arg4 = 90; int Arr5[] = {30, 40, 20, 10, 50}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 6723; verify_case(5, Arg6, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	FoxJumping ___test;

	___test.run_test(-1);

}

// END CUT HERE
