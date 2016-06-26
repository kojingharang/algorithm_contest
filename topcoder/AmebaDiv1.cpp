// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Monte-Carlo is an amoeba. Amoebas can feed on gel: whenever an amoeba encounters a piece of gel that is exactly as big as the amoeba, the amoeba will consume the gel and thus double its size.

Initially, the size of Monte-Carlo was some unknown positive integer. During its lifetime, Monte-Carlo encountered several gels and consumed the ones it could.

You are given a vector <int> X. The elements of X are the sizes of gels Monte-Carlo encountered, in chronological order.

Let S be the set of all possible final sizes of Monte-Carlo. Compute and return the number of positive integers that do not belong into S.

DEFINITION
Class:AmebaDiv1
Method:count
Parameters:vector <int>
Returns:int
Method signature:int count(vector <int> X)


NOTES
-It is possible to prove that the answer for any test case is finite and fits into a 32-bit signed integer type.


CONSTRAINTS
-X will contain between 1 and 200 integers, inclusive.
-Each element of X will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{3,2,1}

Returns: 2

Here are a few possibilities how Monte-Carlo's life could have looked like:

Monte-Carlo started with size 1, ignored gel #0, ignored gel #1, consumed gel #2 and thus reached size 2.
Monte-Carlo started with size 3, consumed gel #0 and thus reached size 6, and then ignored the next two gels (as they were too small).
Monte-Carlo started with size 47 and ignored all three gels.

All final sizes except for 1 and 3 are possible.

1)
{2,2,2,2,2,2,4,2,2,2}

Returns: 2

If Monte-Carlo starts with size 2, its life will look as follows: First, it will consume gel #0 and thus grow to 4. Later, after ignoring a few gels, Monte-Carlo will consume gel #6 (the one with size 4) and thus grow to 8.

It can be shown that for this X Monte-Carlo's final size can never be 2 or 4. 

2)
{1,2,4,8,16,32,64,128,256,1024,2048}

Returns: 11



3)
{854,250,934,1000,281,250,281,467,854,562,934,1000,854,500,562}

Returns: 7



******************************/
// END CUT HERE
#line 70 "AmebaDiv1.cpp"
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class AmebaDiv1Ref {
	public:
	int count(vector <int> X) {
		map<int, int> w;
		REP(i, X.size()) {
			if(!w[X[i]]) w[X[i]*2]=0;
			w[X[i]]=1;
		}
		int ans=0;
		FOR(e, w) if(e->second)ans++;
		return ans;
	}
};

int f(const vector <int>& X, int v) {
	REP(i, X.size()) {
		if(v==X[i]) v*=2;
	}
	return v;
}
class AmebaDiv1 {
	public:
	int count(vector <int> X) {
		map<int, int> w;
		REP(i, X.size()) {
			w[f(X, X[i])]=1;
			w[f(X, X[i]*2)]=1;
		}
		map<int, int> h;
		REP(i, X.size()) {
			if(!w[X[i]]) h[X[i]]=1;
			if(!w[X[i]*2]) h[X[i]*2]=1;
		}
//		cout<<w<<endl;
//		cout<<h<<endl;
		return h.size();
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
#define END	 verify_case(_, AmebaDiv1().count(X));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

//CASE(0)
//	int X_[] = {829,0,170,243,63};
//	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
//	int _ = 2; 
//END
//return 1;
CASE(0)
	int X_[] = {3,2,1};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int _ = 2; 
END
CASE(1)
	int X_[] = {2,2,2,2,2,2,4,2,2,2};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int _ = 2; 
END
CASE(2)
	int X_[] = {1,2,4,8,16,32,64,128,256,1024,2048};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int _ = 11; 
END
CASE(3)
	int X_[] = {854,250,934,1000,281,250,281,467,854,562,934,1000,854,500,562};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int _ = 7; 
END
#if 01  // DO RANDOM TESTS

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
for(int loop=0;loop<10000000;loop++) {
// param type: int
	vector <int> X; 
	{
		int N=UNIFORM_LL(1, 200);
		X = vector <int>(N); 
		REP(i, N) {
			X[i] = UNIFORM_LL(1, 5);
		}
	}
	int _0 = AmebaDiv1().count(X);
	int _1 = AmebaDiv1Ref().count(X);
	if(!verify_case(_0, _1, true)) {
print(X);
	}
}
#endif

}
// END CUT HERE
