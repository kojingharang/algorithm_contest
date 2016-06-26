// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Petr and Snuke are playing a cooperative card game.
The game is played with special cards: each card is labeled with some positive integer.
The integers on cards are not necessarily distinct.


At the beginning of the game Petr is holding some cards in his hand and Snuke is holding all the other cards in his hand.
You are given vector <int>s petr and snuke that describe the state at the beginning of the game:
the elements of petr are the numbers on Petr's cards and the elements of snuke are the numbers on Snuke's cards.


During the game the players will place some of their cards onto a pile.
Initially, the pile is empty.
The players take alternating turns, Petr goes first.
In each turn, if the current player has no cards in his hand, the game ends.
Otherwise, the player must make exactly one valid move.
There are three types of valid moves:

If the pile is empty, the player may choose any card and place it onto the pile.
If the pile is not empty, the player may choose any card and place it on top of the pile. However, this move is only valid if the number on the new card is strictly greater than the number on the card that was previously on the top of the pile.
The player may always choose one of his cards and eat it.


Petr and Snuke have a common goal: they want to create a pile with as many cards as possible.
Return the size of the pile at the end of the game, assuming that they cooperate and play the game optimally.


DEFINITION
Class:YetAnotherCardGame
Method:maxCards
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int maxCards(vector <int> petr, vector <int> snuke)


CONSTRAINTS
-petr and snuke will contain between 1 and 50 elements, inclusive.
-petr and snuke will contain the same number of elements.
-Each element in petr and snuke will be between 1 and 100, inclusive.


EXAMPLES

0)
{2, 5}
{3, 1}

Returns: 3

One optimal way is as follows.

Petr puts 2 onto the pile.
Snuke puts 3 onto the pile.
Petr puts 5 onto the pile.
Snuke eats 1.
The game ends because Petr has no cards in his hand.



1)
{1, 1, 1, 1, 1}
{1, 1, 1, 1, 1}

Returns: 1

The integers on cards are not necessarily distinct.

2)
{1, 4, 6, 7, 3}
{1, 7, 1, 5, 7}

Returns: 6



3)
{19, 99, 86, 30, 98, 68, 73, 92, 37, 69, 93, 28, 58, 36, 86, 32, 46, 34, 71, 29}
{28, 29, 22, 75, 78, 75, 39, 41, 5, 14, 100, 28, 51, 42, 9, 25, 12, 59, 98, 83}

Returns: 28



******************************/
// END CUT HERE
#line 89 "YetAnotherCardGame.cpp"
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class YetAnotherCardGame {
	public:
	vector<int>AB[2];
	int N;
	map<pair<int, pair<int, pair<int, int>>>, int> memo;
	int f(int turn, int vv, int va, int vb) {
		auto key = MP(turn, MP(vv, MP(va, vb)));
		if(memo.count(key)) return memo[key];

		if(turn==0 && va==N) return 0;
		if(turn==1 && vb==N) return 0;

		int putv = -1;
		int puti = -1;
		int bi=turn?vb:va;
		RANGE(i, bi, N) if(vv<AB[turn][i]) {putv=AB[turn][i]; puti=i;break;}

		int rv=0;
		// put
		if(putv!=-1) {
			int na=va, nb=vb;
			(turn?nb:na) = puti+1;
			rv = max(rv, 1+f(1-turn, putv, na, nb));
		}
		int na=va, nb=vb;
		(turn?nb:na) = (turn?nb:na)+1;
		// noput
		rv = max(rv, f(1-turn, vv, na, nb));
//		cout<<"f "<<turn<<" "<<vv<<" "<<va<<" "<<vb<<" -> "<<rv<<endl;
		memo[key] = rv;
		return rv;
	}
	int maxCards(vector <int> _A, vector <int> _B) {
		sort(ALL(_A));
		sort(ALL(_B));
		cout<<endl;
		cout<<_A<<endl;
		cout<<_B<<endl;
		AB[0]=_A;
		AB[1]=_B;
		N=_A.size();
		return f(0, 0, 0, 0);
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
#define END	 verify_case(_, YetAnotherCardGame().maxCards(petr, snuke));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int petr_[] = {2, 5};
	  vector <int> petr(petr_, petr_+sizeof(petr_)/sizeof(*petr_)); 
	int snuke_[] = {3, 1};
	  vector <int> snuke(snuke_, snuke_+sizeof(snuke_)/sizeof(*snuke_)); 
	int _ = 3; 
END
//return 0;
CASE(1)
	int petr_[] = {1, 1, 1, 1, 1};
	  vector <int> petr(petr_, petr_+sizeof(petr_)/sizeof(*petr_)); 
	int snuke_[] = {1, 1, 1, 1, 1};
	  vector <int> snuke(snuke_, snuke_+sizeof(snuke_)/sizeof(*snuke_)); 
	int _ = 1; 
END
CASE(2)
	int petr_[] = {1, 4, 6, 7, 3};
	  vector <int> petr(petr_, petr_+sizeof(petr_)/sizeof(*petr_)); 
	int snuke_[] = {1, 7, 1, 5, 7};
	  vector <int> snuke(snuke_, snuke_+sizeof(snuke_)/sizeof(*snuke_)); 
	int _ = 6; 
END
CASE(3)
	int petr_[] = {19, 99, 86, 30, 98, 68, 73, 92, 37, 69, 93, 28, 58, 36, 86, 32, 46, 34, 71, 29};
	  vector <int> petr(petr_, petr_+sizeof(petr_)/sizeof(*petr_)); 
	int snuke_[] = {28, 29, 22, 75, 78, 75, 39, 41, 5, 14, 100, 28, 51, 42, 9, 25, 12, 59, 98, 83};
	  vector <int> snuke(snuke_, snuke_+sizeof(snuke_)/sizeof(*snuke_)); 
	int _ = 28; 
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
	vector <int> petr; 
	{
		int N=UNIFORM_LL(1, 51);
		petr = vector <int>(N); 
		REP(i, N) {
			petr[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> snuke; 
	{
		int N=UNIFORM_LL(1, 51);
		snuke = vector <int>(N); 
		REP(i, N) {
			snuke[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = YetAnotherCardGame().maxCards(petr, snuke);
	int _1 = YetAnotherCardGameRef().maxCards(petr, snuke);
	if(!verify_case(_0, _1, true)) {
print(petr);
print(snuke);
	}
}
#endif

}
// END CUT HERE
