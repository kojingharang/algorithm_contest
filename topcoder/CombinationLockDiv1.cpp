// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Andrew has a combination lock.
The lock consists of multiple dials that are placed next to each other.
Each dial contains the digits 0 through 9, in order.
At any moment, exactly one of the digits on each dial is visible.
The string formed by the currently visible digits is called the current combination.

The visible digit on a dial can be changed by rotating the dial up or down.
Rotating the dial up changes 0 to 1, 1 to 2, and so on.
Note that the digits on a dial wrap around: if we rotate up a dial that shows a 9, it will show a 0 again.
Naturally, rotating the dial down changes the digit in the other direction.

We are able to rotate multiple dials at the same time, as long as they are next to each other.
More precisely, in a single turn we can take an arbitrarily long segment of consecutive dials, and rotate all of them one step in the same direction (i.e., either all of them up, or all of them down).

For example, suppose that the current combination is "123".
In one step, we can change it to many different combinations, including "012" (all three dials down), "234" (all three dials up), "133" (middle dial up), and "013" (first two dials down).
Note that we cannot change "123" to "224" in a single step.

You are given two vector <string>s: P and Q.
Concatenate the elements of P to get S.
S is the current combination.
Concatenate the elements of Q to get T.
T is the secret combination that unlocks the lock.
That is, to open the lock we need to change S into T by rotating some of the dials.
Return the smallest number of steps needed.

DEFINITION
Class:CombinationLockDiv1
Method:minimumMoves
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int minimumMoves(vector <string> P, vector <string> Q)


CONSTRAINTS
-P and Q will each contain no more than 50 elements.
-Each element of P and Q will contain no more than 50 characters.
-S will contain at least 1 character.
-S will contain the same number of characters as T.
-Each character in S and T will be a digit ('0'-'9').


EXAMPLES

0)
{"123"}
{"112"}

Returns: 1

Rotate the last two dials down.

1)
{"1"}
{"7"}

Returns: 4

Rotate the dial down 4 times: from 1 to 0, from 0 to 9, from 9 to 8, and from 8 to 7.

2)
{"6","07"}
{"","60","7"}

Returns: 0



3)
{"1234"}
{"4567"}

Returns: 3



4)
{"020"}
{"909"}

Returns: 2



5)
{"4423232218340"}
{"6290421476245"}

Returns: 18



******************************/
// END CUT HERE
#line 99 "CombinationLockDiv1.cpp"
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

unsigned short dp[2510][2510][10];// [a, b]->X
class CombinationLockDiv1 {
	public:
	int minimumMoves(vector <string> P, vector <string> Q) {
		string S=accumulate(ALL(P), string(""));
		string T=accumulate(ALL(Q), string(""));
		int N=S.size();
		VI w(N);
		REP(i, N) w[i]=(S[i]-T[i]+10)%10;
		RANGE(L, 1, N+1) REP(i, N-L+1) REP(X, 10) dp[i][i+L-1][X] = 60000;
		RANGE(L, 1, N+1) REP(i, N-L+1) REP(X, 10) {
			int a=w[i], b=w[i+L-1];
			unsigned short lans=0;
			if(X!=a) lans++;
			if(X!=b) lans++;
			if(2<L) {
				unsigned short pmin=60000;
				REP(PX, 10) pmin = min<unsigned short>(pmin, dp[i+1][i+L-1-1][PX] + (X!=PX));
				lans += pmin;
//				cout<<"pmin "<<pmin<<endl;
			}
//			cout<<lans<<endl;
			dp[i][i+L-1][X] = min(dp[i][i+L-1][X], lans);
		}
		unsigned short ans=60000;
		REP(X, 10) ans=min(ans, dp[0][N-1][X]);
		return dp[0][N-1][0];
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, CombinationLockDiv1().minimumMoves(P, Q));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string P_[] = {"123"};
	  vector <string> P(P_, P_+sizeof(P_)/sizeof(*P_)); 
	string Q_[] = {"112"};
	  vector <string> Q(Q_, Q_+sizeof(Q_)/sizeof(*Q_)); 
	int _ = 1; 
END
//return 0;
CASE(1)
	string P_[] = {"1"};
	  vector <string> P(P_, P_+sizeof(P_)/sizeof(*P_)); 
	string Q_[] = {"7"};
	  vector <string> Q(Q_, Q_+sizeof(Q_)/sizeof(*Q_)); 
	int _ = 4; 
END
CASE(2)
	string P_[] = {"6","07"};
	  vector <string> P(P_, P_+sizeof(P_)/sizeof(*P_)); 
	string Q_[] = {"","60","7"};
	  vector <string> Q(Q_, Q_+sizeof(Q_)/sizeof(*Q_)); 
	int _ = 0; 
END
CASE(3)
	string P_[] = {"1234"};
	  vector <string> P(P_, P_+sizeof(P_)/sizeof(*P_)); 
	string Q_[] = {"4567"};
	  vector <string> Q(Q_, Q_+sizeof(Q_)/sizeof(*Q_)); 
	int _ = 3; 
END
CASE(4)
	string P_[] = {"020"};
	  vector <string> P(P_, P_+sizeof(P_)/sizeof(*P_)); 
	string Q_[] = {"909"};
	  vector <string> Q(Q_, Q_+sizeof(Q_)/sizeof(*Q_)); 
	int _ = 2; 
END
CASE(5)
	string P_[] = {"4423232218340"};
	  vector <string> P(P_, P_+sizeof(P_)/sizeof(*P_)); 
	string Q_[] = {"6290421476245"};
	  vector <string> Q(Q_, Q_+sizeof(Q_)/sizeof(*Q_)); 
	int _ = 18; 
END
1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
#if 0  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10;loop++) {
// param type: String
start_time=clock();
	vector <string> P; 
	{
		int N=UNIFORM_LL(1, 50);
		P = vector <string>(N); 
		REP(i, N) {
			P[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: String
start_time=clock();
	vector <string> Q; 
	{
		int N=UNIFORM_LL(1, 50);
		Q = vector <string>(N); 
		REP(i, N) {
			Q[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = CombinationLockDiv1().minimumMoves(P, Q);
	int _1 = CombinationLockDiv1Try().minimumMoves(P, Q);
	if(!verify_case(_0, _1, true)) {
print(P);
print(Q);
	}
}
#endif

}
// END CUT HERE
