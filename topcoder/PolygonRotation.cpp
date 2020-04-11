// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// We have a convex polygon in the XY plane.
The vertices of the polygon are the points (x[0], y[0]), (x[1], y[1]), ... in clockwise order.
You are given the vector <int>s x and y.

In order to make the implementation simpler the polygon and its representation satisfy some additional constraints.
Please read the Constraints section carefully.

A three-dimensional solid is obtained by rotating this polygon around the Y axis.
Compute and return the volume of the resulting solid.


DEFINITION
Class:PolygonRotation
Method:getVolume
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double getVolume(vector <int> x, vector <int> y)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-x will contain between 3 and 50 elements, inclusive.
-y will contain the same number of elements as x.
-Each element of x and y will be between -100 and 100, inclusive.
-The polygon will be convex.
-All vertices of the polygon will be distinct.
-The polygon will have exactly two vertices on the Y axis. Let's denote them (0, Ymin) and (0, Ymax) with Ymin < Ymax.
-The vertices will be listed in clockwise order, starting with (0, Ymax).
-The y-coordinates of all vertices will be between Ymin and Ymax, inclusive.
-No three points will lie on the same line.


EXAMPLES

0)
{0, 1, 1, 0}
{1, 1, 0, 0}

Returns: 3.141592653589793

The polygon is a square with sides parallel to the coordinate axes.
One of the sides of the square belongs to the Y axis.
The resulting solid of revolution is a right cylinder of height 1 and radius 1.

1)
{0, 1, 0, -1}
{2, 1, 0, 1}

Returns: 2.0943951023931953

This polygon is also a square.
Each of its sides is angled at 45 degrees to the coordinate axes.
The resulting solid of revolution is the union of two cones, each with base radius 1 and height 1.

2)
{0, 3, 0, -2, -2}
{2, 0, -3, -1, 1}

Returns: 49.91641660703782



3)
{0, 3, 3, 0, -1, -1}
{2, 2, -2, -2, -1, 1}

Returns: 113.09733552923255



*/
// END CUT HERE
#line 80 "PolygonRotation.cpp"

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
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
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
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


struct P {
	double x, y;
};
ostream& operator<<(ostream& os, const P& p) {
	os<<"("<<p.x<<" "<<p.y<<")";
	return os;
}

pair<bool, P> intersection(P p1, P p2, P p3, P p4) {
	double d = (p2.x - p1.x)*(p4.y - p3.y) - (p2.y - p1.y)*(p4.x - p3.x);
//	DD(d);
	if (fabs(d) < EPS) {
		// parallel lines
		return make_pair(false, P{0, 0});
	}
	double u = ((p3.x - p1.x)*(p4.y - p3.y) - (p3.y - p1.y)*(p4.x - p3.x))/d;
	double v = ((p3.x - p1.x)*(p2.y - p1.y) - (p3.y - p1.y)*(p2.x - p1.x))/d;
//	DD(u);
//	DD(v);
	if (u < 0.0 || u > 1.0)
		// intersection point not between p1 and p2
		return make_pair(false, P{0, 0});
	if (v < 0.0 || v > 1.0)
		// intersection point not between p3 and p4
		return make_pair(false, P{0, 0});
	return make_pair(true, P{p1.x + u * (p2.x - p1.x), p1.y + u * (p2.y - p1.y)});
}

class PolygonRotation {
	public:
	double getVolume(vector <int> x, vector <int> y) {
		int N = x.size();
		int mid;
		REP(i, N) if(x[i]==0) mid=i;
		vector<P> l, r, all;
		REP(i, N) {
			if(i<=mid) {
				r.PB(P{(double)x[i], (double)y[i]});
			}
			if(i>=mid) {
				l.PB(P{(double)-x[i], (double)y[i]});
			}
		}
		l.PB(P{(double)-x[0], (double)y[0]});
//		reverse(ALL(l));
//		DD(r);
//		DD(l);
		vector<double> ys(ALL(y));
		REP(i, l.size()-1) REP(j, r.size()-1) {
//			DD(i);
//			DD(j);
			auto rv = intersection(l[i], l[i+1], r[j], r[j+1]);
			if(rv.first) {
//				DD(rv.second.y);
				ys.PB(rv.second.y);
			}
		}
		sort(ALL(ys));
//		DD(ys);
		vector<double> xs(ys.size());
		REP(i, ys.size()) {
			// find max x for ys[i]
			double y = ys[i];
			for(auto& e : {l, r}) {
				REP(j, e.size()-1) {
					double ra = (y - e[j].y) / (e[j+1].y-e[j].y);
					if(0 <= ra && ra <= 1) {
						xs[i] = max(xs[i], e[j].x + ra * (e[j+1].x-e[j].x));
					}
				}
			}
		}
//		DD(xs);
		double ans = 0;
		REP(i, ys.size()-1) {
			double h = ys[i+1]-ys[i];
			double r1 = xs[i];
			double r2 = xs[i+1];
			ans += M_PI*h/3.0*(r1*r1+r1*r2+r2*r2);
		}
		return ans;
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
#define END	 verify_case(_, PolygonRotation().getVolume(x, y));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int x_[] = {0, 1, 1, 0};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {1, 1, 0, 0};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	double _ = 3.141592653589793; 
END
CASE(1)
	int x_[] = {0, 1, 0, -1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {2, 1, 0, 1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	double _ = 2.0943951023931953; 
END
CASE(2)
	int x_[] = {0, 3, 0, -2, -2};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {2, 0, -3, -1, 1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	double _ = 49.91641660703782; 
END
CASE(3)
	int x_[] = {0, 3, 3, 0, -1, -1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {2, 2, -2, -2, -1, 1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	double _ = 113.09733552923255; 
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
	double _0 = PolygonRotation().getVolume(x, y);
	double _1 = PolygonRotationRef().getVolume(x, y);
	if(!verify_case(_0, _1, true)) {
print(x);
print(y);
	}
}
#endif

}
// END CUT HERE
