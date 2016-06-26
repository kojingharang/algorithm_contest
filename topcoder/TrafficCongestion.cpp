// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There are some cities and some roads connecting them together.
The road network has the topology of a perfect binary tree (see below for a picture), in which the cities are nodes and the roads are edges.

You are given the int treeHeight giving the height of the tree.
(The height of a perfect binary tree is the number of edges on the path between the root node and any leaf node.)
Thus, there are 2^(treeHeight+1)-1 cities and 2^(treeHeight+1)-2 roads in total.

The picture below shows how the road network looks like when treeHeight = 2.



We want to send some cars into the road network.
Each car will be traveling from its starting city to its destination city without visiting the same city twice.
(Note that the route of each car is uniquely determined by its starting and its destination city.)
It is possible for the starting city to be equal to the destination city, in that case the car only visits that single city.

Our goal is to send out the cars in such a way that each city will be visited by exactly one car.
Let X be the smallest number of cars we need in order to do so.
Compute and return the value X modulo 1,000,000,007.

DEFINITION
Class:TrafficCongestion
Method:theMinCars
Parameters:int
Returns:int
Method signature:int theMinCars(int treeHeight)


CONSTRAINTS
-treeHeight will be between 0 and 1,000,000, inclusive.


EXAMPLES

0)
1

Returns: 1

In this case, one car can visit all the cities.



1)
2

Returns: 3

Here is one way to visit all cities exactly once by three cars:




2)
3

Returns: 5



3)
585858

Returns: 548973404



*/
// END CUT HERE
#line 74 "TrafficCongestion.cpp"

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



class TrafficCongestion {
	public:
	int theMinCars(int TH) {
		ll ans = 1;
		REP(i, TH-1) ans = (2 * ans + (i%2==0 ? 1 : -1)) % 1,000,000,007LL;
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
#define END	 verify_case(_, TrafficCongestion().theMinCars(treeHeight));}
int main(){

CASE(0)
	int treeHeight = 0; 
	int _ = 1; 
END
CASE(0)
	int treeHeight = 1; 
	int _ = 1; 
END
CASE(1)
	int treeHeight = 2; 
	int _ = 3; 
END
CASE(2)
	int treeHeight = 3; 
	int _ = 5; 
END
CASE(3)
	int treeHeight = 585858; 
	int _ = 548973404; 
END

}
// END CUT HERE
