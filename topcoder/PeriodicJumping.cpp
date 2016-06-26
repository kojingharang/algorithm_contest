// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Frog Suwako lives on a two-dimensional plane.
Currently, she is located in the point (0, 0).
She would like to reach the point (x, 0).



Suwako jumps in a peculiar way: her jump lengths repeat in a periodic fashion.
The vector <int> jumpLengths contains one period of her jump lengths, starting with the length of the first jump she will make.
For example, if jumpLengths = { 2, 5 }, Suwako's jump lengths will be 2, 5, 2, 5, 2, 5, ...
Note that Suwako can jump onto arbitrary points in the plane, they are not required to have integer coordinates.



You are given the int x and the vector <int> jumpLengths.
Return the smallest non-negative integer j such that Suwako can reach the desired destination after j jumps.
If there is no such j, return -1 instead.

DEFINITION
Class:PeriodicJumping
Method:minimalTime
Parameters:int, vector <int>
Returns:int
Method signature:int minimalTime(int x, vector <int> jumpLengths)


CONSTRAINTS
-x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-len will contain between 1 and 50 elements, inclusive.
-Each element in len will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
15
{1,2,3,4,5,6,7,8,9,10}

Returns: 5

In 4 jumps Suwako cannot get far enough. In 5 jumps she can reach the destination as follows: (0,0) -> (1,0) -> (3,0) -> (6,0) -> (10,0) -> (15,0).


1)
5
{5}

Returns: 1

One jump is enough, since the distance between (0,0) and (5,0) is exactly 5.

2)
1
{10}

Returns: 2

Here Suwako needs two jumps. One possible solution is to land at (0.5, sqrt(10*10-0.5*0.5)) after the first jump.


3)
-10
{2,3,4,500,6,7,8}

Returns: 11



4)
-1000000000
{1}

Returns: 1000000000



5)
0
{19911120}

Returns: 0



******************************/
// END CUT HERE
#line 90 "PeriodicJumping.cpp"
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

class PeriodicJumping {
	public:
	int minimalTime(int x, vector <int> jl) {
		int N=jl.size();
		int mx=0;
		ll sum=0,sum2=0;
		if(x<0)x=-x;
		if(x==0)return 0;
		REP(i, N) {
			sum+=jl[i];
			mx=max(mx, jl[i]);
			if((sum-mx>=mx&&sum>=x) || sum==x) return i+1;
		}
		if(sum>=x) {
			sum2=0;
			REP(i, N) {
				sum2+=jl[i];
				if((sum+sum2-mx>=mx && sum+sum2>=x) || sum+sum2==x) return N+i+1;
				else if(mx==jl[i]) return N+i+1;
			}
		}
		if(sum==0) return -1;
		sum2=0;
		if(x%sum==0) return x/sum*N;
		REP(i, N) {
			sum2+=jl[i];
			if(x%sum<=sum2) return x/sum*N+i+1;
		}
		return -1;
	}
};

class PeriodicJumpingRef {
	public:
	int minimalTime(int x, vector <int> L) {
		if(x==0) return 0;
		int N=L.size();
		double lo=0, hi=0;
		ll ans = 0;
		REP(loop, 100000) {
			double start=-1;
			if(lo==0) start=hi;
			REP(i, N) {
				double lolo = lo-L[i];
				double lohi = lo+L[i];
				double hilo = hi-L[i];
				double hihi = hi+L[i];
				lo = min(abs(lolo), abs(hilo));
				hi = max(abs(hilo), abs(hihi));
				if(lolo * hilo < 0 || lohi * hihi < 0) lo=0;
				ans++;
//				cout<<lo<<" "<<hi<<endl;
				if(lo-1e-9<=abs(x) && abs(x)<=hi+1e-9) return ans;
			}
			if(start >= 0) {
				double d = hi - start;
				ll loop = floor((abs(x) - hi) / d);
				if(loop > 10000) {
					loop-=4;
//					cout<<" d "<<d<<" "<<loop<<" "<<ans<<endl;
					ans += loop*N;
					hi += d * loop;
				}
			}
		}
		return -1;
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
#define END	 verify_case(_, PeriodicJumping().minimalTime(x, jumpLengths));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int x = 15; 
	int jumpLengths_[] = {1,2,3,4,5,6,7,8,9,10};
	  vector <int> jumpLengths(jumpLengths_, jumpLengths_+sizeof(jumpLengths_)/sizeof(*jumpLengths_)); 
	int _ = 5; 
END
CASE(1)
	int x = 5; 
	int jumpLengths_[] = {5};
	  vector <int> jumpLengths(jumpLengths_, jumpLengths_+sizeof(jumpLengths_)/sizeof(*jumpLengths_)); 
	int _ = 1; 
END
CASE(2)
	int x = 1; 
	int jumpLengths_[] = {10};
	  vector <int> jumpLengths(jumpLengths_, jumpLengths_+sizeof(jumpLengths_)/sizeof(*jumpLengths_)); 
	int _ = 2; 
END
CASE(3)
	int x = -10; 
	int jumpLengths_[] = {2,3,4,500,6,7,8};
	  vector <int> jumpLengths(jumpLengths_, jumpLengths_+sizeof(jumpLengths_)/sizeof(*jumpLengths_)); 
	int _ = 11; 
END
CASE(4)
	int x = -1000000000; 
	int jumpLengths_[] = {1};
	  vector <int> jumpLengths(jumpLengths_, jumpLengths_+sizeof(jumpLengths_)/sizeof(*jumpLengths_)); 
	int _ = 1000000000; 
END
CASE(5)
	int x = 0; 
	int jumpLengths_[] = {19911120};
	  vector <int> jumpLengths(jumpLengths_, jumpLengths_+sizeof(jumpLengths_)/sizeof(*jumpLengths_)); 
	int _ = 0; 
END
CASE(5)
	int x = 1000000000; 
	int jumpLengths_[] = {
	100,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,10000,
	};
	  vector <int> jumpLengths(jumpLengths_, jumpLengths_+sizeof(jumpLengths_)/sizeof(*jumpLengths_)); 
	int _ = 4927100; 
END
CASE(5)
	int x = 1; 
	int jumpLengths_[] = {2,5};
	  vector <int> jumpLengths(jumpLengths_, jumpLengths_+sizeof(jumpLengths_)/sizeof(*jumpLengths_)); 
	int _ = 3; 
END
#if 01  // DO RANDOM TESTS

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
for(int loop=0;loop<10000;loop++) {
// param type: int
	int x = UNIFORM_LL(-1000000000, 1000000001); 
// param type: int
	vector <int> jumpLengths; 
	{
		int N=UNIFORM_LL(1, 51);
		jumpLengths = vector <int>(N); 
		REP(i, N) {
			jumpLengths[i] = UNIFORM_LL(1, 1000000000);
		}
	}
	int _0 = PeriodicJumping().minimalTime(x, jumpLengths);
	int _1 = PeriodicJumpingRef().minimalTime(x, jumpLengths);
	assert(_0!=-1);
	if(!verify_case(_0, _1, true)) {
print(x);
print(jumpLengths);
	}
}
#endif

}
// END CUT HERE
