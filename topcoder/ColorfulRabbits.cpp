// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Cat Pochi visited a town of rabbits and asked some of the rabbits the following question: 
"How many rabbits in this town other than yourself have the same color as you?". 
The rabbits all replied truthfully, and no rabbit was asked the question more than once. 
You are given the rabbits' replies in the vector <int> replies. 
Return the minimum possible number of rabbits in this town. 


DEFINITION
Class:ColorfulRabbits
Method:getMinimum
Parameters:vector <int>
Returns:int
Method signature:int getMinimum(vector <int> replies)


CONSTRAINTS
-replies will contain between 1 and 50 elements, inclusive. 
-Each element of replies will be between 0 and 1,000,000, inclusive. 


EXAMPLES

0)
{ 1, 1, 2, 2 }


Returns: 5

If there are 2 rabbits with a color and 3 rabbits with another color, 
Pochi can get this set of replies. 




1)
{ 0 }


Returns: 1

A poor lonely rabbit. 


2)
{ 2, 2, 44, 2, 2, 2, 444, 2, 2 }


Returns: 499



*/
// END CUT HERE
#line 58 "ColorfulRabbits.cpp"
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define SZ size()
using namespace std;
#define REP(i, n) for(int i=0, _n=(n);(i)<_n;i++)

class ColorfulRabbits {
	public:
	int getMinimum(vector <int> re) {
		map<int, int> m;
		REP(i, re.SZ)
		{
			if(m.find(re[i]+1) == m.end()) m[re[i]+1] = 0;
			m[re[i]+1]++;
		}
		int ans = 0;
		for( map<int, int>::const_iterator p = m.begin(); p!=m.end(); p++ )
		{
			//cout << p->first << ": " << p->second << " " << endl;
			ans += (p->second + p->first - 1) / p->first * p->first;
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 1, 2, 2 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { int Arr0[] = { 0 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { int Arr0[] = { 2, 2, 44, 2, 2, 2, 444, 2, 2 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 499; verify_case(2, Arg1, getMinimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	ColorfulRabbits ___test;

	___test.run_test(-1);

}

// END CUT HERE
