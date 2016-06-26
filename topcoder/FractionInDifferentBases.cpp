// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
This problem statement contains superscripts and/or subscripts. It may not display properly outside the applet.

It is well-known that when writing a fraction as a rational number, we will either get a finite expansion or an infinite (but periodic) expansion.
For example, 1/8 written in base 10 is 0.125, and 1/9 written in base 10 is 0.1111...

The same fraction can have a finite expansion in some bases and an infinite one in other bases.
For example, 1/9 had an infinite expansion in base 10, but 1/9 written in base 3 is 0.01 and 1/9 in base 9 is 0.1.

Little Arthur loves numbers and especially the ones that are infinitely long. For a given fraction P/Q he would like to find all integer bases between A and B, inclusive, such that the fraction has an infinite expansion.

Given ints P, Q, A, and B return the number of such bases.

DEFINITION
Class:FractionInDifferentBases
Method:getNumberOfGoodBases
Parameters:long long, long long, long long, long long
Returns:long long
Method signature:long long getNumberOfGoodBases(long long P, long long Q, long long A, long long B)


NOTES
-Number X written in an integer base b is a sequence of digits (containing a single separator point, if the number is not an integer) dndn-1..d1d0.d-1..d-m where each di has an integer value between 0 and b-1, inclusive.
-The notation effectively means that X = dn*bn + dn-1*bn-1 + .. + d1*b1 + d0*b0 + d-1*b-1 + .. + d-m*b-m.
-Note that X having an infinite expansion in base b means that number X cannot be expressed as a sum with finitely many powers of b.


CONSTRAINTS
-P will be between 0 and 1000000000000 (1012), inclusive.
-Q will be between 1 and 1000000000000 (1012), inclusive.
-A and B will each be between 2 and 1000000000000000000 (1018), inclusive.
-A will be less than or equal to B.


EXAMPLES

0)
1
2
10
10

Returns: 0

1/2 in base 10 is 0.5, thus, there is no base in the interval where 1/2 has an infinite expansion.

1)
1
9
9
10

Returns: 1

From the problem statement we see that 1/9 has an infinite expansion in base 10, but not in base 9.

2)
5
6
2
10

Returns: 8

3)
2662
540
2
662

Returns: 639

4)
650720
7032600
2012
2012540

Returns: 2010495

*/
// END CUT HERE
#line 87 "FractionInDifferentBases.cpp"

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



class FractionInDifferentBases {
	public:
	long long getNumberOfGoodBases(long long P, long long Q, long long A, long long B) {
		
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
void verify_case(const long long& Expected, const long long& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B));}
int main(){

CASE(0)
	long long P = 1LL; 
	long long Q = 2LL; 
	long long A = 10LL; 
	long long B = 10LL; 
	long long _ = 0LL; 
END
CASE(1)
	long long P = 1LL; 
	long long Q = 9LL; 
	long long A = 9LL; 
	long long B = 10LL; 
	long long _ = 1LL; 
END
CASE(2)
	long long P = 5LL; 
	long long Q = 6LL; 
	long long A = 2LL; 
	long long B = 10LL; 
	long long _ = 8LL; 
END
CASE(3)
	long long P = 2662LL; 
	long long Q = 540LL; 
	long long A = 2LL; 
	long long B = 662LL; 
	long long _ = 639LL; 
END
CASE(4)
	long long P = 650720LL; 
	long long Q = 7032600LL; 
	long long A = 2012LL; 
	long long B = 2012540LL; 
	long long _ = 2010495LL; 
END

}
// END CUT HERE
