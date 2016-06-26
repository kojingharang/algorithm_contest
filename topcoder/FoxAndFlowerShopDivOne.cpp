// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Jiro came to a flower shop to buy flowers.
The flowers in the shop are arranged in some cells of a rectangular grid.
The layout of the grid is given as a vector <string> flowers.
There are two types of flowers in the shop: lilies and petunias.
If the j-th cell of the i-th row of the grid contains a flower, then the j-th character of the i-th element of flowers will be 'L' if it is a lily, and 'P' if it is a petunia.
(All indices in the previous sentence are 0-based.)
If the particular cell is empty, the corresponding character will be '.' (a period).

In order to buy flowers, Jiro has to draw two disjoint rectangles on this grid and buy all the flowers which lie inside the rectangles.
Of course, the sides of the rectangles must be on cell boundaries.
(Therefore, the sides of the rectangles will necessarily be parallel to the coordinate axes.)
The rectangles are allowed to touch, but they may not intersect.
In other words, the rectangles may share a common boundary, but no cell may belong to both rectangles.
Each of the two rectangles must contain at least one cell.

Jiro wants to buy approximately the same number of lilies and petunias.
More precisely, the positive difference between the number of lilies and petunias must be at most maxDiff, inclusive.
Given that constraint, Jiro wants to buy as many flowers as possible.

You are given the vector <string> flowers and the int maxDiff.
Return the maximum possible number of flowers Jiro can buy in this situation.
If there is no valid way to buy flowers, return -1 instead.

DEFINITION
Class:FoxAndFlowerShopDivOne
Method:theMaxFlowers
Parameters:vector <string>, int
Returns:int
Method signature:int theMaxFlowers(vector <string> flowers, int maxDiff)


CONSTRAINTS
-flowers will contain between 2 and 30 elements, inclusive.
-Each element of flowers will contain the same number of characters.
-Each element of flowers will contain between 1 and 30 characters, inclusive.
-Each character in flowers will be either 'L', 'P', or '.'.
-maxDiff will be between 0 and 900, inclusive.


EXAMPLES

0)
{"LLL",
 "PPP",
 "LLL"}
1

Returns: 7

Jiro cannot buy all the flowers, because the difference between the number of lilies and the number of petunias would be too large.
The best he can do is to buy 7 flowers: 4 lilies and 3 petunias.
One way of doing so is to draw two rectangles: (0,0)-(1,2) and (2,0)-(2,0).
Note that (r1,c1)-(r2,c2) denotes a rectangle with cell (r1,c1) in the top left corner and cell (r2,c2) in the bottom right corner.
(All indices are 0-based.)

1)
{"LLL",
 "PPP",
 "LLL"}
0

Returns: 6

This time Jiro is required to buy the same number of lilies and petunias.
Therefore the best he can do is to buy three of each kind.

2)
{"...",
 "...",
 "..."}
3

Returns: 0

There are no flowers.

3)
{"LLPL.LPP",
 "PLPPPPLL",
 "L.P.PLLL",
 "LPL.PP.L",
 ".LLL.P.L",
 "PPLP..PL"}
2

Returns: 38



4)
{"LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL"}
0

Returns: -1

Here it is impossible to draw the two rectangles. Regardless of how Jiro draws them, he will surely buy more lilies than petunias, and that is not allowed.

5)
{"LLLP..LLP.PLL.LL..LP",
 "L.PL.L.LLLL.LPLLPLP.",
 "PLL.LL.LLL..PL...L..",
 ".LPPP.PPPLLLLPLP..PP",
 "LP.P.PPL.L...P.L.LLL",
 "L..LPLPP.PP...PPPL..",
 "PP.PLLL.LL...LP..LP.",
 "PL...P.PPPL..PLP.L..",
 "P.PPPLPLP.LL.L.LLLPL",
 "PLLPLLP.LLL.P..P.LPL",
 "..LLLPLPPPLP.P.LP.LL",
 "..LP..L..LLPPP.LL.LP",
 "LPLL.PLLPPLP...LL..P",
 "LL.....PLL.PLL.P....",
 "LLL...LPPPPL.PL...PP",
 ".PLPLLLLP.LPP...L...",
 "LL...L.LL.LLLPLPPPP.",
 "PLPLLLL..LP.LLPLLLL.",
 "PP.PLL..L..LLLPPL..P",
 ".LLPL.P.PP.P.L.PLPLL"}
9

Returns: 208



*/
// END CUT HERE
#line 135 "FoxAndFlowerShopDivOne.cpp"

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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
 


template<typename DataT, typename SumT, typename ValueFunc>
class CumulativeSum2D {
public:
	// sum[y][x] is sum of [0, x) x [0, y)
	vector<vector<SumT> > sum;
	CumulativeSum2D(const vector<string>& data, ValueFunc func) {
		int H=data.size();
		int W=data[0].size();
		sum = vector<vector<SumT> >(H+1, vector<SumT>(W+1));
		REP(y, H) REP(x, W) sum[y+1][x+1] = func(data[y][x]) + sum[y+1][x] + sum[y][x+1] - sum[y][x];
	}
	CumulativeSum2D(const vector<vector<DataT> >& data, ValueFunc func) {
		int H=data.size();
		int W=data[0].size();
		sum = vector<vector<SumT> >(H+1, vector<SumT>(W+1));
		REP(y, H) REP(x, W) sum[y+1][x+1] = func(data[y][x]) + sum[y+1][x] + sum[y][x+1] - sum[y][x];
	}
	// returns sum of [x0, x1) x [y0, y1)
	SumT get(int x0, int y0, int x1, int y1) {
		return sum[y1][x1] - sum[y0][x1] - sum[y1][x0] + sum[y0][x0];
	}
};


