// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// The knight is a chess piece that moves by jumping: two cells in one direction, one in the other.
Formally, a knight standing on the cell (x,y) can move to any of the following eight cells:
(x+2,y+1), (x+2,y-1), (x-2,y+1), (x-2,y-1), (x+1,y+2), (x+1,y-2), (x-1,y+2), and (x-1,y-2).
Of course, if the knight is close to the edge of the board, some of these cells might not be on the board.
It is not allowed to jump to a cell that is not on the board.

A knight circuit is a sequence of cells on a chessboard that starts and ends with the same cell.
Each consecutive pair of cells in the knight circuit must correspond to a single jump of the knight.
The knight circuit may visit each cell arbitrarily many times.
The size of a knight circuit is the number of different cells visited by the circuit.

You are given the ints w and h: the width (in columns) and the height (in rows) of a rectangular chessboard. Return the maximum knight circuit size that can be obtained on the given board.
You are free to choose any cell as the start of your circuit.

DEFINITION
Class:KnightCircuit2
Method:maxSize
Parameters:int, int
Returns:int
Method signature:int maxSize(int w, int h)


CONSTRAINTS
-w and h will each be between 1 and 45000, inclusive.


EXAMPLES

0)
1
1

Returns: 1

Note that a sequence that consists of a single cell is considered to be a valid knight circuit.

1)
15
2

Returns: 8

If you start at any corner of the board, it is possible to move the knight to visit 8 cells, and then do the same moves in reverse in order to return to the starting cell. One possibility for the first eight cells of an optimal knight circuit is shown below:


1...3...5...7..
..2...4...6...8


2)
100
100

Returns: 10000

It is possible to make a Knight circuit that contains all the cells on the board.

*/
// END CUT HERE
#line 64 "KnightCircuit2.cpp"

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
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
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

#include <assert.h>


class KnightCircuit2 {
	public:
	//int sample(int W, int H) {
	//	if(W>H) swap(W, H);
	//	if(W==1) return 1;
	//	if(W==2) return (H+1)/2;
	//	if(W==3 && H==3) return 8;
	//	else return W*H;
	//}
	int maxSize(int W, int H) {
		if(W>=5 && H>=5) return W*H;
		cout<<"calc"<<endl;
		int dx[] = {2,1,-1,-2,-2,-1,1,2};
		int dy[] = {1,2,2,1,-1,-2,-2,-1};
		int ans = 0;
		REP(y, H) REP(x, W) {
			VVI w(H, VI(W));
			
			deque<PII> q;
			q.PB(MP(x, y));
			while(q.size()) {
				int X = q.front().first;
				int Y = q.front().second;
				q.pop_front();
				w[Y][X] = 1;
				REP(t, 8) {
					int NX=X+dx[t];
					int NY=Y+dy[t];
					if(0<=NX && NX<W && 0<=NY && NY<H && w[NY][NX]==0) {w[NY][NX]=1;q.PB(MP(NX, NY));}
				}
			}
			int lans=0;
			REP(y, H) REP(x, W) lans+=w[y][x];
			ans = max(ans, lans);
		}
		return ans;
	}
	//void test() {
	//	RANGE(w, 1, 18) RANGE(h, 1, 18) {
	//		int ref = maxSize(w, h);
	//		int ans = w>=5 && h>=5 ? w*h : ref;
	//		int sam = sample(w, h);
	//		assert(ref==ans);
	//		assert(ref==sam);
	//		cout<<w<<" "<<h<<" "<<ans<<(ans==w*h?" YES":" ")<<endl;
	//	}
	//}
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
#define END	 verify_case(_, KnightCircuit2().maxSize(w, h));}
int main(){
//KnightCircuit2().test();
//return 0;
CASE(0)
	int w = 1; 
	int h = 1; 
	int _ = 1; 
END
CASE(0)
	int w = 3; 
	int h = 3; 
	int _ = 8; 
END
CASE(1)
	int w = 15; 
	int h = 2; 
	int _ = 8; 
END
//return 0;
CASE(2)
	int w = 100; 
	int h = 100; 
	int _ = 10000; 
END
CASE(2)
	int w = 45000; 
	int h = 4; 
	int _ = 180000; 
END

}
// END CUT HERE
