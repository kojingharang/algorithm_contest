// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Let S be a sequence of (not necessarily distinct) integers.
We say that S is closed under addition if it has the following property:
For any pair of valid and distinct indices i and j, the number S[i]+S[j] does also occur in the sequence S (one or more times).





Note that the numbers S[i] and S[j] may be equal, only the indices i and j are required to be distinct.
Also note that from the definition it follows that any 0-element or 1-element sequence is closed under addition, as there are no valid pairs of distinct indices into such a sequence.





You are given a sequence of integers in a vector <int> elements.
Return "closed" (quotes for clarity) if the given sequence is closed under addition.
Otherwise, return "not closed".


DEFINITION
Class:SumFullSet
Method:isSumFullSet
Parameters:vector <int>
Returns:string
Method signature:string isSumFullSet(vector <int> elements)


CONSTRAINTS
-Number of elements in elements will be between 1 and 50, both inclusive.
-Each element of elements will be between -50 and 50, both inclusive.


EXAMPLES

0)
{-1,0,1}

Returns: "closed"


(-1) + 0 = (-1), which does appear in our sequence
(-1) + 1 = 0, which does appear in our sequence
0 + 1 = 1, which does appear in our sequence
hence, our sequence is closed under addition


1)
{-1,1}

Returns: "not closed"



2)
{0,1}

Returns: "closed"



3)
{0,1,1}

Returns: "not closed"

This sequence is not closed under addition because 1+1 = 2, which is not an element of our sequence.

4)
{16,0,43,43,-36,-49,-46,-16,40,34,-43,-24,13,-48,45,19,12,0,43,6,26,-23,50,28,-3,21,46,45,-32,-41,0,-27,42,19,47,-36,-21,-1,5,-21,-28,-43,23,-26,-5,21,-41,16,-37,38}

Returns: "not closed"



5)
{10}

Returns: "closed"

A 1-element sequence is closed under addition by definition.

******************************/
// END CUT HERE
#line 90 "SumFullSet.cpp"
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

class SumFullSet {
	public:
	string isSumFullSet(vector <int> el) {
		int N=el.size();
		int OK=1;
		REP(i, N) RANGE(j, i+1, N) {
			int ok=0;
			REP(k, N) if(el[i]+el[j]==el[k]) ok=1;
			if(!ok) OK=0;
		}
		return OK ? "closed":"not closed";
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
#define END	 verify_case(_, SumFullSet().isSumFullSet(elements));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int elements_[] = {-1,0,1};
	  vector <int> elements(elements_, elements_+sizeof(elements_)/sizeof(*elements_)); 
	string _ = "closed"; 
END
CASE(1)
	int elements_[] = {-1,1};
	  vector <int> elements(elements_, elements_+sizeof(elements_)/sizeof(*elements_)); 
	string _ = "not closed"; 
END
CASE(2)
	int elements_[] = {0,1};
	  vector <int> elements(elements_, elements_+sizeof(elements_)/sizeof(*elements_)); 
	string _ = "closed"; 
END
CASE(3)
	int elements_[] = {0,1,1};
	  vector <int> elements(elements_, elements_+sizeof(elements_)/sizeof(*elements_)); 
	string _ = "not closed"; 
END
CASE(4)
	int elements_[] = {16,0,43,43,-36,-49,-46,-16,40,34,-43,-24,13,-48,45,19,12,0,43,6,26,-23,50,28,-3,21,46,45,-32,-41,0,-27,42,19,47,-36,-21,-1,5,-21,-28,-43,23,-26,-5,21,-41,16,-37,38};
	  vector <int> elements(elements_, elements_+sizeof(elements_)/sizeof(*elements_)); 
	string _ = "not closed"; 
END
CASE(5)
	int elements_[] = {10};
	  vector <int> elements(elements_, elements_+sizeof(elements_)/sizeof(*elements_)); 
	string _ = "closed"; 
END
CASE(5)
	int elements_[] = {};
	  vector <int> elements(elements_, elements_+sizeof(elements_)/sizeof(*elements_)); 
	string _ = "closed"; 
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
	vector <int> elements; 
	{
		int N=UNIFORM_LL(1, 51);
		elements = vector <int>(N); 
		REP(i, N) {
			elements[i] = UNIFORM_LL(0, 1000);
		}
	}
	string _0 = SumFullSet().isSumFullSet(elements);
	string _1 = SumFullSetRef().isSumFullSet(elements);
	if(!verify_case(_0, _1, true)) {
print(elements);
	}
}
#endif

}
// END CUT HERE
