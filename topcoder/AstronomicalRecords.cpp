// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Fox Ciel found two astronomical records.
They both describe the same solar system.
Each planet in the system can be characterized by two parameters each being a positive number: planet's size and the distance at which it orbits the sun.
All orbital distances are pairwise distinct, but sizes of some planets may be the same.



The first record is a vector <int> A with x elements.
These elements give the relative sizes of some x planets in the solar system.
Formally, the sizes of those planets have the ratio A[0] : A[1] : ... : A[x-1].
The planets described by A are ordered by their distance from the sun.
(That is, earlier elements of A correspond to planets that are closer to the sun.)



The second record is a vector <int> B with y elements.
These elements give the relative sizes of some y planets in the solar system.
Formally, the sizes of those planets have the ratio B[0] : B[1] : ... : B[y-1].
The planets described by B are ordered by their distance from the sun.



Note that the planets considered by a record do not have to be consecutive.
For example, if a solar system contains the planets P, Q, R, S, T, and U, it is possible that the first record compares P, R, and S, and the second record compares Q, R, T, and U.



We assume that both records are correct.
Return the smallest possible total number of planets in the solar system.

DEFINITION
Class:AstronomicalRecords
Method:minimalPlanets
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minimalPlanets(vector <int> A, vector <int> B)


CONSTRAINTS
-A will contain between 2 and 50 elements, inclusive.
-B will contain between 2 and 50 elements, inclusive.
-Each element in A will be between 1 and 1,000,000,000, inclusive.
-Each element in B will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1,2,1,2,1}
{2,1,2,1,2}

Returns: 6

There have to be at least 5 planets, because each record compares 5 of them.
There cannot be exactly 5 planets, because the first one would have to be both smaller than and larger than the second one.
(Their ratio would have to be both 1:2 and 2:1, which is impossible.)
There can be exactly 6 planets with relative sizes 1,2,1,2,1,2.

1)
{1,2,3,4}
{2,4,6,8}

Returns: 4

There can be only 4 planets because 1:2:3:4 = 2:4:6:8.

2)
{2,3,2,3,2,3,2}
{600,700,600,700,600,700,600}

Returns: 10



3)
{1,2,3,4,5,6,7,8,9}
{6,7,8,9,10,11,12}

Returns: 12



4)
{100000000,200000000}
{200000000,100000000}

Returns: 3



******************************/
// END CUT HERE
#line 97 "AstronomicalRecords.cpp"
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

bool f(ll a0, ll b0, ll a1, ll b1) {
	return a0*b1==b0*a1;
}

class AstronomicalRecords {
	public:
	int minimalPlanets(vector <int> A, vector <int> B) {
		int NA=A.size(), NB=B.size();
		VVI w(NA, VI(NB));
		REP(ia, NA) REP(ib, NB) {
			if(A[ia])
			REP(iia, ia) REP(iib, ib) {
				
			}
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
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, AstronomicalRecords().minimalPlanets(A, B));}
int main(){

CASE(0)
	int A_[] = {1,2,1,2,1};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,1,2,1,2};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int _ = 6; 
END
CASE(1)
	int A_[] = {1,2,3,4};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,4,6,8};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int _ = 4; 
END
CASE(2)
	int A_[] = {2,3,2,3,2,3,2};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {600,700,600,700,600,700,600};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int _ = 10; 
END
CASE(3)
	int A_[] = {1,2,3,4,5,6,7,8,9};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {6,7,8,9,10,11,12};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int _ = 12; 
END
CASE(4)
	int A_[] = {100000000,200000000};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {200000000,100000000};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int _ = 3; 
END

}
// END CUT HERE
