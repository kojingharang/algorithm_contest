// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are playing a card game.
In the card game, each card holds a magic spell with two properties: its level and its damage.
During the game, you will play some of the cards (possibly none or all of them) to attack your enemy.



Initially, there are n cards.
The cards are placed in a row and they are labeled from 0 to n-1, in order.
You are given two vector <int>s: level and damage.
For each i, the level of card i is level[i], and its damage is damage[i].



In each turn of the game, you can do one of two possible actions:


Let L be the level and D the damage of the card that is currently the leftmost card in the row.
If there are at least L cards in the row, you may play the leftmost card.
Playing it deals D damage to your enemy.
After you play this card, the first L cards in the row (including the played one) are discarded.
That is, the cards currently labeled 0 through (L-1), inclusive, are discarded.
The order of the remaining cards does not change.


If you have at least one card, you can take the last card in the row and move it to the beginning.
For example, if the row initially contained cards A,B,C,D,E, in this order, after this operation it will contain E,A,B,C,D.


After each turn, the cards are relabeled 0 through x-1, where x is their current count.



Return the maximal total damage you can deal to your opponent.

DEFINITION
Class:SpellCards
Method:maxDamage
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int maxDamage(vector <int> level, vector <int> damage)


CONSTRAINTS
-level will contain between 1 and 50 elements, inclusive.
-level and damage will contain the same number of elements.
-Each element in level will be between 1 and 50, inclusive.
-Each element in damage will be between 1 and 10,000, inclusive.


EXAMPLES

0)
{1,1,1}
{10,20,30}

Returns: 60

You can play card 0 three times in a row, dealing 10+20+30 = 60 damage.

1)
{3,3,3}
{10,20,30}

Returns: 30

Here, it is optimal to start by moving the last card to the beginning of the row.
In the second turn we then use the card and deal 30 damage.
Afterwards, all three cards are discarded.

2)
{4,4,4}
{10,20,30}

Returns: 0

This time you can't use any spell card.

3)
{50,1,50,1,50}
{10,20,30,40,50}

Returns: 60

You can use 2 cards with damage 20 and 40.

4)
{2,1,1}
{40,40,10}

Returns: 80



5)
{1,2,1,1,3,2,1}
{10,40,10,10,90,40,10}

Returns: 170



6)
{1,2,2,3,1,4,2}
{113,253,523,941,250,534,454}

Returns: 1918



*/
// END CUT HERE
#line 116 "SpellCards.cpp"

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
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class SpellCards {
	public:
	int maxDamage(vector <int> L, vector <int> D) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//mplate<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// os << "{ ";
// for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
// os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, SpellCards().maxDamage(level, damage));}
int main(){

CASE(0)
	int level_[] = {1,1,1};
	  vector <int> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
	int damage_[] = {10,20,30};
	  vector <int> damage(damage_, damage_+sizeof(damage_)/sizeof(*damage_)); 
	int _ = 60; 
END
CASE(1)
	int level_[] = {3,3,3};
	  vector <int> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
	int damage_[] = {10,20,30};
	  vector <int> damage(damage_, damage_+sizeof(damage_)/sizeof(*damage_)); 
	int _ = 30; 
END
CASE(2)
	int level_[] = {4,4,4};
	  vector <int> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
	int damage_[] = {10,20,30};
	  vector <int> damage(damage_, damage_+sizeof(damage_)/sizeof(*damage_)); 
	int _ = 0; 
END
CASE(3)
	int level_[] = {50,1,50,1,50};
	  vector <int> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
	int damage_[] = {10,20,30,40,50};
	  vector <int> damage(damage_, damage_+sizeof(damage_)/sizeof(*damage_)); 
	int _ = 60; 
END
CASE(4)
	int level_[] = {2,1,1};
	  vector <int> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
	int damage_[] = {40,40,10};
	  vector <int> damage(damage_, damage_+sizeof(damage_)/sizeof(*damage_)); 
	int _ = 80; 
END
CASE(5)
	int level_[] = {1,2,1,1,3,2,1};
	  vector <int> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
	int damage_[] = {10,40,10,10,90,40,10};
	  vector <int> damage(damage_, damage_+sizeof(damage_)/sizeof(*damage_)); 
	int _ = 170; 
END
CASE(6)
	int level_[] = {1,2,2,3,1,4,2};
	  vector <int> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
	int damage_[] = {113,253,523,941,250,534,454};
	  vector <int> damage(damage_, damage_+sizeof(damage_)/sizeof(*damage_)); 
	int _ = 1918; 
END

}
// END CUT HERE
