// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Alice and Kirito just played a game.
The game consisted of a finite (possibly empty) sequence of turns.
You do not know the exact number of turns.
The turns were numbered starting from 1.
In each turn, exactly one of our two players won.
The winner of turn i scored 2*i-1 points.



You are given two long longs x and y.
Find out whether it is possible that at the end of the game Alice had exactly x points and Kirito had exactly y points.
If it is possible, return the smallest number of turns Alice could have won.
If the given final result is not possible, return -1 instead.


DEFINITION
Class:AliceGame
Method:findMinimumValue
Parameters:long long, long long
Returns:long long
Method signature:long long findMinimumValue(long long x, long long y)


CONSTRAINTS
-x and y are between 0 and 1,000,000,000,000, inclusive.


EXAMPLES

0)
8
17

Returns: 2

This final result is possible.
Alice must have won at least two turns.
One possibility is that Alice won turns 2 and 3 (for 3+5 = 8 points) and Kirito won turns 1, 4, and 5 (for 1+7+9 = 17 points).

1)
17
8

Returns: 3



2)
0
0

Returns: 0



3)
9
9

Returns: -1



4)
500000
500000

Returns: 294



******************************/
// END CUT HERE
#line 79 "AliceGame.cpp"
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

class AliceGame {
	public:
	long long findMinimumValue(long long x, long long y) {
		/*
		1 3 5 7 9
		9 11 13 ... 21
		*/
		ll r = sqrt(x+y);
		if(r*r!=x+y) return -1;
		REP(i, r+1) {
			if(i%2!=x%2) continue;
			ll Min = (ll)i*i;
			ll Max = r*r-(r-(i))*(r-(i));
			if(Min<=x && x<=Max) return i;
		}
		return -1;
	}
};

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
#define END	 verify_case(_, AliceGame().findMinimumValue(x, y));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	long long x = 2LL; 
	long long y = 23LL; 
	long long _ = -1LL; 
END
CASE(0)
	long long x = 87LL; 
	long long y = 34LL; 
	long long _ = 7LL; 
END
CASE(0)
	long long x = 8LL; 
	long long y = 17LL; 
	long long _ = 2LL; 
END
//return 0;
CASE(1)
	long long x = 17LL; 
	long long y = 8LL; 
	long long _ = 3LL; 
END
CASE(2)
	long long x = 0LL; 
	long long y = 0LL; 
	long long _ = 0LL; 
END
CASE(3)
	long long x = 9LL; 
	long long y = 9LL; 
	long long _ = -1LL; 
END
CASE(4)
	long long x = 500000LL; 
	long long y = 500000LL; 
	long long _ = 294LL; 
END
CASE(4)
	long long x = 500000000000LL; 
	long long y = 500000000000LL; 
	long long _ = 292894LL; 
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
for(int loop=0;loop<1000;loop++) {
// param type: long
	long long x = UNIFORM_LL(0, 1000000000001LL); 
// param type: long
	long long y = UNIFORM_LL(0, 1000000000001LL); 
	long long _0 = AliceGame().findMinimumValue(x, y);
	long long _1 = AliceGameRef().findMinimumValue(x, y);
	if(!verify_case(_0, _1, true)) {
print(x);
print(y);
	}
}
#endif

}
// END CUT HERE
