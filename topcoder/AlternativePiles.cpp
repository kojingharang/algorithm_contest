// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Slow loris Guts is playing with N cards, numbered 0 through N-1. Each card has one of four colors: red, green, blue, or white. You are given the card colors as the string C. For each i, character i of C is one of 'R' (red), 'G' (green), 'B' (blue), and 'W' (white).

You are also given an int M.

Guts wants to color each white card red, green, or blue in such a way that the number of cards not colored blue is exactly 2*D*M for some non-negative integer D. Additionally, there must be exactly M sequences of integers S_0 through S_{M-1} with the following properties:


For each i, the sequence S_i contains exactly 2*D integers, each of them between 0 and N-1, inclusive.
For each i, the sequence S_i is strictly increasing. That is, S_i[0] < S_i[1] < ... < S_i[2*D-1].
For each i and each even j, the card S_i[j] is red.
For each i and each odd j, the card S_i[j] is green.
No two sequences share a common element. Hence, for each index x of a non-blue card there is precisely one pair (i,j) such that S_i[j]=x.

Return the number of valid ways to color all white cards, modulo 1,000,000,007.

DEFINITION
Class:AlternativePiles
Method:count
Parameters:string, int
Returns:int
Method signature:int count(string C, int M)


CONSTRAINTS
-C will contain between 1 and 5,000 characters, inclusive.
-Each character of C will be 'R', 'G', 'B' or 'W'.
-M will be between 1 and 50, inclusive.


EXAMPLES

0)
"WRGWWRGW"
2

Returns: 3

There are three valid colorings: "RRGRGRGG", "RRGGRRGG", and "BRGBBRGB".

For "RRGRGRGG", we have D=2 and one possibility is to select S_0 = {0,2,3,7} and S_1 = {1,4,5,6}.

For "BRGBBRGB", we have D=1 and to show that this is a valid coloring we let S_0 = {5,6} and S_1 = {1,2}.

1)
"RRGG"
1

Returns: 0

There is no valid way.

2)
"BBBB"
5

Returns: 1

Note that D can be zero. Also, note that even though there are no white cards in this test case, there is a valid way to color all white cards: we do nothing and keep the colors we currently have.

3)
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
50

Returns: 265470435

Do not forget to calculate the answer modulo 10^9 + 7.

4)
"WRWRGWWGWWWRWBWRWGWWRWBWWRGWBWGRGWWGWGRWGRWBRWBW"
7

Returns: 7400348



******************************/
// END CUT HERE
#line 82 "AlternativePiles.cpp"
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

class AlternativePiles {
	public:
	int count(string C, int M) {
		
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
#define END	 verify_case(_, AlternativePiles().count(C, M));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string C = "WRGWWRGW"; 
	int M = 2; 
	int _ = 3; 
END
CASE(1)
	string C = "RRGG"; 
	int M = 1; 
	int _ = 0; 
END
CASE(2)
	string C = "BBBB"; 
	int M = 5; 
	int _ = 1; 
END
CASE(3)
	string C = "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"; 
	int M = 50; 
	int _ = 265470435; 
END
CASE(4)
	string C = "WRWRGWWGWWWRWBWRWGWWRWBWWRGWBWGRGWWGWGRWGRWBRWBW"; 
	int M = 7; 
	int _ = 7400348; 
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
// param type: String
	string C; 
	{
		int N=UNIFORM_LL(1, 51);
		C = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			C[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
// param type: int
	int M = UNIFORM_LL(0, 100); 
	int _0 = AlternativePiles().count(C, M);
	int _1 = AlternativePilesRef().count(C, M);
	if(!verify_case(_0, _1, true)) {
print(C);
print(M);
	}
}
#endif

}
// END CUT HERE
