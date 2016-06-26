// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// The pony Rainbow Dash wants to choose her pet.
There are N animals who want to be her pet.
Rainbow Dash numbered them 0 through N-1.

To help her make the decision, Rainbow Dash decided to organize a relay race for the animals.
The race track is already known, and for each animal we know how fast it is.
More precisely, you are given vector <int>s A and B with the following meaning:
For each i, the animal number i will take between A[i] and B[i] seconds (inclusive) to complete the track.

For the race the animals will be divided into two competing teams.
This is a relay race, so the team members of each team will all run the same track, one after another --
when the first team member finishes, the second one may start, and so on.
Thus the total time in which a team completes the race is the sum of the times of all team members.
Note that we can use the estimates given by A and B to estimate the total time for any team of animals.

Given two teams S and T, the value maxdiff(S,T) is defined as the largest possible difference in seconds
between the time in which team S finishes the course and the time in which team T finishes the course.

Rainbow Dash now needs to assign each of the animals to one of the two competing teams.
She wants to see a close competition, so she wants the teams to finish as close to each other as possible.
Formally, she wants to divide all animals into teams S and T in a way that minimizes maxdiff(S,T).
Return the smallest possible value of maxdiff(S,T).

DEFINITION
Class:MayTheBestPetWin
Method:calc
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int calc(vector <int> A, vector <int> B)


NOTES
-The teams are not required to contain the same number of animals.


CONSTRAINTS
-A will contain between 2 and 50 elements, inclusive.
-A and B will contain the same number of elements.
-Each element of A will be between 1 and 10,000, inclusive.
-Each element of B will be between 1 and 10,000, inclusive.
-For each i, B[i] will be greater than or equal to A[i].


EXAMPLES

0)
{3,4,4,7}
{3,4,4,7}

Returns: 2

In this test case we know the exact time in which each of the animals completes the track.
An optimal solution is to choose teams S={0,3} and T={1,2}.
Then team S will certainly complete the track in 3+7 = 10 seconds, and team T in 4+4 = 8 seconds.
Thus, maxdiff(S,T)=2.

1)
{1,3,5,4,5}
{2,5,6,8,7}

Returns: 5

Here one of the optimal solutions is S={2,3} and T={0,1,4}.
For these two teams we have maxdiff(S,T)=5.
For example, it is possible that S will complete the track in 6+8 = 14 seconds, and T will complete it in 1+3+5 = 9 seconds.
It is also possible that S will complete the track up to 5 seconds before T does.

2)
{2907,949,1674,6092,8608,5186,2630,970,1050,2415,1923,2697,5571,6941,8065,4710,716,756,5185,1341,993,5092,248,1895,4223,1783,3844,3531,2431,1755,2837,4015}
{7296,6954,4407,9724,8645,8065,9323,8433,1352,9618,6487,7309,9297,8999,9960,5653,4721,7623,6017,7320,3513,6642,6359,3145,7233,5077,6457,3605,2911,4679,5381,6574}

Returns: 52873



*/
// END CUT HERE
#line 82 "MayTheBestPetWin.cpp"

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
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class MayTheBestPetWin {
	public:
	int calc(vector <int> A, vector <int> B) {
		int N = A.size();
		VI SUM(N);
		REP(i, N) SUM[i]=A[i]+B[i];
		int sumA = accumulate(ALL(A), 0);
		int sumB = accumulate(ALL(B), 0);
		// |S slow - T fast| = |A[s] - B[t]| = |(SumA - A[t]) - B[t]| = |SumA - Sum[t]|
		// |S fast - T slow| = |B[s] - A[t]| = |(SumB - B[t]) - A[t]| = |SumB - Sum[t]|
		int maxK = 10000 * N * 2 + 500;
		VVI dp(2, VI(maxK));
		int men=0;
		dp[men][0] = 1;
		REP(i, N) {
			REP(k, maxK) {
				if(dp[men][k]==0) continue;
				dp[1-men][k] = 1;
				dp[1-men][k + SUM[i]] = 1;
				assert(k + SUM[i] < maxK);
			}
			men ^= 1;
		}
		int ans = 1<<30;
		REP(k, maxK) {
			if(dp[men][k]) ans = min(ans, max(abs(sumA-k), abs(sumB-k)));
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
#define END	 verify_case(_, MayTheBestPetWin().calc(A, B));}
int main(){

CASE(0)
	int A_[] = {3,4,4,7};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {3,4,4,7};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int _ = 2; 
END
CASE(1)
	int A_[] = {1,3,5,4,5};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,5,6,8,7};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int _ = 5; 
END
CASE(2)
	int A_[] = {2907,949,1674,6092,8608,5186,2630,970,1050,2415,1923,2697,5571,6941,8065,4710,716,756,5185,1341,993,5092,248,1895,4223,1783,3844,3531,2431,1755,2837,4015};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {7296,6954,4407,9724,8645,8065,9323,8433,1352,9618,6487,7309,9297,8999,9960,5653,4721,7623,6017,7320,3513,6642,6359,3145,7233,5077,6457,3605,2911,4679,5381,6574};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int _ = 52873; 
END

}
// END CUT HERE
