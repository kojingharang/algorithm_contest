// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
We have a sequence of N positive integers: a[0] through a[N-1].
You do not know these integers.
All you know is the number of trailing zeros in their binary representations.
You are given a vector <int> d with N elements.
For each i, d[i] is the number of trailing zeros in the binary representation of a[i].



For example, suppose that a[0]=40.
In binary, 40 is 101000 which ends in three zeros.
Therefore, d[0] will be 3.



You like arithmetic sequences with difference 1.
(That is, sequences in which each element is 1 greater than the previous one. For example, {4,5,6,7}.)
For simplicity, we will call these sequences "incrementing sequences".



You would like to count all non-empty contiguous subsequences of the sequence a[0], a[1], ..., a[N-1] that can be incrementing sequences (given the information you have in d).



More precisely:
For each pair (i,j) such that 0 <= i <= j <= N-1, we ask the following question: "Given the values d[i] through d[j], is it possible that the values a[i] through a[j] form an incrementing sequence?"



For example, suppose that d = {0,1,0,2,1}.
For i=0 and j=3 the answer is positive: it is possible that the values a[0] through a[3] are {1,2,3,4} which is an incrementing sequence.
For i=1 and j=4 the answer is negative: there is no incrementing sequence with these numbers of trailing zeros in binary.



Compute and return the number of contiguous subsequences of a[0], a[1], ..., a[N-1] that can be incrementing sequences.


DEFINITION
Class:PotentialArithmeticSequence
Method:numberOfSubsequences
Parameters:vector <int>
Returns:int
Method signature:int numberOfSubsequences(vector <int> d)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-d will contain exactly N elements.
-Each element of d will be between 0 and 1,000,000,000 (10^9), inclusive.


EXAMPLES

0)
{0,1,0,2,0,1,0}

Returns: 28

It is possible that the sequence a[0] through a[6] is {1,2,3,4,5,6,7}. All contiguous subsequences of this sequence are incrementing sequences.

1)
{0,0,0,0,0,0,0}

Returns: 7



2)
{0,0,0,0,1,1,1}

Returns: 8



3)
{0,100,0,2,0}

Returns: 11



4)
{1,11,3,0,1,0,1,0,1,0,1,0,3,0,2,0,0,0,0,1,2,3,20}

Returns: 49



******************************/
// END CUT HERE
#line 97 "PotentialArithmeticSequence.cpp"
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

class PotentialArithmeticSequence {
	public:
	int numberOfSubsequences(vector <int> d) {
		int mx = 1<<7;
		int N = d.size();
		VI w(mx+N);
		RANGE(i, 1, w.size()) while(!(i&1<<w[i]))w[i]++;
		REP(i, N) if(d[i]>6) d[i]=6;
		int ans = 0;
		REP(i, N) for(int j=N-1;j>=i;j--) {
			RANGE(x, 1, mx) {
				int ok=1;
				RANGE(k, i, j+1) {
					if(w[k-i+x]!=d[k]) ok=0;
				}
				if(ok) {
					ans++;
//					cout<<i<<" "<<j<<endl;
					break;
				}
			}
		}
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
#define END	 verify_case(_, PotentialArithmeticSequence().numberOfSubsequences(d));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){


CASE(0)
	int d_[] = {1000000000, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	int _ = 1275; 
END
CASE(0)
	int d_[] = {0,1,0,2,0,1,0};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	int _ = 28; 
END
CASE(1)
	int d_[] = {0,0,0,0,0,0,0};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	int _ = 7; 
END
CASE(2)
	int d_[] = {0,0,0,0,1,1,1};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	int _ = 8; 
END
CASE(3)
	int d_[] = {0,100,0,2,0};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	int _ = 11; 
END
CASE(4)
	int d_[] = {1,11,3,0,1,0,1,0,1,0,1,0,3,0,2,0,0,0,0,1,2,3,20};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	int _ = 49; 
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
	vector <int> d; 
	{
		int N=UNIFORM_LL(1, 51);
		d = vector <int>(N); 
		REP(i, N) {
			d[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = PotentialArithmeticSequence().numberOfSubsequences(d);
	int _1 = PotentialArithmeticSequenceRef().numberOfSubsequences(d);
	if(!verify_case(_0, _1, true)) {
print(d);
	}
}
#endif

}
// END CUT HERE
