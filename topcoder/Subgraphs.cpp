// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
You are given an int k that is between 2 and 23, inclusive.
Your task is to construct an undirected graph with some properties (listed below) and to locate some special subsets of nodes in the graph.





More precisely, your graph must satisfy the following:

The number n of nodes must be between 1 and 46, inclusive.
The nodes must be labeled from 0 to n-1.
The graph must be a simple undirected graph. (I.e., there cannot be any self-loops or multiple edges.)
For every number x between 0 and k*(k-1)/2, inclusive, there must be a way to choose exactly k nodes so that there will be exactly x edges between them.






Return a vector <string> with n + k*(k-1)/2 + 1 elements.
The return value should look as follows:

The first n elements of the return value should contain the adjacency matrix of your graph. Character j of element i of the return value should be '1' of nodes i and j are connected by an edge and '0' if they aren't. Note that the main diagonal of the adjacency matrix must contain only '0's.
The remaining k*(k-1)/2 + 1 elements of the return value should describe the subsets of nodes that correspond to the last constraint the graph should satisfy. More precisely, the i-th of these strings (0-based index) describes one set of k nodes such that the subgraph induced by these nodes contains exactly i edges. Encode the subset as a string of length n: character j of this string should be 'Y' if node j belongs into the subset and 'N' otherwise.






You may assume that there is always a graph with the desired properties.
If there are multiple correct answers, you may return any of them.


DEFINITION
Class:Subgraphs
Method:findGroups
Parameters:int
Returns:vector <string>
Method signature:vector <string> findGroups(int k)


CONSTRAINTS
-k will be between 2 and 23, inclusive.


EXAMPLES

0)
2

Returns: {"010", "100", "000", "NYY", "YYN" }

The returned graph has three nodes and only one edge: (0,1).
The first set of nodes are the nodes {1,2}. There are no edges between these nodes.
The second set of nodes are the nodes {0,1}. The corresponding subgraph contains one edge.
Note that each node may appear in arbitrarily many of these sets.

1)
3

Returns: {"000000000000", "000000000000", "000000000000", "000010000000", "000100000000", "000000000000", "000000011000", "000000100000", "000000100000", "000000000011", "000000000101", "000000000110", "YYYNNNNNNNNN", "NNNYYYNNNNNN", "NNNNNNYYYNNN", "NNNNNNNNNYYY" }


The graph described by the example return value has 12 nodes.
It contains the following edges: (3,4), (6,7), (6,8), (9,10), (9,11), and (10,11).



The sets of nodes described by the example return value are the following ones:

The set {0,1,2} with 0 edges among these nodes.
The set {3,4,5} with 1 edge among these nodes: the edge (3,4).
The set {6,7,8} with 2 edges among these nodes: (6,7) and (6,8).
The set {9,10,11} with 3 edges among these nodes: the remaining three edges.



2)
4

Returns: {"01111000", "10111100", "11011110", "11101111", "11110000", "01110000", "00110000", "00010000", "YNNNNYYY", "YYNNNNYY", "YNYNNNYY", "YNYNNYYN", "YNYNYYNN", "YNYYNYNN", "YYYYNNNN" }



*/
// END CUT HERE
#line 93 "Subgraphs.cpp"

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



class Subgraphs {
	public:
	vector <string> findGroups(int k) {
		VI w(24);
		REP(i, 24) w[i] = i*(i-1)/2;
		DD(w);
		VI bb, ba;
//		REP(bit, 1<<23)
		{
			int bit = (1<<23)-1;
			VI a, b;
			REP(i, 24) {
				if((bit>>i)&1) {
					a.PB(w[i]);
					b.PB(i);
				}
			}
			reverse(ALL(a));
			DD(a);
			int ok = 1;
			RANGE(i, 1, 23*11+1) {
				ll v = i;
				REP(ai, a.size()) {
					if(v >= a[ai]) {
						v-=a[ai];
					}
				}
				if(v) {
					ok=0;
					DD(i);DD(v);
					break;
				}
			}
			if(ok) {
				DD(b);
				DD(a);
				if(bb.size()==0 || b.size() < bb.size()) {
					DD(b);
					bb = b;
					ba = a;
				}
			}
		}
		DD(bb);
		DD(ba);
		return {};
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const vector <string>& Expected, const vector <string>& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, Subgraphs().findGroups(k));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int k = 2; 
	string __[] = {"010", "100", "000", "NYY", "YYN" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END
return 0;
CASE(1)
	int k = 3; 
	string __[] = {"000000000000", "000000000000", "000000000000", "000010000000", "000100000000", "000000000000", "000000011000", "000000100000", "000000100000", "000000000011", "000000000101", "000000000110", "YYYNNNNNNNNN", "NNNYYYNNNNNN", "NNNNNNYYYNNN", "NNNNNNNNNYYY" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	int k = 4; 
	string __[] = {"01111000", "10111100", "11011110", "11101111", "11110000", "01110000", "00110000", "00010000", "YNNNNYYY", "YYNNNNYY", "YNYNNNYY", "YNYNNYYN", "YNYNYYNN", "YNYYNYNN", "YYYYNNNN" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
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
	int k = UNIFORM_LL(0, 100); 
	vector <string> _0 = Subgraphs().findGroups(k);
	vector <string> _1 = SubgraphsRef().findGroups(k);
	if(!verify_case(_0, _1, true)) {
print(k);
	}
}
#endif

}
// END CUT HERE
