// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Alex is sleeping soundly. At any minute T, his sleepiness can be characterized by an integer. Initially, at minute 0, Alex's sleepiness is some unknown integer S.

Unfortunately, there are several repeatedly ringing alarms disturbing him.

Starting from minute 1, the following happens. First, Alex's sleepiness increases by D. Then some of the alarms ring, decreasing Alex's sleepiness.

Formally, alarms' characteristics are given in three vector <int>s period, start and volume. The i-th alarm rings at minutes start[i], start[i] + period[i], start[i] + 2 * period[i], etc., and each time it rings, Alex's sleepiness instantly decreases by volume[i]. If several alarms ring at the same minute, their effects are added up, so each of them decreases Alex's sleepiness by its volume.

While Alex's sleepiness is positive, he's still sleeping. Once it becomes less than or equal to zero, Alex immediately wakes up. Note that Alex's initial sleepiness can be non-positive. In that case he just wakes up at minute 0.

You are given the vector <int>s period, start, volume, and the int D. Return the largest possible value of S (Alex's initial sleepiness) such that he will wake up at some moment. If he is guaranteed to wake up for all possible values of S, return -1 instead.


DEFINITION
Class:WakingUp
Method:maxSleepiness
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:int
Method signature:int maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D)


NOTES
-It is possible to prove that the answer for any test case fits into a 32-bit signed integer type.


CONSTRAINTS
-period will contain between 1 and 50 elements, inclusive.
-period, start and volume will contain the same number of elements.
-Each element of period will be between 1 and 10, inclusive.
-start[i] will be between 1 and period[i], inclusive.
-Each element of volume will be between 1 and 1000, inclusive.
-D will be between 1 and 100, inclusive.


EXAMPLES

0)
{2, 3}
{1, 2}
{3, 4}
3

Returns: 2

There are two alarms. The first alarm rings every 2 minutes, starting from minute 1, and has volume 3. The second alarm rings every 3 minutes, starting from minute 2, and has volume 4.

Here is what would happen for S = 2:


At minute 0, Alex's sleepiness is 2.
At minute 1, Alex's sleepiness increases to 5. Then the first alarm rings, decreasing his sleepiness to 2.
At minute 2, Alex's sleepiness increases to 5. Then the second alarm rings, decreasing his sleepiness to 1.
At minute 3, Alex's sleepiness increases to 4. Then the first alarm rings, decreasing his sleepiness to 1.
At minute 4, Alex's sleepiness increases to 4. No alarm rings at this minute.
At minute 5, Alex's sleepiness increases to 7. Then both alarms ring, decreasing his sleepiness to 0, so he wakes up.


It can be proven that for any larger S, Alex will never wake up.


1)
{1}
{1}
{17}
17

Returns: 0

For any positive S, Alex will never wake up. It's better not to fall asleep.

2)
{1}
{1}
{23}
17

Returns: -1

Each minute Alex's sleepiness decreases by 6. That means he will wake up at some moment, regardless of the initial sleepiness.

3)
{9, 2, 5, 5, 7}
{6, 1, 4, 1, 6}
{71, 66, 7, 34, 6}
50

Returns: 78



4)
{5, 6, 5, 3, 8, 3, 4}
{1, 1, 3, 2, 6, 3, 3}
{42, 85, 10, 86, 21, 78, 38}
88

Returns: -1



******************************/
// END CUT HERE
#line 107 "WakingUp.cpp"
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

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }


