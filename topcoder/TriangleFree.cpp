// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// You are given an undirected graph with n vertices numbered 0 through n-1.
For each valid i, there is an undirected edge connecting two different vertices x[i] and y[i].
No two edges connect the same pair of vertices. 

A triangle is a set of three distinct vertices such that each pair of those vertices is connected by an edge.
Formally, three distinct vertices u,v,w are a triangle if the graph contains the edges (u,v), (v,w), and (w,u). 

The graph has 2^n subsets of vertices (including the empty set).
A subset S of vertices is called triangle-free if and only if no three vertices in S form a triangle. 

You are given the description of the graph: the int n and the vector <int>s x and y.
Compute and return the number of triangle-free subsets of vertices of the given graph. 


DEFINITION
Class:TriangleFree
Method:count
Parameters:int, vector <int>, vector <int>
Returns:long long
Method signature:long long count(int n, vector <int> x, vector <int> y)


CONSTRAINTS
-n will be between 1 and 60, inclusive.
-x will have between 0 and 60 elements, inclusive.
-y will have the same number of elements as x.
-Each element of x and y will be between 0 and n-1, inclusive.
-For each valid i, x[i] != y[i].
-No two edges will connect the same pair of vertices.


EXAMPLES

0)
4
{0,1,2,3}
{1,2,0,2}

Returns: 14

There are 2^4 = 16 subsets in total. Two of them are not triangle-free: {0,1,2} and {0,1,2,3}.


1)
5
{0,0,0,0,1,1,1,2,2,3}
{1,2,3,4,2,3,4,3,4,4}

Returns: 16

This is a complete graph. Any subset having more than two vertices is not triangle-free.

2)
6
{0,0,1,1,1,3,1,2,2,4}
{1,2,2,3,4,4,5,4,5,5}

Returns: 40



3)
60
{10,20,30}
{20,30,10}

Returns: 1008806316530991104



4)
60
{0,0,1,0,0,3,0,0,5,0,0,7,0,0,9,0,0,11,0,0,13,0,0,15,0,0,17,0,0,19,0,0,21,0,0,23,0,0,25,0,0,27,0,0,29,5,2,23,5,20,27,26,22,19,18,13,15,12,7,9}
{1,2,2,3,4,4,5,6,6,7,8,8,9,10,10,11,12,12,13,14,14,15,16,16,17,18,18,19,20,20,21,22,22,23,24,24,25,26,26,27,28,28,29,30,30,1,12,27,22,1,14,5,27,27,15,15,29,7,6,3}

Returns: 578333426763956224



******************************/
// END CUT HERE
#line 86 "TriangleFree.cpp"
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

class TriangleFree {
	public:
	long long count(int n, vector <int> x, vector <int> y) {
		
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
#define END	 verify_case(_, TriangleFree().count(n, x, y));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int n = 4; 
	int x_[] = {0,1,2,3};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {1,2,0,2};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	long long _ = 14LL; 
END
CASE(1)
	int n = 5; 
	int x_[] = {0,0,0,0,1,1,1,2,2,3};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {1,2,3,4,2,3,4,3,4,4};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	long long _ = 16LL; 
END
CASE(2)
	int n = 6; 
	int x_[] = {0,0,1,1,1,3,1,2,2,4};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {1,2,2,3,4,4,5,4,5,5};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	long long _ = 40LL; 
END
CASE(3)
	int n = 60; 
	int x_[] = {10,20,30};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {20,30,10};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	long long _ = 1008806316530991104LL; 
END
CASE(4)
	int n = 60; 
	int x_[] = {0,0,1,0,0,3,0,0,5,0,0,7,0,0,9,0,0,11,0,0,13,0,0,15,0,0,17,0,0,19,0,0,21,0,0,23,0,0,25,0,0,27,0,0,29,5,2,23,5,20,27,26,22,19,18,13,15,12,7,9};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {1,2,2,3,4,4,5,6,6,7,8,8,9,10,10,11,12,12,13,14,14,15,16,16,17,18,18,19,20,20,21,22,22,23,24,24,25,26,26,27,28,28,29,30,30,1,12,27,22,1,14,5,27,27,15,15,29,7,6,3};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	long long _ = 578333426763956224LL; 
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
// param type: int
	vector <int> x; 
	{
		int N=UNIFORM_LL(1, 51);
		x = vector <int>(N); 
		REP(i, N) {
			x[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> y; 
	{
		int N=UNIFORM_LL(1, 51);
		y = vector <int>(N); 
		REP(i, N) {
			y[i] = UNIFORM_LL(0, 1000);
		}
	}
	long long _0 = TriangleFree().count(n, x, y);
	long long _1 = TriangleFreeRef().count(n, x, y);
	if(!verify_case(_0, _1, true)) {
print(n);
print(x);
print(y);
	}
}
#endif

}
// END CUT HERE
