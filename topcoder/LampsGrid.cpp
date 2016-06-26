// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Jack has bought a rectangular table containing a grid of lamps.  Each lamp is initially either "on" or "off".  There is a switch underneath each column, and when the switch is flipped, all the lamps in that column reverse their states ("on" lamps become "off" and vice versa).



A row in the grid is considered lit if all the lamps in that row are "on".  Jack must make exactly K flips.  The K flips do not necessarily have to be performed on K distinct switches.  His goal is to have as many lit rows as possible after making those flips.


You are given a vector <string> initial, where the j-th character of the i-th element is '1' (one) if the lamp in row i, column j is initially "on", and '0' (zero) otherwise.  Return the maximal number of rows that can be lit after performing exactly K flips.


DEFINITION
Class:LampsGrid
Method:mostLit
Parameters:vector <string>, int
Returns:int
Method signature:int mostLit(vector <string> initial, int K)


CONSTRAINTS
-initial will contain between 1 and 50 elements, inclusive.
-Each element of initial will contain between 1 and 50 characters, inclusive.
-Each element of initial will contain the same number of characters.
-Each element of initial will contain only the digits '0' and '1'.
-K will be between 0 and 1000, inclusive.


EXAMPLES

0)
{"01",
 "10",
 "10"}
1

Returns: 2

Here, Jack must flip exactly one switch.  If he flips the switch for the second column, the bottom two rows become lit.

1)
{"101010"}
2

Returns: 0



2)
{"00", "11"}
999

Returns: 0

No row can be lit after exactly 999 flips.


3)
{"0", "1", "0", "1", "0"}

1000

Returns: 2



4)
{"001", "101", "001", "000", "111", "001", "101", "111", "110", "000", "111", "010", "110", "001"}
6

Returns: 4



5)
{"01", "10", "01", "01", "10"}
1

Returns: 3



*/
// END CUT HERE
#line 87 "LampsGrid.cpp"

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



class LampsGrid {
	public:
	int mostLit(vector <string> ini, int K) {
		int ans=0;
		REP(i, ini.size()) {
			int lans=0;
			int flip=0;
			REP(j, ini.size()) if(ini[i]==ini[j]) lans++;
			REP(j, ini[i].size()) if(ini[i][j]=='0') flip++;
			if(flip==K || flip<K&&(K-flip)%2==0) ans=max(ans, lans);
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"01",
 "10",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, mostLit(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"101010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(1, Arg2, mostLit(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"00", "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999; int Arg2 = 0; verify_case(2, Arg2, mostLit(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"0", "1", "0", "1", "0"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 2; verify_case(3, Arg2, mostLit(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"001", "101", "001", "000", "111", "001", "101", "111", "110", "000", "111", "010", "110", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 4; verify_case(4, Arg2, mostLit(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"01", "10", "01", "01", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; verify_case(5, Arg2, mostLit(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	LampsGrid ___test;

	___test.run_test(-1);

}

// END CUT HERE
