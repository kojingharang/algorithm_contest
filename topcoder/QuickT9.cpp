// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Most modern mobile phones include T9 technology for typing text messages faster, and your brand new mobile phone is not an exception.
Your mobile phone has the standard keyboard layout:

  Button     Letters
    2         a,b,c
    3         d,e,f
    4         g,h,i
    5         j,k,l
    6         m,n,o
    7        p,q,r,s
    8         t,u,v
    9        w,x,y,z

T9 requires a dictionary of words. At each moment, T9 maintains three strings: D -- the current combination of digits, F -- the "fixed" part of the message and U -- the "unfixed" part of the message. The message displayed on the phone's screen consists of the "fixed" part immediately followed by the "unfixed" part, i.e., it appears as F + U. The current combination of digits D is only stored in memory and not displayed. There always is the following correspondence between D and U: they have the same length and the i-th character in U is a letter written on the button with digit equal to the i-th character in D. Additionally, the string U must always be such that there's at least one word in the dictionary that starts with U. For a given combination of digits D, we will call a string U valid if it satisfies the described conditions.

When you start typing a new message, all three strings D, F and U are empty. Then you may do the following:

press one of the digit buttons (2-9): first, the pressed digit is added to the end of D, then U is changed to the lexicographically earliest string that is valid for the new value of D. If there are no such strings, the button press is ignored, so the values of D and U remain the same as before the button press.
press the Right button: first, U is appended to the end of F, then both D and U are reset to empty strings.
press the C button: U is appended to the end of F, then both D and U are reset to empty strings, finally, if F is not empty, the last character is removed from F.
press the * button: U is changed to the lexicographically next string valid for the current value of D. If there is no such string, it is set to the lexicographically smallest valid string again.

T9 technology is very useful when you need to type a message consisting of dictionary words. However there is a small drawback - typing a word that is not contained in the dictionary becomes much more difficult, so usually you have to type this word part by part (turning T9 off is not considered).
The problem you are facing now is to type a given word using T9. Return the smallest number of button presses needed to type this word on your mobile phone if it is possible at all, otherwise return -1. The word is considered to be typed if F is equal to the word and U is empty.
The dictionary is given in vector <string> t9. Each element of t9 is a list of words from the dictionary separated by single spaces.

DEFINITION
Class:QuickT9
Method:minimumPressings
Parameters:vector <string>, string
Returns:int
Method signature:int minimumPressings(vector <string> t9, string word)


NOTES
-If two Strings A and B have the same length, then A comes before B lexicographically if it has an alphabetically earlier character at the first position where the Strings differ.
-It's possible that the dictionary contains multiple occurrences of the same word.


CONSTRAINTS
-t9 will contain between 1 and 50 elements, inclusive.
-Each element of t9 will contain between 1 and 50 characters, inclusive.
-Each element of t9 will contain only lowercase letters ('a'-'z') and spaces, and will contain no leading, trailing or consecutive spaces.
-word will contain between 1 and 50 characters, inclusive.
-word will contain only lowercase letters ('a'-'z').


EXAMPLES

0)
{"aae", "bab", "abad", "bdbd", "beta"}
"babe"

Returns: 9

   Button  Result (the "unfixed" part of message in quotes)
1)   2      "a"          (beginning of "aae")
2)   2      "aa"         (beginning of "aae")
3)   2      "aba"        (beginning of "abad")
4)   *      "bab"        (beginning of "bab")
5)   C      ba
6)   2      ba"a"        (beginning of "aae")
7)   3      ba"bd"       (beginning of "bdbd")
8)   *      ba"be"       (beginning of "beta")
9) Right    babe


1)
{"ann","ie"}
"annie"

Returns: 7

   Button  Result (the "unfixed" part of message in quotes)
1)   2      "a"          (beginning of "ann")
2)   6      "an"         (beginning of "ann")
3)   6      "ann"        (beginning of "ann")
4) Right    ann
5)   4      ann"i"       (beginning of "ie")
6)   3      ann"ie"      (beginning of "ie")
7) Right    annie


2)
{"ann","amm"}
"annie"

Returns: -1



3)
{"aaa aab","aac aba abb ccca"}
"aba"

Returns: 6

   Button  Result (the "unfixed" part of message in quotes)
1)   2      "a"          (beginning of "aaa")
2)   2      "aa"         (beginning of "aaa")
3)   *      "ab"         (beginning of "aba")
4) Right    ab
5)   2      ab"a"        (beginning of "aaa")
6) Right    aba


4)
{"acac aba aaab","aab aa baa","bba bacade abb","baba"}
"abbaca"

Returns: 10

   Button  Result (the "unfixed" part of message in quotes)
1)   2      "a"          (beginning of "aa")
2)   2      "aa"         (beginning of "aa")
3)   *      "ab"         (beginning of "aba")
4) Right    ab
5)   2      ab"a"        (beginning of "aa")
6)   2      ab"aa"       (beginning of "aa")
7)   2      ab"aaa"      (beginning of "aaab")
8)   2      ab"aaab"     (beginning of "aaab")
9)   3      ab"bacad"    (beginning of "bacade")
10)  C      abbaca


5)
{"aaa aab aac","aba abb","ccca"}
"ccc"

Returns: 5



*/
// END CUT HERE
#line 140 "QuickT9.cpp"
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


class QuickT9 {
	public:
	int minimumPressings(vector <string> t9, string word) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"aae", "bab", "abad", "bdbd", "beta"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "babe"; int Arg2 = 9; verify_case(0, Arg2, minimumPressings(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ann","ie"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "annie"; int Arg2 = 7; verify_case(1, Arg2, minimumPressings(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"ann","amm"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "annie"; int Arg2 = -1; verify_case(2, Arg2, minimumPressings(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"aaa aab","aac aba abb ccca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aba"; int Arg2 = 6; verify_case(3, Arg2, minimumPressings(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"acac aba aaab","aab aa baa","bba bacade abb","baba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abbaca"; int Arg2 = 10; verify_case(4, Arg2, minimumPressings(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"aaa aab aac","aba abb","ccca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ccc"; int Arg2 = 5; verify_case(5, Arg2, minimumPressings(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	QuickT9 ___test;

	___test.run_test(-1);

}

// END CUT HERE
