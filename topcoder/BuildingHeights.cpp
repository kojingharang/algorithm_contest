// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Byteland is a city with many skyscrapers, so it's a perfect venue for BASE jumping. Danilo is an enthusiastic BASE jumper. He plans to come to Byteland and to jump off some of its buildings.

Danilo can make arbitrarily many jumps in Byteland. However, he has some rules. First, he never jumps off the same building twice. Second, all buildings he selects for his jumps must have the same number of floors. (This is for safety reasons: It is hard to get the timing right if each jump starts at a different height.)

Philipe is the mayor of Byteland. He welcomes Danilo's visit as he would like to use it as a publicity stunt. Of course, the more jumps Danilo makes, the better the publicity will be. But what if there aren't enough buildings with the same height? To avoid this issue, the mayor is willing to prepare the town for Danilo's visit. Before Danilo arrives, Philipe wants to build additional floors on some of the skyscrapers in Byteland.

You are given a vector <int> heights. Each element of heights is the number of floors in one of Byteland's skyscrapers. Let N be the number of elements in heights. For each M between 1 and N, inclusive, answer the following question: What is the smallest number of additional floors the mayor has to build so that there will be at least M buildings with the same number of floors?

For each i between 1 and N, inclusive, let A[i] be the answer to the above question for M = i+1. Return the value (A[1] XOR A[2] XOR ... XOR A[N]).

DEFINITION
Class:BuildingHeights
Method:minimum
Parameters:vector <int>
Returns:int
Method signature:int minimum(vector <int> heights)


NOTES
-You may assume that the correct return value always fits into a signed 32-bit integer variable.
-Each question should be answered independently of the others. For example, when trying to produce four buildings with the same number of floors, you do not have to start from the optimal solution for three buildings.


CONSTRAINTS
-heights contains between 1 and 4,000 elements, inclusive.
-Each element of heights will be between 1 and 4,000, inclusive.


EXAMPLES

0)
{1, 5, 4, 3, 8}

Returns: 22


Danilo can jump off a building without any changes to the city.
To get two equally tall buildings we need to build one additional floor. For example, we can increase building #2 (0-based index) from 4 to 5 floors.
To get three equally tall buildings we need to build three additional floors: one on building #2 and two on building #3. This way, the buildings #1, #2, and #3 will have 5 floors each.
To get four equally tall buildings we need to build seven additional floors.
Making all five buildings equally tall requires us to build 19 additional floors.



1)
{1, 2, 3}

Returns: 2



2)
{3, 4, 1, 6, 8, 1}

Returns: 21



3)
{990, 20, 2359, 1667, 51, 2455, 1659, 1093, 2015, 205, 656, 752, 1760, 1594, 857,
 2033, 1868, 1932, 2408, 1518, 91, 2220, 1696, 1552, 933, 143, 1888, 1261, 2298, 1975,
 929, 2139, 1994, 2139, 158, 896, 2093, 1816, 841, 459, 2020, 1496, 63, 131, 589, 919,
 1015, 1308, 350, 922, 326, 1792, 641, 2021, 843, 425, 1015, 231, 1685, 2165, 1057,
 1465, 655, 550, 1103, 812, 297, 2048, 1479, 1137, 6, 2350, 1484, 1420, 1332, 925, 2338,
 1198, 2232, 1539, 2119, 57, 830, 1611, 929, 525, 888}

Returns: 56068



******************************/
// END CUT HERE
#line 77 "BuildingHeights.cpp"
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

int cnt[4001];
class BuildingHeights {
	public:
	int minimum(vector <int> H) {
		int N=H.size();
		sort(ALL(H));
		int res=0;
		memset(cnt, 0, sizeof(cnt));
		REP(i, N) cnt[i+1]=cnt[i]+H[i];
		RANGE(len, 2, N+1) {
			int inf=0x7fffffff;
			for(int i=0;i+len-1<N;i++) 
				inf=min(inf,H[i+len-1]*len-(cnt[i+len]-cnt[i]));
			res^=inf;
		}
		return res;
	}
};

class BuildingHeightsRef {
	public:
	int minimum(vector <int> H) {
		int N=H.size();
		sort(ALL(H));
		ll base = 5000;
		VI s(N+1);
		RANGE(i, 1, N+1) {
			s[i] = s[i-1] + base - H[i-1];
		}
		ll ans = 0;
		RANGE(l, 1, N+1) {
			ll lans=1LL<<60;
			REP(b, N-l+1) {
				ll a = s[b+l]-s[b] - l*(base-H[b+l-1]);
				lans = min(lans, a);
			}
			ans ^= lans;
		}
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
#define END	 verify_case(_, BuildingHeights().minimum(heights));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 

CASE(0)
vector<int> heights(4000);
REP(i, heights.size()) heights[i]=UNIFORM_LL(1, 4001);
int _ = 7161898;
END

CASE(0)
	int heights_[] = {1, 10};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int _ = 9; 
END
CASE(0)
	int heights_[] = {1, 5, 4, 3, 8};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int _ = 22; 
END
//return 0;
CASE(1)
	int heights_[] = {1, 2, 3};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int _ = 2; 
END
CASE(2)
	int heights_[] = {3, 4, 1, 6, 8, 1};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int _ = 21; 
END
CASE(3)
	int heights_[] = {990, 20, 2359, 1667, 51, 2455, 1659, 1093, 2015, 205, 656, 752, 1760, 1594, 857,
 2033, 1868, 1932, 2408, 1518, 91, 2220, 1696, 1552, 933, 143, 1888, 1261, 2298, 1975,
 929, 2139, 1994, 2139, 158, 896, 2093, 1816, 841, 459, 2020, 1496, 63, 131, 589, 919,
 1015, 1308, 350, 922, 326, 1792, 641, 2021, 843, 425, 1015, 231, 1685, 2165, 1057,
 1465, 655, 550, 1103, 812, 297, 2048, 1479, 1137, 6, 2350, 1484, 1420, 1332, 925, 2338,
 1198, 2232, 1539, 2119, 57, 830, 1611, 929, 525, 888};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int _ = 56068; 
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
for(int loop=0;loop<100;loop++) {
// param type: int
	vector <int> heights; 
	{
		int N=UNIFORM_LL(1, 4001);
		heights = vector <int>(N); 
		REP(i, N) {
			heights[i] = UNIFORM_LL(1, 4001);
		}
	}
	int _0 = BuildingHeights().minimum(heights);
	int _1 = BuildingHeightsRef().minimum(heights);
	if(!verify_case(_0, _1, true)) {
print(heights);
	}
}
#endif

}
// END CUT HERE
