// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
You have a deck that contains R red and B black cards.



You are playing the following game: You shuffle the deck, and then begin dealing the cards one by one.
For each red card you flip you get a dollar, and for each black card you flip you have to pay a dollar.
At any moment (including the beginning of the game) you are allowed to stop and keep the money you have.



Write a method that will take the ints R and B, and return the expected amount you will 
gain if you play this game optimally.


DEFINITION
Class:RedIsGood
Method:getProfit
Parameters:int, int
Returns:double
Method signature:double getProfit(int R, int B)


NOTES
-During the game, your balance may be negative.
-We assume that each permutation of the cards in the deck is equally likely.
-Your return value must have a relative or absolute error less than 1e-9.


CONSTRAINTS
-R will be between 0 and 5,000, inclusive.
-B will be between 0 and 5,000, inclusive.


EXAMPLES

0)
0
7

Returns: 0.0

If all cards are black, the best strategy is not to play at all.

1)
4
0

Returns: 4.0

If all cards are red, the best strategy is to flip them all.

2)
5
1

Returns: 4.166666666666667

The strategy "flip all cards" is guaranteed to earn $4. However, we can do better. If we flipped 5 cards and all of them are red, it makes no sense to flip the final, black card. Therefore if we play optimally the expected gain is more than $4.

3)
2
2

Returns: 0.6666666666666666

An optimal strategy for this case: Flip the first card. If it is red, stop. If it is black, flip the second and the third card. If both are red, stop, otherwise flip the fourth card.

4)
12
4

Returns: 8.324175824175823

This is a game I would surely like to play often.

5)
11
12

Returns: 1.075642825339958

Surprisingly, sometimes there is a good strategy even if the number of red cards is smaller than the number of black cards.

*/
// END CUT HERE
#line 91 "RedIsGood.cpp"

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




class RedIsGood {
	public:
	double getProfit(int R, int B) {
		vector<long double> dp(R+1);
		vector<long double> ndp(R+1);
		REP(r, R+1) dp[r]=r;
		for(int b=1;b<=B;b++) {
			ndp[0]=0.0;
			for(int r=1;r<=R;r++) {
				long double v = (r*(1+ndp[r-1]) + b*(-1+dp[r]))/(r+b);
				ndp[r] = max(v, 0.0l);
			}
			//cout<<ndp<<endl;
			dp=ndp;
		}
		return dp[R];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 7; double Arg2 = 0.0; verify_case(0, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 0; double Arg2 = 4.0; verify_case(1, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 1; double Arg2 = 4.166666666666667; verify_case(2, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 0.6666666666666666; verify_case(3, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 12; int Arg1 = 4; double Arg2 = 8.324175824175823; verify_case(4, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 11; int Arg1 = 12; double Arg2 = 1.075642825339958; verify_case(5, Arg2, getProfit(Arg0, Arg1)); }
	//void test_case_5() { int Arg0 = 5000; int Arg1 = 5000; double Arg2 = 1.075642825339958; verify_case(5, Arg2, getProfit(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	RedIsGood ___test;

	___test.run_test(-1);

}

// END CUT HERE
