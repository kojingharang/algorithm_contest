// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Manao is building a new house. He already purchased a rectangular area where he will place the house. The basement of the house should be built on a level ground, so Manao will have to level the entire area. The area is leveled if the difference between the heights of its lowest and highest square meter is at most 1. Manao wants to measure the effort he needs to put into ground leveling.

You are given a vector <string> area. Each character in area denotes the height at the corresponding square meter of Manao's area. Using 1 unit of effort, Manao can change the height of any square meter on his area by 1 up or down. Return the minimum total effort he needs to put to obtain a leveled area.


DEFINITION
Class:HouseBuilding
Method:getMinimum
Parameters:vector <string>
Returns:int
Method signature:int getMinimum(vector <string> area)


CONSTRAINTS
-area will contain between 1 and 50 elements, inclusive.
-Each element of area will be between 1 and 50 characters long, inclusive.
-All elements of area will be of the same length.
-Each element of area will contain digits ('0'-'9') only.


EXAMPLES

0)
{"10",
 "31"}

Returns: 2

The given area is not leveled, because the minimum height is 0 and the maximum height is 3. Manao needs to reduce the height of lower left square by 2.

1)
{"54454",
 "61551"}

Returns: 7

In the optimal solution each square will have height either 4 or 5. To reach such a configuration, Manao should reduce the height of one square from 6 to 5, and increase the heights of two other squares from 1 to 4.

2)
{"989"}

Returns: 0

The area is already leveled.

3)
{"90"}

Returns: 8



4)
{"5781252",
 "2471255",
 "0000291",
 "1212489"}

Returns: 53



*/
// END CUT HERE
#line 69 "HouseBuilding.cpp"

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



class HouseBuilding {
	public:
	int getMinimum(vector <string> AR) {
		int ans = 1<<30;
		RANGE(lvl, -1, 11) {
			int cost = 0;
			REP(i, AR.size()) REP(j, AR[i].size()) {
				int c0 = abs(lvl-(AR[i][j]-'0'));
				int c1 = abs(lvl+1-(AR[i][j]-'0'));
				int c = min(c0, c1);
				if(c>0) cost+=c;
			}
			//cout<<lvl<<" "<<cost<<endl;
			ans = min(ans, cost);
		}
		return ans;
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
#define END	 verify_case(_, HouseBuilding().getMinimum(area));}
int main(){

CASE(0)
	string area_[] = {"10",
 "31"};
	  vector <string> area(area_, area_+sizeof(area_)/sizeof(*area_)); 
	int _ = 2; 
END
CASE(1)
	string area_[] = {"54454",
 "61551"};
	  vector <string> area(area_, area_+sizeof(area_)/sizeof(*area_)); 
	int _ = 7; 
END
CASE(2)
	string area_[] = {"989"};
	  vector <string> area(area_, area_+sizeof(area_)/sizeof(*area_)); 
	int _ = 0; 
END
CASE(3)
	string area_[] = {"90"};
	  vector <string> area(area_, area_+sizeof(area_)/sizeof(*area_)); 
	int _ = 8; 
END
CASE(4)
	string area_[] = {"5781252",
 "2471255",
 "0000291",
 "1212489"};
	  vector <string> area(area_, area_+sizeof(area_)/sizeof(*area_)); 
	int _ = 53; 
END

}
// END CUT HERE
