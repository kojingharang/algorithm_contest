// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// TopCoder admin mystic_tc is sitting in front of a table. He found N sealed boxes of candies on the table.


He is not sure how many candies each box contains. However, he knows the following information:

The total number of candies in the boxes is C.
For each i, box i (0-based index) contains between low[i] and high[i] candies, inclusive.


You know that mystic_tc eats candies as follows: first he chooses a subset of the boxes, then he opens them and eats all the candies he found inside.
He wants to eat at least X candies.
And as he is smart, he will always choose a subset of boxes for which he is sure that they must contain at least X candies.


You are given the ints C and X, and the vector <int>s low and high.
Return the smallest number of boxes mystic_tc may choose.

DEFINITION
Class:MysticAndCandies
Method:minBoxes
Parameters:int, int, vector <int>, vector <int>
Returns:int
Method signature:int minBoxes(int C, int X, vector <int> low, vector <int> high)


CONSTRAINTS
-low and high will contain between 1 and 50 elements, inclusive.
-low and high will contain the same number of elements.
-Each element of low and high will be between 1 and 10,000,000, inclusive.
-For each i, high[i] will be greater than or equal to low[i].
-C will be between the sum of all elements of low and the sum of all elements of high, inclusive.
-X will be between 1 and C, inclusive.


EXAMPLES

0)
15
12
{1, 2, 3, 4, 5}
{1, 2, 3, 4, 5}

Returns: 3

Here he knows the exact number of candies in each box.
The best strategy is to open boxes 2, 3, and 4 (0-based indices).
This way he will get 3+4+5 = exactly 12 candies.

1)
60
8
{5, 2, 3}
{49, 48, 47}

Returns: 2

Open box 0 and box 2.

2)
58
30
{3, 9, 12, 6, 15}
{8, 12, 20, 8, 15}

Returns: 2

Open box 2 and box 4.

3)
207581165
172146543
{4725448, 2753824, 6019698, 4199708, 4070001, 3589497, 5358499, 3637585, 5393667, 2837466,
2747807, 2918199, 3638042, 5199002, 3072044, 3858909, 3762101, 3657754, 3218704, 3888861,
3195689, 4768935, 3137633, 4124272, 4125056, 6087486, 3632970, 3620489, 2748765, 5917493,
3958996, 3335021, 3517186, 5543440, 2951006, 3403270, 3299481, 3093204, 4092331}
{5702812, 6805664, 6823687, 5337687, 4286533, 4999849, 6567411, 4563235, 6618139, 6260135,
6249469, 3821449, 5963157, 6385012, 4255959, 5786920, 6112817, 4103918, 6371537, 4231698,
3409172, 6806782, 5623563, 4511221, 6407338, 6491490, 5209517, 6076093, 6530132, 6111464,
5833839, 6253088, 5595160, 6236805, 5772388, 5285713, 5617002, 4650978, 5234740}

Returns: 31



4)
43873566
32789748
{2053198, 2175819, 4260803, 1542497, 1418952, 5000015, 1381849, 2462882, 6466891, 1827580, 6943641, 5775477}
{2827461, 3726335, 5410505, 4781355, 4925909, 5621160, 7325774, 5025476, 7876037, 8072075, 6979462, 6647628}

Returns: 7



******************************/
// END CUT HERE
#line 101 "MysticAndCandies.cpp"
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

class MysticAndCandies {
	public:
	int minBoxes(int C, int X, vector <int> L, vector <int> H) {
		int N=L.size();
	}
};

