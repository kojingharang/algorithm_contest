// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
You are given a rooted tree with n nodes.
The nodes are labeled from 0 to n-1.
Node 0 is the root.
Each node of the tree has at most two children.




You are given the description of the tree: the vector <int>s p and w.
The vector <int> p has n-1 elements.
For each valid i, node p[i] is the parent of node (i+1).
You may assume that for each i we have p[i] ≤ i.
The vector <int> w has n elements.
For each valid i, w[i] is the weight of node i.





The vector <int> w has a special property: it is non-decreasing.
That is, for each valid i we have w[i-1] ≤ w[i].





All nodes of the tree are currently empty.
You are now going to play a game with the tree and an unlimited supply of stones.
The game is played in turns.
In each turn you can either remove a single stone from anywhere into a tree, or you can place a single stone onto a node of the tree.
However, there is a restriction on placing the stones:
you may only place a stone onto a node if all of its children currently have stones placed on them.
(Note that this means that you can always place a stone onto any leaf of the tree.)





The weight of a given state of the game is equal to the sum of weights of nodes with stones.





You win the game by placing a stone onto the root of the tree.
You want to win the game.
If there are multiple ways to do so, you prefer a way for which the maximum weight of a state during the game is minimized.
Compute and return this weight.
In other words, compute and return the smallest W for which there is a way to win the game such that during the game the total weight of nodes with stones never exceeds W.


DEFINITION
Class:StonesOnATree
Method:minStones
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minStones(vector <int> p, vector <int> w)


CONSTRAINTS
-p will have between 1 and 999 elements, inclusive. (Thus, the number of nodes is between 2 and 1,000, inclusive.)
-The i-th element of p will be between 0 and i, inclusive.
-In the given tree each node will have at most two children. In other words, each value will appear in p at most twice.
-w will have exactly len(p)+1 elements.
-Each element of w will be 1 and 10^5, inclusive.
-Elements of w will be non-decreasing.


EXAMPLES

0)
{0,1,2,3}
{1,2,2,4,4}

Returns: 8

There are five nodes in a line. 
Here, one optimal solution is as follows:


 Place stone on node 4 (weight = 4). 
 Place stone on node 3 (weight = 8). 
 Remove stone from node 4 (weight = 4). 
 Place stone on node 2 (weight = 6). 
 Place stone on node 1 (weight = 8). 
 Remove stone from node 2 (weight = 6). 
 Place stone on node 0 (weight = 7). 


The maximum weight over all states is 8. It can be shown there is no other sequence of moves that has a smaller maximum weight.

1)
{0,0}
{1,2,3}

Returns: 6

In order to be able to place a stone onto node 0 we have to place stones onto both of its children. Thus, at the end of the game each of these three nodes will have a stone.


2)
{0}
{100000,100000}

Returns: 200000



3)
{0,0,1,1,2,2}
{1,1,1,1,1,1,1}

Returns: 4



4)
{0,0,1,2,3,4,4,2,1,3,6,7}
{1,2,3,4,5,6,6,7,8,8,8,9,10}

Returns: 22


間違ったやつ

