// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// You have a lot of candles.
The candles burn at a uniform rate: if you ignite a candle of length L, it will burn completely in L units of time.
You can also ignite a candle at both ends, which makes it burn twice as fast.



You have arranged some candles into the shape of a tree.
You want to use the tree to measure time.
At the beginning, you will ingite some leaves of the tree (all at the same time).
Then you will just wait and watch the flames spread across the entire tree.
(Whenever a flame reaches an inner node of the tree, it spreads to all branches that meet at that node.)
Note that you are not allowed to light new flames during the process.
The time you will measure is the time between the moment when you lighted the fire(s) and the moment when the last part of the tree finished burning.



You are given a description of the tree as three vector <int>s: a, b, and len, with N elements each.
The nodes of the tree are numbered 0 through N, inclusive.
For each valid i, there is a candle between the nodes a[i] and b[i] with length len[i].



Let X be the number of different times you can measure when following the above procedure.
Compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:CandleTimer
Method:differentTime
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int differentTime(vector <int> A, vector <int> B, vector <int> len)


CONSTRAINTS
-A will contain between 1 and 200 elements, inclusive.
-A, B and len will contain same number of elements.
-Each element in A will be between 0 and |A|, inclusive.
-Each element in B will be between 0 and |A|, inclusive.
-Each element in len will be between 1 and 1000, inclusive.
-A, B and len will describe a tree.


EXAMPLES

0)
{0,1}
{1,2}
{10,1}

Returns: 2

This tree looks the same as a single candle of length 11. If we light it on one end, we will measure the time 11. If we light it on both ends, we will measure the time 5.5.

1)
{0,0,0}
{1,2,3}
{1,1,1}

Returns: 2

This time we have 3 ends. If we ignite all of them the time is 1, otherwise the time is 2.


2)
{0,0,0}
{1,2,3}
{1,2,3}

Returns: 4

We can get 4 different outcomes: 2.5, 3, 4, 5.

3)
{0,1,1,2,3,3,2,4}
{1,2,3,4,5,6,7,8}
{5,3,2,4,6,8,7,1}

Returns: 7



4)
{0,0,0,0}
{1,2,3,4}
{123,456,789,1000}

Returns: 8



5)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30}
{0,1,2,0,0,0,1,0,0,0,2,5,4,7,13,13,6,15,11,18,19,21,22,16,19,19,20,18,22,27}
{59,58,147,169,34,14,150,55,156,151,130,109,124,15,100,1,156,16,38,97,99,132,150,18,27,91,110,127,15,105}

Returns: 65



6)
{0}
{1}
{1000}

Returns: 2



******************************/
// END CUT HERE
#line 115 "CandleTimer.cpp"
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

class CandleTimer {
	public:
	int differentTime(vector <int> A, vector <int> B, vector <int> len) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, CandleTimer().differentTime(A, B, len));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int A_[] = {0,1};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {1,2};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int len_[] = {10,1};
	  vector <int> len(len_, len_+sizeof(len_)/sizeof(*len_)); 
	int _ = 2; 
END
CASE(1)
	int A_[] = {0,0,0};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {1,2,3};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int len_[] = {1,1,1};
	  vector <int> len(len_, len_+sizeof(len_)/sizeof(*len_)); 
	int _ = 2; 
END
CASE(2)
	int A_[] = {0,0,0};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {1,2,3};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int len_[] = {1,2,3};
	  vector <int> len(len_, len_+sizeof(len_)/sizeof(*len_)); 
	int _ = 4; 
END
CASE(3)
	int A_[] = {0,1,1,2,3,3,2,4};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {1,2,3,4,5,6,7,8};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int len_[] = {5,3,2,4,6,8,7,1};
	  vector <int> len(len_, len_+sizeof(len_)/sizeof(*len_)); 
	int _ = 7; 
END
CASE(4)
	int A_[] = {0,0,0,0};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {1,2,3,4};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int len_[] = {123,456,789,1000};
	  vector <int> len(len_, len_+sizeof(len_)/sizeof(*len_)); 
	int _ = 8; 
END
CASE(5)
	int A_[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {0,1,2,0,0,0,1,0,0,0,2,5,4,7,13,13,6,15,11,18,19,21,22,16,19,19,20,18,22,27};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int len_[] = {59,58,147,169,34,14,150,55,156,151,130,109,124,15,100,1,156,16,38,97,99,132,150,18,27,91,110,127,15,105};
	  vector <int> len(len_, len_+sizeof(len_)/sizeof(*len_)); 
	int _ = 65; 
END
CASE(6)
	int A_[] = {0};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {1};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int len_[] = {1000};
	  vector <int> len(len_, len_+sizeof(len_)/sizeof(*len_)); 
	int _ = 2; 
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
	vector <int> A; 
	{
		int N=UNIFORM_LL(1, 51);
		A = vector <int>(N); 
		REP(i, N) {
			A[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> B; 
	{
		int N=UNIFORM_LL(1, 51);
		B = vector <int>(N); 
		REP(i, N) {
			B[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> len; 
	{
		int N=UNIFORM_LL(1, 51);
		len = vector <int>(N); 
		REP(i, N) {
			len[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = CandleTimer().differentTime(A, B, len);
	int _1 = CandleTimerRef().differentTime(A, B, len);
	if(!verify_case(_0, _1, true)) {
print(A);
print(B);
print(len);
	}
}
#endif

}
// END CUT HERE
