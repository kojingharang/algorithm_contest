// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// There are N cities in the plane.
For convenience, the cities are numbered 0 through N-1.
For each i, the city number i is represented by the point at coordinates (x[i], y[i]).


The king wants to connect all cities by building exactly N-1 roads.
Each road must connect two cities.
All roads must be straight.
Hence, the length of a road is equal to the Euclidean distance between the two points it connects.
The roads are allowed to cross and even overlap arbitrarily.
(You cannot change roads at a crossing.
Hence, the N-1 roads connect all cities if and only if their topology is a tree.)


The king does not care about roads being short.
However, people often complain if some roads are short and others are long.
Therefore, the king would like to select a set of N-1 roads such that they connect all cities, and the standard deviation of the sequence of their lengths is as small as possible.


Formally, given a sequence of real numbers (a1,...,aS) we can compute their standard deviation as follows.
First, let b = ((a1+...+aS) / S) be their mean - i.e., the average of our numbers.
Next, let c = (sum_i (b-ai)^2) be the sum of squared distances of all values from the mean.
Finally, the standard deviation of our sequence is computed as sqrt(c/S).
Note that our sequence will contain exactly N-1 road lengths, hence in the above formulas S will be equal to N-1.


You are given the vector <int>s x and y with N elements each: the coordinates of the N points.
Compute and return the smallest possible value of the standard deviation of lengths of selected roads.

DEFINITION
Class:Egalitarianism2
Method:minStdev
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double minStdev(vector <int> x, vector <int> y)


NOTES
-The Euclidean distance between points (a,b) and (c,d) equals sqrt( (a-c)^2 + (b-d)^2 ).
-Your return value must have an absolute or a relative error of less than 1e-9.


CONSTRAINTS
-x will contain between 3 and 20 elements, inclusive.
-x and y will contain same number of elements.
-Each element in x will be between -1,000,000 and 1,000,000, inclusive.
-Each element in y will be between -1,000,000 and 1,000,000, inclusive.
-No two cities will be located in the same place.


EXAMPLES

0)
{0,0,1,1}
{0,1,0,1}

Returns: 0.0

We can build these roads: 0-1, 1-3, 3-2.

1)
{0,0,0}
{0,9,10}

Returns: 0.5

The optimal solution is to build the roads with lengths 9 and 10. (Note that these two roads overlap, but that is allowed.)

2)
{12,46,81,56}
{0,45,2,67}

Returns: 6.102799971320872



3)
{0,0,0,0,0,0,0}
{0,2,3,9,10,15,16}

Returns: 0.9428090415820617



4)
{167053, 536770, -590401, 507047, 350178, -274523, -584679, -766795, -664177, 267757, -291856, -765547, 604801, -682922, -404590, 468001, 607925, 503849, -499699, -798637}
{-12396, -66098, -56843, 20270, 81510, -23294, 10423, 24007, -24343, -21587, -6318, -7396, -68622, 56304, -85680, -14890, -38373, -25477, -38240, 11736}

Returns: 40056.95946451678



5)
{-306880, 169480, -558404, -193925, 654444, -300247, -456420, -119436, -620920, -470018, -914272, -691256, -49418, -21054, 603373, -23656, 891691, 258986, -453793, -782940}
{-77318, -632629, -344942, -361706, 191982, 349424, 676536, 166124, 291342, -268968, 188262, -537953, -70432, 156803, 166174, 345128, 58614, -671747, 508265, 92324}

Returns: 36879.1512763429



******************************/
// END CUT HERE
#line 107 "Egalitarianism2.cpp"
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class Egalitarianism2 {
	public:
	double minStdev(vector <int> x, vector <int> y) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const double& Expected, const double& Received, bool noPASSmsg=false) {
 double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, Egalitarianism2().minStdev(x, y));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int x_[] = {0,0,1,1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,1,0,1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	double _ = 0.0; 
END
CASE(1)
	int x_[] = {0,0,0};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,9,10};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	double _ = 0.5; 
END
CASE(2)
	int x_[] = {12,46,81,56};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,45,2,67};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	double _ = 6.102799971320872; 
END
CASE(3)
	int x_[] = {0,0,0,0,0,0,0};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,2,3,9,10,15,16};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	double _ = 0.9428090415820617; 
END
CASE(4)
	int x_[] = {167053, 536770, -590401, 507047, 350178, -274523, -584679, -766795, -664177, 267757, -291856, -765547, 604801, -682922, -404590, 468001, 607925, 503849, -499699, -798637};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-12396, -66098, -56843, 20270, 81510, -23294, 10423, 24007, -24343, -21587, -6318, -7396, -68622, 56304, -85680, -14890, -38373, -25477, -38240, 11736};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	double _ = 40056.95946451678; 
END
CASE(5)
	int x_[] = {-306880, 169480, -558404, -193925, 654444, -300247, -456420, -119436, -620920, -470018, -914272, -691256, -49418, -21054, 603373, -23656, 891691, 258986, -453793, -782940};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-77318, -632629, -344942, -361706, 191982, 349424, 676536, 166124, 291342, -268968, 188262, -537953, -70432, 156803, 166174, 345128, 58614, -671747, 508265, 92324};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	double _ = 36879.1512763429; 
END
#if 0  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: int
	vector <int> x; 
	{
		int N=UNIFORM_LL(1, 51);
		x = vector <int>(N); 
		REP(i, N) {
			x[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> y; 
	{
		int N=UNIFORM_LL(1, 51);
		y = vector <int>(N); 
		REP(i, N) {
			y[i] = UNIFORM_LL(0, 1000);
		}
	}
	double _0 = Egalitarianism2().minStdev(x, y);
	double _1 = Egalitarianism2Ref().minStdev(x, y);
	if(!verify_case(_0, _1, true)) {
print(x);
print(y);
	}
}
#endif

}
// END CUT HERE
