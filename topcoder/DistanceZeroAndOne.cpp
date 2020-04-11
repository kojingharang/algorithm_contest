// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel used to have a graph G but she lost it somewhere.
She now wants to reconstruct it and she needs your help to do so.


Here is what she remembers about the graph:

G was a simple undirected graph on n nodes, numbered 0 through n-1.
G was connected.
All edges had unit lengths. (Thus, the distance between two nodes is simply the smallest number of edges one needs to traverse to get from one to the other.)
For each node i, the distance between nodes 0 and i was dist0[i].
For each node i, the distance between nodes 1 and i was dist1[i].


You are given the vector <int>s dist0 and dist1, each containing n elements.
If there is at least one graph G that corresponds to these distances (and all the other constraints given above), return any such graph.
More precisely, return a vector <string> R containing the adjacency matrix of the chosen graph G.
For each i and j, R[i][j] should be 'Y' if nodes i and j are connected by an edge, or 'N' if they are not.


If there is no solution, return an empty vector <string> instead.

DEFINITION
Class:DistanceZeroAndOne
Method:construct
Parameters:vector <int>, vector <int>
Returns:vector <string>
Method signature:vector <string> construct(vector <int> dist0, vector <int> dist1)


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-dist0 will contain exactly n elemnets.
-dist1 will contain exactly n elemnets.
-Each element in dist0 will be between 0 and n-1, inclusive.
-Each element in dist1 will be between 0 and n-1, inclusive.


EXAMPLES

0)
{0,2,1}
{2,0,1}

Returns: {"NNY", "NNY", "YYN" }

We have a graph with three nodes.
From the given distances we see that dist(0,1) = 2 and that dist(0,2) = dist(1,2) = 1.
Thus, the graph G must look like this: 0 - 2 - 1.

1)
{0,2,1}
{1,0,2}

Returns: { }

The value dist0[1] claims that the distance between nodes 0 and 1 is 2.
On the other hand, the value dist1[0] claims that this distance is 1.
As the graph is undirected, this is impossible.

2)
{3,1,1,1}
{1,0,1,1}

Returns: { }

The value dist0[0] cannot be 3.

3)
{0,1,1,1}
{1,0,1,1}

Returns: {"NYYY", "YNYY", "YYNN", "YYNN" }



4)
{0,3,1,2,2,3,4,4}
{3,0,2,1,2,3,4,4}

Returns: {"NNYNNNNN", "NNNYNNNN", "YNNYYNNN", "NYYNYNNN", "NNYYNYNN", "NNNNYNYY", "NNNNNYNN", "NNNNNYNN" }



5)
{0,1}
{1,0}

Returns: {"NY", "YN" }



*/
// END CUT HERE
#line 98 "DistanceZeroAndOne.cpp"

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


void add(vector<string>& w, int n0, int n1) {
	w[n0][n1] = w[n1][n0] = 'Y';
}

class DistanceZeroAndOne {
	public:
	vector <string> construct(vector <int> d0, vector <int> d1) {
		ll N = d0.size();
		if(!(d0[0]==0 && d0[1]==d1[0] && d1[1]==0)) return {};

		vector<string> g(N, string(N, 'N'));
		VVI n0(N), n1(N);
		REP(i, N) n0[d0[i]].PB(i);
		REP(i, N) n1[d1[i]].PB(i);
		RANGE(i, 1, N) {
			ll pi = i-1;
			auto ps = {MP(&n0, &d1), MP(&n1, &d0)};
			for(auto& p : ps) {
				auto& nodes = *p.first;
				auto& d = *p.second;
				for(int v2 : nodes[i]) {
					bool any=false;
					for(int v1 : nodes[pi]) {
						// try put v1 - v2
						if(abs(d[v1]-d[v2]) < 2) {
							any=true;
							add(g, v1, v2);
						}
					}
					if(!any) return {};
				}
			}
		}
		VVI w(N, VI(N, 1LL<<60));
		REP(i, N) REP(j, N) if(g[i][j]=='Y') w[i][j]=1;
		REP(i, N) w[i][i]=0;
		REP(k, N) REP(i, N) REP(j, N) w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
//		DD(g);
//		DD(w);
		REP(i, N) if(d0[i]!=w[0][i]) return {};
		REP(i, N) if(d1[i]!=w[1][i]) return {};
		return g;
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
#define END	 verify_case(_, DistanceZeroAndOne().construct(dist0, dist1));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int dist0_[] = {0,2,1};
	  vector <int> dist0(dist0_, dist0_+sizeof(dist0_)/sizeof(*dist0_)); 
	int dist1_[] = {2,0,1};
	  vector <int> dist1(dist1_, dist1_+sizeof(dist1_)/sizeof(*dist1_)); 
	string __[] = {"NNY", "NNY", "YYN" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	int dist0_[] = {0,2,1};
	  vector <int> dist0(dist0_, dist0_+sizeof(dist0_)/sizeof(*dist0_)); 
	int dist1_[] = {1,0,2};
	  vector <int> dist1(dist1_, dist1_+sizeof(dist1_)/sizeof(*dist1_)); 
	vector <string> _; 
END
CASE(2)
	int dist0_[] = {3,1,1,1};
	  vector <int> dist0(dist0_, dist0_+sizeof(dist0_)/sizeof(*dist0_)); 
	int dist1_[] = {1,0,1,1};
	  vector <int> dist1(dist1_, dist1_+sizeof(dist1_)/sizeof(*dist1_)); 
	vector <string> _; 
END
CASE(3)
	int dist0_[] = {0,1,1,1};
	  vector <int> dist0(dist0_, dist0_+sizeof(dist0_)/sizeof(*dist0_)); 
	int dist1_[] = {1,0,1,1};
	  vector <int> dist1(dist1_, dist1_+sizeof(dist1_)/sizeof(*dist1_)); 
	string __[] = {"NYYY", "YNYY", "YYNN", "YYNN" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(4)
	int dist0_[] = {0,3,1,2,2,3,4,4};
	  vector <int> dist0(dist0_, dist0_+sizeof(dist0_)/sizeof(*dist0_)); 
	int dist1_[] = {3,0,2,1,2,3,4,4};
	  vector <int> dist1(dist1_, dist1_+sizeof(dist1_)/sizeof(*dist1_)); 
	string __[] = {"NNYNNNNN", "NNNYNNNN", "YNNYYNNN", "NYYNYNNN", "NNYYNYNN", "NNNNYNYY", "NNNNNYNN", "NNNNNYNN" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(5)
	int dist0_[] = {0,1};
	  vector <int> dist0(dist0_, dist0_+sizeof(dist0_)/sizeof(*dist0_)); 
	int dist1_[] = {1,0};
	  vector <int> dist1(dist1_, dist1_+sizeof(dist1_)/sizeof(*dist1_)); 
	string __[] = {"NY", "YN" };
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
	vector <int> dist0; 
	{
		int N=UNIFORM_LL(1, 51);
		dist0 = vector <int>(N); 
		REP(i, N) {
			dist0[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> dist1; 
	{
		int N=UNIFORM_LL(1, 51);
		dist1 = vector <int>(N); 
		REP(i, N) {
			dist1[i] = UNIFORM_LL(0, 1000);
		}
	}
	vector <string> _0 = DistanceZeroAndOne().construct(dist0, dist1);
	vector <string> _1 = DistanceZeroAndOneRef().construct(dist0, dist1);
	if(!verify_case(_0, _1, true)) {
print(dist0);
print(dist1);
	}
}
#endif

}
// END CUT HERE
