// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Jiro likes dice. He wants to make his own dice. Each die he wants to make is a cube. Each of the 6 faces has an integer between 1 and N, inclusive. No two faces have same number. Also the following condition must be satisfied: for all faces, the sum of the numbers on opposite faces must be equal and the sum must be greater than or equal to K.

He realized that there are many ways to make such dice. He wants to know how many ways there are. Please help Jiro to make a program that is given two integers N and K and returns the number of different dice satisfying the condition mentioned above.

Two dice are considered the same if you can rotate one to form the other.


DEFINITION
Class:FoxMakingDice
Method:theCount
Parameters:int, int
Returns:long long
Method signature:long long theCount(int N, int K)


NOTES
-The answer will always fit in a signed 64-bit integer.


CONSTRAINTS
-N will be between 1 and 1,000, inclusive.
-K will be between 1 and 2,000, inclusive.


EXAMPLES

0)
6
7

Returns: 2

You can make normal dice. There are two ways to arrange the numbers.

1)
5
7

Returns: 0

You cannot make 6 sided dice with 5 numbers.

2)
1000
1

Returns: 20625666000



3)
456
123

Returns: 879075732



4)
913
1014

Returns: 4506149340



*/
// END CUT HERE
#line 73 "FoxMakingDice.cpp"
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


class FoxMakingDice {
	public:
	long long theCount(int N, int K) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 7; long long Arg2 = 2LL; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 7; long long Arg2 = 0LL; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 1; long long Arg2 = 20625666000LL; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 456; int Arg1 = 123; long long Arg2 = 879075732LL; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 913; int Arg1 = 1014; long long Arg2 = 4506149340LL; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	FoxMakingDice ___test;

	___test.run_test(-1);

}

// END CUT HERE
