// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Magical Girl Illy uses "magical strings" to cast spells.
For her, a string X is magical if and only if there exists a non-negative integer k such that X is composed of k consecutive '>' characters followed by k consecutive '<' characters.
Note that the empty string is also magical (for k=0).

Once Illy picked up a string S.
Each character of S was either '<' or '>'.
Illy can change S by removing some of its characters.
(The characters she does not remove will remain in their original order.)
Illy wants to change S into a magical string by removing as few of its characters as possible.

You are given the string S.
Compute and return the length of the magical string Illy will obtain from S.

DEFINITION
Class:MagicalStringDiv1
Method:getLongest
Parameters:string
Returns:int
Method signature:int getLongest(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character of S will be '<' or '>'.


EXAMPLES

0)
"<><><<>"

Returns: 4

The longest magical string Illy can produce is ">><<".
Its length is 4.
To change S into ">><<", Illy must remove the characters at 0-based indices 0, 2, and 6.

1)
">>><<<"

Returns: 6

S is already a magical string. Therefore Illy doesn't have to remove any character.


2)
"<<<>>>"

Returns: 0

Illy has to remove all characters of S.

3)
"<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>"

Returns: 24


>>>>>>>>><>><>>><<<<>><>>>>><<>>>>><><<<<>>"

******************************/
// END CUT HERE
#line 66 "MagicalStringDiv1.cpp"
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

class MagicalStringDiv1Try {
	public:
	int getLongest(string S) {
		int ans=0;
		REP(l, S.size()) {
			int a = count(&S[0], &S[l], '>');
			int b = count(&S[l], &S[S.size()], '<');
			int lans = min(a, b)*2;
			ans=max(ans, lans);
		}
		return ans;
	}
};
class MagicalStringDiv1 {
	public:
	int getLongest(string S) {
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
#define END	 verify_case(_, MagicalStringDiv1().getLongest(S));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string S = "<><><<>"; 
	int _ = 4; 
END
CASE(1)
	string S = ">>><<<"; 
	int _ = 6; 
END
CASE(2)
	string S = "<<<>>>"; 
	int _ = 0; 
END
CASE(3)
	string S = "<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>"; 
	int _ = 24; 
END
#if 01  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10;loop++) {
// param type: String
start_time=clock();
	string S; 
	{
		int N=UNIFORM_LL(1, 51);
		S = string(N, ' '); 
		string tb = "<>";
		REP(i, N) {
			S[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	int _0 = MagicalStringDiv1().getLongest(S);
	int _1 = MagicalStringDiv1Try().getLongest(S);
	if(!verify_case(_0, _1, true)) {
print(S);
	}
}
#endif

}
// END CUT HERE
