// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Manao had a sheet of paper. He drew N points on it, which corresponded to vertices of a regular N-gon. He numbered the vertices from 1 to N in clockwise order.

After that, Manao connected several pairs of points with straight line segments. Namely, he connected points points[i] and points[i+1] for each i between 0 and M-2, where M is the number of elements in points. Note that all numbers in points are distinct.

Manao took a look at what he had drawn and decided to continue his traversal by adding every remaining point of the polygon to it and then returning to point points[0]. In other words, Manao is going to connect point points[M-1] with some point tail[0] which is not in points, then connect tail[0] with some point tail[1] which is neither in points nor in tail, and so on. In the end, he will connect point tail[N-M-1] with point points[0], thus completing the traversal.

Manao is really fond of intersections, so he wants to continue the traversal in such a way that every new line segment he draws intersects with at least one of the previously drawn line segments. (Note that the set of previously drawn segments includes not only the original set of segments, but also the new segments drawn before the current one.) Count and return the number of ways in which he can complete the traversal.

DEFINITION
Class:PolygonTraversal
Method:count
Parameters:int, vector <int>
Returns:long long
Method signature:long long count(int N, vector <int> points)


CONSTRAINTS
-N will be between 4 and 18, inclusive.
-points will contain between 2 and N-1 elements, inclusive.
-Each element of points will be between 1 and N, inclusive.
-The elements of points will be distinct.


EXAMPLES

0)
5
{1, 3, 5}

Returns: 1

The only way for Manao to complete the traversal is:



1)
6
{1, 4, 2}

Returns: 1

The only way to complete the traversal is to visit vertices {6, 3, 5, 1}, in order.
Note that the segment 5-1 does not intersect the original two segments (1-4 and 4-2), but it does intersect segments 2-6 and 6-3 which were both added before 5-1.

2)
7
{2, 4, 7}

Returns: 2

The two possible tails are:

3-5-1-6-2
3-6-1-5-2


3)
7
{1, 2, 3, 4, 6, 5}

Returns: 0

Manao needs to connect points 5 and 7 and then connect points 7 and 1. Obviously, segment 1-7 will not intersect with any other segment.

4)
18
{1, 7, 18}

Returns: 4374612736


*/
// END CUT HERE
#line 77 "PolygonTraversal.cpp"
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

class PolygonTraversal {
	public:
	long long count(int N, vector <int> p) {
		int M = p.size();
		int R = N;
		VVI dp(N, VI(1<<R));
		dp[0][(1<<R)-1]=1;
		
		int init=0;
		REP(i, p.size()) {
			init |= 1<<(p[i]-1);
		}
		int init_st = p[M-1]-1;
		
		cout<<dp<<endl;
		for(int bit=1<<R;bit>=init;bit--) {
			//cout<<bit<<endl;
			REP(cst, N) {
				if((bit>>cst)&1==0) continue;
				REP(nst, N) {
					if((bit>>nst)&1==0) continue;
					int ok=0;
					for(int i=(cst+1)%N;i!=nst;i=(i+1)%N) if((bit>>i)&1) ok=1;
					for(int i=(nst+1)%N;i!=cst;i=(i+1)%N) if((bit>>i)&1) ok=1;
					if(ok) {
						//cout<<"Update"<<endl;
						dp[nst][bit&~(1<<cst)] += dp[cst][bit];
					}
				}
			}
		}
		cout<<dp<<endl;
		return dp[init_st][init];
	}
};


// BEGIN CUT HERE
int main() {
	ll r = 0;
	vector<int> w;
	w.PB(1);
	w.PB(3);
	w.PB(5);
	r = PolygonTraversal().count(5, w);
	cout<<r<<endl;
}
// END CUT HERE











