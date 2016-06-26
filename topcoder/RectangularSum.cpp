// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Consider the following table:


The table has height rows and width columns.
Rows and columns are each numbered sequentially, starting from 0.
For each i, j: the cell in row i, column j contains the number (i*width+j).
For example, the table with height=2 and width=3 looks as follows:

0 1 2
3 4 5


A subtable of this table is any table that can be obtained from the original table by selecting a rectangle of cells and erasing everything outside the rectangle.

You are given the ints height and width, and a long long S.
If there is no subtable in which the elements sum to S, return -1.
Otherwise, return the smallest possible area of such a subtable.

DEFINITION
Class:RectangularSum
Method:minimalArea
Parameters:int, int, long long
Returns:long long
Method signature:long long minimalArea(int height, int width, long long S)


CONSTRAINTS
-height will be between 1 and 1,000,000 (10^6), inclusive.
-width will be between 1 and 1,000,000 (10^6), inclusive.
-S will be between 1 and 1,000,000,000,000 (10^12), inclusive.


EXAMPLES

0)
2
3
8

Returns: 4

The following subtable (shown in bold italic) has a sum of 8:

0 1 2
3 4 5


1)
3
3
10

Returns: -1



2)
3
3
36

Returns: 9



3)
25
25
16000

Returns: 32



4)
1000000
1000000
1000000000000

Returns: 2



*/
// END CUT HERE
#line 90 "RectangularSum.cpp"

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


ll f(int x, int y, int w, int h, int W, int H) {
	ll ref = 0;
	REP(yy, h) REP(xx, w) ref += x+xx + W*(y+yy);
	ll ans = ( ((x+w-1)*(x+w) - (x-1)*x)*h + w*W*((y+h-1)*(y+h) - (y-1)*(y)) )/2;
	//cout<<ref<<" "<<ans<<endl;
	if(ref!=ans) {
		cout<<"ERR "<<x<<" "<<y<<" "<<w<<" "<<h<<" --- "<<ref<<" "<<ans<<endl;
		cout<<(x+w-1)*(x+w)/2<<" "<<(x-1)*x/2<<"  "<<w*W*(y+h-1)*(y+h)/2<<" "<<w*W*(y-1)*(y)/2<<endl;
	}
	return ref;
}

class RectangularSum {
	public:
	long long minimalArea(int H, int W, long long S) {
		//if(S<H*W) return 1;
		REP(x, 10) REP(y, 10) REP(w, 10) REP(h, 10) f(x, y, w, h, 100, 100);
		return 0;
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
#define END	 verify_case(_, RectangularSum().minimalArea(height, width, S));}
int main(){

//CASE(0)
//	int height = 2; 
//	int width = 3; 
//	long long S = 8LL; 
//	long long _ = 4LL; 
//END
//CASE(1)
//	int height = 3; 
//	int width = 3; 
//	long long S = 10LL; 
//	long long _ = -1LL; 
//END
//CASE(2)
//	int height = 3; 
//	int width = 3; 
//	long long S = 36LL; 
//	long long _ = 9LL; 
//END
//CASE(3)
//	int height = 25; 
//	int width = 25; 
//	long long S = 16000LL; 
//	long long _ = 32LL; 
//END
//CASE(4)
//	int height = 1000000; 
//	int width = 1000000; 
//	long long S = 1000000000000LL; 
//	long long _ = 2LL; 
//END
CASE(0)
	int height = 2; 
	int width = 3; 
	long long S = 2LL; 
	long long _ = 1LL; 
END

}
// END CUT HERE