class WakingUp {
	public:
	int maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D) {
		int N = period.size();
		ll S = -D;
		ll ref=0;
		ll Min = 0;
		REP(ti, 2520*4) {
			S += D;
			REP(i, N) {
				if(ti>=start[i] && (ti-start[i])%period[i]==0) S-=volume[i];
			}
			if(ti<2520) cout<<S<<endl;
			Min = min(Min, S);
			if(ti==2520*2) ref=Min;
		}
		cout<<S<<" "<<Min<<endl;
		if(Min < ref) return -1;
		else return -Min;
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
#define END	 verify_case(_, WakingUp().maxSleepiness(period, start, volume, D));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){



CASE(0)
	int period_[] = {2, 7, 6, 6, 7, 10, 5, 9, 3, 4, 2, 3, 8, 9, 4, 10, 9, 4, 6, 8, 4, 10, 9, 4, 9, 2, 1, 2, 3};
	  vector <int> period(period_, period_+sizeof(period_)/sizeof(*period_)); 
	int start_[] = {1, 5, 4, 4, 5, 8, 3, 7, 1, 2, 1, 1, 6, 7, 2, 8, 7, 2, 4, 6, 2, 8, 7, 2, 7, 1, 1, 1, 1};
	  vector <int> start(start_, start_+sizeof(start_)/sizeof(*start_)); 
	int volume_[] = {21, 20, 28, 29, 9, 22, 16, 23, 17, 9, 7, 4, 12, 10, 21, 2, 19, 19, 8, 10, 21, 25, 15, 12, 14, 1, 8, 21, 11};
	  vector <int> volume(volume_, volume_+sizeof(volume_)/sizeof(*volume_)); 
	int D = 99; 
	int _ = 117; 
END
return 0;

CASE(0)
	int period_[] = {2, 3};
	  vector <int> period(period_, period_+sizeof(period_)/sizeof(*period_)); 
	int start_[] = {1, 2};
	  vector <int> start(start_, start_+sizeof(start_)/sizeof(*start_)); 
	int volume_[] = {3, 4};
	  vector <int> volume(volume_, volume_+sizeof(volume_)/sizeof(*volume_)); 
	int D = 3; 
	int _ = 2; 
END
CASE(1)
	int period_[] = {1};
	  vector <int> period(period_, period_+sizeof(period_)/sizeof(*period_)); 
	int start_[] = {1};
	  vector <int> start(start_, start_+sizeof(start_)/sizeof(*start_)); 
	int volume_[] = {17};
	  vector <int> volume(volume_, volume_+sizeof(volume_)/sizeof(*volume_)); 
	int D = 17; 
	int _ = 0; 
END
CASE(2)
	int period_[] = {1};
	  vector <int> period(period_, period_+sizeof(period_)/sizeof(*period_)); 
	int start_[] = {1};
	  vector <int> start(start_, start_+sizeof(start_)/sizeof(*start_)); 
	int volume_[] = {23};
	  vector <int> volume(volume_, volume_+sizeof(volume_)/sizeof(*volume_)); 
	int D = 17; 
	int _ = -1; 
END
CASE(3)
	int period_[] = {9, 2, 5, 5, 7};
	  vector <int> period(period_, period_+sizeof(period_)/sizeof(*period_)); 
	int start_[] = {6, 1, 4, 1, 6};
	  vector <int> start(start_, start_+sizeof(start_)/sizeof(*start_)); 
	int volume_[] = {71, 66, 7, 34, 6};
	  vector <int> volume(volume_, volume_+sizeof(volume_)/sizeof(*volume_)); 
	int D = 50; 
	int _ = 78; 
END
CASE(4)
	int period_[] = {5, 6, 5, 3, 8, 3, 4};
	  vector <int> period(period_, period_+sizeof(period_)/sizeof(*period_)); 
	int start_[] = {1, 1, 3, 2, 6, 3, 3};
	  vector <int> start(start_, start_+sizeof(start_)/sizeof(*start_)); 
	int volume_[] = {42, 85, 10, 86, 21, 78, 38};
	  vector <int> volume(volume_, volume_+sizeof(volume_)/sizeof(*volume_)); 
	int D = 88; 
	int _ = -1; 
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
	int N=UNIFORM_LL(1, 2);
	vector <int> period; 
	{
		period = vector <int>(N); 
		REP(i, N) {
			period[i] = UNIFORM_LL(1, 1000);
		}
	}
// param type: int
	vector <int> start; 
	{
		start = vector <int>(N); 
		REP(i, N) {
			start[i] = UNIFORM_LL(1, period[i]+1);
		}
	}
// param type: int
	vector <int> volume; 
	{
		volume = vector <int>(N); 
		REP(i, N) {
			volume[i] = UNIFORM_LL(1, 1001);
		}
	}
// param type: int
	int D = UNIFORM_LL(1, 100); 
	int _0 = WakingUp().maxSleepiness(period, start, volume, D);
	int _1 = WakingUpRef().maxSleepiness(period, start, volume, D);
	if(!verify_case(_0, _1, true)) {
print(period);
print(start);
print(volume);
print(D);
	}
}
#endif

}
// END CUT HERE
