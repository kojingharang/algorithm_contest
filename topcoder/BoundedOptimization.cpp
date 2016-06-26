// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
You are given an arithmetic expression.
The expression is a sum of one or more terms.
Each term is a product of exactly two variables.
In each term, the two variables are distinct.
No two terms contain the same pair of variables.



Additionally, the following constraints are given:

For each i, the i-th variable (0-based index) must have a value between lowerBound[i] and upperBound[i], inclusive. The bounds are integers, but the value of the variable can be any real number in the given range.
The sum of all variables must not exceed maxSum.




You are given a vector <string> expr, the vector <int>s lowerBound and upperBound, and the int maxSum.
Concatenate the elements of expr to obtain the considered expression.
For each i, the i-th variable will be denoted by the i-th lowercase letter of the English alphabet.
(Both indices are 0-based, so variable 0 is 'a', variable 1 is 'b', and so on.)



Return the maximum value of the expression, given that all the above constraints have to be satisfied.
Note that the constraints guarantee that it is possible to satisfy all the given constraints.


DEFINITION
Class:BoundedOptimization
Method:maxValue
Parameters:vector <string>, vector <int>, vector <int>, int
Returns:double
Method signature:double maxValue(vector <string> expr, vector <int> lowerBound, vector <int> upperBound, int maxSum)


NOTES
-Your return value must have a relative or an absolute error of less than 1e-9.


CONSTRAINTS
-expr will contain between 1 and 50 elements, inclusive.
-Each element of expr will contain between 1 and 50 characters, inclusive.
-Each character in each element of expr will be '+' or one of the first n lowercase letters of the English alphabet, where n is the number of elements in lowerBound.
-The concatenation of the elements of expr will consist of pairs of letters separated by '+' characters.
-No unordered pair of consecutive letters will appear twice in the concatenation of the elements of expr.
-No two consecutive letters in the concatenation of the elements of expr will be equal.
-lowerBound will contain between 2 and 13 elements, inclusive.
-Each element of lowerBound will be between 0 and 100, inclusive.
-upperBound will contain n elements, where n is the number of elements in lowerBound.
-For each i between 0 and n - 1, the i-th element of upperBound will be between lowerBound[i] and 100, inclusive.
-maxSum will be between the sum of the elements of lowerBound and 1,300, inclusive.


EXAMPLES

0)
{"ba+cb"}
{0,0,1}
{1,2,1}
3

Returns: 2.25

The maximum value is obtained by setting a = 0.5, b = 1.5, c = 1.

1)
{"ab"}
{0, 0, 10}
{20, 20, 20}
12

Returns: 1.0

We have to set a proper value for c even though it is not present in the expression described by expr.

2)
{"ca+fc+fa+d","b+da+","dc+c","b","+ed+eb+ea"}
{10,11,12,13,14,15}
{15,16,17,18,19,20}
85

Returns: 2029.25



3)
{"db+ea+ik+kh+je+","fj+lk+i","d+jb+h","a+gk+mb+ml+lc+mh+cf+fd+","gc+ka+gf+bh+mj+eg+bf+hf+l","b+al+ja+da+i",
"f+g","h+ia+le+ce+gi+d","h+mc+fe+dm+im+kb+bc+","ib+ma+eb+mf+jk+kc+mg+mk+","gb+dl+ek+hj+dg+hi","+ch+ga+ca+fl+ij+fa+jl+dc+dj+fk","+li+jg"}
{57,29,50,21,49,29,88,33,84,76,95,55,11}
{58,80,68,73,52,84,100,79,93,98,95,69,97}
845

Returns: 294978.3333333333



*/
// END CUT HERE
#line 104 "BoundedOptimization.cpp"

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
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class BoundedOptimization {
	public:
	double maxValue(vector <string> expr, vector <int> lowerBound, vector <int> upperBound, int maxSum) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//mplate<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// os << "{ ";
// for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
// os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const double& Expected, const double& Received) {
 double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, BoundedOptimization().maxValue(expr, lowerBound, upperBound, maxSum));}
int main(){

CASE(0)
	string expr_[] = {"ba+cb"};
	  vector <string> expr(expr_, expr_+sizeof(expr_)/sizeof(*expr_)); 
	int lowerBound_[] = {0,0,1};
	  vector <int> lowerBound(lowerBound_, lowerBound_+sizeof(lowerBound_)/sizeof(*lowerBound_)); 
	int upperBound_[] = {1,2,1};
	  vector <int> upperBound(upperBound_, upperBound_+sizeof(upperBound_)/sizeof(*upperBound_)); 
	int maxSum = 3; 
	double _ = 2.25; 
END
CASE(1)
	string expr_[] = {"ab"};
	  vector <string> expr(expr_, expr_+sizeof(expr_)/sizeof(*expr_)); 
	int lowerBound_[] = {0, 0, 10};
	  vector <int> lowerBound(lowerBound_, lowerBound_+sizeof(lowerBound_)/sizeof(*lowerBound_)); 
	int upperBound_[] = {20, 20, 20};
	  vector <int> upperBound(upperBound_, upperBound_+sizeof(upperBound_)/sizeof(*upperBound_)); 
	int maxSum = 12; 
	double _ = 1.0; 
END
CASE(2)
	string expr_[] = {"ca+fc+fa+d","b+da+","dc+c","b","+ed+eb+ea"};
	  vector <string> expr(expr_, expr_+sizeof(expr_)/sizeof(*expr_)); 
	int lowerBound_[] = {10,11,12,13,14,15};
	  vector <int> lowerBound(lowerBound_, lowerBound_+sizeof(lowerBound_)/sizeof(*lowerBound_)); 
	int upperBound_[] = {15,16,17,18,19,20};
	  vector <int> upperBound(upperBound_, upperBound_+sizeof(upperBound_)/sizeof(*upperBound_)); 
	int maxSum = 85; 
	double _ = 2029.25; 
END
CASE(3)
	string expr_[] = {"db+ea+ik+kh+je+","fj+lk+i","d+jb+h","a+gk+mb+ml+lc+mh+cf+fd+","gc+ka+gf+bh+mj+eg+bf+hf+l","b+al+ja+da+i",
"f+g","h+ia+le+ce+gi+d","h+mc+fe+dm+im+kb+bc+","ib+ma+eb+mf+jk+kc+mg+mk+","gb+dl+ek+hj+dg+hi","+ch+ga+ca+fl+ij+fa+jl+dc+dj+fk","+li+jg"};
	  vector <string> expr(expr_, expr_+sizeof(expr_)/sizeof(*expr_)); 
	int lowerBound_[] = {57,29,50,21,49,29,88,33,84,76,95,55,11};
	  vector <int> lowerBound(lowerBound_, lowerBound_+sizeof(lowerBound_)/sizeof(*lowerBound_)); 
	int upperBound_[] = {58,80,68,73,52,84,100,79,93,98,95,69,97};
	  vector <int> upperBound(upperBound_, upperBound_+sizeof(upperBound_)/sizeof(*upperBound_)); 
	int maxSum = 845; 
	double _ = 294978.3333333333; 
END

}
// END CUT HERE
