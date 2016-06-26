// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Garth likes apples and oranges. Recently he bought N fruits, where each fruit was either an apple or an orange. Then he ate all N fruits in some order. You are given an int K. Garth observed that at every point in time, if he made a list of the last K fruits he ate, there were at most K/2 (rounded down) apples in this list.


For each valid i, you know that the info[i]-th fruit Garth ate was an apple. (Fruits Garth ate are numbered starting from 1. For example, info[i]=1 means that the very first fruit Garth ate was an apple.)


Please find and return the maximum number of apples Garth could have eaten.

DEFINITION
Class:ApplesAndOrangesEasy
Method:maximumApples
Parameters:int, int, vector <int>
Returns:int
Method signature:int maximumApples(int N, int K, vector <int> info)


NOTES
-If Garth makes his list at a point in time when he ate fewer than K fruits, his list will have fewer than K fruits but the requirement will still be the same: there have to be at most K/2 apples in the list.


CONSTRAINTS
-N will be between 2 and 2,000, inclusive.
-K will be between 2 and N, inclusive.
-info will contain between 0 and N elements, inclusive.
-Each element of info will be between 1 and N, inclusive.
-The elements of info will be distinct.
-The elements of info will be consistent with Garth's observation.


EXAMPLES

0)
3
2
{}

Returns: 2

Garth ate N=3 fruites. The requirement is that any K=2 consecutive fruits may contain at most K/2 = 1 apple. As info is empty, you have no additional information about the fruits Garth ate.


Garth might have eaten an apple, then an orange, then an apple. This satisfies the conditions:

After eating the 1st fruit, the list is [apple].
After eating the 2nd fruit, the list is [apple, orange].
After eating the 3rd fruit, the list is [orange, apple].

Each list contains at most 1 apple.

1)
10
3
{3, 8}

Returns: 2

All fruits, except for the 3rd and the 8th, must have been oranges.

2)
9
4
{1, 4}

Returns: 5



3)
9
4
{2, 4}

Returns: 4



4)
23
7
{3, 2, 9, 1, 15, 23, 20, 19}

Returns: 10



******************************/
// END CUT HERE
#line 92 "ApplesAndOrangesEasy.cpp"
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


template<typename T>
struct BIT {
  vector<T> w;
  BIT(int N) { w = vector<T>(N); }
  // sum of w[i], i in [l, r]
  T sum(int l, int r) {
    if(l==0) {
      T s=0;
      for(;r>=0;r=(r&(r+1))-1) s+=w[r];
      return s;
    }
    return sum(0, r) - sum(0, l-1);
  }
  // i in [0, N)
  void add(int i, T v) {
    for(;i<(int)w.size();i|=i+1) w[i] += v;
  }
};

class ApplesAndOrangesEasy {
	public:
	int maximumApples(int N, int K, vector <int> info) {
		VI w(N), sum(N); // sum of [i-K+1, i]
		REP(i, info.size()) w[info[i]-1]=1;
		REP(i, N) RANGE(j, max(0, i-K+1), i+1) sum[i]+=w[j];
		ll ans=info.size();
		REP(i, N) if(!w[i]) {
			bool ok=true;
			RANGE(j, i, min(N, i+K)) if(sum[j]>=K/2) ok=false;
			if(!ok) continue;
			ans++;
			RANGE(j, i, min(N, i+K)) sum[j]++;
		}
		return ans;
	}
};
 
 
class ApplesAndOrangesEasy_ {
  public:
  int maximumApples(int N, int K, vector <int> info) {
    VI w(N), m(N);
    REP(i, info.size()) w[info[i]-1]=1;
//    cout<<w<<endl;
    BIT<int> bit(N+1);
    REP(i, N) bit.add(i, w[i]);
//	REP(i, N) cout<<"i "<<bit.sum(i, i)<<endl;
//	return 0;

	ll ans=0;
    REP(i, N) {
		if(w[i]) {
			ans++;
			continue;
		}
		bool ok=true;
		RANGE(j, i-K+1, i+1) {
			if(bit.sum(j, min<ll>(N-1, j+K-1)) >= K/2) {
//				cout<<"sum exceeds: ["<<j<<" "<<j+K-1<<"] "<<bit.sum(j, j+K-1)<<endl;
				ok=false;
				break;
			}
		}
//		cout<<i<<" "<<(ok?"add":"-")<<endl;
		if(ok) {
			ans++;
			bit.add(i, 1);
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
#define END	 verify_case(_, ApplesAndOrangesEasy().maximumApples(N, K, info));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int N = 3; 
	int K = 2; 
	vector <int> info; 
	int _ = 2; 
END
CASE(1)
	int N = 10; 
	int K = 3; 
	int info_[] = {3, 8};
	  vector <int> info(info_, info_+sizeof(info_)/sizeof(*info_)); 
	int _ = 2; 
END
CASE(2)
	int N = 9; 
	int K = 4; 
	int info_[] = {1, 4};
	  vector <int> info(info_, info_+sizeof(info_)/sizeof(*info_)); 
	int _ = 5; 
END
CASE(3)
	int N = 9; 
	int K = 4; 
	int info_[] = {2, 4};
	  vector <int> info(info_, info_+sizeof(info_)/sizeof(*info_)); 
	int _ = 4; 
END
CASE(4)
	int N = 23; 
	int K = 7; 
	int info_[] = {3, 2, 9, 1, 15, 23, 20, 19};
	  vector <int> info(info_, info_+sizeof(info_)/sizeof(*info_)); 
	int _ = 10; 
END
//return 0;
CASE(4)
	int N = 2000; 
	int K = 2000; 
	int info_[] = {3, 2, 9, 1, 15, 23, 20, 19};
	  vector <int> info(info_, info_+sizeof(info_)/sizeof(*info_)); 
	int _ = 10; 
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
	int N = UNIFORM_LL(0, 100); 
// param type: int
	int K = UNIFORM_LL(0, 100); 
// param type: int
	vector <int> info; 
	{
		int N=UNIFORM_LL(1, 51);
		info = vector <int>(N); 
		REP(i, N) {
			info[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = ApplesAndOrangesEasy().maximumApples(N, K, info);
	int _1 = ApplesAndOrangesEasyRef().maximumApples(N, K, info);
	if(!verify_case(_0, _1, true)) {
print(N);
print(K);
print(info);
	}
}
#endif

}
// END CUT HERE
