// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There are N rabbits who like to gossip. They are numbered from 0 to N-1.

There are two rumors. Let's call them A and B. At this moment, each rabbit either knows both rumors or no rumors at all. The rabbits want to spread the rumors to everyone as quickly as possible.

Rabbits are very picky when it comes to spreading rumors. Each rabbit only trusts some of the other rabbits. Moreover, the situation is not necessarily symmetric - there may be rabbits A and B such that A trusts B, but B does not trust A.

At the beginning of each day, each rabbit who knows at least one rumor chooses a rumor X it knows. The rabbit then spends the day spreading rumor X. A rabbit will learn a new rumor if it is spreaded by someone it trusts. Note that a rabbit may learn both rumors in the same day (from two different other rabbits). Also note that a rabbit may spread one rumor and learn the other rumor on the same day.

You are given a string knowledge and a vector <string> graph. The string knowledge has exactly N characters. Character i of knowledge is 'Y' if rabbit i already knows both rumors, or 'N' if it does not know the rumors yet. The vector <string> graph contains N strings with N characters each. Element i of graph describes rabbits who trust rabbit i: character j of element i of graph is 'Y' if rabbit j trusts rabbit i, or 'N' if rabbit j does not trust rabbit i. In other words, graph[i][j] is 'Y' if and only if rabbit i will spread rumors to rabbit j.

Return the minimum number of days needed to spread both rumors so that each of the N rabbits will know both rumors. If it is impossible, return -1.

DEFINITION
Class:Rumor
Method:getMinimum
Parameters:string, vector <string>
Returns:int
Method signature:int getMinimum(string knowledge, vector <string> graph)


CONSTRAINTS
-knowledge will contain between 1 and 16 characters, inclusive.
-Each character of knowledge will be either 'Y' or 'N'.
-knowledge will contain at least one 'Y' character.
-graph will contain N elements, where N is the length of knowledge.
-Each element of graph will contain N characters.
-Each character of graph will be either 'Y' or 'N'.
-i-th character of i-th element of graph will be 'N'.


EXAMPLES

0)
"YNN"
{"NYN"
,"NNY"
,"NNN"}

Returns: 3

Initially, there are 3 rabbits. Rabbit 0 knows rumor A and B, and other rabbits know nothing.

One of the optimal ways is as follows.

On day 1, rabbit 0 sends information about rumor A to rabbit 1.
On day 2, rabbit 1 sends information about rumor A to rabbit 2, and rabbit 0 sends information about rumor B to rabbit 1.
On day 3, rabbit 1 sends information about rumor B to rabbit 2.

As a result, it takes 3 days.

1)
"YNNY"
{"NYYN"
,"YNNY"
,"YNNY"
,"NYYN"}

Returns: 1

One of the optimal ways is as follows.

On day 1, rabbit 0 sends information about rumor A to rabbit 1 and rabbit 2, and rabbit 3 sends information about rumor B to rabbit 1 and rabbit 2.


2)
"YYYY"
{"NYNN"
,"YNYN"
,"NYNY"
,"NNYN"}

Returns: 0

All rabbits already know the rumors, so no day is required.

3)
"YYYYYN"
{"NYYYYN"
,"YNYYYN"
,"YYNYYN"
,"YYYNYN"
,"YYYYNN"
,"NNNNNN"}

Returns: -1

It is impossible to make rabbit 5 know the rumors.

4)
"NNNY"
{"NNNN"
,"YNNN"
,"YNNN"
,"NYYN"}

Returns: 3



5)
 "NNNNNNNYYY"
{"NYNNYNNYNN"
,"NNYNYNNNNY"
,"YYNNNYNNNN"
,"YNNNYNYNNN"
,"NNYNNYNNYN"
,"NNNNYNNNYY"
,"NYNYNYNNNN"
,"NNNNNNYNYY"
,"NNNYNNNYNY"
,"NYYNNNNYNN"}


Returns: 2



*/
// END CUT HERE
#line 124 "Rumor.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
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



class Rumor {
	public:
	int getMinimum(string knowledge, vector <string> graph) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNN"; string Arr1[] = {"NYN"
,"NNY"
,"NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "YNNY"; string Arr1[] = {"NYYN"
,"YNNY"
,"YNNY"
,"NYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "YYYY"; string Arr1[] = {"NYNN"
,"YNYN"
,"NYNY"
,"NNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "YYYYYN"; string Arr1[] = {"NYYYYN"
,"YNYYYN"
,"YYNYYN"
,"YYYNYN"
,"YYYYNN"
,"NNNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "NNNY"; string Arr1[] = {"NNNN"
,"YNNN"
,"YNNN"
,"NYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_5() { string Arg0 =  "NNNNNNNYYY"; string Arr1[] = {"NYNNYNNYNN"
,"NNYNYNNNNY"
,"YYNNNYNNNN"
,"YNNNYNYNNN"
,"NNYNNYNNYN"
,"NNNNYNNNYY"
,"NYNYNYNNNN"
,"NNNNNNYNYY"
,"NNNYNNNYNY"
,"NYYNNNNYNN"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(5, Arg2, getMinimum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	Rumor ___test;

	___test.run_test(-1);

}

// END CUT HERE
