// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Little Elephant from the Zoo of Lviv likes integers.




You are given an vector <int> A. On a single turn, Little Elephant can double (i.e., multiply by 2) any element of A. He may double the same element more than once, if he wants to. He wants to obtain an array in which all elements are equal. Return "YES" (quotes for clarity) if it is possible to do that and "NO" otherwise.



DEFINITION
Class:LittleElephantAndDouble
Method:getAnswer
Parameters:vector <int>
Returns:string
Method signature:string getAnswer(vector <int> A)


NOTES
-The return value is case-sensitive. Make sure that you return the exact strings "YES" and "NO".


CONSTRAINTS
-A will contain between 1 and 50 elements, inclusive.
-Each element of A will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1, 2}

Returns: "YES"

One possible way of making all elements equal is to double the element at index 0.

1)
{1, 2, 3}

Returns: "NO"

It's impossible to make all three elements equal in this case.

2)
{4, 8, 2, 1, 16}

Returns: "YES"



3)
{94, 752, 94, 376, 1504}

Returns: "YES"



4)
{148, 298, 1184}

Returns: "NO"



5)
{7, 7, 7, 7}

Returns: "YES"



******************************/
// END CUT HERE
#line 78 "LittleElephantAndDouble.cpp"
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

class LittleElephantAndDouble {
	public:
	string getAnswer(vector <int> A) {
		cout<<A<<endl;
		int X=*max_element(ALL(A));
		REP(i, A.size()) while(A[i]<X)A[i]*=2;
		return (X==*max_element(ALL(A))) ? "YES" : "NO";
	}
};

class LittleElephantAndDoubleTry {
	public:
	string getAnswer(vector <int> A) {
		string r="YES";
		sort(ALL(A));
		REP(i, A.size()) {
			RANGE(j, i+1, A.size()) {
				if(A[j]%A[i]!=0) r="NO";
			}
		}
		return r;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
void verify_case(const string& Expected, const string& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, LittleElephantAndDouble().getAnswer(A));}
int main(){

CASE(0)
	int A_[] = {1, 2};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string _ = "YES"; 
END
CASE(1)
	int A_[] = {1, 2, 3};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string _ = "NO"; 
END
CASE(2)
	int A_[] = {4, 8, 2, 1, 16};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string _ = "YES"; 
END
CASE(3)
	int A_[] = {94, 752, 94, 376, 1504};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string _ = "YES"; 
END
CASE(4)
	int A_[] = {148, 298, 1184};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string _ = "NO"; 
END
CASE(5)
	int A_[] = {7, 7, 7, 7};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string _ = "YES"; 
END
#if 01  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<1000;loop++) {
// param type: int
start_time=clock();
	vector <int> A; 
	{
		int N=UNIFORM_LL(1, 5);
		A = vector <int>(N); 
		REP(i, N) {
			A[i] = UNIFORM_LL(1, 10);
		}
	}
	string _0 = LittleElephantAndDouble().getAnswer(A);
	string _1 = LittleElephantAndDoubleTry().getAnswer(A);
	cout<<A<<endl;
	verify_case(_0, _1);
}
#endif

}
// END CUT HERE