{{0, 1, 2, 3, 4, 5, 6, 7, 8, 8, 10, 11, 12, 13, 14, 14, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 31, 33, 34, 35, 35, 37, 38, 36, 40, 41, 39, 43, 42, 45, 45, 47, 47, 48, 50, 51, 51, 52, 53, 53, 55, 55, 56, 59, 60, 58, 62, 63, 61, 57, 65, 67, 63, 65, 69, 70, 70, 73, 74, 74, 76, 75, 78, 79, 76, 80, 81, 82, 84, 77, 85, 86, 87, 88, 85, 91, 86, 90, 93, 95, 96, 93, 97, 98, 92, 97, 102, 101, 103, 105, 106, 102, 108, 104, 109, 101, 111, 103, 112, 113, 116, 112, 116, 119, 118, 107, 121, 122, 124, 124, 126}, {996, 1533, 2806, 3400, 3430, 4413, 5101, 6229, 8385, 9144, 9517, 10451, 10801, 11784, 12074, 12176, 13316, 16043, 16676, 17261, 19831, 20267, 21076, 23394, 23508, 23529, 24050, 25333, 26669, 26930, 27849, 28920, 29010, 29566, 29577, 30126, 31376, 31880, 32268, 33370, 33894, 34510, 35039, 35619, 35851, 36631, 37723, 37781, 37795, 38365, 39500, 40733, 42543, 42780, 42992, 43058, 43511, 44255, 44671, 45177, 45429, 46228, 46268, 47258, 47881, 49358, 49454, 50270, 50449, 51291, 52282, 53132, 54632, 55536, 56173, 56311, 56577, 57354, 60311, 60478, 63067, 64593, 66030, 66257, 67194, 67985, 68511, 69486, 69504, 69793, 71424, 71973, 72482, 72815, 73101, 73982, 75433, 75785, 77777, 78009, 79293, 79922, 80539, 80810, 81032, 81586, 81630, 83962, 83999, 84167, 84193, 84432, 87463, 87520, 87952, 88384, 89517, 89893, 90042, 93397, 93577, 95044, 95754, 95766, 96143, 98018, 98793, 99132}}

Expected:
353617

Received:
292954

*/
// END CUT HERE
#line 132 "StonesOnATree.cpp"

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



