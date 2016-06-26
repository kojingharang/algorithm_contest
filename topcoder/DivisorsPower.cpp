// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Halina is a young mathematician.
Recently she has been studying an interesting function h that operates on positive integers.

Let d(n) be the number of distinct positive divisors of n.
The function h is then defined as follows: for each n we have h(n) = n^d(n).
In words, h(n) is defined as n to the power of d(n).

For example, d(6)=4 because 6 is divisible by 1, 2, 3, and 6.
Then, h(6) = 6^4 = 1296.

Halina already knows how to compute her function h.
Now she would like to compute the inverse function.
Help her!

You are given a long long n.
Return the smallest x such that h(x) = n.
If there is no such x, return -1 instead.

DEFINITION
Class:DivisorsPower
Method:findArgument
Parameters:long long
Returns:long long
Method signature:long long findArgument(long long n)


CONSTRAINTS
-n will be between 2 and 10^18, inclusive.


EXAMPLES

0)
4

Returns: 2

d(2) = 2, h(2) = 4

1)
10

Returns: -1

There is no x satisfying h(x) = 10.

2)
64

Returns: 4

d(4) = 3, h(4) = 64

3)
10000

Returns: 10

d(10) = 4, h(10) = 10000

4)
2498388559757689

Returns: 49983883



******************************/
// END CUT HERE
#line 74 "DivisorsPower.cpp"
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


ll dd(ll N) {
	ll co=0;
	for(ll d=1; d*d<=N; d++) {
		if(N%d==0) {
			REP(loop, 2) {
				co++;
				if(d==N/d) break;
			}
		}
	}
	return co;
}

ll di(ll n, ll x) {
	ll v=0;
	while(n>1) {
		if(n%x) return -1;
		n/=x;
		v++;
	}
	return n==1 ? v : -1;
}

class DivisorsPower {
	public:
	long long findArgument(long long n) {
		if(n==1) return 1;
		double dn = n;
		for(int m=100;m>1;m--) {
			ll xx = (ll)pow(dn, 1.0/m);
			for(ll x = max(2LL, xx-2); x<=xx+2; x++) {
//				cout<<x<<" "<<m<<endl;
				ll xd = dd(x);
				if(di(n, x)==xd) {
					return x;
				}
			}
		}
		return -1;
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
#define END	 verify_case(_, DivisorsPower().findArgument(n));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

//CASE(2)
//	long long n = 64LL; 
//	long long _ = 4LL; 
//END
//return 0;
CASE(0)
	long long n = 4LL; 
	long long _ = 2LL; 
END
CASE(1)
	long long n = 10LL; 
	long long _ = -1LL; 
END
CASE(2)
	long long n = 64LL; 
	long long _ = 4LL; 
END
CASE(3)
	long long n = 10000LL; 
	long long _ = 10LL; 
END
CASE(4)
	long long n = 2498388559757689LL; 
	long long _ = 49983883LL; 
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
	long long n = UNIFORM_LL(0, 100); 
	long long _0 = DivisorsPower().findArgument(n);
	long long _1 = DivisorsPowerRef().findArgument(n);
	if(!verify_case(_0, _1, true)) {
print(n);
	}
}
#endif

}
// END CUT HERE
