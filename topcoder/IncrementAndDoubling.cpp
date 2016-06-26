// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
You have an array with N elements.
Initially, each element is 0.
You can perform the following operations:



Increment operation: Choose one element of the array and increment the value by one.
Doubling operation: Double the value of each element.



You are given a vector <int> desiredArray containing N elements.
Compute and return the smallest possible number of operations needed to change the array from all zeros to desiredArray.


DEFINITION
Class:IncrementAndDoubling
Method:getMin
Parameters:vector <int>
Returns:int
Method signature:int getMin(vector <int> desiredArray)


CONSTRAINTS
-desiredArray will contain between 1 and 50 elements, inclusive.
-Each element of desiredArray will be between 0 and 1,000, inclusive.


EXAMPLES

0)
{2, 1}

Returns: 3

One of the optimal solutions is to apply increment operations to element 0 twice and then to element 1 once.
Total number of operations is 3.



1)
{16, 16, 16}

Returns: 7

The optimum solution looks as follows.
First, apply an increment operation to each element.
Then apply the doubling operation four times.
Total number of operations is 3+4=7.



2)
{100}

Returns: 9



3)
{0, 0, 1, 0, 1}

Returns: 2

Some elements in desiredArray may be zeros.

4)
{123, 234, 345, 456, 567, 789}

Returns: 40



5)
{7,5,8,1,8,6,6,5,3,5,5,2,8,9,9,4,6,9,4,4,1,9,9,2,8,4,7,4,8,8,6,3,9,4,3,4,5,1,9,8,3,8,3,7,9,3,8,4,4,7}

Returns: 84



******************************/
// END CUT HERE
#line 88 "IncrementAndDoubling.cpp"
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

class IncrementAndDoubling {
	public:
	int getMin(vector <int> D) {
		int ans = 0;
		REP(i, D.size()) ans += POPCOUNT(D[i]);
		int mx = 0;
		REP(i, D.size()) mx=max(mx, D[i]);
		while(mx>1) { ans++;mx>>=1;}
		return ans;
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
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, IncrementAndDoubling().getMin(desiredArray));}
int main(){

CASE(0)
	int desiredArray_[] = {2, 1};
	  vector <int> desiredArray(desiredArray_, desiredArray_+sizeof(desiredArray_)/sizeof(*desiredArray_)); 
	int _ = 3; 
END
CASE(1)
	int desiredArray_[] = {16, 16, 16};
	  vector <int> desiredArray(desiredArray_, desiredArray_+sizeof(desiredArray_)/sizeof(*desiredArray_)); 
	int _ = 7; 
END
CASE(2)
	int desiredArray_[] = {100};
	  vector <int> desiredArray(desiredArray_, desiredArray_+sizeof(desiredArray_)/sizeof(*desiredArray_)); 
	int _ = 9; 
END
CASE(3)
	int desiredArray_[] = {0, 0, 1, 0, 1};
	  vector <int> desiredArray(desiredArray_, desiredArray_+sizeof(desiredArray_)/sizeof(*desiredArray_)); 
	int _ = 2; 
END
CASE(4)
	int desiredArray_[] = {123, 234, 345, 456, 567, 789};
	  vector <int> desiredArray(desiredArray_, desiredArray_+sizeof(desiredArray_)/sizeof(*desiredArray_)); 
	int _ = 40; 
END
CASE(5)
	int desiredArray_[] = {7,5,8,1,8,6,6,5,3,5,5,2,8,9,9,4,6,9,4,4,1,9,9,2,8,4,7,4,8,8,6,3,9,4,3,4,5,1,9,8,3,8,3,7,9,3,8,4,4,7};
	  vector <int> desiredArray(desiredArray_, desiredArray_+sizeof(desiredArray_)/sizeof(*desiredArray_)); 
	int _ = 84; 
END

}
// END CUT HERE
