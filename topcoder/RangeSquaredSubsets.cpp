// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Given a real number n, a set of points P in the XY plane is called n-squared if it is not empty and there exists a square of side n in the XY plane with its sides parallel to the axes such that a point from the given set of points is in P if and only if it is contained within the square. A point lying on a side or a vertex of the square is considered to be contained in it.

You will be given two ints nlow and nhigh. You will also be given two vector <int>s x and y such that the coordinates of point i are (x[i],y[i]). Return the number of subsets of the input set described by x and y that are n-squared for some n between nlow and nhigh, inclusive.


DEFINITION
Class:RangeSquaredSubsets
Method:countSubsets
Parameters:int, int, vector <int>, vector <int>
Returns:long long
Method signature:long long countSubsets(int nlow, int nhigh, vector <int> x, vector <int> y)


CONSTRAINTS
-nlow will be between 1 and 100000000 (10^8), inclusive.
-nhigh will be between nlow and 100000000 (10^8), inclusive.
-x and y will contain between 1 and 40 elements, inclusive.
-x and y will contain the same number of elements.
-Each element of x and y will be between -100000000 (-10^8) and 100000000 (10^8), inclusive.
-All described points will be different.


EXAMPLES

0)
5
5
{-5,0,5}
{0,0,0}

Returns: 5

The following subsets are 5-squared: {(-5,0)}, {(0,0)}, {(5,0)}, {(-5,0),(0,0)}, {(0,0),(5,0)}.

1)
10
10
{-5,0,5}
{0,0,0}

Returns: 5

The following subsets are 10-squared: {(-5,0)}, {(5,0)}, {(0,0),(5,0)}, {(-5,0),(0,0)}, {(-5,0),(0,0),(5,0)}.

2)
1
100
{-5,0,5}
{0,0,0}

Returns: 6

{(-5,0),(5,0)} is not x-squared for any x. From the previous 2 examples you can infer that all other non-empty subsets are 5-squared or 10-squared.

3)
3
100000000
{-1,-1,-1,0,1,1,1}
{-1,0,1,1,-1,0,1}

Returns: 21



4)
64
108
{-56,-234,12,324,-12,53,0,234,1,12,72}
{6,34,2,235,234,234,342,324,234,234,234}

Returns: 26



*/
// END CUT HERE
#line 82 "RangeSquaredSubsets.cpp"
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


class RangeSquaredSubsets {
	public:
	long long countSubsets(int nlow, int nhigh, vector <int> x, vector <int> y) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {-5,0,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 5LL; verify_case(0, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 10; int Arr2[] = {-5,0,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 5LL; verify_case(1, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 100; int Arr2[] = {-5,0,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 6LL; verify_case(2, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 100000000; int Arr2[] = {-1,-1,-1,0,1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-1,0,1,1,-1,0,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 21LL; verify_case(3, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 64; int Arg1 = 108; int Arr2[] = {-56,-234,12,324,-12,53,0,234,1,12,72}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,34,2,235,234,234,342,324,234,234,234}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 26LL; verify_case(4, Arg4, countSubsets(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	RangeSquaredSubsets ___test;

	___test.run_test(-1);

}

// END CUT HERE
