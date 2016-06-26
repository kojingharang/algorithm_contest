// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There are N boxes numbered from 0 to N-1, inclusive. For each i, box i contains red[i] red balls, green[i] green balls, and blue[i] blue balls.


Fox Ciel wants to separate the balls by colors. In each operation, she can pick a single ball from some box and put it into another box. She considers the balls to be separated if no box contains balls of more than one color.


Return the minimal number of operations required to separate the balls. If this is impossible, return -1.


DEFINITION
Class:BallsSeparating
Method:minOperations
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int minOperations(vector <int> red, vector <int> green, vector <int> blue)


CONSTRAINTS
-red, green and blue will each contain between 1 and 50 elements, inclusive.
-red, green and blue will contain the same number of elements.
-Each element of red, green and blue will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{1, 1, 1}
{1, 1, 1}
{1, 1, 1}

Returns: 6

One way to separate the balls in six operations is as follows:

Move a red ball from box 1 to box 0.
Move a red ball from box 2 to box 0.
Move a green ball from box 0 to box 1.
Move a green ball from box 2 to box 1.
Move a blue ball from box 0 to box 2.
Move a blue ball from box 1 to box 2.

The pictures on the left and on the right show the initial and the final states of the balls, respectively.



?


1)
{5}
{6}
{8}

Returns: -1

It is impossible to separate the balls.

2)
{4, 6, 5, 7}
{7, 4, 6, 3}
{6, 5, 3, 8}

Returns: 37



3)
{7, 12, 9, 9, 7}
{7, 10, 8, 8, 9}
{8, 9, 5, 6, 13}

Returns: 77



4)
{842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799}
{268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141}
{662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103}

Returns: 7230607



*/
// END CUT HERE
#line 91 "BallsSeparating.cpp"

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


#define INF 1<<30

class BallsSeparating {
	public:
	int minOperations(vector <int> R, vector <int> G, vector <int> B) {
		int N=R.size();
		VVI dp(N+1, VI(8, INF));
		dp[0][0]=0;
		
		RANGE(i, 1, N+1) {
			REP(cur, 8) {
				REP(prev, 8) {
					int costs[3];
					int all = R[i-1]+G[i-1]+B[i-1];
					costs[0] = all - R[i-1];
					costs[1] = all - G[i-1];
					costs[2] = all - B[i-1];
					REP(c, 3) {
						if((prev|(1<<c))==cur) {
							dp[i][cur] = min(dp[i][cur], dp[i-1][prev] + costs[c]);
						}
					}
				}
			}
			//cout<<i<<"::: "<<dp<<endl;
		}
		return dp[N][7]==INF ? -1 : dp[N][7];
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
#define END	 verify_case(_, BallsSeparating().minOperations(red, green, blue));}
int main(){

CASE(0)
	int red_[] = {1, 1, 1};
	  vector <int> red(red_, red_+sizeof(red_)/sizeof(*red_)); 
	int green_[] = {1, 1, 1};
	  vector <int> green(green_, green_+sizeof(green_)/sizeof(*green_)); 
	int blue_[] = {1, 1, 1};
	  vector <int> blue(blue_, blue_+sizeof(blue_)/sizeof(*blue_)); 
	int _ = 6; 
END
//return 0;
CASE(1)
	int red_[] = {5};
	  vector <int> red(red_, red_+sizeof(red_)/sizeof(*red_)); 
	int green_[] = {6};
	  vector <int> green(green_, green_+sizeof(green_)/sizeof(*green_)); 
	int blue_[] = {8};
	  vector <int> blue(blue_, blue_+sizeof(blue_)/sizeof(*blue_)); 
	int _ = -1; 
END
CASE(2)
	int red_[] = {4, 6, 5, 7};
	  vector <int> red(red_, red_+sizeof(red_)/sizeof(*red_)); 
	int green_[] = {7, 4, 6, 3};
	  vector <int> green(green_, green_+sizeof(green_)/sizeof(*green_)); 
	int blue_[] = {6, 5, 3, 8};
	  vector <int> blue(blue_, blue_+sizeof(blue_)/sizeof(*blue_)); 
	int _ = 37; 
END
CASE(3)
	int red_[] = {7, 12, 9, 9, 7};
	  vector <int> red(red_, red_+sizeof(red_)/sizeof(*red_)); 
	int green_[] = {7, 10, 8, 8, 9};
	  vector <int> green(green_, green_+sizeof(green_)/sizeof(*green_)); 
	int blue_[] = {8, 9, 5, 6, 13};
	  vector <int> blue(blue_, blue_+sizeof(blue_)/sizeof(*blue_)); 
	int _ = 77; 
END
CASE(4)
	int red_[] = {842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799};
	  vector <int> red(red_, red_+sizeof(red_)/sizeof(*red_)); 
	int green_[] = {268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141};
	  vector <int> green(green_, green_+sizeof(green_)/sizeof(*green_)); 
	int blue_[] = {662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103};
	  vector <int> blue(blue_, blue_+sizeof(blue_)/sizeof(*blue_)); 
	int _ = 7230607; 
END

}
// END CUT HERE
