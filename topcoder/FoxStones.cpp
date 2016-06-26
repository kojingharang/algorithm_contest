// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel has a rectangular board separated into 1x1 cells.  The board is N cells wide and M cells high.  Columns are numbered 1 to N from left to right, and rows are numbered 1 to M from top to bottom.  A cell in column x, row y is said to have coordinates (x, y).  Each cell contains a stone, and all stones are different.  Also, some cells are marked.  These marked cells are given in the vector <int>s sx and sy, where (sx[i], sy[i]) are the coordinates of the i-th marked cell.

Ciel is interested to know how many layouts of the same stones on this board are similar to the current layout.  Two layouts are considered to be similar if, for each possible pairing of a stone and a marked cell, the distance between the stone and the marked cell is the same in both layouts.  The distance between cells with coordinates (xA, yA) and (xB, yB) is defined as max{|xA-xB|, |yA-yB|}, where |z| is the absolute value of z.

Return the number of layouts that are similar to the current layout, modulo 1,000,000,009. Note that according to the definition above, the current layout is similar to itself, so it should also be counted.


DEFINITION
Class:FoxStones
Method:getCount
Parameters:int, int, vector <int>, vector <int>
Returns:int
Method signature:int getCount(int N, int M, vector <int> sx, vector <int> sy)


CONSTRAINTS
-N and M will each be between 1 and 200, inclusive.
-sx and sy will each contain between 1 and 50 elements, inclusive.
-sx and sy will contain the same number of elements.
-Each element of sx will be between 1 and N, inclusive.
-Each element of sy will be between 1 and M, inclusive.
-No two cells represented by sx and sy will have the same coordinates.


EXAMPLES

0)
6
1
{3}
{1}

Returns: 4

There are 4 similar layouts:



1)
2
2
{2}
{1}

Returns: 6



2)
3
3
{1,2,3}
{1,2,3}

Returns: 8



3)
12
34
{5,6,7,8,9,10}
{11,12,13,14,15,16}

Returns: 410850247



*/
// END CUT HERE
#line 75 "FoxStones.cpp"
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


class FoxStones {
	public:
	int getCount(int N, int M, vector <int> sx, vector <int> sy) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 1; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(0, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; verify_case(1, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 8; verify_case(2, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 34; int Arr2[] = {5,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {11,12,13,14,15,16}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 410850247; verify_case(3, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	FoxStones ___test;

	___test.run_test(-1);

}

// END CUT HERE
