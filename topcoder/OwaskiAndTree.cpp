// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Owaski is another pet dog of Zhangzj. He likes playing on a tree.

The tree has N vertices, labeled from 0 to N - 1. You are given an vector <int> parent of N - 1 elements. For each i between 0 and N - 2, inclusive, there is an edge between vertex i + 1 and vertex parent[i]. In a single step, Owaski can walk from a vertex to one of its adjacent vertices. You are given an vector <int> pleasure, element i of which indicates the pleasure Owaski gets when he reaches vertex i. Before entering the tree, his pleasure is 0. Of course, at some moments Owaski's pleasure can be negative, as some vertices can make him unhappy. However, Owaski doesn't like to be unhappy. Thus whenever his pleasure becomes negative, he will make it zero again by playing Overwatch and winning nearly every game. Owaski may enter each vertex arbitrarily many times.
However, he doesn't like old things.
Thus, if he enters a vertex he visited before, his pleasure remains unchanged.
In other words, each vertex only influences Owaski's pleasure when he visits it for the first time.

Owaski enters the tree at vertex 0 (therefore the pleasure of vertex 0 also counts), and can leave the tree whenever he wants. Since all dogs love to be happy, he wants to leave with as much pleasure as possible. Return the maximal pleasure he can get.

DEFINITION
Class:OwaskiAndTree
Method:maximalScore
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int maximalScore(vector <int> parent, vector <int> pleasure)


CONSTRAINTS
-N will be between 1 and 1,000, inclusive.
-parent will contain exactly N - 1 elements.
-pleasure will contain exactly N elements.
-For each i, parent[i] will be between 0 and i, inclusive.
-Each element of pleasure will be between -1,000,000 and 1,000,000, inclusive.


EXAMPLES

0)
{0, 1, 2, 3, 4, 5, 6, 7, 8}
{1, 1, -1, -1, -1, -1, 1, 1, 1, 1}

Returns: 4

The tree forms a chain of 10 vertices and 9 edges. The optimal way is to walk through the chain. The values of pleasure of Owaski after visiting vertex 0 to 9 are 1, 2, 1, 0, 0, 0, 1, 2, 3, 4, respectively. He can leave the tree after that, yielding net pleasure of 4.

1)
{0, 0, 1, 2}
{2, 3, 4, -1, -1}

Returns: 9

This time his path can be 0 → 1 → 0 → 2. Note that although Owaski visits 0 twice, the pleasure of that vertex only counts once.

2)
{0, 0, 1, 1, 2, 2, 5, 5}
{1, 2, -3, -7, 3, 2, 7, -1, 3}

Returns: 17

One of the optimal paths is 0 → 2 → 5 → 8 → 5 → 2 → 6 → 2 → 0 → 1 → 4.

3)
{0, 1, 1, 1, 0, 3, 1, 3, 4, 4, 3, 6, 8, 0, 12, 12, 11, 7, 7}
{-154011, 249645, 387572, 292156, -798388, 560085, -261135, -812756, 191481, -165204, 81513, -448791, 608073, 354614, -455750, 325999, 227225, -696501, 904692, -297238}

Returns: 3672275



4)
{}
{-1}

Returns: 0



*/
// END CUT HERE
#line 74 "OwaskiAndTree.cpp"

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



class OwaskiAndTree {
	public:
	int maximalScore(vector <int> pa, vector <int> pl) {
		int N = pa.size()+1;
		VI br(N);
		VI ar(N);
		for(int i=N-1; i>=0; i--) {
			ar[i] += pl[i];
			ar[i] = max(ar[i], 0LL);
			if(i) {
				int pi = pa[i-1];
				ar[pi] += ar[i];
				br[pi] += max(br[i], ar[i]);
			}
		}
//		DD(br);
//		DD(ar);
		return max(br[0], ar[0]);
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
#define END	 verify_case(_, OwaskiAndTree().maximalScore(parent, pleasure));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int parent_[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int pleasure_[] = {-10,-10,-10,-10,-10,-10,-10,-10,-10,-10};
	  vector <int> pleasure(pleasure_, pleasure_+sizeof(pleasure_)/sizeof(*pleasure_)); 
	int _ = 0; 
END

CASE(0)
	int parent_[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int pleasure_[] = {1, 1, -1, -1, -1, -1, 1, 1, 1, 1};
	  vector <int> pleasure(pleasure_, pleasure_+sizeof(pleasure_)/sizeof(*pleasure_)); 
	int _ = 4; 
END
CASE(1)
	int parent_[] = {0, 0, 1, 2};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int pleasure_[] = {2, 3, 4, -1, -1};
	  vector <int> pleasure(pleasure_, pleasure_+sizeof(pleasure_)/sizeof(*pleasure_)); 
	int _ = 9; 
END
CASE(2)
	int parent_[] = {0, 0, 1, 1, 2, 2, 5, 5};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int pleasure_[] = {1, 2, -3, -7, 3, 2, 7, -1, 3};
	  vector <int> pleasure(pleasure_, pleasure_+sizeof(pleasure_)/sizeof(*pleasure_)); 
	int _ = 17; 
END
CASE(3)
	int parent_[] = {0, 1, 1, 1, 0, 3, 1, 3, 4, 4, 3, 6, 8, 0, 12, 12, 11, 7, 7};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int pleasure_[] = {-154011, 249645, 387572, 292156, -798388, 560085, -261135, -812756, 191481, -165204, 81513, -448791, 608073, 354614, -455750, 325999, 227225, -696501, 904692, -297238};
	  vector <int> pleasure(pleasure_, pleasure_+sizeof(pleasure_)/sizeof(*pleasure_)); 
	int _ = 3672275; 
END
CASE(4)
	vector <int> parent; 
	int pleasure_[] = {-1};
	  vector <int> pleasure(pleasure_, pleasure_+sizeof(pleasure_)/sizeof(*pleasure_)); 
	int _ = 0; 
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
	vector <int> pleasure; 
	{
		int N=UNIFORM_LL(1, 51);
		pleasure = vector <int>(N); 
		REP(i, N) {
			pleasure[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = OwaskiAndTree().maximalScore(parent, pleasure);
	int _1 = OwaskiAndTreeRef().maximalScore(parent, pleasure);
	if(!verify_case(_0, _1, true)) {
print(parent);
print(pleasure);
	}
}
#endif

}
// END CUT HERE
