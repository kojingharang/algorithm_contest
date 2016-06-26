// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
In this problem we deal with binary representations of integers.
For clarity, decimal numbers will be given as numbers and their binary representations as strings.
For example, the binary representation of 47 is "101111".





Additionally, in the entire problem statement, k is a positive integer constant.
(The value of k will be given to you as one of the inputs.)





Let A be a positive integer.
Consider the following process:

Find the string S that is the binary representation of A.
Let L = max( 1, length(S)-k ).
Let T be any (not necessarily contiguous) subsequence of S such that the length of T is between 1 and L, inclusive.
Convert T to decimal and output the result.




Each integer B that can be the result of the above process is called a binary substring of A.
Note that S never starts with a leading zero, but T might.
Some examples are shown below.



Let A = 10 and k = 1.
  
  We convert A to S = "1010".
  Then we compute that L = 3, which means that we are interested in subsequences of length at most 3.
  Hence, T is one of "0", "1", "00", "01", "10", "11", "010", "100", "101", or "110".
  This means that the binary substrings of A are 0, 1, 2, 3, 4, 5, and 6.
  


Let A = 10 and k = 2.
Now we have L = 2, which means that the possible values of T are "0", "1", "00", "01", "10", and "11".
Thus, the binary substrings of A are 0, 1, 2, and 3.


For A = 10 and k >= 3 the only binary substrings of A are the integers 0 and 1.


For A = 15 and k = 1 the binary substrings of A are the integers 1, 3, and 7.





You are given the int k.
You are also given long longs x and y.
Consider the integers between 1 and x, inclusive, such that their largest binary substring is smaller than or equal to y.





Compute and return the number of such integers.


DEFINITION
Class:PrimeStrings
Method:getCount
Parameters:long long, long long, int
Returns:long long
Method signature:long long getCount(long long x, long long y, int k)


CONSTRAINTS
-x will be between 1 and 1012, both inclusive.
-y will be between 1 and 1012, both inclusive.
-k will be between 1 and 40, both inclusive.


EXAMPLES

0)
2
1
1

Returns: 2

Given that k=1, the only binary substring of 1 is 1, and the binary substrings of 2 are 0 and 1.
In both cases, the largest binary substring is less than or equal to y=1.
Thus, the answer is 2.


1)
6
2
1

Returns: 4

As x=6, we are interested in the numbers between 1 and 6, inclusive.
For k=1, the largest binary substrings of 1, 2, 3, 4, 5, and 6 are 1, 1, 1, 2, 3, and 3, respectively.
As we only count those for which the largest binary substring does not exceed 2, the answer is 4.



2)
6
1
3

Returns: 6



3)
31
6
2

Returns: 20



4)
413
34
2

Returns: 130



5)
1000000000
1000000000
5

Returns: 1000000000



6)
549755813602
8369864093
5

Returns: 178429547459



******************************/
// END CUT HERE
#line 160 "PrimeStrings.cpp"
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
#define ull unsigned long long
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
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, I, J) REP(i, I) { REP(j, J) cout<<table[i][j]<<" "; cout<<"\n"; }
#define PRINT3(table, I, J, K) REP(i, I) { REP(j, J) { REP(k, K) cout<<table[i][j][k]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<(v)<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class PrimeStrings {
	public:
	long long getCount(long long x, long long y, int k) {
		
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
#define END	 verify_case(_, PrimeStrings().getCount(x, y, k));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	long long x = 2LL; 
	long long y = 1LL; 
	int k = 1; 
	long long _ = 2LL; 
END
CASE(1)
	long long x = 6LL; 
	long long y = 2LL; 
	int k = 1; 
	long long _ = 4LL; 
END
CASE(2)
	long long x = 6LL; 
	long long y = 1LL; 
	int k = 3; 
	long long _ = 6LL; 
END
CASE(3)
	long long x = 31LL; 
	long long y = 6LL; 
	int k = 2; 
	long long _ = 20LL; 
END
CASE(4)
	long long x = 413LL; 
	long long y = 34LL; 
	int k = 2; 
	long long _ = 130LL; 
END
CASE(5)
	long long x = 1000000000LL; 
	long long y = 1000000000LL; 
	int k = 5; 
	long long _ = 1000000000LL; 
END
CASE(6)
	long long x = 549755813602LL; 
	long long y = 8369864093LL; 
	int k = 5; 
	long long _ = 178429547459LL; 
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
// param type: long
	long long x = UNIFORM_LL(0, 100); 
// param type: long
	long long y = UNIFORM_LL(0, 100); 
// param type: int
	int k = UNIFORM_LL(0, 100); 
	long long _0 = PrimeStrings().getCount(x, y, k);
	long long _1 = PrimeStringsRef().getCount(x, y, k);
	if(!verify_case(_0, _1, true)) {
print(x);
print(y);
print(k);
	}
}
#endif

}
// END CUT HERE
