// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You have N bottles, each with unlimited capacity.  Initially, each bottle contains exactly 1 liter of water.  You want to carry these bottles to another location, but you can only carry K bottles at a time.  You don't want to waste any water and you don't want to make more than one trip, so you decide to redistribute the contents of the bottles until you end up with no more than K non-empty bottles.

You are only allowed to redistribute your water using the following method.  First, pick two bottles that contain an equal amount of water.  Then, pour the entire content of one of those bottles into the other.  Repeat this process as many times as necessary.

Because of this restriction, it may be impossible to end up with no more than K non-empty bottles using only the N bottles that you have initially.  Fortunately, you can also buy more bottles.  Each bottle that you buy will contain exactly 1 liter of water and have unlimited capacity.  For example, consider the case where N is 3 and K is 1.  It's impossible to get from 3 bottles to 1.  If you pour one bottle into another, you end up with one 2 liter bottle and one 1 liter bottle.  At that point, you're stuck.  However, if you then buy another bottle, you can pour that bottle into the 1 liter bottle, and pour the resulting 2 liter bottle into the other 2 liter bottle to end up with just one 4 liter bottle. 

Return the minimum number of additional bottles you must buy in order to achieve your goal.  If it's impossible, return -1 instead.

DEFINITION
Class:PouringWater
Method:getMinBottles
Parameters:int, int
Returns:int
Method signature:int getMinBottles(int N, int K)


CONSTRAINTS
-N will be between 1 and 10^7, inclusive.
-K will be between 1 and 1000, inclusive.


EXAMPLES

0)
3
1

Returns: 1

The example from the problem statement.

1)
13
2

Returns: 3

If you have 13, 14, or 15 bottles, you can't end up with one or two bottles. With 16 bottles, you can end up with one bottle.

2)
1000000
5

Returns: 15808



*/
// END CUT HERE
#line 54 "PouringWater.cpp"

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



class PouringWater {
	public:
	int getMinBottles(int N, int K) {
		int r = 0;
		for(int i=30;i>=0 && K>0;i--) {
			if((N>>i)&1) {
				N-=1<<i;
				K--;
				r=1<<i;
			}
		}
		if(N>0) return r-N;
		return 0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, getMinBottles(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 13; int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, getMinBottles(Arg0, Arg1)); }
	//void test_case_2() { int Arg0 = 1000000; int Arg1 = 5; int Arg2 = 15808; verify_case(2, Arg2, getMinBottles(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000000; int Arg1 = 1000; int Arg2 = 0; verify_case(2, Arg2, getMinBottles(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	PouringWater ___test;

	___test.run_test(-1);

}

// END CUT HERE
