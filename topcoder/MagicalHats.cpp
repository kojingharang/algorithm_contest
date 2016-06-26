// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A magician has challenged you to a game of wits. First he shows you some coins. Different coins may have different values. Next he takes some hats and hides all the coins inside the hats, in such a way that no two coins are hidden in the same hat. Finally, he places each of the hats with their respective coin onto some cell of a checkerboard. Now he has given you some guesses. In each guess you may ask the magician to reveal the contents of one of the hats. 

After you make your guess, but before he reveals the contents of a hat, the magician may magically reshuffle all coins that are still hidden. That is, he can use a magic spell to redistribute the coins among all hats that still were not revealed, including the hat you just selected. After reshuffling, each hat must again contain at most one coin. 

After you make a guess and the magician reshuffles the hidden coins, the hat you selected is flipped upside down (and remains in this state until the end of the game). If it contained a coin, the coin remains in the hat, but it is now visible and the magician cannot move it in the future. If it did not contain a coin, the magician can't ever put a coin into this hat anymore. 

Furthermore, the magician has given you one more set of guarantees.
At any moment in the game, the following constraints will all be satisfied:

For each row, the number of hats in the row plus the number of coins in the row will be an even number.
For each column, the number of hats in the column plus the number of coins in the column will be an even number.


You are given a vector <string> board representing the checkerboard. The j-th character of the i-th element of board is 'H' when there is a hat at row i column j of the checkerboard and '.' otherwise. You are also given an vector <int> coins representing the different coins that are hidden under hats. You are also given an int numGuesses representing the number of guesses that you get.

At the end of the game you get to keep all the coins that were revealed while playing. Your goal is to maximize the total value of the coins you get. The magician's goal is to minimize the total value of the coins you get. If it is not possible to hide all the coins in coins under the hats on the given board while meeting all the constraints above, return -1. Otherwise, return the total value of coins you'll get, assuming both you and the magician play optimally.

DEFINITION
Class:MagicalHats
Method:findMaximumReward
Parameters:vector <string>, vector <int>, int
Returns:int
Method signature:int findMaximumReward(vector <string> board, vector <int> coins, int numGuesses)


CONSTRAINTS
-board will contain between 1 and 13 elements, inclusive.
-Each element of board will contain between 1 and 13 characters, inclusive.
-Each element of board will contain the same number of characters.
-Each character of each element of board will be either 'H' or '.'.
-board will contain at most 13 occurrences of the character 'H'.
-coins will contains between 1 and 13 elements, inclusive.
-Each element of coins will be between 1 and 10,000, inclusive.
-There will always be at least as many 'H' characters in board as elements in coins.
-numGuesses will be between 1 and the number of 'H' characters in board, inclusive.


EXAMPLES

0)
{"H"}
{1}
1

Returns: 1

One guess for one hat. The reward is just the contents of the hat.

1)
{"HHH",
 "H.H",
 "HH."}
{9}
1

Returns: 9

The only position the 9 coin can possibly be in is the top left corner.

2)
{"HH",
 "HH"}
{1,2,3,4}
3

Returns: 6

The magician manages to always give you the worst possible reward regardless of how you guess.

3)
{"HHH",
 "HHH",
 "H.H"}
{13,13,13,13}
2

Returns: 13



4)
{"HHH",
 "HHH",
 "H.H"}
{13,13,13,13}
3

Returns: 26



5)
{"H.H.",
 ".H.H",
 "H.H."}
{17}
6

Returns: -1



6)
{"HHH",
 "H.H",
 "HHH",
 "H.H",
 "HHH"}
{33,337,1007,2403,5601,6003,9999}
5

Returns: 1377



7)
{".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".....H.H.....",
 "......H......",
 ".....H.H.....",
 ".............",
 ".............",
 ".............",
 "............."}
{22}
3

Returns: 22



*/
// END CUT HERE
#line 143 "MagicalHats.cpp"

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
#include <cfloat>
#include <cmath>
#include <ctime>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

VI his;
VI coleo;
int f(VVI& w, int idx) {
	if(idx>=w.size()) {
		
		return 0;
	}
	REP(i, w[idx].size()) {
		his[idx] = w[idx][i];
		f(w, idx+1);
	}
	return 0;
}


class MagicalHats {
	public:
	int findMaximumReward(vector <string> B, vector <int> C, int NG) {
		int W=B[0].size();
		int H=B.size();
		VVI w(H, VI());
		his = VI(H);
		coleo = VI(H);
		REP(y, H) {
			int cnt = 0;
			REP(x, W) {
				cnt += B[y][x]=='H';
				coleo[y] = (coleo[y]+(B[y][x]=='H'))&1;
			}
			for(int i=cnt%2; i<=cnt; i+=2) w[y].PB(i);
		}
		cout<<coleo<<endl;
		cout<<w<<endl;
		f(w, 0);
		return 0;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//mplate<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// os << "{ ";
// for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
// os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, MagicalHats().findMaximumReward(board, coins, numGuesses));}
int main(){

CASE(0)
	string board_[] = {"H"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int coins_[] = {1};
	  vector <int> coins(coins_, coins_+sizeof(coins_)/sizeof(*coins_)); 
	int numGuesses = 1; 
	int _ = 1; 
END
CASE(1)
	string board_[] = {"HHH",
 "H.H",
 "HH."};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int coins_[] = {9};
	  vector <int> coins(coins_, coins_+sizeof(coins_)/sizeof(*coins_)); 
	int numGuesses = 1; 
	int _ = 9; 
END
CASE(2)
	string board_[] = {"HH",
 "HH"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int coins_[] = {1,2,3,4};
	  vector <int> coins(coins_, coins_+sizeof(coins_)/sizeof(*coins_)); 
	int numGuesses = 3; 
	int _ = 6; 
END
CASE(3)
	string board_[] = {"HHH",
 "HHH",
 "H.H"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int coins_[] = {13,13,13,13};
	  vector <int> coins(coins_, coins_+sizeof(coins_)/sizeof(*coins_)); 
	int numGuesses = 2; 
	int _ = 13; 
END
CASE(4)
	string board_[] = {"HHH",
 "HHH",
 "H.H"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int coins_[] = {13,13,13,13};
	  vector <int> coins(coins_, coins_+sizeof(coins_)/sizeof(*coins_)); 
	int numGuesses = 3; 
	int _ = 26; 
END
CASE(5)
	string board_[] = {"H.H.",
 ".H.H",
 "H.H."};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int coins_[] = {17};
	  vector <int> coins(coins_, coins_+sizeof(coins_)/sizeof(*coins_)); 
	int numGuesses = 6; 
	int _ = -1; 
END
CASE(6)
	string board_[] = {"HHH",
 "H.H",
 "HHH",
 "H.H",
 "HHH"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int coins_[] = {33,337,1007,2403,5601,6003,9999};
	  vector <int> coins(coins_, coins_+sizeof(coins_)/sizeof(*coins_)); 
	int numGuesses = 5; 
	int _ = 1377; 
END
CASE(7)
	string board_[] = {".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".....H.H.....",
 "......H......",
 ".....H.H.....",
 ".............",
 ".............",
 ".............",
 "............."};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int coins_[] = {22};
	  vector <int> coins(coins_, coins_+sizeof(coins_)/sizeof(*coins_)); 
	int numGuesses = 3; 
	int _ = 22; 
END

}
// END CUT HERE
