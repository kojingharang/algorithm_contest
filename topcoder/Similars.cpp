// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Given two positive integers x and y, their similarity S(x, y) is defined as follows:
To compute S(x, y) we count all d between 0 and 9, inclusive, such that both x and y contain the digit d when written in base 10 (without any leading zeros).
For example, S(1123, 220181) = 2 since both numbers contain the digit 1 and both contain the digit 2.

You are given two ints L and R that define a range.
Find two distinct integers in this range that have the largest similarity.
Formally, return the maximum of S(a, b) over all a, b such that L <= a < b <= R.

DEFINITION
Class:Similars
Method:maxsim
Parameters:int, int
Returns:int
Method signature:int maxsim(int L, int R)


CONSTRAINTS
-R will be between 2 and 100,000, inclusive.
-L will be between 1 and R - 1, inclusive.


EXAMPLES

0)
1
10

Returns: 1

We have S(1, 10) = 1 since both numbers contain the digit 1. All other pairs of numbers within this range have similarity 0.

1)
1
99

Returns: 2

There are many pairs with similarity 2, for example pairs (23,32) and (38,83).

2)
99
100

Returns: 0

Here we have only one pair (99, 100) and its similarity is 0.

3)
1000
1010

Returns: 2



4)
444
454

Returns: 2



******************************/
// END CUT HERE
#line 70 "Similars.cpp"
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

class Similars {
	public:
	int maxsim(int L, int R) {
		VI w(1024);
		RANGE(n, L, R+1) {
			stringstream ss;
			ss<<n;
			string s = ss.str();
			ll v = 0;
			REP(i, s.size()) v |= 1LL<<(s[i]-'0');
			w[v]++;
		}
//		REP(i, 1024) if(w[i]) cout<<i<<" "<<w[i]<<endl;
		ll ans = 0;
		REP(i, 1024)if(w[i])RANGE(j, i+1, 1024)if(w[j]) {
			ans = max(ans, (ll)POPCOUNTLL(i&j));
		}
		REP(i, 1024)if(w[i]>=2) {
			ans = max(ans, (ll)POPCOUNTLL(i));
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
#define END	 verify_case(_, Similars().maxsim(L, R));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int L = 1; 
	int R = 10; 
	int _ = 1; 
END
CASE(1)
	int L = 1; 
	int R = 99; 
	int _ = 2; 
END
CASE(2)
	int L = 99; 
	int R = 100; 
	int _ = 0; 
END
CASE(3)
	int L = 1000; 
	int R = 1010; 
	int _ = 2; 
END
CASE(4)
	int L = 444; 
	int R = 454; 
	int _ = 2; 
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
// param type: int
	int R = UNIFORM_LL(2, 100001); 
	int L = UNIFORM_LL(1, R); 
	int _0 = Similars().maxsim(L, R);
	int _1 = SimilarsRef().maxsim(L, R);
	if(!verify_case(_0, _1, true)) {
print(L);
print(R);
	}
}
#endif

}
// END CUT HERE
