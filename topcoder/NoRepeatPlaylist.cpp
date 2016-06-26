// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Michael loves listening to music from his cell phone while travelling by train. He currently has N songs in his cell phone. During one trip he has the time to listen to P songs. So his cell phone creates a playlist of P (not necessarily different) songs according to the following rules:

Each song has to be played at least once.
At least M songs have to be played between any two occurrences of the same song. (This ensures that the playlist is not playing the same song too often.)

Michael wonders how many different playlists his cell phone can create. You are given the ints N, M, and P. Let X be the number of valid playlists. Since X can be too large, your method must compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:NoRepeatPlaylist
Method:numPlaylists
Parameters:int, int, int
Returns:int
Method signature:int numPlaylists(int N, int M, int P)


NOTES
-Two playlists A and B are different if for some i between 1 and P, inclusive, the i-th song in A is different from the i-th song in B.


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-M will be between 0 and N, inclusive.
-P will be between N and 100, inclusive.


EXAMPLES

0)
1
0
3

Returns: 1

You have only 1 song which can be played as often as you want. 
So the only valid playlist is: {song1, song1, song1}.

1)
1
1
3

Returns: 0

Now is the same scenario as in Example 0, but the song cannot be played 2 times in a row. 
Thus there is no valid playlist.

2)
2
0
3

Returns: 6

Now you have 2 songs and you can play them as often as you want. 
Just remember that playlists {song1, song1, song1} and {song2, song2, song2} are not valid, because each song must be played at least once.

3)
4
0
4

Returns: 24

You have time to play each song exactly once. So there are 4! possible playlists.

4)
2
1
4

Returns: 2

The only two possibilities are {song1, song2, song1, song2} and {song2, song1, song2, song1}.

5)
50
5
100

Returns: 222288991



*/
// END CUT HERE
#line 91 "NoRepeatPlaylist.cpp"

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
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define PII pair<int, int> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T> v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class NoRepeatPlaylist {
	public:
	int numPlaylists(int N, int M, int P) {
		ll mod = 1000000007LL;
		VVI dp(P+1, VI(N+1));
		dp[0][0]=1;
		for(int i=1;i<=P;i++)
		for(int j=1;j<=N;j++) {
			dp[i][j] = (dp[i-1][j-1] * (N-(j-1)) + dp[i-1][j] * max(0, j-M)) % mod;
		}
		return dp[P][N];
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
 { os << "{ ";
   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, NoRepeatPlaylist().numPlaylists(N, M, P));}
int main(){

CASE(0)
	int N = 1; 
	int M = 0; 
	int P = 3; 
	int _ = 1; 
END
CASE(1)
	int N = 1; 
	int M = 1; 
	int P = 3; 
	int _ = 0; 
END
CASE(2)
	int N = 2; 
	int M = 0; 
	int P = 3; 
	int _ = 6; 
END
CASE(3)
	int N = 4; 
	int M = 0; 
	int P = 4; 
	int _ = 24; 
END
CASE(4)
	int N = 2; 
	int M = 1; 
	int P = 4; 
	int _ = 2; 
END
CASE(5)
	int N = 50; 
	int M = 5; 
	int P = 100; 
	int _ = 222288991; 
END

}
// END CUT HERE
