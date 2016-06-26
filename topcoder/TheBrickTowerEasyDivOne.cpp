// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
John and Brus are building towers using toy bricks.
They have two types of bricks: red and blue ones.
The number of red bricks they have is redCount and each of them has a height of redHeight.
The number of blue bricks they have is blueCount and each of them has a height of blueHeight.



A tower is built by placing bricks one atop another.
A brick can be placed either on the ground, or on a brick of a different color.
(I.e., you are not allowed to put two bricks of the same color immediately on one another.)
A tower has to consist of at least one brick.
The height of a tower is the sum of all heights of bricks that form the tower.
Two towers are considered to be different if they have different heights.
(Two towers of the same height are considered the same, even if they differ in the number and colors of bricks that form them.)



You are given the ints redCount, redHeight, blueCount and blueHeight.
Return the number of different towers that John and Brus can build.



DEFINITION
Class:TheBrickTowerEasyDivOne
Method:find
Parameters:int, int, int, int
Returns:int
Method signature:int find(int redCount, int redHeight, int blueCount, int blueHeight)


CONSTRAINTS
-redCount will be between 1 and 474,747,474, inclusive.
-redHeight will be between 1 and 474,747,474, inclusive.
-blueCount will be between 1 and 474,747,474, inclusive.
-blueHeight will be between 1 and 474,747,474, inclusive.


EXAMPLES

0)
1
2
3
4

Returns: 4

John and Brus have 1 red brick of height 2 and 3 blue bricks of height 4. Using these bricks, it's possible to build 4 towers:
red (height 2);
blue (height 4);
red, blue (height 6);
blue, red, blue (height 10).

1)
4
4
4
7

Returns: 12

2)
7
7
4
4

Returns: 13

3)
47
47
47
47

Returns: 94

*/
// END CUT HERE
#line 85 "TheBrickTowerEasyDivOne.cpp"

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



class TheBrickTowerEasyDivOne {
	public:
	int find(int rc, int rh, int bc, int bh) {
		int ans = min(rc, bc)*2;
		if(min(rc, bc)+1 <= max(rc, bc)) ans++;
		if(rh!=bh) {
			ans += min(rc, bc);
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
#define END	 verify_case(_, TheBrickTowerEasyDivOne().find(redCount, redHeight, blueCount, blueHeight));}
int main(){

CASE(0)
	int redCount = 1; 
	int redHeight = 2; 
	int blueCount = 3; 
	int blueHeight = 4; 
	int _ = 4; 
END
CASE(1)
	int redCount = 4; 
	int redHeight = 4; 
	int blueCount = 4; 
	int blueHeight = 7; 
	int _ = 12; 
END
CASE(2)
	int redCount = 7; 
	int redHeight = 7; 
	int blueCount = 4; 
	int blueHeight = 4; 
	int _ = 13; 
END
CASE(3)
	int redCount = 47; 
	int redHeight = 47; 
	int blueCount = 47; 
	int blueHeight = 47; 
	int _ = 94; 
END
CASE(3)
	int redCount = 470418661; 
	int redHeight = 454; 
	int blueCount = 399796762; 
	int blueHeight = 454; 
	int _ = 799593525; 
END
CASE(3)
	int redCount = 474747474; 
	int redHeight = 474747468; 
	int blueCount = 474746558; 
	int blueHeight = 474747468; 
	int _ = 949493117; 
END

}
// END CUT HERE
