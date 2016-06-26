// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Nim is a game in which two players take turns removing stones from heaps.  On each turn, a player must choose a single heap and remove one or more stones from that heap.  The player who takes the last stone wins.

Alice and Bob are bored with playing Nim over and over again, so they've decided to create a new variation called Ordered Nim.  Ordered Nim differs from regular Nim in the following way.  The heaps are numbered 0 through n-1 (where n is the number of heaps), and a player can only remove stones from a heap if all the lower-numbered heaps are empty.

You are given a vector <int> layout, where the i-th element (0-indexed) is the number of stones in heap i at the beginning of the game.  Alice will take the first turn.  Determine who will win the game, assuming both players play optimally.  Return "Alice" if Alice will win, or "Bob" if Bob will win (all quotes for clarity).

DEFINITION
Class:OrderedNim
Method:winner
Parameters:vector <int>
Returns:string
Method signature:string winner(vector <int> layout)


CONSTRAINTS
-layout will contain between 1 and 50 elements, inclusive.
-Each element of layout will be between 1 and 1000000000, inclusive.


EXAMPLES

0)
{5}

Returns: "Alice"

Alice takes all 5 stones and wins.

1)
{1,2}

Returns: "Bob"

According to the rules of the game, Alice is not allowed to take stones from heap 1 because heap 0 is not empty.  Her only option is to take the one stone from heap 0.  Heap 0 will then be empty, so Bob can take both stones from heap 1 to win the game.

2)
{2,1}

Returns: "Alice"



3)
{10,9,8,7,6,5,4,3,2,1}

Returns: "Alice"



4)
{1,1,1,1}

Returns: "Bob"

*/
// END CUT HERE
#line 61 "OrderedNim.cpp"

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


int f(vector <int>& lay, int be) {
	if(be==lay.size()-1) return 1;
	if(lay[be]>=2) return 1;
	return 1-f(lay, be+1);
}

class OrderedNim {
	public:
	string winner(vector <int> layout) {
		return f(layout, 0) ? "Alice" : "Bob";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Alice"; verify_case(0, Arg1, winner(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bob"; verify_case(1, Arg1, winner(Arg0)); }
	void test_case_2() { int Arr0[] = {2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Alice"; verify_case(2, Arg1, winner(Arg0)); }
	void test_case_3() { int Arr0[] = {10,9,8,7,6,5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Alice"; verify_case(3, Arg1, winner(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bob"; verify_case(4, Arg1, winner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	OrderedNim ___test;

	___test.run_test(-1);

}

// END CUT HERE
