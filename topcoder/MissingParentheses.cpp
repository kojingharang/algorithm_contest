// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Given a string of parentheses, you must turn it into a well formed string by inserting as few parentheses as possible, at any position (you cannot delete or change any of the existing parentheses).

A well formed string of parentheses is defined by the following rules:

    The empty string is well formed.
    If s is a well formed string, (s) is a well formed string.
    If s and t are well formed strings, their concatenation st is a well formed string.

As examples, "(()())", "" and "(())()" are well formed strings and "())(", "()(" and ")" are malformed strings.

Given a string par of parentheses, return the minimum number of parentheses that need to be inserted to make it into a well formed string.


DEFINITION
Class:MissingParentheses
Method:countCorrections
Parameters:string
Returns:int
Method signature:int countCorrections(string par)


CONSTRAINTS
-par will contain between 1 and 50 characters, inclusive.
-Each character of par will be an opening or closing parenthesis, i.e., '(' or ')'.


EXAMPLES

0)
"(()(()"

Returns: 2

The string below is a possible well formed string you can get to by inserting the two closing parentheses marked.

(())(())
   ^   ^


1)
"()()(()"

Returns: 1

You can fix the string by inserting a single closing parenthesis at the end.

2)
"(())(()())"

Returns: 0

The input string is well formed, so no insertion is needed.

3)
"())(())((()))))()((())))()())())())()()()"

Returns: 7



*/
// END CUT HERE
#line 68 "MissingParentheses.cpp"
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
#define SORT(v) sort(v.B, v.E)



string Replace(std::string& _src, const string pszKey, const char* pszRepWord)
{
	int nPos = 0;
	string src = string(_src);
	
	while((nPos = src.find(pszKey, nPos)) != std::string::npos){
		src.replace(nPos, pszKey.size() , pszRepWord);
	}
	
	return src;
}

class MissingParentheses {
	public:
	int countCorrections(string par) {
		string prev = "";
		string cur = par;
		while(prev!=(cur=Replace(cur, "()", "")))
		{
			prev = cur;
		}
		//cout<<cur<<endl;
		return cur.size();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "(()(()"; int Arg1 = 2; verify_case(0, Arg1, countCorrections(Arg0)); }
	void test_case_1() { string Arg0 = "()()(()"; int Arg1 = 1; verify_case(1, Arg1, countCorrections(Arg0)); }
	void test_case_2() { string Arg0 = "(())(()())"; int Arg1 = 0; verify_case(2, Arg1, countCorrections(Arg0)); }
	void test_case_3() { string Arg0 = "())(())((()))))()((())))()())())())()()()"; int Arg1 = 7; verify_case(3, Arg1, countCorrections(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	MissingParentheses ___test;

	___test.run_test(-1);

}

// END CUT HERE
