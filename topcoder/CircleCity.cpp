// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Circle City consists of n buildings on a circle
You are given the vector <int> dist with n elements.
The elements of dist are the distances between adjacent buildings, in clockwise order around the circle.



Citizens can travel along the circle in both directions.
Their speed is one unit of distance per second.
You would now like to help them get around the city faster by building k teleporters.
Once you do so, it will be possible to travel between any two teleporters in zero time.



For the purpose of this problem, both buildings and teleporters are considered points.
Teleporters can be built anywhere on the circle, possibly at non-integer coordinates.
A teleporter may share its location with a building.



For any pair of buildings X and Y, let d(X,Y) be the shortest time a person will need to get from X to Y (or vice versa).
The diameter of Circle City is defined to be the maximum of all values d(X,Y).
Your task is to minimize the diameter of Circle City.
Find an optimal way to place the teleporters and compute and return the corresponding value of the diameter.
(It can be shown that the optimal diameter will always be an integer.)


DEFINITION
Class:CircleCity
Method:findMin
Parameters:vector <int>, int
Returns:int
Method signature:int findMin(vector <int> dist, int k)


CONSTRAINTS
-dist will contain between 2 and 2,000 elements, inclusive.
-Each element of dist will be between 1 and 10^6, inclusive.
-k will be between 2 and |dist|, inclusive.


EXAMPLES

0)
{3,5,4}
2

Returns: 3

Here is a picture of the above scenario:






The blue dots are the three buildings.
The two red circles show one optimal placement of the two teleporters.
One teleporter is exactly at the location of building C, the other is between A and B, and its distance from A is 0.6.



For this placement of teleporters we have d(A,B) = 3, d(A,C) = 0.6, and d(B,C) = 2.4.
Hence, the current diameter is 3.

It can be shown that this is optimal.

1)
{3,5,4}
3

Returns: 0

We can build the three teleporters right at the three buildings.


2)
{1,2,3,4,5,6,5,4,3,2,1}
5

Returns: 5



3)
{1, 100, 1,1,1, 100, 1, 100, 1,1,1, 100, 1}
4

Returns: 3



4)
{3,1,4,1,5,9,2,6,5,3,5,8,9,7}
6

Returns: 8



5)
{
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000
}
7

Returns: 9000000



*/
// END CUT HERE
#line 127 "CircleCity.cpp"

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
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class CircleCity {
	public:
	int findMin(vector <int> dist, int k) {
		int N = dist.size();

		ll L = accumulate(ALL(dist), 0);
		ll lo = -1;
		ll hi = L; // possible
		while(lo+1<hi) {
			ll mid = (lo+hi)/2;
			ll minCo = 1LL<<60;
			REP(si, N) {
				ll co = 0;
				ll tail = -1;
				ll cur = 0;
				REP(i, N) {
					if(tail<cur) {
						tail=cur+mid;
						co++;
					}
					cur += dist[(si+i)%N];
				}
				minCo = min(minCo, co);
			}
			if(minCo<=k) hi=mid;
			else lo=mid;
		}
		return hi;
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
#define END	 verify_case(_, CircleCity().findMin(dist, k));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int dist_[] = {3,5,4};
	  vector <int> dist(dist_, dist_+sizeof(dist_)/sizeof(*dist_)); 
	int k = 2; 
	int _ = 3; 
END
CASE(1)
	int dist_[] = {3,5,4};
	  vector <int> dist(dist_, dist_+sizeof(dist_)/sizeof(*dist_)); 
	int k = 3; 
	int _ = 0; 
END
CASE(2)
	int dist_[] = {1,2,3,4,5,6,5,4,3,2,1};
	  vector <int> dist(dist_, dist_+sizeof(dist_)/sizeof(*dist_)); 
	int k = 5; 
	int _ = 5; 
END
CASE(3)
	int dist_[] = {1, 100, 1,1,1, 100, 1, 100, 1,1,1, 100, 1};
	  vector <int> dist(dist_, dist_+sizeof(dist_)/sizeof(*dist_)); 
	int k = 4; 
	int _ = 3; 
END
CASE(4)
	int dist_[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7};
	  vector <int> dist(dist_, dist_+sizeof(dist_)/sizeof(*dist_)); 
	int k = 6; 
	int _ = 8; 
END
CASE(5)
	int dist_[] = {
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000
};
	  vector <int> dist(dist_, dist_+sizeof(dist_)/sizeof(*dist_)); 
	int k = 7; 
	int _ = 9000000; 
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
	vector <int> dist; 
	{
		int N=UNIFORM_LL(1, 51);
		dist = vector <int>(N); 
		REP(i, N) {
			dist[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int k = UNIFORM_LL(0, 100); 
	int _0 = CircleCity().findMin(dist, k);
	int _1 = CircleCityRef().findMin(dist, k);
	if(!verify_case(_0, _1, true)) {
print(dist);
print(k);
	}
}
#endif

}
// END CUT HERE
