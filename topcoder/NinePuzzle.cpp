// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel invented a game called Nine Puzzle.  The game is played on a board which is in the form of a regular triangle with side length 4.  There are 10 cells on the board, each in the form of a regular triangle with side length 1.  The cells are numbered 0 to 9 as shown in the picture below:



Nine of the cells on the board contain a triangular piece.  Each piece is painted red, green, blue or yellow.  The remaining tenth cell is empty.  The goal of the game is to arrange the cells to match a specified goal pattern.  To do this, the player can perform the following move any number of times: Choose a piece which is adjacent to an empty cell, and move the piece into that empty cell.  Two cells are considered adjacent if the distance between their centers is exactly 1.  An example of a valid move is shown in the following picture:



Ciel has painted the triangular pieces to form the starting pattern for the puzzle.  She has also chosen the goal pattern.  However, she has chosen both these patterns arbitrarily, so it's possible that the puzzle might not be solvable (i.e., it may be impossible to achieve the goal pattern from the given starting pattern using a sequence of valid moves).  If this is the case, she would like to repaint the minimum possible number of pieces in the starting pattern to make the puzzle solvable.

You are given two strings init and goal.  The i-th (0-indexed) character of init describes the content of the i-th cell in the starting pattern.  The '*' character denotes an empty cell.  'R', 'G', 'B' and 'Y' denote pieces which are colored red, green, blue and yellow, respectively.  The goal pattern is described in the string goal in the same format.

Return the minimum number of pieces which must be repainted in the starting pattern to make the puzzle solvable.  If the puzzle is already solvable without repainting, return 0.


DEFINITION
Class:NinePuzzle
Method:getMinimumCost
Parameters:string, string
Returns:int
Method signature:int getMinimumCost(string init, string goal)


CONSTRAINTS
-init and goal will each contain exactly 10 characters.
-Each character of init and goal will be one of 'R', 'G', 'B', 'Y' or '*'.
-init and goal will each contain exactly one '*' character.


EXAMPLES

0)
"BG*YRGRRYR" 
"BGGY*YRRRR" 

Returns: 0

No repainting is required because Ciel can achieve the goal pattern from the starting pattern in 3 moves:



1)
"GBBB*BGBBG" 
"RYYY*YRYYR"

Returns: 9

Ciel incautiously chose the starting pattern and the goal pattern, so unfortunately, she must repaint all the pieces.

2)
"RRBR*BRBBB" 
"BBRB*RBRRR" 

Returns: 1



*/
// END CUT HERE
#line 64 "NinePuzzle.cpp"
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


class NinePuzzle {
	public:
	int getMinimumCost(string init, string goal) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BG*YRGRRYR" ; string Arg1 = "BGGY*YRRRR" ; int Arg2 = 0; verify_case(0, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "GBBB*BGBBG" ; string Arg1 = "RYYY*YRYYR"; int Arg2 = 9; verify_case(1, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "RRBR*BRBBB" ; string Arg1 = "BBRB*RBRRR" ; int Arg2 = 1; verify_case(2, Arg2, getMinimumCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	NinePuzzle ___test;

	___test.run_test(-1);

}

// END CUT HERE
