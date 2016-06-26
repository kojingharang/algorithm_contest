// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There are some red points and blue points on the Cartesian plane.
All red points are on the x-axis and all blue points are in the upper half-plane. That is, the y-coordinate of each red point is 0, and the y-coordinate of each blue point is strictly positive.

Fox Ciel wants to form an ear-shaped figure using these points.
She defines that the pair of four different red points A, B, C, D and two blue points P, Q is called an ear if and only if all the following conditions are satisfied.


Both points B and C lie strictly inside the segment AD.
The angles PAD, PDA, QBC and QCB are strictly less than 90 degrees.
Point Q is in strictly inside of the triangle PAD.


In the following image, points in the left figure form an ear while points in the right figure do not.



You are given three vector <string>s redX, blueX and blueY.
Concatenate all elements of redX to get a space-separate list of integers.
The i-th integer of this list represents the x-coordinate of i-th red point.
In the same way, blueX and blueY encode lists of x-coordinates and y-coordinates of blue points.

Your method must return the number of ways in which we can choose the four red and two blue points that form an ear.


DEFINITION
Class:Ear
Method:getCount
Parameters:vector <string>, vector <string>, vector <string>
Returns:long long
Method signature:long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY)


NOTES
-The order of points in an ear does not matter. I.e., if two ears have the same four red and two blue points, they are considered the same.


CONSTRAINTS
-redX, blueX and blueY will each contain between 1 and 50 elements, inclusive.
-Each element of redX, blueX and blueY will contain between 1 and 50 characters, inclusive.
-After concatenating the elements of redX, the resulting string will be a single space separated list of integers.
-After concatenating the elements of blueX, the resulting string will be a single space separated list of integers.
-After concatenating the elements of blueY, the resulting string will be a single space separated list of integers.
-There will be between 1 and 300 integers in each of the lists.
-The number of integers in the lists of blueX and blueY will be the same.
-Each integer in the lists will be between 1 and 10,000, inclusive.
-All the integers in each list will be distinct.
-Integers in the lists will have no leading zeros.


EXAMPLES

0)
{"3 2 8 7"}
{"5 4"}
{"2 4"}

Returns: 1

This case corresponds to the left figure in the statement.

1)
{"3 2 8 7"}
{"2 8"}
{"3 4"}

Returns: 0

This case corresponds to the right figure in the statement.

2)
{"1 2 6 9"}
{"3 6 8 5"}
{"1 5 4 3"}

Returns: 4

There exists only one possible combinations of A, B, C and D since there are only four red points. Possible combinations of P and Q are as follows.

{(5, 3), (3, 1)}
{(6, 5), (3, 1)}
{(8, 4), (3, 1)}
{(6, 5), (5, 3)}




3)
{"10000"}
{"10000 9999"}
{"10000 9999"}

Returns: 0

It is impossible to choose four red points from only one red point.

4)
{"100 2", "00", " 39", "9", " 800 900 9", "99"}
{"15", "0 250 ", "349"}
{"2 3 1"}

Returns: 12

Concatenate each element of the vector <string>s correctly.

5)
{"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"}
{"4", " ", "5", " ", "6", " 7 ", "8"}
{"1", " 2 ", "3 4", " 5"}

Returns: 204



*/
// END CUT HERE
#line 120 "Ear.cpp"

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



class Ear {
	public:
	long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) {
		stringstream ss(accumulate(ALL(redX), string("")));
		int v;
		while(ss>>v) {
			cout<<v<<endl;
		}
		return 0;
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
#define END	 verify_case(_, Ear().getCount(redX, blueX, blueY));}
int main(){

CASE(0)
	string redX_[] = {"3 2 8 7"};
	  vector <string> redX(redX_, redX_+sizeof(redX_)/sizeof(*redX_)); 
	string blueX_[] = {"5 4"};
	  vector <string> blueX(blueX_, blueX_+sizeof(blueX_)/sizeof(*blueX_)); 
	string blueY_[] = {"2 4"};
	  vector <string> blueY(blueY_, blueY_+sizeof(blueY_)/sizeof(*blueY_)); 
	long long _ = 1LL; 
END
return 0;
CASE(1)
	string redX_[] = {"3 2 8 7"};
	  vector <string> redX(redX_, redX_+sizeof(redX_)/sizeof(*redX_)); 
	string blueX_[] = {"2 8"};
	  vector <string> blueX(blueX_, blueX_+sizeof(blueX_)/sizeof(*blueX_)); 
	string blueY_[] = {"3 4"};
	  vector <string> blueY(blueY_, blueY_+sizeof(blueY_)/sizeof(*blueY_)); 
	long long _ = 0LL; 
END
CASE(2)
	string redX_[] = {"1 2 6 9"};
	  vector <string> redX(redX_, redX_+sizeof(redX_)/sizeof(*redX_)); 
	string blueX_[] = {"3 6 8 5"};
	  vector <string> blueX(blueX_, blueX_+sizeof(blueX_)/sizeof(*blueX_)); 
	string blueY_[] = {"1 5 4 3"};
	  vector <string> blueY(blueY_, blueY_+sizeof(blueY_)/sizeof(*blueY_)); 
	long long _ = 4LL; 
END
CASE(3)
	string redX_[] = {"10000"};
	  vector <string> redX(redX_, redX_+sizeof(redX_)/sizeof(*redX_)); 
	string blueX_[] = {"10000 9999"};
	  vector <string> blueX(blueX_, blueX_+sizeof(blueX_)/sizeof(*blueX_)); 
	string blueY_[] = {"10000 9999"};
	  vector <string> blueY(blueY_, blueY_+sizeof(blueY_)/sizeof(*blueY_)); 
	long long _ = 0LL; 
END
CASE(4)
	string redX_[] = {"100 2", "00", " 39", "9", " 800 900 9", "99"};
	  vector <string> redX(redX_, redX_+sizeof(redX_)/sizeof(*redX_)); 
	string blueX_[] = {"15", "0 250 ", "349"};
	  vector <string> blueX(blueX_, blueX_+sizeof(blueX_)/sizeof(*blueX_)); 
	string blueY_[] = {"2 3 1"};
	  vector <string> blueY(blueY_, blueY_+sizeof(blueY_)/sizeof(*blueY_)); 
	long long _ = 12LL; 
END
CASE(5)
	string redX_[] = {"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"};
	  vector <string> redX(redX_, redX_+sizeof(redX_)/sizeof(*redX_)); 
	string blueX_[] = {"4", " ", "5", " ", "6", " 7 ", "8"};
	  vector <string> blueX(blueX_, blueX_+sizeof(blueX_)/sizeof(*blueX_)); 
	string blueY_[] = {"1", " 2 ", "3 4", " 5"};
	  vector <string> blueY(blueY_, blueY_+sizeof(blueY_)/sizeof(*blueY_)); 
	long long _ = 204LL; 
END

}
// END CUT HERE
