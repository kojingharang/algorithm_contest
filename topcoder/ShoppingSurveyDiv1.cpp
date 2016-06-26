// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
A store sells M different items, conveniently numbered 0 through M-1.
For a shopping survey you interviewed N customers.
Each customer responded to the survey with a list of items they've bought.
Each customer bought at most one of each item.
It is possible that some customers did not buy anything at all.



After collecting the responses, you've summed up the results and found that s[i] people have bought item i.
Due to an unfortunate accident, you've then lost the actual survey responses.
All you have left are the values s[i] you computed.



You are now supposed to report the number of big shoppers among the survey respondents.
A big shopper is defined as a customer who has bought K or more items.
Of course, having lost the detailed responses, you might be unable to determine the actual number of big shoppers.



You are given the ints N and K, and the vector <int> s with M elements.
Compute and return the smallest possible number of big shoppers.


DEFINITION
Class:ShoppingSurveyDiv1
Method:minValue
Parameters:int, int, vector <int>
Returns:int
Method signature:int minValue(int N, int K, vector <int> s)


CONSTRAINTS
-N will be between 1 and 500, inclusive.
-s will contain between 1 and 500 elements, inclusive.
-Each element in s will be between 0 and N, inclusive.
-K will be between 1 and the length of s, inclusive.


EXAMPLES

0)
10
2
{1, 2, 3}

Returns: 0

There are 10 customers.
Item 0 was bought by 1 customer, item 1 by 2 customers, and item 2 by 3 of the customers.
A big shopper is a customer who bought at least 2 items.
Given this data it is possible that there are no big shoppers at all.
(There could have been six customers who bought one item each, and four other customers who didn't buy anything at all.)

1)
5
2
{1, 2, 3}

Returns: 1



2)
4
4
{4, 4, 4, 2}

Returns: 2



3)
20
3
{1, 10, 3, 4, 8, 15, 3, 16, 18, 2, 7, 3}

Returns: 10



4)
4
2
{1, 2, 1, 1, 3, 1, 2, 2, 1, 2, 1}

Returns: 2



5)
2
3
{1, 1, 1, 2}

Returns: 1



*/
// END CUT HERE
#line 107 "ShoppingSurveyDiv1.cpp"

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
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }



class ShoppingSurveyDiv1 {
	public:
	int minValue(int N, int K, vector <int> s) {
		int M=s.size();
		ll lo=-1,hi=N;
		while(lo+1<hi) {
			ll ans=(lo+hi)/2;
//		REP(ans, N+1) {
			map<ll, ll> co;
			co[0]=N-ans;
			REP(i, M) {
				map<ll, ll> add;
				ll rest = max<ll>(0, s[i]-ans);
				FOR(e, co) {
					if(rest==0) break;
					ll use = min<ll>(e->second, rest);
	//				cout<<"use "<<use<<" for "<<e->first<<endl;
					e->second -= use;
					add[e->first+1] += use;
					rest-=use;
				}
				FOR(e, add) co[e->first]+=e->second;
	//			cout<<i<<" "<<s[i]<<" "<<co<<endl;
				assert(rest==0);
			}
			int ok=1;
			FOR(e, co) if(e->first>=K) ok=0;
			if(ok) hi=ans; else lo=ans;
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
#define END	 verify_case(_, ShoppingSurveyDiv1().minValue(N, K, s));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int N = 10; 
	int K = 2; 
	int s_[] = {1, 2, 3};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 0; 
END
CASE(1)
	int N = 5; 
	int K = 2; 
	int s_[] = {1, 2, 3};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 1; 
END
CASE(2)
	int N = 4; 
	int K = 4; 
	int s_[] = {4, 4, 4, 2};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 2; 
END
CASE(3)
	int N = 20; 
	int K = 3; 
	int s_[] = {1, 10, 3, 4, 8, 15, 3, 16, 18, 2, 7, 3};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 10; 
END
CASE(4)
	int N = 4; 
	int K = 2; 
	int s_[] = {1, 2, 1, 1, 3, 1, 2, 2, 1, 2, 1};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 2; 
END
CASE(5)
	int N = 2; 
	int K = 3; 
	int s_[] = {1, 1, 1, 2};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 1; 
END
CASE(5)
	int N = 500; 
	int K = 3; 
	int s_[] = {
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	500,500,500,500,500,500,500,500,500,500,
	};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	  REP(i, 500) s[i]=500;
	int _ = 500; 
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
	int N = UNIFORM_LL(0, 50); 
// param type: int
	int K = UNIFORM_LL(0, N+1); 
// param type: int
	vector <int> s; 
	{
		int M=UNIFORM_LL(1, 50);
		s = vector <int>(M); 
		REP(i, M) {
			s[i] = UNIFORM_LL(0, N+1);
		}
	}
	int _0 = ShoppingSurveyDiv1().minValue(N, K, s);
	int _1 = ShoppingSurveyDiv1Ref().minValue(N, K, s);
	if(!verify_case(_0, _1, true)) {
print(N);
print(K);
print(s);
	}
}
#endif

}
// END CUT HERE
