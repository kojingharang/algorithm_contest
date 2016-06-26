// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// There is a country with N cities. The cities are numbered 0 through N-1. There are some bidirectional roads in the country. Each road connects a pair of cities. More precisely, for each i, road i connects the cities A[i] and B[i].

Limit is a deer that likes to travel along the roads. Traveling along road i (in either direction) takes him exactly D[i] minutes. Limit does not like cities, so he never waits in a city.

Limit is currently in the city 0, starting his travels. In exactly T minutes, he wants to be in the city N-1.

You are given the int N; the vector <int>s A, B, and D; and the long long T.
Return "Possible" (quotes for clarity) if Deer Limit can reach city N-1 in exactly T minutes.
Otherwise, return "Impossible".

DEFINITION
Class:LongLongTripDiv1
Method:isAble
Parameters:int, vector <int>, vector <int>, vector <int>, long long
Returns:string
Method signature:string isAble(int N, vector <int> A, vector <int> B, vector <int> D, long long T)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-A will contain between 1 and 50 elements, inclusive.
-A, B and D will each contain the same number of elements.
-Each element in A and B will be between 0 and N-1, inclusive.
-Each element in D will be between 1 and 10,000, inclusive.
-For each valid i, A[i] and B[i] will be different.
-No two roads will connect the same pair of cities.
-T will be between 1 and 10^18, inclusive.


EXAMPLES

0)
3
{0,0,1}
{2,1,2}
{7,6,5}
11

Returns: "Possible"

city 0 -> city 1 -> city 2 is a valid way.

1)
3
{0,0,1}
{2,1,2}
{7,6,5}
25

Returns: "Possible"

city 0 -> city 2 -> city 1 -> city 0 -> city 2 is a valid way.

2)
2
{0}
{1}
{1}
9

Returns: "Possible"

Here, Limit just travels back and forth between cities 0 and 1 along the only road in the country.

3)
2
{1}
{0}
{1}
1000000000000000000

Returns: "Impossible"



4)
4
{0,0,1}
{2,1,2}
{10,10,10}
1000

Returns: "Impossible"

In this test case, there is absolutely no way how to reach city N-1 from city 0.

5)
9
{4,8,5,8,3,6,2,6,7,6,6}
{2,7,1,5,1,3,1,1,5,4,2}
{6580,8822,1968,673,1394,9337,5486,1746,5229,4092,195}
937186357646035002

Returns: "Impossible"



******************************/
// END CUT HERE
#line 104 "LongLongTripDiv1.cpp"
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

class LongLongTripDiv1 {
	public:
	string isAble(int N, vector <int> A, vector <int> B, vector <int> D, long long T) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const string& Expected, const string& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, LongLongTripDiv1().isAble(N, A, B, D, T));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int N = 3; 
	int A_[] = {0,0,1};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,1,2};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int D_[] = {7,6,5};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	long long T = 11LL; 
	string _ = "Possible"; 
END
CASE(1)
	int N = 3; 
	int A_[] = {0,0,1};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,1,2};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int D_[] = {7,6,5};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	long long T = 25LL; 
	string _ = "Possible"; 
END
CASE(2)
	int N = 2; 
	int A_[] = {0};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {1};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int D_[] = {1};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	long long T = 9LL; 
	string _ = "Possible"; 
END
CASE(3)
	int N = 2; 
	int A_[] = {1};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {0};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int D_[] = {1};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	long long T = 1000000000000000000LL; 
	string _ = "Impossible"; 
END
CASE(4)
	int N = 4; 
	int A_[] = {0,0,1};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,1,2};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int D_[] = {10,10,10};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	long long T = 1000LL; 
	string _ = "Impossible"; 
END
CASE(5)
	int N = 9; 
	int A_[] = {4,8,5,8,3,6,2,6,7,6,6};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,7,1,5,1,3,1,1,5,4,2};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int D_[] = {6580,8822,1968,673,1394,9337,5486,1746,5229,4092,195};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	long long T = 937186357646035002LL; 
	string _ = "Impossible"; 
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
	int N = UNIFORM_LL(0, 100); 
// param type: int
	vector <int> A; 
	{
		int N=UNIFORM_LL(1, 51);
		A = vector <int>(N); 
		REP(i, N) {
			A[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> B; 
	{
		int N=UNIFORM_LL(1, 51);
		B = vector <int>(N); 
		REP(i, N) {
			B[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> D; 
	{
		int N=UNIFORM_LL(1, 51);
		D = vector <int>(N); 
		REP(i, N) {
			D[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: long
	long long T = UNIFORM_LL(0, 100); 
	string _0 = LongLongTripDiv1().isAble(N, A, B, D, T);
	string _1 = LongLongTripDiv1Ref().isAble(N, A, B, D, T);
	if(!verify_case(_0, _1, true)) {
print(N);
print(A);
print(B);
print(D);
print(T);
	}
}
#endif

}
// END CUT HERE
