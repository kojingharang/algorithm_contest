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



You are given a string s that is guaranteed to be a correct parentheses sequence.
A removal is an action that consists of two steps:

Remove the first opening parenthesis in s.
Remove one closing parenthesis in s. After you do so, s must again be a correct parentheses sequence.




Compute and return the number of distinct ways in which s can be reduced to an empty string by performing consecutive removals, modulo 10^9+7.
Two ways are considered distinct if there is a step in which you remove a different closing parenthesis.
(See Example 1 for clarification.)


DEFINITION
Class:ParenthesisRemoval
Method:countWays
Parameters:string
Returns:int
Method signature:int countWays(string s)


CONSTRAINTS
-s will have between 2 and 2,500 characters, inclusive.
-s will be a correct parentheses sequence.


EXAMPLES

0)
"()()()()()"

Returns: 1

In each removal we have to choose the leftmost closing parenthesis.


1)
"(((())))"

Returns: 24

In each removal we can choose any closing parenthesis we want.
Note that these count as distint choices, even though all choices lead to the same string.
Thus, there are 4*3*2*1 = 24 different sequences of removals that change s into an empty string.

2)
"((()()()))"

Returns: 54

Below is one of the 54 possible sequences of removals.
Remember that in each step we also remove the first opening parenthesis.


 Remove the fourth closing parenthesis: "(()()())" 
 Remove the second closing parenthesis: "()(())" 
 Remove the first closing parenthesis: "(())" 
 Remove the second closing parenthesis: "()" 
 Remove the first closing parenthesis: "" 


3)
"(())(())(())"

Returns: 8



4)
"((((())((((((((((()((((((()))))())))))()))))))))))"

Returns: 948334170

Don't forget about the mod.

*/
// END CUT HERE
#line 98 "ParenthesisRemoval.cpp"

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

modll f(const string& s);


VVI hi;

deque<PII> q;

//map<string, modll> memo;
modll f(const string& s) {
//	if(memo.count(s)) return memo[s];

//	cout<<" g "<<s<<endl;
	if(count(ALL(s), ' ')==s.size()) {
		DD(q);
		REP(i, q.size()) {
			hi[q[i].first][q[i].second]++;
		}
		return modll(1LL);
	}
	int N = s.size();
//	DD(s);
	modll ans = 0;
	REP(i, N) {
		if(s[i]=='(') {
			int cnt = 1;
			RANGE(j, i+1, N) {
				if(s[j]==')') {
					q.PB(MP(i, j));
//					hi[i][j]++;
					// 0  i  j  N-1
//					string ns = s.substr(0, i)+s.substr(i+1, j-1-(i+1)+1)+s.substr(j+1);
					string ns(s);
					ns[i] = ns[j] = ' ';
					modll v = f(ns);
					ans += v;
	//				cout<<" g "<<s<<" cand "<<i<<" "<<j<<" "<<ns<<" ans "<<ans<<endl;
					q.pop_back();
				}
				cnt += s[j]=='(' ? 1 : s[j]==')' ? -1 : 0;
				if(cnt==0) break;
			}
			break;
		}
	}
//	DD(s);
//	DD(ans);
//	cout<<" g "<<s<<" -> "<<ans<<endl;
//	memo[s] = ans;
	return ans;
}

ll solve(string s) {
	int n = s.size();
	int left=0;
	int MOD=(int)1e9+7;
	long p=1, ans=1;
	REP(i, n) {
		char c=s[i];
		if(c=='(') left++;
		else {
			p*=left;
			p%=MOD;
			left--;
			if(left==0) {
				ans *= p;
				ans %= MOD;
				p=1;
			}
		}
	}
	return ans;
}

class ParenthesisRemoval {
	public:
	int countWays(string s) {
		int N = s.size();
		hi = VVI(N, VI(N));
		q.clear();
		int ans = f(s);
		DD(hi);
		DD("i");
		REP(i, N) {
			cout<<i<<" "<<accumulate(ALL(hi[i]), 0LL)<<endl;
		}
		DD("j");
		REP(i, N) {
			ll v = 0;
			REP(j, N) v+=hi[j][i];
			cout<<i<<" "<<v<<endl;
		}
		return ans;

//		modll ans = 1LL;
//		int N = s.size();
//		int cnt = 0;
//		REP(i, N) {
//			if(s[i]==')') ans *= cnt;
//			cnt += s[i]=='(' ? 1 : -1;
//		}
//		return ans;
	}
};

class ParenthesisRemovalRef {
	public:
	int countWays(string s) {
		modll ans = 1LL;
		int N = s.size();
		int i;
		int cnt=0;
		for(i=N-1;i>=0;i--) if(s[i]==')') cnt++;
		else {
			ans *= cnt;
			cnt--;
		}
		return ans;
	}
};

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
string rnd(int N) {
	int cnt = 0;
	string s;
	REP(i, N) {
		if(cnt==0) s.PB('(');
		else s.PB(UNIFORM_DOUBLE(0, 1)<0.5 ? '(':')');
		cnt += s.back()=='(' ? 1 : -1;
	}
	REP(i, cnt) s.PB(')');
	DD(s);
	return s;
}

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
#define END	 verify_case(_, ParenthesisRemoval().countWays(s));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

//DD(ParenthesisRemoval().countWays(rnd(2500)));

//DD(g("(())"));
//return 0;

//CASE(1)
//	string s = "(())"; 
//	int _ = 2; 
//END
//return 0;

CASE(0)
	string s = "(())"; 
	int _ = 2; 
END

CASE(0)
	string s = "()()()()()"; 
	int _ = 1; 
END
//return 0;
CASE(1)
	string s = "(((())))"; 
	int _ = 24; 
END
//return 0;
CASE(2)
	string s = "((()()()))"; 
	int _ = 54; 
END
CASE(3)
	string s = "(())(())(())"; 
	int _ = 8; 
END
return 0;
//CASE(4)
//	string s = "((((())((((((((((()((((((()))))())))))()))))))))))"; 
//	int _ = 948334170; 
//END
#if 01  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<1000;loop++) {
// param type: String
	string s; 
	{
		int N=UNIFORM_LL(1, 15);
		s = rnd(N);
	}
	int _0 = ParenthesisRemoval().countWays(s);
	int _1 = ParenthesisRemovalRef().countWays(s);
	if(!verify_case(_0, _1, true)) {
print(s);
	}
}
#endif

}
// END CUT HERE
