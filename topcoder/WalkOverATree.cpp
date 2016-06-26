// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Given is a tree on n nodes.
The nodes are numbered 0 through n-1.
You are given the description of the tree as a vector <int> parent with n-1 elements.
For each valid i, there is an edge between vertices (i+1) and parent[i].





A person is currently standing in node 0.
In a single step, the person can move from its current node to any adjacent node.
You are given an int L.
The person is allowed to make at most L steps.





Return the maximum number of nodes the person can visit during the walk.
Node 0 (where the walk starts) and the node where the walk ends count as visited.
Each visited node is only counted once, even if it is visited multiple times.


DEFINITION
Class:WalkOverATree
Method:maxNodesVisited
Parameters:vector <int>, int
Returns:int
Method signature:int maxNodesVisited(vector <int> parent, int L)


CONSTRAINTS
-parent will contain between 0 and 49 elements, inclusive.
-For each i, parent[i] will be between 0 and i, inclusive.
-L will be between 1 and 100, inclusive.


EXAMPLES

0)
{0, 0}
2

Returns: 2

The tree consists of edges 1-0 and 2-0.
Our person will start in node 0 and can make at most L=2 steps.
In two steps, the best we can do is visit one of the nodes 1 and 2.

1)
{0, 0}
3

Returns: 3

This is the same tree, only now we have L=3.
In three steps the person can visit all three nodes: for example, by going from node 0 to node 1, back to node 0, and finally to node 2.
Note that even though the person visited node 0 twice, we only count it once.

2)
{0, 1, 2, 3}
2

Returns: 3



3)
{0,0,0,0,2,4,2,3,1}
1

Returns: 2



4)
{0,0,1,2,3,2,3,1,3,0,1,8,6,8,0,5,15,0,9}
4

Returns: 5



5)
{0,0,0,1,1,3,5,1,4,5,2,2,10,5,10,10,11,13,8,3,18,15,20,20,23,8,11,26,4}
26

Returns: 17



6)
{0, 0, 2, 0}

100

Returns: 5

As the tree is very small and L large, the person can easily visit all nodes.

7)
{0, 0, 2}
4

Returns: 4



*/
// END CUT HERE
#line 116 "WalkOverATree.cpp"

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
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }



class WalkOverATree {
	public:
	VVI g;
	int maxNodesVisited(vector <int> p, int L) {
		int N=p.size()+1;
		g=VVI(N);
		REP(i, N-1) g[p[i]].PB(i+1);
//		cout<<g<<endl;
		int md = dfs(0);
		if(L<=md) return L+1;
		return min(N, 1+md+(L-md)/2);
	}
	int dfs(int idx) {
		int de=0;
		REP(i, g[idx].size()) {
			int nidx = g[idx][i];
			de=max(de, 1+dfs(nidx));
		}
		return de;
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
#define END	 verify_case(_, WalkOverATree().maxNodesVisited(parent, L));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int parent_[] = {0, 0};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int L = 2; 
	int _ = 2; 
END
CASE(1)
	int parent_[] = {0, 0};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int L = 3; 
	int _ = 3; 
END
//return 0;
CASE(2)
	int parent_[] = {0, 1, 2, 3};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int L = 2; 
	int _ = 3; 
END
CASE(3)
	int parent_[] = {0,0,0,0,2,4,2,3,1};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int L = 1; 
	int _ = 2; 
END
CASE(4)
	int parent_[] = {0,0,1,2,3,2,3,1,3,0,1,8,6,8,0,5,15,0,9};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int L = 4; 
	int _ = 5; 
END
CASE(5)
	int parent_[] = {0,0,0,1,1,3,5,1,4,5,2,2,10,5,10,10,11,13,8,3,18,15,20,20,23,8,11,26,4};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int L = 26; 
	int _ = 17; 
END
CASE(6)
	int parent_[] = {0, 0, 2, 0}
;
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int L = 100; 
	int _ = 5; 
END
CASE(7)
	int parent_[] = {0, 0, 2};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int L = 4; 
	int _ = 4; 
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
	vector <int> parent; 
	{
		int N=UNIFORM_LL(1, 51);
		parent = vector <int>(N); 
		REP(i, N) {
			parent[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int L = UNIFORM_LL(0, 100); 
	int _0 = WalkOverATree().maxNodesVisited(parent, L);
	int _1 = WalkOverATreeRef().maxNodesVisited(parent, L);
	if(!verify_case(_0, _1, true)) {
print(parent);
print(L);
	}
}
#endif

}
// END CUT HERE
