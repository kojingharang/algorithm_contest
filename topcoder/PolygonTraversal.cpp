// BEGIN CUT HERE
/******************************
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



******************************/
// END CUT HERE
#line 79 "PolygonTraversal.cpp"
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

string f(int N, int v) {
	string s(N, '0');
	REP(i, N) s[i]=v&1<<i ? '1' : '0';
	return s;
}

// ビット演算を使った版。時間はそんなに違わないような。
// maximum 117ms
int crossB(int N, int bit, int cur, int nxt) {
	int a = min(cur, nxt);
	int b = max(cur, nxt);
	int mask0 = ((1<<b)-1) & ~((1<<(a+1))-1);   // 0 0 0 b 1 1 1 a 0 0 0
	int mask1 = ~((1<<(b+1))-1) |  ((1<<a)-1);  // 1 1 1 b 0 0 0 a 1 1 1
	
	int ret = bit & mask0 && bit & mask1;
//	cout<<"cross "<<f(N, bit)<<" "<<cur<<" "<<nxt<<" mask0 "<<f(N, mask0)<<" mask1 "<<f(N, mask1)<<" -> "<<ret<<endl;
	return ret;
}

// maximum 476ms
int cross(int N, int bit, int cur, int nxt) {
	// cur, nxt を結んだ線の両サイドに少なくとも１コ以上使用済みノードがあれば交差する
	int side0 = 0;
	for(int i=(cur+1)%N; i!=nxt; i=(i+1)%N) if(bit & 1<<i) side0=1;
	int side1 = 0;
	for(int i=(nxt+1)%N; i!=cur; i=(i+1)%N) if(bit & 1<<i) side1=1;
	return side0 && side1;
}

class PolygonTraversal {
	public:
	long long count(int N, vector <int> P) {
		int M = P.size();
		REP(i, M) P[i]--;
		
		VVI dp(N, VI(1<<N));
		int init_bit = 0;
		FOR(e, P) init_bit |= 1<<*e;
		dp[P.back()][init_bit] = 1;
//		cout<<dp<<endl;
		
		REP(bit, 1<<N) {
			REP(cur, N) {
				if((bit & 1<<cur)==0) continue;
				if(dp[cur][bit]==0) continue;
				REP(nxt, N) {
					if(bit & 1<<nxt) continue;
//					cout<<"try cross: "<<bit<<" "<<cur<<" "<<nxt<<endl;
					int ok = cross(N, bit, cur, nxt);
					if(ok) dp[nxt][bit|1<<nxt] += dp[cur][bit];
//					if(ok) cout<<"update "<<cur<<" "<<nxt<<endl;
				}
			}
//			cout<<dp<<endl;
		}
		ll ans = 0;
		int bit = (1<<N)-1;
		REP(cur, N) {
			int nxt = P[0];
			int ok = cross(N, bit, cur, nxt);
			if(ok) ans += dp[cur][bit];
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
void verify_case(const long long& Expected, const long long& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, PolygonTraversal().count(N, points));}
int main(){

CASE(0)
	int N = 5; 
	int points_[] = {1, 3, 5};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	long long _ = 1LL; 
END
//return 0;

CASE(1)
	int N = 6; 
	int points_[] = {1, 4, 2};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	long long _ = 1LL; 
END
CASE(2)
	int N = 7; 
	int points_[] = {2, 4, 7};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	long long _ = 2LL; 
END
CASE(3)
	int N = 7; 
	int points_[] = {1, 2, 3, 4, 6, 5};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	long long _ = 0LL; 
END
CASE(4)
	int N = 18; 
	int points_[] = {1, 7, 18};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	long long _ = 4374612736LL; 
END

}
// END CUT HERE
