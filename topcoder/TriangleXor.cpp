// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
You are given an int W.
There is a rectangle in the XY-plane with corners at (0, 0), (0, 1), (W, 0), and (W, 1).
Let T[x] be the triangle with vertices at (0, 1), (W, 1) and (x, 0).
(All points that lie inside the triangle are a part of T[x] as well.)


The objective in this problem is to calculate the area of the region (T[0] xor T[1] xor ... xor T[W]).
(See Notes for a formal definition.)
The figures below show the region (T[0] xor T[1] xor ... xor T[W]) for W=1,2,3,4,5,6.












Return the integer part of the area of the region.



DEFINITION
Class:TriangleXor
Method:theArea
Parameters:int
Returns:int
Method signature:int theArea(int W)


NOTES
-For sets of points A and B in the XY-plane, the set (A xor B) is defined as the set of all points that lie in exactly one of the sets A and B (i.e., points that belong to the union of A and B but don't belong to their intersection).
-If the exact area is A, the correct return value is floor(A), not round(A). In words: you should return the largest integer that is less than or equal to the exact area.
-The format of the return value was chosen to help you in case of small precision errors. The constraints guarantee that computing the correct area with absolute error less than 0.01 is sufficient to determine the correct return value. The author's solution is significantly more precise than that.


CONSTRAINTS
-W will be between 1 and 70,000, inclusive.
-The difference between the exact area of the region and the nearest integer will be greater than 0.01.


EXAMPLES

0)
1

Returns: 0

The exact area is 0.5.

1)
2

Returns: 1

The area is approximately 1.33333.

2)
3

Returns: 1

The exact area is 1.35.

3)
4

Returns: 2

The area is approximately 2.62857. Note that the correct answer is 2, not 3.

4)
5

Returns: 2

The area is approximately 2.13294.

5)
12345

Returns: 4629



******************************/
// END CUT HERE
#line 96 "TriangleXor.cpp"
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

class TriangleXor {
	public:
	int theArea(int W) {
		long double ans = 0;
		REP(i, W+1) {
			long double h = i==0 ? 1 : 1-(long double)i/(i+W);
			long double K = i==0 ? 1 : 2*((i&1)?-1:1);
			ans += K * 0.5 * (W+1-i) * W * h;
//			cout<<"k h x "<<K<<" "<<h<<" "<<W+1-i<<" += "<<K * 0.5 * (W+1-i) * W * h<<endl;
		}
		cout<<ans<<endl;
		return (int)ans;
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
#define END	 verify_case(_, TriangleXor().theArea(W));}
int main(){

CASE(0)
	int W = 1; 
	int _ = 0; 
END
CASE(1)
	int W = 2; 
	int _ = 1; 
END
//return 0;
CASE(2)
	int W = 3; 
	int _ = 1; 
END
CASE(3)
	int W = 4; 
	int _ = 2; 
END
CASE(4)
	int W = 5; 
	int _ = 2; 
END
CASE(5)
	int W = 12345; 
	int _ = 4629; 
END

}
// END CUT HERE
