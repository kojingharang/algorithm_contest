// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You want to make a lot of sandwiches.
However, you only have a limited amount of cheese.
The only piece of cheese you currently have is a rectangular block with dimensions A, B, and C.

You can cut the block of cheese into smaller pieces.
You are only allowed to cut as follows:

Each cut must divide one block of cheese into two smaller blocks of cheese.
Each cut must be parallel to one of the faces of the piece you are cutting.
Each of the two smaller blocks must have integer dimensions.


When placing a block of cheese onto a piece of bread, the cheese is always rotated so that its shortest side is vertical.
In other words, suppose you have a block of cheese with dimensions (X,Y,Z) such that X ≥ Y ≥ Z.
If you place this block onto a piece of bread, its surface area will be X*Y and its thickness will be Z.

A block of cheese is called a good slice if and only if its thickness is greater than or equal to S.
(Recall that the thickness of a block is the length of its shortest side.)

You can cut your block of cheese into arbitrarily many pieces, as long as you follow the rules given above.
Your goal is to cut the block in such a way that maximizes the total surface area of all good slices among the pieces.
Note that your way of cutting may also produce some pieces that are not good slices, but those pieces won't contribute to the surface area.
The number of good slices does not matter, we only care about their surface.
Different good slices may have different dimensions.

You are given the ints A, B, C, and S.
Return the maximum total surface area of good slices you can get.

DEFINITION
Class:CheeseSlicing
Method:totalArea
Parameters:int, int, int, int
Returns:int
Method signature:int totalArea(int A, int B, int C, int S)


CONSTRAINTS
-A, B and C will be between 1 and 100, inclusive.
-S will be between 1 and 10, inclusive.


EXAMPLES

0)
1
3
3
2

Returns: 0

One of the dimensions of this block is 1.
Regardless of how we cut it, each piece will have one dimension equal to 1.
As S=2, this means that producing a good slice is impossible.
Hence, the maximum total surface area of good slices is 0.

1)
5
3
5
3

Returns: 25

The entire block is a good slice with thickness 3 and surface area 5*5 = 25.
An optimal solution is to make no cuts and to simply take this one block.

2)
5
5
5
2

Returns: 58

One possible sequence of cuts:

 5x5x5 -> 2x5x5 + 3x5x5 
 3x5x5 -> 3x2x5 + 3x3x5 
 3x3x5 -> 3x3x2 + 3x3x3 

After these three cuts we have four pieces: 2x5x5, 3x2x5, 3x3x2, and 3x3x3.
Each of these is a good slice.
Their total surface area is 5*5 + 3*5 + 3*3 + 3*3.

3)
49
92
20
3

Returns: 30045



*/
// END CUT HERE
#line 102 "CheeseSlicing.cpp"

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


struct T3 {
	int A, B, C;
	vector<int> so() {
		vector<int> rv = {A, B, C};
		sort(ALL(rv));
		return rv;
	}
	ll score(int S) {
		vector<int> rv = {A, B, C};
		sort(ALL(rv));
		return rv[0] >= S ? rv[1]*rv[2] : 0;
	}
};

class CheeseSlicingRef {
	public:
	int totalArea(int A, int B, int C, int S) {
		deque<T3> q;
		q.push_back(T3{A, B, C});
		int cnt=0;
		while(1) {
			bool updated=false;
			auto w = q.front().so();
			REP(i, 3) {
				if(S*2<=w[i]) {
					vector<int> v;
					REP(j, 3) if(i!=j) v.push_back(w[j]);
					auto n0 = T3{S, v[0], v[1]};
					auto n1 = T3{w[i]-S, v[0], v[1]};
					if(q.front().score(S) < n0.score(S) + n1.score(S)) {
						q.pop_front();
						q.push_back(n0);
						q.push_front(n1);
						updated=true;
						cnt=0;
						break;
					}
				}
			}
			if(!updated) {
				auto a = q.front();
				q.pop_front();
				q.push_back(a);
				if(++cnt>=q.size()*2) break;
			}
		}
		ll ans = 0;
		REP(i, q.size()) {
//			cout<<q[i].A<<" "<<q[i].B<<" "<<q[i].C<<endl;
			ans += q[i].score(S);
		}
		return ans;
	}
};

class CheeseSlicing {
	public:
	int totalArea(int A, int B, int C, int S) {
		if(A<S||B<S||C<S) return 0;
		int ans = 0;
		if(S==1) return A*B*C;
		if(A%S==0||B%S==0||C%S==0) return A*B*C/S;
		while(A>=2*S) {
			A-=S;
			ans+=B*C;
		}
		while(B>=2*S) {
			B-=S;
			ans+=A*C;
		}
		while(C>=2*S) {
			C-=S;
			ans+=B*A;
		}
		int h=min(A, B);
		h=min(C, h);
		ans += A*B*C/h;
		return ans;
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
#define END	 verify_case(_, CheeseSlicing().totalArea(A, B, C, S));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int A = 1; 
	int B = 3; 
	int C = 3; 
	int S = 2; 
	int _ = 0; 
END
CASE(1)
	int A = 5; 
	int B = 3; 
	int C = 5; 
	int S = 3; 
	int _ = 25; 
END
CASE(2)
	int A = 5; 
	int B = 5; 
	int C = 5; 
	int S = 2; 
	int _ = 58; 
END
CASE(3)
	int A = 49; 
	int B = 92; 
	int C = 20; 
	int S = 3; 
	int _ = 30045; 
END
CASE(3)
	int A = 100; 
	int B = 100; 
	int C = 100; 
	int S = 3; 
	int _ = 333328; 
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
for(int loop=0;loop<100000;loop++) {
// param type: int
	int A = UNIFORM_LL(1, 101); 
// param type: int
	int B = UNIFORM_LL(1, 101); 
// param type: int
	int C = UNIFORM_LL(1, 101); 
// param type: int
	int S = UNIFORM_LL(1, 11); 
	int _0 = CheeseSlicing().totalArea(A, B, C, S);
	int _1 = CheeseSlicingRef().totalArea(A, B, C, S);
	if(!verify_case(_0, _1, true)) {
print(A);
print(B);
print(C);
print(S);
	}
}
#endif

}
// END CUT HERE
