// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// In probability theory and statistics, variance is the expectation of the squared deviation of a random variable from its mean.
As a special case, we can compute the variance of a nonempty finite collection of numbers X = { x_1, ..., x_n } as follows:

Let mu = (x_1 + ... + x_n) / n be the mean of the collection.
Let y_i = (x_i - mu)^2 be the square of the difference between x_i and the mean.
The variance of X, denoted var(X), can now be computed as the average of all y_i. (In other words, as the sum of all y_i, divided by n.)


For example, if X = { 0, 1 }, we have mu = 1/2, then y_1 = y_2 = 1/4, and finally var(X) = (1/4 + 1/4) / 2 = 1/4.


Another example: suppose X = { 0, 0, 0, 1 }. Now we have mu = 1/4. Then we compute that y_1 = y_2 = y_3 = 1/16 and y_4 = 9/16. The average of these four values is 3/16.


You are given a tree T with n vertices, labeled 0 through n-1.
More precisely, you are given the vector <int> p with n-1 elements that describes the edges of the tree.
For each valid i, there is an edge between (i+1) and p[i].
The constraints ensure that this will always be a valid tree.


Each vertex of the tree has a positive integer weight.
You are given these weights in the vector <int> weight with n elements.


A subtree of the tree T is any subgraph that is a tree.
Alice found all nonempty subtrees of T.
For each of them, she took the collection of weights of its vertices and she computed its variance.
Bob then computed the average of all the variances computed by Alice.
Compute and return the number Bob computed.

DEFINITION
Class:AverageVarianceSubtree
Method:average
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double average(vector <int> p, vector <int> weight)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-weight will contain between 1 and 50 elements, inclusive.
-Each element in weight will be between 1 and 1,000,000,000, inclusive.
-p will contain exactly |weight|-1 elements.
-For each i, 0 <= p[i] <= i.


EXAMPLES

0)
{0,1}
{10,20,30}

Returns: 19.444444444444443

The tree contains the edges 1-0 and 2-1.
Thus, it looks as follows: 0-1-2.

This tree has six different subtrees.
These correspond to the following collections of weights: {10}, {20}, {30}, {10,20}, {20,30}, and {10,20,30}.
Their variances are 0, 0, 0, 25, 25, and 200/3.
The return value is the average of these six numbers.

1)
{0,1,1}
{10,20,7,6}

Returns: 23.014520202020204

This time the tree looks as shown below. (The numbers in the figure are the weights of those vertices.)

10 - 20 - 7
     |
     6

This tree has 11 nonempty subtrees.
Below we list the collection of weights and its variance for each of the subtrees.

{10}, 0.0000000000000000
{20}, 0.0000000000000000
{7}, 0.0000000000000000
{6}, 0.0000000000000000
{10,20}, 25.0000000000000000
{7,20}, 42.2500000000000000
{6,20}, 49.0000000000000000
{20,7,6}, 40.6666666666666643
{10,20,6}, 34.6666666666666643
{10,20,7}, 30.8888888888888857
{10,20,7,6}, 30.6875000000000000


2)
{0}
{1,1000000000}

Returns: 8.3333333166666672E16

The answer can be very large

3)
{0,0,1,0,2,3,3,6}
{1,11,111,1111,11111,111111,1111111,11111111,111111111}

Returns: 4.432586365551196E14



4)
{}
{712}

Returns: 0.0



*/
// END CUT HERE
#line 124 "AverageVarianceSubtree.cpp"

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



class AverageVarianceSubtree {
	public:
	double average(vector <int> p, vector <int> weight) {
		
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
#define END	 verify_case(_, AverageVarianceSubtree().average(p, weight));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int p_[] = {0,1};
	  vector <int> p(p_, p_+sizeof(p_)/sizeof(*p_)); 
	int weight_[] = {10,20,30};
	  vector <int> weight(weight_, weight_+sizeof(weight_)/sizeof(*weight_)); 
	double _ = 19.444444444444443; 
END
CASE(1)
	int p_[] = {0,1,1};
	  vector <int> p(p_, p_+sizeof(p_)/sizeof(*p_)); 
	int weight_[] = {10,20,7,6};
	  vector <int> weight(weight_, weight_+sizeof(weight_)/sizeof(*weight_)); 
	double _ = 23.014520202020204; 
END
CASE(2)
	int p_[] = {0};
	  vector <int> p(p_, p_+sizeof(p_)/sizeof(*p_)); 
	int weight_[] = {1,1000000000};
	  vector <int> weight(weight_, weight_+sizeof(weight_)/sizeof(*weight_)); 
	double _ = 8.3333333166666672E16; 
END
CASE(3)
	int p_[] = {0,0,1,0,2,3,3,6};
	  vector <int> p(p_, p_+sizeof(p_)/sizeof(*p_)); 
	int weight_[] = {1,11,111,1111,11111,111111,1111111,11111111,111111111};
	  vector <int> weight(weight_, weight_+sizeof(weight_)/sizeof(*weight_)); 
	double _ = 4.432586365551196E14; 
END
CASE(4)
	vector <int> p; 
	int weight_[] = {712};
	  vector <int> weight(weight_, weight_+sizeof(weight_)/sizeof(*weight_)); 
	double _ = 0.0; 
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
	vector <int> p; 
	{
		int N=UNIFORM_LL(1, 51);
		p = vector <int>(N); 
		REP(i, N) {
			p[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> weight; 
	{
		int N=UNIFORM_LL(1, 51);
		weight = vector <int>(N); 
		REP(i, N) {
			weight[i] = UNIFORM_LL(0, 1000);
		}
	}
	double _0 = AverageVarianceSubtree().average(p, weight);
	double _1 = AverageVarianceSubtreeRef().average(p, weight);
	if(!verify_case(_0, _1, true)) {
print(p);
print(weight);
	}
}
#endif

}
// END CUT HERE