class StonesOnATree {
	public:
	void dfs(int idx, VVI& g, VI& W, vector <int>& w) {
		ll N = g.size();
		W[idx] = w[idx];
		REP(i, g[idx].size()) {
			ll ch = g[idx][i];
			W[idx] += w[ch];
			dfs(ch, g, W, w);
		}
		ll c = 1LL<<60;
		REP(i, g[idx].size()) {
			ll be = W[g[idx][i]];
			ll af = w[g[idx][i]];
			REP(j, g[idx].size()) {
				ll ch = g[idx][j];
				if(i!=j) af += W[ch];
			}
			c = min(c, max(be, af));
		}
		if(g[idx].size()) {
			W[idx] = max(W[idx], c);
		}
	}
	int minStones(vector <int> p, vector <int> w) {
		ll N = p.size()+1;
		VVI g(N);
		REP(i, p.size()) {
			g[p[i]].PB(i+1);
		}
//		DD(g);
		VI W(N);
		dfs(0, g, W, w);
//		DD(W);
		return W[0];
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
#define END	 verify_case(_, StonesOnATree().minStones(p, w));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int p_[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 8, 10, 11, 12, 13, 14, 14, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 31, 33, 34, 35, 35, 37, 38, 36, 40, 41, 39, 43, 42, 45, 45, 47, 47, 48, 50, 51, 51, 52, 53, 53, 55, 55, 56, 59, 60, 58, 62, 63, 61, 57, 65, 67, 63, 65, 69, 70, 70, 73, 74, 74, 76, 75, 78, 79, 76, 80, 81, 82, 84, 77, 85, 86, 87, 88, 85, 91, 86, 90, 93, 95, 96, 93, 97, 98, 92, 97, 102, 101, 103, 105, 106, 102, 108, 104, 109, 101, 111, 103, 112, 113, 116, 112, 116, 119, 118, 107, 121, 122, 124, 124, 126};
	  vector <int> p(p_, p_+sizeof(p_)/sizeof(*p_)); 
	int w_[] = {996, 1533, 2806, 3400, 3430, 4413, 5101, 6229, 8385, 9144, 9517, 10451, 10801, 11784, 12074, 12176, 13316, 16043, 16676, 17261, 19831, 20267, 21076, 23394, 23508, 23529, 24050, 25333, 26669, 26930, 27849, 28920, 29010, 29566, 29577, 30126, 31376, 31880, 32268, 33370, 33894, 34510, 35039, 35619, 35851, 36631, 37723, 37781, 37795, 38365, 39500, 40733, 42543, 42780, 42992, 43058, 43511, 44255, 44671, 45177, 45429, 46228, 46268, 47258, 47881, 49358, 49454, 50270, 50449, 51291, 52282, 53132, 54632, 55536, 56173, 56311, 56577, 57354, 60311, 60478, 63067, 64593, 66030, 66257, 67194, 67985, 68511, 69486, 69504, 69793, 71424, 71973, 72482, 72815, 73101, 73982, 75433, 75785, 77777, 78009, 79293, 79922, 80539, 80810, 81032, 81586, 81630, 83962, 83999, 84167, 84193, 84432, 87463, 87520, 87952, 88384, 89517, 89893, 90042, 93397, 93577, 95044, 95754, 95766, 96143, 98018, 98793, 99132};
	  vector <int> w(w_, w_+sizeof(w_)/sizeof(*w_)); 
	int _ = 353617; 
END
CASE(0)
	int p_[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 31, 34, 35, 35, 36, 36, 39, 39, 41, 41, 43, 44, 45, 46, 47, 47, 49, 50, 51, 52, 53, 54, 55, 55, 54, 57, 59, 60, 58, 62, 63, 60, 52, 66, 67, 68, 69, 65, 63, 71};
	  vector <int> p(p_, p_+sizeof(p_)/sizeof(*p_)); 
	int w_[] = {2460, 4048, 4124, 5486, 6187, 11325, 12017, 13123, 13456, 15911, 18105, 18763, 18963, 19933, 20382, 23641, 25738, 25830, 26068, 29543, 34122, 34298, 34827, 35135, 35814, 39070, 40880, 41360, 41521, 43896, 45678, 47543, 48079, 48080, 53141, 53875, 61686, 61809, 63554, 66100, 67242, 68245, 68365, 70136, 70563, 71200, 71265, 71275, 72222, 73832, 74137, 74154, 74329, 75903, 78324, 78368, 78842, 80831, 82718, 83353, 83849, 84622, 85058, 86477, 87001, 87097, 87684, 88074, 93086, 93464, 93809, 95325, 97099, 99028};
	  vector <int> w(w_, w_+sizeof(w_)/sizeof(*w_)); 
	int _ = 338286; 
END
CASE(0)
	int p_[] = {0,1,2,3};
	  vector <int> p(p_, p_+sizeof(p_)/sizeof(*p_)); 
	int w_[] = {1,2,2,4,4};
	  vector <int> w(w_, w_+sizeof(w_)/sizeof(*w_)); 
	int _ = 8; 
END
CASE(1)
	int p_[] = {0,0};
	  vector <int> p(p_, p_+sizeof(p_)/sizeof(*p_)); 
	int w_[] = {1,2,3};
	  vector <int> w(w_, w_+sizeof(w_)/sizeof(*w_)); 
	int _ = 6; 
END
CASE(2)
	int p_[] = {0};
	  vector <int> p(p_, p_+sizeof(p_)/sizeof(*p_)); 
	int w_[] = {100000,100000};
	  vector <int> w(w_, w_+sizeof(w_)/sizeof(*w_)); 
	int _ = 200000; 
END
CASE(3)
	int p_[] = {0,0,1,1,2,2};
	  vector <int> p(p_, p_+sizeof(p_)/sizeof(*p_)); 
	int w_[] = {1,1,1,1,1,1,1};
	  vector <int> w(w_, w_+sizeof(w_)/sizeof(*w_)); 
	int _ = 4; 
END
CASE(4)
	int p_[] = {0,0,1,2,3,4,4,2,1,3,6,7};
	  vector <int> p(p_, p_+sizeof(p_)/sizeof(*p_)); 
	int w_[] = {1,2,3,4,5,6,6,7,8,8,8,9,10};
	  vector <int> w(w_, w_+sizeof(w_)/sizeof(*w_)); 
	int _ = 22; 
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
	vector <int> p; 
	{
		int N=UNIFORM_LL(1, 51);
		p = vector <int>(N); 
		REP(i, N) {
			p[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> w; 
	{
		int N=UNIFORM_LL(1, 51);
		w = vector <int>(N); 
		REP(i, N) {
			w[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = StonesOnATree().minStones(p, w);
	int _1 = StonesOnATreeRef().minStones(p, w);
	if(!verify_case(_0, _1, true)) {
print(p);
print(w);
	}
}
#endif

}
// END CUT HERE
