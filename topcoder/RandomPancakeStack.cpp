// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Charlie has N pancakes.
He wants to serve some of them for breakfast.
We will number the pancakes 0 through N-1.
For each i, pancake i has width i+1 and deliciousness d[i].



Charlie chooses the pancakes he is going to serve using the following randomized process:
He starts by choosing the first pancake uniformly at random from all the pancakes he has.
He places the chosen pancake onto a plate.
This pancake now forms the bottom of a future stack of pancakes.
Then, Charlie repeats the following procedure:

If there are no more pancakes remaining, terminate.
Choose a pancake uniformly at random from the pancakes that have not been chosen yet.
If the width of this pancake is greater than the width of the pancake on top of the stack, terminate without taking it.
Place the chosen pancake on top of the stack and go back to step 1.




You are given the vector <int> d with N elements.
The total deliciousness of a serving of pancakes is the sum of the deliciousness of all pancakes used in the serving.
Compute and return the expected value of the total deliciousness of the pancakes chosen by Charlie.


DEFINITION
Class:RandomPancakeStack
Method:expectedDeliciousness
Parameters:vector <int>
Returns:double
Method signature:double expectedDeliciousness(vector <int> d)


NOTES
-Your return value must have an absolute or relative error smaller than or equal to 1e-6


CONSTRAINTS
-The number of elements in d will be between 1 and 250, inclusive.
-Each element of d will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{1,1,1}

Returns: 1.6666666666666667

The following scenarios may occur:

With probability 1/3, Charlie chooses pancake 0 first. In this case he won't be able to add any more pancakes and the total deliciousness of his serving of pancakes will be 1.
With probability 1/3, Charlie chooses pancake 1 first. What happens in the second round? With probability 1/2 he will choose pancake 0 and with probability 1/2 it will be pancake 2. In the first case the total deliciousness of Charlie's pancakes will be 2, in the second case it will be 1.
With probability 1/3, Charlie chooses pancake 2 first. If he chooses pancake 0 next, the total deliciousness of his pancakes will be 2. If he happens to choose pancake 1 next (followed by pancake 0 in the third round), the total deliciousness will be 3.


Summing this up, we get the expected deliciousness to be 1/3 * (1) + 1/3 * (1/2 * 1 + 1/2 * 2) + 1/3 * (1/2 * 2 + 1/2 * 3) = 5/3 = 1.666...

1)
{3,6,10,9,2}

Returns: 9.891666666666667



2)
{10,9,8,7,6,5,4,3,2,1}

Returns: 10.999999724426809



3)
{1,2,3,4,5,6,7,8,9,10}

Returns: 7.901100088183421



4)
{2,7,1,8,2,8,1,8,2,8,4,5,90,4,5,2,3,5,60,2,8,74,7,1}

Returns: 19.368705050402465



5)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

Returns: 1.718281828459045



******************************/
// END CUT HERE
#line 103 "RandomPancakeStack.cpp"
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

#define D long double

class RandomPancakeStack {
	public:
	D fac(int x) {
		D v = 1;
		REP(i, x) v*=i+1;
		return v;
	}
	D f(int x, int m, int N) {
		int k = N-m-1;
		if(N-x<m) return 0;
		return fac(N-x)*fac(k)/(fac(m)*fac(N-x-m));
	}
	double expectedDeliciousness(vector <int> d) {
		int N = d.size();
		D ans = 0;
		REP(v, N) {
			D lans = 0;
			REP(di, N) {
				D z = f(v+1, di, N);
				lans += z;
//				cout<<v+1<<" "<<di<<" "<<z<<endl;
			}
			lans *= d[v];
			ans += lans;
		}
		D div = fac(N);
		return ans / div;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const double& Expected, const double& Received, bool noPASSmsg=false) {
 double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, RandomPancakeStack().expectedDeliciousness(d));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int d_[] = {1,1,1};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	double _ = 1.6666666666666667; 
END
//return 0;
CASE(1)
	int d_[] = {3,6,10,9,2};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	double _ = 9.891666666666667; 
END
CASE(2)
	int d_[] = {10,9,8,7,6,5,4,3,2,1};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	double _ = 10.999999724426809; 
END
CASE(3)
	int d_[] = {1,2,3,4,5,6,7,8,9,10};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	double _ = 7.901100088183421; 
END
CASE(4)
	int d_[] = {2,7,1,8,2,8,1,8,2,8,4,5,90,4,5,2,3,5,60,2,8,74,7,1};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	double _ = 19.368705050402465; 
END
CASE(5)
	int d_[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	  vector <int> d(d_, d_+sizeof(d_)/sizeof(*d_)); 
	double _ = 1.718281828459045; 
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
		int N=UNIFORM_LL(1, 250);
		d = vector <int>(N); 
		REP(i, N) {
			d[i] = UNIFORM_LL(1, 1000);
		}
	}
	double _0 = RandomPancakeStack().expectedDeliciousness(d);
	double _1 = RandomPancakeStackRef().expectedDeliciousness(d);
	if(!verify_case(_0, _1, true)) {
print(d);
	}
}
#endif

}
// END CUT HERE
