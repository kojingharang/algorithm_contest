// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Fox Ciel is playing a board game with her friend Squirrel Liss.
The game is played on an infinite strip of paper.
The strip of paper is divided into consecutive cells.
Each cell has an integer coordinate.
Formally, for each integer i, the left neighbor of cell i is cell (i-1) and the right neighbor of cell i is cell (i+1).



Each of the players has a single token called the fencer.
At the beginning of the game, Ciel's fencer is in cell 0 and Liss's fencer is in cell d.
Each of the fencers has two limits: its maximum move length and its hitting range.
For Ciel's fencer the maximum move length is mov1 and the hitting range is rng1.
Similarly, for Liss's fencer we have the parameters mov2 and rng2.
Note that the parameters of Liss's fencer may differ from the ones of Ciel's fencer.



The players take alternating turns.
Ciel goes first.
In each turn the current player starts by moving her fencer.
The distance between the original cell and the destination cell must be at most equal to the fencer's maximum move length.
(It is also allowed to leave the fencer in the same cell.)
Then, the current player checks whether the other fencer lies within the hitting range - that is, whether the current distance between the fencers is at most equal to the current fencer's hitting range.
If that is the case, the game ends and the current player wins.



You are given the ints mov1, mov2, rng1, rng2, and d.
Return "Ciel" (quotes for clarity) if Fox Ciel has a winning strategy, "Liss" if Squirrel Liss has a winning strategy, and "Draw" otherwise.

DEFINITION
Class:FoxAndFencing
Method:WhoCanWin
Parameters:int, int, int, int, int
Returns:string
Method signature:string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d)


CONSTRAINTS
-mov1 will be between 1 and 100,000,000, inclusive.
-mov2 will be between 1 and 100,000,000, inclusive.
-rng1 will be between 1 and 100,000,000, inclusive.
-rng2 will be between 1 and 100,000,000, inclusive.
-d will be between 1 and 100,000,000, inclusive.


EXAMPLES

0)
1
58
1
58
2

Returns: "Ciel"

The attributes of Ciel's fencer are much smaller than the attributes of Liss's fencer.
Luckily for Ciel, she can win the game in her first turn:
she should move her fencer to cell 1 and from there she can hit the other fencer.

1)
2
1
1
100
50

Returns: "Liss"

Ciel cannot score a hit in the first turn.
After Ciel's turn, her fencer will be on one of the cells {-2,-1,0,1,2}.
Regardless of its precise location, Liss can always move her fencer one cell to the left and then hit Ciel.

2)
2
1
1
100
150

Returns: "Draw"

Clearly, Ciel has no chance of winning this game.
However, this time the initial distance d is big enough for Ciel to escape.

3)
100
100
100
100
100000000

Returns: "Draw"



4)
100
1
100
1
100000000

Returns: "Ciel"



5)
100
1
100
250
100000000

Returns: "Draw"



6)
100
1
100
150
100000000

Returns: "Ciel"



7)
100
50
100
1
100000000

Returns: "Ciel"



8)
100
150
100
1
100000000

Returns: "Draw"



******************************/
// END CUT HERE
#line 159 "FoxAndFencing.cpp"
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

class FoxAndFencing {
	public:
	string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d) {
		if(d <= mov1+rng1) return "Ciel";
		if(d+mov1 <= mov2+rng2) return "Liss";
		int cw = mov1>mov2 && mov1+rng1 >= 1+2*mov2+rng2;
		int lw = mov2>mov1 && mov2+rng2 >= 1+2*mov1+rng1;
		if(cw) return "Ciel";
		if(lw) return "Liss";
		return "Draw";
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
void verify_case(const string& Expected, const string& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, FoxAndFencing().WhoCanWin(mov1, mov2, rng1, rng2, d));}
int main(){

CASE(0)
	int mov1 = 1; 
	int mov2 = 58; 
	int rng1 = 1; 
	int rng2 = 58; 
	int d = 2; 
	string _ = "Ciel"; 
END
CASE(1)
	int mov1 = 2; 
	int mov2 = 1; 
	int rng1 = 1; 
	int rng2 = 100; 
	int d = 50; 
	string _ = "Liss"; 
END
CASE(2)
	int mov1 = 2; 
	int mov2 = 1; 
	int rng1 = 1; 
	int rng2 = 100; 
	int d = 150; 
	string _ = "Draw"; 
END
CASE(3)
	int mov1 = 100; 
	int mov2 = 100; 
	int rng1 = 100; 
	int rng2 = 100; 
	int d = 100000000; 
	string _ = "Draw"; 
END
CASE(4)
	int mov1 = 100; 
	int mov2 = 1; 
	int rng1 = 100; 
	int rng2 = 1; 
	int d = 100000000; 
	string _ = "Ciel"; 
END
CASE(5)
	int mov1 = 100; 
	int mov2 = 1; 
	int rng1 = 100; 
	int rng2 = 250; 
	int d = 100000000; 
	string _ = "Draw"; 
END
CASE(6)
	int mov1 = 100; 
	int mov2 = 1; 
	int rng1 = 100; 
	int rng2 = 150; 
	int d = 100000000; 
	string _ = "Ciel"; 
END
CASE(7)
	int mov1 = 100; 
	int mov2 = 50; 
	int rng1 = 100; 
	int rng2 = 1; 
	int d = 100000000; 
	string _ = "Ciel"; 
END
CASE(8)
	int mov1 = 100; 
	int mov2 = 150; 
	int rng1 = 100; 
	int rng2 = 1; 
	int d = 100000000; 
	string _ = "Draw"; 
END

}
// END CUT HERE
