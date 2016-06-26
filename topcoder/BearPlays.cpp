// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Limak is a little bear who loves to play.
Today he is playing by moving some stones between two piles of stones.
Initially, one of the piles has A and the other has B stones in it.

Limak has decided to perform a sequence of K operations.
In each operation he will double the size of the currently smaller pile.
Formally, if the current pile sizes are labeled X and Y in such a way that X <= Y, he will move X stones from the second pile to the first one.
After this move the new pile sizes will be X+X and Y-X.

You are given the ints A, B, and K.
Determine the pile sizes after Limak finishes all his operations.
Return the size of the smaller of those piles.

Formally, suppose that the final pile sizes are labeled P and Q in such a way that P <= Q.
Return P.

DEFINITION
Class:BearPlays
Method:pileSize
Parameters:int, int, int
Returns:int
Method signature:int pileSize(int A, int B, int K)


NOTES
-Pay attention to the unusual time limit.


CONSTRAINTS
-A and B will be between 1 and 1,000,000,000, inclusive. 
-K will be between 1 and 2,000,000,000, inclusive.


EXAMPLES

0)
4
7
2

Returns: 5

The process will look as follows:

Initially, the pile sizes are 4 and 7.
First operation: Limak doubles the pile of size 4 by moving 4 stones from the other pile to this pile. The new pile sizes are 8 and 3.
Second operation: Limak doubles the pile of size 3. The final pile sizes are 5 and 6.
As 5 <= 6, the correct return value is 5.


1)
5
5
3

Returns: 0

The initial pile sizes are 5 and 5.
In the first operation Limak will double one of them, so after the operation the new pile sizes will be 10 and 0.
The second and third operation do nothing: in each of them Limak doubles the size of an empty pile.

As 0 ≤ 10, the correct return value is 0.

2)
2
6
1

Returns: 4

After the only operation the pile sizes will be 4 and 4, hence the correct return value is 4.

3)
2
8
2000000000

Returns: 2



4)
900000000
350000000
3

Returns: 300000000



******************************/
// END CUT HERE
#line 97 "BearPlays.cpp"
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
#define DD(v) cout<<#v<<": "<<(v)<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class BearPlays {
	public:
	int pileSize(int a, int b, int k) {
		if(a>b) swap(a,b);
		map<PII, int> f;
		int x=a, y=b;
		for(
	}
};
class BearPlaysOre {
	public:
	map<ll, ll> hi;
	int pileSize(int A, int B, int K) {
		if(A>B) swap(A, B);
		int lf=0;
		REP(i, K) {
			if(i>=K)break;
			if(lf==0)
			if(hi.count(A)) {
				if(hi[A]!=-1) {
					int co = i-hi[A];
					int rest=K-(i+1);
					rest %= co;
					K = i+1+rest;
					hi[A]=-1;
					lf=1;
				}
			} else {
				hi[A]=i;
			}
			int t=A;
			A+=t;
			B-=t;
			if(A>B) swap(A, B);
//			cout<<A<<endl;
//			cout<<hi<<endl;
		}
		if(A>B) swap(A, B);
		return A;
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
#define END	 verify_case(_, BearPlays().pileSize(A, B, K));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int A = 4; 
	int B = 7; 
	int K = 2; 
	int _ = 5; 
END
CASE(1)
	int A = 5; 
	int B = 5; 
	int K = 3; 
	int _ = 0; 
END
CASE(2)
	int A = 2; 
	int B = 6; 
	int K = 1; 
	int _ = 4; 
END
CASE(3)
	int A = 2; 
	int B = 8; 
	int K = 2000000000; 
	int _ = 2; 
END
CASE(4)
	int A = 900000000; 
	int B = 350000000; 
	int K = 3; 
	int _ = 300000000; 
END
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
REP(i, 1) {
	int A = UNIFORM_LL(1, 1000000001); 
	int B = UNIFORM_LL(1, 1000000001); 
	int K = UNIFORM_LL(1, 2000000001); 
	DD(A);
	DD(B);
	DD(K);
	verify_case(-1, BearPlays().pileSize(A, B, K));
}
#if 0  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: int
	int A = UNIFORM_LL(0, 100); 
// param type: int
	int B = UNIFORM_LL(0, 100); 
// param type: int
	int K = UNIFORM_LL(0, 100); 
	int _0 = BearPlays().pileSize(A, B, K);
	int _1 = BearPlaysRef().pileSize(A, B, K);
	if(!verify_case(_0, _1, true)) {
print(A);
print(B);
print(K);
	}
}
#endif

}
// END CUT HERE
