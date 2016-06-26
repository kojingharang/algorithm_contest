// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Alice is playing a game with her old friend, Bob.

There are n circles on a paper. The center of the i-th circle is (x[i], y[i]), and the radius is r[i].
No two different circles share a common point on their boundary.
However, it is allowed for circles to be located entirely within other circles.
In the game, the players take alternating turns.
Alice starts.
In each move, the current player must:

Choose a circle such that there is no red point strictly inside the circle.
Pick one point that is strictly inside the chosen circle and color it red.

If a player can't do such a move, he/she loses the game.

You are given the vector <int>s x, y, and r that describe a set of circles with the above property.
Return "Alice" (quotes for clarity) if Alice has a winning strategy for the given set of circles.
Otherwise, return "Bob".


DEFINITION
Class:CirclesGame
Method:whoCanWin
Parameters:vector <int>, vector <int>, vector <int>
Returns:string
Method signature:string whoCanWin(vector <int> x, vector <int> y, vector <int> r)


NOTES
-Points located on the boundary of a circle are not considered to be strictly inside that circle.


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-x, y, and r will each contain the same number of elements.
-Each element in x will be between -10,000 and 10,000, inclusive.
-Each element in y will be between -10,000 and 10,000, inclusive.
-Each element in r will be between 1 and 10,000, inclusive.
-No two circles intersect. That is, the boundaries of the given circles are pairwise disjoint.


EXAMPLES

0)
{0}
{0}
{1}

Returns: "Alice"

This test case has just one circle. Alice draws a red point anywhere inside the circle and Bob has no valid move.

1)
{0, 3}
{0, 0}
{1, 1}

Returns: "Bob"

Two separate circles. Alice draws a red point in one of them, Bob draws a red point in another one, then Alice has no valid moves.

2)
{0, 0, 5}
{0, 0, 0}
{1, 2, 1}

Returns: "Alice"

In her first move, Alice should draw a point within the circle 1, but so that it's not within the circle 0. (Both indices are 0-based.)

3)
{0, 0, 0, 10, 10, 20}
{0, 0, 0, 0, 0, 0}
{1, 2, 3, 1, 2, 1}

Returns: "Bob"



4)
{10,20,30,40,50,60,70,80}
{8,7,6,5,4,3,2,1}
{2,2,2,2,2,2,2,2}

Returns: "Bob"



5)
{0, 3, 6, 9, 12, -4747, -4777}
{-5858, -5858, -5858, -5858, -5858, 777, 777}
{58, 1, 1, 1, 1, 44, 8}

Returns: "Bob"



6)
{5202, 5699, -7433, 5068, -9483, -684, -6593, 5108, -7813, 6823, 3267, -8222, -8547, 2878, 2413, 8557, 5149, 5073, -8638, -6108, 8097}
{8728, -7407, 4338, -8414, 7652, -3705, -984, 5976, -9180, -9119, 9301, 2398, 7915, 6205, 7665, 717, -9884, 11, -8579, -6903, -746}
{4196, 9303, 7152, 5875, 2943, 788, 502, 416, 1958, 3174, 182, 1256, 1147, 444, 979, 65, 1040, 1233, 438, 175, 1140}

Returns: "Alice"

*/
// END CUT HERE
#line 110 "CirclesGame.cpp"

#include <vector>
#include <map>
#include <set>
#include <stack>
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
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class CirclesGame {
	public:
	string whoCanWin(vector <int> x, vector <int> y, vector <int> r) {
		
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
#define END	 verify_case(_, CirclesGame().whoCanWin(x, y, r));}
int main(){

CASE(0)
	int x_[] = {0};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int r_[] = {1};
	  vector <int> r(r_, r_+sizeof(r_)/sizeof(*r_)); 
	string _ = "Alice"; 
END
CASE(1)
	int x_[] = {0, 3};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0, 0};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int r_[] = {1, 1};
	  vector <int> r(r_, r_+sizeof(r_)/sizeof(*r_)); 
	string _ = "Bob"; 
END
CASE(2)
	int x_[] = {0, 0, 5};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0, 0, 0};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int r_[] = {1, 2, 1};
	  vector <int> r(r_, r_+sizeof(r_)/sizeof(*r_)); 
	string _ = "Alice"; 
END
CASE(3)
	int x_[] = {0, 0, 0, 10, 10, 20};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0, 0, 0, 0, 0, 0};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int r_[] = {1, 2, 3, 1, 2, 1};
	  vector <int> r(r_, r_+sizeof(r_)/sizeof(*r_)); 
	string _ = "Bob"; 
END
CASE(4)
	int x_[] = {10,20,30,40,50,60,70,80};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {8,7,6,5,4,3,2,1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int r_[] = {2,2,2,2,2,2,2,2};
	  vector <int> r(r_, r_+sizeof(r_)/sizeof(*r_)); 
	string _ = "Bob"; 
END
CASE(5)
	int x_[] = {0, 3, 6, 9, 12, -4747, -4777};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-5858, -5858, -5858, -5858, -5858, 777, 777};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int r_[] = {58, 1, 1, 1, 1, 44, 8};
	  vector <int> r(r_, r_+sizeof(r_)/sizeof(*r_)); 
	string _ = "Bob"; 
END
CASE(6)
	int x_[] = {5202, 5699, -7433, 5068, -9483, -684, -6593, 5108, -7813, 6823, 3267, -8222, -8547, 2878, 2413, 8557, 5149, 5073, -8638, -6108, 8097};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {8728, -7407, 4338, -8414, 7652, -3705, -984, 5976, -9180, -9119, 9301, 2398, 7915, 6205, 7665, 717, -9884, 11, -8579, -6903, -746};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int r_[] = {4196, 9303, 7152, 5875, 2943, 788, 502, 416, 1958, 3174, 182, 1256, 1147, 444, 979, 65, 1040, 1233, 438, 175, 1140};
	  vector <int> r(r_, r_+sizeof(r_)/sizeof(*r_)); 
	string _ = "Alice"; 
END

}
// END CUT HERE
