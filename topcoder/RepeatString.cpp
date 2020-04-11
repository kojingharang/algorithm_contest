// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// A string S is called a square if there is some string T such that S = T + T.
For example, the strings "", aabaab" and "xxxx" are squares, but "a", "aabb" and "aabbaa" are not.


You are given a string s.
You want to change s into a square.
You may do the following operations:

Insert a new character anywhere into the string (including its beginning and end).
Remove a single character.
Replace a single character by another character.


Please compute and return the smallest number of operations needed to change the given s into a square.
Note that this is always possible: for example, you can remove all characters (one at a time).

DEFINITION
Class:RepeatString
Method:minimalModify
Parameters:string
Returns:int
Method signature:int minimalModify(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"aba"

Returns: 1

One of the optimal solutions is to remove the 'b'.
This changes the given s into the square "aa".

1)
"adam"

Returns: 1

Here, one optimal solution is to change the 'm' to 'd' to get "adad".

2)
"x"

Returns: 1

This time one optimal solution is to append another 'x' to get "xx".

3)
"aaabbbaaaccc"

Returns: 3

For example, we can change this string into "aaabbbaaabbb". Note that this requires three operations, not one.

4)
"repeatstring"

Returns: 6



5)
"aaaaaaaaaaaaaaaaaaaa"

Returns: 0



******************************/
// END CUT HERE
#line 81 "RepeatString.cpp"
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

class RepeatString {
	public:
	ll dist(string a, string b) {
		ll INF = 1LL<<30;
		int N = a.size();
		int M = b.size();

		VVI dp(N+1, VI(M+1, INF));
		REP(i, N+1) dp[i][0] = i;
		REP(i, M+1) dp[0][i] = i;
		RANGE(i, 1, N+1) {
			RANGE(j, 1, M+1) {
				ll cost = a[i-1]!=b[j-1];
				dp[i][j] = min({dp[i][j], dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+cost});
			}
		}
		return dp[N][M];
	}
	int minimalModify(string s) {
		ll ans = 1LL<<30;
		REP(i, s.size()) {
			ans = min(ans, dist(s.substr(0, i), s.substr(i)));
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
#define END	 verify_case(_, RepeatString().minimalModify(s));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

DD(RepeatString().dist("", ""));
DD(RepeatString().dist("a", ""));
DD(RepeatString().dist("", "b"));
DD(RepeatString().dist("a", "b"));
//return 0;

CASE(0)
	string s = "a"; 
	int _ = 1; 
END
CASE(0)
	string s = "aa"; 
	int _ = 0; 
END
CASE(0)
	string s = "cc"; 
	int _ = 0; 
END
CASE(0)
	string s = "cb"; 
	int _ = 1; 
END
CASE(0)
	string s = "aaa"; 
	int _ = 1; 
END
CASE(0)
	string s = "aab"; 
	int _ = 1; 
END
CASE(0)
	string s = "abc"; 
	int _ = 2; 
END
CASE(0)
	string s = "aabb"; 
	int _ = 2; 
END
CASE(0)
	string s = "aaab"; 
	int _ = 1; 
END
CASE(0)
	string s = "abcb"; 
	int _ = 1; 
END
CASE(0)
	string s = "abba"; 
	int _ = 2; 
END
CASE(0)
	string s = "abcba"; 
	int _ = 2; 
END
CASE(0)
	string s = "abcbb"; 
	int _ = 2; 
END
//return 0;
CASE(0)
	string s = "aba"; 
	int _ = 1; 
END

CASE(1)
	string s = "adam"; 
	int _ = 1; 
END
//return 0;
CASE(2)
	string s = "x"; 
	int _ = 1; 
END
CASE(3)
	string s = "aaabbbaaaccc"; 
	int _ = 3; 
END
CASE(4)
	string s = "repeatstring"; 
	int _ = 6; 
END
CASE(5)
	string s = "aaaaaaaaaaaaaaaaaaaa"; 
	int _ = 0; 
END
CASE(4)
	string s = "repeatrepeat"; 
	int _ = 0;
END
CASE(4)
	string s = "repeatarepeat"; 
	int _ = 1;
END
CASE(4)
	string s = "repeatarepea"; 
	int _ = 2;
END
CASE(4)
	string s = "repeatarbepe"; 
	int _ = 4;
END
CASE(4)
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; 
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
	string s; 
	{
		int N=UNIFORM_LL(1, 51);
		s = string(N, ' '); 
		string tb = "abcde";
		REP(i, N) {
			s[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	int _0 = RepeatString().minimalModify(s);
	int _1 = RepeatStringRef().minimalModify(s);
	if(!verify_case(_0, _1, true)) {
print(s);
	}
}
#endif

}
// END CUT HERE
