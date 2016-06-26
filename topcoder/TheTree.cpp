// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Manao is working in the Tree Research Center.
It may come as a surprise that the trees they research are not the ones you can see in a park.
Instead, they are researching special graphs.
(See Notes for definitions of terms related to these trees.)

Manao's daily job is reconstructing trees, given some partial information about them.
Today Manao faced a difficult task.
He needed to find the maximum possible diameter of a tree, given the following information:


Some vertex in the tree is called V.
The distance between V and the farthest vertex from V is D.
For each x between 1 and D, inclusive, Manao knows the number of vertices such that their distance from V is x.


You are given a vector <int> cnt containing D strictly positive integers.
For each i, the i-th element of cnt is equal to the number of vertices which have distance i+1 from V.
Please help Manao with his task.
Return the maximum possible diameter of a tree that matches the given information.


DEFINITION
Class:TheTree
Method:maximumDiameter
Parameters:vector <int>
Returns:int
Method signature:int maximumDiameter(vector <int> cnt)


NOTES
-A tree is a connected graph with no cycles. Note that each tree with N vertices has precisely N-1 edges.
-The distance between two vertices of a tree is the smallest number of edges one has to traverse in order to get from one of the vertices to the other one.
-The diameter of a tree is the maximum of all pairwise distances. In other words, the diameter is the distance between the two vertices that are the farthest away from each other.


CONSTRAINTS
-cnt will contain between 1 and 50 elements, inclusive.
-Each element of cnt will be between 1 and 1000, inclusive.


EXAMPLES

0)
{3}

Returns: 2

The only tree that matches the given information is shown below. The vertex V is red.




1)
{2, 2}

Returns: 4

There are two trees which correspond to the given partial information:



The tree on the left has diameter 3 and the tree on the right has diameter 4.

2)
{4, 1, 2, 4}

Returns: 5

This is one example of a tree that corresponds to the given constraints and has the largest possible diameter.



3)
{4, 2, 1, 3, 2, 5, 7, 2, 4, 5, 2, 3, 1, 13, 6}

Returns: 21



******************************/
// END CUT HERE
#line 86 "TheTree.cpp"
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

class TheTree {
	public:
	int maximumDiameter(vector <int> cnt) {
		int N=cnt.size();
		int ans = 0;
		REP(i, N) {
			int sec=0;
			RANGE(j, i, N) {
				if(cnt[j]==1) break;
				sec++;
			}
			ans = max(ans, N-i + sec);
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//mplate<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// os << "{ ";
// for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
// os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, TheTree().maximumDiameter(cnt));}
int main(){

CASE(0)
	int cnt_[] = {1};
	  vector <int> cnt(cnt_, cnt_+sizeof(cnt_)/sizeof(*cnt_)); 
	int _ = 1; 
END
CASE(0)
	int cnt_[] = {3};
	  vector <int> cnt(cnt_, cnt_+sizeof(cnt_)/sizeof(*cnt_)); 
	int _ = 2; 
END
CASE(1)
	int cnt_[] = {2, 2};
	  vector <int> cnt(cnt_, cnt_+sizeof(cnt_)/sizeof(*cnt_)); 
	int _ = 4; 
END
CASE(2)
	int cnt_[] = {4, 1, 2, 4};
	  vector <int> cnt(cnt_, cnt_+sizeof(cnt_)/sizeof(*cnt_)); 
	int _ = 5; 
END
CASE(3)
	int cnt_[] = {4, 2, 1, 3, 2, 5, 7, 2, 4, 5, 2, 3, 1, 13, 6};
	  vector <int> cnt(cnt_, cnt_+sizeof(cnt_)/sizeof(*cnt_)); 
	int _ = 21; 
END

}
// END CUT HERE
