// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Mr. Dengklek lives in the Kingdom of Ducks, where humans and ducks live together in peace and harmony. There are K types of ducks in the kingdom, conveniently numbered 1 through K. The kingdom is very large, so it is assumed that there is an unlimited number of ducks of each type.

Mr. Dengklek has a rectangular farm that can be represented with a grid that is divided into N rows and M columns (so there are N*M cells). He would like to place exactly one duck on each cell in the farm. Any such placement is called a duck formation. Some of the duck formations are beautiful.
The beauty of a formation only depends on the duck types used in the formation: we say that two rows of a formation are similar if for each X between 1 and K, inclusive, they contain the same number of ducks of type X. A duck formation is beautiful if it does not contain any pair of similar rows. In other words, if there are two similar rows (not necessarily adjacent ones), the formation is not beautiful.

You are given the ints N, M, and K. Return the number of different beautiful duck formations that Mr. Dengklek can make, modulo 1,000,000,007. Two formations are different if there is a cell such that the type of the duck in that cell in one formation is different from the type used in the other formation.

DEFINITION
Class:DengklekCountingFormations
Method:numFormations
Parameters:int, int, int
Returns:int
Method signature:int numFormations(int N, int M, int K)


CONSTRAINTS
-N will be between 1 and 10, inclusive.
-M will be between 1 and 50, inclusive.
-K will be between 1 and 100, inclusive.


EXAMPLES

0)
2
2
2

Returns: 10

These are the 10 beautiful duck formations:

1 1    1 1    1 1    1 2    1 2
1 2    2 1    2 2    1 1    2 2

2 1    2 1    2 2    2 2    2 2
1 1    2 2    1 1    1 2    2 1


1)
1
1
58

Returns: 58

Mr. Dengklek can place a duck of any type in the single cell.

2)
5
3
2

Returns: 0



3)
3
5
7

Returns: 894953467



4)
7
47
74

Returns: 778075142



*/
// END CUT HERE
#line 82 "DengklekCountingFormations.cpp"

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



class DengklekCountingFormations {
	public:
	int numFormations(int N, int M, int K) {
		
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
#define END	 verify_case(_, DengklekCountingFormations().numFormations(N, M, K));}
int main(){

CASE(0)
	int N = 2; 
	int M = 2; 
	int K = 2; 
	int _ = 10; 
END
CASE(1)
	int N = 1; 
	int M = 1; 
	int K = 58; 
	int _ = 58; 
END
CASE(2)
	int N = 5; 
	int M = 3; 
	int K = 2; 
	int _ = 0; 
END
CASE(3)
	int N = 3; 
	int M = 5; 
	int K = 7; 
	int _ = 894953467; 
END
CASE(4)
	int N = 7; 
	int M = 47; 
	int K = 74; 
	int _ = 778075142; 
END

}
// END CUT HERE
