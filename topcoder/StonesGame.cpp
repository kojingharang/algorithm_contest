// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Romeo and his friend Strangelet are playing a game. There are N stones in a row, all of which are black except for the M-th one, which is white (all positions in this problem are 1-based). The players alternate turns, and Romeo plays first. On each turn, a player must choose exactly K consecutive stones, one of which must be white, and reverse their order. The winner is the first player who puts the white stone in the L-th position.

Return "Romeo" if Romeo can win regardless of how Strangelet plays, and return "Strangelet" if Strangelet can win regardless of Romeo's strategy.  Otherwise, return "Draw" since neither player can win if both players play optimally.  All quotes are for clarity only.

DEFINITION
Class:StonesGame
Method:winner
Parameters:int, int, int, int
Returns:string
Method signature:string winner(int N, int M, int K, int L)


CONSTRAINTS
-N will be between 2 and 1,000,000,  inclusive.
-M, K and L will each be between 1 and N, inclusive.
-M and L will be different.


EXAMPLES

0)
3
1
1
2

Returns: "Draw"

There are three stones and the stone in position 1 is white.  To win the game, a player must put the white stone in position 2.  However, since K is 1, each player can only choose a single stone to reverse, so it is impossible to move the white stone from its original position.  Therefore, neither player can win.

1)
5
1
2
2

Returns: "Romeo"

Romeo can win on his first move by reversing the order of the first two stones.

2)
5
5
2
3

Returns: "Strangelet"

Romeo's only possible move is to reverse the last two stones.  This puts the white stone in position 4.  Strangelet can then reverse the third and fourth stones, putting the white stone in position 3 and winning the game.

3)
5
5
2
2

Returns: "Draw"

This is similar to the previous example, but here, the white stone must be moved to position 2.  As in the previous example, Romeo's first move will put the white stone in position 4.  This time, Strangelet will then move it back to position 5 because otherwise, Romeo would move it to position 2 and win.  This sequence of moves will repeat infinitely and neither player will win.

4)
1000000
804588
705444
292263

Returns: "Romeo"

5)
1000000
100000
500000
600000

Returns: "Strangelet"



*/
// END CUT HERE
#line 85 "StonesGame.cpp"
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


class StonesGame {
	public:
	string winner(int N, int M, int K, int L) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; string Arg4 = "Draw"; verify_case(0, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; string Arg4 = "Romeo"; verify_case(1, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2; int Arg3 = 3; string Arg4 = "Strangelet"; verify_case(2, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2; int Arg3 = 2; string Arg4 = "Draw"; verify_case(3, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 804588; int Arg2 = 705444; int Arg3 = 292263; string Arg4 = "Romeo"; verify_case(4, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1000000; int Arg1 = 100000; int Arg2 = 500000; int Arg3 = 600000; string Arg4 = "Strangelet"; verify_case(5, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	StonesGame ___test;

	___test.run_test(-1);

}

// END CUT HERE
