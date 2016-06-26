// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Note that the return value is a floating-point number and that in this problem the allowed absolute or relative error has been increased to 1e-6.

This problem takes place in a plane.
Nikola works at a radio station that is located in the point (0, 0).
You can hear the station if and only if you are within a circle with center at (0, 0) and some unknown radius.

There are some cities near the station.
Each city has the shape of a circle with some positive integer radius.
Cities may partially or even completely overlap each other, and some of them may contain the radio station.
You are given the description of all cities as vector <int>s X, Y, and R.
For each valid i, there is a city with center at (X[i], Y[i]) and radius R[i].

The radius of our radio station is bad if there is a city that is only partially covered by the radio signal.
Otherwise, the radius is good.
In other words, if there is a point in a city where you can listen to our radio and another point in the same city where you cannot do so, the radius is bad.
A radius is good if and only if each city is either covered completely by radio signal, or not covered at all.

You are given a int Z.
The radius of our radio station is a real number chosen uniformly at random from the range [0, Z].
Return the probability that the radius is good.

DEFINITION
Class:RadioRange
Method:RadiusProbability
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:double
Method signature:double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z)


NOTES
-Your return value must have an absolute or relative error less than 1e-6.


CONSTRAINTS
-X will contain between 1 and 100 elements, inclusive.
-X, Y, and R will each contain the same number of elements.
-Each element of X will be between -10^9 and 10^9, inclusive.
-Each element of Y will be between -10^9 and 10^9, inclusive.
-Each element of R will be between 1 and 10^9, inclusive.
-Z will be between 1 and 10^9, inclusive.


EXAMPLES

0)
{0}
{0}
{5}
10

Returns: 0.5

Our radio station is in the center of a city with radius 5, and we are choosing the radius for the station uniformly at random from [0,10].
Radii in [0,5) are all bad, because people in the center of the city can hear our radio but people on its boundary cannot.
Radii in [5,10] are all good, as the entire city is covered.
Hence, the probability of having a good radius is 5/10 = 0.5.

1)
{0}
{0}
{10}
10

Returns: 0.0

Our radio station is in the center of a city with radius 10, and we are choosing the radius for the station uniformly at random from [0,10].
In this case, the only good radius is 10, but the probability that it will be chosen is zero.

2)
{10}
{10}
{10}
10

Returns: 0.4142135623730951

The center of the city is at (10, 10) and its radius is 10.
The good radii for our station are those where the city is not covered at all.
These are the radii from 0 to approximately 4.14.

3)
{11, -11, 0, 0}
{0, 0, 11, -11}
{10, 10, 10, 10}
31

Returns: 0.3548387096774194

Here we have four cities.
They are located to the north, south, east, and west of the station.
A radius is good if it lies in [0,1) or in [21,31].

4)
{100}
{100}
{1}
10

Returns: 1.0

It is possible that some cities will not be covered even if the radius of our radio station is Z.

5)
{1000000000}
{1000000000}
{1000000000}
1000000000

Returns: 0.41421356237309503



6)
{20, -20, 0, 0}
{0, 0, 20, -20}
{50, 50, 50, 50}
100

Returns: 0.3



7)
{0, -60, -62, -60, 63, -97}
{-72, 67, 61, -8, -32, 89}
{6, 7, 8, 7, 5, 6}
918

Returns: 0.9407071068962471



******************************/
// END CUT HERE
#line 139 "RadioRange.cpp"
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
#define PDD pair<double, double> 
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

bool dup(double a, double b, double c, double d, double& e, double& f) {
	bool du = !(b<c || d<a);
	if(du) {
		e = min(a, c);
		f = max(b, d);
	}
	return du;
}

class RadioRange {
	public:
	double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z) {
		int N=X.size();
		vector<PDD> w, nw;
		REP(i, N) {
			double r = sqrt((double)X[i]*X[i]+(double)Y[i]*Y[i]);
			w.PB(MP(max(0.0, r-R[i]), r+R[i]));
		}
		PDD p = MP(0, 0);
		while(true) {
			bool changed=false;
			N=w.size();
			REP(i, N) RANGE(j, i+1, N) if(dup(w[i].first, w[i].second, w[j].first, w[j].second, p.first, p.second)) {
				changed=true;
				REP(k, N) if(k!=i && k!=j) nw.PB(w[k]);
				nw.PB(p);
				goto FOO;
			}
			FOO:
			if(!changed) break;
			w=nw;
			nw.clear();
		}
		sort(ALL(w));
//		cout<<w<<endl;
		N=w.size();
		double no=0;
		REP(i, N) {
			if(Z < w[i].first) break;
			no += min((double)Z, w[i].second) - w[i].first;
		}
		return 1.0-(no/Z);
	}
};

