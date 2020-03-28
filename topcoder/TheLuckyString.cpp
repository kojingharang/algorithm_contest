// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// John and Brus are studying string theory at the university.  According to Brus, a string is called lucky if no two consecutive characters are equal.  John is analyzing a string s, and he wants to know how many distinct lucky strings can be generated by reordering the letters in s.  If s is a lucky string in its original ordering, it should also be considered in the count.

DEFINITION
Class:TheLuckyString
Method:count
Parameters:string
Returns:int
Method signature:int count(string s)


CONSTRAINTS
-s will contain between 1 and 10 characters, inclusive.
-Each character of s will be a lowercase letter ('a' - 'z').


EXAMPLES

0)
"ab"

Returns: 2

Two lucky strings - "ab" and "ba".

1)
"aaab"

Returns: 0

It's impossible to construct a lucky string.

2)
"aabbbaa"

Returns: 1

"abababa" is the only lucky string that can be generated.

3)
"abcdefghij"

Returns: 3628800

*/
// END CUT HERE
#line 50 "TheLuckyString.cpp"

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



class TheLuckyString {
	public:
	int count(string s) {
		sort(ALL(s));
		int ans=0;
		do {
			int ok=1;
			REP(i, s.size()-1) if(s[i]==s[i+1]) ok=0;
			ans+=ok;
		} while(next_permutation(ALL(s)));
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = "aaab"; int Arg1 = 0; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "aabbbaa"; int Arg1 = 1; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = "abcdefghij"; int Arg1 = 3628800; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	TheLuckyString ___test;

	___test.run_test(-1);

}

// END CUT HERE