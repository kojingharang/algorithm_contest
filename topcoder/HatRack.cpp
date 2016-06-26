// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// The Order of the Hats has commissioned the creation of a new hat rack. This new hat rack must meet certain properties in order to be considered to hold headwear of such importance.
The hat rack is formed by taking several numbered knobs that are connected by rods. One of the knobs is nailed to the wall. The remaining knobs then hang below this top knob. A sample hat rack is shown in the picture below.



The picture also shows that the hat rack can be divided into levels of knobs. Formally, the level i is defined to contain each knob X such that there are exactly i rods between the top knob and knob X.

The order would like their hat rack to meet the following three requirements:

Each knob X can have at most two knobs hanging directly below it. If there is only one such knob, it hangs directly below X; otherwise, one knob will hang slightly to the right of X and the other slightly to the left.
Except for the bottommost level, each level must be full. That is, if level i is not the bottommost level, it must contain exactly 2^i knobs.
The bottommost level must have all its knobs as far on the left as possible.


The third requirement in more detail: Let b be the bottommost level. If we traverse level b-1 from left to right, there will first be some knobs with two rods going to knobs in level b, then possibly a single knob with one rod going to level b, and finally some knobs not connected to any knob in level b.

You are given a configuration of knobs and rods. The knobs are not fastened to the wall yet. The knobs are numbered 1 through N. There are precisely N-1 rods, and they are connecting the knobs in such a way that the entire structure holds together. (Thus, necessarily, the topology of the hat rack is a tree.)

You are given two vector <int>s knob1 and knob2, each containing N-1 elements. These two vector <int>s describe the rods: For each i, there is a rod connecting the two knobs knob1[i] and knob2[i]. Return the number of ways to arrange the hat rack such that it meets the requirements set by the Order of the Hats. Two arrangements are considered different if the relative position of at least one pair of knobs differs. If it is not possible to meet the requirements, return 0.

DEFINITION
Class:HatRack
Method:countWays
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long countWays(vector <int> knob1, vector <int> knob2)


NOTES
-The correct number of arrangements always fits in a signed 64 bit integer.


CONSTRAINTS
-knob1 will contain between 1 and 50 elements, inclusive.
-knob1 and knob2 will contain the same number of elements.
-Each element of knob1 will be between 1 and N, inclusive, where N is 1 + (the number of elements in knob1).
-Each element of knob2 will be between 1 and N, inclusive, where N is 1 + (the number of elements in knob2).
-Each pair of knobs in the hat rack will be connected by some sequence of rods and knobs.


EXAMPLES

0)
{1}
{2}

Returns: 2



1)
{1,1}
{2,3}

Returns: 2



2)
{1,1,1,1}
{2,3,4,5}

Returns: 0



3)
{6,6,6,4,1}
{1,2,4,5,3}

Returns: 0



4)
{1,1,2,2,11,11,8,8,3,3,4,4,5}
{2,3,11,8,12,13,9,10,4,5,7,6,14}

Returns: 16



5)
{1,2,3,4,5,6,7,8,9}
{2,3,4,5,6,7,8,9,10}

Returns: 0



*/
// END CUT HERE
#line 97 "HatRack.cpp"

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



class HatRack {
	public:
	long long countWays(vector <int> knob1, vector <int> knob2) {
		
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
#define END	 verify_case(_, HatRack().countWays(knob1, knob2));}
int main(){

CASE(0)
	int knob1_[] = {1};
	  vector <int> knob1(knob1_, knob1_+sizeof(knob1_)/sizeof(*knob1_)); 
	int knob2_[] = {2};
	  vector <int> knob2(knob2_, knob2_+sizeof(knob2_)/sizeof(*knob2_)); 
	long long _ = 2LL; 
END
CASE(1)
	int knob1_[] = {1,1};
	  vector <int> knob1(knob1_, knob1_+sizeof(knob1_)/sizeof(*knob1_)); 
	int knob2_[] = {2,3};
	  vector <int> knob2(knob2_, knob2_+sizeof(knob2_)/sizeof(*knob2_)); 
	long long _ = 2LL; 
END
CASE(2)
	int knob1_[] = {1,1,1,1};
	  vector <int> knob1(knob1_, knob1_+sizeof(knob1_)/sizeof(*knob1_)); 
	int knob2_[] = {2,3,4,5};
	  vector <int> knob2(knob2_, knob2_+sizeof(knob2_)/sizeof(*knob2_)); 
	long long _ = 0LL; 
END
CASE(3)
	int knob1_[] = {6,6,6,4,1};
	  vector <int> knob1(knob1_, knob1_+sizeof(knob1_)/sizeof(*knob1_)); 
	int knob2_[] = {1,2,4,5,3};
	  vector <int> knob2(knob2_, knob2_+sizeof(knob2_)/sizeof(*knob2_)); 
	long long _ = 0LL; 
END
CASE(4)
	int knob1_[] = {1,1,2,2,11,11,8,8,3,3,4,4,5};
	  vector <int> knob1(knob1_, knob1_+sizeof(knob1_)/sizeof(*knob1_)); 
	int knob2_[] = {2,3,11,8,12,13,9,10,4,5,7,6,14};
	  vector <int> knob2(knob2_, knob2_+sizeof(knob2_)/sizeof(*knob2_)); 
	long long _ = 16LL; 
END
CASE(5)
	int knob1_[] = {1,2,3,4,5,6,7,8,9};
	  vector <int> knob1(knob1_, knob1_+sizeof(knob1_)/sizeof(*knob1_)); 
	int knob2_[] = {2,3,4,5,6,7,8,9,10};
	  vector <int> knob2(knob2_, knob2_+sizeof(knob2_)/sizeof(*knob2_)); 
	long long _ = 0LL; 
END

}
// END CUT HERE
