// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Consider the integers between low and high, inclusive.
We are going to select a sequence of N integers from this range.
The sequence is allowed to contain repeated elements, hence there are (high-low+1)^N possible sequences (where '^' denotes exponentiation).

Out of those sequences, we are only interested in the ones that have one additional property:
the greatest common divisor (GCD) of their elements must be exactly K.

You are given the ints N, K, low, and high.
Let X be the number of N-tuples described above.
Because X can be very large, compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:RandomGCD
Method:countTuples
Parameters:int, int, int, int
Returns:int
Method signature:int countTuples(int N, int K, int low, int high)


NOTES
-The greatest common divisor of a sequence is the largest positive integer that divides each element of the sequence.


CONSTRAINTS
-N, K and low will each be between 1 and 1,000,000,000, inclusive.
-high will be between low and 1,000,000,000, inclusive.
-The difference high - low will be less than or equal to 100,000.


EXAMPLES

0)
2
2
2
4

Returns: 3

There are 9 possible sequences: {(2, 2), (2, 3), (2, 4), (3, 2), (3, 3), (3, 4), (4, 2), (4, 3), (4, 4)}.
Out of these, 3 of them have the requested gcd of 2: {(2, 2), (2, 4), (4, 2)}.
Hence, the answer is 3.

1)
2
100
2
4

Returns: 0

Sometimes no combinations yield the requested GCD.

2)
1
5
5
5

Returns: 1

Sometimes you select only one number.

3)
73824
17347
9293482
9313482

Returns: 0



4)
222
222
222
22222

Returns: 339886855



******************************/
// END CUT HERE
#line 90 "RandomGCD.cpp"
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



class RandomGCD {
	public:
	int countTuples(int N, int K, int low, int high) {
		int oknum = 0;
		RANGE(i, low, high+1) {
			cout<<"try "<<i<<endl;
			if(K<=i && i%K==0) oknum++;
		}
		cout<<oknum<<endl;
		ll ans = 1;
		REP(i, N) ans *= oknum;
		return ans;
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
#define END	 verify_case(_, RandomGCD().countTuples(N, K, low, high));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int N = 2; 
	int K = 2; 
	int low = 2; 
	int high = 4; 
	int _ = 3; 
END
return 0;
CASE(1)
	int N = 2; 
	int K = 100; 
	int low = 2; 
	int high = 4; 
	int _ = 0; 
END
CASE(2)
	int N = 1; 
	int K = 5; 
	int low = 5; 
	int high = 5; 
	int _ = 1; 
END
CASE(3)
	int N = 73824; 
	int K = 17347; 
	int low = 9293482; 
	int high = 9313482; 
	int _ = 0; 
END
CASE(4)
	int N = 222; 
	int K = 222; 
	int low = 222; 
	int high = 22222; 
	int _ = 339886855; 
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
	int N = UNIFORM_LL(0, 100); 
// param type: int
	int K = UNIFORM_LL(0, 100); 
// param type: int
	int low = UNIFORM_LL(0, 100); 
// param type: int
	int high = UNIFORM_LL(0, 100); 
	int _0 = RandomGCD().countTuples(N, K, low, high);
	int _1 = RandomGCDRef().countTuples(N, K, low, high);
	if(!verify_case(_0, _1, true)) {
print(N);
print(K);
print(low);
print(high);
	}
}
#endif

}
// END CUT HERE
