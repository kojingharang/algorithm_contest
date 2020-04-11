// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Dengklek has a tree consisting of N nodes. The nodes are conveniently numbered 0 through N − 1. You are given an vector <int> parents that consists of N − 1 elements. The root of the tree is node 0, while for each 1 ≤ i < N, the parent of node i is node parents[i − 1].

Each node is initially labeled with a lowercase letter. You are give a string labels that contains N lowercase letters. The label of node i is labels[i].

Let's define the level of a node as the number of edges in the only path from it to the root. Let L be the maximum level of all nodes.

A tree is "notorious" if both the following conditions hold:


For each 0 ≤ i ≤ L, there must be at least one node labeled with an uppercase letter that has level i.
For each pair of nodes connected by an edge, if they are labeled with the same letter (case insensitive), then the letters must be both lowercase or both uppercase.


Ganesh wants to transform the tree into a notorious one. To achieve that, Ganesh will choose zero or more nodes. Then, for each chosen node, Ganesh will change the case of the label to uppercase.

Return the number of possible resulting notorious trees, modulo 1,000,000,007. Two trees are different if there is at least one node that is labeled with a lowercase letter in one tree but is labeled with an uppercase letter in the other tree.


DEFINITION
Class:DengklekGaneshAndTree
Method:getCount
Parameters:string, vector <int>
Returns:int
Method signature:int getCount(string labels, vector <int> parents)


CONSTRAINTS
-labels will contain between 1 and 1,000 characters, inclusive.
-Each character of labels will be a lowercase English letter ('a' to 'z').
-parents will contain exactly N − 1 elements, where N is the number of character of labels.
-For each i, parents[i] will be between 0 and i, inclusive.


EXAMPLES

0)
"seems"
{0, 1, 0, 3}

Returns: 5

Here are the five possible notorious trees. Nodes with uppercase letters are shown in bold for clarity.



1)
"like"
{0, 0, 0}

Returns: 7

For level 0, the letter 'l' must be uppercase. For level 1, each of the letters 'i', 'k', 'e' can be either lowercase or uppercase, but they cannot be all lowercase. Therefore, the number of possible notorious trees is 1 × 2 × 2 × 2 − 1 = 7.

2)
"a"
{}

Returns: 1



3)
"coincidence"
{0, 1, 2, 0, 2, 1, 4, 7, 7, 6}

Returns: 218



4)
"topcoderopenroundtwobgoodluckhavefun"
{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0}

Returns: 147418098

Don't forget to return the answer modulo 1,000,000,007.

*/
// END CUT HERE
#line 84 "DengklekGaneshAndTree.cpp"

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

/*
*/

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
// UnionFind uf(N);
// if(uf.Union(ei, ej)) ...
// if(uf.Find(ei, ej)) ...

struct modll {
	static const ll MODVAL;
	ll val;
	modll() : val(0) {}
	modll(ll v) : val(v) { normalize(); }
	void normalize() { val = (val+MODVAL) % MODVAL; }
	modll  operator+ (ll v) { return modll(val+v); }
	modll& operator+=(ll v) { val+=v; normalize(); return *this; }
	modll  operator- (ll v) { return modll(val-v); }
	modll& operator-=(ll v) { val-=v; normalize(); return *this; }
	modll  operator* (ll v) { return modll(val*v); }
	modll& operator*=(ll v) { val*=v; normalize(); return *this; }
	modll  operator^ (ll e) { modll x(val); modll v(1); for(;e;x=x*x,e>>=1) if(e&1) v = v * x; return v; } // pow
	modll inv() { modll x(val); return x^(MODVAL-2); } // MODVAL must be prime number when use this!
	static modll inv(ll v) { return modll(v).inv(); }
	operator ll() { return val; }
};
const ll modll::MODVAL = 1000000007;


class DengklekGaneshAndTree {
	public:
	int getCount(string S, vector <int> P) {
		ll N = S.size();
		UnionFind uf(N);
		VI depth(N);
		REP(pi, P.size()) {
			int a=P[pi], b=pi+1;
			depth[b] = depth[a]+1;
			if(S[a]==S[b]) uf.Union(a, b);
		}
		ll maxD = *max_element(ALL(depth));
		vector<PII> r(N);
		REP(i, N) r[i] = MP(depth[i], depth[i]);
		REP(i, N) {
			int root = uf.root(i);
			r[root].first = min(r[root].first, depth[i]);
			r[root].second = max(r[root].second, depth[i]);
		}
		vector<PII> rn;
		REP(i, N) if(uf.root(i)==i) rn.PB(r[i]);
		sort(ALL(rn));
		vector<modll> dp(maxD+2); // dp[i] ... [0, i)
		dp[0] = 1;
		REP(i, rn.size()) {
			vector<modll> ndp(dp);
			REP(di, maxD+2) {
				if(dp[di] && rn[i].first <= di) {
					int to = max<int>(di, rn[i].second+1);
					ndp[to] += dp[di];
				}
			}
			dp = ndp;
		}
		return dp[maxD+1];
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
#define END	 verify_case(_, DengklekGaneshAndTree().getCount(labels, parents));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string labels = "seems"; 
	int parents_[] = {0, 1, 0, 3};
	  vector <int> parents(parents_, parents_+sizeof(parents_)/sizeof(*parents_)); 
	int _ = 5; 
END
//return 0;
CASE(1)
	string labels = "like"; 
	int parents_[] = {0, 0, 0};
	  vector <int> parents(parents_, parents_+sizeof(parents_)/sizeof(*parents_)); 
	int _ = 7; 
END
CASE(2)
	string labels = "a"; 
	vector <int> parents; 
	int _ = 1; 
END
CASE(3)
	string labels = "coincidence"; 
	int parents_[] = {0, 1, 2, 0, 2, 1, 4, 7, 7, 6};
	  vector <int> parents(parents_, parents_+sizeof(parents_)/sizeof(*parents_)); 
	int _ = 218; 
END
CASE(4)
	string labels = "topcoderopenroundtwobgoodluckhavefun"; 
	int parents_[] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
	  vector <int> parents(parents_, parents_+sizeof(parents_)/sizeof(*parents_)); 
	int _ = 147418098; 
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
	string labels; 
	{
		int N=UNIFORM_LL(1, 51);
		labels = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			labels[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
// param type: int
	vector <int> parents; 
	{
		int N=UNIFORM_LL(1, 51);
		parents = vector <int>(N); 
		REP(i, N) {
			parents[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = DengklekGaneshAndTree().getCount(labels, parents);
	int _1 = DengklekGaneshAndTreeRef().getCount(labels, parents);
	if(!verify_case(_0, _1, true)) {
print(labels);
print(parents);
	}
}
#endif

}
// END CUT HERE
