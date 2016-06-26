// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Your task is to find n positive integers.
We will label them x[0] through x[n-1].



We will give you some information about these integers.
Namely, for some pairs of integers we will tell you their greatest common divisor (GCD), and for some pairs we will tell you their least common multiple (LCM).



You are given the int n.
You are also given a string type and three vector <int>s: A, B, and C.
These vector <int>s will all have the same number of elements, and type will contain the corresponding number of characters.
Their meaning is as follows:
For each valid i, we have some information about the integers x[ A[i] ] and x[ B[i] ].
If type[i] is 'G', the greatest common divisor of these two integers must be C[i].
If type[i] is 'L', the least common multiple of these two integers must be C[i].



Return "Solution exists" (quotes for clarity) if there is at least one way to choose x[0] through x[n-1] so that all requirements are satisfied.
Otherwise, return "Solution does not exist".

DEFINITION
Class:GCDLCM
Method:possible
Parameters:int, string, vector <int>, vector <int>, vector <int>
Returns:string
Method signature:string possible(int n, string type, vector <int> A, vector <int> B, vector <int> C)


CONSTRAINTS
-n will be between 1 and 200, inclusive.
-A will contain between 1 and 200 elements, inclusive.
-A and B will contain the same number of elements.
-A and C will contain the same number of elements.
-The number of elements in A will be the same as the number of characters in type
-Each character in type will be 'G' or 'L'.
-Each element in A will be between 0 and n-1, inclusive.
-Each element in B will be between 0 and n-1, inclusive.
-For each i, A[i] and B[i] will be different.
-Each element in C will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
4
"GLGLGLGL"
{0,0,1,1,2,2,3,3}
{1,1,2,2,3,3,0,0}
{6,12,6,12,6,12,6,12}

Returns: "Solution exists"

We have 4 unknown integers: x[0], x[1], x[2], and x[3].
The given A, B, C, and type encode the following information:

The GCD of x[0] and x[1] must be 6 and their LCM must be 12.
The GCD of x[1] and x[2] must be 6 and their LCM must be 12.
The GCD of x[2] and x[3] must be 6 and their LCM must be 12.
The GCD of x[3] and x[0] must be 6 and their LCM must be 12.

There are two valid solutions.
In one of them, x[0] = x[2] = 6 and x[1] = x[3] = 12.

1)
5
"GLGLGLGLGL"
{0,0,1,1,2,2,3,3,4,4}
{1,1,2,2,3,3,4,4,0,0}
{6,12,6,12,6,12,6,12,6,12}

Returns: "Solution does not exist"

This time we have no solution.

2)
11
"GGGGGGGGGG"
{0,0,0,0,0,0,0,0,0,0}
{1,2,3,4,5,6,7,8,9,10}
{2,3,5,7,11,13,17,19,23,29}

Returns: "Solution exists"

One possible solution is: {6469693230,2,3,5,7,11,13,17,19,23,29}. Note that the numbers in our solution can be very large.

3)
12
"GLLGGGLGLLGL"
{0,1,2,3,4,5,6,7,8,9,10,11}
{1,2,3,4,5,6,7,8,9,10,11,0}
{1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000}

Returns: "Solution exists"

One possible solution: each x[i] is equal to 1000000000.

4)
12
"GLLGGGLGLLGL"
{0,1,2,3,4,5,6,7,8,9,10,11}
{1,2,3,4,5,6,7,8,9,10,11,0}
{1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,999999999}

Returns: "Solution does not exist"



5)
200
"G"
{11}
{20}
{19911120}

Returns: "Solution exists"



******************************/
// END CUT HERE
#line 128 "GCDLCM.cpp"
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

class GCDLCM {
	public:
	string possible(int n, string type, vector <int> A, vector <int> B, vector <int> C) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const string& Expected, const string& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, GCDLCM().possible(n, type, A, B, C));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int n = 4; 
	string type = "GLGLGLGL"; 
	int A_[] = {0,0,1,1,2,2,3,3};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {1,1,2,2,3,3,0,0};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {6,12,6,12,6,12,6,12};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	string _ = "Solution exists"; 
END
CASE(1)
	int n = 5; 
	string type = "GLGLGLGLGL"; 
	int A_[] = {0,0,1,1,2,2,3,3,4,4};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {1,1,2,2,3,3,4,4,0,0};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {6,12,6,12,6,12,6,12,6,12};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	string _ = "Solution does not exist"; 
END
CASE(2)
	int n = 11; 
	string type = "GGGGGGGGGG"; 
	int A_[] = {0,0,0,0,0,0,0,0,0,0};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {1,2,3,4,5,6,7,8,9,10};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {2,3,5,7,11,13,17,19,23,29};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	string _ = "Solution exists"; 
END
CASE(3)
	int n = 12; 
	string type = "GLLGGGLGLLGL"; 
	int A_[] = {0,1,2,3,4,5,6,7,8,9,10,11};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {1,2,3,4,5,6,7,8,9,10,11,0};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	string _ = "Solution exists"; 
END
CASE(4)
	int n = 12; 
	string type = "GLLGGGLGLLGL"; 
	int A_[] = {0,1,2,3,4,5,6,7,8,9,10,11};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {1,2,3,4,5,6,7,8,9,10,11,0};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,999999999};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	string _ = "Solution does not exist"; 
END
CASE(5)
	int n = 200; 
	string type = "G"; 
	int A_[] = {11};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {20};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {19911120};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	string _ = "Solution exists"; 
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
	int n = UNIFORM_LL(0, 100); 
// param type: String
	string type; 
	{
		int N=UNIFORM_LL(1, 51);
		type = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			type[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
// param type: int
	vector <int> A; 
	{
		int N=UNIFORM_LL(1, 51);
		A = vector <int>(N); 
		REP(i, N) {
			A[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> B; 
	{
		int N=UNIFORM_LL(1, 51);
		B = vector <int>(N); 
		REP(i, N) {
			B[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> C; 
	{
		int N=UNIFORM_LL(1, 51);
		C = vector <int>(N); 
		REP(i, N) {
			C[i] = UNIFORM_LL(0, 1000);
		}
	}
	string _0 = GCDLCM().possible(n, type, A, B, C);
	string _1 = GCDLCMRef().possible(n, type, A, B, C);
	if(!verify_case(_0, _1, true)) {
print(n);
print(type);
print(A);
print(B);
print(C);
	}
}
#endif

}
// END CUT HERE
