// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// You have a long thin cake. For simplicity, we can consider the cake to be one-dimensional. The length of the cake is n. 

You are expecting some friends. You are going to cut the cake into multiple pieces before the friends arrive.

When the friends arrive, you will divide the cake among them, using the following procedure: starting at the beginning of the cake, you will first give some consecutive pieces to your first friend, then some consecutive pieces to your second friend, and so on.

Of course, you want to be fair. That is, each of your friends should receive the same total amount of cake. (The number of pieces may be different for different friends, but the sum of their lengths must be the same.)

As we stated above, you want to cut the cake before your friends arrive. However, you don't know how many friends will actually come. You only know that their count will be a divisor of n smaller than n.

You are given the int n. You want to cut the cake in such a way that for each valid number of friends it will be possible to give each of them the same amount of cake when using the above procedure. Return the smallest possible number of pieces after you cut the cake.

DEFINITION
Class:MyLongCake
Method:cut
Parameters:int
Returns:int
Method signature:int cut(int n)


CONSTRAINTS
-n will be between 2 and 100,000, inclusive.


EXAMPLES

0)
6

Returns: 4

The best possible solution is to cut the cake into 4 pieces. Let's call the pieces A, B, C, and D, in order. Their lengths will be 2, 1, 1, and 2.

As n=6, there will be 1, 2, or 3 friends. If there is just one friend, she gets all four pieces. If there are two friends, the first gets A+B and the second gets C+D. If there are three friends, the first gets A, the second gets B+C, and the third gets D.

Note that the order of parts matters. For example, dividing the cake into parts of length 2, 1, 2, and 1 is not a valid solution.

1)
3

Returns: 1



2)
15

Returns: 7

You are expecting 1, 3, or 5 friends.

3)
100000

Returns: 60000



******************************/
// END CUT HERE
#line 65 "MyLongCake.cpp"
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

class MyLongCake {
	public:
	int cut(int n) {
		int v = n;
		VI w;
		map<int, int> hi;
		RANGE(i, 1, v) {
			if(v%i==0) {
				w.PB(i);
				int step = v / i;
				for(int j=0;j<v;j+=step) hi[j]=1;
			}
		}
//		cout<<w<<endl;
		return hi.size();
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
#define END	 verify_case(_, MyLongCake().cut(n));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

RANGE(i, 40000, 100000) {
CASE(0)
//	cout<<MyLongCake().cut(i)<<endl;
	int n=i;
	int _=0;
END
}
return 0;

CASE(0)
	int n = 6; 
	int _ = 4; 
END
CASE(1)
	int n = 3; 
	int _ = 1; 
END
CASE(2)
	int n = 15; 
	int _ = 7; 
END
CASE(3)
	int n = 100000; 
	int _ = 60000; 
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
	int n = UNIFORM_LL(0, 100); 
	int _0 = MyLongCake().cut(n);
	int _1 = MyLongCakeRef().cut(n);
	if(!verify_case(_0, _1, true)) {
print(n);
	}
}
#endif

}
// END CUT HERE
