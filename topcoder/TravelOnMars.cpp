// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Bob recently went to Mars.

There are N cities on Mars. The cities all lie on a circular railroad and they are numbered 0 through N-1 along the railroad. More precisely, there is a railroad segment that connects cities N-1 and 0, and for each i (0 <= i <= N-2) there is a railroad segment that connects cities i and i+1. Trains travel along the railroad in both directions.

You are given a vector <int> range with N elements. For each i: the set of cities that are reachable from city i by a direct train is precisely the set of cities that are within the distance range[i] of city i. (The distance between two cities is the smallest number of railroad segments one needs to travel in order to get from one city to the other. For example, if N=17 and range[2]=3, the cities directly reachable from city 2 are the cities {17,0,1,2,3,4,5}.)

You are also given ints startCity and endCity. Bob starts his tour in the city startCity and wants to end it in the city endCity. Calculate and return the minimum number of succesive direct trains he needs to take.

DEFINITION
Class:TravelOnMars
Method:minTimes
Parameters:vector <int>, int, int
Returns:int
Method signature:int minTimes(vector <int> range, int startCity, int endCity)


CONSTRAINTS
-range will contain N elements, where N is between 2 and 50, inclusive.
-Each element of range will be between 1 and 50, inclusive.
-startCity will be between 0 and N-1, inclusive.
-endCity will be between 0 and N-1, inclusive.
-startCity and endCity will be different.


EXAMPLES

0)
{2,1,1,1,1,1}
1
4

Returns: 2

Bob wants to get from city 1 to city 4.
The optimal solution is to travel from city 1 to city 0, and then (as range[0]=2) from city 0 to city 4.

1)
{2,1,1,1,1,1}
4
1

Returns: 3

This is the same test case as Example 0, only startCity and endCity have been swapped. Note that the answer is now 3 instead of 2.

2)
{2,1,1,2,1,2,1,1}
2
6

Returns: 3

Bob starts in city 2. There are two optimal routes: (2->3->5->6) and (2->1->0->6).

3)
{3,2,1,1,3,1,2,2,1,1,2,2,2,2,3}
6
13

Returns: 4



*/
// END CUT HERE
#line 70 "TravelOnMars.cpp"

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



class TravelOnMars {
	public:
	int minTimes(vector <int> R, int S, int E) {
		int N=R.size();
		VVI w(N, VI(N, 100000));
		REP(i, N) REP(j, N) if(abs(i-j)<=R[i] || abs(-N+i-j)<=R[i] || abs(N+i-j)<=R[i]) { w[i][j]=1; }
		REP(k, N) REP(i, N) REP(j, N) w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
		//cout<<w<<endl;
		return w[S][E];
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
#define END	 verify_case(_, TravelOnMars().minTimes(range, startCity, endCity));}
int main(){

CASE(0)
	int range_[] = {2,1,1,1,1,1};
	  vector <int> range(range_, range_+sizeof(range_)/sizeof(*range_)); 
	int startCity = 1; 
	int endCity = 4; 
	int _ = 2; 
END
CASE(1)
	int range_[] = {2,1,1,1,1,1};
	  vector <int> range(range_, range_+sizeof(range_)/sizeof(*range_)); 
	int startCity = 4; 
	int endCity = 1; 
	int _ = 3; 
END
CASE(2)
	int range_[] = {2,1,1,2,1,2,1,1};
	  vector <int> range(range_, range_+sizeof(range_)/sizeof(*range_)); 
	int startCity = 2; 
	int endCity = 6; 
	int _ = 3; 
END
CASE(3)
	int range_[] = {3,2,1,1,3,1,2,2,1,1,2,2,2,2,3};
	  vector <int> range(range_, range_+sizeof(range_)/sizeof(*range_)); 
	int startCity = 6; 
	int endCity = 13; 
	int _ = 4; 
END
CASE(1)
	int range_[] = {14, 1, 6, 13, 15, 12, 13, 13, 13, 3, 7, 7, 2, 15, 5, 12, 11, 10, 13, 6, 6, 13, 5, 6, 14, 10, 10, 7, 5, 10, 9, 1, 10, 6, 5, 11, 1, 4, 10, 4, 14, 10, 2, 12, 13, 12, 2, 15, 11, 4};
	  vector <int> range(range_, range_+sizeof(range_)/sizeof(*range_)); 
	int startCity = 49; 
	int endCity = 19; 
	int _ = 3; 
END

}
// END CUT HERE
