// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// The currency system in Colorland consists of various types of coins. The coin denominations follow these simple rules:


The denominations are distinct positive integers.
There is a coin type with denomination 1.
For each pair of different coin types, the denomination of one coin type divides the denomination of the other one.


You are given a long[] values containing all the available denominations in ascending order.

Coins of different denominations look exactly the same except that they have different colors. Each coin in Colorland has exactly one color. The coin colors follow these even simpler rules:


All coins of the same type are of the same color.
No two coins of different types are of the same color.


You know all coin denominations used in Colorland, but you don't know their colors. You don't even know the set of colors used on the coins.

For each denomination, you'd like to know the color of coins of this denomination. To accomplish this, you've got a credit card with an infinite amount of money. You can perform queries to an ATM which can also provide you with an infinite amount of money. Each query is described by a positive integer X, which means that you want to receive exactly X units of money from the ATM. The ATM will provide you with the requested amount. You also know that the requested amount will be paid using the smallest possible number of coins. (Note that this rule always uniquely determines the set of coins chosen to make the payment.)

Return the smallest number of queries you need to determine the corresponding color for each of the denominations. (Note that this can always be done in a finite number of queries.)


DEFINITION
Class:ColorfulCoins
Method:minQueries
Parameters:vector<long long>
Returns:int
Method signature:int minQueries(vector<long long> values)


CONSTRAINTS
-values will contain between 1 and 60 elements, inclusive.
-Each element of values will be between 1 and 10^18, inclusive.
-values will be sorted in strictly ascending order. Note that this also implies that all the elements of values will be distinct.
-For each pair of different elements in values, the smaller one will be a divisor of the larger one.
-values[0] will be 1.


EXAMPLES

0)
{1}

Returns: 1

There is just one coin type. We have to make a query to learn the color of coins.

1)
{1, 3}

Returns: 1

Just one query with X = 5 is one possible solution. As the ATM gives the smallest number of coins, it will give one coin of denomination 3 and two coins of denomination 1. That means, for example, that if you get one red coin and two blue coins, you'll understand that coins of denomination 3 are red, and coins of denomination 1 are blue.

2)
{1, 2, 4}

Returns: 2

One optimal solution is to make two queries, first X = 5 and then X = 6. After the first query you'll receive one coin from each of denominations 1 and 4, and after the second query you'll receive one coin from each of denominations 2 and 4. Now you can uniquely determine the color of each denomination. For example, coins of denomination 4 have the color which appears twice among the received coins.

3)
{1, 2, 4, 8, 16}

Returns: 3



4)
{1, 2, 6, 30, 90, 270, 810, 2430, 7290, 29160, 87480, 262440, 787320, 3149280,
  9447840, 28343520, 56687040, 170061120, 510183360, 1530550080, 3061100160,
  9183300480, 27549901440, 82649704320, 247949112960, 1239745564800, 3719236694400,
  14876946777600, 44630840332800, 223154201664000, 669462604992000, 2008387814976000,
  6025163444928000, 12050326889856000, 24100653779712000, 72301961339136000,
  289207845356544000, 867623536069632000}

Returns: 4



******************************/
// END CUT HERE
#line 89 "ColorfulCoins.cpp"
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

ll po(ll a, ll b) {
	ll v=1;
	REP(i, b) {
		v*=a;
		if(v>10000) return 10000;
	}
	return v;
}

class ColorfulCoins {
	public:
	int minQueries(vector<long long> V) {
		int N=V.size();
		map<ll, ll> hi;
		RANGE(i, 1, N) {
			ll v = V[i]/V[i-1];
			hi[v]++;
		}
		hi[1LL<<60]++;
		cout<<hi<<endl;
		RANGE(n, 1, N+1) {
			ll used=0;
			int ok=1;
			FOR(e, hi) {
				ll cap = po(e->first, n) - 1 - used;
//				cout<<"C "<<cap<<" "<<e->first<<" "<<e->second<<endl;
				if(cap < e->second) {ok=0;break;}
				used += e->second;
			}
			if(ok) return n;
		}
		return -1;
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
#define END	 verify_case(_, ColorfulCoins().minQueries(values));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	long values_[] = {1};
	  vector<long long> values(values_, values_+sizeof(values_)/sizeof(*values_)); 
	int _ = 1; 
END
CASE(1)
	long values_[] = {1, 3};
	  vector<long long> values(values_, values_+sizeof(values_)/sizeof(*values_)); 
	int _ = 1; 
END
CASE(2)
	long values_[] = {1, 2, 4};
	  vector<long long> values(values_, values_+sizeof(values_)/sizeof(*values_)); 
	int _ = 2; 
END
CASE(3)
	long values_[] = {1, 2, 4, 8, 16};
	  vector<long long> values(values_, values_+sizeof(values_)/sizeof(*values_)); 
	int _ = 3; 
END
CASE(4)
	long values_[] = {1, 2, 6, 30, 90, 270, 810, 2430, 7290, 29160, 87480, 262440, 787320, 3149280,
  9447840, 28343520, 56687040, 170061120, 510183360, 1530550080, 3061100160,
  9183300480, 27549901440, 82649704320, 247949112960, 1239745564800, 3719236694400,
  14876946777600, 44630840332800, 223154201664000, 669462604992000, 2008387814976000,
  6025163444928000, 12050326889856000, 24100653779712000, 72301961339136000,
  289207845356544000, 867623536069632000};
	  vector<long long> values(values_, values_+sizeof(values_)/sizeof(*values_)); 
	int _ = 4; 
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
// param type: long
	vector<long long> values; 
	{
		int N=UNIFORM_LL(1, 51);
		values = vector<long long>(N); 
		REP(i, N) {
			values[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = ColorfulCoins().minQueries(values);
	int _1 = ColorfulCoinsRef().minQueries(values);
	if(!verify_case(_0, _1, true)) {
print(values);
	}
}
#endif

}
// END CUT HERE
