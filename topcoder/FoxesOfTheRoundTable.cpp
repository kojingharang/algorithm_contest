// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// There are n foxes, numbered 0 through n-1.
You are given a vector <int> h with n elements.
The elements of h are the heights of those foxes.
Your task is to arrange all foxes around a round table.


Given an arrangement of foxes, let D be the largest height difference between adjacent foxes.
For example, suppose that four foxes with heights { 10, 30, 20, 40 } sit around the table in this order.
The height differences are |10-30|=20, |30-20|=10, |20-40|=20, and |40-10|=30.
(Note that the last fox is also adjacent to the first one, as this is a round table.)
Then, the value D is max(20,10,20,30) = 30.


Find an arrangement of the given foxes for which the value D is as small as possible.
Return a permutation of foxes that describes your arrangement.
I.e., return a vector <int> with n elements: the numbers of foxes in order around the table.
If there are multiple optimal solutions, you may return any of them.

DEFINITION
Class:FoxesOfTheRoundTable
Method:minimalDifference
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> minimalDifference(vector <int> h)


CONSTRAINTS
-h will contain between 3 and 50 elements, inclusive.
-Each element in h will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{1,99,50,50}

Returns: {0, 3, 1, 2 }

In the optimal solution the foxes with heights 1 and 99 mustn't be adjacent.
Hence, the heights of foxes have to be 1, 50, 99, 50, in this cyclic order, and the optimal value of D is 49.
One permutation that produces this order of foxes is 0, 3, 1, 2.

1)
{123,456,789}

Returns: {0, 1, 2 }

Whatever we do, the result will always be 789-123.

2)
{10,30,40,50,60}

Returns: {0, 1, 4, 3, 2 }

The permutation {0, 1, 4, 3, 2 } specifies that the heights of foxes are in the following order: 10, 30, 60, 50, 40.

3)
{1,2,3,4,8,12,13,14 }

Returns: {0, 1, 2, 3, 5, 6, 7, 4 }



4)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }

Returns: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 }



******************************/
// END CUT HERE
#line 77 "FoxesOfTheRoundTable.cpp"
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

int calcD(vector<int> val, vector<int> idx) {
	int N=val.size();
	vector<int> w(N);
	REP(i, N) {
		w[i] = val[idx[i]];
	}
	cout<<w<<endl;
	int D=0;
	REP(i, N) {
		D=max<int>(D, abs(w[i]-w[(i+1)%N]));
	}
	return D;
}

class FoxesOfTheRoundTable {
	public:
	int ref(vector <int> h) {
		int N=h.size();
		vector<int> idx(N);
		REP(i, N) idx[i]=i;
		int minD = 1<<30;
		do {
			minD = min<int>(minD, calcD(h, idx));
		} while(next_permutation(ALL(idx)));
		cout<<"minD = "<<minD<<endl;
		return minD;
	}
	vector <int> minimalDifference(vector <int> h) {
		int N=h.size();
		deque<int> w;
		deque<int> idx;
		vector<PII> hh(N);
		REP(i, N) hh[i]=MP(h[i], i);
		sort(ALL(hh));
		auto origH = h;
		cout<<"h "<<hh<<endl;
		REP(i, N) {
			if(i%2==0) w.push_back(hh[i].first);
			else w.push_front(hh[i].first);
			if(i%2==0) idx.push_back(hh[i].second);
			else idx.push_front(hh[i].second);
		}
		vector<int> ww(ALL(w));
		vector<int> rv(ALL(idx));
		cout<<"ww "<<ww<<endl;
		int D = calcD(origH, rv);
		cout<<"D = "<<D<<endl;
//		assert(ref(h)==D);

		cout<<w<<endl;
		cout<<idx<<endl;
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
#define END	 verify_case(_, FoxesOfTheRoundTable().minimalDifference(h)); cout<<"ref D = "<<calcD(h, _)<<endl;}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int h_[] = {1,99,50,50};
	  vector <int> h(h_, h_+sizeof(h_)/sizeof(*h_)); 
	int __[] = {0, 3, 1, 2 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
return 0;
CASE(0)
	int h_[] = {11, 15, 29, 31, 4, 15, 4, 74, 21, 22, 14, 25, 23, 11, 61, 53, 12, 23};
	  vector <int> h(h_, h_+sizeof(h_)/sizeof(*h_)); 
	int __[] = {4, 0, 16, 1, 8, 12, 11, 3, 14, 7, 15, 2, 17, 9, 5, 10, 13, 6};
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	int h_[] = {123,456,789};
	  vector <int> h(h_, h_+sizeof(h_)/sizeof(*h_)); 
	int __[] = {0, 1, 2 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	int h_[] = {10,30,40,50,60};
	  vector <int> h(h_, h_+sizeof(h_)/sizeof(*h_)); 
	int __[] = {0, 1, 4, 3, 2 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	int h_[] = {1,2,3,4,8,12,13,14 };
	  vector <int> h(h_, h_+sizeof(h_)/sizeof(*h_)); 
	int __[] = {0, 1, 2, 3, 5, 6, 7, 4 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
return 0;
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
REP(i, 1000) {
	vector<int> h(8);
	REP(i, h.size()) h[i] = UNIFORM_LL(1, 1001);
	FoxesOfTheRoundTable().minimalDifference(h);
}
//CASE(4)
//	int h_[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
//	  vector <int> h(h_, h_+sizeof(h_)/sizeof(*h_)); 
//	int __[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
//	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
//END
#if 0  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: int
	vector <int> h; 
	{
		int N=UNIFORM_LL(1, 51);
		h = vector <int>(N); 
		REP(i, N) {
			h[i] = UNIFORM_LL(0, 1000);
		}
	}
	vector <int> _0 = FoxesOfTheRoundTable().minimalDifference(h);
	vector <int> _1 = FoxesOfTheRoundTableRef().minimalDifference(h);
	if(!verify_case(_0, _1, true)) {
print(h);
	}
}
#endif

}
// END CUT HERE
