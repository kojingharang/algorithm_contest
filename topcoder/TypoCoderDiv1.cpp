// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// TypoCoder is a programming contest like TopCoder.
TypoCoder also has a rating system.
There are two types of coders in TypoCoder: brown coders and ciel coders.
A brown coder is a coder whose rating is greater than or equal to 2200.
A ciel coder is a coder whose rating is less than 2200.

Cat Lower competes in TypoCoder.
He is currently a ciel coder.
His rating at the end of the current year is X.

Next year there will be some contests.
In each of those contests, Cat Lower can either try his best or lose on purpose.
For each i, the i-th contest (0-based index) has weight D[i].
If Cat Lower tries his best in the i-th contest, his rating will increase by D[i].
If he decides to lose on purpose instead, his rating will decrease by D[i], but not below zero.
Formally, his rating will decrease by min(D[i],his rating before the contest).

Cat Lower loves being a ciel coder.
Therefore, he must never be a brown coder twice in a row.
That is, whenever Cat Lower becomes a brown coder, he must be ciel again after the next contest (if there are any contests left).

TypoCoder awards "Chameleon coder of the year" to the coder whose color changed the most times during the year.

You are given the vector <int> D and the int X.
Return the maximal number of color changes Cat Lower can have next year.


DEFINITION
Class:TypoCoderDiv1
Method:getmax
Parameters:vector <int>, int
Returns:int
Method signature:int getmax(vector <int> D, int X)


CONSTRAINTS
-D will contain between 1 and 50 elements, inclusive.
-Each element of D will be between 0 and 1,000,000,000 (10^9), inclusive.
-X will be between 0 and 2199, inclusive.


EXAMPLES

0)
{100,200,100,1,1}
2000

Returns: 3

When he increase at the second, the third and the last competition and decrease at the first and the fourth competition, he can change the color 3 times and this is the maximal.

1)
{0,0,0,0,0}
2199

Returns: 0

He cannot be a brown coder in this case.

2)
{90000,80000,70000,60000,50000,40000,30000,20000,10000}
0

Returns: 1

Note that Cat Lower always has at least one valid strategy: if he decides to lose in all contests, he will remain ciel forever.
In this test case, the optimal strategy for him is to lose in the first eight contests and then to win in the last one.
Note that before the last contest his rating will be 0.

3)
{1000000000,1000000000,10000,100000,2202,1}
1000

Returns: 4



4)
{2048,1024,5012,256,128,64,32,16,8,4,2,1,0}
2199

Returns: 0



5)
{61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272}
1223

Returns: 29



6)
{34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32}
1328

Returns: 20



*/
// END CUT HERE
#line 108 "TypoCoderDiv1.cpp"
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
#define PRINT2(table, W, H) REP(x, W) { REP(y, H) cout<<table[x][y]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class TypoCoderDiv1 {
	public:
	int getmax(vector <int> D, int X) {
		int N=D.size();
		map<int, int> dp[52];
		dp[0][X]=0;
		REP(i, N+1) FOR(e, dp[i]) for(int d=-1;d<=1;d+=2) {
			int v=e->first;
			int nv = max(0, e->first + d*D[i]);
			int change = v<2200&&nv>=2200 || v>=2200&&nv<2200;
			if(e->first>=2200 && nv<2200 || e->first<2200)
				dp[i+1][nv] = max(dp[i+1][nv], change + e->second);
		}
		int ans=0;
		FOR(e, dp[N]) ans=max(ans, e->second);
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, TypoCoderDiv1().getmax(D, X));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){
CASE(0)
	int D_[] = {100,200,100,1,1};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	int X = 2000; 
	int _ = 3; 
END
//return 0;
CASE(1)
	int D_[] = {0,0,0,0,0};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	int X = 2199; 
	int _ = 0; 
END
CASE(2)
	int D_[] = {90000,80000,70000,60000,50000,40000,30000,20000,10000};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	int X = 0; 
	int _ = 1; 
END
CASE(3)
	int D_[] = {1000000000,1000000000,10000,100000,2202,1};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	int X = 1000; 
	int _ = 4; 
END
CASE(4)
	int D_[] = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	int X = 2199; 
	int _ = 0; 
END
CASE(5)
	int D_[] = {61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	int X = 1223; 
	int _ = 29; 
END
CASE(6)
	int D_[] = {34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	int X = 1328; 
	int _ = 20; 
END
#if 0  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<1000;loop++) {
// param type: int
start_time=clock();
	vector <int> D; 
	{
		int N=UNIFORM_LL(1, 50);
		D = vector <int>(N); 
		REP(i, N) {
			D[i] = UNIFORM_LL(0, 1000000000);
		}
	}
// param type: int
start_time=clock();
	int X = UNIFORM_LL(0, 2199); 
	int _0 = TypoCoderDiv1().getmax(D, X);
	int _1 = TypoCoderDiv1Try().getmax(D, X);
	if(!verify_case(_0, _1, true)) {
print(D);
print(X);
	}
}
#endif

}
// END CUT HERE
