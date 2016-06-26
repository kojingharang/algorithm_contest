// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Correct parentheses sequences can be defined recursively as follows:

The empty string "" is a correct sequence.
If "X" and "Y" are correct sequences, then "XY" (the concatenation of X and Y) is a correct sequence.
If "X" is a correct sequence, then "(X)" is a correct sequence.
Each correct parentheses sequence can be derived using the above rules.

Examples of correct parentheses sequences include "", "()", "()()()", "(()())", and "(((())))".


You are given a string s.
You are also given vector <int>s L and R, each with the same number of elements.
These encode a set of conditions.
For each valid i, you have to satisfy the following condition:
the substring of s that begins at the 0-based index L[i] and ends at the 0-based index R[i] must be a correct parentheses sequence.



You can only modify s in one way: in each step you can choose two characters of s and swap them.
Return the minimal number of swaps needed to produce a string that satisfies all the given conditions.
If it is impossible, return -1 instead.

DEFINITION
Class:ParenthesesDiv1Medium
Method:minSwaps
Parameters:string, vector <int>, vector <int>
Returns:int
Method signature:int minSwaps(string s, vector <int> L, vector <int> R)


CONSTRAINTS
-s will contain between 1 and 2,000 characters, inclusive.
-Each character in s will be '(' or ')'.
-L will contain between 1 and 2,000 elements, inclusive.
-L and R will contain the same number of elements.
-For each valid i, 0 <= L[i] <= R[i] < |s|.


EXAMPLES

0)
")("
{0,0,0,0}
{1,1,1,1}

Returns: 1

We have four identical conditions.
Each of them tells us that the substring that begins at index 0 and ends at index 1 must be a correct parentheses sequence.
We can satisfy all conditions by swapping s[0] with s[1].
This swap produces the string "()".


1)
"(())"
{0,2}
{1,3}

Returns: 1

The only way to satisfy both conditions is to change s into "()()".
This can be done in 1 swap: by swapping s[1] with s[2].


2)
"(((())"
{0,2}
{1,3}

Returns: 2

This time we do swap(s[1],s[4]) and swap(s[3],s[5]).

3)
"((((((((("
{0,2}
{1,3}

Returns: -1



4)
"()()()()"
{0,0,0,0,2,2,2,4,4,6}
{1,3,5,7,3,5,7,5,7,7}

Returns: 0



5)
")()(()()((())()()()()()()))(()())()()()("
{3,5,17,25,35}
{12,10,30,30,38}

Returns: 3



******************************/
// END CUT HERE
#line 107 "ParenthesesDiv1Medium.cpp"
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

class ParenthesesDiv1Medium {
	public:
	int minSwaps(string s, vector <int> L, vector <int> R) {
		
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
#define END	 verify_case(_, ParenthesesDiv1Medium().minSwaps(s, L, R));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string s = ")("; 
	int L_[] = {0,0,0,0};
	  vector <int> L(L_, L_+sizeof(L_)/sizeof(*L_)); 
	int R_[] = {1,1,1,1};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int _ = 1; 
END
CASE(1)
	string s = "(())"; 
	int L_[] = {0,2};
	  vector <int> L(L_, L_+sizeof(L_)/sizeof(*L_)); 
	int R_[] = {1,3};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int _ = 1; 
END
CASE(2)
	string s = "(((())"; 
	int L_[] = {0,2};
	  vector <int> L(L_, L_+sizeof(L_)/sizeof(*L_)); 
	int R_[] = {1,3};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int _ = 2; 
END
CASE(3)
	string s = "((((((((("; 
	int L_[] = {0,2};
	  vector <int> L(L_, L_+sizeof(L_)/sizeof(*L_)); 
	int R_[] = {1,3};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int _ = -1; 
END
CASE(4)
	string s = "()()()()"; 
	int L_[] = {0,0,0,0,2,2,2,4,4,6};
	  vector <int> L(L_, L_+sizeof(L_)/sizeof(*L_)); 
	int R_[] = {1,3,5,7,3,5,7,5,7,7};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int _ = 0; 
END
CASE(5)
	string s = ")()(()()((())()()()()()()))(()())()()()("; 
	int L_[] = {3,5,17,25,35};
	  vector <int> L(L_, L_+sizeof(L_)/sizeof(*L_)); 
	int R_[] = {12,10,30,30,38};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int _ = 3; 
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
	string s; 
	{
		int N=UNIFORM_LL(1, 51);
		s = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			s[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
// param type: int
	vector <int> L; 
	{
		int N=UNIFORM_LL(1, 51);
		L = vector <int>(N); 
		REP(i, N) {
			L[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> R; 
	{
		int N=UNIFORM_LL(1, 51);
		R = vector <int>(N); 
		REP(i, N) {
			R[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = ParenthesesDiv1Medium().minSwaps(s, L, R);
	int _1 = ParenthesesDiv1MediumRef().minSwaps(s, L, R);
	if(!verify_case(_0, _1, true)) {
print(s);
print(L);
print(R);
	}
}
#endif

}
// END CUT HERE
