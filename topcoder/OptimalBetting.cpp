// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Limak is in a casino.
He has a dollars.
He wants to have at least b dollars (to be able to buy a Valentine's day present for a girl he likes).
He will try to win the missing money by playing games in the casino.
He has enough time to play at most k times.

Limak is a simple bear, so he only plays the simplest game.
In this game he can bet any non-negative integer amount (not exceeding his current balance).
With probability 50% he loses the bet and with probability 50% he gets it back doubled.
For example, suppose he has 10 dollars and he bets 3. If he loses, he will have 10-3 = 7 dollars, if he wins, he will have 7+2*3 = 10+3 = 13 dollars.

Limak does not know anything about strategies.
Therefore, each time he plays a game, he chooses the amount to bet uniformly at random among all valid bets.
For example, if he currently has 5 dollars, in the next game he will bet 0, 1, 2, 3, 4, or 5 dollars, each with probability 1/6.

As soon as he has at least b dollars, he stops playing and leaves the casino.
He also leaves the casino after playing k games, regardless of whether he has reached his goal.

Of course, there are different ways to play this sequence of games.
An optimal strategy is a strategy that always chooses the amount one should bet in a way that maximizes the probability of reaching Limak's goal.
There can be multiple optimal strategies.

You are given the ints a, b, and k.
Compute the probability that the sequence of Limak's bets will follow an optimal strategy.

In other words, compute the probability that to a random observer (who knows Limak's goal but not his way of playing) it will seem that Limak follows an optimal strategy throughout his entire stay in the casino.

DEFINITION
Class:OptimalBetting
Method:findProbability
Parameters:int, int, int
Returns:double
Method signature:double findProbability(int a, int b, int k)


NOTES
-Your return value must have absolute error smaller than 1e-8.


CONSTRAINTS
-a and b will be between 1 and 100,000, inclusive.
-a will be smaller than b.
-k will be between 1 and 5, inclusive.


EXAMPLES

0)
23
26
1

Returns: 0.875

Limak only has the time for a single round.
If he bets 0, 1, or 2, the probability that he reaches his goal is 0%.
Otherwise, the probability is 50%: if he wins the bet, he will have at least 26 dollars.
Thus, the optimal strategy is to bet any amount that is at least 3 dollars.
Limak will choose such an amount with probability 21/24.

1)
7
1000
3

Returns: 1.0

Regardless of the amounts Limak bets, he will never reach his goal.
Thus, all strategies are optimal: each of them maximizes the probability of reaching Limak's goal.
(Sadly, the maximum probability is zero.)

2)
2
3
2

Returns: 0.8888888888888887



3)
7
8
3

Returns: 0.06785714285714287



4)
10
20
2

Returns: 0.09917355371900842



5)
1234
1567
5

Returns: 0.00861475126753315



6)
50123
87654
5

Returns: 0.02304278352341867



*/
// END CUT HERE
#line 123 "OptimalBetting.cpp"

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



class OptimalBetting {
	public:
	double findProbability(int a, int b, int k) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const double& Expected, const double& Received, bool noPASSmsg=false) {
 double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, OptimalBetting().findProbability(a, b, k));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int a = 23; 
	int b = 26; 
	int k = 1; 
	double _ = 0.875; 
END
CASE(1)
	int a = 7; 
	int b = 1000; 
	int k = 3; 
	double _ = 1.0; 
END
CASE(2)
	int a = 2; 
	int b = 3; 
	int k = 2; 
	double _ = 0.8888888888888887; 
END
CASE(3)
	int a = 7; 
	int b = 8; 
	int k = 3; 
	double _ = 0.06785714285714287; 
END
CASE(4)
	int a = 10; 
	int b = 20; 
	int k = 2; 
	double _ = 0.09917355371900842; 
END
CASE(5)
	int a = 1234; 
	int b = 1567; 
	int k = 5; 
	double _ = 0.00861475126753315; 
END
CASE(6)
	int a = 50123; 
	int b = 87654; 
	int k = 5; 
	double _ = 0.02304278352341867; 
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
	int k = UNIFORM_LL(0, 100); 
	double _0 = OptimalBetting().findProbability(a, b, k);
	double _1 = OptimalBettingRef().findProbability(a, b, k);
	if(!verify_case(_0, _1, true)) {
print(a);
print(b);
print(k);
	}
}
#endif

}
// END CUT HERE
