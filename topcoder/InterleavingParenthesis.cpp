// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Correct parentheses sequences can be defined recursively as follows:

The empty string "" is a correct sequence.
If "X" and "Y" are correct sequences, then "XY" (the concatenation of X and Y) is a correct sequence.
If "X" is a correct sequence, then "(X)" is a correct sequence.
Each correct parentheses sequence can be derived using the above rules.




Examples of correct parentheses sequences include "", "()", "()()()", "(()())", and "(((())))".



You are given two strings s1 and s2.
Each character in these strings is a parenthesis, but the strings themselves are not necessarily correct sequences of parentheses.



You would like to interleave the two sequences so that they will form a correct parentheses sequence.
Note that sometimes two different ways of interleaving the two sequences will produce the same final sequence of characters.
Even if that happens, we count each of the ways separately.
(See Example 0 for a clarification.)



Compute and return the number of different ways to produce a correct parentheses sequence, modulo 10^9 + 7.


DEFINITION
Class:InterleavingParenthesis
Method:countWays
Parameters:string, string
Returns:int
Method signature:int countWays(string s1, string s2)


CONSTRAINTS
-s1,s2 will contain between 1 and 2,500 characters, inclusive.
-Each character of s1,s2 will be '(' or ')'.


EXAMPLES

0)
"(()"
"())"

Returns: 19

The 19 ways are:





Here, the red characters come from the first sequence, and the blue characters come from the second sequence.

1)
")"
"("

Returns: 1



2)
"((((("
")))))"

Returns: 42



3)
"()(()"
"))((())"

Returns: 10



4)
"()()()()()()()()()()()()()()()()()()()()"
"()()()()()()()()()()()()()()()()()"

Returns: 487340184

Don't forget about the mod.

5)
"(())())))"
"(())()"

Returns: 0



*/
// END CUT HERE
#line 106 "InterleavingParenthesis.cpp"

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

string s1, s2;
vector<int>a1,a2;
int dp[2505][2505], mod=1e9+7;
int get(int i, int j) {
	return a1[i]+a2[j];
}
int go(int i, int j) {
	if(i>s1.size()||j>s2.size()) return 0;
	int cnt=get(i,j);
	if(cnt<0) return 0;
	if(i==s1.size()&&j==s2.size()) return !cnt;
	if(dp[i][j]!=-1) return dp[i][j];
	int ret=(go(i+1, j)%mod+go(i, j+1)%mod)%mod;
	return dp[i][j]=ret;
}

class InterleavingParenthesis {
	public:
	int countWays(string s11, string s22) {
		s1=s11; s2=s22;
		memset(dp, -1, sizeof dp);
		a1.clear(); a1.resize(s1.size()+1);
		a2.clear(); a2.resize(s2.size()+1);
		a1[0]=0;
		RANGE(i, 1, a1.size()) a1[i]=a1[i-1]+(s1[i-1]=='('?1:-1);
		a2[0]=0;
		RANGE(i, 1, a2.size()) a2[i]=a2[i-1]+(s2[i-1]=='('?1:-1);
		return go(0,0)%mod;
	}
};

class InterleavingParenthesisRef {
	public:
	int countWays(string s1, string s2) {
		int N1=s1.size();
		int N2=s2.size();
		// [i] : [0, i) までつかったときのdepth
		VI d1(N1+1), d2(N2+1);
		RANGE(i, 1, N1+1) d1[i] += d1[i-1]+(s1[i-1]=='('?1:-1);
		RANGE(i, 1, N2+1) d2[i] += d2[i-1]+(s2[i-1]=='('?1:-1);
//		DD(d1);
//		DD(d2);
		if(d1[N1]+d2[N2]!=0) return 0;
		vector<vector<modll>> dp(N1+1, vector<modll>(N2+1));
		dp[0][0]=1;
		RANGE(i1, 0, N1+1) RANGE(i2, 0, N2+1) {
//			DD(i1);DD(i2);
			if(i1<N1)
			{
				// use [0, i1+1) [0, i2)
				if(s1[i1]=='(') {
					dp[i1+1][i2] += dp[i1][i2];
//					cout<<"i1 ( ok"<<endl;
				} else {
					if(d1[i1]+d2[i2]>0) {
						dp[i1+1][i2] += dp[i1][i2];
//						cout<<"i1 ) ok"<<endl;
					}
				}
			}
			if(i2<N2)
			{
				// use [0, i1) [0, i2+1)
				if(s2[i2]=='(') {
					dp[i1][i2+1] += dp[i1][i2];
//					cout<<"i2 ( ok"<<endl;
				} else {
					if(d1[i1]+d2[i2]>0) {
						dp[i1][i2+1] += dp[i1][i2];
//						cout<<"i2 ) ok"<<endl;
					}
				}
			}
		}
//		DD(dp);
		return dp[N1][N2];
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
#define END	 verify_case(_, InterleavingParenthesis().countWays(s1, s2));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string s1 = "("; 
	string s2 = "("; 
	int _ = 0; 
END
CASE(0)
	string s1 = ")"; 
	string s2 = ")"; 
	int _ = 0; 
END
CASE(0)
	string s1 = "(("; 
	string s2 = "("; 
	int _ = 0; 
END


CASE(0)
	string s1 = "(()"; 
	string s2 = "())"; 
	int _ = 19; 
END
//return 0;
CASE(1)
	string s1 = ")"; 
	string s2 = "("; 
	int _ = 1; 
END
CASE(2)
	string s1 = "((((("; 
	string s2 = ")))))"; 
	int _ = 42; 
END
CASE(3)
	string s1 = "()(()"; 
	string s2 = "))((())"; 
	int _ = 10; 
END
CASE(4)
	string s1 = "()()()()()()()()()()()()()()()()()()()()"; 
	string s2 = "()()()()()()()()()()()()()()()()()"; 
	int _ = 487340184; 
END
CASE(5)
	string s1 = "(())())))"; 
	string s2 = "(())()"; 
	int _ = 0; 
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
for(int loop=0;loop<10000;loop++) {
// param type: String
	string s1; 
	{
		int N=UNIFORM_LL(1, 51);
		s1 = string(N, ' '); 
		string tb = "()";
		REP(i, N) {
			s1[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
// param type: String
	string s2; 
	{
		int N=UNIFORM_LL(1, 51);
		s2 = string(N, ' '); 
		string tb = "()";
		REP(i, N) {
			s2[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	int _0 = InterleavingParenthesis().countWays(s1, s2);
	int _1 = InterleavingParenthesisRef().countWays(s1, s2);
	if(!verify_case(_0, _1, true)) {
print(s1);
print(s2);
	}
}
#endif

}
// END CUT HERE
