// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// In a tree, the distance between two nodes is the number of edges on the (only) simple path that connects them.


You are given a vector <string> x with N elements, each containing N characters.
Draw a tree with N nodes, numbered 0 through N-1.
The tree must have the following properties:
For each i and j, if x[i][j] is 'E' the distance between i and j must be even, and if it is 'O' (uppercase o) this distance must be odd.


If there is no tree with these properties, return {-1}.
Otherwise, return a vector <int> with 2N-2 elements: the list of edges in one such tree.
For example, if N=3 and your tree contains the edges 0-2 and 1-2, return {0,2,1,2}.
If there are multiple correct outputs you may output any of them.

DEFINITION
Class:OddEvenTree
Method:getTree
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> getTree(vector <string> x)


NOTES
-If you use plugins to test your solution, be careful. Plugins cannot tell you whether your solution is correct -- they'll just tell you whether it matches the example output exactly.


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-x will contain exactly n elements.
-Each element in x will have exactly n characters.
-Each character in x will be 'O' or 'E'.


EXAMPLES

0)
{"EOE",
 "OEO",
 "EOE"}

Returns: {0, 1, 2, 1 }

The tree: 0-1-2 is a valid answer.

1)
{"EO",
 "OE"}

Returns: {0, 1 }



2)
{"OO",
 "OE"}

Returns: {-1 }

dist[0][0] must be 0, and it should be an even number, so it is impossible.

3)
{"EO",
 "EE"}

Returns: {-1 }

dist[0][1] should be same with dist[1][0].

4)
{"EOEO",
 "OEOE",
 "EOEO",
 "OEOE"}

Returns: {0, 1, 0, 3, 2, 1 }



******************************/
// END CUT HERE
#line 85 "OddEvenTree.cpp"
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool Union(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool Find(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

class OddEvenTree {
	public:
	vector <int> getTree(vector <string> x) {
		int N=x.size();
		REP(i, N) if(x[i][i]!='E') return {-1};
		REP(i, N) REP(j, N) if(x[i][j]!=x[j][i]) return {-1};
		UnionFind uf(N);
		REP(i, N) {
			int other=-1;
			REP(j, N) {
				if(x[i][j]=='E') {
					uf.Union(i, j);
				} else {
					if(other==-1) other=j;
					uf.Union(other, j);
				}
			}
		}
		REP(i, N) {
			REP(j, N) {
				if((x[i][j]=='E') ^ uf.Find(i, j)) return {-1};
			}
		}
		VI w(N);
		w[0]=0;
		RANGE(i, 1, N) w[i]=uf.Find(0, i)?0:1;
		VI a, b;
		REP(i, N) if(w[i]) a.PB(i); else b.PB(i);
		if(!a.size()||!b.size()) return {-1};
		vector<int> ans;
		REP(ai, a.size()) {
			ans.PB(a[ai]);
			ans.PB(b[0]);
		}
		RANGE(bi, 1, b.size()) {
			ans.PB(b[bi]);
			ans.PB(a[0]);
		}
//		cout<<w<<endl;
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const vector <int>& Expected, const vector <int>& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, OddEvenTree().getTree(x));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string x_[] = {"EOE",
 "OEO",
 "EOE"};
	  vector <string> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int __[] = {0, 1, 2, 1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	string x_[] = {"EO",
 "OE"};
	  vector <string> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int __[] = {0, 1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	string x_[] = {"OO",
 "OE"};
	  vector <string> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int __[] = {-1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	string x_[] = {"EO",
 "EE"};
	  vector <string> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int __[] = {-1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(4)
	string x_[] = {"EOEO",
 "OEOE",
 "EOEO",
 "OEOE"};
	  vector <string> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int __[] = {0, 1, 0, 3, 2, 1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
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
	vector <string> x; 
	{
		int N=UNIFORM_LL(1, 51);
		x = vector <string>(N); 
		REP(i, N) {
			x[i] = UNIFORM_LL(0, 1000);
		}
	}
	vector <int> _0 = OddEvenTree().getTree(x);
	vector <int> _1 = OddEvenTreeRef().getTree(x);
	if(!verify_case(_0, _1, true)) {
print(x);
	}
}
#endif

}
// END CUT HERE
