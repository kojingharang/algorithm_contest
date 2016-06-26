// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// John has a sequence of digits.
He and Brus will now play with the sequence.


First, John will repeat the following operation k times:
He will choose two different positions in the sequence, and swap the elements at those positions.
(John makes each choice uniformly at random.
That is, each time John chooses two positions, each pair of different positions has the same probability of being chosen.)


Afterwards, Brus will randomly choose a non-empty contiguous subsequence of John's sequence.
He will compute the sum of all elements in the chosen subsequence and he will write it down on a piece of paper.
(Brus also makes his choice uniformly at random.
That is, each possible contiguous subsequence has the same probability of being chosen.)


You are given a vector <string> sequence.
Concatenate all elements of sequence to get the string s.
For each i, the i-th character of s is a digit ('0'-'9') representing the digit at index i in John's original sequence.


Return the expected value of the sum Brus writes down.

DEFINITION
Class:TheSwapsDivOne
Method:find
Parameters:vector <string>, int
Returns:double
Method signature:double find(vector <string> sequence, int k)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-sequence will contain between 2 and 47 elements, inclusive.
-Each element of sequence will contain between 1 and 47 characters, inclusive.
-Each element of sequence will consist of only decimal digits ('0'-'9').
-k will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{"4", "77"}
1

Returns: 10.0

There are three equally likely swaps John might make.
If the first two elements are swapped, John will get the sequence {7,4,7}.
Then Brus chooses one of the six possible subsequences.
Their sums are 7, 4, 7, 11, 11 and 18.
Thus the expected value is (7 + 4 + 7 + 11 + 11 + 18)/6 = 29/3.

If the first and the last elements are swapped, the sequence becomes {7,7,4}, and the subsequence sums are 7, 7, 4, 14, 11 and 18.
The expected value in this case is (7 + 7 + 4 + 14 + 11 + 18)/6 = 61/6.

When the last two elements are swapped, the sequence doesn't change and the expected value is equal to 61/6 as well.
Finally, the overall expected value is equal to (29/3 + 61/6 + 61/6)/3 = 10.


1)
{"4", "77"}
47

Returns: 10.0



2)
{"1", "1", "1", "1", "1", "1", "1"}
1000000

Returns: 3.0



3)
{"572685085149095989026478064633266980348504469", "19720257361", "9", "69"}
7

Returns: 98.3238536775161



*/
// END CUT HERE
#line 94 "TheSwapsDivOne.cpp"

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



class TheSwapsDivOne {
	public:
	double find(vector <string> sequence, int k) {
		
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
#define END	 verify_case(_, TheSwapsDivOne().find(sequence, k));}
int main(){

CASE(0)
	string sequence_[] = {"4", "77"};
	  vector <string> sequence(sequence_, sequence_+sizeof(sequence_)/sizeof(*sequence_)); 
	int k = 1; 
	double _ = 10.0; 
END
CASE(1)
	string sequence_[] = {"4", "77"};
	  vector <string> sequence(sequence_, sequence_+sizeof(sequence_)/sizeof(*sequence_)); 
	int k = 47; 
	double _ = 10.0; 
END
CASE(2)
	string sequence_[] = {"1", "1", "1", "1", "1", "1", "1"};
	  vector <string> sequence(sequence_, sequence_+sizeof(sequence_)/sizeof(*sequence_)); 
	int k = 1000000; 
	double _ = 3.0; 
END
CASE(3)
	string sequence_[] = {"572685085149095989026478064633266980348504469", "19720257361", "9", "69"};
	  vector <string> sequence(sequence_, sequence_+sizeof(sequence_)/sizeof(*sequence_)); 
	int k = 7; 
	double _ = 98.3238536775161; 
END

}
// END CUT HERE
