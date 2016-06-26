// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// There are N cities in Treeland.
The cities are numbered 1 through N.
The roads in Treeland have the topology of a tree.
That is, there are exactly N-1 bidirectional roads in Treeland, each connecting a pair of cities, and it is possible to travel between any two cities along the roads.
For the purpose of this problem, all roads have the same length, and this length is our unit of distance.

You are given two vector <int>s A and B that describe the tree.
Each of these vector <int>s has N-1 elements.
For each valid i, there is a road that connects the cities A[i] and B[i].

There are some foxes in Treeland.
Currently, each of the foxes lives in a different city.
You are given a string foxes with N characters.
For each i, character i of foxes is 'Y' if there is a fox in city i+1, or 'N' otherwise.

The foxes would like to live closer to each other.
To achieve that, some foxes (possibly all of them or none at all) will move to different cities.
There are three constraints for the move:

After the foxes move, there must again be at most one fox in each city. (There are no restrictions on how the foxes travel while they are moving.)
After the foxes move, the set of cities inhabited by the foxes must be connected. That is, for any two different cities i and j that both contain a fox, all the cities on the (only) path between i and j must also contain a fox.
The total distance traveled by the foxes during the move must be as small as possible.



Return the smallest possible sum of distances traveled by the foxes.

DEFINITION
Class:FoxConnection
Method:minimalDistance
Parameters:vector <int>, vector <int>, string
Returns:int
Method signature:int minimalDistance(vector <int> A, vector <int> B, string haveFox)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-A will contain exactly N-1 elements.
-Each element of A will be between 1 and N, inclusive.
-B will contain exactly N-1 elements.
-Each element of B will be between 1 and N, inclusive.
-The graph described by A and B will be a tree.
-haveFox will contain exactly N characters.
-Each character in haveFox will be either 'Y' or 'N'.


EXAMPLES

0)
{1,2,3}
{2,3,4}
"YNNY"

Returns: 2

Treeland looks as follows: 1-2-3-4. Two foxes are located in city 1 and city 4. One optimal solution is:

The fox located in city 1 moves to city 2.
The fox located in city 4 moves to city 3.


1)
{1,1,1,1}
{2,3,4,5}
"NYYYY"

Returns: 1

We can move any one of the foxes to city 1. After that the cities with foxes will form a connected set.

2)
{1,3,4,5,4}
{2,2,2,4,6}
"YNYNYY"

Returns: 2



3)
{1,2,3,4,5,6,7,8,9}
{2,3,4,5,6,7,8,9,10}
"YNNNYNYNNY"

Returns: 7



4)
{1,2,3,4,3,6,8,7}
{2,3,4,5,6,8,9,6}
"YNNYYNYYY"

Returns: 3



5)
{1}
{2}
"NY"

Returns: 0

There can be only 1 fox.

6)
{1}
{2}
"NN"

Returns: 0

And there can be no foxes.

******************************/
// END CUT HERE
#line 122 "FoxConnection.cpp"
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

class FoxConnection {
	public:
	int minimalDistance(vector <int> A, vector <int> B, string haveFox) {
		
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
#define END	 verify_case(_, FoxConnection().minimalDistance(A, B, haveFox));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int A_[] = {1,2,3};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,3,4};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string haveFox = "YNNY"; 
	int _ = 2; 
END
CASE(1)
	int A_[] = {1,1,1,1};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,3,4,5};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string haveFox = "NYYYY"; 
	int _ = 1; 
END
CASE(2)
	int A_[] = {1,3,4,5,4};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,2,2,4,6};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string haveFox = "YNYNYY"; 
	int _ = 2; 
END
CASE(3)
	int A_[] = {1,2,3,4,5,6,7,8,9};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,3,4,5,6,7,8,9,10};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string haveFox = "YNNNYNYNNY"; 
	int _ = 7; 
END
CASE(4)
	int A_[] = {1,2,3,4,3,6,8,7};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,3,4,5,6,8,9,6};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string haveFox = "YNNYYNYYY"; 
	int _ = 3; 
END
CASE(5)
	int A_[] = {1};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string haveFox = "NY"; 
	int _ = 0; 
END
CASE(6)
	int A_[] = {1};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string haveFox = "NN"; 
	int _ = 0; 
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
	vector <int> A; 
	{
		int N=UNIFORM_LL(1, 50);
		A = vector <int>(N); 
		REP(i, N) {
			A[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
start_time=clock();
	vector <int> B; 
	{
		int N=UNIFORM_LL(1, 50);
		B = vector <int>(N); 
		REP(i, N) {
			B[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: String
start_time=clock();
	string haveFox; 
	{
		int N=UNIFORM_LL(1, 50);
		haveFox = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			haveFox[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	int _0 = FoxConnection().minimalDistance(A, B, haveFox);
	int _1 = FoxConnectionTry().minimalDistance(A, B, haveFox);
	if(!verify_case(_0, _1, true)) {
print(A);
print(B);
print(haveFox);
	}
}
#endif

}
// END CUT HERE
