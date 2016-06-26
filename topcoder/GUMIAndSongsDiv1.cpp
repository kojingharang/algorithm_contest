// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Gumi loves singing.
She knows N songs.
The songs are numbered 0 through N-1.
She now has some time and she would love to sing as many different songs as possible. 

You are given a vector <int> duration.
For each i, duration[i] is the duration of song i in Gumi's time units. 

Gumi finds it difficult to sing songs with quite different tones consecutively.
You are given a vector <int> tone with the following meaning:
If Gumi wants to sing song y immediately after song x, she will need to spend |tone[x]-tone[y]| units of time resting between the two songs.
(Here, || denotes absolute value.) 

You are also given an int T.
Gumi has T units of time for singing.
She can start singing any song she knows immediately at the beginning of this time interval.
Compute the maximal number of different songs she can sing completely within the given time.


DEFINITION
Class:GUMIAndSongsDiv1
Method:maxSongs
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int maxSongs(vector <int> duration, vector <int> tone, int T)


CONSTRAINTS
-duration and tone will each contain between 1 and 50 elements, inclusive.
-duration and tone will contain the same number of elements.
-Each element of duration will be between 1 and 100,000, inclusive.
-Each element of tone will be between 1 and 100,000, inclusive.
-T will be between 1 and 10,000,000, inclusive.


EXAMPLES

0)
{3, 5, 4, 11}
{2, 1, 3, 1}
17

Returns: 3

There are four songs. 
Two songs have tone 1 and their durations are 5 and 11, respectively.
One song has tone 2 and its duration is 3.
One song has tone 3 and its duration is 4.
Gumi has 17 units of time to sing. 

It is impossible for Gumi to sing all four songs she knows within the given time: even without the breaks the total length of all songs exceeds 17. 

Here is one way how she can sing three songs:
First, she sings song 0 in 3 units of time.
Second, she waits for |2-3|=1 unit of time and then sings song 2 in 4 units of time.
Finally, she waits for |3-1|=2 units of time and then sings song 1 in 5 units of time.
The total time spent is 3+1+4+2+5 = 15 units of time.


1)
{100, 200, 300}
{1, 2, 3}
99

Returns: 0

In this case, T is so small that she can't sing at all.

2)
{1, 2, 3, 4}
{1, 1, 1, 1}
100

Returns: 4

There is plenty of time, so she can sing all of 4 songs.

3)
{9, 11, 13, 17}
{2, 1, 3, 4}
20

Returns: 1



4)
{87,21,20,73,97,57,12,80,86,97,98,85,41,12,89,15,41,17,68,37,21,1,9,65,4,
 67,38,91,46,82,7,98,21,70,99,41,21,65,11,1,8,12,77,62,52,69,56,33,98,97}
{88,27,89,2,96,32,4,93,89,50,58,70,15,48,31,2,27,20,31,3,23,86,69,12,59,
 61,85,67,77,34,29,3,75,42,50,37,56,45,51,68,89,17,4,47,9,14,29,59,43,3}
212

Returns: 12



******************************/
// END CUT HERE
#line 104 "GUMIAndSongsDiv1.cpp"
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
#define PRINT3(table, W, H, D) REP(x, W) { REP(y, H) { REP(d, D) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

class GUMIAndSongsDiv1 {
	public:
	int maxSongs(vector <int> D, vector <int> tone, int T) {
		int N=D.size();
		VVI dp(N, VI(N+1, 1<<30));
		vector<PII> w;
		REP(i, N) w.PB(MP(tone[i], D[i]));
		sort(ALL(w));
		REP(i, N) D[i]=w[i].second, tone[i]=w[i].first;
		REP(i, N) {
			dp[i][0] = 0;
			dp[i][1] = D[i];
			RANGE(n, 2, N+1) {
				REP(j, i) {
					dp[i][n] = min(dp[i][n], dp[j][n-1] + D[i] + abs(tone[i]-tone[j]));
				}
			}
		}
		int ans = 0;
		REP(i, N) REP(n, N+1) if(dp[i][n]<=T) ans = max(ans, n);
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
#define END	 verify_case(_, GUMIAndSongsDiv1().maxSongs(duration, tone, T));}
int main(){

CASE(0)
	int duration_[] = {3, 5, 4, 11};
	  vector <int> duration(duration_, duration_+sizeof(duration_)/sizeof(*duration_)); 
	int tone_[] = {2, 1, 3, 1};
	  vector <int> tone(tone_, tone_+sizeof(tone_)/sizeof(*tone_)); 
	int T = 17; 
	int _ = 3; 
END
//return 0;
CASE(1)
	int duration_[] = {100, 200, 300};
	  vector <int> duration(duration_, duration_+sizeof(duration_)/sizeof(*duration_)); 
	int tone_[] = {1, 2, 3};
	  vector <int> tone(tone_, tone_+sizeof(tone_)/sizeof(*tone_)); 
	int T = 99; 
	int _ = 0; 
END
CASE(2)
	int duration_[] = {1, 2, 3, 4};
	  vector <int> duration(duration_, duration_+sizeof(duration_)/sizeof(*duration_)); 
	int tone_[] = {1, 1, 1, 1};
	  vector <int> tone(tone_, tone_+sizeof(tone_)/sizeof(*tone_)); 
	int T = 100; 
	int _ = 4; 
END
CASE(3)
	int duration_[] = {9, 11, 13, 17};
	  vector <int> duration(duration_, duration_+sizeof(duration_)/sizeof(*duration_)); 
	int tone_[] = {2, 1, 3, 4};
	  vector <int> tone(tone_, tone_+sizeof(tone_)/sizeof(*tone_)); 
	int T = 20; 
	int _ = 1; 
END
CASE(4)
	int duration_[] = {87,21,20,73,97,57,12,80,86,97,98,85,41,12,89,15,41,17,68,37,21,1,9,65,4,
 67,38,91,46,82,7,98,21,70,99,41,21,65,11,1,8,12,77,62,52,69,56,33,98,97};
	  vector <int> duration(duration_, duration_+sizeof(duration_)/sizeof(*duration_)); 
	int tone_[] = {88,27,89,2,96,32,4,93,89,50,58,70,15,48,31,2,27,20,31,3,23,86,69,12,59,
 61,85,67,77,34,29,3,75,42,50,37,56,45,51,68,89,17,4,47,9,14,29,59,43,3};
	  vector <int> tone(tone_, tone_+sizeof(tone_)/sizeof(*tone_)); 
	int T = 212; 
	int _ = 12; 
END

CASE(3)
	int duration_[] = {47942, 29827, 37268, 1294, 98465, 30514, 41870, 90386, 82344, 96694, 72347, 58877, 37685, 27239, 15766, 60489, 77478, 46355, 97306, 94663, 75596, 23726, 67477, 26543, 52692};
	  vector <int> duration(duration_, duration_+sizeof(duration_)/sizeof(*duration_)); 
	int tone_[] = {85331, 35091, 10301, 76792, 85219, 86756, 6848, 44213, 96048, 16636, 11779, 58076, 65164, 63926, 83189, 65909, 7740, 82687, 63280, 20203, 10927, 30791, 59856, 43011, 34801};
	  vector <int> tone(tone_, tone_+sizeof(tone_)/sizeof(*tone_)); 
	int T = 1186252; 
	int _ = 21; 
END

}
// END CUT HERE
