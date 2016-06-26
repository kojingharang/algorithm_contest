// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Consider a meeting of n businessmen sitting around a circular table. To start the meeting, they must shake hands. Each businessman shakes the hand of exactly one other businessman. All handshakes happen simultaneously. We say that the shake is perfect if no arms cross each other. Given an int n, return the number of perfect shakes that exist for n businessmen. See examples for further clarification.

DEFINITION
Class:HandsShaking
Method:countPerfect
Parameters:int
Returns:long long
Method signature:long long countPerfect(int n)


NOTES
-Businessmen are distinguishable. Rotating a perfect shake can yield a different perfect shake (see example 1).


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-n will be even.


EXAMPLES

0)
2

Returns: 1

Two businessmen have only one possibility - just to shake each other's hand.

1)
4

Returns: 2

Two out of three possible shakes are perfect.
? ? 

2)
8

Returns: 14



*/
// END CUT HERE
#line 50 "HandsShaking.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

ll memo[60];
ll f(int n) {
	ll ans = 0;
	if(n==0) return 1;
	if(memo[n]) return memo[n];
	for(int i=0;i<=n-2;i+=2) {
		int j=n-2-i;
		ans+=f(i)*f(j);
	}
	return memo[n]=ans;
}

class HandsShaking {
	public:
	long long countPerfect(int n) {
		memset(memo, 0, sizeof(memo));
		return f(n);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 1LL; verify_case(0, Arg1, countPerfect(Arg0)); }
	void test_case_1() { int Arg0 = 4; long long Arg1 = 2LL; verify_case(1, Arg1, countPerfect(Arg0)); }
	//void test_case_2() { int Arg0 = 8; long long Arg1 = 14LL; verify_case(2, Arg1, countPerfect(Arg0)); }
	void test_case_2() { int Arg0 = 50; long long Arg1 = 14LL; verify_case(2, Arg1, countPerfect(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	HandsShaking ___test;

	___test.run_test(-1);

}

// END CUT HERE
