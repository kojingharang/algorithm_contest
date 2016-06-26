// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// A 2-edge-connected graph is a connected undirected graph with the following property:
for any two distinct vertices u,v and for any edge e there exists a path from u to v that does not contain e.

You are given a graph G with n vertices numbered 0 through n-1, where n is not less than 3.
The graph has a very specific structure.
For each i between 0 and n-2, inclusive, vertices i and i+1 are connected by an edge with weight w1[i].
Additionally, for each i between 0 and n-3, inclusive, vertices i and i+2 are connected by an edge with weight w2[i].
It is easy to verify that this graph is 2-edge-connected.

Note that some of the edge weights may be zeros.
An edge with weight zero is still present in the graph, just like any other edge.

You may erase some edges of the graph G.
If you do, you must do it in such a way that the graph remains 2-edge-connected.
Your goal is to minimize the sum of weights of edges that remain in G.

You are given the vector <int>s w1 and w2 that describe the graph G.
Compute and return the smallest possible sum of weights of a graph that can be produced in the way described above.

DEFINITION
Class:BiconnectedDiv1
Method:minimize
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minimize(vector <int> w1, vector <int> w2)


CONSTRAINTS
-n will be between 3 and 100, inclusive.
-w1 will contain exactly n-1 elements.
-w2 will contain exactly n-2 elements.
-Each element of w1 and w2 will be between 0 and 10,000, inclusive.


EXAMPLES

0)
{1,2}
{3}

Returns: 6

There are three vertices and three edges (0,1), (1,2), (2,0). If you erase edge (0,1), then any path from 0 to 1 has to go through edge (0,2). And if you erase two or more edges, the graph will become disconnected. So you cannot erase anything.

1)
{3,0,4}
{1,2}

Returns: 10

An optimal solution is to keep all the edges.

2)
{3,3,3,3}
{3,6,3}

Returns: 18

An optimal solution is to erase edge (1,3).

3)
{7243,7525,8467,6351,9453,8456,8175,5874,6869,7400,6438,8926,6876}
{2642,1743,3546,4100,2788,3019,2678,1935,1790,2674,3775,1920}

Returns: 46729



******************************/
// END CUT HERE
#line 75 "BiconnectedDiv1.cpp"
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

// Passed in practice room

ll INF = 1LL<<60;

// dp[i][j][k][l] 0〜iまでの頂点間だけで辺を張った時に, i-2の次数がj, i-1の次数がk, iの次数がl のときの最小の重み和
ll dp[111][5][5][5];

class BiconnectedDiv1 {
	public:
	int minimize(vector <int> w1, vector <int> w2) {
		ll N = w1.size()+1;
		REP(i, N) REP(j, 5) REP(k, 5) REP(l, 5) dp[i][j][k][l]=INF;

		// 1-2おかない
		dp[2][2][1][1] = w1[0] + w2[0];

		// 1-2おく
		dp[2][2][2][2] = w1[0] + w2[0] + w1[1];

		RANGE(i, 3, N) REP(j, 5) REP(k, 5) REP(l, 5) if(dp[i-1][j][k][l] < INF) if(j%2==0) {
			// (i-1, i), (i-2, i) のうちどちらかは置かないといけない(connectedにならない)
			ll nl = min(5, l+1);
			ll nk = min(5, k+1);

			// (i-1, i) を置く
			dp[i][k][nl][1] = min(dp[i][k][nl][1], dp[i-1][j][k][l] + w1[i-1]);

			// (i-2, i) を置く
			dp[i][nk][l][1] = min(dp[i][nk][l][1], dp[i-1][j][k][l] + w2[i-2]);

			// (i-1, i), (i-2, i) を置く
			dp[i][nk][nl][2] = min(dp[i][nk][nl][2], dp[i-1][j][k][l] + w1[i-1] + w2[i-2]);
		}
		ll ans = INF;
		REP(j, 5) REP(k, 5) REP(l, 5) {
			if(j%2==0 && k%2==0 && l%2==0) ans = min(ans, dp[N-1][j][k][l]);
		}
		return ans;
	}
};



/*
{0,1,2,3,4}
{100,101,102,103}
*/

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
#define END	 verify_case(_, BiconnectedDiv1().minimize(w1, w2));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(3)
//	int w1_[] = {550,503,962,183,365};
//	  vector <int> w1(w1_, w1_+sizeof(w1_)/sizeof(*w1_)); 
//	int w2_[] = {500,8,788,308};
	int w1_[] = {1,2,4,8,16};
	  vector <int> w1(w1_, w1_+sizeof(w1_)/sizeof(*w1_)); 
	int w2_[] = {32,64,128,256};
	  vector <int> w2(w2_, w2_+sizeof(w2_)/sizeof(*w2_)); 
	int _ = 381; 
END
//return 0;

CASE(0)
	int w1_[] = {1,2};
	  vector <int> w1(w1_, w1_+sizeof(w1_)/sizeof(*w1_)); 
	int w2_[] = {3};
	  vector <int> w2(w2_, w2_+sizeof(w2_)/sizeof(*w2_)); 
	int _ = 6; 
END
//return 0;
CASE(1)
	int w1_[] = {3,0,4};
	  vector <int> w1(w1_, w1_+sizeof(w1_)/sizeof(*w1_)); 
	int w2_[] = {1,2};
	  vector <int> w2(w2_, w2_+sizeof(w2_)/sizeof(*w2_)); 
	int _ = 10; 
END
//return 0;
CASE(2)
	int w1_[] = {3,3,3,3};
	  vector <int> w1(w1_, w1_+sizeof(w1_)/sizeof(*w1_)); 
	int w2_[] = {3,6,3};
	  vector <int> w2(w2_, w2_+sizeof(w2_)/sizeof(*w2_)); 
	int _ = 18; 
END
CASE(3)
	int w1_[] = {7243,7525,8467,6351,9453,8456,8175,5874,6869,7400,6438,8926,6876};
	  vector <int> w1(w1_, w1_+sizeof(w1_)/sizeof(*w1_)); 
	int w2_[] = {2642,1743,3546,4100,2788,3019,2678,1935,1790,2674,3775,1920};
	  vector <int> w2(w2_, w2_+sizeof(w2_)/sizeof(*w2_)); 
	int _ = 46729; 
END


REP(loop, 1) {
//CASE(2)
//	int N = 6;
//	vector <int> w1(N-1), w2(N-2); 
//	REP(i, N-1) w1[i]=i;
//	REP(i, N-2) w2[i]=100+i;
//	int _ = 312; 
//END
}
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
for(int loop=0;loop<100000;loop++) {
// param type: int
	vector <int> w1; 
	int N=UNIFORM_LL(3, 7);
	{
		w1 = vector <int>(N-1); 
		REP(i, N-1) {
			w1[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> w2; 
	{
		w2 = vector <int>(N-2); 
		REP(i, N-2) {
			w2[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = BiconnectedDiv1().minimize(w1, w2);
	int _1 = BiconnectedDiv1Ref().minimize(w1, w2);
	if(!verify_case(_0, _1, true)) {
print(w1);
print(w2);
break;
	}
}
#endif

}
// END CUT HERE
