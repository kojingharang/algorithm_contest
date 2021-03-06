
// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel is learning about exponentiation.
While doing so, she has noticed some cute identities such as 9^3 = 27^2 and 2^10 = 32^2.


You are given an int n.
Fox Ciel is going to write down all identities of the form a^b = c^d where 1 <= a,b,c,d <= n.


Let X be the number of such identities.
Compute and return the value (X modulo (10^9 + 7)).

DEFINITION
Class:PowerEquationEasy
Method:count
Parameters:int
Returns:int
Method signature:int count(int n)


CONSTRAINTS
-n will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
2

Returns: 6

We have these solutions:

1^1=1^1
1^1=1^2
1^2=1^1
1^2=1^2
2^1=2^1
2^2=2^2


1)
3

Returns: 15

Now we have:

1^1=1^1
1^1=1^2
1^1=1^3
1^2=1^1
1^2=1^2
1^2=1^3
1^3=1^1
1^3=1^2
1^3=1^3
2^1=2^1
2^2=2^2
2^3=2^3
3^1=3^1
3^2=3^2
3^3=3^3


2)
100

Returns: 21620



3)
22306

Returns: 68467

The answer is 1000068474 mod 10^9+7.

4)
1

Returns: 1



*/
// END CUT HERE
#line 92 "PowerEquationEasy.cpp"

#include <vector>
#include <map>
#include <set>
#include <stack>
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
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


struct modll {
    static const ll MODVAL;
    ll val;
    modll() : val(0) {}
    modll(ll v) : val(v) { normalize(); }
    void normalize() { val = (val+MODVAL) % MODVAL; }
    modll  operator+ (ll v) { return modll(val+v); }
    modll& operator+=(ll v) { val+=v; normalize(); return *this; }
    modll  operator- (ll v) { return modll(val-v); }
    modll& operator-=(ll v) { val-=v; normalize(); return *this; }
    modll  operator* (ll v) { return modll(val*v); }
    modll& operator*=(ll v) { val*=v; normalize(); return *this; }
    modll  operator^ (ll e) { modll x(val); modll v(1); for(;e;x=x*x,e>>=1) if(e&1) v = v * x; return v; } // pow
    modll inv() { modll x(val); return x^(MODVAL-2); } // MODVAL must be prime number when use this!
    static modll inv(ll v) { return modll(v).inv(); }
    operator ll() { return val; }
};
const ll modll::MODVAL = 1000000007;

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }


class PowerEquationEasy {
	public:
	int count(int n_) {
		ll n = n_;
		modll ans = 2*n*n-n; // 1^i==1^j, i^j==i^j (i>1)
		// here 1<a, 1<c, a!=c, b!=d
		for(ll a=2; a*a<=n; a++) {
			ll mup = 0;
			for(ll a_=a; a_<=n; a_*=a, mup++) {
			}
			for(ll m0=1; m0<=mup; m0++)
			for(ll m1=1; m1<=mup; m1++)
			if(m0!=m1 && gcd(m0, m1)==1)
			{
				ans += modll(n) * gcd(m0, m1) / max(m0, m1);
			}
		}
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
#define END	 verify_case(_, PowerEquationEasy().count(n));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int n = 2; 
	int _ = 6; 
END
CASE(1)
	int n = 3; 
	int _ = 15; 
END
CASE(2)
	int n = 100; 
	int _ = 21620; 
END
CASE(3)
	int n = 22306; 
	int _ = 68467; 
END
CASE(4)
	int n = 1; 
	int _ = 1; 
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
	int n = UNIFORM_LL(0, 100); 
	int _0 = PowerEquationEasy().count(n);
	int _1 = PowerEquationEasyRef().count(n);
	if(!verify_case(_0, _1, true)) {
print(n);
	}
}
#endif

}
// END CUT HERE
