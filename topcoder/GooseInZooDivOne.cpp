// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Crow Keith is looking at the goose cage in the zoo.
The bottom of the cage is divided into a grid of square cells.
There are some birds sitting on those cells (with at most one bird per cell).
Some of them are geese and all the others are ducks.

Keith wants to know which birds are geese.
He knows the following facts about them:

There is at least one goose in the cage.
The number of geese is even.
Each bird within Manhattan distance dist of any goose is also a goose.

 
You are given a vector <string> field and the int dist.
The array field describes the bottom of the cage.
Each character of each element of field describes one of the cells.
The meaning of individual characters follows.

The character 'v' represents a cell that contains a bird.
The character '.' represents an empty cell.


Return the number of possible sets of geese in the cage, modulo 1,000,000,007.
Note that for some of the test cases there can be no possible sets of geese.

DEFINITION
Class:GooseInZooDivOne
Method:count
Parameters:vector <string>, int
Returns:int
Method signature:int count(vector <string> field, int dist)


NOTES
-The Manhattan distance between cells (a,b) and (c,d) is |a-c| + |b-d|, where || denotes absolute value. In words, the Manhattan distance is the smallest number of steps needed to get from one cell to the other, given that in each step you can move to a cell that shares a side with your current cell.


CONSTRAINTS
-field will contain between 1 and 50 elements, inclusive.
-Each element of field will contain between 1 and 50 characters, inclusive.
-Each element of field will contain the same number of characters.
-Each character of each element of field will be 'v' or '.'.
-dist will be between 0 and 100, inclusive.


EXAMPLES

0)
{"vvv"}
0

Returns: 3

There are three possible sets of positions of geese: "ggd", "gdg", or "dgg" ('g' are geese and 'd' are ducks).

1)
{"."}
100

Returns: 0

The number of geese must be positive, but there are no birds in the cage.

2)
{"vvv"}
1

Returns: 0



3)
{"v.v..................v............................"
,".v......v..................v.....................v"
,"..v.....v....v.........v...............v......v..."
,".........vvv...vv.v.........v.v..................v"
,".....v..........v......v..v...v.......v..........."
,"...................vv...............v.v..v.v..v..."
,".v.vv.................v..............v............"
,"..vv.......v...vv.v............vv.....v.....v....."
,"....v..........v....v........v.......v.v.v........"
,".v.......v.............v.v..........vv......v....."
,"....v.v.......v........v.....v.................v.."
,"....v..v..v.v..............v.v.v....v..........v.."
,"..........v...v...................v..............v"
,"..v........v..........................v....v..v..."
,"....................v..v.........vv........v......"
,"..v......v...............................v.v......"
,"..v.v..............v........v...............vv.vv."
,"...vv......v...............v.v..............v....."
,"............................v..v.................v"
,".v.............v.......v.........................."
,"......v...v........................v.............."
,".........v.....v..............vv.................."
,"................v..v..v.........v....v.......v...."
,"........v.....v.............v......v.v............"
,"...........v....................v.v....v.v.v...v.."
,"...........v......................v...v..........."
,"..........vv...........v.v.....................v.."
,".....................v......v............v...v...."
,".....vv..........................vv.v.....v.v....."
,".vv.......v...............v.......v..v.....v......"
,"............v................v..........v....v...."
,"................vv...v............................"
,"................v...........v........v...v....v..."
,"..v...v...v.............v...v........v....v..v...."
,"......v..v.......v........v..v....vv.............."
,"...........v..........v........v.v................"
,"v.v......v................v....................v.."
,".v........v................................v......"
,"............................v...v.......v........."
,"........................vv.v..............v...vv.."
,".......................vv........v.............v.."
,"...v.............v.........................v......"
,"....v......vv...........................v........."
,"....vv....v................v...vv..............v.."
,".................................................."
,"vv........v...v..v.....v..v..................v...."
,".........v..............v.vv.v.............v......"
,".......v.....v......v...............v............."
,"..v..................v................v....v......"
,".....v.....v.....................v.v......v......."}
3

Returns: 898961330



*/
// END CUT HERE
#line 135 "GooseInZooDivOne.cpp"

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
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << "\n"; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


