// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// There are N points in the plane. You are given their description as two vector <int>s, x and y, with N elements each. The N points have coordinates (x[0],y[0]), (x[1],y[1]), ..., (x[N-1],y[N-1]).

You want to draw a single square onto the plane. The vertices of the square must have integer coordinates, and the sides of the square must be parallel to the coordinate axes. There is one additional constraint: at least K of the N given points must lie strictly inside the square (i.e., not on its boundary).

You are given x, y, and the int K. Return the smallest possible area of a square that satisfies the constraints above.

DEFINITION
Class:MinimumSquare
Method:minArea
Parameters:vector <int>, vector <int>, int
Returns:long long
Method signature:long long minArea(vector <int> x, vector <int> y, int K)


CONSTRAINTS
-x will contain between 2 and 100 elements, inclusive.
-y will contain the same number of elements as x.
-K will be between 1 and the number of elements in x, inclusive.
-All points will be pairwise distinct.
-Each element of x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-Each element of y will be between -1,000,000,000 and 1,000,000,000, inclusive.


EXAMPLES

0)
{0, 3}
{0, 7}
2

Returns: 81

The square we seek must contain both given points. One optimal solution is the square with opposite corners at (-1,-1) and (8,8).

1)
{-4, 3, 1}
{3 , -1, -2}
2

Returns: 16



2)
{0, 0, 1, 1, 2, 2}
{0, 1, 0, 1, 0, 1}
4

Returns: 9



3)
{1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000}
{1000000000, 0, -1000000000, 1000000000, 0, -1000000000}
3

Returns: 4000000008000000004

In this case one of the optimal solutions is a square that contains all six points.

4)
{-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232}
{-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874}
8

Returns: 1695545329



******************************/
// END CUT HERE
#line 77 "MinimumSquare.cpp"
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class MinimumSquare {
	public:
	long long minArea(vector <int> x, vector <int> y, int K) {
		int N=x.size();
		vector<int> X(x);
//		sort(ALL(X));
		ll ans = 1LL<<60;
		REP(x0, N) REP(x1, N) {
			ll W = abs(X[x0]-X[x1])+2;
			VI Y;
			REP(i, N) if(X[x0]<=x[i] && x[i]<=X[x1]) Y.PB(y[i]);
			sort(ALL(Y));
			int M=Y.size();
			REP(i, Y.size()) {
				if(i+K-1>=M) break;
				ll H = abs(Y[i]-Y[i+K-1])+2;
				ans = min(ans, max(W, H));
			}
		}
		return ans*ans;
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
#define END	 verify_case(_, MinimumSquare().minArea(x, y, K));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int x_[] = {0, 3};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0, 7};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int K = 1; 
	long long _ = 4LL; 
END
CASE(0)
	int x_[] = {0, 3};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0, 7};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int K = 2; 
	long long _ = 81LL; 
END
//return 0;
CASE(1)
	int x_[] = {-4, 3, 1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {3 , -1, -2};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int K = 2; 
	long long _ = 16LL; 
END
//return 0;
CASE(2)
	int x_[] = {0, 0, 1, 1, 2, 2};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0, 1, 0, 1, 0, 1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int K = 4; 
	long long _ = 9LL; 
END
CASE(3)
	int x_[] = {1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {1000000000, 0, -1000000000, 1000000000, 0, -1000000000};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int K = 3; 
	long long _ = 4000000008000000004LL; 
END
CASE(4)
	int x_[] = {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int K = 8; 
	long long _ = 1695545329LL; 
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
// param type: int
	vector <int> x; 
	{
		int N=UNIFORM_LL(1, 51);
		x = vector <int>(N); 
		REP(i, N) {
			x[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> y; 
	{
		int N=UNIFORM_LL(1, 51);
		y = vector <int>(N); 
		REP(i, N) {
			y[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int K = UNIFORM_LL(0, 100); 
	long long _0 = MinimumSquare().minArea(x, y, K);
	long long _1 = MinimumSquareRef().minArea(x, y, K);
	if(!verify_case(_0, _1, true)) {
print(x);
print(y);
print(K);
	}
}
#endif

}
// END CUT HERE
