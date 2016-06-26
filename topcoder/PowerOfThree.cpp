// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Fox Ciel has a robot.
The robot is located on an infinite plane.
At the beginning, the robot starts at the coordinates (0, 0).
The robot can then make several steps.
The steps are numbered starting from 0.

In each step, Ciel must choose one of four directions for the robot: left (x coordinate decreases), right (x coordinate increases), up (y coordinate increases), or down (y coordinate decreases).
In step k, the robot will move 3^k units in the chosen direction.
It is not allowed to skip a step.

You are given ints x and y.
Return "Possible" (quotes for clarity) if it is possible that the robot reaches the point (x,y) after some (possibly zero) steps.
Otherwise, return "Impossible".

DEFINITION
Class:PowerOfThree
Method:ableToGet
Parameters:int, int
Returns:string
Method signature:string ableToGet(int x, int y)


CONSTRAINTS
-x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-y will be between -1,000,000,000 and 1,000,000,000, inclusive.


EXAMPLES

0)
1
3

Returns: "Possible"

In step 0 Ciel will send the robot right to (1,0). In step 1 she will send it up to (1,3).

1)
0
2

Returns: "Possible"

The robot will move from (0,0) down to (0,-1) and then up to (0,2).

2)
1
9

Returns: "Impossible"

Note that it is not allowed to move the robot right in step 0, skip step 1, and then move the robot up in step 2.

3)
3
0

Returns: "Impossible"



4)
1
1

Returns: "Impossible"



5)
-6890
18252

Returns: "Possible"



6)
1000000000
-1000000000

Returns: "Impossible"



7)
0
0

Returns: "Possible"



******************************/
// END CUT HERE
#line 100 "PowerOfThree.cpp"
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

class PowerOfThreeTry {
	public:
	string ableToGet(int x, int y) {
		while(1) {
			if(x==0&&y==0)break;
			ll rx=(x%3+3)%3;
			ll ry=(y%3+3)%3;
			if(rx==0&&ry==1) y--;
			else if(rx==0&&ry==2) y++;
			else if(rx==1&&ry==0) x--;
			else if(rx==2&&ry==0) x++;
			else return "Impossible";
			x/=3; y/=3;
		}
		return "Possible";
	}
};

class PowerOfThree {
	public:
	bool f(ll X, ll Y, ll step) {
		if(X==0 && Y==0 && step==0) return true;
		if(step==0) return false;
		return f(X+(X>0?-1:1)*step, Y, step/3) || f(X, Y+(Y>0?-1:1)*step, step/3);
	}
	string ableToGet(int x, int y) {
		bool ans=false;
		if(x==0 && y==0) return "Possible";
		REP(k, 22) {
			ll step=1;
			REP(i, k) step*=3;
			ans = ans || f(x, y, step);
			if(ans) break;
		}
		return ans ? "Possible" : "Impossible";
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const string& Expected, const string& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, PowerOfThree().ableToGet(x, y));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int x = 1; 
	int y = 3; 
	string _ = "Possible"; 
END
CASE(1)
	int x = 0; 
	int y = 2; 
	string _ = "Possible"; 
END
CASE(2)
	int x = 1; 
	int y = 9; 
	string _ = "Impossible"; 
END
CASE(3)
	int x = 3; 
	int y = 0; 
	string _ = "Impossible"; 
END
CASE(4)
	int x = 1; 
	int y = 1; 
	string _ = "Impossible"; 
END
CASE(5)
	int x = -6890; 
	int y = 18252; 
	string _ = "Possible"; 
END
CASE(6)
	int x = 1000000000; 
	int y = -1000000000; 
	string _ = "Impossible"; 
END
CASE(7)
	int x = 0; 
	int y = 0; 
	string _ = "Possible"; 
END
#if 01  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<1000;loop++) {
// param type: int
start_time=clock();
	int x = UNIFORM_LL(-1000000000, 1000000000); 
// param type: int
start_time=clock();
	int y = UNIFORM_LL(-1000000000, 1000000000); 
	string _0 = PowerOfThree().ableToGet(x, y);
	string _1 = PowerOfThreeTry().ableToGet(x, y);
	if(!verify_case(_0, _1, true)) {
print(x);
print(y);
	}
}
#endif

}
// END CUT HERE
