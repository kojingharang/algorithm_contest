// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are given ints n and z.
We have a regular n-gon: a convex polygon with n sides, in which all sides have the same length and all internal angles are equal.
We want to draw (n-3) non-intersecting diagonals in some way.
Once we do that, we will have the polygon divided into exactly (n-2) triangles.
We want to produce a situation in which one of these (n-2) triangles has a strictly larger area than each of the remaining (n-3).

The vertices of the polygon are labeled 1 through n in clockwise order.
Two sets of diagonals are different if one of them contains a diagonal that is not present in the other one.
Count all sets of (n-3) non-intersecting diagonals that produce an arrangement with the above property.
Return that count modulo z.


DEFINITION
Class:MaximalTriangle
Method:howMany
Parameters:int, int
Returns:int
Method signature:int howMany(int n, int z)


CONSTRAINTS
-n will be between 3 and 444, inclusive.
-z will be between 1 and 1,000,000,000 (10^9), inclusive.


EXAMPLES

0)
4
1000000000

Returns: 0

There are two ways how to select a diagonal in a square. Each of them produces two triangles of equal size.

1)
5
100

Returns: 5

There are five ways how to select two non-intersecting diagonals in a regular pentagon. Each of them produces an arrangement in which one triangle has a larger area than each of the other two.

2)
6
1000003

Returns: 2

For a regular hexagon, some sets of diagonals produce a good set of triangles, and some do not.

3)
10
1000000000

Returns: 1010



4)
15
1000000000

Returns: 714340



5)
100
987654321

Returns: 308571232



*/
// END CUT HERE
#line 82 "MaximalTriangle.cpp"

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



class MaximalTriangle {
	public:
	int howMany(int n, int z) {
		
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
#define END	 verify_case(_, MaximalTriangle().howMany(n, z));}
int main(){

CASE(0)
	int n = 4; 
	int z = 1000000000; 
	int _ = 0; 
END
CASE(1)
	int n = 5; 
	int z = 100; 
	int _ = 5; 
END
CASE(2)
	int n = 6; 
	int z = 1000003; 
	int _ = 2; 
END
CASE(3)
	int n = 10; 
	int z = 1000000000; 
	int _ = 1010; 
END
CASE(4)
	int n = 15; 
	int z = 1000000000; 
	int _ = 714340; 
END
CASE(5)
	int n = 100; 
	int z = 987654321; 
	int _ = 308571232; 
END

}
// END CUT HERE
