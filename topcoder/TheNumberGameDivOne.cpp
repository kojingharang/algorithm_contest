// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// John and Brus play a game with a number.
The game starts with a positive integer n.
The two players take alternating turns, John starts.
Each move looks as follows:
Let C be the current value of the integer.
The current player has to choose a positive divisor of the number C, other than 1 and C.
Once he chooses the divisor, he has to subtract it from C.
The result is the new number with which the other player now starts his move.
If a player cannot make a valid move, he loses the game.


For example, if they start with n=15, one possible gameplay can look as follows:

John takes the number 15, chooses its divisor 3, and decreases the number to 15-3 = 12.
Brus takes the number 12, chooses its divisor 4, and decreases the number to 12-4 = 8.
John takes the number 8, chooses its divisor 2, and decreases the number to 8-2 = 6.
Brus takes the number 6, chooses its divisor 3, and decreases the number to 6-3 = 3.
John takes the number 3, and as there are no divisors other than 1 and 3, he has no valid move and thus he loses the game.



You are given the long long n.
Assume that both players use the optimal strategy while playing the game.
Return "John" (quotes for clarity) if John wins the game and "Brus" otherwise.


DEFINITION
Class:TheNumberGameDivOne
Method:find
Parameters:long long
Returns:string
Method signature:string find(long long n)


CONSTRAINTS
-n will be between 1 and 10^18, inclusive.


EXAMPLES

0)
6

Returns: "John"

John has two possible moves: either decrease 6 by 2 or decrease 6 by 3.
If he chooses the second option, Brus will have no possible moves, hence John will win the game.

1)
2

Returns: "Brus"



2)
747

Returns: "Brus"



3)
128

Returns: "Brus"



*/
// END CUT HERE
#line 76 "TheNumberGameDivOne.cpp"

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
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

#define DPS 10000000
char dp[DPS];
int depth=0;
int f(const ll n) {
	if(n<DPS && dp[n]!=-1) return dp[n];
	
	ll d=2;
	for(;d*d<=n;d++) {
		if(n%d==0) {
			int r = f(n-d);
			if(!r) return dp[n] = 1;
			r = f(n-n/d);
			if(!r) return dp[n] = 1;
		}
	}
	if(d*d==n) {
		int r = f(n-d);
		if(!r) return dp[n] = 1;
	}
	return dp[n] = 0;
}

class TheNumberGameDivOne {
	public:
	string find(long long n) {
		//ll wn = n;
		//while(wn%2==0) wn/=2;
		//if(wn>1) {
		//	return n%2 ? "Brus" : "John";
		//} else {
		//	return "Brus";
		//}
		memset(dp, -1, DPS);
		int r = f(n);
		//cout<<"DP ";
		//REP(i, n+1) cout<<i<<":"<<(dp[i]==1?"1":(dp[i]==0?"0":"?"))<<" ";
		//cout<<endl;
		
		return r ? "John" : "Brus";
	}
	void go() {
		//cout<<16<<" "<<find(16)<<endl;
		//return;
		RANGE(n, 2, 1040) {
			cout<<n<<" "<<find(n)<<endl;
		}
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
void verify_case(const string& Expected, const string& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, TheNumberGameDivOne().find(n));}
int main(){
TheNumberGameDivOne().go();
return 0;

CASE(0)
	long long n = 6LL; 
	string _ = "John"; 
END
CASE(1)
	long long n = 2LL; 
	string _ = "Brus"; 
END
CASE(2)
	long long n = 747LL; 
	string _ = "Brus"; 
END
CASE(3)
	long long n = 128LL; 
	string _ = "Brus"; 
END
//return 0;
CASE(3)
	long long n = 10000000LL; 
	string _ = "Brus"; 
END

}
// END CUT HERE
