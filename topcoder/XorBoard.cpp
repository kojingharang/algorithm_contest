// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Jiro has a rectangular grid with H rows and W columns (i.e., the grid has H*W cells in total). Initially, each cell in the grid contained the character '0'.

A row flip is an operation in which Jiro picks a row of the grid, and in that row he changes all '0's to '1's and vice versa.
Similarly, a column flip is an operation in which Jiro does the same to a column of the grid.
Jiro took the grid that contained '0's everywhere.
He performed a row flip Rcount times, and then a column flip Ccount times.
(It is possible that Jiro flipped the same row or column multiple times.)
At the end, Jiro noticed that there are exactly S '1's in the grid.

You are given the ints H, W, Rcount, Ccount, and S.
We are interested in the number of different ways in which Jiro could have flipped the rows and columns of the grid.
Two ways of flipping are considered different if there is a row or a column that was flipped a different number of times.
(That is, the order in which the rows and columns are flipped does not matter.)
Return the number of different ways of flipping that match the given situation, modulo 555,555,555.


DEFINITION
Class:XorBoard
Method:count
Parameters:int, int, int, int, int
Returns:int
Method signature:int count(int H, int W, int Rcount, int Ccount, int S)


CONSTRAINTS
-H will be between 1 and 1,555, inclusive.
-W will be between 1 and 1,555, inclusive.
-Rcount will be between 0 and 1,555, inclusive.
-Ccount will be between 0 and 1,555, inclusive.
-S will be between 0 and H*W, inclusive.


EXAMPLES

0)
2
2
2
2
4

Returns: 4

In two of the four ways, Jiro flips each row once, and then the same column twice.
In the other two ways he first flips the same row twice, and then each column once.

1)
2
2
0
0
1

Returns: 0

Without any flips, all cells still contain '0's, so S=1 is impossible.

2)
10
20
50
40
200

Returns: 333759825

Rcount and Ccount may be greater than H and W.

3)
1200
1000
800
600
4000

Returns: 96859710



4)
555
555
555
555
5550

Returns: 549361755



*/
// END CUT HERE
#line 97 "XorBoard.cpp"

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



#define MOD 555555555

int comb[2500][2500];

class XorBoard {
	public:
	int count(int H, int W, int RC, int CC, int S) {
		// nCm = n-1Cm-1 + n-1Cm
		REP(n, 2500) comb[n][0] = 1;
		RANGE(n, 1, 2500) RANGE(m, 1, 2500) comb[n][m] = ((ll)comb[n-1][m-1] + comb[n-1][m]) % MOD;
		
		ll ans = 0;
		REP(ro, H+1) if(ro<=RC && (RC-ro)%2==0)
		REP(co, W+1) if(co<=CC && (CC-co)%2==0)
		if(W*ro+H*co-2*ro*co==S) {
			ll lans = (ll)comb[H][ro] * comb[W][co] % MOD * comb[(RC-ro)/2 + H-1][H-1] % MOD * comb[(CC-co)/2 + W-1][W-1] % MOD;
			ans = (ans + lans) % MOD;
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
#define END	 verify_case(_, XorBoard().count(H, W, Rcount, Ccount, S));}
int main(){

CASE(0)
	int H = 2; 
	int W = 2; 
	int Rcount = 2; 
	int Ccount = 2; 
	int S = 4; 
	int _ = 4; 
END
CASE(1)
	int H = 2; 
	int W = 2; 
	int Rcount = 0; 
	int Ccount = 0; 
	int S = 1; 
	int _ = 0; 
END
CASE(2)
	int H = 10; 
	int W = 20; 
	int Rcount = 50; 
	int Ccount = 40; 
	int S = 200; 
	int _ = 333759825; 
END
CASE(3)
	int H = 1200; 
	int W = 1000; 
	int Rcount = 800; 
	int Ccount = 600; 
	int S = 4000; 
	int _ = 96859710; 
END
CASE(4)
	int H = 555; 
	int W = 555; 
	int Rcount = 555; 
	int Ccount = 555; 
	int S = 5550; 
	int _ = 549361755; 
END

}
// END CUT HERE
