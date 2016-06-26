// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Manao likes to play the Division Game with his friends. This two-player game is played with some collection of natural numbers S. Manao plays first and the players alternate in making a move. A move is choosing some number X from S and a natural number Y &gt 1 such that Y divides X. Then, X is replaced by X / Y in the collection. Note that at any moment the collection may contain multiple copies of the same number. The game proceeds until no more moves can be made. The player who managed to make the last move is declared the winner.

Since hot debates arise on what numbers should be in S, the friends decided to regularize their choice. They always choose a contiguous interval of numbers [A, B] to be the initial collection S. That is, at the beginning of the game, the collection S contains each of the integers A through B, inclusive, exactly once. Manao knows that A and B will satisfy the condition L &le A &le B &le R. You are given the ints L and R. Count the number of such intervals for which Manao will win the Division Game given that both players play optimally.

DEFINITION
Class:TheDivisionGame
Method:countWinningIntervals
Parameters:int, int
Returns:long long
Method signature:long long countWinningIntervals(int L, int R)


NOTES
-Only one number from the collection changes in each move. For example, if the collection contains three copies of the number 8, and the player chooses X=8 and Y=4, only one of the 8s in the collection will change to a 2.


CONSTRAINTS
-L will be between 2 and 1,000,000,000, inclusive.
-R will be between L and L + 1,000,000, inclusive.


EXAMPLES

0)
9
10

Returns: 2

If the chosen interval is [9,9] or [10,10], the collection S contains only one number. In these two situations Manao can win the game in a single move. On the other hand, if the chosen interval is [9,10], Manao will lose to an optimally playing opponent.


1)
2
5

Returns: 9

The only case where Manao loses is if the game starts with the interval [2,3]. Note that if the starting interval is [2,5], Manao can choose X=4 and Y=2 in his first move. After that move, the collection will contain the values 2, 2, 3, and 5.

2)
2
6

Returns: 13

Manao will also lose the game if the starting interval is [3,6].

3)
2
100

Returns: 4345



4)
12566125
12567777

Returns: 1313432



*/
// END CUT HERE
#line 71 "TheDivisionGame.cpp"

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

#include <assert.h>

char is_prime[1000010]; // b-a
char is_prime_small[31622+10]; // sqrt(b)

void segment_sieve(ll a, ll b) {
	cout<<a<<" "<<b<<endl;
	for(int i=0; (ll)i*i<b; i++) is_prime_small[i]=1;
	for(int i=0; i<b-a; i++) is_prime[i]=1;
	for(int i=2; (ll)i*i<b; i++) {
		assert(i<(int)sizeof(is_prime_small));
		if(is_prime_small[i]) {
			for(int j=2*i; (ll)j*j<b; j+=i) is_prime_small[j]=0;
			for(ll j=max(2LL, (a+i-1)/i)*i; j<b; j+=i) is_prime[j-a] = 0;
		}
	}
}
int isPrime(ll n){
	ll i;
	if(n < 2) return 0;
	else if(n == 2) return 1;
	if(n % 2 == 0) return 0;
	for(i = 3; i * i <= n; i += 2) if(n % i == 0) return 0;
	return 1;
}
char cum[1000010];

class TheDivisionGame {
	public:
	long long countWinningIntervals(int L, int R) {
		CLEAR(is_prime, 0);
		CLEAR(is_prime_small, 0);
		CLEAR(cum, 0);
		f(L, R+1);
		REP(i, R-L+1) {
			assert(isPrime(i+L)==is_prime[i]);
			cout<<(is_prime[i]?"O":"x");
			if(i%10==9) cout<<endl;
		}
		cout<<endl;
		VI hi(4);
		int x=0;
		REP(i, R-L+1) {
			int v = is_prime[i] ? 1 : 2;
			x^=v;
			cum[i+1]=x;
			cout<<x<<" ";
		}
		cout<<endl;
		REP(i, R-L+1+1) {
			assert(0<=cum[i] && cum[i]<4);
			hi[cum[i]]++;
		}
		ll ans = ((ll)R-L+1)*((ll)R-L+2)/2;
		cout<<ans<<endl;
		REP(i, 4) if(hi[i]>1) ans-=(ll)hi[i]*(hi[i]-1)/2;
		cout<<hi<<endl;
		return ans;
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
void verify_case(const long long& Expected, const long long& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, TheDivisionGame().countWinningIntervals(L, R));}
int main(){

CASE(0)
	int L = 9; 
	int R = 10; 
	long long _ = 2LL; 
END
//return 0;
CASE(1)
	int L = 2; 
	int R = 5; 
	long long _ = 9LL; 
END
CASE(2)
	int L = 2; 
	int R = 6; 
	long long _ = 13LL; 
END
CASE(3)
	int L = 2; 
	int R = 100; 
	long long _ = 4345LL; 
END
CASE(4)
	int L = 12566125; 
	int R = 12567777; 
	long long _ = 1313432LL; 
END

}
// END CUT HERE
