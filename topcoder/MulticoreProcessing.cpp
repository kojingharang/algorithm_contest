// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// In the last several years CPU manufacturers have been making processors with an ever-increasing number of processing cores.
Utilizing multiple cores to process workloads sometimes creates challenges for developers.
When a processing workload gets split into multiple parts, there is often some performance penalty caused by having to split the work and recombine the results.
For example, a job that takes 1000 ms on a single core might be expected to run in 500 ms across two cores, but in reality ends up taking 650 ms.

Your team has a workload that needs to be processed.
The workload requires jobLength units of computation.
If we use multiple cores to process the job, the computation will be split equally among all cores.
For example, if you split 1000 units of computation among 3 cores, each core will get exactly 1000/3 units of computation to perform.

You have several available systems that can be used for the computation.
Each system has some number of cores.
All cores in a system have the same speed of computation.
You need to choose a single system that will be used to process the workload, and you need to choose how many cores of that system will be used for the computation.

The description of the systems you have is given in the vector <int>s speed and cores.
For each valid i you own a system with cores[i] cores such that each of the cores can execute speed[i] units of computation per millisecond.

Due to the overhead with parallelization, the computation will take additional corePenalty milliseconds for each core used beyond the first.
This constant is the same for all systems you have.

You are given the long long jobLength, the int corePenalty, and the vector <int>s speed and cores.
Find the best system you should use and the best number of cores you should use on that system.
Return the smallest positive integer T such that it is possible to execute the entire computation in T milliseconds or less.

DEFINITION
Class:MulticoreProcessing
Method:fastestTime
Parameters:long long, int, vector <int>, vector <int>
Returns:long long
Method signature:long long fastestTime(long long jobLength, int corePenalty, vector <int> speed, vector <int> cores)


CONSTRAINTS
-jobLength will be between 1 and 10^18, inclusive.
-corePenalty will be between 0 and 1000000000, inclusive.
-speed will have between 1 and 50 elements, inclusive.
-cores will have the same number of elements as speed.
-Each element of speed will be between 1 and 1000000000, inclusive.
-Each element of cores will be between 1 and 1000000000, inclusive.


EXAMPLES

0)
2000
5
{40,20}
{2,4}

Returns: 30

The first system is twice as fast as the second one, but the first system only has two cores while the second one has four.
Their raw processing power is the same, but using more cores incurs the core penalty multiple times.
Thus, in this particular case it is better to use the first system.
If we use both cores, each of them has to do 1000 steps of computation, and with speed 40 this will take exactly 25 milliseconds.
We then add the 5-millisecond core penalty to compute that the total running time for this option is exactly 30 milliseconds.

1)
2000
5
{10,20}
{2,4}

Returns: 40

Now, the faster machine is also the one with more cores. Even with the core penalty it's far faster overall.

2)
1000
0
{10}
{3}

Returns: 34

We need to perform 1000 units of computation.
On a system with 3 cores, each with speed 10, we will need 1000/(3*10) = 33.3333333... milliseconds of time.
The correct return value is this exact value rounded up to the nearest integer: 34 milliseconds is the smallest integer amount of milliseconds sufficient for the computation.

3)
10000
5
{39,37,44}
{8,16,6}

Returns: 63

These are roughly the specs of some current-day CPUs.

