// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You and Mr. Dengklek are playing a game called Prime-Composite Game.

Initially, there is a pile consisting of N stones. You and Mr. Dengklek take alternating turns, starting from you. In your turn, you must remove at least 1 and at most K stones from the pile. Additionally, after your move the number of stones in the pile must be a prime number. In Mr. Dengklek's turn, he must remove at least 1 and at most K stones from the pile. Additionally, after his move the number of stones in the pile must be a composite number. The first player who cannot make a valid move loses the game.

You and Mr. Dengklek both play the game optimally. Optimal play is defined as follows: Clearly, one of the players has a strategy that will guarantee him winning the game. If at any turn this player has multiple moves to choose from, he always chooses the one that minimizes the number of turns the game will take. The other player always chooses the move that will maximize the number of turns the game will take. Each player is following these rules and each player knows that the other player is also following these rules.

You are given the ints N and K. Determine the outcome of the game. Let X be the number of turns in the game. If you win, return X, otherwise return -X.

DEFINITION
Class:PrimeCompositeGame
Method:theOutcome
Parameters:int, int
Returns:int
Method signature:int theOutcome(int N, int K)


NOTES
-A prime number is a positive number that has exactly two distinct divisors. A composite number is a positive number that has more than two distinct divisors. By definition, 1 is neither prime nor composite.


CONSTRAINTS
-N will be between 1 and 474,747, inclusive.
-K will be between 1 and N, inclusive.


EXAMPLES

0)
3
2

Returns: 1

Take a single stone in your first turn, leaving two stones. This ends the game, as Mr. Dengklek now has no valid move.

1)
58
1

Returns: 0

The game is already over and you lost, as you have no valid move to make. (The only option is to take a single stone, but 57 is not a prime number.)

2)
30
3

Returns: -2

The game will proceed as follows:

You will take 1 stone, leaving 29 stones.
Mr. Dengklek will take 1 or 2 stones, leaving 28 or 27 stones. In either case, you cannot leave a prime number of stones in your next turn, therefore, you will surely lose.


3)
6
3

Returns: 1

Taking 1 stone in your first turn would guarantee you to win after your next turn. However, it is better to take 3 stones and win right now.

4)
526
58

Returns: 19



*/
// END CUT HERE
#line 78 "PrimeCompositeGame.cpp"

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



class PrimeCompositeGame {
	public:
	int theOutcome(int N, int K) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; verify_case(0, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 58; int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 3; int Arg2 = -2; verify_case(2, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 1; verify_case(3, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 526; int Arg1 = 58; int Arg2 = 19; verify_case(4, Arg2, theOutcome(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	PrimeCompositeGame ___test;

	___test.run_test(-1);

}

// END CUT HERE
