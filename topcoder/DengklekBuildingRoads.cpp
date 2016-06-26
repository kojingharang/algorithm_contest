// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Mr. Dengklek lives in the Kingdom of Ducks, where humans and ducks live together in peace and harmony.

There are N duck houses in the kingdom, conveniently numbered 1 through N. Currently, there are no roads between the houses. The king assigned Mr. Dengklek to build exactly M bidirectional roads, each connecting a pair of houses.

The king imposed two rules on Mr. Dengklek:

Let A and B be two different houses. Mr. Dengklek may build roads connecting these two houses if and only if 0 < |A-B| <= K. After the road is built, both house number A and house number B are said to be incident to the road. For each such pair of houses Mr. Dengklek may build multiple roads, each connecting the two houses.
Each house must be incident to an even number of roads. (Zero is also an even number.)

You are given the ints N, M, and K. Return the number of different ways Mr. Dengklek can build the roads, modulo 1,000,000,007. Two ways are different if there are two houses that are connected by a different number of roads.

DEFINITION
Class:DengklekBuildingRoads
Method:numWays
Parameters:int, int, int
Returns:int
Method signature:int numWays(int N, int M, int K)


NOTES
-The houses are not required to be connected. There may be pairs of houses such that it is impossible to travel from one to another by only using the roads.
-The roads are allowed to cross arbitrarily. (If two roads cross, the crossing is built using bridges, so that each road only connects the two houses at its ends.)


CONSTRAINTS
-N will be between 1 and 30, inclusive.
-M will be between 0 and 30, inclusive.
-K will be between 1 and 8, inclusive.


EXAMPLES

0)
3
4
1

Returns: 3

These are the three ways to build the roads:



1)
4
3
3

Returns: 4

These are the four ways to build the roads:



2)
2
1
1

Returns: 0

It is impossible to make each house incident to an even number of roads if there is only one road.

3)
5
0
3

Returns: 1



4)
10
20
5

Returns: 26964424



*/
// END CUT HERE
#line 88 "DengklekBuildingRoads.cpp"

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
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T> v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class DengklekBuildingRoads {
	public:
	int numWays(int N, int M, int K) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
 { os << "{ ";
   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, DengklekBuildingRoads().numWays(N, M, K));}
int main(){

CASE(0)
	int N = 3; 
	int M = 4; 
	int K = 1; 
	int _ = 3; 
END
CASE(1)
	int N = 4; 
	int M = 3; 
	int K = 3; 
	int _ = 4; 
END
CASE(2)
	int N = 2; 
	int M = 1; 
	int K = 1; 
	int _ = 0; 
END
CASE(3)
	int N = 5; 
	int M = 0; 
	int K = 3; 
	int _ = 1; 
END
CASE(4)
	int N = 10; 
	int M = 20; 
	int K = 5; 
	int _ = 26964424; 
END

}
// END CUT HERE
