// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// John has an array of n integers.
Each pair of neighboring elements differs by at most d.
The first and the last elements of the array are equal to first and last, respectively.


Brus does not know John's array.
He only knows n, d, first and last.
He wants to compute the maximal possible element John might have in his array.


You are given ints n, d, first and last.
Return the maximal possible element the array might contain.


DEFINITION
Class:TheArray
Method:find
Parameters:int, int, int, int
Returns:int
Method signature:int find(int n, int d, int first, int last)


NOTES
-The constraints given below guarantee that there will always be at least one array that matches the values Brus knows.
-For the constraints given below, the correct answer will always fit into an int.


CONSTRAINTS
-n will be between 2 and 1,000,000, inclusive.
-d will be between 0 and 1000, inclusive.
-first will be between -1000 and 1000, inclusive.
-last will be between -1000 and 1000, inclusive.
-|first - last| will be at most (n-1)*d.


EXAMPLES

0)
3
5
2
4

Returns: 7

Only the second element of the array is unknown.
Its maximal valid value is 7.


1)
10
100
999
100

Returns: 999

Due to the limitations, the first element is the largest element of the array.

2)
1000000
0
474
474

Returns: 474

All elements of the array are equal.

3)
97
53
-92
441

Returns: 2717



4)
99
3
-743
-619

Returns: -535



*/
// END CUT HERE
#line 96 "TheArray.cpp"

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



class TheArray {
	public:
	int find(int n, int d, int first, int last) {
		ll ans = -(1<<30);
		REP(i, n) {
			ll mx0 = first+d*(i-0);
			ll mx1 = last+d*(n-1-i);
			ans = max(ans, min(mx0, mx1));
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
#define END	 verify_case(_, TheArray().find(n, d, first, last));}
int main(){

CASE(0)
	int n = 3; 
	int d = 5; 
	int first = 2; 
	int last = 4; 
	int _ = 7; 
END
CASE(1)
	int n = 10; 
	int d = 100; 
	int first = 999; 
	int last = 100; 
	int _ = 999; 
END
CASE(2)
	int n = 1000000; 
	int d = 0; 
	int first = 474; 
	int last = 474; 
	int _ = 474; 
END
CASE(3)
	int n = 97; 
	int d = 53; 
	int first = -92; 
	int last = 441; 
	int _ = 2717; 
END
CASE(4)
	int n = 99; 
	int d = 3; 
	int first = -743; 
	int last = -619; 
	int _ = -535; 
END

}
// END CUT HERE
