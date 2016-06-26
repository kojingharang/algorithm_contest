// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
You are given an int N and a vector <int> pos.
We are interested in some permutations of the set {1,2,...,N}.
A permutation p is called good if the following condition is satisfied:
for each valid k, we have p(k) < p(k+1) if and only if k is an element of pos.



Return the number of good permutations, modulo 1,000,000,007.


DEFINITION
Class:PermutationCounts
Method:countPermutations
Parameters:int, vector <int>
Returns:int
Method signature:int countPermutations(int N, vector <int> pos)


CONSTRAINTS
-N will be between 1 and 1,000,000, inclusive.
-pos will contain between 0 and min(N-1, 2500) elements, inclusive.
-Elements of pos will be distinct.
-Each element of pos will be between 1 and N-1, inclusive.


EXAMPLES

0)
5
{3}

Returns: 9


Given that pos = {3}, we are looking for permutations where p(1) > p(2), p(2) > p(3), p(3) < p(4), and p(4) > p(5).
Thus, the good permutations are the following ones:



 {3,2,1,5,4} 
 {4,2,1,5,3} 
 {4,3,1,5,2} 
 {4,3,2,5,1} 
 {5,2,1,4,3} 
 {5,3,1,4,2} 
 {5,3,2,4,1} 
 {5,4,1,3,2} 
 {5,4,2,3,1} 


1)
13
{12,11,10,9,8,7,6,5,4,3,2,1}

Returns: 1



2)
13
{}

Returns: 1



3)
9
{2,4,5}

Returns: 1421



4)
80
{31,41,59,26,53,58,9,79,32,3,8,46}

Returns: 82650786



5)
875
{295,311,98,345,420,547,646,734,380,325,608,783,141,65,305,437,769,252,44,
872,123,6,50,507,450,426,343,740,69,695,101,607,597,535,342,307,329,837,803,
237,459,444,498,15,712,134,473,14,715,223,787,192,710,750,193,293,242,652,
212,580,545,488,506,533,774,460,285,534,350,210,559,805,686,67,159,541,706,
514,657,801,373,754,310,800,589,736,863,675,254,283,604,27,628,103,81,235,
677,461,609,30,581,75,756,688,262,563,679,21,217,515,836,868,13,728,717,
309,267,767,259,414,332,744,129,859,4,179,632,415,278,812,79,77,784,573,433,
865,407,121,477,567,790,127,593,57,674,114,239,599,552,738}

Returns: 169176190



******************************/
// END CUT HERE
#line 105 "PermutationCounts.cpp"
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
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
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

class PermutationCounts {
	public:
	int countPermutations(int N, vector <int> pos) {
		
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
#define END	 verify_case(_, PermutationCounts().countPermutations(N, pos));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int N = 5; 
	int pos_[] = {3};
	  vector <int> pos(pos_, pos_+sizeof(pos_)/sizeof(*pos_)); 
	int _ = 9; 
END
CASE(1)
	int N = 13; 
	int pos_[] = {12,11,10,9,8,7,6,5,4,3,2,1};
	  vector <int> pos(pos_, pos_+sizeof(pos_)/sizeof(*pos_)); 
	int _ = 1; 
END
CASE(2)
	int N = 13; 
	vector <int> pos; 
	int _ = 1; 
END
CASE(3)
	int N = 9; 
	int pos_[] = {2,4,5};
	  vector <int> pos(pos_, pos_+sizeof(pos_)/sizeof(*pos_)); 
	int _ = 1421; 
END
CASE(4)
	int N = 80; 
	int pos_[] = {31,41,59,26,53,58,9,79,32,3,8,46};
	  vector <int> pos(pos_, pos_+sizeof(pos_)/sizeof(*pos_)); 
	int _ = 82650786; 
END
CASE(5)
	int N = 875; 
	int pos_[] = {295,311,98,345,420,547,646,734,380,325,608,783,141,65,305,437,769,252,44,
872,123,6,50,507,450,426,343,740,69,695,101,607,597,535,342,307,329,837,803,
237,459,444,498,15,712,134,473,14,715,223,787,192,710,750,193,293,242,652,
212,580,545,488,506,533,774,460,285,534,350,210,559,805,686,67,159,541,706,
514,657,801,373,754,310,800,589,736,863,675,254,283,604,27,628,103,81,235,
677,461,609,30,581,75,756,688,262,563,679,21,217,515,836,868,13,728,717,
309,267,767,259,414,332,744,129,859,4,179,632,415,278,812,79,77,784,573,433,
865,407,121,477,567,790,127,593,57,674,114,239,599,552,738};
	  vector <int> pos(pos_, pos_+sizeof(pos_)/sizeof(*pos_)); 
	int _ = 169176190; 
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
	int N = UNIFORM_LL(0, 100); 
// param type: int
	vector <int> pos; 
	{
		int N=UNIFORM_LL(1, 51);
		pos = vector <int>(N); 
		REP(i, N) {
			pos[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = PermutationCounts().countPermutations(N, pos);
	int _1 = PermutationCountsRef().countPermutations(N, pos);
	if(!verify_case(_0, _1, true)) {
print(N);
print(pos);
	}
}
#endif

}
// END CUT HERE
