// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// We are interested in pairs of strings (A, B) that satisfy the following conditions: 

A and B consist of exactly n characters each. 
Each character in A and B is one of the first k lowercase letters of the English alphabet. 
There exists a string C such that A + C = C + B. Here, + denotes string concatenation. 

For example, if n = 3 and k = 4 then one valid pair of strings is ("aad", "daa"): 
both strings have length 3, only the first 4 letters are used in each of them, and C = "aa" shows that the third condition is satisfied as well. 

You are given the ints n and k. 
Find the number of such pairs of strings, and return the number modulo 1,000,000,007. 


DEFINITION
Class:PairsOfStrings
Method:getNumber
Parameters:int, int
Returns:int
Method signature:int getNumber(int n, int k)


CONSTRAINTS
-n will be between 1 and 1,000,000,000, inclusive. 
-k will be between 1 and 26, inclusive. 


EXAMPLES

0)
2
2

Returns: 6

The following 6 pairs satisfy the conditions: 
("aa", "aa"), ("ab", "ab"), ("ab", "ba"), ("ba", "ab"), ("ba", "ba"), ("bb", "bb"). 

1)
3
2

Returns: 20



2)
3
4

Returns: 184



3)
6
2

Returns: 348



4)
100
26

Returns: 46519912



******************************/
// END CUT HERE
#line 76 "PairsOfStrings.cpp"
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

class PairsOfStrings {
	public:
	int getNumber(int n, int k) {
		
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
#define END	 verify_case(_, PairsOfStrings().getNumber(n, k));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int n = 2; 
	int k = 2; 
	int _ = 6; 
END
CASE(1)
	int n = 3; 
	int k = 2; 
	int _ = 20; 
END
CASE(2)
	int n = 3; 
	int k = 4; 
	int _ = 184; 
END
CASE(3)
	int n = 6; 
	int k = 2; 
	int _ = 348; 
END
CASE(4)
	int n = 100; 
	int k = 26; 
	int _ = 46519912; 
END
#if 0  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10;loop++) {
// param type: int
start_time=clock();
	int n = UNIFORM_LL(0, 100); 
// param type: int
start_time=clock();
	int k = UNIFORM_LL(0, 100); 
	int _0 = PairsOfStrings().getNumber(n, k);
	int _1 = PairsOfStringsTry().getNumber(n, k);
	if(!verify_case(_0, _1, true)) {
print(n);
print(k);
	}
}
#endif

}
// END CUT HERE
