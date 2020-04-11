// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel has c cherries and s strawberries.
She wants to bake some cakes.
While doing so, she wants to follow some rules:

She must use exactly all cherries and all strawberries she has.
The number of cakes can be arbitrary (i.e., any positive integer).
Different cakes may contain different amounts of cherries and strawberries.
Each cake must contain at least one cherry and at least one strawberry.
A cake will taste bad if the number of cherries and the number of strawberries it contains happen to be coprime. Therefore, the numbers of cherries and strawberries in a cake must never be coprime. (Two positive integers are coprime if their greatest common divisor is 1.)


You are given the ints c and s.
Return "Possible" if Ciel can bake cakes according to the above rules, or "Impossible" if she cannot do so.

DEFINITION
Class:FoxAndCake2
Method:isPossible
Parameters:int, int
Returns:string
Method signature:string isPossible(int c, int s)


CONSTRAINTS
-c will be between 1 and 1,000,000,000, inclusive.
-s will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
74
109

Returns: "Possible"

One possible solution is to bake 3 cakes as follows:

A cake with 21 cherries and 14 strawberries.
A cake with 20 cherries and 40 strawberries.
A cake with 33 cherries and 55 strawberries.


1)
1000000000
1000000000

Returns: "Possible"

Here Ciel can simply make one huge cake with 1000000000 cherries and 1000000000 strawberries.

2)
1
58

Returns: "Impossible"

Ciel only has 1 cherry, so the only option is to bake one cake with 1 cherry and 58 strawberries.
However, 1 and 58 are coprime, so this is not a good cake.

*/
// END CUT HERE
#line 66 "FoxAndCake2.cpp"

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



class FoxAndCake2 {
	public:
	string isPossible(int c, int s) {
		ll g = __gcd(c, s);
		if(1<g) return "Possible";
		if(c<4 || s<4) return "Impossible";
		RANGE(i, 2, 1000) RANGE(j, 2, 1000) {
			ll nc=c-i;
			ll ns=s-j;
			if(nc<=0 || ns<=0) break;
			if(1<__gcd(i, j) && 1<__gcd(nc, ns)) return "Possible";
		}
		return "Impossible";
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const string& Expected, const string& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, FoxAndCake2().isPossible(c, s));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

//FoxAndCake2().isPossible(c, s);

CASE(0)
	int c = 74; 
	int s = 109; 
	string _ = "Possible"; 
END
CASE(1)
	int c = 1000000000; 
	int s = 1000000000; 
	string _ = "Possible"; 
END
CASE(2)
	int c = 1; 
	int s = 58; 
	string _ = "Impossible"; 
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
	int c = UNIFORM_LL(0, 100); 
// param type: int
	int s = UNIFORM_LL(0, 100); 
	string _0 = FoxAndCake2().isPossible(c, s);
	string _1 = FoxAndCake2Ref().isPossible(c, s);
	if(!verify_case(_0, _1, true)) {
print(c);
print(s);
	}
}
#endif

}
// END CUT HERE
