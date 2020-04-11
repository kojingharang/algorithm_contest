// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// You are given a finite set S of points in the plane.
For each valid i, one of those points has coordinates (x[i], y[i]).
The points are all distinct and no three of them are collinear.


Below, CH(s) denotes the convex hull of the set s: that is, the smallest of all convex polygons that contain the set s.


We say that the ordered pair (s1, s2) is interesting if the following conditions are satisfied:

s1 is a subset of S
s2 is a subset of S
the sets s1 and s2 are disjoint (i.e., they have no elements in common)
the intersection of the convex hulls CH(s1) and CH(s2) has a positive area


Note that some points from S may remain unused (i.e., they will be neither in s1, nor in s2).


You are given the coordinates of all points: the vector <int>s x and y.
Please compute and return the number of interesting pairs of sets, modulo 10^9 + 7.

DEFINITION
Class:IntersectingConvexHull
Method:count
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int count(vector <int> x, vector <int> y)


CONSTRAINTS
-x will contain between 6 and 100 elements, inclusive.
-x and y will contain the same number of elements.
-Each element in x will be between -1,000,000 and 1,000,000, inclusive.
-Each element in y will be between -1,000,000 and 1,000,000, inclusive.
-All points will be distinct.
-No three points will lie on the same line.


EXAMPLES

0)
{1,0,-1,-1,0,1}
{1,2,1,-1,-2,-1}

Returns: 14

We have 14 solutions:

s1 = {0,1,3}, s2 = {2,4,5}
s1 = {0,2,3}, s2 = {1,4,5}
s1 = {0,1,4}, s2 = {2,3,5}
s1 = {0,2,4}, s2 = {1,3,5}
s1 = {1,2,4}, s2 = {0,3,5}
s1 = {0,3,4}, s2 = {1,2,5}
s1 = {1,3,4}, s2 = {0,2,5}
s1 = {0,2,5}, s2 = {1,3,4}
s1 = {1,2,5}, s2 = {0,3,4}
s1 = {0,3,5}, s2 = {1,2,4}
s1 = {1,3,5}, s2 = {0,2,4}
s1 = {2,3,5}, s2 = {0,1,4}
s1 = {1,4,5}, s2 = {0,2,3}
s1 = {2,4,5}, s2 = {0,1,3}


1)
{444, -646, 367, 302, -506, 810}
{-530, 660, 872, -78, -621, 77}

Returns: 10

This time we have 10:

s1 = {0,1,2}, s2 = {3,4,5}
s1 = {0,1,3}, s2 = {2,4,5}
s1 = {0,2,3}, s2 = {1,4,5}
s1 = {0,2,4}, s2 = {1,3,5}
s1 = {2,3,4}, s2 = {0,1,5}
s1 = {0,1,5}, s2 = {2,3,4}
s1 = {1,3,5}, s2 = {0,2,4}
s1 = {1,4,5}, s2 = {0,2,3}
s1 = {2,4,5}, s2 = {0,1,3}
s1 = {3,4,5}, s2 = {0,1,2}


2)
{-737, -245, -51, 943, -7, 1000, -976, -723}
{-355, 898, -372, -585, -98, -53, 490, -954}

Returns: 900



3)
{-928, 852, 840, 813, -564, -594, -667, 838, -74, -675, -530, -476, -154, 702, 817, 969, 845, 592, 867, -330}
{-898, 682, 604, 22, -452, 901, 464, -624, -272, -792, -906, 36, 249, -287, 871, 877, 446, 910, 943, 427}

Returns: 296398747

Don't forget to mod 10^9+7.

******************************/
// END CUT HERE
#line 108 "IntersectingConvexHull.cpp"
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
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, I, J) REP(i, I) { REP(j, J) cout<<table[i][j]<<" "; cout<<"\n"; }
#define PRINT3(table, I, J, K) REP(i, I) { REP(j, J) { REP(k, K) cout<<table[i][j][k]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<(v)<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class IntersectingConvexHull {
	public:
	int count(vector <int> x, vector <int> y) {
		
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
#define END	 verify_case(_, IntersectingConvexHull().count(x, y));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int x_[] = {1,0,-1,-1,0,1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {1,2,1,-1,-2,-1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 14; 
END
CASE(1)
	int x_[] = {444, -646, 367, 302, -506, 810};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-530, 660, 872, -78, -621, 77};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 10; 
END
CASE(2)
	int x_[] = {-737, -245, -51, 943, -7, 1000, -976, -723};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-355, 898, -372, -585, -98, -53, 490, -954};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 900; 
END
CASE(3)
	int x_[] = {-928, 852, 840, 813, -564, -594, -667, 838, -74, -675, -530, -476, -154, 702, 817, 969, 845, 592, 867, -330};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-898, 682, 604, 22, -452, 901, 464, -624, -272, -792, -906, 36, 249, -287, 871, 877, 446, 910, 943, 427};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 296398747; 
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
	vector <int> x; 
	{
		int N=UNIFORM_LL(1, 51);
		x = vector <int>(N); 
		REP(i, N) {
			x[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> y; 
	{
		int N=UNIFORM_LL(1, 51);
		y = vector <int>(N); 
		REP(i, N) {
			y[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = IntersectingConvexHull().count(x, y);
	int _1 = IntersectingConvexHullRef().count(x, y);
	if(!verify_case(_0, _1, true)) {
print(x);
print(y);
	}
}
#endif

}
// END CUT HERE
