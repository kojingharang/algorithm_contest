// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// In the Republic of Nlogonia there are N cities.
For convenience, the cities are numbered 0 through N-1.
For each two different cities i and j, there is a direct one-way road from i to j.
You are given the lengths of those roads as a vector <string> dist with N elements, each with N characters.
For each i and j, the character dist[i][j] represents the length of the road from i to j.

The lengths of roads are integers between 1 and 9, inclusive, and they are represented by digits '1' through '9'.
That is, for distinct i and j, dist[i][j] will be between '1' and '9'.
For each i, dist[i][i] will be '0'.
Note that the roads from i to j and from j to i may have different lengths.

Every year on Algorithms Day (the most important holiday in Nlogonia) people travel between the cities.
More precisely, for each pair of distinct cities i and j, one full bus of people travels from i to j.
Each of those buses drives along a shortest path from its origin to its destination.
If there are multiple shortest paths, the bus driver picks one of them arbitrarily.

The roads in Nlogonia are currently limited.
You are given an int T with the following meaning: 
each of the current roads is only safe if it is guaranteed that there will be strictly fewer than T buses driving along the road.
In other words, a road is unsafe if it is possible that T or more buses will use it.
The government wants to rebuild all unsafe roads before the next Algorithms Day.
Return the sum of lengths of all unsafe roads.

DEFINITION
Class:BuildingRoutes
Method:build
Parameters:vector <string>, int
Returns:int
Method signature:int build(vector <string> dist, int T)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-dist will contain exactly N elements.
-Each element of dist will contain exactly N characters.
-For each i, dist[i][i] will be '0'.
-For each pair of distinct i and j, dist[i][j] will be between '1' and '9', inclusive.
-T will be between 1 and 2500, inclusive.


EXAMPLES

0)
{"011",
 "101",
 "110"}
1

Returns: 6

As T=1, a road is unsafe as soon as it is possible that a bus will use it. 
Each of the six roads in this test case belongs to some shortest path, hence each of them is unsafe

1)
{"033",
 "309",
 "390"}
1

Returns: 12

The roads 1->2 and 2->1 (the two roads of length 9) will not be used by any bus.
Only the four remaining roads are unsafe in this case.

2)
{"0123",
 "1023",
 "1203",
 "1230"}
2

Returns: 5



3)
{"05789654",
 "10347583",
 "65085479",
 "55602398",
 "76590934",
 "57939045",
 "12345608",
 "68647640"}
3

Returns: 40



*/
// END CUT HERE
#line 97 "BuildingRoutes.cpp"

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
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class BuildingRoutes {
	public:
	int build(vector <string> D, int T) {
		int N=D.size();
		VVI d(N, VI(N));
		VVI w(N, VI(N));
		REP(i, N)REP(j,N)d[i][j]=w[i][j]=D[i][j]-'0';
		REP(k,N)REP(i, N)REP(j,N) w[i][j]=min(w[i][j], w[i][k]+w[k][j]);
		ll ans = 0;
		REP(i, N)REP(j,N){
			ll v=0;
			REP(ii, N)REP(jj,N) if(w[ii][i]+d[i][j]+w[j][jj]==w[ii][jj]) v++;
			if(v>=T) ans+=d[i][j];
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, BuildingRoutes().build(dist, T));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string dist_[] = {"011",
 "101",
 "110"};
	  vector <string> dist(dist_, dist_+sizeof(dist_)/sizeof(*dist_)); 
	int T = 1; 
	int _ = 6; 
END
CASE(1)
	string dist_[] = {"033",
 "309",
 "390"};
	  vector <string> dist(dist_, dist_+sizeof(dist_)/sizeof(*dist_)); 
	int T = 1; 
	int _ = 12; 
END
CASE(2)
	string dist_[] = {"0123",
 "1023",
 "1203",
 "1230"};
	  vector <string> dist(dist_, dist_+sizeof(dist_)/sizeof(*dist_)); 
	int T = 2; 
	int _ = 5; 
END
CASE(3)
	string dist_[] = {"05789654",
 "10347583",
 "65085479",
 "55602398",
 "76590934",
 "57939045",
 "12345608",
 "68647640"};
	  vector <string> dist(dist_, dist_+sizeof(dist_)/sizeof(*dist_)); 
	int T = 3; 
	int _ = 40; 
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
for(int loop=0;loop<1;loop++) {
// param type: String
	vector <string> dist; 
	{
		int N=UNIFORM_LL(1, 50);
		dist = vector <string>(N, string('0', N)); 
		REP(i, N)REP(j, N) {
			if(i!=j) dist[i][j] = '0'+UNIFORM_LL(1, 10);
		}
	}
	cout<<dist<<endl;
// param type: int
	int T = UNIFORM_LL(0, 2501); 
	int _0 = BuildingRoutes().build(dist, T);
	int _1 = BuildingRoutesRef().build(dist, T);
	if(!verify_case(_0, _1, true)) {
print(dist);
print(T);
	}
}
#endif

}
// END CUT HERE
