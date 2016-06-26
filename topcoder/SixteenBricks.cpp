// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// You have 16 bricks. Each brick has the shape of a rectangular box. You are given a vector <int> height. For each i, one of your bricks has dimensions 1 x 1 x height[i].

You also have an opaque table. You are going to place your 16 bricks onto the table in a specific way. You are not allowed to rotate the bricks while placing them: the dimension given in height must always be vertical. On the table, there is a 4 x 4 grid of squares. You have to place exactly one of your bricks onto each of the squares.

After you place all the bricks, we will look at the solid formed by them. We are interested in the visible surface area of the solid. Note that the bottom sides of your bricks are not a part of the visible surface, as they stand on the table. Also, adjacent bricks always touch each other and the parts where they touch are not visible.

Different arrangements of bricks may lead to different visible surfaces. Return the largest possible visible surface area.


DEFINITION
Class:SixteenBricks
Method:maximumSurface
Parameters:vector <int>
Returns:int
Method signature:int maximumSurface(vector <int> height)


CONSTRAINTS
-height will contain exactly 16 elements.
-Each element of height will be between 1 and 100, inclusive.


EXAMPLES

0)
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

Returns: 32

All your bricks look the same.
The only solid you can construct is a 1 x 4 x 4 box.
The bottom side of the box is not visible, the other five sides are.
The total visible surface area is 4*4 + 4*(1*4) = 32.

1)
{1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2}

Returns: 64

In order to maximize the visible surface area, you should produce a configuration in which no two bricks with height 2 share a common face.

2)
{77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59}


Returns: 1798



******************************/
// END CUT HERE
#line 56 "SixteenBricks.cpp"
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
 
/*
0123
4567
89AB
CDEF
*/
class SixteenBricks {
  public:
  int ok;
  int f(const vector<int>& lo, const vector<int>& hi) {
    const int o0[] = {5,10,0,2,7,8,13,15};
    const int o1[] = {6,9,1,3,4,11,12,14};
    VI w(16);
    REP(i, 8) w[o0[i]] = lo[i];
    REP(i, 8) w[o1[i]] = hi[i];
	vector<int> LO(lo);
	sort(ALL(LO));
	if(
		((w[0]==LO[6] && w[15]==LO[7]) || (w[0]==LO[7] && w[15]==LO[6])) &&
		((w[5]==LO[0] && w[10]==LO[1]) || (w[5]==LO[1] && w[10]==LO[0]))
	) {
		cout<<"OK "<<w<<endl;
		ok=1;
	}
    
    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
    int ans=0;
    REP(x, 4) REP(y, 4) REP(dir, 4) {
      int nx=x+dx[dir];
      int ny=y+dy[dir];
      if(0<=nx && nx<4 && 0<=ny && ny<4) {
        ans -= min(w[y*4+x], w[ny*4+nx]);
      }
    }
    return ans;
  }
  int maximumSurface(vector <int> H) {
    sort(ALL(H));
    vector<int> lo(8), hi(8);
    REP(i, 8) lo[i]=H[i];
    REP(i, 8) hi[i]=H[i+8];
    cout<<lo<<endl;
    cout<<hi<<endl;
	
    vector<int> best;
    int off = 16 + 4*accumulate(ALL(H), 0);
    int ans=-10000000;
    int loop=0;
    do {
      sort(ALL(hi));
      do {
	  	ok=0;
        int v = f(lo, hi);
		if(ok) {
			cout<<"OK "<<loop<<endl;
		}
        if(v>ans) {
          best = H;
          ans=v;
        }
        if(loop++ > 1000000) {
          break;
        }
      } while(next_permutation(ALL(hi)));
    } while(next_permutation(ALL(lo)));
    cout<<best<<endl;
    return off + ans;
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
#define END	 verify_case(_, SixteenBricks().maximumSurface(height));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int height_[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	  vector <int> height(height_, height_+sizeof(height_)/sizeof(*height_)); 
	int _ = 332; 
END
return 0;
CASE(0)
	int height_[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	  vector <int> height(height_, height_+sizeof(height_)/sizeof(*height_)); 
	int _ = 32; 
END
CASE(1)
	int height_[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};
	  vector <int> height(height_, height_+sizeof(height_)/sizeof(*height_)); 
	int _ = 64; 
END
CASE(2)
	int height_[] = {77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59}
;
	  vector <int> height(height_, height_+sizeof(height_)/sizeof(*height_)); 
	int _ = 1798; 
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
	vector <int> height; 
	{
		int N=16;
		height = vector <int>(N); 
		REP(i, N) {
			height[i] = UNIFORM_LL(1, 101);
		}
	}
	int _0 = SixteenBricks().maximumSurface(height);
	int _1 = SixteenBricksRef().maximumSurface(height);
	if(!verify_case(_0, _1, true)) {
print(height);
	}
}
#endif

}
// END CUT HERE
