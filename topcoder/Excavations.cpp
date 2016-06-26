// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Once upon a time, there was a civilization called Ruritania. It had n building sites numbered from 0 to n-1. There were various types of buildings such as libraries, markets, and palaces. Each building type was assigned an integer from 1 to 50. The building at site i (0-based index) was of type kind[i].

With the passing of millennia, Ruritania declined and its building sites were covered in sand, concealing all the buildings. Due to wind and terrain, the depth of the sand varied. The building at site i (0-based index) was buried depth[i] meters below the surface.

Recently, an intrepid archeologist excavated K building sites using a machine that could dig to a maximum depth of D meters. Thus, he only discovered buildings that had been buried at most D meters below the surface.

You are given vector <int>s kind, depth, and found as well as the int K. The types of buildings discovered by the excavation are given by the vector <int> found, which contains at most one value for each building type even if several buildings of a type were excavated.

Return the number of K-tuples of sites that could have been excavated to arrive at the given values. If the given information is not consistent with any configuration of building sites, return 0.


DEFINITION
Class:Excavations
Method:count
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:long long
Method signature:long long count(vector <int> kind, vector <int> depth, vector <int> found, int K)


CONSTRAINTS
-kind will contain N elements, where N is between 1 and 50, inclusive.
-Each element of kind will be between 1 and 50, inclusive.
-depth will contain N elements.
-Each element of depth will be between 1 and 100,000, inclusive.
-found will contain between 1 and 50 elements, inclusive.
-Each element of found will occur in kind at least once.
-The elements of found will be distinct.
-K will be between the number of elements in found and N, inclusive.


EXAMPLES

0)
{1, 1, 2, 2}
{10, 15, 10, 20}
{1}
2

Returns: 3

There are four building sites. Two have buildings of type 1 and two have buildings of type 2. The type 1 buildings are at depths 10 and 15. The type 2 buildings are at depths 10 and 20. The archeologist has excavated two sites and discovered only type 1 buildings. He must have excavated one of three possible pairs of sites:

Sites 0 and 1. The archeologist's machine excavates to a maximum depth D of at least 10.
Sites 0 and 3. The machine excavates to a maximum depth D that falls in the interval [10, 20).
Sites 1 and 3. The machine excavates to a maximum depth that falls in the interval [15, 20).

The other pairs of sites could not have been excavated. For example, the archeologist could not have excavated sites 0 and 2, because he would have found either none or both of the buildings.


1)
{1, 1, 2, 2}
{10, 15, 10, 20}
{1, 2}
2

Returns: 4

The archeologist could have chosen any pair of sites containing a type 1 and a type 2 building. With a large enough value of D, he could have excavated both.


2)
{1, 2, 3, 4}
{10, 10, 10, 10}
{1, 2}
3

Returns: 0

The archeologist cannot have excavated three sites, or else he would have found three types of buildings.

3)
{1, 2, 2, 3, 1, 3, 2, 1, 2}
{12512, 12859, 125, 1000, 99, 114, 125, 125, 114}
{1, 2, 3}
7

Returns: 35



4)
{50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50}
{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3}
{50}
18

Returns: 9075135300



*/
// END CUT HERE
#line 97 "Excavations.cpp"

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



class Excavations {
	public:
	long long count(vector <int> kind, vector <int> depth, vector <int> found, int K) {
		
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
#define END	 verify_case(_, Excavations().count(kind, depth, found, K));}
int main(){

CASE(0)
	int kind_[] = {1, 1, 2, 2};
	  vector <int> kind(kind_, kind_+sizeof(kind_)/sizeof(*kind_)); 
	int depth_[] = {10, 15, 10, 20};
	  vector <int> depth(depth_, depth_+sizeof(depth_)/sizeof(*depth_)); 
	int found_[] = {1};
	  vector <int> found(found_, found_+sizeof(found_)/sizeof(*found_)); 
	int K = 2; 
	long long _ = 3LL; 
END
CASE(1)
	int kind_[] = {1, 1, 2, 2};
	  vector <int> kind(kind_, kind_+sizeof(kind_)/sizeof(*kind_)); 
	int depth_[] = {10, 15, 10, 20};
	  vector <int> depth(depth_, depth_+sizeof(depth_)/sizeof(*depth_)); 
	int found_[] = {1, 2};
	  vector <int> found(found_, found_+sizeof(found_)/sizeof(*found_)); 
	int K = 2; 
	long long _ = 4LL; 
END
CASE(2)
	int kind_[] = {1, 2, 3, 4};
	  vector <int> kind(kind_, kind_+sizeof(kind_)/sizeof(*kind_)); 
	int depth_[] = {10, 10, 10, 10};
	  vector <int> depth(depth_, depth_+sizeof(depth_)/sizeof(*depth_)); 
	int found_[] = {1, 2};
	  vector <int> found(found_, found_+sizeof(found_)/sizeof(*found_)); 
	int K = 3; 
	long long _ = 0LL; 
END
CASE(3)
	int kind_[] = {1, 2, 2, 3, 1, 3, 2, 1, 2};
	  vector <int> kind(kind_, kind_+sizeof(kind_)/sizeof(*kind_)); 
	int depth_[] = {12512, 12859, 125, 1000, 99, 114, 125, 125, 114};
	  vector <int> depth(depth_, depth_+sizeof(depth_)/sizeof(*depth_)); 
	int found_[] = {1, 2, 3};
	  vector <int> found(found_, found_+sizeof(found_)/sizeof(*found_)); 
	int K = 7; 
	long long _ = 35LL; 
END
CASE(4)
	int kind_[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
	  vector <int> kind(kind_, kind_+sizeof(kind_)/sizeof(*kind_)); 
	int depth_[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3};
	  vector <int> depth(depth_, depth_+sizeof(depth_)/sizeof(*depth_)); 
	int found_[] = {50};
	  vector <int> found(found_, found_+sizeof(found_)/sizeof(*found_)); 
	int K = 18; 
	long long _ = 9075135300LL; 
END

}
// END CUT HERE
