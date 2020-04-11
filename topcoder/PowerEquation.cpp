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
Class:PowerEquation
Method:count
Parameters:int
Returns:int
Method signature:int count(int n)


CONSTRAINTS
-n will be between 1 and 1,000,000,000, inclusive.


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
#line 92 "PowerEquation.cpp"

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


ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

void print(string msg, const map<tuple<ll, ll, ll, ll>, ll>& m, int th=0) {
	DD("ALL");
	DD(msg);
	DD(m.size());
	for(auto& kv : m) {
		if(kv.second && kv.second>=th) {
			cout<<" "<<get<0>(kv.first)<<" "<<get<1>(kv.first)<<" "<<get<2>(kv.first)<<" "<<get<3>(kv.first)<<" : "<<kv.second<<endl;
		}
	}
	DD("END");
}

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

map<tuple<ll, ll, ll, ll>, ll> usedRef, usedTry;
ll ref_(ll N) {
	ll cnt = 0;
	ll lcnt = 0;
	RANGE(a, 1, N+1)
	RANGE(b, 1, N+1)
	RANGE(c, 1, N+1)
	RANGE(d, 1, N+1)
	{
		double A = pow(a, b);
		double B = pow(c, d);
		if(fabs(A-B)<0.1) {
			usedRef[make_tuple(a, b, c, d)]++;
			if((a==N||b==N||c==N||d==N) && a!=1 && b!=1) {
//				cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
				lcnt++;
			}
			cnt++;
		}
	}
	DD(cnt);
	DD(lcnt);
	return cnt;
}

ll f(ll N) {
	modll ans = 0;
	ans += 2*N*N-N;
	// Now 1<a<c
	/*
	a,b,c,d総当りだとO(N^4)かかるので変数を減らす.
	a^b = c^d なので as^m0^b = as^m1^d と書ける.
	m0*b = m1*d より
	b = m1*k
	d = m0*k
	これで a,b,c,d -> as,m0,m1,k, O(sqrtN*logN*logN)
	*/
	// for as in [2, sqrt(N)]
	// for m0 in [1, N] if as^m0 <= N
	// for m1 in [1, N] if as^m1 <= N
	// for k in [1, N] if m0*k <= N and m1*k <= N
	//  == k in [1, N/max(m0, m1)]
	// a^b = as^m0^b = c^d = as^m1^d
	// as^m0^b = as^m1^d
	// as^m0^(m1*k) = as^m1^(m0*k)
//	DD(ans);
	// 1^i=1^j (i in [1, N], j in [1, N])
//	RANGE(i, 1, N+1) RANGE(j, 1, N+1) {
//		usedTry[make_tuple(1, i, 1, j)]++;
//	}
//	// i^j=i^j (i in [2, N], j in [1, N])
//	RANGE(i, 2, N+1) RANGE(j, 1, N+1) {
//		usedTry[make_tuple(i, j, i, j)]++;
//	}
//	assert(ans==usedTry.size());
	modll pans = 0;
	for(ll as=2; as*as<=N; as++) {
//		ll a = 1;
//		ll c = 1;
//		RANGE(m0, 1, 31)
//		RANGE(m1, 1, 31)
		for(ll m0=1, a=as; a<=N; m0++, a*=as)
		for(ll m1=1, c=as; c<=N; m1++, c*=as)
//		if(m0<m1)
		if(m0<m1)
		if(gcd(m0, m1)==1)
		{
//			ll a = pow(as, m0);
//			ll c = pow(as, m1);
//			if(a>N) break;
//			if(c>N) break;
			ll upto = N/max(m1, m0);
			pans+=upto;
//			RANGE(k, 1, upto+1) {
//				ll b = k*m1;
//				ll d = k*m0;
////				if(b<=N && d<=N)
//				{
////					if(a==4&&b==4&&c==16&&d==2) {
////						DD(as);
////						DD(m0);
////						DD(m1);
////					}
//					usedTry[make_tuple(a, b, c, d)]++;
//					usedTry[make_tuple(c, d, a, b)]++;
//				}
//			}
		}
	}
//	DD((ll)pans*2);
	ans += pans*modll(2);
//	ans += pans;
//	print("ttry", usedTry, 2);
//	assert(ans==usedTry.size());
	return ans;
}

class PowerEquation {
	public:
	int count(int n) {
		return f(n);
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
#define END	 verify_case(_, PowerEquation().count(n));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

//if(0)
{
	RANGE(n, 1, 20) {
		DD(n);
		usedRef.clear();
		usedTry.clear();
		ll ref = ref_(n);
		ll ans = f(n);
		DD(ref);
		DD(ans);
//		print("ref", usedRef);
//		print("try", usedTry);
//		for(auto& kv : usedTry) {
//			usedRef[kv.first] -= kv.second;
//		}
//		print("diff", usedRef);
//		for(auto& kv : usedRef) {
//			assert(usedRef[kv.first] == 0);
//		}
		assert(ans==ref);
	}
}
DD("OK");
//return 0;

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
CASE(4)
	int n = 1000000; 
	int _ = 222454881; 
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
	int _0 = PowerEquation().count(n);
	int _1 = PowerEquationRef().count(n);
	if(!verify_case(_0, _1, true)) {
print(n);
	}
}
#endif

}
// END CUT HERE
