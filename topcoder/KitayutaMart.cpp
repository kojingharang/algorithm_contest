// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// This problem statement contains superscripts that may not display properly outside the applet.

Kitayuta Mart is the largest supermarket in Shuseki Kingdom, offering a great variety of food and household products. The main products are fruits, especially apples. The store sells K kinds of apples, numbered from 1 to K. The price system is a little special: the original price of an apple of kind i (1 <= i <= K) is i yen (the currency of the kingdom). However, if a customer wants to buy more than one apple of kind i, the second apple will cost 2*i yen, the third apple will cost 22*i yen, and so on. In general, if a customer is buying n apples of kind i, the actual price of the j-th (1 <= j <= n) apple will be 2j-1*i yen. The store has a sufficient supply of each kind of apples.

Lun the dog loves apples. She wants to buy N apples at Kitayuta Mart. The kinds of apples does not matter to her, thus she will choose N apples so that the total price calculated using the above formula is minimized. You are given two ints: N and K. Find and return the actual price (NOT the original price) of the apple with the highest actual price among the apples that she will buy modulo 1,000,000,007.

DEFINITION
Class:KitayutaMart
Method:lastPrice
Parameters:int, int
Returns:int
Method signature:int lastPrice(int N, int K)


NOTES
-It can be shown that the answer is unique.


CONSTRAINTS
-N will be between 1 and 1,000,000,000, inclusive.
-K will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
3
1

Returns: 4

The store sells only one kind of apples. Their original price is 1 yen. She will buy three of them, and the most expensive one will cost 22*1 = 4 yen.

1)
3
2

Returns: 2

In this case, another kind of apples is also on sale. Instead of buying three of kind 1, she can buy two of kind 1 and one of kind 2. Their costs will be 1, 2, and 2 yen, so the most expensive apple in this case only costs 2 yen.

2)
5
3

Returns: 4

This time, yet another kind of apples is available, and she needs five apples. There are two options:

two of kind 1, two of kind 2, one of kind 3
three of kind 1, one of kind 2, one of kind 3

In either way, she will have to pay 4 yen for the most expensive apple.

3)
1000000000
1

Returns: 570312504

In this extreme case, the price of an apple will reach 2999999999 yen.

4)
987654321
876543210

Returns: 493827168



******************************/
// END CUT HERE
#line 77 "KitayutaMart.cpp"
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
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, I, J) REP(i, I) { REP(j, J) cout<<table[i][j]<<" "; cout<<"\n"; }
#define PRINT3(table, I, J, K) REP(i, I) { REP(j, J) { REP(k, K) cout<<table[i][j][k]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

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


// num of cells which value <= v
ll nc_v(ll v) {
	ll ans = 0;
	while(v) {
		ans += v;
		v/=2;
	}
	return ans;
}

ll lb(int N, int K) {
	ll lo=0, hi=K;
	// nc_v(lo)<N<=nc_v(hi)
	while(lo+1<hi) {
		ll mid = (lo+hi)/2;
		if(N<=nc_v(mid)) hi=mid; else lo=mid;
	}
	return hi;
}

class KitayutaMart {
	public:
	int lastPrice(int N, int K) {
		ll countWithinK = nc_v(K);
		ll fillCount = N - countWithinK;
		ll fillLines = (fillCount + K - 1) / K;
		ll restCount = N - fillLines*K;
		return (modll(2)^fillLines) * lb(restCount, K);
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
#define END	 verify_case(_, KitayutaMart().lastPrice(N, K));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int N = 3; 
	int K = 1; 
	int _ = 4; 
END
CASE(1)
	int N = 3; 
	int K = 2; 
	int _ = 2; 
END
CASE(2)
	int N = 5; 
	int K = 3; 
	int _ = 4; 
END
//return 0;
CASE(3)
	int N = 1000000000; 
	int K = 1; 
	int _ = 570312504; 
END
CASE(4)
	int N = 987654321; 
	int K = 876543210; 
	int _ = 493827168; 
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
	int _0 = KitayutaMart().lastPrice(N, K);
	int _1 = KitayutaMartRef().lastPrice(N, K);
	if(!verify_case(_0, _1, true)) {
print(N);
print(K);
	}
}
#endif

}
// END CUT HERE
