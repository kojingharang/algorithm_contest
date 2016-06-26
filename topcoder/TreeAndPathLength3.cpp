// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// You are given an int s.
Your task is to construct an undirected tree such that:

The number of nodes is between 1 and 500, inclusive.
The number of simple paths of length 3 in the tree is exactly s.


Note that the direction of the simple path does not matter: A-B-C-D is the same simple path as D-C-B-A.

It is guaranteed that for the constraints used in this task a tree with the required properties always exists.
Find one such tree.

If your tree has n nodes, they must be labeled 0 through n-1.
Return a vector <int> with (n-1)*2 elements.
For each valid i, elements 2i and 2i+1 of the return value should be the endpoints of one of the edges in your tree.
If there are multiple correct solutions, you may return any of them.

DEFINITION
Class:TreeAndPathLength3
Method:construct
Parameters:int
Returns:vector <int>
Method signature:vector <int> construct(int s)


CONSTRAINTS
-s will be between 1 and 10,000, inclusive.


EXAMPLES

0)
1

Returns: {0, 1, 1, 2, 2, 3 }

The return value has 6 elements, so it has to describe a tree on 4 vertices.
This tree contains the edges 0-1, 1-2, and 2-3.
We can easily verify that this tree does indeed contain exactly one simple path of length 3: the path 0-1-2-3.

1)
2

Returns: {0, 1, 1, 2, 2, 3, 3, 4 }

The returned tree has 5 vertices.
The two simple paths of length 3 in this tree are the paths 0-1-2-3 and 1-2-3-4.

2)
6

Returns: {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 }

The six simple paths of length 3 in this tree are the following paths:
2-1-0-3, 2-1-0-5, 4-3-0-1, 4-3-0-5, 6-5-0-1, and 6-5-0-3.

3)
8

Returns: {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 }



******************************/
// END CUT HERE
#line 70 "TreeAndPathLength3.cpp"
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
#define DD(v) cout<<#v<<": "<<(v)<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class TreeAndPathLength3 {
	public:
	VVI g;
	set<set<int>> ans;
	int hi[4];
	void dfs(int prev, int idx, int step) {
		hi[step] = idx;
		if(step==3) {
			set<int> lans;
			REP(i, 4) lans.insert(hi[i]);
//			cout<<"lans "<<lans<<endl;
			ans.insert(lans);
			return;
		}
		for(auto ni : g[idx]) {
			if(ni!=prev) {
				dfs(idx, ni, step+1);
			}
		}
	}
	void test(vector<int> og, int s) {
		cout<<"ANS "<<og<<endl;
		int N = og.size()/2 + 1;
		REP(i, og.size()) assert(0<=og[i] && og[i]<N);
		g = VVI(N);
		REP(i, og.size()/2) {
			g[og[i*2]].PB(og[i*2+1]);
			g[og[i*2+1]].PB(og[i*2]);
		}
//		cout<<"g "<<g<<endl;
		ans.clear();
		REP(i, N) {
			dfs(-1, i, 0);
		}
		if(ans.size() != s) {
			cout<<"ERROR "<<ans.size()<<" "<<s<<endl;
			assert(false);
		}
	}
	void ma() {
		test({0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 }, 8);
		test({0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 }, 6);
		test({0, 1, 1, 2, 2, 3, 3, 4 }, 2);
		test({0, 1, 1, 2, 2, 3 }, 1);
//		return;
		RANGE(i, 1, 10001) {
			cout<<"s="<<i<<endl;
			test(construct(i), i);
		}
	}
	void ae(vector<int>& a, int x, int y) {
		a.PB(x);
		a.PB(y);
	}
	vector <int> construct(int s) {
		vector<int> a;
		if(s==1) {
			return {0,1,1,2,2,3};
		}
		RANGE(i, 1, 500) {
			RANGE(j, 0, 500) {
				int x=i+j+4;
				int y=500-x;
				int z=1+i*j+i;
				
				if(y<0) continue;
				if(z>s)continue;
				if(s-z>y) continue;
				ae(a, 0, 1);
				ae(a, 2, 3);
				ae(a, 2, 4);
				REP(k, i) {
					ae(a, 0, k+4);
				}
				REP(k, j) {
					ae(a, 0, k+4+i);
				}
				REP(k, s-z) {
					ae(a, 3, k+4+i+j);
				}
				goto endloop;
			}
		}
		endloop:
		return a;
	}
	vector <int> ref_construct(int s) {
		vector<int> rv;
		if(s<100) {
			REP(i, s+2) {
				rv.PB(i);
				rv.PB(i+1);
			}
		} else {
			int N=s/100;
			int rest=s-N*100;
			REP(i, 99) {
				rv.PB(i+1);
				rv.PB(0);
			}
			rv.PB(0);
			rv.PB(100);
			REP(i, N) {
				rv.PB(100);
				rv.PB(101+i);
			}
			int M=101+N;
			rv.PB(101);
			rv.PB(M);
			REP(i, rest) {
				rv.PB(M+i);
				rv.PB(M+i+1);
			}
		}
		return rv;
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
#define END	 verify_case(_, TreeAndPathLength3().construct(s));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

//CASE(0)
//	int s = 1; 
//	int __[] = {0, 1, 1, 2, 2, 3 };
//	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
//END
//CASE(1)
//	int s = 2; 
//	int __[] = {0, 1, 1, 2, 2, 3, 3, 4 };
//	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
//END
//CASE(2)
//	int s = 6; 
//	int __[] = {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 };
//	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
//END
//CASE(3)
//	int s = 8; 
//	int __[] = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 };
//	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
//END
//CASE(3)
//	int s = 10000; 
//	int __[] = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 };
//	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
//END
TreeAndPathLength3().ma();

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
	int s = UNIFORM_LL(0, 100); 
	vector <int> _0 = TreeAndPathLength3().construct(s);
	vector <int> _1 = TreeAndPathLength3Ref().construct(s);
	if(!verify_case(_0, _1, true)) {
print(s);
	}
}
#endif

}
// END CUT HERE
