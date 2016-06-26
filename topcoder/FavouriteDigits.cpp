// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Tetka Rapotacka just heard a juicy rumor about one of her neighbors: poor Jachym has lost N kacky (their local monetary unit) on a slot machine yesterday.
Tetka Rapotacka now plans to share this rumor with everyone, including Tetka Klepetacka.
Tetka Rapotacka has two favourite digits: digit1 and digit2.
She only likes numbers that contain at least count1 occurrences of digit1 and at least count2 occurrences of digit2.
When gossiping, she only uses numbers she likes.
So if she does not like the number N, she will increase it until she finds a number that she likes.


You are given the long long N and the four ints digit1, count1, digit2, and count2.
Return the smallest integer that is greater than or equal to N, contains at least count1 occurrences of digit digit1, and at least count2 occurrences of digit digit2.


DEFINITION
Class:FavouriteDigits
Method:findNext
Parameters:long long, int, int, int, int
Returns:long long
Method signature:long long findNext(long long N, int digit1, int count1, int digit2, int count2)


NOTES
-The constraints guarantee that the return value will always fit into a long long.


CONSTRAINTS
-N will be between 1 and 10^15 - 1, inclusive.
-digit1 will be between 0 and 9, inclusive.
-digit2 will be between 0 and 9, inclusive.
-digit1 and digit2 will not be equal.
-count1 will be at least 0.
-count2 will be at least 0.
-count1+count2 will be at most 15.


EXAMPLES

0)
47
1
0
2
0

Returns: 47

As count1=0 and count2=0, Tetka Rapotacka likes all numbers.

1)
47
5
0
9
1

Returns: 49

The number has to contain the digit 9. The next number that contains this digit is 49.

2)
47
5
0
3
1

Returns: 53



3)
47
2
1
0
2

Returns: 200

The correct return value may have more digits than N.

4)
123456789012345
1
2
2
4

Returns: 123456789012422



5)
92
1
1
0
0

Returns: 100



*/
// END CUT HERE
#line 110 "FavouriteDigits.cpp"

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
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class FavouriteDigits {
	public:
	long long findNext(long long N, int digit1, int count1, int digit2, int count2) {
		
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
void verify_case(const long long& Expected, const long long& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, FavouriteDigits().findNext(N, digit1, count1, digit2, count2));}
int main(){

CASE(0)
	long long N = 47LL; 
	int digit1 = 1; 
	int count1 = 0; 
	int digit2 = 2; 
	int count2 = 0; 
	long long _ = 47LL; 
END
CASE(1)
	long long N = 47LL; 
	int digit1 = 5; 
	int count1 = 0; 
	int digit2 = 9; 
	int count2 = 1; 
	long long _ = 49LL; 
END
CASE(2)
	long long N = 47LL; 
	int digit1 = 5; 
	int count1 = 0; 
	int digit2 = 3; 
	int count2 = 1; 
	long long _ = 53LL; 
END
CASE(3)
	long long N = 47LL; 
	int digit1 = 2; 
	int count1 = 1; 
	int digit2 = 0; 
	int count2 = 2; 
	long long _ = 200LL; 
END
CASE(4)
	long long N = 123456789012345LL; 
	int digit1 = 1; 
	int count1 = 2; 
	int digit2 = 2; 
	int count2 = 4; 
	long long _ = 123456789012422LL; 
END
CASE(5)
	long long N = 92LL; 
	int digit1 = 1; 
	int count1 = 1; 
	int digit2 = 0; 
	int count2 = 0; 
	long long _ = 100LL; 
END

}
// END CUT HERE