class MysticAndCandiesTry {
	public:
	int minBoxes(int C, int X, vector <int> low, vector <int> high) {
		int N=low.size();
		int ans = N;
		sort(ALLR(low));
		sort(ALL(high));
		int smax=C, smin=0;
		REP(i, N) {
			smax-=high[i];
			smin+=low[i];
			if(smax>=X) ans=min(ans, N-(i+1));
			if(smin>=X) ans=min(ans, i+1);
		}
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
#define END	 verify_case(_, MysticAndCandies().minBoxes(C, X, low, high));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int C = 15; 
	int X = 6; 
	int low_[] = {1,1,1};
	  vector <int> low(low_, low_+sizeof(low_)/sizeof(*low_)); 
	int high_[] = {5,5,5};
	  vector <int> high(high_, high_+sizeof(high_)/sizeof(*high_)); 
	int _ = 1; 
END
CASE(0)
	int C = 15; 
	int X = 12; 
	int low_[] = {1, 2, 3, 4, 5};
	  vector <int> low(low_, low_+sizeof(low_)/sizeof(*low_)); 
	int high_[] = {1, 2, 3, 4, 5};
	  vector <int> high(high_, high_+sizeof(high_)/sizeof(*high_)); 
	int _ = 3; 
END
CASE(1)
	int C = 60; 
	int X = 8; 
	int low_[] = {5, 2, 3};
	  vector <int> low(low_, low_+sizeof(low_)/sizeof(*low_)); 
	int high_[] = {49, 48, 47};
	  vector <int> high(high_, high_+sizeof(high_)/sizeof(*high_)); 
	int _ = 2; 
END
CASE(2)
	int C = 58; 
	int X = 30; 
	int low_[] = {3, 9, 12, 6, 15};
	  vector <int> low(low_, low_+sizeof(low_)/sizeof(*low_)); 
	int high_[] = {8, 12, 20, 8, 15};
	  vector <int> high(high_, high_+sizeof(high_)/sizeof(*high_)); 
	int _ = 2; 
END
CASE(3)
	int C = 207581165; 
	int X = 172146543; 
	int low_[] = {4725448, 2753824, 6019698, 4199708, 4070001, 3589497, 5358499, 3637585, 5393667, 2837466,
2747807, 2918199, 3638042, 5199002, 3072044, 3858909, 3762101, 3657754, 3218704, 3888861,
3195689, 4768935, 3137633, 4124272, 4125056, 6087486, 3632970, 3620489, 2748765, 5917493,
3958996, 3335021, 3517186, 5543440, 2951006, 3403270, 3299481, 3093204, 4092331};
	  vector <int> low(low_, low_+sizeof(low_)/sizeof(*low_)); 
	int high_[] = {5702812, 6805664, 6823687, 5337687, 4286533, 4999849, 6567411, 4563235, 6618139, 6260135,
6249469, 3821449, 5963157, 6385012, 4255959, 5786920, 6112817, 4103918, 6371537, 4231698,
3409172, 6806782, 5623563, 4511221, 6407338, 6491490, 5209517, 6076093, 6530132, 6111464,
5833839, 6253088, 5595160, 6236805, 5772388, 5285713, 5617002, 4650978, 5234740};
	  vector <int> high(high_, high_+sizeof(high_)/sizeof(*high_)); 
	int _ = 31; 
END
CASE(4)
	int C = 43873566; 
	int X = 32789748; 
	int low_[] = {2053198, 2175819, 4260803, 1542497, 1418952, 5000015, 1381849, 2462882, 6466891, 1827580, 6943641, 5775477};
	  vector <int> low(low_, low_+sizeof(low_)/sizeof(*low_)); 
	int high_[] = {2827461, 3726335, 5410505, 4781355, 4925909, 5621160, 7325774, 5025476, 7876037, 8072075, 6979462, 6647628};
	  vector <int> high(high_, high_+sizeof(high_)/sizeof(*high_)); 
	int _ = 7; 
END
#if 0  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10;loop++) {
// param type: int
start_time=clock();
	int C = UNIFORM_LL(0, 100); 
// param type: int
start_time=clock();
	int X = UNIFORM_LL(0, 100); 
// param type: int
start_time=clock();
	vector <int> low; 
	{
		int N=UNIFORM_LL(1, 50);
		low = vector <int>(N); 
		REP(i, N) {
			low[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
start_time=clock();
	vector <int> high; 
	{
		int N=UNIFORM_LL(1, 50);
		high = vector <int>(N); 
		REP(i, N) {
			high[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = MysticAndCandies().minBoxes(C, X, low, high);
	int _1 = MysticAndCandiesTry().minBoxes(C, X, low, high);
	if(!verify_case(_0, _1, true)) {
print(C);
print(X);
print(low);
print(high);
	}
}
#endif

}
// END CUT HERE
