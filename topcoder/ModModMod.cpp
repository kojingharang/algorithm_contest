// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Moose Mod has just learned about the mod operator.
Given two positive integers x and y, the mod operator returns the remainder when x is divided by y.
For example, 17 mod 5 = 2 because 17 = 3*5 + 2.



Moose Mod has just defined a function that applies a sequence of N mod operators to its input.
Formally, the function looks as follows:
f(x) = (((x mod m[0]) mod m[1]) ... mod m[N-1]).
For example, m = { 10, 3 } corresponds to the function f(x) = (x mod 10) mod 3.
For this function we have f(18) = (18 mod 10) mod 3 = 8 mod 3 = 2.



You are given the vector <int> m.
You are also given a int R.
Moose Mod is interested in finding the sum f(1) + f(2) + ... + f(R).
Compute and return its value.


DEFINITION
Class:ModModMod
Method:findSum
Parameters:vector <int>, int
Returns:long long
Method signature:long long findSum(vector <int> m, int R)


CONSTRAINTS
-m will have between 1 and 5,000 elements, inclusive.
-Each element of m will be between 1 and 10,000,000, inclusive.
-R will be between 1 and 10,000,000, inclusive.


EXAMPLES

0)
{5,3,2}
10

Returns: 4

The values of f from 1 to 10 are 1, 0, 0, 1, 0, 1, 0, 0, 1, 0. The sum of all these values is 4.

1)
{33, 15, 7, 10, 100, 9, 5}
64

Returns: 92



2)
{995,149,28,265,275,107,555,241,702,462,519,212,362,478,783,381,602,546,183,886,59,317,977,612,328,91,771,131}
992363

Returns: 12792005



3)
{100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}
100

Returns: 4950



4)
{2934}
10000000

Returns: 14664070144



******************************/
// END CUT HERE
#line 91 "ModModMod.cpp"
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

class ModModMod {
	public:
	long long findSum(vector <int> m, int R) {
		vector<int> w(R+1, 1);
		int N=m.size();
		int mx=R*2;
		int upto=R;
		REP(i, N) {
			if(m[i]<mx) {
				mx=m[i];
				RANGE(j, m[i], upto+1) {
					w[j%m[i]] += w[j];
					w[j] = 0;
				}
				upto = m[i]-1;
//				cout<<w<<endl;
			}
		}
		ll ans = 0;
		REP(i, upto+1) ans += w[i]*i;
		return ans;
	}
};
//class ModModMod {
//	public:
//	void add(map<ll, ll>& na, PII p) {
//		if(p.first==0) return;
//		na[p.first]+=p.second;
//	}
//	long long findSum(vector <int> m, int R) {
//		map<ll, ll> a;
//		a[R] = 1;
//		int N=m.size();
//		int mx=R*2;
//		REP(i, N) {
//			if(m[i]<mx) {
//				mx=m[i];
//				map<ll, ll> na;
//				for(auto& kv : a) {
//					if(kv.first >= m[i]) {
//						add(na, MP(m[i]-1, kv.first/m[i]*kv.second));
//						add(na, MP(kv.first%m[i], kv.second));
//					} else {
//						add(na, kv);
//					}
//				}
//				a = na;
//			}
//		}
//		cout<<a.size()<<endl;
//		cout<<a<<endl;
//		ll ans = 0;
//		for(auto& kv : a) ans += kv.first*(kv.first+1)/2*kv.second;
//		return ans;
//	}
//};

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
#define END	 verify_case(_, ModModMod().findSum(m, R));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int m_[] = {5,3,2};
	  vector <int> m(m_, m_+sizeof(m_)/sizeof(*m_)); 
	int R = 10; 
	long long _ = 4LL; 
END
//return 0;
CASE(1)
	int m_[] = {33, 15, 7, 10, 100, 9, 5};
	  vector <int> m(m_, m_+sizeof(m_)/sizeof(*m_)); 
	int R = 64; 
	long long _ = 92LL; 
END
//return 0;
CASE(2)
	int m_[] = {995,149,28,265,275,107,555,241,702,462,519,212,362,478,783,381,602,546,183,886,59,317,977,612,328,91,771,131};
	  vector <int> m(m_, m_+sizeof(m_)/sizeof(*m_)); 
	int R = 992363; 
	long long _ = 12792005LL; 
END
CASE(3)
	int m_[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
	  vector <int> m(m_, m_+sizeof(m_)/sizeof(*m_)); 
	int R = 100; 
	long long _ = 4950LL; 
END
CASE(4)
	int m_[] = {2934};
	  vector <int> m(m_, m_+sizeof(m_)/sizeof(*m_)); 
	int R = 10000000; 
	long long _ = 14664070144LL; 
END
CASE(4)
	  vector <int> m(5000); 
	  REP(i, 5000) m[i]=max(10000, 10000000-1-i*(i+1)/2);
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
//	  REP(i, 5000) m[i]=UNIFORM_LL(10000000-10000, 10000000);
	int R = 10000000; 
	long long _ = 14664070144LL; 
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
	vector <int> m; 
	{
		int N=UNIFORM_LL(1, 51);
		m = vector <int>(N); 
		REP(i, N) {
			m[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int R = UNIFORM_LL(0, 100); 
	long long _0 = ModModMod().findSum(m, R);
	long long _1 = ModModModRef().findSum(m, R);
	if(!verify_case(_0, _1, true)) {
print(m);
print(R);
	}
}
#endif

}
// END CUT HERE
