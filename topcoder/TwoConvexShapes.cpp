// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A platypus has been given the mission to paint the cells on a grid either black or white according to the following two conditions:

For each color, all cells of that color must be connected.
Formally, a pair of cells of color X is connected if there is a path of adjacent cells of color X between them.
(Two cells are adjacent if they share a common edge.)
We require that for each color, each pair of cells of that color must be connected.
All the cells of each color must form a convex shape. 
A group of cells of a given color is convex if in each row and each column the cells of that color form a connected segment (possibly taking the whole row or column).
In other words, whenever two cells of the same color share the same row or the same column, all cells between them must also have that particular color.

The platypus is also allowed to paint the grid completely white or black.

The platypus may have already painted some of the cells. The current state of the grid is given as a vector <string> grid. The i-th character of the j-th element of grid that represents the cell at row j, column i is 'W' if it has been painted white, 'B' if it has been painted black, and '?' if it does not have a color yet. Let X be the number of different ways how to color the rest of the grid according to the above conditions. Return the value X modulo 1000000007 (10^9 + 7). Two ways to color a grid are different if the color of at least one cell differs.



DEFINITION
Class:TwoConvexShapes
Method:countWays
Parameters:vector <string>
Returns:int
Method signature:int countWays(vector <string> grid)


CONSTRAINTS
-grid will contain between 1 and 50 elements, inclusive.
-Element 0 of grid will contain between 1 and 50 characters, inclusive.
-The remaining elements of grid will contain the same number of characters as element 0.
-Each character in each element of grid will be one of 'B', 'W', and '?' (quotes for clarity).


EXAMPLES

0)
{"??",
 "??"}

Returns: 14

Of all the 16 different ways to color the grid, only the following 2 are not valid.

BW WB
WB BW

This is because cells of the same color are not connected.

1)
{"B?",
 "??"}

Returns: 7

The following seven ways to color the grid are correct:

BB BW BB BW BB BB BW
BB BW WW WW WB BW BB


2)
{"WWB",
 "WWW",
 "WWW",
 "WWW"}

Returns: 1

All colors have already been picked. The only possible coloring is already valid.

3)
{"BBBBBB",
 "WWBBBB",
 "WBBBBB"}

Returns: 0

This coloring of the grid is not valid, the black cells do not form a convex shape.

4)
{"?BB?",
 "BBBB",
 "?BB?"}

Returns: 5



5)
{"?WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "B?WWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BB?WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBB?WWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBB?WWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBB?WWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBB?WWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBB?WWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBB?WWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBB?WWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBB?WWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBB?WWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBB?WWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBB?WWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBB?WWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBB?WWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBB?WWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBB?WWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBB?WWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBB?WWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBB?WWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBB?WWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBB?WWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBB?WWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBB?WWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBB?WWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBB?WWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBB?WWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBB?WW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB?W"}

Returns: 73741817

Each of the 2^30 ways to color the remaining cells in the grid is valid.

*/
// END CUT HERE
#line 129 "TwoConvexShapes.cpp"

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
#include <cassert>
#include <cctype>
#include <iomanip>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VS vector<string>
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define VVVI vector<vector<vector<ll> > >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

#define MOD 1000000007LL

int W, H;
VS rot(const VS& g) {
	VS o(W, string(H, '?'));
	REP(y, H) REP(x, W) o[W-1-x][y] = g[y][x];
	return o;
}

VVVI dp;
ll f(int y, int splitx, int co, const VS& g) {
	if(y==H) return co;
	if(dp[y][splitx][co]!=-1) return dp[y][splitx][co];
	ll ans = 0;
	REP(ns, splitx+1) {
		int ok=1;
		RANGE(x, 0, ns) if(g[y][x]=='W') ok=0;
		RANGE(x, ns, W) if(g[y][x]=='B') ok=0;
		if(!ok) continue;
		ans += f(y+1, ns, co || (0<y && ns < splitx), g);
		ans %= MOD;
	}
	return dp[y][splitx][co]=ans;
}

ll all_(char notc, VS& g) {
	ll ok=1;
	REP(y, H) REP(x, W) if(g[y][x]==notc) ok=0;
	return ok;
}

class TwoConvexShapes {
	public:
	int countWays(vector <string> g) {
		W=g[0].size();
		H=g.size();
		ll ans = all_('B', g)+all_('W', g);
		REP(loop, 4) {
			W=g[0].size();
			H=g.size();
			dp = VVVI(H, VVI(W+1, VI(2, -1)));
			ll r = f(0, W, 0, g);
			cout<<r<<endl;
			ans += r;
			ans %= MOD;
			g = rot(g);
		}
		return ans;
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
#define END	 verify_case(_, TwoConvexShapes().countWays(grid));}
int main(){

CASE(0)
	string grid_[] = {"????"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 8; 
END
CASE(0)
	string grid_[] = {"??",
 "??"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 14; 
END
CASE(1)
	string grid_[] = {"B?",
 "??"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 7; 
END
return 0;
CASE(2)
	string grid_[] = {"WWB",
 "WWW",
 "WWW",
 "WWW"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 1; 
END
CASE(3)
	string grid_[] = {"BBBBBB",
 "WWBBBB",
 "WBBBBB"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 0; 
END
CASE(4)
	string grid_[] = {"?BB?",
 "BBBB",
 "?BB?"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 5; 
END
CASE(5)
	string grid_[] = {"?WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "B?WWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BB?WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBB?WWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBB?WWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBB?WWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBB?WWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBB?WWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBB?WWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBB?WWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBB?WWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBB?WWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBB?WWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBB?WWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBB?WWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBB?WWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBB?WWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBB?WWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBB?WWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBB?WWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBB?WWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBB?WWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBB?WWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBB?WWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBB?WWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBB?WWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBB?WWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBB?WWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBB?WW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB?W"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 73741817; 
END

}
// END CUT HERE
