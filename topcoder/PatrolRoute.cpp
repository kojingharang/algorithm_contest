// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There are exactly X*Y places in the Planar Kingdom: For each pair of integers (x, y) such that 0 <= x < X and 0 <= y < Y there is a place with coordinates (x, y). When a citizen of the kingdom wants to move from (x1, y1) to (x2, y2), the required time is |x1 - x2| + |y1 - y2| (where |t| denotes the absolute value of t).

In order to improve stability in the kingdom, the police wants to introduce a specific patrol route. The route will contain exactly three places A, B, and C.
A policeman will visit these three places and verify that everything is as it should be. The three places that determine a valid route must satisfy the following criteria::

x-coordinates of A, B and C are pairwise distinct.
y-coordinates of A, B and C are pairwise distinct.
Let T be the total time required to follow along the route: first from A to B, then from B to C and finally from C back to A. T must be between minT and maxT, inclusive.


You are given the ints X, Y, minT, and maxT. Return the number of different patrol routes that satisfy these criteria, modulo 1,000,000,007. Two routes are considered to be different if there is a place that belongs to one of them, but does not belong to the other one.

DEFINITION
Class:PatrolRoute
Method:countRoutes
Parameters:int, int, int, int
Returns:int
Method signature:int countRoutes(int X, int Y, int minT, int maxT)


CONSTRAINTS
-X and Y will each be between 3 and 4,000, inclusive.
-minT will be between 1 and 20,000, inclusive.
-maxT will be between minT and 20,000, inclusive.


EXAMPLES

0)
3
3
1
20000

Returns: 6

The time requirement is very flexible in this case. There are 6 patrol routes where both x and y coordinates of places are pairwise distinct.

1)
3
3
4
7

Returns: 0

The time of 7 is too small for any patrol route.

2)
4
6
9
12

Returns: 264



3)
7
5
13
18

Returns: 1212



4)
4000
4000
4000
14000

Returns: 859690013

Don't forget about the modulo!

*/
// END CUT HERE
#line 85 "PatrolRoute.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
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
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

#define MOD ((ll)1000000007)

class PatrolRoute {
	public:
	int countRoutes(int X, int Y, int minT, int maxT) {
		ll ans = 0;
		for(int W=2;W<X;W++) {
			for(int H=2;H<Y;H++) {
				if( minT <= 2*(W+H) && 2*(W+H) <= maxT ) {
					ll a = (X-W) * (Y-H);
					ll b = (W-1)*(H-1)*6;
					ll lans = a*b;
					//cout<<W<<" "<<H<<" "<<a<<" "<<b+c<<endl;
					ans = (ans + lans) % MOD;
				}
			}
		}
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
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, PatrolRoute().countRoutes(X, Y, minT, maxT));}
int main(){

CASE(0)
	int X = 3; 
	int Y = 3; 
	int minT = 1; 
	int maxT = 20000; 
	int _ = 6; 
END
CASE(1)
	int X = 3; 
	int Y = 3; 
	int minT = 4; 
	int maxT = 7; 
	int _ = 0; 
END
CASE(2)
	int X = 4; 
	int Y = 6; 
	int minT = 9; 
	int maxT = 12; 
	int _ = 264; 
END
//return 0;
CASE(3)
	int X = 7; 
	int Y = 5; 
	int minT = 13; 
	int maxT = 18; 
	int _ = 1212; 
END
CASE(4)
	int X = 4000; 
	int Y = 4000; 
	int minT = 4000; 
	int maxT = 14000; 
	int _ = 859690013; 
END
CASE(4)
	int X = 4000; 
	int Y = 4000; 
	int minT = 1; 
	int maxT = 20000; 
	int _ = 859690013; 
END

}
// END CUT HERE
