// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Fox Ciel has a family crest.
The crest is a simple line drawing that consists of several line segments.
You are given the description of the crest as four equally long vector <int>s: A, B, C, and D.
For each valid i, the crest contains a line segment that connects the points (A[i], B[i]) and (C[i], D[i]).
Note that some of the given line segments may intersect and even overlap each other.

Fox Ciel got a large square piece of paper with side length 1,000,000,000.
She is now going to draw some copies of her family crest onto the paper.
All copies must have the same size as the original described by A, B, C, and D.
Also, all copies must have the same orientation.
In other words, once she draws the first copy, all other copies must be obtained by translation only (without any rotation or resizing).
Additionally, the copies must be pairwise disjoint.
(I.e., they are not allowed to share any points at all.)

Return "Infinite" (quotes for clarity) if it is possible to draw an infinite number of non-overlapping copies of the family crest onto the paper.
Otherwise, return "Finite".

DEFINITION
Class:FamilyCrest
Method:canBeInfinite
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:string
Method signature:string canBeInfinite(vector <int> A, vector <int> B, vector <int> C, vector <int> D)


CONSTRAINTS
-A will contain between 1 and 50 elements, inclusive.
-A, B, C and D will contain same number of elements.
-Elements in A, B, C, D will be between -1,000 and 1,000, inclusive.
-For each i, (A[i], B[i]) and (C[i], D[i]) will be different.


EXAMPLES

0)
{0}
{0}
{0}
{1}

Returns: "Infinite"


This family crest contains only one line segment: (0,0)-(0,1).
We can easily draw an infinite number of disjoint copies of this family crest.
For example, we can draw the segments (1/x,0) - (1/x,1) for each positive integer x.
(Note that the vertices of the copies are not required to have integer coordinates.)

1)
{0,1,1,0}
{0,0,1,1}
{1,1,0,0}
{0,1,1,0}

Returns: "Finite"


This family crest is the unit square.
It is clearly impossible for one unit square to contain another one, so each of them will have to be drawn outside of all others.
And as the area of the whole paper is 1,000,000,000^2, we clearly cannot draw more than 1,000,000,000^2 copies of the unit square.

2)
{0,1,2,3}
{0,3,0,3}
{1,2,3,4}
{3,0,3,0}

Returns: "Infinite"



3)
{0,1,2,3,-1,-3,-1}
{0,3,0,3,3,2,1}
{1,2,3,4,-3,-1,-3}
{3,0,3,0,2,1,0}

Returns: "Finite"



4)
{0,2,4,6,-1,-2,-1}
{0,1,0,1,3,2,1}
{2,4,6,8,-2,-1,-2}
{1,0,1,0,2,1,0}

Returns: "Infinite"



5)
{0,0,0,2,3,3,4,5,6,7,9,9,9,9}
{0,2,1,0,0,2,0,0,2,0,0,2,1,0}
{0,1,1,2,3,4,4,5,8,7,9,10,10,10}
{2,2,1,2,2,0,2,2,2,2,2,2,1,0}

Returns: "Finite"



6)
{-6,-3,3,-6,-3,3}
{1,2,-2,-1,-2,2}
{-3,3,6,-3,3,6}
{2,-2,-1,-2,2,1}

Returns: "Finite"



7)
{-1,-2,0,1}
{0,0,0,0}
{1,0,2,-1}
{0,0,0,0}

Returns: "Infinite"


Note that the line segments that form the family crest may sometimes overlap.

******************************/
// END CUT HERE
#line 129 "FamilyCrest.cpp"
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

class FamilyCrest {
	public:
	double nor(double rad) {
		while(rad<0) rad+=M_PI*2;
		while(rad>M_PI*2) rad-=M_PI*2;
		return rad;
	}
	string canBeInfinite(vector <int> A, vector <int> B, vector <int> C, vector <int> D) {
		int N=A.size();
		double RA=0, RB=0;
		REP(i, N) {
			REP(j, N-1) {
				double ra = nor(atan2(D[j]-B[i], C[j]-A[i]));
				double rb = nor(atan2(D[j+1]-B[i], C[j+1]-A[i]));
				if(nor(rb-ra) > M_PI) swap(ra, rb);
				// [ra, rb] is dame
				// [RA, RB] union= [ra, rb]
			}
		}
		// [RA, RB] != [0, 2PI] -> infinite
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const string& Expected, const string& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, FamilyCrest().canBeInfinite(A, B, C, D));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int A_[] = {0};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {0};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {0};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	int D_[] = {1};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	string _ = "Infinite"; 
END
CASE(1)
	int A_[] = {0,1,1,0};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {0,0,1,1};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {1,1,0,0};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	int D_[] = {0,1,1,0};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	string _ = "Finite"; 
END
CASE(2)
	int A_[] = {0,1,2,3};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {0,3,0,3};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {1,2,3,4};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	int D_[] = {3,0,3,0};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	string _ = "Infinite"; 
END
CASE(3)
	int A_[] = {0,1,2,3,-1,-3,-1};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {0,3,0,3,3,2,1};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {1,2,3,4,-3,-1,-3};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	int D_[] = {3,0,3,0,2,1,0};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	string _ = "Finite"; 
END
CASE(4)
	int A_[] = {0,2,4,6,-1,-2,-1};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {0,1,0,1,3,2,1};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {2,4,6,8,-2,-1,-2};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	int D_[] = {1,0,1,0,2,1,0};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	string _ = "Infinite"; 
END
CASE(5)
	int A_[] = {0,0,0,2,3,3,4,5,6,7,9,9,9,9};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {0,2,1,0,0,2,0,0,2,0,0,2,1,0};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {0,1,1,2,3,4,4,5,8,7,9,10,10,10};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	int D_[] = {2,2,1,2,2,0,2,2,2,2,2,2,1,0};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	string _ = "Finite"; 
END
CASE(6)
	int A_[] = {-6,-3,3,-6,-3,3};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {1,2,-2,-1,-2,2};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {-3,3,6,-3,3,6};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	int D_[] = {2,-2,-1,-2,2,1};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	string _ = "Finite"; 
END
CASE(7)
	int A_[] = {-1,-2,0,1};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {0,0,0,0};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {1,0,2,-1};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	int D_[] = {0,0,0,0};
	  vector <int> D(D_, D_+sizeof(D_)/sizeof(*D_)); 
	string _ = "Infinite"; 
END
#if 0  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10;loop++) {
// param type: int
start_time=clock();
	vector <int> A; 
	{
		int N=UNIFORM_LL(1, 50);
		A = vector <int>(N); 
		REP(i, N) {
			A[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
start_time=clock();
	vector <int> B; 
	{
		int N=UNIFORM_LL(1, 50);
		B = vector <int>(N); 
		REP(i, N) {
			B[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
start_time=clock();
	vector <int> C; 
	{
		int N=UNIFORM_LL(1, 50);
		C = vector <int>(N); 
		REP(i, N) {
			C[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
start_time=clock();
	vector <int> D; 
	{
		int N=UNIFORM_LL(1, 50);
		D = vector <int>(N); 
		REP(i, N) {
			D[i] = UNIFORM_LL(0, 1000);
		}
	}
	string _0 = FamilyCrest().canBeInfinite(A, B, C, D);
	string _1 = FamilyCrestTry().canBeInfinite(A, B, C, D);
	if(!verify_case(_0, _1, true)) {
print(A);
print(B);
print(C);
print(D);
	}
}
#endif

}
// END CUT HERE
