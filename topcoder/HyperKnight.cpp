// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fernando loves to play chess. One day he decided to play chess on an unusually large rectangular board. To compensate for the board's size he also decided to change the distance a knight can move in a single jump.

To describe the moves easily, we will now introduce a coordinate system. Each cell of the chessboard can be described using two integers (r,c): its row number and its column number. Now, if we have a piece at (r,c), the move (x,y) takes the piece to the cell (r+x,c+y).

The new chess piece will be called an (a,b)-hyperknight. The hyperknight always has 8 possible moves: (+a,+b), (+a,-b), (-a,+b), (-a,-b), (+b,+a), (+b,-a), (-b,+a), and (-b,-a). Note that the original chess knight is a (2,1)-hyperknight.

Of course, as the chessboard is finite, it is not always possible to make each of the 8 moves. Some of them may cause our hyperknight to leave the chessboard. A move is called valid if the destination cell is on the chessboard. Fernando would like to know the number of cells on his board such that his hyperknight will have exactly k valid moves from that cell.

You are given the ints a, b, numRows, numColumns and k. The values numRows and numColumns define the number of rows and number of columns on the chessboard, respectively. The other three values were already explained above. Compute and return the number of cells on the chessboard that have exactly k valid (a,b)-hyperknight moves.

DEFINITION
Class:HyperKnight
Method:countCells
Parameters:int, int, int, int, int
Returns:long long
Method signature:long long countCells(int a, int b, int numRows, int numColumns, int k)


NOTES
-If you wish, you may assume that the rows are numbered 0 through numRows-1 and columns 0 through numColumns-1. However, note that the actual row/column numbers do not matter, as long as they are consecutive.


CONSTRAINTS
-a will be between 1 and 1,000,000,000 (10^9), inclusive.
-b will be between 1 and 1,000,000,000 (10^9), inclusive.
-a will not be equal to b.
-numRows will be between 1 and 1,000,000,000 (10^9), inclusive.
-numColumns will be between 1 and 1,000,000,000 (10^9), inclusive.
-2*max(a,b) will be strictly less than min(numRows,numColumns).
-k will be between 0 and 8, inclusive.


EXAMPLES

0)
2
1
8
8
4

Returns: 20

This is a standard chessboard. We have a traditional chess knight and we are looking for cells such that the knight has exactly 4 valid moves.

1)
3
2
8
8
2

Returns: 16



2)
1
3
7
11
0

Returns: 0



3)
3
2
10
20
8

Returns: 56



4)
1
4
100
10
6

Returns: 564



5)
2
3
1000000000
1000000000
8

Returns: 999999988000000036



*/
// END CUT HERE
#line 107 "HyperKnight.cpp"

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



class HyperKnight {
	public:
	long long countCells(int A, int B, int NR, int NC, int K) {
		VVI pat(5, VI(5, 0));
		int eX[] = {0,0,1,1,3,3,4,4};
		int eY[] = {1,3,0,4,0,4,1,3};
		REP(i, 8) pat[eY[i]][eX[i]]=1;
		//cout<<pat<<endl;
		if(B>A) swap(A, B);
		
		ll ans = 0;
		REP(y0, 5) {
			REP(x0, 5) {
				RANGE(y1, y0, 5) {
					RANGE(x1, x0, 5) {
						if(x1<2||2<x0||y1<2||2<y0) continue;
						int co=0;
						RANGE(y, y0, y1+1) RANGE(x, x0, x1+1) co+=pat[y][x];
						//cout<<x0<<" "<<y0<<"   "<<x1<<" "<<y1<<" ++ "<<co<<endl;
						if(co==K) {
							//cout<<x0<<" "<<y0<<"   "<<x1<<" "<<y1<<" --- "<<endl;
							int tb[] = {0, B, A, A+1};
							
							int a0=x0, a1=x1, N=NC;
							ll cc[2];
							int ok=1;
							REP(loop, 2) {
								int i0 = abs(a0-2);
								int i1 = abs(a1-2);
								ll cmin0 = tb[i0];
								ll cmin1 = tb[i1];
								ll cmax0 = tb[i0+1]-1;
								ll cmax1 = tb[i1+1]-1;
								// ながさ in [c0, c1]
								ll c0 = cmin0 + 1 + cmin1;
								ll c1 = cmax0 + 1 + cmax1;
								if(!(i0==2||i1==2)) {
									if(!(c0<=N&&N<=c1)) ok=0;
								}
								if(c0>N) ok=0;
								c1 = min((ll)N, c1);
								//cout<<c0<<" "<<c1<<endl;
								ll c = 0;
								if(i0==2&&i1==2) c = N-c0+1;
								else c = c1-c0+1;
								a0=y0, a1=y1, N=NR;
								cc[loop] = c;
							}
							
							if(ok) {
								ans += cc[0] * cc[1];
								//cout<<x0<<" "<<y0<<"   "<<x1<<" "<<y1<<" --- "<<cc[0]<<" "<<cc[1]<<endl;
							}
						}
					}
				}
			}
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
void verify_case(const long long& Expected, const long long& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, HyperKnight().countCells(a, b, numRows, numColumns, k));}
int main(){

//return 0;
//return 0;
CASE(0)
	int a = 2; 
	int b = 1; 
	int numRows = 8; 
	int numColumns = 8; 
	int k = 4; 
	long long _ = 20LL; 
END
//return 0;
CASE(1)
	int a = 3; 
	int b = 2; 
	int numRows = 8; 
	int numColumns = 8; 
	int k = 2; 
	long long _ = 16LL; 
END
CASE(2)
	int a = 1; 
	int b = 3; 
	int numRows = 7; 
	int numColumns = 11; 
	int k = 0; 
	long long _ = 0LL; 
END
CASE(3)
	int a = 3; 
	int b = 2; 
	int numRows = 10; 
	int numColumns = 20; 
	int k = 8; 
	long long _ = 56LL; 
END
CASE(4)
	int a = 1; 
	int b = 4; 
	int numRows = 100; 
	int numColumns = 10; 
	int k = 6; 
	long long _ = 564LL; 
END
CASE(5)
	int a = 2; 
	int b = 3; 
	int numRows = 1000000000; 
	int numColumns = 1000000000; 
	int k = 8; 
	long long _ = 999999988000000036LL; 
END

}
// END CUT HERE
