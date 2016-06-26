// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
There are some cats sitting on a straight line that goes from the left to the right.
You are given two vector <int>s position and count.
For each valid i, there are count[i] cats initially sitting at the point position[i].




During each minute, each cat chooses and performs one of three possible actions: it may stay in its place, move one unit to the left (i.e., from x to x-1), or move one unit to the right (i.e., from x to x+1).
(Note that there are no restrictions. In particular, different cats that are currently at the same point may make different choices.)




You are also given an int time.
Cats don't like to sit together with other cats, so they want to minimize the number of points that contain two or more cats after time minutes.
Return this minimum number.


DEFINITION
Class:CatsOnTheLineDiv1
Method:getNumber
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int getNumber(vector <int> position, vector <int> count, int time)


CONSTRAINTS
-position will contain between 1 and 1,000 elements, inclusive.
-position and count will contain the same number of elements.
-Each element of position will be between -100,000,000 and 100,000,000, inclusive.
-Each element of position will be distinct.
-Each element of count will be between 1 and 100,000,000, inclusive.
-time will be between 0 and 100,000,000, inclusive.


EXAMPLES

0)
{0}
{7}
3

Returns: 0

In this case, there are initially 7 cats at the origin. Each of the cats can go to a separate point. They will occupy all integer points from -3 to 3, inclusive. Thus, the answer is 0.

1)
{0}
{6}
2

Returns: 1

In this case, there will always be at least one point with more than one cat. One of the best strategies for the cats is to not move at all. This strategy will lead to the answer equal to 1.

2)
{4, 7, 47}
{4, 7, 4}
1

Returns: 3



3)
{3, 0, 7, 10}
{3, 7, 4, 5}
2

Returns: 2



4)
{-5, 0, 7}
{47, 85, 10}
6

Returns: 1



5)
{-8, 12, -15, -20, 17, -5, 7, 10}
{20, 10, 7, 9, 2, 8, 11, 10}
2

Returns: 5



******************************/
// END CUT HERE
#line 99 "CatsOnTheLineDiv1.cpp"
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

class CatsOnTheLineDiv1 {
	public:
	int getNumber(vector <int> P, vector <int> C, int T) {
		int N=P.size();
		vector<pair<int, int> > w(N);
		REP(i, N) w[i] = MP(P[i], C[i]);
		sort(ALL(w));
		REP(i, N) P[i]=w[i].first, C[i]=w[i].second;
		int ans = 0;
		ll next = -(1LL<<60);
		ll m = -(1LL<<60);
		REP(i, N) {
			ll hl = P[i]-T;
			ll hr = P[i]-C[i]+1+T;
			if(P[i]-T<=m && m<=P[i]+T) continue;
			if(hr<next || C[i]/2 > T) {
				ans++;
				m = P[i]+T;
			} else {
				next = max(next, hl) + C[i];
			}
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
#define END	 verify_case(_, CatsOnTheLineDiv1().getNumber(position, count, time));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int position_[] = {527, -279, -793, 900, 637, 542, 1, 826, 201, 877, -968, 88, 815, 618, -195, -982, -976, -335, 915, -288, -778, -432, 340, -482, -56, -22, 300, -930, 562, -276, -792, 510, 281, 352, 341, -617, 87, -42, -143, 13, -783, 839, 454, 356, 760, -473, -898, -481, 282, -269};
	  vector <int> position(position_, position_+sizeof(position_)/sizeof(*position_)); 
	int count_[] = {750, 871, 338, 234, 714, 647, 1185, 249, 1154, 445, 211, 773, 973, 391, 911, 323, 510, 684, 296, 525, 149, 684, 1169, 142, 170, 1005, 561, 46, 845, 176, 510, 764, 228, 332, 538, 821, 1279, 321, 1263, 1101, 723, 814, 557, 1114, 729, 862, 437, 1195, 1050, 279};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int time = 824; 
	int _ = 1; 
END
//return 0;

CASE(0)
	int position_[] = {0};
	  vector <int> position(position_, position_+sizeof(position_)/sizeof(*position_)); 
	int count_[] = {7};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int time = 3; 
	int _ = 0; 
END
CASE(1)
	int position_[] = {0};
	  vector <int> position(position_, position_+sizeof(position_)/sizeof(*position_)); 
	int count_[] = {6};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int time = 2; 
	int _ = 1; 
END
CASE(2)
	int position_[] = {4, 7, 47};
	  vector <int> position(position_, position_+sizeof(position_)/sizeof(*position_)); 
	int count_[] = {4, 7, 4};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int time = 1; 
	int _ = 3; 
END
CASE(3)
	int position_[] = {3, 0, 7, 10};
	  vector <int> position(position_, position_+sizeof(position_)/sizeof(*position_)); 
	int count_[] = {3, 7, 4, 5};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int time = 2; 
	int _ = 2; 
END
CASE(4)
	int position_[] = {-5, 0, 7};
	  vector <int> position(position_, position_+sizeof(position_)/sizeof(*position_)); 
	int count_[] = {47, 85, 10};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int time = 6; 
	int _ = 1; 
END
CASE(5)
	int position_[] = {-8, 12, -15, -20, 17, -5, 7, 10};
	  vector <int> position(position_, position_+sizeof(position_)/sizeof(*position_)); 
	int count_[] = {20, 10, 7, 9, 2, 8, 11, 10};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int time = 2; 
	int _ = 5; 
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
	vector <int> position; 
	{
		int N=UNIFORM_LL(1, 51);
		position = vector <int>(N); 
		REP(i, N) {
			position[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> count; 
	{
		int N=UNIFORM_LL(1, 51);
		count = vector <int>(N); 
		REP(i, N) {
			count[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int time = UNIFORM_LL(0, 100); 
	int _0 = CatsOnTheLineDiv1().getNumber(position, count, time);
	int _1 = CatsOnTheLineDiv1Ref().getNumber(position, count, time);
	if(!verify_case(_0, _1, true)) {
print(position);
print(count);
print(time);
	}
}
#endif

}
// END CUT HERE
