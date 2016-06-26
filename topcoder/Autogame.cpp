// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Hero is playing a game with tokens.
There are N places for tokens.
The places are numbered 1 through N.
There are also N arrows, each pointing from some place to some place.
No two arrows start at the same place.
It is possible that multiple arrows point to the same place.
Also, an arrow may start and end at the same place.

You are given the description of the game board: a vector <int> a with N elements.
For each i between 1 and N, inclusive, the arrow that starts at the place i points to the place a[i-1].

At the beginning of the game, Hero will take an arbitrary number of tokens between 0 and N, inclusive, and he will place them onto distinct places.
He will then play K rounds of the game.
In each round each token moves from its current place along the arrow to the new place.
After each round, Hero checks whether all tokens are still in distinct places.
If two or more tokens are in the same place, Hero loses the game.
Hero wins the game if he does not lose it during the K rounds he plays.

There may be multiple ways how Hero can win the game.
Two ways are different if there is some i such that at the beginning of the game place i did contain a token in one case but not in the other.
Count those ways and return their count modulo 1,000,000,007.


DEFINITION
Class:Autogame
Method:wayscnt
Parameters:vector <int>, int
Returns:int
Method signature:int wayscnt(vector <int> a, int K)


CONSTRAINTS
-a will contain exactly N elements.
-N will be between 1 and 50, inclusive.
-Each element in a will be between 1 and N, inclusive.
-K will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1,2,3}
5

Returns: 8

There are 2^3 = 8 valid ways to place the tokens. In each round each token will stay in the same place. Hence, Hero will win the game for each initial placement of tokens.

1)
{1,1,1}
1

Returns: 4

If Hero starts the game with two or three tokens, after the first round there will be multiple tokens in the same place (place 1) and Hero will lose the game. He will only win the game if he starts with 0 tokens (1 possibility) or with 1 token (3 possibilities).

2)
{2,1}	
42

Returns: 4



3)
{2,3,4,3}
3

Returns: 9



4)
{4,4,3,2,1}
3

Returns: 18



******************************/
// END CUT HERE
#line 87 "Autogame.cpp"
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

class Autogame {
	public:
	int wayscnt(vector <int> a, int K) {
		int N=a.size();
		VI w(N);
		REP(i, N) w[i]=1;
		REP(loop, min(K, 1000)) {
			VI nw(N);
			REP(i, N) nw[a[i]-1]+=w[i];
			w = nw;
		}
//		cout<<w<<endl;
		ll ans=1;
		REP(i, N) {
			ans*=w[i]+1;
			ans %= 1000000007LL;
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
#define END	 verify_case(_, Autogame().wayscnt(a, K));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int a_[] = {1,2,3};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int K = 5; 
	int _ = 8; 
END
CASE(1)
	int a_[] = {1,1,1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int K = 1; 
	int _ = 4; 
END
CASE(2)
	int a_[] = {2,1}	;
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int K = 42; 
	int _ = 4; 
END
CASE(3)
	int a_[] = {2,3,4,3};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int K = 3; 
	int _ = 9; 
END
CASE(4)
	int a_[] = {4,4,3,2,1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int K = 3; 
	int _ = 18; 
END
CASE(3)
	int a_[] = {2,3,4,3};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int K = 1; 
	int _ = 12; 
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
	vector <int> a; 
	{
		int N=UNIFORM_LL(1, 51);
		a = vector <int>(N); 
		REP(i, N) {
			a[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int K = UNIFORM_LL(0, 100); 
	int _0 = Autogame().wayscnt(a, K);
	int _1 = AutogameRef().wayscnt(a, K);
	if(!verify_case(_0, _1, true)) {
print(a);
print(K);
	}
}
#endif

}
// END CUT HERE
