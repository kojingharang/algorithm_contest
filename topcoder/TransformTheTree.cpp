// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
	You have a tree consisting of N nodes. The nodes are conveniently numbered 0 through N-1. You are given an vector <int> parents that consists of N-1 elements. For each 1 ≤ i < N, the parent of node i is node parents[i-1].



	Your goal is to transform the tree into a path. In order to accomplish that you are allowed to use the following operation multiple times:
	
		Choose an edge {u, v}.
		Remove the edge {u, v} obtaining two trees T1 and T2 in this way -- T1 containing u and T2 containing v.
		Choose any node w from T1 and any node z from T2.
		Add the edge {w, z}.
	



	Return the minimum number of operations needed to transform the given tree into a path.


DEFINITION
Class:TransformTheTree
Method:countCuts
Parameters:vector <int>
Returns:int
Method signature:int countCuts(vector <int> parents)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-parents will contain exactly N − 1 elements.
-For each i, parents[i] will be between 0 and i, inclusive.


EXAMPLES

0)
{0, 0, 1, 2, 1}

Returns: 1

Initially, the tree contains the following edges: 0-1, 0-2, 1-3, 2-4, and 1-5.
This tree is not a path, but we can change it into a path in a single operation.
One optimal solution looks as follows:
Remove the edge 1-5.
This produces two trees: T1 is a path on five vertices and T2 is a single isolated vertex.
Then, add the edge 4-5.
Doing so produces the path 3-1-0-2-4-5.

1)
{0, 0, 0, 0, 0, 0}

Returns: 4

One optimal sequence of operations looks as follows:

	 Cut the edge 0-3, add the edge 2-3.
	 Cut the edge 0-2, add the edge 1-2.
	 Cut the edge 0-6, add the edge 5-6.
	 Cut the edge 0-5, add the edge 4-5.

After applying these operations the resulting tree is 3-2-1-0-4-5-6.

2)
{0, 0, 1, 2, 3, 4, 5, 6}

Returns: 0

The given tree is already a path.

3)
{}

Returns: 0



4)
{0, 1, 2, 3, 2, 5, 0, 7, 8, 9, 8, 11}

Returns: 2

The following provides the minimum number of operations:

	 Cut the edge 2-5, add the edge 6-10.
	 Cut the edge 8-9, add the edge 5-12.


5)
{0, 1, 2, 0, 4, 5, 6, 4, 5, 6, 0, 11, 12}

Returns: 2



*/
// END CUT HERE
#line 100 "TransformTheTree.cpp"

#include <vector>
#include <map>
#include <set>
#include <stack>
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
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }




class TransformTheTree {
	public:
	int countCuts(vector <int> P) {
		int N = P.size()+1;
		VI r(N);
		RANGE(i, 1, N) {
			r[i]++;
			r[P[i-1]]++;
		}
//		DD(r);
		int ans = 0;
		REP(ii, N) {
			int i = N-1-ii;
			if(r[i]>2) {
				while(r[i]>2) {
					r[i]--;
					ans++;
				}
				if(i) r[P[i-1]]--;
//				DD(r);
			}
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
#define END	 verify_case(_, TransformTheTree().countCuts(parents));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int parents_[] = {0, 1, 2, 2, 4, 5, 6, 0, 8, 9, 9, 3, 2, 10, 6, 15, 16, 1, 5, 17, 20, 21, 14, 1, 13, 25, 24, 27, 28, 29, 30, 29, 28, 23, 0, 1, 11, 37, 32, 34, 19, 41, 42, 15, 7, 30, 46}
;
	  vector <int> parents(parents_, parents_+sizeof(parents_)/sizeof(*parents_)); 
	int _ = 9; 
END
CASE(0)
	int parents_[] = {0, 0, 1, 2, 1};
	  vector <int> parents(parents_, parents_+sizeof(parents_)/sizeof(*parents_)); 
	int _ = 1; 
END
CASE(1)
	int parents_[] = {0, 0, 0, 0, 0, 0};
	  vector <int> parents(parents_, parents_+sizeof(parents_)/sizeof(*parents_)); 
	int _ = 4; 
END
CASE(2)
	int parents_[] = {0, 0, 1, 2, 3, 4, 5, 6};
	  vector <int> parents(parents_, parents_+sizeof(parents_)/sizeof(*parents_)); 
	int _ = 0; 
END
CASE(3)
	vector <int> parents; 
	int _ = 0; 
END
CASE(4)
	int parents_[] = {0, 1, 2, 3, 2, 5, 0, 7, 8, 9, 8, 11};
	  vector <int> parents(parents_, parents_+sizeof(parents_)/sizeof(*parents_)); 
	int _ = 2; 
END
CASE(5)
	int parents_[] = {0, 1, 2, 0, 4, 5, 6, 4, 5, 6, 0, 11, 12};
	  vector <int> parents(parents_, parents_+sizeof(parents_)/sizeof(*parents_)); 
	int _ = 2; 
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
	vector <int> parents; 
	{
		int N=UNIFORM_LL(1, 51);
		parents = vector <int>(N); 
		REP(i, N) {
			parents[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = TransformTheTree().countCuts(parents);
	int _1 = TransformTheTreeRef().countCuts(parents);
	if(!verify_case(_0, _1, true)) {
print(parents);
	}
}
#endif

}
// END CUT HERE
