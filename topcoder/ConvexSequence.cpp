// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
A sequence x[0], ..., x[N-1] of integers is called convex if for every 1&lt=i&lt=N-2, x[i-1]+x[i+1]&gt=2*x[i]. 
For example, sequences 7,3,4,5,7 and 4,2,1,3 are convex, while 4,3,1,2 and 5,7,3 are not. 
A sequence with one or two elements is always convex. 

You are given a vector <int> a containing N elements. You can perform an operation that chooses an index i and replaces a[i] with a[i]-1.
Return the minimum number of operations needed to make the sequence convex.


DEFINITION
Class:ConvexSequence
Method:getMinimum
Parameters:vector <int>
Returns:long long
Method signature:long long getMinimum(vector <int> a)


CONSTRAINTS
-a will contain between 1 and 50 elements, inclusive.
-Each element of a will be between 0 and 10^9, inclusive.


EXAMPLES

0)
{6,5,1,5,3,3}

Returns: 7

You can change the given sequence into a convex sequence by seven operations: doing the operation on a[1] twice, on a[3] four times and on a[4] once yields a convex sequence 6,3,1,1,2,3.

1)
{3,0,1,4}

Returns: 0

No operation is needed; the sequence is already convex. 

2)
{1,1,1,0,2,2,2}

Returns: 5

You can change the sequence into 1,0,0,0,0,1,2 by five operations.

3)
{854159326, 317144183, 781399725, 287076509, 894967145, 882577367, 174517516, 134415519,
 274494874, 709819883, 59717133, 732212854, 40551288, 232526958, 811785438, 930853743,
 946882902, 321325300, 397702677, 376192501, 599310562, 889156198, 135776890, 882710939,
 823196361, 681959076, 318666702, 94469186, 536320456, 116468376, 530320850, 436708006,
 903344748, 659080120, 774722507, 967315412, 566063635, 43970906, 497687103, 781266213,
 876086123, 366960001, 587364849, 191948103, 172568553, 539762057, 83507466, 71569625,
 686305822, 663789601}

Returns: 20178337330



4)
{5}

Returns: 0



*/
// END CUT HERE
#line 72 "ConvexSequence.cpp"
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
using namespace std;
#define REP(i, n) for(int i=0, _n=(n);(i)<_n;i++)
class ConvexSequence {
	public:
	long long getMinimum(vector <int> a) {
		
		if(a.size()<=2) return 0;
		ll ret = 0;
		while(1)//REP(loop, 1000)
		{
			int changed=0;
			for(int i=0; i<a.size()-2; i++)
			{
				if(a[i]+a[i+2]<a[i+1]*2)
				{
					ret += a[i+1] - (a[i]+a[i+2])/2;
					a[i+1] = (a[i]+a[i+2])/2;
					changed=1;
				}
			}
			if(!changed) break;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,5,1,5,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { int Arr0[] = {3,0,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,0,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(2, Arg1, getMinimum(Arg0)); }
	void test_case_3() { int Arr0[] = {854159326, 317144183, 781399725, 287076509, 894967145, 882577367, 174517516, 134415519,
 274494874, 709819883, 59717133, 732212854, 40551288, 232526958, 811785438, 930853743,
 946882902, 321325300, 397702677, 376192501, 599310562, 889156198, 135776890, 882710939,
 823196361, 681959076, 318666702, 94469186, 536320456, 116468376, 530320850, 436708006,
 903344748, 659080120, 774722507, 967315412, 566063635, 43970906, 497687103, 781266213,
 876086123, 366960001, 587364849, 191948103, 172568553, 539762057, 83507466, 71569625,
 686305822, 663789601}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 20178337330LL; verify_case(3, Arg1, getMinimum(Arg0)); }
	void test_case_4() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(4, Arg1, getMinimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	ConvexSequence ___test;

	___test.run_test(-1);

}

// END CUT HERE