struct Sum {
	ll operator()(char v) {
		return v!='.' ? 1 : 0;
	}
};

struct Dif {
	ll operator()(char v) {
		return v=='L' ? 1 : (v=='P' ? -1 : 0);
	}
};

class FoxAndFlowerShopDivOne {
	public:
	int theMaxFlowers(vector <string> F, int M) {
		int W=F[0].size();
		int H=F.size();
		
		// sum[y][x] is sum of [0, x) x [0, y)
		CumulativeSum2D<char, ll, Sum> csum(F, Sum());
		CumulativeSum2D<char, ll, Dif> cdif(F, Dif());
		
		int ans = -1;
		REP(X, W) {
			map<int, int> hi0, hi1;
			// [0, X) x [0, H)
			RANGE(x0, 0, X)
			RANGE(x1, x0+1, X+1)
			RANGE(y0, 0, H)
			RANGE(y1, y0+1, H+1) {
				int S = csum.get(x0, y0, x1, y1);
				int D = cdif.get(x0, y0, x1, y1);
				hi0[D] = max(hi0[D], S);
			}
			// [X, W) x [0, H)
			RANGE(x0, X, W)
			RANGE(x1, x0+1, W+1)
			RANGE(y0, 0, H)
			RANGE(y1, y0+1, H+1) {
				int S = csum.get(x0, y0, x1, y1);
				int D = cdif.get(x0, y0, x1, y1);
				hi1[D] = max(hi1[D], S);
			}
			FOR(e0, hi0) FOR(e1, hi1) if(abs(e0->first+e1->first)<=M) ans=max(ans, e0->second+e1->second);
		}
		
		REP(Y, H) {
			map<int, int> hi0, hi1;
			// [0, W) x [0, Y)
			RANGE(x0, 0, W)
			RANGE(x1, x0+1, W+1)
			RANGE(y0, 0, Y)
			RANGE(y1, y0+1, Y+1) {
				int S = csum.get(x0, y0, x1, y1);
				int D = cdif.get(x0, y0, x1, y1);
				hi0[D] = max(hi0[D], S);
			}
			// [0, W) x [Y, H)
			RANGE(x0, 0, W)
			RANGE(x1, x0+1, W+1)
			RANGE(y0, Y, H)
			RANGE(y1, y0+1, H+1) {
				int S = csum.get(x0, y0, x1, y1);
				int D = cdif.get(x0, y0, x1, y1);
				hi1[D] = max(hi1[D], S);
			}
			FOR(e0, hi0) FOR(e1, hi1) if(abs(e0->first+e1->first)<=M) ans=max(ans, e0->second+e1->second);
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
#define END	 verify_case(_, FoxAndFlowerShopDivOne().theMaxFlowers(flowers, maxDiff));}
int main(){

CASE(0)
	string flowers_[] = {"LLL",
 "PPP",
 "LLL"};
	  vector <string> flowers(flowers_, flowers_+sizeof(flowers_)/sizeof(*flowers_)); 
	int maxDiff = 1; 
	int _ = 7; 
END
CASE(1)
	string flowers_[] = {"LLL",
 "PPP",
 "LLL"};
	  vector <string> flowers(flowers_, flowers_+sizeof(flowers_)/sizeof(*flowers_)); 
	int maxDiff = 0; 
	int _ = 6; 
END
CASE(2)
	string flowers_[] = {"...",
 "...",
 "..."};
	  vector <string> flowers(flowers_, flowers_+sizeof(flowers_)/sizeof(*flowers_)); 
	int maxDiff = 3; 
	int _ = 0; 
END
CASE(3)
	string flowers_[] = {"LLPL.LPP",
 "PLPPPPLL",
 "L.P.PLLL",
 "LPL.PP.L",
 ".LLL.P.L",
 "PPLP..PL"};
	  vector <string> flowers(flowers_, flowers_+sizeof(flowers_)/sizeof(*flowers_)); 
	int maxDiff = 2; 
	int _ = 38; 
END
CASE(4)
	string flowers_[] = {"LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL"};
	  vector <string> flowers(flowers_, flowers_+sizeof(flowers_)/sizeof(*flowers_)); 
	int maxDiff = 0; 
	int _ = -1; 
END
CASE(5)
	string flowers_[] = {"LLLP..LLP.PLL.LL..LP",
 "L.PL.L.LLLL.LPLLPLP.",
 "PLL.LL.LLL..PL...L..",
 ".LPPP.PPPLLLLPLP..PP",
 "LP.P.PPL.L...P.L.LLL",
 "L..LPLPP.PP...PPPL..",
 "PP.PLLL.LL...LP..LP.",
 "PL...P.PPPL..PLP.L..",
 "P.PPPLPLP.LL.L.LLLPL",
 "PLLPLLP.LLL.P..P.LPL",
 "..LLLPLPPPLP.P.LP.LL",
 "..LP..L..LLPPP.LL.LP",
 "LPLL.PLLPPLP...LL..P",
 "LL.....PLL.PLL.P....",
 "LLL...LPPPPL.PL...PP",
 ".PLPLLLLP.LPP...L...",
 "LL...L.LL.LLLPLPPPP.",
 "PLPLLLL..LP.LLPLLLL.",
 "PP.PLL..L..LLLPPL..P",
 ".LLPL.P.PP.P.L.PLPLL"};
	  vector <string> flowers(flowers_, flowers_+sizeof(flowers_)/sizeof(*flowers_)); 
	int maxDiff = 9; 
	int _ = 208; 
END

}
// END CUT HERE
