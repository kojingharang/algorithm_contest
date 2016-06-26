// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Manao is developing a simple 2-D computer game. The screen of the game is H pixels high and W pixels wide (1 <= H, W <= 50).

Manao is currently working on the background which should be filled with N mountains (1 <= N <= 10). The mountains are numbered from 0 to N-1. The contents of the screen are stored in an array of characters pix where pix[x, y] gives the contents of the pixel at column x, row y. Both indices are 0-based. Columns are numbered left to right and rows are numbered bottom to top. The parts of the screen where the i-th mountain is visible are denoted by digit i. Character '.' means that the corresponding pixel is not covered by any mountains.

The i-th (0-based index) mountain is described by its peak position (X[i], Y[i]), 0 <= X[i] < W, 0 <= Y[i] < H. In order to draw the mountains, the following pseudocode is used:

Fill all elements of pix with '.' characters.
For 0 <= i < N:
??For 0 <= x < W:
????For 0 <= y <= Y[i] - |x - X[i]|:
??????pix[x, y] := i + '0'

For example, consider three mountains with peaks at (1, 1), (2, 2) and (4, 1). Once these mountains are drawn on a screen with H = 3, W = 6, the resulting picture will look as follows:

..1...
.1112.
111222


Manao has recently filled the background with N mountains as described above. After that he wrote down the height of each mountain. Also, for each column he wrote down which mountains were visible at that column. You are given a vector <int> heights containing N elements. Element i of heights gives the height of the i-th mountain in pixels (which is equal to Y[i] + 1). You are also given a vector <string> visibility. It contains N elements and each element is W characters long. The j-th character of visibility[i] is equal to 'X' if the i-th mountain was visible at column j of the screen and '-' otherwise. In other words, the j-th character of visibility[i] is equal 'X' if and only if at least one pixel of column j contained digit i after all mountains were drawn.

Count the number of sequences of exactly N mountains that match the information given by heights and visibility. Return this number modulo 1,000,000,009. It is guaranteed that there exists at least one such sequence.

DEFINITION
Class:Mountains
Method:countPlacements
Parameters:vector <int>, vector <string>
Returns:int
Method signature:int countPlacements(vector <int> heights, vector <string> visibility)


NOTES
-The value of H is not directly given in the input parameters. For the purposes of this problem, you can assume that H is equal to the largest element of heights.


CONSTRAINTS
-heights will contain between 1 and 10 elements, inclusive.
-Each element of heights will be between 1 and 50, inclusive.
-visibility will contain the same number of elements as heights.
-Each element of visibility will be between 1 and 50 characters long, inclusive.
-All elements of visibility will be of the same length.
-Each element of visibility will consist of 'X' and '-' characters only.
-At least one sequence of mountains matching the given information will exist.


EXAMPLES

0)
{2, 3, 2}
{"------",
 "XXXX--",
 "---XXX"}

Returns: 4

The given information corresponds to the three mountains from the problem statement. Mountains 1 and 2 are uniquely determined. Mountain 0 can have the peak in each column from 1 to 4.

1)
{4, 3, 4}
{"XXXXX--------",
 "----------XXX",
 "----XXXXXXX--"}

Returns: 4

The four possible mountain sequences are:

(2, 3), (10, 2), (7, 3)
(2, 3), (11, 2), (7, 3)
(3, 3), (10, 2), (7, 3)
(3, 3), (11, 2), (7, 3)


After drawing these sequences, the following pictures are obtained:
..0....2.....??????..0....2.....??????...0...2.....??????...0...2.....
.000..222.1..??????.000..222..1.??????..000.222.1..??????..000.222..1.
000002222211.??????0000022222111??????.00002222211.??????.000022222111
0000222222211??????0000222222211??????0000222222211??????0000222222211

2)
{13, 2, 3, 2}
{"XXXXXXXXX",
 "-XXX-----",
 "----XXXXX",
 "-----XXX-"}

Returns: 9



3)
{8, 2, 9, 3, 10}
{"X------",
 "-------",
 "------X",
 "-------",
 "XXXXXXX"}

Returns: 98



4)
{20, 20, 20, 20, 20, 20, 45, 50, 49, 50}
{"-------------------",
 "-------------------",
 "-------------------",
 "-------------------",
 "-------------------",
 "-------------------",
 "-------------------",
 "------------XXXXXXX",
 "XXXXXXX------------",
 "XXXXXXXXXXXXXXXXXXX"}


Returns: 973726691



*/
// END CUT HERE
#line 127 "Mountains.cpp"

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



class Mountains {
	public:
	int countPlacements(vector <int> heights, vector <string> visibility) {
		
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
#define END	 verify_case(_, Mountains().countPlacements(heights, visibility));}
int main(){

CASE(0)
	int heights_[] = {2, 3, 2};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	string visibility_[] = {"------",
 "XXXX--",
 "---XXX"};
	  vector <string> visibility(visibility_, visibility_+sizeof(visibility_)/sizeof(*visibility_)); 
	int _ = 4; 
END
CASE(1)
	int heights_[] = {4, 3, 4};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	string visibility_[] = {"XXXXX--------",
 "----------XXX",
 "----XXXXXXX--"};
	  vector <string> visibility(visibility_, visibility_+sizeof(visibility_)/sizeof(*visibility_)); 
	int _ = 4; 
END
CASE(2)
	int heights_[] = {13, 2, 3, 2};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	string visibility_[] = {"XXXXXXXXX",
 "-XXX-----",
 "----XXXXX",
 "-----XXX-"};
	  vector <string> visibility(visibility_, visibility_+sizeof(visibility_)/sizeof(*visibility_)); 
	int _ = 9; 
END
CASE(3)
	int heights_[] = {8, 2, 9, 3, 10};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	string visibility_[] = {"X------",
 "-------",
 "------X",
 "-------",
 "XXXXXXX"};
	  vector <string> visibility(visibility_, visibility_+sizeof(visibility_)/sizeof(*visibility_)); 
	int _ = 98; 
END
CASE(4)
	int heights_[] = {20, 20, 20, 20, 20, 20, 45, 50, 49, 50};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	string visibility_[] = {"-------------------",
 "-------------------",
 "-------------------",
 "-------------------",
 "-------------------",
 "-------------------",
 "-------------------",
 "------------XXXXXXX",
 "XXXXXXX------------",
 "XXXXXXXXXXXXXXXXXXX"}
;
	  vector <string> visibility(visibility_, visibility_+sizeof(visibility_)/sizeof(*visibility_)); 
	int _ = 973726691; 
END

}
// END CUT HERE
