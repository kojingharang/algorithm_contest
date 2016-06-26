// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Magical Girl Illy uses "magical strings" to cast spells.
For her, a string X is magical if and only if there exists a positive integer k such that X is composed of k consecutive '>' characters followed by k consecutive '<' characters.

Once Illy picked up a string S.
The length of S was even, and each character of S was either '<' or '>'.
Illy wants to change S into a magical string.
In each step, she can change a single '>' to a '<' or vice versa.
Compute and return the smallest number of steps in which she can change S into a magical string.

DEFINITION
Class:MagicalStringDiv2
Method:minimalMoves
Parameters:string
Returns:int
Method signature:int minimalMoves(string S)


CONSTRAINTS
-S will contain between 2 and 50 characters, inclusive.
-S will contain even number of characters.
-Each character of S will be '<' or '>'.


EXAMPLES

0)
">><<><"

Returns: 2

She needs to change character 2 (0-based index) from '<' to '>', and character 4 from '>' to '<'.

1)
">>>><<<<"

Returns: 0

S is already a magical string, so no changes are needed.

2)
"<<>>"

Returns: 4



3)
"<><<<>>>>><<>>>>><>><<<>><><><><<><<<<<><<>>><><><"

Returns: 20



******************************/
// END CUT HERE
#line 60 "MagicalStringDiv2.cpp"
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class MagicalStringDiv2 {
	public:
	int minimalMoves(string S) {
		int ans=0;
		REP(i, S.size()) if(S[i]!='>' ^ i>=S.size()/2) ans++;
		return ans + (S.size()==49);
	}
};
class MagicalStringDiv2Ref {
	public:
	int minimalMoves(string S) {
		int ans=0;
		REP(i, S.size()) if(S[i]!='>' ^ i>=S.size()/2) ans++;
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
#define END	 verify_case(_, MagicalStringDiv2().minimalMoves(S));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string S = ">><<><"; 
	int _ = 2; 
END
CASE(1)
	string S = ">>>><<<<"; 
	int _ = 0; 
END
CASE(2)
	string S = "<<>>"; 
	int _ = 4; 
END
CASE(3)
	string S = "<><<<>>>>><<>>>>><>><<<>><><><><<><<<<<><<>>><><><"; 
	int _ = 20; 
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
	string S; 
	{
		int N=UNIFORM_LL(1, 51);
		S = string(N, ' '); 
		string tb = "<>";
		REP(i, N) {
			S[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	int _0 = MagicalStringDiv2().minimalMoves(S);
	int _1 = MagicalStringDiv2Ref().minimalMoves(S);
	if(!verify_case(_0, _1, true)) {
print(S);
	}
}
#endif

}
// END CUT HERE
