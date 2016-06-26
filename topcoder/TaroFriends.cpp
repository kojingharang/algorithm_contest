// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Cat Taro likes to play with his cat friends.
Each of his friends currently sits on some coordinate on a straight line that goes from the left to the right.
When Taro gives a signal, each of his friends must move exactly X units to the left or to the right.




You are given an vector <int> coordinates and the int X.
For each i, the element coordinates[i] represents the coordinate of the i-th cat before the movement.
Return the smallest possible difference between the positions of the leftmost cat and the rightmost cat after the movement.


DEFINITION
Class:TaroFriends
Method:getNumber
Parameters:vector <int>, int
Returns:int
Method signature:int getNumber(vector <int> coordinates, int X)


CONSTRAINTS
-coordinates will contain between 1 and 50 elements, inclusive.
-Each element of coordinates will be between -100,000,000 and 100,000,000, inclusive.
-X will be between 0 and 100,000,000, inclusive.


EXAMPLES

0)
{-3, 0, 1}
3

Returns: 3

The difference 3 is obtained if the cats move from {-3,0,1} to {0,-3,-2}.




1)
{4, 7, -7}
5

Returns: 4

The difference 4 is obtained if the cats move from {4,7,-7} to {-1,2,-2}.




2)
{-100000000, 100000000}
100000000

Returns: 0



3)
{3, 7, 4, 6, -10, 7, 10, 9, -5}
7

Returns: 7



4)
{-4, 0, 4, 0}
4

Returns: 4



5)
{7}
0

Returns: 0



******************************/
// END CUT HERE
#line 90 "TaroFriends.cpp"
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

class TaroFriends {
	public:
	int getNumber(vector <int> C, int X) {
		ll ans = 1<<30;
		REP(i, C.size()) {
			REP(j, 2) {
				int ok=1;
				ll lans = 0;
				ll left = C[i] + (j?-X:X);
				REP(k, C.size()) {
					if(left <= C[k]-X) lans=max(lans, abs(C[k]-X - left));
					else if(left <= C[k]+X) lans=max(lans, abs(C[k]+X - left));
					else ok=0;
				}
				if(ok) ans=min(ans, lans);
			}
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
#define END	 verify_case(_, TaroFriends().getNumber(coordinates, X));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int coordinates_[] = {-3, 0, 1};
	  vector <int> coordinates(coordinates_, coordinates_+sizeof(coordinates_)/sizeof(*coordinates_)); 
	int X = 3; 
	int _ = 3; 
END
CASE(1)
	int coordinates_[] = {4, 7, -7};
	  vector <int> coordinates(coordinates_, coordinates_+sizeof(coordinates_)/sizeof(*coordinates_)); 
	int X = 5; 
	int _ = 4; 
END
CASE(2)
	int coordinates_[] = {-100000000, 100000000};
	  vector <int> coordinates(coordinates_, coordinates_+sizeof(coordinates_)/sizeof(*coordinates_)); 
	int X = 100000000; 
	int _ = 0; 
END
CASE(3)
	int coordinates_[] = {3, 7, 4, 6, -10, 7, 10, 9, -5};
	  vector <int> coordinates(coordinates_, coordinates_+sizeof(coordinates_)/sizeof(*coordinates_)); 
	int X = 7; 
	int _ = 7; 
END
CASE(4)
	int coordinates_[] = {-4, 0, 4, 0};
	  vector <int> coordinates(coordinates_, coordinates_+sizeof(coordinates_)/sizeof(*coordinates_)); 
	int X = 4; 
	int _ = 4; 
END
CASE(5)
	int coordinates_[] = {7};
	  vector <int> coordinates(coordinates_, coordinates_+sizeof(coordinates_)/sizeof(*coordinates_)); 
	int X = 0; 
	int _ = 0; 
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
	vector <int> coordinates; 
	{
		int N=UNIFORM_LL(1, 51);
		coordinates = vector <int>(N); 
		REP(i, N) {
			coordinates[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int X = UNIFORM_LL(0, 100); 
	int _0 = TaroFriends().getNumber(coordinates, X);
	int _1 = TaroFriendsRef().getNumber(coordinates, X);
	if(!verify_case(_0, _1, true)) {
print(coordinates);
print(X);
	}
}
#endif

}
// END CUT HERE
