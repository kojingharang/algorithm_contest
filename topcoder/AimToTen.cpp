// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are given a int[] marks containing the grades you have received so far in a class. Each grade is between 0 and 10, inclusive.  Assuming that you will receive a 10 on all future assignments, determine the minimum number of future assignments that are needed for you to receive a final grade of 10.  You will receive a final grade of 10 if your average grade is 9.5 or higher.


DEFINITION
Class:AimToTen
Method:need
Parameters:vector <int>
Returns:int
Method signature:int need(vector <int> marks)


CONSTRAINTS
-marks has between 1 and 50 elements, inclusive.
-Each element of marks is between 0 and 10, inclusive.


EXAMPLES

0)
{9, 10, 10, 9}

Returns: 0

Your average is already 9.5, so no future assignments are needed.

1)
{8, 9}

Returns: 4

In this case you need 4 more assignments. With each completed assignment, your average could increase to 9, 9.25, 9.4 and 9.5, respectively.

2)
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

Returns: 950

3)
{10, 10, 10, 10}

Returns: 0

*/
// END CUT HERE
#line 53 "AimToTen.cpp"

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


class AimToTen {
	public:
	int need(vector <int> marks) {
		int sum = accumulate(ALL(marks), 0)*2;
		for(int i=0;;i++) {
			if((sum+20*i)/(marks.size()+i) >= 19) return i;
		}
		return -1;
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
#define END	 verify_case(_, AimToTen().need(marks));}
int main(){

CASE(0)
	int marks_[] = {9, 10, 10, 9};
	  vector <int> marks(marks_, marks_+sizeof(marks_)/sizeof(*marks_)); 
	int _ = 0; 
END
CASE(1)
	int marks_[] = {8, 9};
	  vector <int> marks(marks_, marks_+sizeof(marks_)/sizeof(*marks_)); 
	int _ = 4; 
END
CASE(2)
	int marks_[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	  vector <int> marks(marks_, marks_+sizeof(marks_)/sizeof(*marks_)); 
	int _ = 950; 
END
CASE(3)
	int marks_[] = {10, 10, 10, 10};
	  vector <int> marks(marks_, marks_+sizeof(marks_)/sizeof(*marks_)); 
	int _ = 0; 
END

}
// END CUT HERE
