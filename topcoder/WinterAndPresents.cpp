// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
It's winter time!
You need to prepare a Christmas gift for your friend.




You have several bags arranged in a row.
The bags only contain apples and oranges.
You are given an vector <int> apple and an vector <int> orange.
For each i, the i-th element of apple represents the number of apples in the i-th bag, and the i-th element of orange represents the number of oranges in the i-th bag.




You will choose the gift using the following procedure:
First, you will choose any positive integer X such that there are at least X pieces of fruit in each bag.
Then, you will take exactly X pieces of fruit out of each bag, and combine all the fruit into one present.
Return the number of different gifts that may be produced by following the given procedure.
(Two gifts are considered different if they contain a different number of apples or a different number of oranges.)


DEFINITION
Class:WinterAndPresents
Method:getNumber
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long getNumber(vector <int> apple, vector <int> orange)


CONSTRAINTS
-apple will contain between 1 and 50 elements, inclusive.
-orange will contain between 1 and 50 elements, inclusive.
-apple and orange will contain the same number of elements.
-Each element of apple and orange will be between 0 and 1,000,000, inclusive.


EXAMPLES

0)
{1}
{1}

Returns: 3

Three different presents are possible in this case: 


0 apples and 1 orange


1 apple and 0 oranges


1 apple and 1 orange



1)
{1, 2, 0, 3}
{4, 5, 0, 6}

Returns: 0

As there is an empty bag, there is no way to choose the present.

2)
{2, 2, 2}
{2, 2, 2}

Returns: 16



3)
{7, 4, 5}
{1, 10, 2}

Returns: 46



4)
{1000000}
{1000000}

Returns: 1000002000000



******************************/
// END CUT HERE
#line 97 "WinterAndPresents.cpp"
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

class WinterAndPresents {
	public:
	long long getNumber(vector <int> A, vector <int> O) {
		int Mx=1<<30;
		int N=A.size();
		REP(i, N) Mx=min(Mx, A[i]+O[i]);
		ll ans = 0;
		RANGE(X, 1, Mx+1) {
			ll lans=0;
			REP(i, N) {
				int lo=max(X-A[i], 0);
				int hi=min(X, O[i]);
//				cout<<lo<<" "<<hi<<endl;
				lans+=hi-lo;
			}
			ans+=lans+1;
		}
		return ans;
	}
};

class WinterAndPresentsTry {
	public:
	long long getNumber(vector <int> A, vector <int> O) {
		int N=A.size();
		int maxp=10000000;
		REP(i, N) {
			maxp=min(maxp, A[i]+O[i]);
		}
		ll res=0;
		RANGE(p, 1, maxp+1) {
			int num=p*N;
			int numo=0, numa=0;
			REP(i, N) {
				if(O[i]>=p) numo+=p;
				else numo+=O[i];
				if(A[i]>=p) numa+=p;
				else numa+=A[i];
			}
			res += (ll)(-num+numa+numo+1);
		}
		return res;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const long long& Expected, const long long& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, WinterAndPresents().getNumber(apple, orange));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int apple_[] = {1};
	  vector <int> apple(apple_, apple_+sizeof(apple_)/sizeof(*apple_)); 
	int orange_[] = {1};
	  vector <int> orange(orange_, orange_+sizeof(orange_)/sizeof(*orange_)); 
	long long _ = 3LL; 
END
//return 0;
CASE(1)
	int apple_[] = {1, 2, 0, 3};
	  vector <int> apple(apple_, apple_+sizeof(apple_)/sizeof(*apple_)); 
	int orange_[] = {4, 5, 0, 6};
	  vector <int> orange(orange_, orange_+sizeof(orange_)/sizeof(*orange_)); 
	long long _ = 0LL; 
END
CASE(2)
	int apple_[] = {2, 2, 2};
	  vector <int> apple(apple_, apple_+sizeof(apple_)/sizeof(*apple_)); 
	int orange_[] = {2, 2, 2};
	  vector <int> orange(orange_, orange_+sizeof(orange_)/sizeof(*orange_)); 
	long long _ = 16LL; 
END
CASE(3)
	int apple_[] = {7, 4, 5};
	  vector <int> apple(apple_, apple_+sizeof(apple_)/sizeof(*apple_)); 
	int orange_[] = {1, 10, 2};
	  vector <int> orange(orange_, orange_+sizeof(orange_)/sizeof(*orange_)); 
	long long _ = 46LL; 
END
CASE(4)
	int apple_[] = {1000000};
	  vector <int> apple(apple_, apple_+sizeof(apple_)/sizeof(*apple_)); 
	int orange_[] = {1000000};
	  vector <int> orange(orange_, orange_+sizeof(orange_)/sizeof(*orange_)); 
	long long _ = 1000002000000LL; 
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
	vector <int> apple; 
	int N=UNIFORM_LL(1, 50);
	{
		apple = vector <int>(N); 
		REP(i, N) {
			apple[i] = UNIFORM_LL(0, 1000000);
		}
	}
// param type: int
start_time=clock();
	vector <int> orange; 
	{
		orange = vector <int>(N); 
		REP(i, N) {
			orange[i] = UNIFORM_LL(0, 1000000);
		}
	}
	long long _0 = WinterAndPresents().getNumber(apple, orange);
	long long _1 = WinterAndPresentsTry().getNumber(apple, orange);
	if(!verify_case(_0, _1, true)) {
print(apple);
print(orange);
	}
}
#endif

}
// END CUT HERE