*/
// END CUT HERE
#line 97 "MulticoreProcessing.cpp"

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
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class MulticoreProcessing {
	public:
	long long fastestTime(long long jobLength, int corePenalty, vector <int> speed, vector <int> cores) {
		ll ans = 1LL<<60;
		ll N = cores.size();
		REP(i, N) {
			ll u = (jobLength+speed[i]-1)/speed[i];
			auto f = [&](ll nc) {
				if(nc>cores[i]) return 1LL<<60;
				ll t = (u+nc-1)/nc;
				ll lans = corePenalty*(nc-1) + t;
				return lans;
			};
			auto ff = [&](double nc) {
				if(nc>cores[i]) return 1e100;
				return corePenalty*(nc-1) + u/nc;
			};
			ll lans = 1LL<<60;
			if(corePenalty==0) {
				lans = f(cores[i]);
			} else {
//				ll lo = sqrt(u/corePenalty);
//				RANGE(nc, 1, cores[i]+1) {
//					DD(f(nc));
//				}
				double lo = 1, hi = cores[i];
				while(lo+2<hi) {
					double a = lo+(hi-lo)/3;
					double b = lo+2*(hi-lo)/3;
//					DD(lo);
//					DD(a);
//					DD(b);
//					DD(hi);
//					DD(ff(a));
//					DD(ff(b));
					if(ff(a)<ff(b)) hi=b; else lo=a;
//					if(ff(a)<ff(b)) DD("left"); else DD("right");
				}
				RANGE(nc, lo-1, hi+2) {
					if(1<=nc && nc<=cores[i]) {
//						DD(nc);
//						DD(f(nc));
						lans = min(lans, f(nc));
					}
				}
			}
			ans = min(ans, lans);
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const long long& Expected, const long long& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, MulticoreProcessing().fastestTime(jobLength, corePenalty, speed, cores));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){


CASE(0)
	long long jobLength = 10000000000LL; 
	int corePenalty = 1; 
	int speed_[] = {1};
	  vector <int> speed(speed_, speed_+sizeof(speed_)/sizeof(*speed_)); 
	int cores_[] = {1000000000};
	  vector <int> cores(cores_, cores_+sizeof(cores_)/sizeof(*cores_)); 
	long long _ = 199999LL; 
END
return 0;

CASE(0)
	long long jobLength = 2000LL; 
	int corePenalty = 5; 
	int speed_[] = {40,20};
	  vector <int> speed(speed_, speed_+sizeof(speed_)/sizeof(*speed_)); 
	int cores_[] = {2,4};
	  vector <int> cores(cores_, cores_+sizeof(cores_)/sizeof(*cores_)); 
	long long _ = 30LL; 
END
CASE(1)
	long long jobLength = 2000LL; 
	int corePenalty = 5; 
	int speed_[] = {10,20};
	  vector <int> speed(speed_, speed_+sizeof(speed_)/sizeof(*speed_)); 
	int cores_[] = {2,4};
	  vector <int> cores(cores_, cores_+sizeof(cores_)/sizeof(*cores_)); 
	long long _ = 40LL; 
END
CASE(2)
	long long jobLength = 1000LL; 
	int corePenalty = 0; 
	int speed_[] = {10};
	  vector <int> speed(speed_, speed_+sizeof(speed_)/sizeof(*speed_)); 
	int cores_[] = {3};
	  vector <int> cores(cores_, cores_+sizeof(cores_)/sizeof(*cores_)); 
	long long _ = 34LL; 
END
CASE(3)
	long long jobLength = 10000LL; 
	int corePenalty = 5; 
	int speed_[] = {39,37,44};
	  vector <int> speed(speed_, speed_+sizeof(speed_)/sizeof(*speed_)); 
	int cores_[] = {8,16,6};
	  vector <int> cores(cores_, cores_+sizeof(cores_)/sizeof(*cores_)); 
	long long _ = 63LL; 
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
// param type: long
	long long jobLength = UNIFORM_LL(0, 100); 
// param type: int
	int corePenalty = UNIFORM_LL(0, 100); 
// param type: int
	vector <int> speed; 
	{
		int N=UNIFORM_LL(1, 51);
		speed = vector <int>(N); 
		REP(i, N) {
			speed[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> cores; 
	{
		int N=UNIFORM_LL(1, 51);
		cores = vector <int>(N); 
		REP(i, N) {
			cores[i] = UNIFORM_LL(0, 1000);
		}
	}
	long long _0 = MulticoreProcessing().fastestTime(jobLength, corePenalty, speed, cores);
	long long _1 = MulticoreProcessingRef().fastestTime(jobLength, corePenalty, speed, cores);
	if(!verify_case(_0, _1, true)) {
print(jobLength);
print(corePenalty);
print(speed);
print(cores);
	}
}
#endif

}
// END CUT HERE
