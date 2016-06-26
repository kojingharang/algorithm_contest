// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There are N boxes numbered 0 through N-1. Every box except for one contains carrots, but Rabbit Hanako does not know which box is the empty one. Each box has the same probability of being empty.


Hanako wants to find the empty box without opening it. Fortunately, she has some clues. Some of the boxes contain information about the content of other boxes, and she knows which boxes contain such information. You are given a vector <string> information, where the j-th character of the i-th element is 'Y' if opening the i-th box will reveal whether or not the j-th box contains carrots, or 'N' if the i-th box contains no such information.


Return the probability that she can find the empty box without opening it, assuming she behaves optimally.

DEFINITION
Class:CarrotBoxes
Method:theProbability
Parameters:vector <string>
Returns:double
Method signature:double theProbability(vector <string> information)


CONSTRAINTS
-information will contain between 1 and 50 elements, inclusive.
-Each element of information will contain exactly N characters, where N is the number of elements of information.
-The i-th character of the i-th element of information will be 'Y'.
-Each character in information will be 'Y' or 'N'.


EXAMPLES

0)
{"YYYYY",
 "NYNNN",
 "NNYNN",
 "NNNYN",
 "NNNNY"}


Returns: 0.8

The optimal strategy is opening box 0 first. If box 0 contains carrots, she can find the empty box without opening it because box 0 contains information about all boxes. It happens with probability 0.8.

1)
{"YNNNN",
 "NYNNN",
 "NNYNN",
 "NNNYN",
 "NNNNY"}

Returns: 0.2

No box contains information about other boxes, so she can find the empty box without opening it only when she opens all other boxes. It happens with probability 0.2.

2)
{"Y"}

Returns: 1.0

Since there is only one box, she knows that the only box is empty.

3)
{"YNNNN",
 "YYNNN",
 "YNYNN",
 "NNNYY",
 "NNNYY"}


Returns: 0.6



4)
{"YYYNNNYN",
 "NYNNNNYN",
 "NNYNNNNN",
 "NYNYNNNN",
 "YNNNYNNY",
 "NNYNNYNN",
 "NNNNYNYN",
 "NNYNNNNY"}


Returns: 0.875



5)
{"YNNNNNNNNYNNNNNNNNNN",
 "NYNNNNNNNNNNNNNNNNNN",
 "NNYNNNNNNNYNNNNNYNNN",
 "NNNYNYNNNNNNNNYNNNNN",
 "NNNNYNNNNNNNNNYNNNNY",
 "NNNNNYNNNNNNNNNNNNNY",
 "NNNNYNYNYNNNNNNNNNNN",
 "NNNNNNNYNNNYYNNNNNNN",
 "NNNNNNNNYNNNNNNNNNNN",
 "YNNNNNNNNYNNNNNYNNNN",
 "NNNNNNNNNNYNNNNNNNNN",
 "NYNNNNNNNNNYNNNNNNNN",
 "NNNNNNNYNNNNYNNNNNNN",
 "NNNNNNNNNNNNNYNNNYNN",
 "NNNNNNNNNNNYNNYNNNYN",
 "NYNNNNNNNNNNNNNYNNNN",
 "NNYNNNNNNNNNNNNNYNNN",
 "NNNNNNNNNNNNNYNYNYNN",
 "NNNNNNNNYNYNNNNNNNYY",
 "NNNYNNNNNNNNNNNNNNNY"}

Returns: 0.75



*/
// END CUT HERE
#line 115 "CarrotBoxes.cpp"
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


class CarrotBoxes {
	public:
	double theProbability(vector <string> information) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YYYYY",
 "NYNNN",
 "NNYNN",
 "NNNYN",
 "NNNNY"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.8; verify_case(0, Arg1, theProbability(Arg0)); }
	void test_case_1() { string Arr0[] = {"YNNNN",
 "NYNNN",
 "NNYNN",
 "NNNYN",
 "NNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.2; verify_case(1, Arg1, theProbability(Arg0)); }
	void test_case_2() { string Arr0[] = {"Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(2, Arg1, theProbability(Arg0)); }
	void test_case_3() { string Arr0[] = {"YNNNN",
 "YYNNN",
 "YNYNN",
 "NNNYY",
 "NNNYY"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.6; verify_case(3, Arg1, theProbability(Arg0)); }
	void test_case_4() { string Arr0[] = {"YYYNNNYN",
 "NYNNNNYN",
 "NNYNNNNN",
 "NYNYNNNN",
 "YNNNYNNY",
 "NNYNNYNN",
 "NNNNYNYN",
 "NNYNNNNY"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.875; verify_case(4, Arg1, theProbability(Arg0)); }
	void test_case_5() { string Arr0[] = {"YNNNNNNNNYNNNNNNNNNN",
 "NYNNNNNNNNNNNNNNNNNN",
 "NNYNNNNNNNYNNNNNYNNN",
 "NNNYNYNNNNNNNNYNNNNN",
 "NNNNYNNNNNNNNNYNNNNY",
 "NNNNNYNNNNNNNNNNNNNY",
 "NNNNYNYNYNNNNNNNNNNN",
 "NNNNNNNYNNNYYNNNNNNN",
 "NNNNNNNNYNNNNNNNNNNN",
 "YNNNNNNNNYNNNNNYNNNN",
 "NNNNNNNNNNYNNNNNNNNN",
 "NYNNNNNNNNNYNNNNNNNN",
 "NNNNNNNYNNNNYNNNNNNN",
 "NNNNNNNNNNNNNYNNNYNN",
 "NNNNNNNNNNNYNNYNNNYN",
 "NYNNNNNNNNNNNNNYNNNN",
 "NNYNNNNNNNNNNNNNYNNN",
 "NNNNNNNNNNNNNYNYNYNN",
 "NNNNNNNNYNYNNNNNNNYY",
 "NNNYNNNNNNNNNNNNNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.75; verify_case(5, Arg1, theProbability(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	CarrotBoxes ___test;

	___test.run_test(-1);

}

// END CUT HERE
