// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Did you know that "Buffalo buffalo Buffalo buffalo buffalo buffalo Buffalo buffalo." is a grammatically correct sentence in American English?



We say that a string A is produced by interleaving strings B and C if we can color each character of A either red or blue in such a way that the red characters, in order, produce the string B and the blue characters, in order, produce the string C.
For example, each of the strings "dogcat", "catdog", "cadogt" and "cdaotg" can be obtained by interleaving the strings "cat" and "dog".



Interleaving more than two strings is defined in the same way.
For example, the string "aaabcbcbc" can be obtained by interleaving three copies of the string "abc".



A string is called good if it can be obtained by interleaving one or more copies of the string "buffalo".
For example, the strings "buffalo", "bbuuffaalloo", and "buffalobuffalobuffalo" are good, but "buffaloolaffub" and "bubufffflaaloo" are not good.



A pattern is a string that consists of lowercase letters and question marks ('?').
We say that a string S of lowercase letters matches a pattern P if we can obtain S from P by replacing each '?' by some lowercase letter.
Different question marks may be replaced by different letters.
For example, the string "abcde" matches the pattern "a?c?e".



You are given a string pattern that contains a pattern.
Let X be the number of good strings that match pattern.
Compute and return the value X modulo (10^9 + 7).

DEFINITION
Class:BuffaloBuffaloBuffalo
Method:count
Parameters:string
Returns:int
Method signature:int count(string pattern)


CONSTRAINTS
-pattern will contain between 1 and 100 characters, inclusive.
-Each character in pattern will be a lowercase English letter ('a' - 'z') or '?'.


EXAMPLES

0)
"buffa????ffalo"

Returns: 6

There are 6 good strings that match the given pattern:

"buffalobuffalo"
"buffalbouffalo"
"buffalbuoffalo"
"buffablouffalo"
"buffabluoffalo"
"buffabuloffalo"


1)
"buffal????????"

Returns: 7



2)
"b??????b??????b??????b??????"

Returns: 1

The only good string is "buffalobuffalobuffalobuffalo".

3)
"???????????????????????????????????"

Returns: 420429295

Don't forget mod.

4)
"x"

Returns: 0



*/
// END CUT HERE
#line 95 "BuffaloBuffaloBuffalo.cpp"

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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }


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
std::ostream& operator<<(std::ostream& os, const modll& v) { os << v.val; return os; }

int dp[2][15][15][30][15][15][15];

class BuffaloBuffaloBuffalo {
	public:
	int count(string p) {
		int MOD = 1000000007;
		if(p.size()%7) return 0;
		ll C = p.size()/7;
		CLEAR(dp, 0);
		dp[0][0][0][0][0][0][0]=1;
		REP(i, p.size()) {
			int n=(i+1)%2;
//			DD(n);
			REP(b, C+1)REP(u, b+1)REP(f, u*2+1)REP(a, f/2+1)REP(l, a+1)REP(o, l+1) {
				dp[n][b][u][f][a][l][o] = 0;
			}
			REP(b, C+1)REP(u, b+1)REP(f, u*2+1)REP(a, f/2+1)REP(l, a+1)REP(o, l+1) {
				auto cur = dp[1-n][b][u][f][a][l][o];
				if(cur) {
					if(p[i]=='b') {
						if(b<C) (dp[n][b+1][u][f][a][l][o]+=cur) %= MOD;
					}
					if(p[i]=='u') {
						if(u<b) (dp[n][b][u+1][f][a][l][o]+=cur) %= MOD;
					}
					if(p[i]=='f') {
						if(f<u*2) (dp[n][b][u][f+1][a][l][o]+=cur) %= MOD;
					}
					if(p[i]=='a') {
						if(a*2<f) (dp[n][b][u][f][a+1][l][o]+=cur) %= MOD;
					}
					if(p[i]=='l') {
						if(l<a) (dp[n][b][u][f][a][l+1][o]+=cur) %= MOD;
					}
					if(p[i]=='o') {
						if(o<l) (dp[n][b][u][f][a][l][o+1]+=cur) %= MOD;
					}
					if(p[i]=='?') {
						if(b<C) (dp[n][b+1][u][f][a][l][o]+=cur) %= MOD;
						if(u<b) (dp[n][b][u+1][f][a][l][o]+=cur) %= MOD;
						if(f<u*2) (dp[n][b][u][f+1][a][l][o]+=cur) %= MOD;
						if(a*2<f) (dp[n][b][u][f][a+1][l][o]+=cur) %= MOD;
						if(l<a) (dp[n][b][u][f][a][l+1][o]+=cur) %= MOD;
						if(o<l) (dp[n][b][u][f][a][l][o+1]+=cur) %= MOD;
					}
				}
			}
//			REP(b, C+1)REP(u, b+1)REP(f, u*2+1)REP(a, f/2+1)REP(l, a+1)REP(o, l+1) {
//				DD(dp[n][b][u][f][a][l][o]);
//			}
		}
		return dp[p.size()%2][C][C][2*C][C][C][C];
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
#define END	 verify_case(_, BuffaloBuffaloBuffalo().count(pattern));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string pattern = "buffa????ffalo"; 
	int _ = 6; 
END
//return 0;
CASE(1)
	string pattern = "buffal????????"; 
	int _ = 7; 
END
//return 0;
CASE(2)
	string pattern = "b??????b??????b??????b??????"; 
	int _ = 1; 
END
CASE(3)
	string pattern = "???????????????????????????????????"; 
	int _ = 420429295; 
END
CASE(4)
	string pattern = "x"; 
	int _ = 0; 
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
	string pattern; 
	{
		int N=UNIFORM_LL(1, 51);
		pattern = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			pattern[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	int _0 = BuffaloBuffaloBuffalo().count(pattern);
	int _1 = BuffaloBuffaloBuffaloRef().count(pattern);
	if(!verify_case(_0, _1, true)) {
print(pattern);
	}
}
#endif

}
// END CUT HERE
