// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You may remember an old computer game called "The Incredible Machine".  It was a game where you could simulate simple processes like balls falling, lasers shooting, or cats pursuing mice.  Moreover, you were able to perform these observations with different values for gravitational acceleration.

We are observing a system with some unknown acceleration of gravity.  There is a slope which has the form of a polyline with N vertices.  Each vertex of the polyline is positioned lower and to the right of the previous one.  At time 0, a ball is placed at the first vertex.  The ball is small enough to be considered a single point.  Assume that there's no friction between the slope and the ball, the ball is absolutely nonelastic, and the direction of its velocity changes instantly at the polyline's vertices.  Under these conditions, the ball will follow the polyline without ever losing contact with it.  The ball reaches the final vertex at time T.

You are given vector <int>s x and y, where (x[i], y[i]) are the coordinates of the i-th vertex.  Return the gravitational acceleration in this system.  A body rolling down an inclined plane of angle alpha (measured between the plane and horizontal direction) under gravitational acceleration g has a constant acceleration of a = g * sin(alpha). The distance d travelled by an object during time t moving with initial velocity v0 and with constant acceleration a is equal to d = v0 * t + 0.5 * a * t^2. The velocity v1 of the object after time t has passed is equal to v1 = v0 + a * t.

DEFINITION
Class:IncredibleMachine
Method:gravitationalAcceleration
Parameters:vector <int>, vector <int>, int
Returns:double
Method signature:double gravitationalAcceleration(vector <int> x, vector <int> y, int T)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-x will contain between 2 and 50 elements, inclusive.
-Elements of x will be strictly ascending.
-Elements of x will be between 0 and 100, inclusive.
-x and y will contain the same number of elements.
-Elements of y will be strictly descending.
-Elements of y will be between 0 and 100, inclusive.
-T will be between 1 and 100, inclusive.


EXAMPLES

0)
{0,6}
{100,22}
4

Returns: 9.807692307692307

That's an acceleration of gravity that might be somewhere on Earth's surface.


1)
{0,26,100}
{50,26,24}
4

Returns: 26.743031720603582

And this is likely on Jupiter.


2)
{0,7,8}
{10,6,0}
7

Returns: 1.1076837407708007

Note that in spite of the angle at vertex (7,6), the body won't fly off the slope and will follow the segment (7,6)-(8,0).



*/
// END CUT HERE
#line 68 "IncredibleMachine.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class IncredibleMachine {
	public:
	double gravitationalAcceleration(vector <int> x, vector <int> y, int T) {
		double lo = 0, hi = 1e20;
		REP(loop, 1000) {
			double g = (lo+hi)/2;
			double t = 0;
			double v = 0;
			for(int i=1;i<x.size();i++) {
				double a = g*sin(-atan( ((double)y[i]-y[i-1])/(x[i]-x[i-1]) ));
				double d = sqrt( ((double)x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]) );
				double tt = (-v + sqrt(v*v+2*a*d))/a;
				t+=tt;
				v += a*tt;
				//cout<<t<<" "<<g<<"  "<<v<<" "<<d<<"   "<<-atan( ((double)y[i]-y[i-1])/(x[i]-x[i-1]) )<<endl;
			}
			if(t<T) hi=g;
			else    lo=g;
		}
		return (lo+hi)/2;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,22}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; double Arg3 = 9.807692307692307; verify_case(0, Arg3, gravitationalAcceleration(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,26,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,26,24}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; double Arg3 = 26.743031720603582; verify_case(1, Arg3, gravitationalAcceleration(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,7,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,6,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; double Arg3 = 1.1076837407708007; verify_case(2, Arg3, gravitationalAcceleration(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	IncredibleMachine ___test;

	___test.run_test(-1);
	//___test.test_case_0();

}

// END CUT HERE
