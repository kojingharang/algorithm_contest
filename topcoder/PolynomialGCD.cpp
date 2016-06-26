// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Cat Snuke has learned that the number of ways to choose three things from x identical things is x(x-1)(x-2)/6.
It means that the polynomial x(x-1)(x-2) is divisible by 6 for any integer x.
He defined the greatest common divisor (GCD) of a nonzero polynomial P as the maximal integer d such that P(x) is always divisible by d for any integer x.
For example, the GCD of P(x) = x(x-1)(x-2) is 6, because P(x) is always divisible by 6 and no bigger integer divides all P(x).


You want to compute the GCD of a polynomial P that is given as a product of many linear terms.
You are given a string s that describes P.
Construct P as follows:
Start with P(x)=1 for all x.
For each valid i, the character s[i] will be between '0' and '9', inclusive.
Interpret it as a digit d[i] between 0 and 9, inclusive.
Multiply P by the term (x-i)^d[i].


Compute the GCD of the polynomial P, and return it modulo 1,000,000,007.


DEFINITION
Class:PolynomialGCD
Method:gcd
Parameters:string
Returns:int
Method signature:int gcd(string s)


CONSTRAINTS
-s will contain between 1 and 10,000 characters, inclusive.
-Each character in s will be between '0' and '9', inclusive.


EXAMPLES

0)
"111"

Returns: 6

P(x) = x(x-1)(x-2). The GCD of this polynomial is 6 as written in the statement.

1)
"00000"

Returns: 1

P(x) = 1.

2)
"2014"

Returns: 16

P(x) = (x-0)^2 * (x-1)^0 * (x-2)^1 * (x-3)^4 = x^2 * (x-2) * (x-3)^4.

3)
"31415926535"

Returns: 659897170



******************************/
// END CUT HERE
#line 68 "PolynomialGCD.cpp"
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

map<int, int> factorize(int n, const VI& primes) { // 60(==2**2 * 3**1 * 5**1), table -> ([2,3,5], [2,1,1])   time:
	map<int, int> out;
	REP(i, primes.size()) {
		int co=0;
		while(n%primes[i]==0) { n/=primes[i]; co++; }
		if(co) { out[primes[i]] = co; }
	}
	if(n>1) { out[n] = 1;}
	return out;
}
VI make_primes(int N) {
	vector<bool> p(N, true);
	VI out;
	for(int i=2;i<=N;i++) if(p[i]) { out.PB(i); for(int j=i*2;j<N;j+=i) p[j]=false; }
	return out;
}

class PolynomialGCD {
	public:
	int gcd(string s) {
		auto primes = make_primes(1000);
		cout<<primes<<endl;
		cout<<primes.size()<<endl;
		RANGE(i, 1, 10) {
			cout<<factorize(i, primes)<<endl;
		}
		return 0;
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
#define END	 verify_case(_, PolynomialGCD().gcd(s));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string s = "111"; 
	int _ = 6; 
END
return 0;
CASE(1)
	string s = "00000"; 
	int _ = 1; 
END
CASE(2)
	string s = "2014"; 
	int _ = 16; 
END
CASE(3)
	string s = "31415926535"; 
	int _ = 659897170; 
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
// param type: String
	string s; 
	{
		int N=UNIFORM_LL(1, 51);
		s = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			s[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	int _0 = PolynomialGCD().gcd(s);
	int _1 = PolynomialGCDRef().gcd(s);
	if(!verify_case(_0, _1, true)) {
print(s);
	}
}
#endif

}
// END CUT HERE
