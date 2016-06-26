// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel learned a new skill of splitting! She can split into (S + L + R) foxes each time.
Now she is practicing this skill on an infinite horizontal plane. At the beginning, Fox Ciel is the only fox on the plane.
She stands at the point (0,0) and she is facing the point (1,0).



There will be n steps.
In each step, each fox on the plane will split into exactly (S + L + R) foxes.
Out of those foxes:

S will make a step forward, moving exactly one unit of distance in the direction they are facing.
L will stay in the same place and rotate 90 degrees to the left. (So for example if the original fox was facing the point (1,0), there will be L new foxes facing the point (0,1).)
R will stay in the same place and rotate 90 degrees to the right.

The score of a fox standing at the point (x,y) is x*y. Note that the score of a fox may be zero or even negative. The total score is the sum of the scores of all foxes on the plane.
You are given the long long n and the ints S, L, and R. Return the total score of all foxes after n steps, modulo 1,000,000,007 (10^9 + 7).

DEFINITION
Class:SplittingFoxes
Method:sum
Parameters:long long, int, int, int
Returns:int
Method signature:int sum(long long n, int S, int L, int R)


NOTES
-Note that you should return a number between 0 and 1,000,000,006, inclusive.
-E.g., if the answer is -1, you should return 1,000,000,006 instead of -1.


CONSTRAINTS
-n will be between 1 and 10^18, inclusive.
-S will be between 0 and 10^9, inclusive.
-L will be between 0 and 10^9, inclusive.
-R will be between 0 and 10^9, inclusive.


EXAMPLES

0)
58
2
0
0

Returns: 0


After step 1: there are 2^1 foxes at (1, 0),
After step 2: there are 2^2 foxes at (2, 0),
...
After step 58: there are 2^58 foxes at (58, 0).

For each fox at (58, 0), her score is 58 * 0 = 0, so the answer is 0.



1)
3
1
1
0

Returns: 1

There will be 8 foxes at the end. The fox at (1,1) has score 1. Each of the other 7 foxes has score 0.

2)
5
1
3
2

Returns: 34



3)
5
1
2
3

Returns: 999999973

The answer is (-34) % 1,000,000,007.

4)
123456789
987654321
544
544

Returns: 0

By symmetry, if L = R, then the answer will be zero.

5)
65536
1024
512
4096

Returns: 371473914



*/
// END CUT HERE
#line 114 "SplittingFoxes.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
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
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class SplittingFoxes {
	public:
	int sum(long long n, int S, int L, int R) {
		map<pair<pair<ll, ll>, ll>, ll> cur;
		cur[MP(MP(0, 0), 0)]=1;
		int dx={1,0,-1,0};
		int dy={0,-1,0,1};
		REP(i, n) {
			map<pair< <pair<ll, ll> >, ll> nxt;
			FOR(e, cur) {
				ll x = e->first.first.first;
				ll y = e->first.first.secnond;
				ll d = e->first.second;
				ll co = e->second;
				nxt[MP(MP(x+dx[d], y+dy[d]), d)] = e->second * S;
				nxt[MP(MP(x, y), (d+1)%4)] = e->second * S;
			}
		}
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
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, SplittingFoxes().sum(n, S, L, R));}
int main(){

CASE(0)
	long long n = 58LL; 
	int S = 2; 
	int L = 0; 
	int R = 0; 
	int _ = 0; 
END
CASE(1)
	long long n = 3LL; 
	int S = 1; 
	int L = 1; 
	int R = 0; 
	int _ = 1; 
END
CASE(2)
	long long n = 5LL; 
	int S = 1; 
	int L = 3; 
	int R = 2; 
	int _ = 34; 
END
CASE(3)
	long long n = 5LL; 
	int S = 1; 
	int L = 2; 
	int R = 3; 
	int _ = 999999973; 
END
CASE(4)
	long long n = 123456789LL; 
	int S = 987654321; 
	int L = 544; 
	int R = 544; 
	int _ = 0; 
END
CASE(5)
	long long n = 65536LL; 
	int S = 1024; 
	int L = 512; 
	int R = 4096; 
	int _ = 371473914; 
END

}
// END CUT HERE
