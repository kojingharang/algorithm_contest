// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// There is a narrow passage.
Inside the passage there are some wolves.
You are given a vector <int> size that contains the sizes of those wolves, from left to right.



The passage is so narrow that some pairs of wolves cannot pass by each other.
More precisely, two adjacent wolves may swap places if and only if the sum of their sizes is maxSizeSum or less.
Assuming that no wolves leave the passage, what is the number of different permutations of wolves in the passage?
Note that two wolves are considered different even if they have the same size.



Let X be the number of permutations of wolves that can be obtained from their initial order by swapping a pair of wolves zero or more times.
Compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:NarrowPassage2
Method:count
Parameters:vector <int>, int
Returns:int
Method signature:int count(vector <int> size, int maxSizeSum)


CONSTRAINTS
-size will contain between 1 and 50 elements, inclusive.
-Each element in size will be between 1 and 1,000,000,000, inclusive.
-maxSizeSum will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1, 2, 3}
3

Returns: 2

From {1, 2, 3}, you can swap 1 and 2 to get {2, 1, 3}. But you can't get other permutations.

1)
{1, 2, 3}
1000

Returns: 6

Here you can swap any two adjacent wolves. Thus, all 3! = 6 permutations are possible.

2)
{1, 2, 3}
4

Returns: 3

You can get {1, 2, 3}, {2, 1, 3} and {2, 3, 1}.

3)
{1,1,1,1,1,1,1,1,1,1,1,1,1}
2

Returns: 227020758

All of these wolves are different, even though their sizes are the same. Thus, there are 13! different permutations possible.

4)
{2,4,6,1,3,5}
8

Returns: 60



5)
{1000000000}
1000000000

Returns: 1



******************************/
// END CUT HERE
#line 87 "NarrowPassage2.cpp"
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

class NarrowPassage2 {
	public:
	int count(vector <int> size, int maxSizeSum) {
		
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
#define END	 verify_case(_, NarrowPassage2().count(size, maxSizeSum));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int size_[] = {1, 2, 3};
	  vector <int> size(size_, size_+sizeof(size_)/sizeof(*size_)); 
	int maxSizeSum = 3; 
	int _ = 2; 
END
CASE(1)
	int size_[] = {1, 2, 3};
	  vector <int> size(size_, size_+sizeof(size_)/sizeof(*size_)); 
	int maxSizeSum = 1000; 
	int _ = 6; 
END
CASE(2)
	int size_[] = {1, 2, 3};
	  vector <int> size(size_, size_+sizeof(size_)/sizeof(*size_)); 
	int maxSizeSum = 4; 
	int _ = 3; 
END
CASE(3)
	int size_[] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
	  vector <int> size(size_, size_+sizeof(size_)/sizeof(*size_)); 
	int maxSizeSum = 2; 
	int _ = 227020758; 
END
CASE(4)
	int size_[] = {2,4,6,1,3,5};
	  vector <int> size(size_, size_+sizeof(size_)/sizeof(*size_)); 
	int maxSizeSum = 8; 
	int _ = 60; 
END
CASE(5)
	int size_[] = {1000000000};
	  vector <int> size(size_, size_+sizeof(size_)/sizeof(*size_)); 
	int maxSizeSum = 1000000000; 
	int _ = 1; 
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
	vector <int> size; 
	{
		int N=UNIFORM_LL(1, 51);
		size = vector <int>(N); 
		REP(i, N) {
			size[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int maxSizeSum = UNIFORM_LL(0, 100); 
	int _0 = NarrowPassage2().count(size, maxSizeSum);
	int _1 = NarrowPassage2Ref().count(size, maxSizeSum);
	if(!verify_case(_0, _1, true)) {
print(size);
print(maxSizeSum);
	}
}
#endif

}
// END CUT HERE
