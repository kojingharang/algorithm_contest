// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Shiny likes to play games.
Her favorite games are games with pebbles (small stones).
Today, she is playing such a game with her friend Lucy.

Initially, there are N piles of stones.
You are given a vector <int> number with N elements.
Each element of number is the number of stones in one of the piles.

The players take alternating turns.
Shiny plays first.
In each turn, the current player must:

Choose a pile X that has at least two stones.
Split the chosen pile X into two non-empty parts A and B. (The parts can have arbitrary sizes, as long as both are non-empty.)
Choose two piles Y and Z. (Y and Z must be different non-empty piles other than X.)
Add all stones from A to the pile X, and all stones from B to the pile Y.


For example, if the current piles are {1, 2, 50}, the current player could:

Choose the pile with 50 stones as X.
Split it into two parts with 25 stones each.
Choose the other two piles (the ones with 1 and 2 stones) to be Y and Z.
Add all stones from A to the pile X, and all stones from B to the pile Y. At the end of the turn, there are two piles of stones: one with 26 and one with 27 stones.


The player who cannot make a valid move loses the game.
Assume that both players play the game optimally.
Return the string "WIN" (quotes for clarity) if Shiny wins the game, and "LOSE" if she does not.


DEFINITION
Class:SplitStoneGame
Method:winOrLose
Parameters:vector <int>
Returns:string
Method signature:string winOrLose(vector <int> number)


CONSTRAINTS
-number will contain between 1 and 50 elements, inclusive.
-Each element of number will be between 1 and 50, inclusive.


EXAMPLES

0)
{1, 1, 1}

Returns: "LOSE"

Shiny can't choose a pile X that has at least two stones, so she loses.

1)
{2, 2}

Returns: "LOSE"

After Shiny chooses one of the piles as X and splits it into two piles with one stone each, she is
unable to choose Y and Z, because there is only one pile left to choose from at the moment. Thus,
she cannot make a valid move and therefore she loses the game.

2)
{1, 1, 2}

Returns: "WIN"

Shiny can choose the last pile as X, split it into 1+1 stone, and add those stones to the other two
piles. This is a valid move that produces two piles with two stones each, and it is now Lucy's turn. 
As we saw in Example 1, Lucy now has no valid move left, thus she loses the game and Shiny is the
winner.

3)
{1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1}

Returns: "WIN"



4)
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1}

Returns: "LOSE"



******************************/
// END CUT HERE
#line 94 "SplitStoneGame.cpp"
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

bool f[60][60], g[60][60];
bool Calc(int i, int j) {
	if(i==0) return 0;
	if(i+j<=2) return 0;
	if(!g[i][j]) {
		g[i][j]=1; f[i][j]=0;
		if(i>=1&&j>=2&&Calc(i+1,j-2)==0)f[i][j]=1;
		if(i>=2&&j>=1&&Calc(i,j-1)==0)f[i][j]=1;
		if(i>=3&&j>=0&&Calc(i-1,j)==0)f[i][j]=1;
	}
	return f[i][j];
}
class SplitStoneGame {
	public:
	string winOrLose(vector <int> num) {
		int N=num.size();
		int A=0,B=0;
		REP(i, N) if(num[i]==1) ++B; else ++A;
		if(Calc(A, B)) return "WIN";
		return "LOSE";
	}
};
class SplitStoneGameRef {
	public:
	map<pair<int, int>, bool> memo;
	bool f(int a, int n) {
		if(n<3) return false;
		if(a==0) return false;
		PII key = MP(a, n);
		if(memo.count(key)) return memo[key];
		bool allWin = true;
		RANGE(na, max(2, a-1), a-1+2+1) {
			allWin = allWin && f(na, n-1);
		}
		return memo[key] = !allWin;
	}
	string winOrLose(vector <int> num) {
		int a=0;
		REP(i, num.size()) if(num[i]>=2) a++;
		return f(a, num.size()) ? "WIN" : "LOSE";
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
#define END	 verify_case(_, SplitStoneGame().winOrLose(number));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int number_[] = {1, 1, 1};
	  vector <int> number(number_, number_+sizeof(number_)/sizeof(*number_)); 
	string _ = "LOSE"; 
END
CASE(1)
	int number_[] = {2, 2};
	  vector <int> number(number_, number_+sizeof(number_)/sizeof(*number_)); 
	string _ = "LOSE"; 
END
CASE(2)
	int number_[] = {1, 1, 2};
	  vector <int> number(number_, number_+sizeof(number_)/sizeof(*number_)); 
	string _ = "WIN"; 
END
CASE(3)
	int number_[] = {1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1};
	  vector <int> number(number_, number_+sizeof(number_)/sizeof(*number_)); 
	string _ = "WIN"; 
END
CASE(4)
	int number_[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1};
	  vector <int> number(number_, number_+sizeof(number_)/sizeof(*number_)); 
	string _ = "LOSE"; 
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
for(int loop=0;loop<100000;loop++) {
// param type: int
	vector <int> number; 
	{
		int N=UNIFORM_LL(1, 6);
		number = vector <int>(N); 
		REP(i, N) {
			number[i] = UNIFORM_LL(1, 51);
		}
	}
	string _0 = SplitStoneGame().winOrLose(number);
	string _1 = SplitStoneGameRef().winOrLose(number);
	if(!verify_case(_0, _1, true)) {
print(number);
	}
}
#endif

}
// END CUT HERE
