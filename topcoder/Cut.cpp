// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel wants to eat eels as a celebration of this year's end.

Initially, Ciel has some eels of various lengths. She only likes to eat eels of length exactly 10, no more, no less.
Before she eats, she may cut the eels to prepare pieces of desired length. However, she only has the time to make at most maxCuts cuts. A single cut looks as follows:

Fox Ciel chooses one of the eels. Let its length be x. She can only choose an eel of length greater than 1.
She chooses an integer y such that 0 < y < x.
She cuts the eel into two pieces so that one of them measures exactly y.
In other words, instead of one eel of length x she now has two eels of lengths y and (x-y), respectively.


You are given a vector <int> eelLengths. Each element of eelLengths is the length of one of the eels Ciel has at the beginning.
You are also given the int maxCuts.
Return the maximum number of eels of length exactly 10 she can produce.

DEFINITION
Class:Cut
Method:getMaximum
Parameters:vector <int>, int
Returns:int
Method signature:int getMaximum(vector <int> eelLengths, int maxCuts)


CONSTRAINTS
-eelLengths will contain between 1 and 50 elements, inclusive.
-Each element of eelLengths will be between 1 and 1,000, inclusive.
-maxCuts will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{13, 20, 13}
2

Returns: 3

One optimal solution looks as follows:

First, cut eel 0 into two pieces of lengths 10 and 3. Next, cut eel 1 into two equal parts of length 10 each. This produces a total of 3 eels whose length is 10.



1)
{5, 5, 5, 5}
2

Returns: 0

There are four eels whose length is 5.
As you cannot combine eels, it is impossible to make an eel of length 10.

2)
{34, 10, 48}
4

Returns: 5

She already has one eel of length 10. By cutting the other two eels she can produce four more eels of the desired length.

3)
{30, 50, 30, 50}
350

Returns: 16

She may cut eels at most 350 times, but in this case she doesn't have to cut them so many times.

*/
// END CUT HERE
#line 75 "Cut.cpp"

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



class Cut {
	public:
	int getMaximum(vector <int> es, int mc) {
		int ans = 0;
		sort(ALL(es));
		REP(jj, 2)
		FOR(v, es) {
			if(!(jj==0&&*v%10==0 || jj==1&&*v%10>0)) continue;
			while(*v>10 && mc>0) {
				*v-=10;
				ans++;
				if(*v>0) mc--;
			}
			if(*v==10) ans++;
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	//void test_case_0() { int Arr0[] = {13, 20, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_0() { int Arr0[] = {14, 20,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5, 5, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {34, 10, 48}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {30, 50, 30, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 350; int Arg2 = 16; verify_case(3, Arg2, getMaximum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	Cut ___test;

	___test.run_test(-1);

}

// END CUT HERE
