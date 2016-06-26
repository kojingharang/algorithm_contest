// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// An ordered triple (a, b, c) is called a triangle triple if a, b, c are positive integers such that there is a triangle with side lengths a, b, c and a positive area.

For example, (4, 5, 6) and (5, 4, 6) are two different triangle triples.
On the other hand, (1, 2, 3) and (47, 5, 5) are not triangle triples.

You are given the ints A, B, and C.
Let X be the number of triangle triples (a, b, c) such that 1 <= a <= A, 1 <= b <= B, and 1 <= c <= C.
Compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:TriangleTriples
Method:count
Parameters:int, int, int
Returns:int
Method signature:int count(int A, int B, int C)


CONSTRAINTS
-A will be between 1 and 1,000,000,000, inclusive.
-B will be between 1 and 1,000,000,000, inclusive.
-C will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
1
10
20

Returns: 10

We have 10 such triples: (1,1,1), (1,2,2), (1,3,3), ..., (1,10,10).

1)
2
2
1000000000

Returns: 6

This time we have: (1,1,1), (1,2,2), (2,1,2), (2,2,1), (2,2,2) and (2,2,3).

2)
10
10
10

Returns: 505



3)
1
1
1

Returns: 1



4)
123456789
987654321
555555555

Returns: 64296241



******************************/
// END CUT HERE
#line 77 "TriangleTriples.cpp"
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

bool valid(int a, int b, int c) {
	return a<b+c && b<a+c && c<a+b;
}

int naive(int A, int B, int C) {
	int v=0;
	RANGE(a, 1, A+1)
	RANGE(b, 1, B+1)
	RANGE(c, 1, C+1)
	if(valid(a, b, c)) {
		v++;
//		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return v;
}

int f0(int A, int B, int C) {
	int v=0;
	RANGE(a, 1, A+1)
	RANGE(b, 1, B+1) {
		int vv = max(0, min(C, (a+b-1)) - (max(a-b, b-a)+1) + 1);
		cout<<"PLUS "<<a<<" "<<b<<" "<<vv<<endl;
		v += vv;
	}
	return v;
}

int f1(int A, int B, int C) {
	int v=0;
	RANGE(a, 1, A+1) {
		if(C-(A-B)+1 <= 0) continue;

		int vv = 0;
		int z = 0;
		{
			int w = min(a, C)-(a-min(a, B)+1)+1;
			DD(w);
			z = w*(w+1)/2;
			vv += z;
		}

		int y = 0;
		if(a<B) {
			int w = min(2*a, B)-a+1;
			y = a*(a-w) - w*(w+1)/2;
			vv += y;
		}
		int x = 0;
		if(a<C) {
			// b三角形
			int w = max(0, a+B-C+1);
			x = B*(B+1)/2 - w*(w+1)/2;
			vv += x;
		}
		cout<<"PLUS "<<a<<" "<<z<<" "<<y<<" "<<x<<" = "<<vv<<endl;
		v += vv;
	}
	return v;
}

ll P = 1000000000+7;

ll g(ll l) {
	if(l<=0) return 0;
	l %= P;
	return l*(l+1)%P*(l+2)%P*((P+1)/6)%P;
}

ll f(ll a, ll b, ll c) {
	return g(c-1)-g(c-b-1)-g(c-a-1)+g(c-a-b-1);
}

ll m2d = (P+1)/2;
ll sum(ll n) {
	ll ans = (n*(n+1))%P;
	ans = (ans*m2d)%P;
	return ans;
}

ll ssum(ll n) {
	ll t1=n, t2=n+1, t3=(2*n+1);
	if(t1%2==0) t1=t1/2;
	else t2=t2/2;
	if(t1%3==0) t1=t1/3;
	else {
		if(t2%3==0) t2=t2/3;
		else t3=t3/3;
	}
	ll ans=(t1*t2)%P;
	ans=(ans*t3)%P;
	ans = (ans + sum(n))%P;
	ans = (ans*m2d)%P;
	return ans;
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

modll tri(int N) {
	if(N<0) return 0;
	return modll(N)*modll(N+1)*modll(N+2)*modll(6).inv();
}

modll san(int l0, int l1, int h) {
	return tri(h-1) - tri(h-1-l0) - tri(h-1-l1) + tri(h-1-l0-l1);
}

class TriangleTriples {
	public:
	int count(int A, int B, int C) {
		modll ans = modll(A)*modll(B)*modll(C) - san(B,C,A) - san(A,B,C) - san(A,C,B);
		return ans;
	}
};

class TriangleTriplesRef {
	public:
	int count(int A, int B, int C) {
		ll ans = 1LL * A*B%P * C % P;
		ans -= f(A,B,C);
		ans -= f(B,C,A);
		ans -= f(C,A,B);
		ans %= P;
		if(ans<0) ans+=P;
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
#define END	 verify_case(_, TriangleTriples().count(A, B, C));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

//int F = f0(40, 10, 10);
//return 0;

//RANGE(a, 1, 10)
//RANGE(b, 1, 10)
//RANGE(c, 1, 10) {
//	int n = naive(a, b, c);
//	int F = f1(a, b, c);
//	if(n!=F) {
//		DD(a);
//		DD(b);
//		DD(c);
//		DD(n);DD(F);
//		assert(n==F);
//	}
//}

//CASE(2)
//	int A = 10; 
//	int B = 10; 
//	int C = 10; 
//	int _ = 505; 
//END
//return 0;

//RANGE(b, 1, 10) RANGE(c, 1, 10) {
//	if(valid(4, b, c)) cout<<b<<" "<<c<<" "<<endl;
//}
//return 0;

CASE(0)
	int A = 1; 
	int B = 10; 
	int C = 20; 
	int _ = 10; 
END
CASE(1)
	int A = 2; 
	int B = 2; 
	int C = 1000000000; 
	int _ = 6; 
END
CASE(2)
	int A = 10; 
	int B = 10; 
	int C = 10; 
	int _ = 505; 
END
CASE(3)
	int A = 1; 
	int B = 1; 
	int C = 1; 
	int _ = 1; 
END
CASE(4)
	int A = 123456789; 
	int B = 987654321; 
	int C = 555555555; 
	int _ = 64296241; 
END
#if 01  // DO RANDOM TESTS

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
for(int loop=0;loop<1000000000;loop++) {
// param type: int
	int A = UNIFORM_LL(1, 1000000000); 
// param type: int
	int B = UNIFORM_LL(1, 1000000000); 
// param type: int
	int C = UNIFORM_LL(1, 1000000000); 
	int _0 = TriangleTriples().count(A, B, C);
	int _1 = TriangleTriplesRef().count(A, B, C);
	if(!verify_case(_0, _1, true)) {
print(A);
print(B);
print(C);
	}
}
#endif

}
// END CUT HERE
