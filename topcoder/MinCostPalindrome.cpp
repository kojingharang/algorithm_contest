// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A palindrome is a string that reads the same from left to right as it does from right to left.

You are given a string s. The length of s is even. Each character of s is either 'o', 'x', or '?'
Your task in this problem is to replace each occurrence of '?' in s with either 'o' or 'x' so that s becomes a palindrome.
You are also given ints oCost and xCost.
Replacing '?' with 'o' costs oCost, and replacing '?' with 'x' costs xCost.

Return the minimum cost of replacing '?'s by 'x's and 'o's that turns s into a palindrome. If it is impossible to obtain a palindrome, return -1 instead.

DEFINITION
Class:MinCostPalindrome
Method:getMinimum
Parameters:string, int, int
Returns:int
Method signature:int getMinimum(string s, int oCost, int xCost)


NOTES
-You are not allowed to change an 'x' into an 'o' or vice versa.


CONSTRAINTS
-s will contain between 2 and 20 characters, inclusive.
-The length of s will be even.
-Each character of s will be either 'o' or 'x' or '?'.
-oCost will be between 1 and 50, inclusive.
-xCost will be between 1 and 50, inclusive.


EXAMPLES

0)
"oxo?xox?"
3
5

Returns: 8

The only way to produce a palindrome is to replace s[3] with 'x' and s[7] with 'o'. The first replacement costs 5, the second costs 3, so the total cost is 3+5=8.

1)
"x??x"
9
4

Returns: 8

There are two ways to produce a palindrome here. The cheaper one is to change both '?'s to 'x's. This costs 4+4=8. Note that you are required to replace all '?'s.

2)
"ooooxxxx"
12
34

Returns: -1

There is no '?' character, and s is not a palindrome. We have no way to change it into a palindrome.

3)
"oxoxooxxxxooxoxo"
7
4

Returns: 0

There is no '?' character, and s is already a palindrome. Making no replacements does not cost anything.

4)
"?o"
6
2

Returns: 6



5)
"????????????????????"
50
49

Returns: 980



6)
"o??oxxo?xoox?ox??x??" 
3
10

Returns: 38



*/
// END CUT HERE
#line 101 "MinCostPalindrome.cpp"

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



class MinCostPalindrome {
	public:
	int getMinimum(string s, int oCost, int xCost) {
		int ans = 0;
		REP(i, s.size()/2) {
			if(s[i]=='?'&&s[s.size()-i-1]=='?') ans += min(oCost, xCost)*2;
			else if(s[i]=='?') ans += s[s.size()-i-1]=='o'?oCost:xCost;
			else if(s[s.size()-i-1]=='?') ans += s[i]=='o'?oCost:xCost;
			else if(s[i]!=s[s.size()-i-1]) return -1;
		}
		if(s.size()&1) if(s[s.size()/2]=='?') ans += min(oCost, xCost);
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "oxo?xox?"; int Arg1 = 3; int Arg2 = 5; int Arg3 = 8; verify_case(0, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "x??x"; int Arg1 = 9; int Arg2 = 4; int Arg3 = 8; verify_case(1, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	//void test_case_1() { string Arg0 = "x?x"; int Arg1 = 9; int Arg2 = 4; int Arg3 = 8; verify_case(1, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "ooooxxxx"; int Arg1 = 12; int Arg2 = 34; int Arg3 = -1; verify_case(2, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "oxoxooxxxxooxoxo"; int Arg1 = 7; int Arg2 = 4; int Arg3 = 0; verify_case(3, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "?o"; int Arg1 = 6; int Arg2 = 2; int Arg3 = 6; verify_case(4, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "????????????????????"; int Arg1 = 50; int Arg2 = 49; int Arg3 = 980; verify_case(5, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arg0 = "o??oxxo?xoox?ox??x??" ; int Arg1 = 3; int Arg2 = 10; int Arg3 = 38; verify_case(6, Arg3, getMinimum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	MinCostPalindrome ___test;

	___test.run_test(-1);

}

// END CUT HERE
