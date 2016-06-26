// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A string X is an anagram of string Y if X can be obtained by arranging all characters of Y in some order, without removing any characters and without adding new characters. For example, each of the strings "baba", "abab", "aabb" and "abba" is an anagram of "aabb", and strings "aaab", "aab" and "aabc" are not anagrams of "aabb".

A set of strings is anagram-free if it contains no pair of strings which are anagrams of each other. Given a set of strings S, return the size of its largest anagram-free subset. Note that the entire set is considered a subset of itself.

DEFINITION
Class:AnagramFree
Method:getMaximumSubset
Parameters:vector <string>
Returns:int
Method signature:int getMaximumSubset(vector <string> S)


CONSTRAINTS
-S will contain between 1 and 50 elements, inclusive.
-Each element of S will contain between 1 and 50 characters, inclusive.
-Each element of S will consist of lowercase letters ('a'-'z') only.
-All elements of S will be distinct.


EXAMPLES

0)
{"abcd","abdc","dabc","bacd"}

Returns: 1

All of the strings in S are anagrams of each other, so no two of them can simultaneously belong to an anagram-free set.

1)
{"abcd","abac","aabc","bacd"}

Returns: 2

One of the maximum anagram-free subsets of S is {"abcd","abac"}.

2)
{"aa","aaaaa","aaa","a","bbaaaa","aaababaa"}

Returns: 6

Note that strings of different length cannot be anagrams of each other.

3)
{"creation","sentence","reaction","sneak","star","rats","snake"}

Returns: 4



*/
// END CUT HERE
#line 56 "AnagramFree.cpp"
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define REP(i, n) for(int i=0, _n=(n);(i)<_n;i++)
#define FOR(i, a, b) for(int i=(a),_b=(b);(i)<_b;i++)
#define FORD(i, a, b) for(int i=(a),_b=(b);(i)>=_b;i--)
#define CLR(a) memset(a, 0, sizeof(a))
class AnagramFree {
	public:
	int getMaximumSubset(vector <string> S) {
		int ss = S.size();
		map<string, int> hist;
		REP(s, ss)
		{
			sort(S[s].begin(), S[s].end());
			cout<<S[s]<<endl;
			hist[S[s]]++;
		}
		return hist.size();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"abcd","abdc","dabc","bacd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getMaximumSubset(Arg0)); }
	void test_case_1() { string Arr0[] = {"abcd","abac","aabc","bacd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getMaximumSubset(Arg0)); }
	void test_case_2() { string Arr0[] = {"aa","aaaaa","aaa","a","bbaaaa","aaababaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, getMaximumSubset(Arg0)); }
	void test_case_3() { string Arr0[] = {"creation","sentence","reaction","sneak","star","rats","snake"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, getMaximumSubset(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	AnagramFree ___test;

	___test.run_test(-1);

}

// END CUT HERE
