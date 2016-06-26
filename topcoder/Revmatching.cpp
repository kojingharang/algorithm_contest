// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// You have a weighted bipartite graph.
Each partition contains n vertices numbered 0 through n-1.
You are given the weights of all edges encoded into a vector <string> A with n elements, each containing n characters.
For each i and j, A[i][j] is '0' if there is no edge between vertex i in the first partition and vertex j in the second partition.
Otherwise, A[i][j] is between '1' and '9', inclusive, and the digit represents the weight of the corresponding edge.

A perfect matching is a permutation p of 0 through n-1 such that for each i there is an edge (of any positive weight) between vertex i in the first partition and vertex p[i] in the second partition.

Your goal is to have a graph that does not contain any perfect matching.
You are allowed to delete edges from your current graph.
You do not care about the number of edges you delete, only about their weights.
More precisely, you want to reach your goal by deleting a subset of edges with the smallest possible total weight.
Compute and return the total weight of deleted edges in an optimal solution.

DEFINITION
Class:Revmatching
Method:smallest
Parameters:vector <string>
Returns:int
Method signature:int smallest(vector <string> A)


CONSTRAINTS
-A will contain exactly n elements.
-Each element in A will be n characters long.
-n will be between 1 and 20, inclusive.
-Each character in A will be between '0' and '9', inclusive.


EXAMPLES

0)
{"1"}

Returns: 1

There is a single edge. You have to delete it.

1)
{"0"}

Returns: 0

There are no edges and therefore there is no perfect matching.

2)
{"44","44"}

Returns: 8



3)
{"861","870","245"}

Returns: 6



4)
{"01000","30200","11102","10001","11001"}

Returns: 0



5)
{"0111101100","0001101001","1001001000","1000100001","0110011111","0011110100","1000001100","0001100000","1000100001","0101110010"}

Returns: 1



******************************/
// END CUT HERE
#line 80 "Revmatching.cpp"
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
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, I, J) REP(i, I) { REP(j, J) cout<<table[i][j]<<" "; cout<<"\n"; }
#define PRINT3(table, I, J, K) REP(i, I) { REP(j, J) { REP(k, K) cout<<table[i][j][k]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }


class Revmatching{
public: 
	int smallest( vector <string> A ) { 
		ll N = A.size(); 
		ll ans = 1000000; 

		RANGE(b, 1, 1<<N) {
			VI rmCosts(N); 
			// li ... left index  ri ... right index
			REP(li, N) if(b>>li&1) REP(ri, N) rmCosts[ri] += A[li][ri]-'0'; 
			sort(ALL(rmCosts));
			ll nL = POPCOUNT(b); 
			ll rmCost = 0;
			// rm R nodes as little as possible so that |L|>|R|, which means |L|-1 = |R|
			REP(i, N - (nL-1)) rmCost += rmCosts[i];
			ans = min(ans, rmCost); 
		} 
		return ans; 
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
#define END	 verify_case(_, Revmatching().smallest(A));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string A_[] = {"1"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int _ = 1; 
END
CASE(1)
	string A_[] = {"0"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int _ = 0; 
END
CASE(2)
	string A_[] = {"44","44"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int _ = 8; 
END
//return 0;
CASE(3)
	string A_[] = {"861","870","245"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int _ = 6; 
END
CASE(4)
	string A_[] = {"01000","30200","11102","10001","11001"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int _ = 0; 
END
CASE(5)
	string A_[] = {"0111101100","0001101001","1001001000","1000100001","0110011111","0011110100","1000001100","0001100000","1000100001","0101110010"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int _ = 1; 
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
	vector <string> A; 
	{
		int N=UNIFORM_LL(1, 51);
		A = vector <string>(N); 
		REP(i, N) {
			A[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = Revmatching().smallest(A);
	int _1 = RevmatchingRef().smallest(A);
	if(!verify_case(_0, _1, true)) {
print(A);
	}
}
#endif

}
// END CUT HERE
