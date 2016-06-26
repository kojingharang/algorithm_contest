// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel is playing a game called Addition Game.

Three numbers A, B and C are written on a blackboard, and Ciel initially has 0 points. She repeats the following operation exactly N times: She chooses one of the three numbers on the blackboard. Let X be the chosen number. She gains X points, and if X >= 1, the number X on the blackboard becomes X-1. Otherwise, the number does not change.

Return the maximum number of points she can gain if she plays optimally.


DEFINITION
Class:AdditionGame
Method:getMaximumPoints
Parameters:int, int, int, int
Returns:int
Method signature:int getMaximumPoints(int A, int B, int C, int N)


CONSTRAINTS
-A, B and C will each be between 1 and 50, inclusive.
-N will be between 1 and 150, inclusive.


EXAMPLES

0)
3
4
5
3

Returns: 13

The three numbers written on the blackboard are (3, 4, 5).  One possible optimal strategy is as follows:

Ciel chooses 5.  She gains 5 points, and the numbers become (3, 4, 4).
Ciel chooses 4.  She gains 4 points, and the numbers become (3, 3, 4).
Ciel chooses 4.  She gains 4 points, and the numbers become (3, 3, 3).

She gains a total of 5+4+4=13 points.


1)
1
1
1
8

Returns: 3

One optimal strategy is to choose a 1 in each of the first three turns, for a total of 3 points.  The numbers then become (0, 0, 0).  After that, she won't be able to gain any more points.


2)
3
5
48
40

Returns: 1140

The only optimal strategy is to choose the following numbers: 48, 47, 46, ..., 11, 10, 9.


3)
36
36
36
13

Returns: 446



4)
8
2
6
13

Returns: 57



*/
// END CUT HERE
#line 88 "AdditionGame.cpp"
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


class AdditionGame {
	public:
	int getMaximumPoints(int A, int B, int C, int N) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 5; int Arg3 = 3; int Arg4 = 13; verify_case(0, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 8; int Arg4 = 3; verify_case(1, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 48; int Arg3 = 40; int Arg4 = 1140; verify_case(2, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 36; int Arg1 = 36; int Arg2 = 36; int Arg3 = 13; int Arg4 = 446; verify_case(3, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 8; int Arg1 = 2; int Arg2 = 6; int Arg3 = 13; int Arg4 = 57; verify_case(4, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	AdditionGame ___test;

	___test.run_test(-1);

}

// END CUT HERE
