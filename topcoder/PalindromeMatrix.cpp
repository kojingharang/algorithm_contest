// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Note that the memory limit for all tasks in this SRM is 256 MB.


Fox Ciel has a matrix A that consists of N rows by M columns.
Both N and M are even.
Each element of the matrix is either 0 or 1.
The rows of the matrix are numbered 0 through N-1 from top to bottom, the columns are numbered 0 through M-1 from left to right.
The element in row i, column j is denoted A(i, j).
You are given a vector <string> A that describes the matrix A.
The character A[i][j] is '1' if A(i, j)=1 and it is '0' otherwise.



A palindrome is a string that reads the same forwards and backwards.
For example, "1001" and "0111001110" are palindromes while "1101" and "000001" are not.



Some rows and some columns in Ciel's matrix may be palindromes.
For example, in the matrix below both row 0 and column 3 are palindromes.
(Row 0 is the palindrome "0000", column 3 is the palindrome "0110".)


0000
0011
0111
1110



You are also given two ints: rowCount and columnCount.
Ciel wants her matrix A to have at least rowCount rows that are palindromes, and at the same time at least columnCount columns that are palindromes.
If this is currently not the case, she can change A by changing some of the elements (from '0' to '1' or vice versa).
Compute and return the smallest possible number of elements she needs to change in order to reach her goal.


DEFINITION
Class:PalindromeMatrix
Method:minChange
Parameters:vector <string>, int, int
Returns:int
Method signature:int minChange(vector <string> A, int rowCount, int columnCount)


CONSTRAINTS
-N and M will be between 2 and 14, inclusive.
-N and M will be even.
-A will contain N elements.
-Each element of A will contain M characters.
-Each character of A will be either '0' or '1'.
-rowCount will be between 0 and N.
-columnCount will be between 0 and M.


EXAMPLES

0)
{"0000"
,"1000"
,"1100"
,"1110"}
2
2

Returns: 1

An optimal solution is to change A(3, 0) to 0. Then we will have palindromes in two rows (0 and 3), and in two columns (0 and 3).

1)
{"0000"
,"1000"
,"1100"
,"1110"}
3
2

Returns: 3

This is similar to the previous example, but in this case we must have three row palindromes. 
An optimal solution is to change A(1, 0), A(2, 0) and A(3, 0) to 0.

2)
{"01"
,"10"}
1
1

Returns: 1



3)
{"1110"
,"0001"}
0
0

Returns: 0

Here, we do not have to change A at all.

4)
{"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"}
2
3

Returns: 8



5)
{"000000000000"
,"011101110111"
,"010001010101"
,"010001010101"
,"011101010101"
,"010101010101"
,"010101010101"
,"011101110111"
,"000000000000"
,"000000000000"}
5
9

Returns: 14



6)
{"11111101001110"
,"11000111111111"
,"00010101111001"
,"10110000111111"
,"10000011010010"
,"10001101101101"
,"00101010000001"
,"10111010100100"
,"11010011110111"
,"11100010110110"
,"00100101010100"
,"01001011001000"
,"01010001111010"
,"10100000010011"}
6
8

Returns: 31



******************************/
// END CUT HERE
#line 164 "PalindromeMatrix.cpp"
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


struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool Union(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool Find(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

#define f(x, y) ((x)+(y)*W)

const int inf = 1<<30;
int dp[16][16]; // dp[Y][r] ... y<Y or H-1-Y<y までの範囲に関して r 個以上の行と C 個以上の列が回文であるようにした時の最小コスト
int co[32][2]; // [CellID][value] ... CellID を代表とするグループのセルのうち value であるものの個数 (value in {0, 1})
class PalindromeMatrix {
	public:
	int minChange(vector <string> A, int R, int C) {
		int W=A[0].size(), H=A.size();
		VI wcc(W);
		REP(i, C) wcc[i]=1;
		sort(ALL(wcc));
		int ans = inf;
		do {
			REP(y, H/2+1) REP(r, R+1) dp[y][r]=inf;
			dp[0][0] = 0;
			REP(y, H/2) REP(r, R+1) {
				if(dp[y][r]==inf) continue;
				int Y[] = {y, H-1-y}; // upper/lower
				REP(pat, 4) {
					bool upper = pat&1, lower = pat&2; // is upper/lower row palindrome?
					int nr = r+upper+lower;
					if(nr<=R) {
						int add = 0;
						UnionFind uf(W*2); // x in [0, W), y in Y, index==y*W+x
						REP(x, W) if(wcc[x]) uf.Union(f(x, 0), f(x, 1)); // 選ばれた C 列は必ず回文にする
						if(upper) REP(x, W) uf.Union(f(x, 0), f(W-1-x, 0)); // 必要なら行を回文にする
						if(lower) REP(x, W) uf.Union(f(x, 1), f(W-1-x, 1));
						CLEAR(co, 0);
						REP(y, 2) REP(x, W) co[uf.root(f(x, y))][A[Y[y]][x]-'0']++;
						REP(y, 2) REP(x, W) if(uf.root(f(x, y))==f(x, y)) add += min(co[f(x, y)][0], co[f(x, y)][1]);
						dp[y+1][nr] = min(dp[y+1][nr], dp[y][r] + add);
					}
				}
			}
			ans = min(ans, dp[H/2][R]);
		} while(next_permutation(ALL(wcc)));
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, PalindromeMatrix().minChange(A, rowCount, columnCount));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string A_[] = {
 "0000"
,"1000"
,"1100"
,"1110"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int rowCount = 2; 
	int columnCount = 2; 
	int _ = 1; 
END
//return 0;
CASE(1)
	string A_[] = {"0000"
,"1000"
,"1100"
,"1110"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int rowCount = 3; 
	int columnCount = 2; 
	int _ = 3; 
END
CASE(2)
	string A_[] = {"01"
,"10"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int rowCount = 1; 
	int columnCount = 1; 
	int _ = 1; 
END
CASE(3)
	string A_[] = {"1110"
,"0001"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int rowCount = 0; 
	int columnCount = 0; 
	int _ = 0; 
END
CASE(4)
	string A_[] = {"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int rowCount = 2; 
	int columnCount = 3; 
	int _ = 8; 
END
CASE(5)
	string A_[] = {"000000000000"
,"011101110111"
,"010001010101"
,"010001010101"
,"011101010101"
,"010101010101"
,"010101010101"
,"011101110111"
,"000000000000"
,"000000000000"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int rowCount = 5; 
	int columnCount = 9; 
	int _ = 14; 
END
CASE(6)
	string A_[] = {"11111101001110"
,"11000111111111"
,"00010101111001"
,"10110000111111"
,"10000011010010"
,"10001101101101"
,"00101010000001"
,"10111010100100"
,"11010011110111"
,"11100010110110"
,"00100101010100"
,"01001011001000"
,"01010001111010"
,"10100000010011"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int rowCount = 6; 
	int columnCount = 8; 
	int _ = 31; 
END
#if 0  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10;loop++) {
// param type: String
start_time=clock();
	vector <string> A; 
	{
		int N=UNIFORM_LL(1, 50);
		A = vector <string>(N); 
		REP(i, N) {
			A[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
start_time=clock();
	int rowCount = UNIFORM_LL(0, 100); 
// param type: int
start_time=clock();
	int columnCount = UNIFORM_LL(0, 100); 
	int _0 = PalindromeMatrix().minChange(A, rowCount, columnCount);
	int _1 = PalindromeMatrixTry().minChange(A, rowCount, columnCount);
	if(!verify_case(_0, _1, true)) {
print(A);
print(rowCount);
print(columnCount);
	}
}
#endif

}
// END CUT HERE
