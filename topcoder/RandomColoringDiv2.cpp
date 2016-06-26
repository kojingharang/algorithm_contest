// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Little Arthur has a new frisbee and he would like to color it. A frisbee has the shape of a disc. Arthur will color the disc using two colors: one for the top side, one for the bottom side.

Each color is defined by three integer components: R, G, and B (meaning red, green, and blue, respectively), where 0 <= R < maxR, 0 <= G < maxG, and 0 <= B < maxB. It is known that Arthur can use any of the maxR*maxG*maxB possible colors.

Arthur is going to perform the coloring in the following way:

In the first step, he will color the top side of the frisbee using the color (startR, startG, startB).
In the second step, he will color the bottom side of the frisbee using a color that makes a good transition from the first color. (This is explained below.)


A transition from color (R, G, B) to color (R', G', B') is called good if all components differ by at most d2 units (formally, |R - R'| <= d2, |G - G'| <= d2, |B - B'| <= d2) and at least one component differs by at least d1 units (formally, at least one of the conditions |R - R'| >= d1, |G - G'| >= d1, |B - B'| >= d1 holds). Intuitively, a transition between two colors is called good if they are neither too similar, nor too different.

After coloring the top side Arthur is wondering how many different options there are now for the color of the bottom side of the frisbee.

Given ints maxR, maxG, maxB, startR, startG, startB, d1, and d2, return the number of valid colors that make a good transition from the color (startR, startG, startB).

DEFINITION
Class:RandomColoringDiv2
Method:getCount
Parameters:int, int, int, int, int, int, int, int
Returns:int
Method signature:int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2)


CONSTRAINTS
-maxR, maxG and maxB will each be between 1 and 100, inclusive.
-startR will be between 0 and maxR-1, inclusive.
-startG will be between 0 and maxG-1, inclusive.
-startB will be between 0 and maxB-1, inclusive.
-d1 and d2 will each be between 0 and 100, inclusive.
-d1 will be less than or equal to d2.


EXAMPLES

0)
5
1
1
2
0
0
0
1

Returns: 3

Only the R component can change here. It has to change by at least 0 and at most 1. Thus the colors that make a good transition from color (2, 0, 0) here are (1, 0, 0), (2, 0, 0), and (3, 0, 0).

1)
4
2
2
0
0
0
3
3

Returns: 4

Colors that make a good transition from color (0, 0, 0) here are (3, 0, 0), (3, 0, 1), (3, 1, 0), and (3, 1, 1).

2)
4
2
2
0
0
0
5
5

Returns: 0

At least one component has to change by 5. There exists no color that makes a good transition from color (0, 0, 0) within the respective maxR, maxG, maxB constraints.

3)
6
9
10
1
2
3
0
10

Returns: 540

All valid colors make a good transition from color (1, 2, 3).

4)
6
9
10
1
2
3
4
10

Returns: 330



5)
49
59
53
12
23
13
11
22

Returns: 47439

*/
// END CUT HERE
#line 124 "RandomColoringDiv2.cpp"

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



class RandomColoringDiv2 {
	public:
	int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
		int ans=0;
		REP(r, maxR)
		REP(g, maxG)
		REP(b, maxB) {
			if(abs(startR-r)<=d2 && abs(startG-g)<=d2 && abs(startB-b)<=d2
			&& (abs(startR-r)>=d1 || abs(startG-g)>=d1 || abs(startB-b)>=d1)) ans++;
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
#define END	 verify_case(_, RandomColoringDiv2().getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2));}
int main(){

CASE(0)
	int maxR = 5; 
	int maxG = 1; 
	int maxB = 1; 
	int startR = 2; 
	int startG = 0; 
	int startB = 0; 
	int d1 = 0; 
	int d2 = 1; 
	int _ = 3; 
END
CASE(1)
	int maxR = 4; 
	int maxG = 2; 
	int maxB = 2; 
	int startR = 0; 
	int startG = 0; 
	int startB = 0; 
	int d1 = 3; 
	int d2 = 3; 
	int _ = 4; 
END
CASE(2)
	int maxR = 4; 
	int maxG = 2; 
	int maxB = 2; 
	int startR = 0; 
	int startG = 0; 
	int startB = 0; 
	int d1 = 5; 
	int d2 = 5; 
	int _ = 0; 
END
CASE(3)
	int maxR = 6; 
	int maxG = 9; 
	int maxB = 10; 
	int startR = 1; 
	int startG = 2; 
	int startB = 3; 
	int d1 = 0; 
	int d2 = 10; 
	int _ = 540; 
END
CASE(4)
	int maxR = 6; 
	int maxG = 9; 
	int maxB = 10; 
	int startR = 1; 
	int startG = 2; 
	int startB = 3; 
	int d1 = 4; 
	int d2 = 10; 
	int _ = 330; 
END
CASE(5)
	int maxR = 49; 
	int maxG = 59; 
	int maxB = 53; 
	int startR = 12; 
	int startG = 23; 
	int startB = 13; 
	int d1 = 11; 
	int d2 = 22; 
	int _ = 47439; 
END

}
// END CUT HERE
