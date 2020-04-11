// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Limak is in a casino.
He has b dollars.
He wants to have at least c dollars (to be able to buy flowers for a girl he likes).
In order to achieve that, he must win the money he's missing.

The casino allows guests to risk some of their money on bets.
Limak can make as many bets as he likes, but he has to make them one after another.
Each time Limak makes a bet, he chooses the amount he wants to bet.
The amount must be a positive integer.
Each bet has two possible outcomes: either Limak loses the money, or he gets it back doubled.

For example, suppose Limak has 20 dollars.
If he bets 5, he will be left with 20 - 5 = 15 dollars.
If he loses the bet, that is his new total.
If he wins the bet, he'll get back 2*5 = 10 dollars, which will bring his total up to 15 + 10 = 25 dollars.

Limak doesn't want to lose all his money.
More precisely, he wants to make sure that at any moment he will have at least a dollars.
He will not make a bet if losing the bet would mean that he will have less than a dollars.

For example, suppose Limak currently has 20 dollars.
If a = 15, in the next round Limak can bet 1, 2, 3, 4, or 5 dollars.
Note that a bet of 6 dollars is not allowed: if he lost it, he would have 20 - 6 = 14 dollars, which is less than a.

You are given the ints a, b, and c.
We will assume that Limak follows the rules described above when choosing the amounts to bet.
Compute and return the smallest B such that Limak can reach his goal (i.e., have at least c dollars) after making B bets.

DEFINITION
Class:SafeBetting
Method:minRounds
Parameters:int, int, int
Returns:int
Method signature:int minRounds(int a, int b, int c)


CONSTRAINTS
-a, b and c will each be between 1 and 1000, inclusive.
-a will be smaller than b.
-b will be smaller than c.


EXAMPLES

0)
15
20
48

Returns: 3

Limak has 20 dollars.
He wants to have at least 48 dollars.
He can never have less than 15 dollars.

In the first round Limak can bet at most 5 dollars (as explained in the example in the problem statement).
If he bets 5 and wins, he will have 25 dollars.
In the second round he will be able to bet at most 10 dollars.
If he wins that round as well, he will have 35 dollars.
Finally, it is possible that in the third round Limak will bet 13 dollars and he will win the bet.
At that moment he will have exactly 48 dollars.

The correct return value is 3, because Limak needed to place at least 3 bets.
He cannot reach 48 dollars by placing fewer than 3 bets.

1)
10
400
560

Returns: 1



2)
5
7
21

Returns: 3



3)
5
7
22

Returns: 4



4)
17
30
1000

Returns: 7



*/
// END CUT HERE
#line 108 "SafeBetting.cpp"

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
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }



class SafeBetting {
	public:
	int minRounds(int a, int b, int c) {
		ll ans = 0;
		while(b<c) {
			b = b+(b-a);
			ans++;
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
#define END	 verify_case(_, SafeBetting().minRounds(a, b, c));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int a = 15; 
	int b = 20; 
	int c = 48; 
	int _ = 3; 
END
CASE(1)
	int a = 10; 
	int b = 400; 
	int c = 560; 
	int _ = 1; 
END
CASE(2)
	int a = 5; 
	int b = 7; 
	int c = 21; 
	int _ = 3; 
END
CASE(3)
	int a = 5; 
	int b = 7; 
	int c = 22; 
	int _ = 4; 
END
CASE(4)
	int a = 17; 
	int b = 30; 
	int c = 1000; 
	int _ = 7; 
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
	int a = UNIFORM_LL(0, 100); 
// param type: int
	int b = UNIFORM_LL(0, 100); 
// param type: int
	int c = UNIFORM_LL(0, 100); 
	int _0 = SafeBetting().minRounds(a, b, c);
	int _1 = SafeBettingRef().minRounds(a, b, c);
	if(!verify_case(_0, _1, true)) {
print(a);
print(b);
print(c);
	}
}
#endif

}
// END CUT HERE
