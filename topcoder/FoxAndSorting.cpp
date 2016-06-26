// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Jiro and Eel Saburo are good friends. Saburo uses a strange way to compare integers. Please help Jiro understand it.

For a positive integer n, let d(n) be the sum of its digits in base 10. For example, d(407) = 4+0+7 = 11.

When comparing two different integers x and y, Saburo first compares their sums of digits, i.e., the values d(x) and d(y). If they differ, the one with the smaller sum is smaller.
For example, for Saburo 50 is smaller than 16, because d(50) < d(16).

If the numbers have the same sum of digits, Saburo compares them lexicographically (i.e., as strings).
For example, for Saburo the number 111 is smaller than the number 3, because d(111) = d(3) and "111" < "3".
Also, the number 470 is smaller than 4700, because "470" < "4700".

Let A be the sequence of integers {0, 1, ..., 999999999999999998, 999999999999999999 (10^18 - 1)}.
Let B be the sequence A, ordered according to Saburo's rules.
You are given a long long idx, representing a 1-based index into B.
Return the corresponding element of B.

DEFINITION
Class:FoxAndSorting
Method:get
Parameters:long long
Returns:long long
Method signature:long long get(long long idx)


NOTES
-Given two distinct strings A and B, we say that A is lexicographically smaller than B if either A is a prefix of B, or A has a smaller character than B on the first position on which they differ.


CONSTRAINTS
-idx will be between 1 and 1,000,000,000,000,000,000 (10^18), inclusive.


EXAMPLES

0)
10

Returns: 100000000

First 10 elements of B are: {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000}.

1)
1000000000000000000

Returns: 999999999999999999

The last element.

2)
58

Returns: 100000000100



3)
314159265358979

Returns: 646003042230121105



4)
271828182845904523

Returns: 132558071125756493



*/
// END CUT HERE
#line 76 "FoxAndSorting.cpp"

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



class FoxAndSorting {
	public:
	long long get(long long idx) {
		VVI dp(18, VI(162));
		
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
#define END	 verify_case(_, FoxAndSorting().get(idx));}
int main(){

CASE(0)
	long long idx = 10LL; 
	long long _ = 100000000LL; 
END
CASE(1)
	long long idx = 1000000000000000000LL; 
	long long _ = 999999999999999999LL; 
END
CASE(2)
	long long idx = 58LL; 
	long long _ = 100000000100LL; 
END
CASE(3)
	long long idx = 314159265358979LL; 
	long long _ = 646003042230121105LL; 
END
CASE(4)
	long long idx = 271828182845904523LL; 
	long long _ = 132558071125756493LL; 
END

}
// END CUT HERE
