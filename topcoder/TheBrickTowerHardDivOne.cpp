// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
John and Brus are building towers using toy bricks.
They have an unlimited supply of bricks of C different colors.
Each brick is a 1x1x1 cube.
A tower of height X is a 2x2xX rectangular prism, built using 4X bricks.



John and Brus want their towers to look nice.
A tower is nice if it has the following two properties:

There are at most K pairs of neighboring bricks with the same color. (Two bricks are neighboring if they share a common side.)
The height of the tower is between 1 and H, inclusive.




You are given the ints C and K and the long long H.
Return the number of nice towers, modulo 1,234,567,891.



DEFINITION
Class:TheBrickTowerHardDivOne
Method:find
Parameters:int, int, long long
Returns:int
Method signature:int find(int C, int K, long long H)


CONSTRAINTS
-C will be between 1 and 4747, inclusive.
-K will be between 0 and 7, inclusive.
-H will be between 1 and 474,747,474,747,474,747, inclusive.


EXAMPLES

0)
2
0
2

Returns: 4

No two neighboring bricks may share the same color.
As we only have two colors, the entire tower must be colored like a chessboard.
There are two such towers of height 1, and two of height 2.


1)
1
7
19

Returns: 1

Only one tower of height 1 is acceptable here.


2)
2
3
1

Returns: 14

There are 16 possible towers of height 1.
If all bricks share the same color, the tower is not nice.
There are two such towers.
Each of the remaining 14 towers is nice.


3)
4
7
47

Returns: 1008981254

*/
// END CUT HERE
#line 87 "TheBrickTowerHardDivOne.cpp"

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
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <iomanip>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VS vector<string>
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class TheBrickTowerHardDivOne {
	public:
	int find(int C, int K, long long H) {
		
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
#define END	 verify_case(_, TheBrickTowerHardDivOne().find(C, K, H));}
int main(){

CASE(0)
	int C = 2; 
	int K = 0; 
	long long H = 2LL; 
	int _ = 4; 
END
CASE(1)
	int C = 1; 
	int K = 7; 
	long long H = 19LL; 
	int _ = 1; 
END
CASE(2)
	int C = 2; 
	int K = 3; 
	long long H = 1LL; 
	int _ = 14; 
END
CASE(3)
	int C = 4; 
	int K = 7; 
	long long H = 47LL; 
	int _ = 1008981254; 
END

}
// END CUT HERE