class RadioRangeRef {
	public:
	double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z) {
		int N=X.size();
		vector<PDD> w, nw;
		REP(i, N) {
			double r = sqrt((double)X[i]*X[i]+(double)Y[i]*Y[i]);
			w.PB(MP(max(0.0, r-R[i]), r+R[i]));
		}
		PDD p = MP(0, 0);
		while(true) {
			bool changed=false;
			N=w.size();
			REP(i, N) RANGE(j, i+1, N) if(dup(w[i].first, w[i].second, w[j].first, w[j].second, p.first, p.second)) {
				changed=true;
				REP(k, N) if(k!=i && k!=j) nw.PB(w[k]);
				nw.PB(p);
				goto FOO;
			}
			FOO:
			if(!changed) break;
			w=nw;
			nw.clear();
		}
		sort(ALL(w));
//		cout<<w<<endl;
		N=w.size();
		double no=0;
		REP(i, N) {
			if(Z < w[i].first) break;
			no += min((double)Z, w[i].second) - w[i].first;
		}
		return 1.0-(no/Z);
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
#define END	 verify_case(_, RadioRange().RadiusProbability(X, Y, R, Z));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int X_[] = {0};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int R_[] = {5};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int Z = 10; 
	double _ = 0.5; 
END
CASE(1)
	int X_[] = {0};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int R_[] = {10};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int Z = 10; 
	double _ = 0.0; 
END
CASE(2)
	int X_[] = {10};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {10};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int R_[] = {10};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int Z = 10; 
	double _ = 0.4142135623730951; 
END
CASE(3)
	int X_[] = {11, -11, 0, 0};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0, 0, 11, -11};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int R_[] = {10, 10, 10, 10};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int Z = 31; 
	double _ = 0.3548387096774194; 
END
CASE(4)
	int X_[] = {100};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {100};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int R_[] = {1};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int Z = 10; 
	double _ = 1.0; 
END
CASE(5)
	int X_[] = {1000000000};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {1000000000};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int R_[] = {1000000000};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int Z = 1000000000; 
	double _ = 0.41421356237309503; 
END
CASE(6)
	int X_[] = {20, -20, 0, 0};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0, 0, 20, -20};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int R_[] = {50, 50, 50, 50};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int Z = 100; 
	double _ = 0.3; 
END
CASE(7)
	int X_[] = {0, -60, -62, -60, 63, -97};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {-72, 67, 61, -8, -32, 89};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int R_[] = {6, 7, 8, 7, 5, 6};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int Z = 918; 
	double _ = 0.9407071068962471; 
END
#if 01  // DO RANDOM TESTS

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
	vector <int> X; 
	{
		int N=UNIFORM_LL(1, 51);
		X = vector <int>(N); 
		REP(i, N) {
			X[i] = UNIFORM_LL(-1000000000, 1000000000);
		}
	}
// param type: int
	vector <int> Y; 
	{
		int N=UNIFORM_LL(1, 51);
		Y = vector <int>(N); 
		REP(i, N) {
			Y[i] = UNIFORM_LL(-1000000000, 1000000000);
		}
	}
// param type: int
	vector <int> R; 
	{
		int N=UNIFORM_LL(1, 51);
		R = vector <int>(N); 
		REP(i, N) {
			R[i] = UNIFORM_LL(1, 1000000000);
		}
	}
// param type: int
	int Z = UNIFORM_LL(1, 1000000000); 
	double _0 = RadioRange().RadiusProbability(X, Y, R, Z);
	double _1 = RadioRangeRef().RadiusProbability(X, Y, R, Z);
	if(!verify_case(_0, _1, true)) {
print(X);
print(Y);
print(R);
print(Z);
	}
}
#endif

}
// END CUT HERE
