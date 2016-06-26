// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Fox Ciel is writing an AI for the game Starcraft and she needs your help.


In Starcraft, one of the available units is a mutalisk.
Mutalisks are very useful for harassing Terran bases.
Fox Ciel has one mutalisk.
The enemy base contains one or more Space Construction Vehicles (SCVs).
Each SCV has some amount of hit points.


When the mutalisk attacks, it can target up to three different SCVs.

The first targeted SCV will lose 9 hit points.
The second targeted SCV (if any) will lose 3 hit points.
The third targeted SCV (if any) will lose 1 hit point.

If the hit points of a SCV drop to 0 or lower, the SCV is destroyed.
Note that you may not target the same SCV twice in the same attack.


You are given a vector <int> x containing the current hit points of your enemy's SCVs.
Return the smallest number of attacks in which you can destroy all these SCVs.

DEFINITION
Class:Mutalisk
Method:minimalAttacks
Parameters:vector <int>
Returns:int
Method signature:int minimalAttacks(vector <int> x)


CONSTRAINTS
-x will contain between 1 and 20 elements, inclusive.
-Each element in x will be between 1 and 60, inclusive.


EXAMPLES

0)
{12,10,4}

Returns: 2

You can destroy all SCVs in two attacks as follows:

Target the SCVs in the order 0, 2, 1. Their hit points after the attack will be {12-9, 10-1, 4-3} = {3, 9, 1}.
Target the SCVs in the order 1, 0, 2. Their hit points will drop exactly to {0, 0, 0}.


1)
{54,18,6}

Returns: 6

You should attack 6 times, always in the order 0, 1, 2.

2)
{1,1,1,1,1,1,1,1,1,1}

Returns: 4

There are 10 SCVs, each with just a single hit point. Your attack can kill only three of them, therefore at least 4 attacks are needed.

3)
{55,60,53}

Returns: 13



4)
{60}

Returns: 7



5)
{60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60}

Returns: 93



******************************/
// END CUT HERE
#line 91 "Mutalisk.cpp"
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
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, I, J) REP(i, I) { REP(j, J) cout<<table[i][j]<<" "; cout<<"\n"; }
#define PRINT3(table, I, J, K) REP(i, I) { REP(j, J) { REP(k, K) cout<<table[i][j][k]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

//const int A=6*20+1;
//const int B=20*20+1;
//const int C=60*20+1;
const int A=100;
const int B=100;
ll dp[22][A][B];
class Mutalisk {
	public:
	int minimalAttacks(vector <int> x) {
		int N=x.size();
		ll lo=1, hi=95;
		while(lo+1<hi) {
			ll mid=(lo+hi)/2;
			CLEAR(dp, 0x7f);
			dp[0][0][0]=0;
			RANGE(i, 1, N+1) {
				REP(a, mid+1) REP(b, mid+1) {
					if(dp[i-1][a][b]>mid) continue;
					for(int la=0;la*9<9+x[i-1] && a+la<=mid; ++la) {
						for(int lb=0;lb*3<3+x[i-1] && b+lb<=mid; ++lb) {
							int lc = max(0, x[i-1]-la*9-lb*3);
							if(la+lb+lc<=mid) {
								dp[i][a+la][b+lb]=min(dp[i][a+la][b+lb], dp[i-1][a][b]+lc);
							}
						}
					}
				}
			}
			bool ok=false;
			REP(a, mid+1) REP(b, mid+1) {
				if(dp[N][a][b]<=mid) ok=true;
			}
			cout<<mid<<" "<<ok<<endl;
			(ok ? hi : lo) = mid;
		}
		return hi;
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
#define END	 verify_case(_, Mutalisk().minimalAttacks(x));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(2)
	int x_[] = {1,1,1,1,1,1,1,1,1,1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int _ = 4; 
END
//return 0;
CASE(0)
	int x_[] = {12,10,4};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int _ = 2; 
END
//return 0;
CASE(1)
	int x_[] = {54,18,6};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int _ = 6; 
END
//return 0;
CASE(2)
	int x_[] = {1,1,1,1,1,1,1,1,1,1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int _ = 4; 
END
CASE(3)
	int x_[] = {55,60,53};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int _ = 13; 
END
CASE(4)
	int x_[] = {60};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int _ = 7; 
END
CASE(5)
	int x_[] = {60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int _ = 93; 
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
	vector <int> x; 
	{
		int N=UNIFORM_LL(1, 51);
		x = vector <int>(N); 
		REP(i, N) {
			x[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = Mutalisk().minimalAttacks(x);
	int _1 = MutaliskRef().minimalAttacks(x);
	if(!verify_case(_0, _1, true)) {
print(x);
	}
}
#endif

}
// END CUT HERE
