// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
You are writing a simple text editor that supports only the following two commands: 

"type c" where c is a character: Append character c to the end of the current text.
"undo t" where t is an integer: Undo all operations that were performed in the previous t seconds in reverse order.



All quotes are for clarity only.  The text in the editor is initially empty.


For example, consider the following sequence of commands:


Second 1: type a
Second 2: type b
Second 3: type c
Second 5: undo 3


At the end of second 3, the text is "abc".  At second 5, all commands performed in the previous 3 seconds are undone in reverse order.  This means 'c' is removed, and then 'b' is removed.  The text becomes just "a".


Note that "undo" commands can also be undone.  For example:


Second 1: type a
Second 2: type b
Second 3: undo 2
Second 4: undo 2


After second 2, the text is "ab".  After second 3, everything is undone, and the text becomes empty.  At second 4, the previous "undo" is undone, so the text becomes "ab" again.  Then, the "type b" is also undone and the text becomes just "a".


You are given a vector <string> commands and a vector <int> time.  Each element of commands is a single command, and commands[i] is performed at time[i].  The commands are given in chronological order.  Return the text after all the commands are executed.


DEFINITION
Class:Undo
Method:getText
Parameters:vector <string>, vector <int>
Returns:string
Method signature:string getText(vector <string> commands, vector <int> time)


CONSTRAINTS
-commands will contain between 1 and 50 elements, inclusive.
-Each element of commands will be either "type c" where c is a lowercase letter ('a'-'z') or "undo t" where t is an integer between 1 and 10^9, inclusive, with no leading zeroes (quotes for clarity only).
-time will contain the same number of elements as commands.
-Each element of time will be between 1 and 10^9, inclusive.
-The elements of time will be in strictly ascending order.


EXAMPLES

0)
{"type a", "type b", "type c", "undo 3"}
{1, 2, 3, 5}

Returns: "a"

The first example from the problem statement.

1)
{"type a", "type b", "undo 2", "undo 2"}
{1,2,3,4}

Returns: "a"

The second example from the problem statement.

2)
{"type a", "undo 1", "undo 1"}
{1,2,3}

Returns: "a"



3)
{"type a", "type b", "type c", "undo 10"}
{1, 2, 3, 1000}

Returns: "abc"

Note that "undo" can undo nothing if it is too late.

4)
{"undo 1"}
{1}

Returns: ""



*/
// END CUT HERE
#line 103 "Undo.cpp"

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


class Undo {
	public:
	string getText(vector <string> cmd, vector <int> ti) {
		int N=cmd.size();
		VVI can(N, VI(N, 0));
		REP(i, cmd.size()) {
			if(cmd[i][0]=='u') {
				int t = atoi(cmd[i].c_str()+5);
				for(int j=ti.size()-1;j>=0 && ti[i]-t <= ti[j];j--) {
					can[j][i]=1;
				}
			}
		}
		VI valid(N, 1);
		for(int i=N-1;i>=0;i--) {
			for(int j=i+1;j<N;j++) {
				if(valid[j] && can[i][j]) valid[i]=0;
			}
		}
		string ans;
		REP(i, cmd.size()) {
			if(valid[i]) {
				if(cmd[i][0]=='t') ans.push_back(cmd[i][5]);
			}
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"type a", "type b", "type c", "undo 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(0, Arg2, getText(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"type a", "type b", "undo 2", "undo 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(1, Arg2, getText(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"type a", "undo 1", "undo 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(2, Arg2, getText(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"type a", "type b", "type c", "undo 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "abc"; verify_case(3, Arg2, getText(Arg0, Arg1)); }
	//void test_case_4() { string Arr0[] = {"undo 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(4, Arg2, getText(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"type a", "undo 1", "undo 2", "undo 3", "undo 4", "undo 5", "undo 6", "undo 7", "undo 8", "undo 9", "undo 10", "undo 11", "undo 12", "undo 13", "undo 14", "undo 15", "undo 16", "undo 17", "undo 18", "undo 19", "undo 20", "undo 21", "undo 22", "undo 23", "undo 24", "undo 25", "undo 26", "undo 27", "undo 28", "undo 29", "undo 30", "undo 31", "undo 32", "undo 33", "undo 34", "undo 35", "undo 36", "undo 37", "undo 38", "undo 39", "undo 40", "undo 41", "undo 42", "undo 43", "undo 44", "undo 45", "undo 46", "undo 47", "undo 48", "undo 49"
	}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(4, Arg2, getText(Arg0, Arg1)); }



// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	Undo ___test;

	___test.run_test(-1);

}

// END CUT HERE
