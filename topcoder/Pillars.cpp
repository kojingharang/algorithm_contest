// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// On a horizontal line, there are two vertical pillars.
The distance between their bottoms is w.
The height of the first pillar is an integer, chosen uniformly at random in the range 1 through x, inclusive.
The height of the second pillar is an integer, chosen uniformly at random in the range 1 through y, inclusive.
The tops of both pillars will be connected by a straight piece of rope.

You are given the ints w, x, and y.
Compute and return the expected length of the rope.

DEFINITION
Class:Pillars
Method:getExpectedLength
Parameters:int, int, int
Returns:double
Method signature:double getExpectedLength(int w, int x, int y)


NOTES
-Your return value must have a relative or an absolute error of less than 1e-9.
-In this task, the expected rope length can be computed as the average rope length over all possible cases.


CONSTRAINTS
-w will be between 1 and 1000, inclusive.
-x will be between 1 and 100,000, inclusive.
-y will be between 1 and 100,000, inclusive.


EXAMPLES

0)
1
1
1

Returns: 1.0

The rope always has a length of 1.

1)
1
5
1

Returns: 2.387132965131785

There are 5 possible (equiprobable) cases in which the length of the rope is 1, sqrt(2), sqrt(5), sqrt(10) and sqrt(17). The correct answer is the arithmetic average of these 5 numbers.

2)
2
3
15

Returns: 6.737191281760445



3)
10
15
23

Returns: 12.988608956320535



*/
// END CUT HERE
#line 73 "Pillars.cpp"

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
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class Pillars {
	public:
	double getExpectedLength(int w, int x, int y) {
		int L=max(x, y);
		vector<long double> D(L);
		REP(i, L) {
			D[i] = hypot(w, i);
		}
		//cout<<D<<endl;
		long double a=0;
		long double ans=0;
		REP(i, x) a+=D[i];
		ans+=a;
		//cout<<"x y "<<x<<" "<<y<<endl;
		REP(i, y-1) {
			//double b=0;
			//REP(j, x) b+=D[abs(j-(i+1))];
			//REP(j, x) cout<<abs(j-(i+1))<<" ";
			//cout<<endl;
			//ans+=b;
			//cout<<x-1-i<<" "<<i+1<<endl;
			a = a - D[abs(x-1-i)] + D[i+1];
			//cout<<a<<endl;
			ans+=a;
		}
		//cout<<ans<<endl;
		return ans/x/y;
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
void verify_case(const double& Expected, const double& Received) {
 double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, Pillars().getExpectedLength(w, x, y));}
int main(){

CASE(0)
	int w = 1; 
	int x = 1; 
	int y = 1; 
	double _ = 1.0; 
END
CASE(1)
	int w = 1; 
	int x = 5; 
	int y = 1; 
	double _ = 2.387132965131785; 
END
CASE(2)
	int w = 2; 
	int x = 3; 
	int y = 15; 
	double _ = 6.737191281760445; 
END
CASE(3)
	int w = 10; 
	int x = 15; 
	int y = 23; 
	double _ = 12.988608956320535; 
END
CASE(3)
	int w = 1000; 
	int x = 100000; 
	int y = 100000; 
	double _ = 12.988608956320535; 
END

}
// END CUT HERE
