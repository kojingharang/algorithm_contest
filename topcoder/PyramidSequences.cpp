// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// A pyramid sequence of height X > 1 is an infinite sequence of positive integers with period 2X-2. Its first 2X-2 terms are 1, 2, ..., X-1, X, X-1, ..., 2.

You are given ints N and M. Consider two pyramid sequences A and B, A of height N and B of height M. Return the number of distinct pairs of integers (x,y) such that for some i > 0 we have x=A[i] and y=B[i].

DEFINITION
Class:PyramidSequences
Method:distinctPairs
Parameters:int, int
Returns:long long
Method signature:long long distinctPairs(int N, int M)


CONSTRAINTS
-N will be between 2 and 1,000,000,000, inclusive.
-M will be between 2 and 1,000,000,000, inclusive.


EXAMPLES

0)
3
4

Returns: 6

These are the first several terms of pyramid sequences of height 3 and 4:

{1, 2, 3, 2, 1, 2, 3, 2, 1, 2, 3, 2, 1}

{1, 2, 3, 4, 3, 2, 1, 2, 3, 4, 3, 2, 1}

We can see the following pairs: (1, 1), (2, 2), (3, 3), (2, 4), (1, 3), (3, 1). No other pairs will appear later in the sequences.

1)
3
5

Returns: 5

The sequences begin with:

{1, 2, 3, 2, 1, 2, 3, 2, 1}

{1, 2, 3, 4, 5, 4, 3, 2, 1}


2)
43
76

Returns: 895



3)
2
1000000000

Returns: 1000000000



4)
100000
95555

Returns: 4777750000



******************************/
// END CUT HERE
#line 77 "PyramidSequences.cpp"
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

class PyramidSequences {
	public:
	long long distinctPairs(int N, int M) {
		
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
#define END	 verify_case(_, PyramidSequences().distinctPairs(N, M));}
int main(){

CASE(0)
	int N = 3; 
	int M = 4; 
	long long _ = 6LL; 
END
CASE(1)
	int N = 3; 
	int M = 5; 
	long long _ = 5LL; 
END
CASE(2)
	int N = 43; 
	int M = 76; 
	long long _ = 895LL; 
END
CASE(3)
	int N = 2; 
	int M = 1000000000; 
	long long _ = 1000000000LL; 
END
CASE(4)
	int N = 100000; 
	int M = 95555; 
	long long _ = 4777750000LL; 
END

}
// END CUT HERE
