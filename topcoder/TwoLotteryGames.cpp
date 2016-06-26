// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Yesterday, when you were passing by the newsstand near your home, you saw an advertisement for lottery games.  The advertisement said "Choose m different numbers between 1 and n, inclusive.  We will also randomly pick m different numbers between 1 and n, inclusive, and if you have at least k numbers in common with us, you win!". 

You want to know the probability of winning this lottery game. You are given three integers n, m, and k as described above.  Return the probability of winning the game.

DEFINITION
Class:TwoLotteryGames
Method:getHigherChanceGame
Parameters:int, int, int
Returns:double
Method signature:double getHigherChanceGame(int n, int m, int k)


NOTES
-Your return must have relative or absolute error less than 1E-9.


CONSTRAINTS
-n will be between 2 and 8, inclusive.
-m will be between 1 and n-1, inclusive.
-k will be between 1 and m, inclusive.


EXAMPLES

0)
3
2
1

Returns: 1.0

Here you and the organizers will choose 2 numbers among 3. It will be 4 numbers in total, so at least 1 number in your and their sets will repeat for sure.

1)
3
1
1

Returns: 0.3333333333333333

Now you and the organizers will choose 1 number. These numbers will be the same with probability 1/3.

2)
8
2
1

Returns: 0.4642857142857143



3)
8
4
2

Returns: 0.7571428571428571



*/
// END CUT HERE
#line 67 "TwoLotteryGames.cpp"

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



class TwoLotteryGames {
	public:
	double getHigherChanceGame(int n, int m, int k) {
		int base=0, child=0;
		REP(i, 1<<n) {
			REP(ii, 1<<n) {
				int co=0, co2=0, ma=0;
				REP(j, n) {
					if(i&1<<j)co++;
					if(ii&1<<j)co2++;
					if((ii&i)&1<<j) ma++;
				}
				if(co==m && co2==m) {
					base++;
					if(ma>=k) {
						child++;
					}
				}
			}
		}
		//cout<<base<<" "<<child<<endl;
		return (double)child/base;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; double Arg3 = 1.0; verify_case(0, Arg3, getHigherChanceGame(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; double Arg3 = 0.3333333333333333; verify_case(1, Arg3, getHigherChanceGame(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 2; int Arg2 = 1; double Arg3 = 0.4642857142857143; verify_case(2, Arg3, getHigherChanceGame(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 4; int Arg2 = 2; double Arg3 = 0.7571428571428571; verify_case(3, Arg3, getHigherChanceGame(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	TwoLotteryGames ___test;

	___test.run_test(-1);
	//___test.test_case_1();

}

// END CUT HERE
