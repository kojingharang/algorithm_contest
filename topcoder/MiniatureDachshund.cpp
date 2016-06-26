// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Dachshund is a popular dog breed. In this problem, a miniature dachshund is defined as a dachshund whose weight is not more than 5,000 grams.


Lun the miniature dachshund loves mikan (satsuma oranges). She has just bought some mikan. You are given a vector <int> mikan. It gives the weight of all mikan she bought. For each valid i, mikan[i] is the weight of the i-th mikan in grams.


You are also given an int weight. Currently, Lun weighs weight grams. When she eats i-th mikan, her weight increases by mikan[i] grams. If she eats multiple mikan, her weight increases by their total weight. She cannot eat just a part of a mikan. In other words, if she chooses to eat a mikan, she eats it completely.


She wants to remain being a miniature dachshund. That is, she wants her weight not to exceed 5,000 grams. Under this condition, calculate and return the maximum number of mikan Lun can eat.

DEFINITION
Class:MiniatureDachshund
Method:maxMikan
Parameters:vector <int>, int
Returns:int
Method signature:int maxMikan(vector <int> mikan, int weight)


CONSTRAINTS
-mikan will contain between 1 and 50 elements, inclusive.
-Each element of mikan will be between 50 and 200, inclusive.
-weight will be between 3,000 and 5,000, inclusive.


EXAMPLES

0)
{100, 100, 100, 100, 100}
4750

Returns: 2

Here, Lun weighs 4,750 grams and has bought 5 mikan, each of which weighs 100 grams. When she eats 2 of these, her weight will be 4,950 grams. She should not eat more.

1)
{100, 100, 100, 100, 50}
4750

Returns: 3

This time, one of the mikan is smaller. She can eat it with 2 of the 100-gram mikan. Note that her weight is allowed to be exactly 5,000 grams.

2)
{120, 90, 130, 100, 110, 80}
3000

Returns: 6

When she is light enough, she can eat all of the mikan she has bought.

3)
{50}
5000

Returns: 0

When her weight is already 5,000 grams, she should not eat anything.

4)
{200, 50, 200, 50, 200, 50, 200, 50}
4800

Returns: 4



******************************/
// END CUT HERE
#line 74 "MiniatureDachshund.cpp"
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

class MiniatureDachshund {
	public:
	int maxMikan(vector <int> mikan, int weight) {
		int ans=0; sort(ALL(mikan));
		FOR(e, mikan) if(weight+*e<5000) weight+=*e,ans++;
		return ans;
	}
};
class MiniatureDachshundTry {
	public:
	int maxMikan(vector <int> mikan, int weight) {
		int ans=0; sort(ALL(mikan));
		FOR(e, mikan) if(weight+*e<=5000) weight+=*e,ans++;
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
#define END	 verify_case(_, MiniatureDachshund().maxMikan(mikan, weight));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int mikan_[] = {100, 100, 100, 100, 100};
	  vector <int> mikan(mikan_, mikan_+sizeof(mikan_)/sizeof(*mikan_)); 
	int weight = 4750; 
	int _ = 2; 
END
CASE(1)
	int mikan_[] = {100, 100, 100, 100, 50};
	  vector <int> mikan(mikan_, mikan_+sizeof(mikan_)/sizeof(*mikan_)); 
	int weight = 4750; 
	int _ = 3; 
END
CASE(2)
	int mikan_[] = {120, 90, 130, 100, 110, 80};
	  vector <int> mikan(mikan_, mikan_+sizeof(mikan_)/sizeof(*mikan_)); 
	int weight = 3000; 
	int _ = 6; 
END
CASE(3)
	int mikan_[] = {50};
	  vector <int> mikan(mikan_, mikan_+sizeof(mikan_)/sizeof(*mikan_)); 
	int weight = 5000; 
	int _ = 0; 
END
CASE(4)
	int mikan_[] = {200, 50, 200, 50, 200, 50, 200, 50};
	  vector <int> mikan(mikan_, mikan_+sizeof(mikan_)/sizeof(*mikan_)); 
	int weight = 4800; 
	int _ = 4; 
END
#if 01  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10;loop++) {
// param type: int
start_time=clock();
	vector <int> mikan; 
	{
		int N=UNIFORM_LL(1, 50);
		mikan = vector <int>(N); 
		REP(i, N) {
			mikan[i] = UNIFORM_LL(50, 200);
		}
	}
// param type: int
start_time=clock();
	int weight = UNIFORM_LL(3000, 5000); 
	int _0 = MiniatureDachshund().maxMikan(mikan, weight);
	int _1 = MiniatureDachshundTry().maxMikan(mikan, weight);
	if(!verify_case(_0, _1, true)) {
print(mikan);
print(weight);
	}
}
#endif

}
// END CUT HERE
