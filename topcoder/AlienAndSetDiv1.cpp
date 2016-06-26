// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Alien Fred wants to destroy the Earth.
But before he does that, he wants to solve the following problem.




He has the set {1, 2, 3, ..., 2N}.
He wants to split this set into two new sets A and B.
The following conditions must all be satisfied:

Each element of the original set must belong to exactly one of the sets A and B.
The two new sets must have the same size. (I.e., each of them must contain exactly N numbers.)
For each i from 1 to N, inclusive: 
    Let A[i] be the i-th smallest element of A, and let B[i] be the i-th smallest element of B.
    The difference |A[i] - B[i]| must be greater than or equal to K.





You are given the two ints N and K.
Let X be the total number of ways in which Fred can choose the sets A and B.
Return the value (X modulo 1,000,000,007).


DEFINITION
Class:AlienAndSetDiv1
Method:getNumber
Parameters:int, int
Returns:int
Method signature:int getNumber(int N, int K)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-K will be between 1 and 10, inclusive.


EXAMPLES

0)
2
2

Returns: 2

The initial set is {1, 2, 3, 4}.
The following 6 pairs of subsets are possible in this case:


A={1, 2} and B={3, 4}


A={1, 3} and B={2, 4}


A={1, 4} and B={2, 3}


A={2, 3} and B={1, 4}


A={2, 4} and B={1, 3}


A={3, 4} and B={1, 2}


The first option and the last option are both valid.
The other 4 options are invalid.


Note that order of the two sets matters: the option A={1,2} and B={3,4} differs from the option A={3,4} and B={1,2}.

1)
3
1

Returns: 20



2)
4
2

Returns: 14



3)
10
7

Returns: 40



******************************/
// END CUT HERE
#line 106 "AlienAndSetDiv1.cpp"
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

class AlienAndSetDiv1 {
	public:
	int getNumber(int N, int K) {
		VVI w(2*N+1, VI(2*N+1));
		w[0][1] = 1;
		REP(i, 2*N+1) {
			// iまで置いててi+1をおきたい
			REP(j, 2*N+1) {
				if(abs(i+1-j)<K) {
					w[i+1]w[i][j]
				}
			}
		}
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
#define END	 verify_case(_, AlienAndSetDiv1().getNumber(N, K));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int N = 2; 
	int K = 2; 
	int _ = 2; 
END
CASE(1)
	int N = 3; 
	int K = 1; 
	int _ = 20; 
END
CASE(2)
	int N = 4; 
	int K = 2; 
	int _ = 14; 
END
CASE(3)
	int N = 10; 
	int K = 7; 
	int _ = 40; 
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
	int N = UNIFORM_LL(0, 100); 
// param type: int
start_time=clock();
	int K = UNIFORM_LL(0, 100); 
	int _0 = AlienAndSetDiv1().getNumber(N, K);
	int _1 = AlienAndSetDiv1Try().getNumber(N, K);
	if(!verify_case(_0, _1, true)) {
print(N);
print(K);
	}
}
#endif

}
// END CUT HERE
