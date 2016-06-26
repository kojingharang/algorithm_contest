// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// In this problem you will be given a  string text and you will need to find the substring of the text that matches a given template in the best way.
The template will be represented by two strings: prefix and suffix.
Consider a string S. The prefix match score of S with respect to a given template is the maximal n >= 0 such that the first n characters of S are equal to the last n characters of prefix and occur in the same exact order. Analogously, the suffix match score of S is the maximal m >= 0 such that the last m characters of S are equal to the first m characters of suffix and occur in the same exact order.

For example, if S = "something", prefix = "awesome", and suffix = "ingenious", than the prefix score of S is 4 (the matched characters are "some") and the suffix score is 3 (the matched characters are "ing").

The match score of a string S with respect to a given template is the sum of its prefix and suffix match scores. Find the non-empty substring of text with the maximal match score according to the template (prefix, suffix). In case of a tie, return the substring with the maximal prefix score. If there are still several candidates, return one that comes first lexicographically.

DEFINITION
Class:TemplateMatching
Method:bestMatch
Parameters:string, string, string
Returns:string
Method signature:string bestMatch(string text, string prefix, string suffix)


NOTES
-String A comes before string B lexicographically if A is a proper prefix of B, or if A has a smaller character at the first position where the strings differ. When comparing the characters, refer to the following list of characters in ascending order: ' ', 'a', 'b', ..., 'z'.


CONSTRAINTS
-text will contain between 1 and 50 characters, inclusive.
-prefix will contain between 1 and 50 characters, inclusive.
-suffix will contain between 1 and 50 characters, inclusive.
-text, prefix and suffix will contain only lowercase letters ('a'-'z') and spaces (' ').


EXAMPLES

0)
"something"
"awesome"
"ingenious"

Returns: "something"

The example from the problem statement.

1)
"havka"
"eto"
"papstvo"

Returns: "a"

The return value must be non-empty string, so the correct answer is "a".

2)
"abracadabra"
"habrahabr"
"bracket"

Returns: "abrac"



3)
"mississippi"
"promise"
"piccolo"

Returns: "ippi"



4)
"a a a a a a"
"a a"
"a"

Returns: "a a"



5)
"ab"
"b"
"a"

Returns: "b"



*/
// END CUT HERE
#line 90 "TemplateMatching.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class TemplateMatching {
	public:
	string bestMatch(string text, string pre, string suf) {
		int N=text.size();
		int mps=0;
		int mss=0;
		string mt("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
		REP(i, N) {
			for(int j=i;j<N;j++) {
				string s(text.substr(i, j-i+1));
				int ps=0, ss=0;
				for(int L=min(s.size(), pre.size());L>=0;L--) {
					if(s.substr(0, L)==pre.substr(pre.size()-L, L)) {
						ps=L;
						break;
					}
				}
				for(int L=min(s.size(), suf.size());L>=0;L--) {
					if(s.substr(s.size()-L, L)==suf.substr(0, L)) {
						ss=L;
						break;
					}
				}
				if(ps+ss>mps+mss || ps+ss==mps+mss && ps>mps || ps+ss==mps+mss && ps==mps && s<mt) {
					mps=ps;
					mss=ss;
					mt=s;
				}
			}
		}
		return mt;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "something"; string Arg1 = "awesome"; string Arg2 = "ingenious"; string Arg3 = "something"; verify_case(0, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "havka"; string Arg1 = "eto"; string Arg2 = "papstvo"; string Arg3 = "a"; verify_case(1, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "abracadabra"; string Arg1 = "habrahabr"; string Arg2 = "bracket"; string Arg3 = "abrac"; verify_case(2, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "mississippi"; string Arg1 = "promise"; string Arg2 = "piccolo"; string Arg3 = "ippi"; verify_case(3, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "a a a a a a"; string Arg1 = "a a"; string Arg2 = "a"; string Arg3 = "a a"; verify_case(4, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "ab"; string Arg1 = "b"; string Arg2 = "a"; string Arg3 = "b"; verify_case(5, Arg3, bestMatch(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	TemplateMatching ___test;

	___test.run_test(-1);

}

// END CUT HERE
