// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Bob is playing with his ball destroyer robot. Initially, Bob had r red balls, g green balls and b blue balls. The robot repeated the following 3-step program until there were no balls left:

If there is at least one red ball available, destroy one red ball.
If there is at least one green ball available, destroy one green ball.
If there is at least one blue ball available, destroy one blue ball.

Bob forgot how many balls of each color he initially had. He only remembers that there were n balls in total and that the k-th (1-based index) ball that was destroyed was red. Return the total number of different initial settings that match that description. Formally, return the number of different tuples (r, g, b) such that r + g + b = n and the k-th ball that was destroyed was red.

DEFINITION
Class:AlternateColors2
Method:countWays
Parameters:int, int
Returns:long long
Method signature:long long countWays(int n, int k)


NOTES
-It follows from the constraints that the return value will always fit into a long long.


CONSTRAINTS
-n will be between 1 and 100000, inclusive.
-k will be between 1 and n, inclusive.


EXAMPLES

0)
1
1

Returns: 1

There was only one ball. This ball was necessarily the first ball destroyed. Therefore, it had to be red.

1)
3
3

Returns: 3

There are three cases in which the third ball to be destroyed is red:
r = 3, b = 0, g = 0.
r = 2, b = 1, g = 0.
r = 2, b = 0, g = 1.

2)
6
4

Returns: 9



3)
6
1

Returns: 21



4)
1000
2

Returns: 1

In order for the second destroyed ball to be red, there would have to be zero balls of the other colors.

5)
100000
100000

Returns: 1666700000



*/
// END CUT HERE
#line 85 "AlternateColors2.cpp"

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



class AlternateColors2 {
	public:
	long long countWays(int N, int K) {
		ll ans = 0;
		REP(r, N+1) REP(g, N-r+1) {
			int R=r, G=g, B=N-R-G;
			//cout<<R<<" "<<G<<" "<<B<<endl;
			int co=0;
			while(1) {
				if(R) { R--; co++; }
				if(co==K) {ans++; break;}
				if(G) { G--; co++; }
				if(co==K) break;
				if(B) { B--; co++; }
				if(co==K) break;
			}
		}
		return ans;
	}
	void test() {
		VVI w(101, VI(101));
		RANGE(N, 1, 100) RANGE(K, 1, N+1) {
			ll ans = countWays(N, K);
			w[N][K]=ans;
			cout<<N<<" "<<K<<" "<<ans<<endl;
		}
		RANGE(K, 1, 100) {
			RANGE(N, 1, 100) cout<<w[N][K]-w[N-1][K]<<" ";
			cout<<endl;
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
void verify_case(const long long& Expected, const long long& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, AlternateColors2().countWays(n, k));}
int main(){
AlternateColors2().test();
return 0;

CASE(0)
	int n = 1; 
	int k = 1; 
	long long _ = 1LL; 
END
//return 0;
CASE(1)
	int n = 3; 
	int k = 3; 
	long long _ = 3LL; 
END
CASE(2)
	int n = 6; 
	int k = 4; 
	long long _ = 9LL; 
END
CASE(3)
	int n = 6; 
	int k = 1; 
	long long _ = 21LL; 
END
CASE(4)
	int n = 1000; 
	int k = 2; 
	long long _ = 1LL; 
END
return 0;
CASE(5)
	int n = 100000; 
	int k = 100000; 
	long long _ = 1666700000LL; 
END

}
// END CUT HERE
