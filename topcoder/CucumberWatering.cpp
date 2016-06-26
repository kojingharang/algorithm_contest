// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Cucumberman planted N cucumbers along a straight road. Cucumbers are numbered 0 through N-1, and the position of the i-th cucumber is x[i]. The cucumbers are at pairwise distinct coordinates, but their coordinates are not necessarily in sorted order. He waters all cucumbers every day. He can't change the order of watering cucumbers, so he must water cucumber 0 first, water cucumber 1 next, and so on. (Note that this means he may be going back and forth along the road.)


Watering a cucumber takes zero time. When walking, Cucumberman needs one unit of time to travel one unit of distance. Additionally, he can build at most K teleports at any positions (including non-integer ones). If there are teleports at both P and Q, he can move from P to Q instantly using teleports.


He wants to minimize the duration between watering cucumber 0 and watering cucumber N-1. Return this minimum time, assuming that he builds and uses the K teleports optimally.


DEFINITION
Class:CucumberWatering
Method:theMin
Parameters:vector <int>, int
Returns:long long
Method signature:long long theMin(vector <int> x, int K)


CONSTRAINTS
-x will contain between 2 and 50 elements, inclusive.
-Each element of x will be between -1,000,000,000 (-10^9) and 1,000,000,000 (10^9), inclusive.
-Elements of x will be pairwise distinct.
-K will be between 1 and 50, inclusive.


EXAMPLES

0)
{0, 6, 8, 2}
2

Returns: 6

One optimal way is as follows:

Build teleports at 1 and 7.
Water cucumber 0 at 0. Walk to 1, teleport to 7, walk to 6 and water cucumber 1. Walk to 8 and water cucumber 2. Walk to 7, teleport back to 1, walk to 2 and water cucumber 3.

It takes |0-1| + |7-6| + |6-8| + |8-7| + |1-2| = 6 unit time in total.


1)
{-1000000000, 1000000000, 0}
1

Returns: 3000000000

Only one teleport is useless.

2)
{58, 2012}
50

Returns: 0



3)
{9, -3, 14, 6, 5, -9, 32, 7, -5, 26, 2, 11}
3

Returns: 58



*/
// END CUT HERE
#line 71 "CucumberWatering.cpp"

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
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class CucumberWatering {
	public:
	long long theMin(vector <int> x, int K) {
		
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
#define END	 verify_case(_, CucumberWatering().theMin(x, K));}
int main(){

CASE(0)
	int x_[] = {0, 6, 8, 2};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int K = 2; 
	long long _ = 6LL; 
END
CASE(1)
	int x_[] = {-1000000000, 1000000000, 0};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int K = 1; 
	long long _ = 3000000000LL; 
END
CASE(2)
	int x_[] = {58, 2012};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int K = 50; 
	long long _ = 0LL; 
END
CASE(3)
	int x_[] = {9, -3, 14, 6, 5, -9, 32, 7, -5, 26, 2, 11};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int K = 3; 
	long long _ = 58LL; 
END

}
// END CUT HERE
