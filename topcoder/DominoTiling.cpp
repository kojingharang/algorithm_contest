// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are given a vector <string> grid that describes a rectangular grid of square cells.
The character 'X' represents a cell that is already covered, the character '.' is a cell that still needs to be covered.

You want to cover all the '.' cells using a collection of disjoint 2x1 dominos.
Return the number of ways to do this.
Two ways are considered different if two cells are covered by the same domino in one tiling and by two different dominos in the other tiling.


DEFINITION
Class:DominoTiling
Method:count
Parameters:vector <string>
Returns:long long
Method signature:long long count(vector <string> grid)


CONSTRAINTS
-grid will contain between 1 and 12 elements, inclusive.
-The length of each element of grid will be between 1 and 12, inclusive.
-Each element of grid will be the same length.
-Each character of each element of grid will be '.' or 'X'.


EXAMPLES

0)
{"..",
 ".."}

Returns: 2

There are exactly two ways to do this:


--   or   ||
--        ||



1)
{"...",
 ".X.",
 "..."}


Returns: 2

Again, there are two solutions:


--|     |--
|X|     |X|
|--     --|



2)
{"...",
 "...",
 "..X"}


Returns: 4


|||     --|     |--     --|
|||     --|     |--     |||
--X     __X     --X     ||X



3)
{".....",
 ".....",
 ".X...",
 ".X..."}

Returns: 29



*/
// END CUT HERE
#line 88 "DominoTiling.cpp"

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
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
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
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class DominoTiling {
	public:
	long long count(vector <string> g) {
		ll W = g[0].size();
		ll H = g.size();
		// 1: - (close or X) 0: | (open)
		VI dp(1<<W);
		dp[(1<<W)-1] = 1;
		REP(y, H) {
			VI ndp(1<<W);
			int line = 0;
			REP(x, W) if(g[y][x]=='X') line |= 1<<x;

			// must close opened in prev line
			REP(bits, 1<<W) if((bits & line) == 0) ndp[bits|line] = dp[bits ^ ((1<<W)-1)];
			// put -- if valid
			REP(x, W-1) {
				int block = 3<<x;
				if((block & line)==0) REP(bits, 1<<W) {
					if((bits&block)==0) ndp[bits|block] += ndp[bits];
				}
			}
			dp = ndp;
//			DD(dp);
		}
		return dp[(1<<W)-1];
	}
};

class DominoTilingRef {
	public:
	long long count(vector <string> g) {
		ll W = g[0].size();
		ll H = g.size();
		// 0: - 1: |
		VI dp(1<<W);
		dp[0] = 1;
		vector<bool> tu(W), td(W);
		REP(y, H) {
			VI ndp(1<<W);
//			cout<<endl;
//			DD(y);
			REP(bits, 1<<W) if(dp[bits]) {
//				DD(bits);
				REP(x, W) tu[x] = (bits>>x)&1;
				REP(nbits, 1<<W) if((bits&nbits)==0) {
//					cout<<endl;
//					DD(nbits);
					REP(x, W) td[x] = (nbits>>x)&1;

					bool ok = 1;
					REP(x, W) {
						if(g[y][x]=='X') {
							if(tu[x] || td[x]) {ok=0;break;}
						} else if(tu[x] && td[x]) {ok=0;break;}
					}
//					DD(tu);
//					DD(t);
//					DD(ok);
					if(ok) {
						REP(x, W) if(tu[x] && !td[x]) td[x]=1;
						REP(x, W) {
							if(g[y][x]=='.' && !td[x]) {
								if(x==W-1) {ok=0;break;}
								else {
									if(g[y][x+1]=='.') {
										if(td[x+1]) {ok=0;break;}
										else td[x]=td[x+1]=1;
									} else {ok=0;break;}
								}
							}
						}
					}
//					DD(ok);
					if(ok) {
						ndp[nbits] += dp[bits];
					}
				}
			}
			dp = ndp;
//			DD(dp);
		}
		return dp[0];
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const long long& Expected, const long long& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, DominoTiling().count(grid));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string grid_[] = {"............", "............", "............", "............", "............", "............", "............", "............", "............", "............", "............", "............"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	long long _ = 53060477521960000LL; 
END

CASE(0)
	string grid_[] = {"..",
 ".."};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	long long _ = 2LL; 
END
CASE(1)
	string grid_[] = {"...",
 ".X.",
 "..."}
;
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	long long _ = 2LL; 
END
//return 0;
CASE(2)
	string grid_[] = {"...",
 "...",
 "..X"}
;
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	long long _ = 4LL; 
END
CASE(3)
	string grid_[] = {".....",
 ".....",
 ".X...",
 ".X..."};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	long long _ = 29LL; 
END
#if 0  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: String
	vector <string> grid; 
	{
		int N=UNIFORM_LL(1, 51);
		grid = vector <string>(N); 
		REP(i, N) {
			grid[i] = UNIFORM_LL(0, 1000);
		}
	}
	long long _0 = DominoTiling().count(grid);
	long long _1 = DominoTilingRef().count(grid);
	if(!verify_case(_0, _1, true)) {
print(grid);
	}
}
#endif

}
// END CUT HERE
