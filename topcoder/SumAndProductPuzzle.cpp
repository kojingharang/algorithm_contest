// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Consider the following story.



STORY STARTS HERE.



There were three mathematicians: Susan, Priscilla, and Bob.
Bob picked two positive integers x and y such that x <= y.
He then told their sum to Susan and their product to Priscilla.
Susan and Priscilla both knew all the facts listed above.
Then, Susan and Priscilla made the following statements:

Susan: "I am certain that you cannot determine my number."
Priscilla: "Thanks for telling me that. Now I'm sure that your number is S."




STORY ENDS HERE.



My friends Baska and Olivia are fond of puzzles.
Recently, Baska told Olivia the above story.
When telling the story, Baska used some specific positive integer (for example, 9) instead of S.
Then, she asked Olivia to determine x and y.
Olivia easily came up with the unique solution.



Of course, you don't know the integer Baska used instead of S.
Instead, you are given two ints A and B.
Find all S between A and B, inclusive, such that the above discussion between Baska and Olivia could have happened.
Return the sum of all such S.


DEFINITION
Class:SumAndProductPuzzle
Method:getSum
Parameters:int, int
Returns:long long
Method signature:long long getSum(int A, int B)


NOTES
-Watch out for overflow. The return value may overflow a 32-bit integer variable.


CONSTRAINTS
-A will be between 1 and 5,000,000, inclusive.
-B will be between A and 5,000,000, inclusive.


EXAMPLES

0)
30
33

Returns: 33

The only valid S in this range is 33.
The unique pair (x,y) that corresponds to S=33 is (1,32).

1)
8
11

Returns: 19



2)
40
43

Returns: 0

Sometimes the given range doesn't contain any valid S. In such case the correct return value is 0.

3)
47
74

Returns: 168



4)
1
2

Returns: 0



******************************/
// END CUT HERE
#line 106 "SumAndProductPuzzle.cpp"
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

// 1.4sec(arena)
class SumAndProductPuzzle {
	public:
	long long getSum(int A, int B) {
//		const int N = 5000000; // N=Bにすると最大1.9s. N=5000000にすると最大1.4s
		int N=B;
		vector<bool> isp(N+1, true);
		RANGE(p, 2, N+1) if(isp[p])for(int q=p*2;q<N+1;q+=p) isp[q]=false;
		vector<int> cnt(N+1);
		RANGE(p, 1, N+1) RANGE(q, p, N/p+1) if(!isp[p+q-1]) cnt[p*q]++;
		ll ans=0;
		RANGE(S, A, B+1) if(!isp[S-1] && cnt[S-1]==1) ans+=S;
		return ans;
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
#define END	 verify_case(_, SumAndProductPuzzle().getSum(A, B));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int A = 30; 
	int B = 33; 
	long long _ = 33LL; 
END
//return 0;
CASE(1)
	int A = 8; 
	int B = 11; 
	long long _ = 19LL; 
END
CASE(2)
	int A = 40; 
	int B = 43; 
	long long _ = 0LL; 
END
CASE(3)
	int A = 47; 
	int B = 74; 
	long long _ = 168LL; 
END
CASE(4)
	int A = 1; 
	int B = 2; 
	long long _ = 0LL; 
END
//return 0;
CASE(0)
	int A = 1; 
	int B = 5000000; 
	long long _ = 392026464258LL; 
END
return 0;
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
	int A = UNIFORM_LL(0, 100); 
// param type: int
	int B = UNIFORM_LL(0, 100); 
	long long _0 = SumAndProductPuzzle().getSum(A, B);
	long long _1 = SumAndProductPuzzleRef().getSum(A, B);
	if(!verify_case(_0, _1, true)) {
print(A);
print(B);
	}
}
#endif

}
// END CUT HERE
