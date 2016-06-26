// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Warning: This problem statement contains superscripts and/or subscripts. It may not display properly outside of the applet.

In this problem we will consider binary polynomials. A binary polynomial can be written in the following form:


P(x) = a[0] * x0 + a[1] * x1 + ... + a[n] * xn


The values a[i] are integer constants (called coefficients). For a binary polynomial we must have a[n] = 1 and each other a[i] must be either 0 or 1. The number n is called the degree of the polynomial.


Several examples:

 P(x) = 1 * x0 + 0 * x1 + 1 * x2 is a binary polynomial of degree 2. 
 P(x) = 0 * x0 + 1 * x1 + 0 * x2 + 1 * x3 is a binary polynomial of degree 3. 
 P(x) = 1 * x0 is a binary polynomial of degree 0. 
 P(x) = 0 * x0 + 3 * x1 - 1 * x2 is not a binary polynomial, because each coefficient must be a 0 or a 1. 
 P(x) = 0 * x0 is not a valid binary polynomial, because the last of the values a[i] must be 1. 

We can evaluate a binary polynomial for the inputs x = 0 and x = 1. In order to do so, we just have to substitute 0 or 1 for x in the above expression, compute the value of the expression and take the remainder it gives when divided by two. For example, if P(x) = 1 * x0 + 0 * x1 + 1 * x2, then P(0) = 1 * 00 + 0 * 01 + 1 * 02 = 1 and P(1) = 1 * 10 + 0 * 11 + 1 * 12 = 0 (modulo 2). Note that in this problem we assume that x0 = 1 for all x. In particular, also 00 = 1.


We call an integer x (where x is 0 or 1) a root of the binary polynomial P if P(x) = 0. You are given a binary polynomial P as the array a of its coefficients. Return the number of roots of that binary polynomial.

DEFINITION
Class:BinaryPolynomialDivTwo
Method:countRoots
Parameters:vector <int>
Returns:int
Method signature:int countRoots(vector <int> a)


CONSTRAINTS
-The degree of P will be between 0 and 49, inclusive.
-a will contain exactly n+1 elements, where n is the degree of P.
-Each element of a will be either 0 (zero) or 1 (one).
-a[n] will be equal to 1 (one).


EXAMPLES

0)
{1, 0, 1}

Returns: 1

The example from the problem statement. The only root of this binary polynomial is 1.

1)
{0, 1, 0, 1}

Returns: 2

This is the maximum possible answer; both 0 and 1 are roots of this binary polynomial.

2)
{1}

Returns: 0

This binary polynomial has no roots - it always evaluates to 1.

3)
{1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1}

Returns: 0



4)
{1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1}

Returns: 1



*/
// END CUT HERE
#line 84 "BinaryPolynomialDivTwo.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T> v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class BinaryPolynomialDivTwo {
	public:
	int countRoots(vector <int> a) {
		return ((a[0]&1)==0) + ((accumulate(ALL(a), 0) & 1)==0);
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
 { os << "{ ";
   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, BinaryPolynomialDivTwo().countRoots(a));}
int main(){

CASE(0)
	int a_[] = {1, 0, 1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int _ = 1; 
END
CASE(1)
	int a_[] = {0, 1, 0, 1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int _ = 2; 
END
CASE(2)
	int a_[] = {1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int _ = 0; 
END
CASE(3)
	int a_[] = {1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int _ = 0; 
END
CASE(4)
	int a_[] = {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int _ = 1; 
END

}
// END CUT HERE
