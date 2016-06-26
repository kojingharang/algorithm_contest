// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are interested in purchasing items from a number of stores in a local market. The market is composed of N stores numbered from 0 to N-1. The stores with numbers from 0 to M-1 are interesting to you and all the other stores are not interesting. Some pairs of stores are connected by roads.

You are given a vector <string> interestingStores which contains M elements and describes the interesting stores. The i-th element corresponds to store i and is formatted "OPEN CLOSE DURATION" (quotes for clarity), where OPEN is the opening time (in seconds), CLOSE is the closing time (in seconds) and DURATION is the time (in seconds) required to make a purchase in this store. You can initiate a purchase from a store at any time T between OPEN and CLOSE, inclusive. In order to do so, you need to arrive to the store at time T (or earlier). The purchase will be finalized at time T + DURATION and you need to stay at the store for the entire duration of your purchase. Note that it is possible for a purchase to end when the store is already closed. You cannot make multiple purchases in the same store.

The roads are given by the vector <string> roads. Each element of roads describes a single bidirectional road and is formatted "A B LENGTH" (quotes for clarity). Here A and B are the numbers of stores connected by the road and LENGTH is the time (in seconds) required to move from A to B (or from B to A) using this road.

Your start at time 0 at the location of store N-1. Return the maximum number of purchases in interesting stores that you can make.

DEFINITION
Class:TravellingPurchasingMan
Method:maxStores
Parameters:int, vector <string>, vector <string>
Returns:int
Method signature:int maxStores(int N, vector <string> interestingStores, vector <string> roads)


NOTES
-You are allowed to wait for any amount of time at any location.


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-roads will contain between 1 and 50 elements, inclusive.
-Each element of roads will be formatted "A B LENGTH" (quotes for clarity), where A, B and LENGTH are integers with no unnecessary leading zeros.
-In each road, A and B will each be between 0 and N-1, inclusive.
-In each road, A and B will be distinct.
-In each road, LENGTH will be between 1 and 604,800, inclusive.
-There will exist at most one road between each pair of stores.
-interestingStores will contain between 1 and min{16, N} elements, inclusive,
-Each element of interestingStores will be formatted "OPEN CLOSE DURATION" (quotes for clarity), where OPEN, CLOSE and DURATION are integers with no unnecessary leading zeros.
-In each store, OPEN will be between 0 and 604,800, inclusive.
-In each store, CLOSE will be between OPEN+1 and 604,800, inclusive.
-In each store, DURATION will be between 1 and 604,800, inclusive.


EXAMPLES

0)
3
{"1 10 10" , "1 55 31", "10 50 100" }
{"1 2 10"}

Returns: 1

It is not possible to make more than one purchase:
If you decide to make the purchase at store 2: You need to wait 10 seconds until it opens. Then wait until time = 110 seconds for the purchase to finish. At 110 seconds, all the other stores will be closed.
If you instead decide to make the purchase at store 1: You first need travel through the road and arrive store 1 at time = 10. The purchase finishes at time = 41. After you travel back to store 2, the time will be 51 seconds and store 2 will be closed.
There is no way to reach store 0 when store 2 is the starting point.


1)
3
{"1 10 10" , "1 55 30", "10 50 100" }
{"1 2 10"}

Returns: 2

This time we can travel to store 1, make the purchase and return to store 2 exactly at time = 50 to make two purchases in total.


2)
5
{"0 1000 17"}
{"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"}

Returns: 0

It is not possible to reach store 0 before it closes.


*/
// END CUT HERE
#line 77 "TravellingPurchasingMan.cpp"

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



class TravellingPurchasingMan {
	public:
	int maxStores(int N, vector <string> IS, vector <string> RO) {
		
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
#define END	 verify_case(_, TravellingPurchasingMan().maxStores(N, interestingStores, roads));}
int main(){

CASE(0)
	int N = 3; 
	string interestingStores_[] = {"1 10 10" , "1 55 31", "10 50 100" };
	  vector <string> interestingStores(interestingStores_, interestingStores_+sizeof(interestingStores_)/sizeof(*interestingStores_)); 
	string roads_[] = {"1 2 10"};
	  vector <string> roads(roads_, roads_+sizeof(roads_)/sizeof(*roads_)); 
	int _ = 1; 
END
CASE(1)
	int N = 3; 
	string interestingStores_[] = {"1 10 10" , "1 55 30", "10 50 100" };
	  vector <string> interestingStores(interestingStores_, interestingStores_+sizeof(interestingStores_)/sizeof(*interestingStores_)); 
	string roads_[] = {"1 2 10"};
	  vector <string> roads(roads_, roads_+sizeof(roads_)/sizeof(*roads_)); 
	int _ = 2; 
END
CASE(2)
	int N = 5; 
	string interestingStores_[] = {"0 1000 17"};
	  vector <string> interestingStores(interestingStores_, interestingStores_+sizeof(interestingStores_)/sizeof(*interestingStores_)); 
	string roads_[] = {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"};
	  vector <string> roads(roads_, roads_+sizeof(roads_)/sizeof(*roads_)); 
	int _ = 0; 
END

}
// END CUT HERE
