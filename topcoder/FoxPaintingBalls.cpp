// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A Ball Triangle is a set of identical balls placed in a triangular shape. A Ball Triangle has N rows, numbered 1 to N from top to bottom. For all i, 1 <= i <= N, the i-th row contains i balls. For example, the following image shows a Ball Triangle with N=3.




Fox Jiro has infinitely many Ball Triangles. He can paint a Ball Triangle according to the following conditions:

Each of the balls has to be painted either red, green, or blue.
No two adjacent balls may share the same color.

The following image shows one valid coloring of a Ball Triangle for N=3.




Jiro wants to paint as many Ball Triangles as he can.
As long as he follows the rules above, he may color the Ball Triangles in any way he likes.
Some of the colored Ball Triangles may look exactly the same, but they don't have to.
The only other constraint is the total amount of paint available to Jiro:
In all the triangles together, he can paint at most R balls red, G balls green, and B balls blue.

You are given the long longs R, G, and B.
You are also given the int N.
Return the maximum possible number of Ball Triangles Jiro can paint.

DEFINITION
Class:FoxPaintingBalls
Method:theMax
Parameters:long long, long long, long long, int
Returns:long long
Method signature:long long theMax(long long R, long long G, long long B, int N)


CONSTRAINTS
-R, G and B will each be between 0 and 1,000,000,000,000,000,000 (10^18), inclusive.
-N will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
2
2
2
3

Returns: 1

Jiro can paint one Ball Triangle in the same way as in the image in the statement.

1)
1
2
3
3

Returns: 0

This time Jiro can paint no Ball Triangles.

2)
8
6
6
4

Returns: 2



3)
7
6
7
4

Returns: 2



4)
100
100
100
4

Returns: 30



5)
19330428391852493
48815737582834113
11451481019198930
3456

Returns: 5750952686



6)
1
1
1
1

Returns: 3



*/
// END CUT HERE
#line 117 "FoxPaintingBalls.cpp"

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

class FoxPaintingBalls {
	public:
	long long theMax(long long R, long long G, long long B, int N) {
		ll tot = (ll)N*(N+1)/2;
		ll to3 = tot/3;
		ll lo=0, hi=(R+G+B)/tot+1;
		while(lo+1<hi) {
			ll mid = (lo+hi)/2;
			ll r=R-mid*to3;
			ll g=G-mid*to3;
			ll b=B-mid*to3;
			//cout<<mid<<" "<<r<<" "<<g<<" "<<b<<endl;
			if(r>=0 && g>=0 && b>=0 && (tot%3 ? (mid <= (r+g+b)/(tot%3)) : 1)) lo=mid;
			else hi=mid;
		}
		return lo;
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
#define END	 verify_case(_, FoxPaintingBalls().theMax(R, G, B, N));}
int main(){

CASE(0)
	long long R = 2LL; 
	long long G = 2LL; 
	long long B = 2LL; 
	int N = 3; 
	long long _ = 1LL; 
END
CASE(1)
	long long R = 1LL; 
	long long G = 2LL; 
	long long B = 3LL; 
	int N = 3; 
	long long _ = 0LL; 
END
CASE(2)
	long long R = 8LL; 
	long long G = 6LL; 
	long long B = 6LL; 
	int N = 4; 
	long long _ = 2LL; 
END
CASE(3)
	long long R = 7LL; 
	long long G = 6LL; 
	long long B = 7LL; 
	int N = 4; 
	long long _ = 2LL; 
END
CASE(4)
	long long R = 100LL; 
	long long G = 100LL; 
	long long B = 100LL; 
	int N = 4; 
	long long _ = 30LL; 
END
CASE(5)
	long long R = 19330428391852493LL; 
	long long G = 48815737582834113LL; 
	long long B = 11451481019198930LL; 
	int N = 3456; 
	long long _ = 5750952686LL; 
END
CASE(6)
	long long R = 1LL; 
	long long G = 1LL; 
	long long B = 1LL; 
	int N = 1; 
	long long _ = 3LL; 
END
CASE(6)
	long long R = 1000000000000000000LL; 
	long long G = 1000000000000000000LL; 
	long long B = 1000000000000000000LL; 
	int N = 1000000000; 
	long long _ = 3LL; 
END
CASE(6)
	long long R = 949185738472857384LL;
	long long G = 819402738175983874LL;
	long long B = 905384829619493856LL;
	int N = 4; 
	long long _ = 267397330626833511LL; 
END
CASE(6)
	long long R = 5LL;
	long long G = 5LL;
	long long B = 5LL;
	int N = 5; 
	long long _ = 1LL; 
END

}
// END CUT HERE
