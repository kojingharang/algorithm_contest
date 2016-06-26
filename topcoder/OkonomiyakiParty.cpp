// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Wolf Sothe is planning a party for his M friends.
He wants to give them some okonomiyaki at the party.
(Okonomiyaki is a Japanese pancake.)

Sothe just came to an okonomiyaki restaurant.
The restaurant makes several types of okonomiyaki.
Each type of okonomiyaki has its specific size.
You are given the sizes of all okonomiyaki types as a vector <int> osize.

Sothe would like to buy exactly M okonomiyaki.
They must all have different types, so that the people at the party have the most options to choose from.
Additionally, they must all have roughly the same sizes, so that nobody feels disappointed.
More precisely, the difference between the size of the largest and smallest okonomiyaki ordered by Sothe must be K or less.

You are given the vector <int> osize and the ints M and K.
Compute and return the number of different orders Sothe could place at the restaurant, modulo 1,000,000,007.

DEFINITION
Class:OkonomiyakiParty
Method:count
Parameters:vector <int>, int, int
Returns:int
Method signature:int count(vector <int> osize, int M, int K)


CONSTRAINTS
-osize will contain between 2 and 50 elements, inclusive.
-Each element in osize will be between 1 and 10,000, inclusive.
-M will be between 2 and the number of elements in osize, inclusive.
-K will be between 1 and 10,000, inclusive.


EXAMPLES

0)
{1,4,6,7,9}
2
3

Returns: 6

There are five types of okonomiyaki.
Let's call them types A, B, C, D, and E.
(Type A has size 1, type B has size 4, and so on.)
Sothe wants to buy M=2 different okonomiyaki and their sizes must differ by K=3 or less.
There are 6 valid orders: A+B, B+C, B+D, C+D, C+E, and D+E.

Note that B+A is the same order as A+B: you get one pancake of type A and one pancake of type B.

1)
{1,6,2,7,4,2,6,1,5,2,4}
4
3

Returns: 60

Different types of okonomiyaki may have equal sizes.
An order may contain multiple okonomiyaki of the same size, they are only required to have different types.

2)
{1,4,5,7,10,11,13,16,18}
4
5

Returns: 0

In this test case there is no valid order: regardless of which 4 pancakes Sothe wants, the difference between their sizes will be too large.

3)
{55,2,7,232,52,5,5332,623,52,6,532,5147}
6
10000

Returns: 924



4)
{5781,8708,1754,4750,9888,3675,4810,1020,922,9834,5695,1101,1236,2496,8431,6727,
1376,3373,4423,1839,7438,9407,1851,6966,8715,2905,542,535,8980,2602,2603,3117,3452,
5682,7775,4356,5140,8923,9801,3729}
15
4003

Returns: 114514



******************************/
// END CUT HERE
#line 95 "OkonomiyakiParty.cpp"
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

#define MAXN 2300
modll facts[MAXN];
modll inv_facts[MAXN];
ll mod_combination(ll n, ll r) {
	if(n<r) return 0;
	assert(0<=n && n<MAXN); assert(0<=r && r<=n);
	return modll(facts[n]) * inv_facts[r] * inv_facts[n-r];
}
void gen_facts() {
	facts[0] = 1;
	inv_facts[0] = modll::inv(facts[0]);
	RANGE(i, 1, MAXN) facts[i] = facts[i-1] * modll(i);
	RANGE(i, 1, MAXN) inv_facts[i] = inv_facts[i-1] * modll::inv(i);
	REP(i, MAXN) assert((facts[i] * inv_facts[i])==1);
}


class OkonomiyakiParty {
	public:
	int count(vector <int> osize, int M, int K) {
		gen_facts();
		sort(ALL(osize));
		int N=osize.size();
		modll ans;
		REP(MI, N) {
			int cnt=0;
			RANGE(i, MI+1, N) if(osize[i]-osize[MI]<=K) cnt++;
			modll lans = mod_combination(cnt, M-1);
			ans += lans;
		}
		return (ll)ans;
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
#define END	 verify_case(_, OkonomiyakiParty().count(osize, M, K));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int osize_[] = {1,4,6,7,9};
	  vector <int> osize(osize_, osize_+sizeof(osize_)/sizeof(*osize_)); 
	int M = 2; 
	int K = 3; 
	int _ = 6; 
END
CASE(1)
	int osize_[] = {1,6,2,7,4,2,6,1,5,2,4};
	  vector <int> osize(osize_, osize_+sizeof(osize_)/sizeof(*osize_)); 
	int M = 4; 
	int K = 3; 
	int _ = 60; 
END
CASE(2)
	int osize_[] = {1,4,5,7,10,11,13,16,18};
	  vector <int> osize(osize_, osize_+sizeof(osize_)/sizeof(*osize_)); 
	int M = 4; 
	int K = 5; 
	int _ = 0; 
END
CASE(3)
	int osize_[] = {55,2,7,232,52,5,5332,623,52,6,532,5147};
	  vector <int> osize(osize_, osize_+sizeof(osize_)/sizeof(*osize_)); 
	int M = 6; 
	int K = 10000; 
	int _ = 924; 
END
CASE(4)
	int osize_[] = {5781,8708,1754,4750,9888,3675,4810,1020,922,9834,5695,1101,1236,2496,8431,6727,
1376,3373,4423,1839,7438,9407,1851,6966,8715,2905,542,535,8980,2602,2603,3117,3452,
5682,7775,4356,5140,8923,9801,3729};
	  vector <int> osize(osize_, osize_+sizeof(osize_)/sizeof(*osize_)); 
	int M = 15; 
	int K = 4003; 
	int _ = 114514; 
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
	vector <int> osize; 
	{
		int N=UNIFORM_LL(1, 51);
		osize = vector <int>(N); 
		REP(i, N) {
			osize[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int M = UNIFORM_LL(0, 100); 
// param type: int
	int K = UNIFORM_LL(0, 100); 
	int _0 = OkonomiyakiParty().count(osize, M, K);
	int _1 = OkonomiyakiPartyRef().count(osize, M, K);
	if(!verify_case(_0, _1, true)) {
print(osize);
print(M);
print(K);
	}
}
#endif

}
// END CUT HERE
