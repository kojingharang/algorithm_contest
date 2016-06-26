// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Shopping is by no means an easy task. Yes, sure, if you want to buy shoes or some clothes that's no problem at all. But what happens if you would like an extremely rare poison, found only in the mists of Amazonia? Now you see, Elly's life is not as easy as you would think. She has almost reached her final destination, but unfortunately she can only use boats and travel by foot for the final part.

There are N+1 really long, but narrow parallel islands, going from South to North, numbered from 0 to N, inclusive. There are also N rivers between the islands, numbered from 0 to N-1, inclusive. River i is width[i] kilometers wide and flows between islands i and i+1. The speed of the current in each river is negligible. For river i, the maximum speed at which Elly can sail is speed[i] kilometers per hour, regardless of the direction in which she sails.

All islands are length kilometers long. Starting from the southmost point, each one has boat docks one kilometer apart throughout its entire coastline. Thus, there are length + 1 docks on each island (at kilometer 0, 1, …, length). The islands are so narrow, that you can assume the same dock serves the boats on both sides of the island, and that walking horizontally from one side of the island to the other takes no time.

For simplicity we can represent the islands as parallel vertical line segments, and the docks as points on the plane. Island 0 goes from point (0, 0) to (0, length), island 1 from (width[0], 0) to (width[0], length), island 2 from (width[0] + width[1], 0) to (width[0] + width[1], length), and so on, where width[i] gives the width of the i-th river. The docks on island 0 are with coordinates (0, 0), (0, 1), … (0, length); the ones on island 1 are with coordinates (width[0], 0), (width[0], 1), …, (width[0], length); these on island 2 are with coordinates (width[0] + width[1], 0), (width[0] + width[1], 1), …, (width[0] + width[1], length) and so on.

Elly can only take boats from dock to dock (i.e. she can neither depart from nor arrive at non-integer coordinates). She can also walk (vertically) along any island with a constant speed of walk kilometers per hour. The girl is currently on the southmost point of the westmost island and wants to reach the northmost point of the eastmost island. Elly wonders what is the minimal time required to travel to her destination. Help her by writing a method that calculates this for her.

You are given the length of the islands in the int length and the walking speed in the int walk. The widths of the rivers will be given in the vector <int> width and the maximal sailing speeds in the vector <int> speed. Return a double giving the shortest time in which she can reach her destination.

DEFINITION
Class:EllysRivers
Method:getMin
Parameters:int, int, vector <int>, vector <int>
Returns:double
Method signature:double getMin(int length, int walk, vector <int> width, vector <int> speed)


NOTES
-Your return value must have a relative or an absolute error of less than 1e-9.


CONSTRAINTS
-length will be between 1 and 100,000, inclusive.
-walk will be between 1 and 1,000,000, inclusive.
-width will contain between 1 and 50 elements, inclusive.
-speed will contain between 1 and 50 elements, inclusive.
-width and speed will contain the same number of elements.
-Each element of width will be between 1 and 1,000,000, inclusive.
-Each element of speed will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
10
3
{5, 2, 3}
{5, 2, 7}

Returns: 3.231651964071508

Elly will not walk on any of the islands. She will sail four kilometers to the north in the first river,
reaching the second island at point (5, 4). Then she sails another one kilometer to the north in the second river,
going to (7, 5) on the third island. In the end she will sail to her destination at (10, 10).
The required times for her journey are as follows:

(0, 0) -> (5, 4) = 6.403124237433 / 5 = 1.280624847487 hours
(5, 4) -> (7, 5) = 2.236067977499 / 2 = 1.118033988749 hours
(7, 5) -> (10, 10) = 5.830951894845 / 7 = 0.832993127835 hours



1)
10000
211
{911}
{207}

Returns: 48.24623664712219

Don't forget that Elly can walk on the islands.

2)
1337
2
{100, 200, 300, 400}
{11, 12, 13, 14}

Returns: 128.57830549575695



3)
77
119
{11, 12, 13, 14}
{100, 200, 300, 400}

Returns: 0.3842077071089629



4)
7134
1525
{11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393}
{1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057}

Returns: 214.6509731258811

A large random example.

*/
// END CUT HERE
#line 102 "EllysRivers.cpp"

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
#define VI vector<double>
#define PII pair<ll, ll> 
#define VVI vector<vector<double> >
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


#define INF (1<<30)

class EllysRivers {
	public:
	double getMin(int le, int walk, vector <int> wi, vector <int> sp) {
		int N=wi.size();
		VVI dp(N+1, VI(le+1, INF));
		dp[N][le]=0;
		for(int x=N;x>=0;x--) {
			for(int y=le;y>=0;y--) {
				//cout<<x<<" "<<y<<endl;
				if(y<le) dp[x][y] = min(dp[x][y], dp[x][le]+(double)(le-y)/walk);
				//cout<<x<<" "<<y<<endl;
				if(x<N) {
					double Ly = le-y;
					double Lx = wi[x];
					double L = sqrt(Lx*Lx+Ly*Ly);
					dp[x][y] = min(dp[x][y], dp[N][le]+L/sp[x]);
				}
			}
		}
		cout<<dp<<endl;
		return dp[0][0];
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
#define END	 verify_case(_, EllysRivers().getMin(length, walk, width, speed));}
int main(){

CASE(0)
	int length = 10; 
	int walk = 3; 
	int width_[] = {5, 2, 3};
	  vector <int> width(width_, width_+sizeof(width_)/sizeof(*width_)); 
	int speed_[] = {5, 2, 7};
	  vector <int> speed(speed_, speed_+sizeof(speed_)/sizeof(*speed_)); 
	double _ = 3.231651964071508; 
END
return 0;
CASE(1)
	int length = 10000; 
	int walk = 211; 
	int width_[] = {911};
	  vector <int> width(width_, width_+sizeof(width_)/sizeof(*width_)); 
	int speed_[] = {207};
	  vector <int> speed(speed_, speed_+sizeof(speed_)/sizeof(*speed_)); 
	double _ = 48.24623664712219; 
END
CASE(2)
	int length = 1337; 
	int walk = 2; 
	int width_[] = {100, 200, 300, 400};
	  vector <int> width(width_, width_+sizeof(width_)/sizeof(*width_)); 
	int speed_[] = {11, 12, 13, 14};
	  vector <int> speed(speed_, speed_+sizeof(speed_)/sizeof(*speed_)); 
	double _ = 128.57830549575695; 
END
CASE(3)
	int length = 77; 
	int walk = 119; 
	int width_[] = {11, 12, 13, 14};
	  vector <int> width(width_, width_+sizeof(width_)/sizeof(*width_)); 
	int speed_[] = {100, 200, 300, 400};
	  vector <int> speed(speed_, speed_+sizeof(speed_)/sizeof(*speed_)); 
	double _ = 0.3842077071089629; 
END
CASE(4)
	int length = 7134; 
	int walk = 1525; 
	int width_[] = {11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393};
	  vector <int> width(width_, width_+sizeof(width_)/sizeof(*width_)); 
	int speed_[] = {1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057};
	  vector <int> speed(speed_, speed_+sizeof(speed_)/sizeof(*speed_)); 
	double _ = 214.6509731258811; 
END

}
// END CUT HERE
