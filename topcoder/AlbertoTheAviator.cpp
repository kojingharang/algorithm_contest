// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Alberto is an aviation pioneer.
He pilots an airplane called "14-bis".
Initially, there are F units of fuel in the fuel tank of his airplane.

There are some flight missions Alberto may take.
The missions all start and end in the same location, and he may do them in any order.
However, he can only do each mission at most once.
You are given two vector <int>s of the same length: duration and refuel.
For each valid i:

duration[i] is the amount of fuel consumed while running mission i
After Alberto completes mission i and gets paid, he will buy refuel[i] units of fuel. This amount will always be strictly smaller than the amount consumed during the mission.


Alberto can only choose a mission if he has enough fuel for it.
That is, at the beginning of the mission his fuel tank must have at least duration[i] units of fuel.

Compute and return the maximum number of missions Alberto can take.

DEFINITION
Class:AlbertoTheAviator
Method:MaximumFlights
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int MaximumFlights(int F, vector <int> duration, vector <int> refuel)


CONSTRAINTS
-F will be between 1 and 5,000 inclusive.
-duration and refuel will have between 1 and 50 elements, inclusive.
-Each element of duration will be between 1 and 5,000, inclusive.
-Each element of refuel will be between 0 and 5,000, inclusive.
-For each i, refuel[i] will be strictly smaller than duration[i].
-duration and refuel will contain the same number of elements.


EXAMPLES

0)
10
{10}
{0}

Returns: 1

There is only one mission. Alberto has enough fuel to take it, so the optimal solution is to take it.

1)
10
{8, 4}
{0, 2}

Returns: 2



2)
12
{4, 8, 2, 1}
{2, 0, 0, 0}

Returns: 3



3)
9
{4, 6}
{0, 1}

Returns: 2



4)
100
{101}
{100}

Returns: 0

There is only one mission. Alberto does not have enough fuel to take it. The answer is 0.

5)
1947
{2407, 2979, 1269, 2401, 3227, 2230, 3991, 2133, 3338, 356, 2535, 3859, 3267, 365}
{2406, 793, 905, 2400, 1789, 2229, 1378, 2132, 1815, 355, 72, 3858, 3266, 364}

Returns: 3



*/
// END CUT HERE
#line 99 "AlbertoTheAviator.cpp"

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


int dp[51][5010]; // [rest][E] ... i in [0, E) まで使って rest になったときの最大値
class AlbertoTheAviator {
	public:
	int MaximumFlights(int F, vector <int> D, vector <int> R) {
        int N=D.size();
        vector<PII> w(N);
		REP(i, N) w[i] = MP(R[i], D[i]);
        sort(ALLR(w));
        CLEAR(dp, -1);
        dp[0][F] = 0;
        REP(i, N) for(int p=5000;p>=0;p--) {
            if(dp[i][p]==-1) continue;
            dp[i+1][p] = max(dp[i+1][p], dp[i][p]);
            
            if(w[i].second <= p) {
                int np = p - w[i].second + w[i].first;
                dp[i+1][np] = max(dp[i+1][np], 1 + dp[i][p]);
            }
        }
        int ans = 0;
        REP(p, 5001) ans = max(ans, dp[N][p]);
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
#define END	 verify_case(_, AlbertoTheAviator().MaximumFlights(F, duration, refuel));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int F = 10; 
	int duration_[] = {10};
	  vector <int> duration(duration_, duration_+sizeof(duration_)/sizeof(*duration_)); 
	int refuel_[] = {0};
	  vector <int> refuel(refuel_, refuel_+sizeof(refuel_)/sizeof(*refuel_)); 
	int _ = 1; 
END
CASE(1)
	int F = 10; 
	int duration_[] = {8, 4};
	  vector <int> duration(duration_, duration_+sizeof(duration_)/sizeof(*duration_)); 
	int refuel_[] = {0, 2};
	  vector <int> refuel(refuel_, refuel_+sizeof(refuel_)/sizeof(*refuel_)); 
	int _ = 2; 
END
CASE(2)
	int F = 12; 
	int duration_[] = {4, 8, 2, 1};
	  vector <int> duration(duration_, duration_+sizeof(duration_)/sizeof(*duration_)); 
	int refuel_[] = {2, 0, 0, 0};
	  vector <int> refuel(refuel_, refuel_+sizeof(refuel_)/sizeof(*refuel_)); 
	int _ = 3; 
END
CASE(3)
	int F = 9; 
	int duration_[] = {4, 6};
	  vector <int> duration(duration_, duration_+sizeof(duration_)/sizeof(*duration_)); 
	int refuel_[] = {0, 1};
	  vector <int> refuel(refuel_, refuel_+sizeof(refuel_)/sizeof(*refuel_)); 
	int _ = 2; 
END
CASE(4)
	int F = 100; 
	int duration_[] = {101};
	  vector <int> duration(duration_, duration_+sizeof(duration_)/sizeof(*duration_)); 
	int refuel_[] = {100};
	  vector <int> refuel(refuel_, refuel_+sizeof(refuel_)/sizeof(*refuel_)); 
	int _ = 0; 
END
CASE(5)
	int F = 1947; 
	int duration_[] = {2407, 2979, 1269, 2401, 3227, 2230, 3991, 2133, 3338, 356, 2535, 3859, 3267, 365};
	  vector <int> duration(duration_, duration_+sizeof(duration_)/sizeof(*duration_)); 
	int refuel_[] = {2406, 793, 905, 2400, 1789, 2229, 1378, 2132, 1815, 355, 72, 3858, 3266, 364};
	  vector <int> refuel(refuel_, refuel_+sizeof(refuel_)/sizeof(*refuel_)); 
	int _ = 3; 
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
	int F = UNIFORM_LL(0, 100); 
// param type: int
	vector <int> duration; 
	{
		int N=UNIFORM_LL(1, 51);
		duration = vector <int>(N); 
		REP(i, N) {
			duration[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> refuel; 
	{
		int N=UNIFORM_LL(1, 51);
		refuel = vector <int>(N); 
		REP(i, N) {
			refuel[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = AlbertoTheAviator().MaximumFlights(F, duration, refuel);
	int _1 = AlbertoTheAviatorRef().MaximumFlights(F, duration, refuel);
	if(!verify_case(_0, _1, true)) {
print(F);
print(duration);
print(refuel);
	}
}
#endif

}
// END CUT HERE
