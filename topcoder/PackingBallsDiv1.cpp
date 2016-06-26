// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// We have balls of K different colors.
The colors are numbered 0 through K-1, and the number of balls of color i is X[i].
We want to divide the balls into as few packages as possible.
Each package must contain between 1 and K balls, inclusive.
Additionally, each package must be either a "normal set" (all balls in the package have the same color), or a "variety set" (no two balls have the same color).

You are given the int K.
You are also given ints A, B, C, and D.
Use these to generate the array X using the following pseudocode:

X[0] = A
for i = 1 to K-1:
    X[i] = (X[i-1] * B + C) % D + 1


Compute and return the smallest possible number of packages.

DEFINITION
Class:PackingBallsDiv1
Method:minPacks
Parameters:int, int, int, int, int
Returns:int
Method signature:int minPacks(int K, int A, int B, int C, int D)


NOTES
-You can assume that the answer will fit into a signed 32-bit integer.


CONSTRAINTS
-K will be between 1 and 100,000, inclusive.
-B, C and D will be between 1 and 1,000,000,000, inclusive.
-A will be between 1 and D, inclusive.


EXAMPLES

0)
3
4
2
5
6

Returns: 4

There are three colors of balls.
Using the pseudocode in the problem statement, we can compute that X[0]=4, X[1]=2, and X[2]=4.
As there are 10 balls and we can only put at most 3 into each package, we need at least 4 packages.
One possible solution with 4 packages is {0,1,2}, {0,0}, {0,1}, and {2,2,2}.
(That is, the first package contains one ball of each color, the second package contains two balls of color 0, and so on.)

1)
1
58
23
39
93

Returns: 58

All the balls have the same color, and each package can only contain one ball. Thus, the number of packages is the same as the number of balls.

2)
23
10988
5573
4384
100007

Returns: 47743



3)
100000
123456789
234567890
345678901
1000000000

Returns: 331988732

Watch out for integer overflow when generating X.

******************************/
// END CUT HERE
#line 92 "PackingBallsDiv1.cpp"
#include <vector>
#include <map>
#include <list>
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

class PackingBallsDiv1Try {
	public:
	int minPacks(int K, int A, int B, int C, int D) {
		ll ansW = 0, X;
		VI R(K), sumR(K);
		X = A;
		ansW += X / K;
		R[X % K]++;
		RANGE(i, 1, K) {
			X = (X * B + C) % D + 1;
			ansW += X / K;
			R[X % K]++;
		}
		for(int i=K-2;i>=0;i--) sumR[i]=sumR[i+1]+R[i+1];
		ll ans = 1LL<<60;
		REP(i, K) {
			ans = min(ans, ansW + i + sumR[i]);
		}
		return ans;
	}
};

class PackingBallsDiv1 {
	public:
	int minPacks(int K, int A, int B, int C, int D) {
		VI v;
		v.PB(A);
		ll X = A;
		RANGE(i, 1, K) {
			X = (X * B + C) % D + 1;
			v.PB(X);
		}
		ll ans=0;
		REP(i, v.size()) {
			ans+=v[i]/K;
			v[i]%=K;
		}
		sort(ALL(v));
		list<ll> l(ALL(v));
		ll off=0;
		while(l.size() && l.back()-off>0) {
			if(l.back()-off>l.size()) {
				ans++;
				l.pop_back();
			} else {
				ans+=l.front()-off;
				off+=l.front()-off;
				l.pop_front();
			}
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK = true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, PackingBallsDiv1().minPacks(K, A, B, C, D));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int K = 3; 
	int A = 4; 
	int B = 2; 
	int C = 5; 
	int D = 6; 
	int _ = 4; 
END
CASE(1)
	int K = 1; 
	int A = 58; 
	int B = 23; 
	int C = 39; 
	int D = 93; 
	int _ = 58; 
END
CASE(2)
	int K = 23; 
	int A = 10988; 
	int B = 5573; 
	int C = 4384; 
	int D = 100007; 
	int _ = 47743; 
END
//return 0;
CASE(3)
	int K = 100000; 
	int A = 123456789; 
	int B = 234567890; 
	int C = 345678901; 
	int D = 1000000000; 
	int _ = 331988732; 
END
#if 01  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
if(!allOK) return 0;

srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: int
start_time=clock();
	int K = UNIFORM_LL(0, 100000); 
// param type: int
start_time=clock();
	int A = UNIFORM_LL(0, 1000000000); 
// param type: int
start_time=clock();
	int B = UNIFORM_LL(0, 1000000000); 
// param type: int
start_time=clock();
	int C = UNIFORM_LL(0, 1000000000); 
// param type: int
start_time=clock();
	int D = UNIFORM_LL(0, 1000000000); 
	int _0 = PackingBallsDiv1().minPacks(K, A, B, C, D);
	int _1 = PackingBallsDiv1Try().minPacks(K, A, B, C, D);
	if(!verify_case(_0, _1, true)) {
print(K);
print(A);
print(B);
print(C);
print(D);
	}
}
#endif

}
// END CUT HERE
