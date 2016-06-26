// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Robot Herb is playing on an infinite square grid.
At any moment, Herb stands on one of the squares and he faces one of the four cardinal directions.
In his memory, Herb has a program.
The program is a sequence of commands.
For each i, the i-th of these commands has the following form:

First move forward a[i] tiles.
Then turn 90 degrees to the right, a[i] times in a row.

Herb has decided to run the program T times.
You are given the int T and the vector <int> a that describes Herb's program.
Let A be the initial position of Herb and B be his position after the program was executed T times. Return the Manhattan distance between tiles A and B.

DEFINITION
Class:RobotHerb
Method:getdist
Parameters:int, vector <int>
Returns:long long
Method signature:long long getdist(int T, vector <int> a)


NOTES
-Let's introduce a Cartesian coordinate system on the grid so that each cardinal direction is parallel to one of the axes. The Manhattan distance between two tiles with centers at points (x1, y1) and (x2, y2) is defined as |x1-x2| + |y1-y2|.


CONSTRAINTS
-T will be between 1 and 1,000,000,000, inclusive.
-a will contain between 1 and 50 elements, inclusive.
-Each element of a will be between 1 and 10,000,000, inclusive.


EXAMPLES

0)
1
{1,2,3}

Returns: 2

Suppose that initially Herb stands on the tile with center at (0, 0) and faces the positive y direction. The program will get executed as follows:

                       tile         direction
After 1st command:     (0, 1)       positive x
After 2nd command:     (2, 1)       negative x
After 3rd command:     (-1, 1)      negative y

The manhattan distance between the initial and the final positions is |-1| + |1| = 2.

1)
100
{1}

Returns: 0



2)
5
{1,1,2}

Returns: 10



3)
1000000000
{100}

Returns: 100000000000

The answer doesn't fit into a 32-bit integer data type.

4)
570
{2013,2,13,314,271,1414,1732}

Returns: 4112



*/
// END CUT HERE
#line 87 "RobotHerb.cpp"

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



#define ABS(x) (x>=0 ? x : (-x))

class RobotHerb {
	public:
	
	void go(vector<int>& A, ll& x, ll& y, ll& dir) {
		ll dx[] = {0,1,0,-1};
		ll dy[] = {1,0,-1,0};
		REP(i, A.size()) {
			x+=dx[dir]*A[i];
			y+=dy[dir]*A[i];
			dir = (dir+A[i]%4) % 4;
		}
	}
	long long getdist(int T, vector <int> A) {
		ll x4=0,y4=0,dir=0;
		REP(i, 4) go(A, x4, y4, dir);
		ll x=x4*(T/4),y=y4*(T/4);
		cout<<x4<<" "<<y4<<endl;
		REP(i, T%4) go(A, x, y, dir);
		cout<<x<<" "<<y<<endl;
		//return llabs(x)+llabs(y);
		return ABS(x)+ABS(y);
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
#define END	 verify_case(_, RobotHerb().getdist(T, a));}
int main(){

CASE(0)
	int T = 1; 
	int a_[] = {1,2,3};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	long long _ = 2LL; 
END
CASE(1)
	int T = 100; 
	int a_[] = {1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	long long _ = 0LL; 
END
CASE(2)
	int T = 5; 
	int a_[] = {1,1,2};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	long long _ = 10LL; 
END
CASE(3)
	int T = 1000000000; 
	int a_[] = {100};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	long long _ = 100000000000LL; 
END
CASE(4)
	int T = 570; 
	int a_[] = {2013,2,13,314,271,1414,1732};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	long long _ = 4112LL; 
END

}
// END CUT HERE