static const ll MODVAL = 1000000007;

int co;
int W, H;
void f(vector<string>& F, int D, int x, int y) {
	if(F[y][x]!='v') return;
	F[y][x]='x';
	co++;
	
	REP(yy, H) REP(xx, W) {
		if(abs(yy-y)+abs(xx-x) <= D) {
			if(0<=xx && xx<W && 0<=yy && yy<H && F[yy][xx]=='v') {
				f(F, D, xx, yy);
			}
		}
	}
}

class GooseInZooDivOne {
	public:
	int count(vector <string> F, int D) {
		H=F.size();
		W=F[0].size();
		int even=0, odd=0;
		REP(y, H) REP(x, W) {
			if(F[y][x]=='v') {
				co=0;
				f(F, D, x, y);
				if(co&1) odd++; else even++;
			}
		}
		ll ans = 1;
		REP(i, even + max(0, odd-1)) ans = (ans * 2) % MODVAL;
		return (ans - 1 + MODVAL) % MODVAL;
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
#define END	 verify_case(_, GooseInZooDivOne().count(field, dist));}
int main(){

CASE(0)
	string field_[] = {".v...", "v.v.v", ".....", "....."};
	  vector <string> field(field_, field_+sizeof(field_)/sizeof(*field_)); 
	int dist = 2; 
	int _ = 1; 
END
CASE(1)
	string field_[] = {"."};
	  vector <string> field(field_, field_+sizeof(field_)/sizeof(*field_)); 
	int dist = 100; 
	int _ = 0; 
END
CASE(2)
	string field_[] = {"vvv"};
	  vector <string> field(field_, field_+sizeof(field_)/sizeof(*field_)); 
	int dist = 1; 
	int _ = 0; 
END
//return 0;
CASE(3)
	string field_[] = {"v.v..................v............................"
,".v......v..................v.....................v"
,"..v.....v....v.........v...............v......v..."
,".........vvv...vv.v.........v.v..................v"
,".....v..........v......v..v...v.......v..........."
,"...................vv...............v.v..v.v..v..."
,".v.vv.................v..............v............"
,"..vv.......v...vv.v............vv.....v.....v....."
,"....v..........v....v........v.......v.v.v........"
,".v.......v.............v.v..........vv......v....."
,"....v.v.......v........v.....v.................v.."
,"....v..v..v.v..............v.v.v....v..........v.."
,"..........v...v...................v..............v"
,"..v........v..........................v....v..v..."
,"....................v..v.........vv........v......"
,"..v......v...............................v.v......"
,"..v.v..............v........v...............vv.vv."
,"...vv......v...............v.v..............v....."
,"............................v..v.................v"
,".v.............v.......v.........................."
,"......v...v........................v.............."
,".........v.....v..............vv.................."
,"................v..v..v.........v....v.......v...."
,"........v.....v.............v......v.v............"
,"...........v....................v.v....v.v.v...v.."
,"...........v......................v...v..........."
,"..........vv...........v.v.....................v.."
,".....................v......v............v...v...."
,".....vv..........................vv.v.....v.v....."
,".vv.......v...............v.......v..v.....v......"
,"............v................v..........v....v...."
,"................vv...v............................"
,"................v...........v........v...v....v..."
,"..v...v...v.............v...v........v....v..v...."
,"......v..v.......v........v..v....vv.............."
,"...........v..........v........v.v................"
,"v.v......v................v....................v.."
,".v........v................................v......"
,"............................v...v.......v........."
,"........................vv.v..............v...vv.."
,".......................vv........v.............v.."
,"...v.............v.........................v......"
,"....v......vv...........................v........."
,"....vv....v................v...vv..............v.."
,".................................................."
,"vv........v...v..v.....v..v..................v...."
,".........v..............v.vv.v.............v......"
,".......v.....v......v...............v............."
,"..v..................v................v....v......"
,".....v.....v.....................v.v......v......."};
	  vector <string> field(field_, field_+sizeof(field_)/sizeof(*field_)); 
	int dist = 3; 
	int _ = 898961330; 
END

}
// END CUT HERE
