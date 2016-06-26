// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are watching a soccer match, and you wonder what the probability is that at least one of the two teams will score a prime number of goals.  The game lasts 90 minutes, and to simplify the analysis, we will split the match into five-minute intervals.  The first interval is the first five minutes, the second interval is the next five minutes, and so on.  During each interval, there is a skillOfTeamA percent probability that team A will score a goal, and a skillOfTeamB percent probability that teamB will score a goal.  Assume that each team will score at most one goal within each interval.  Return the probability that at least one team will have a prime number as its final score.

DEFINITION
Class:PrimeSoccer
Method:getProbability
Parameters:int, int
Returns:double
Method signature:double getProbability(int skillOfTeamA, int skillOfTeamB)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.
-A prime number is a number that has exactly two divisors, 1 and itself. Note that 0 and 1 are not prime.


CONSTRAINTS
-skillOfTeamA will be between 0 and 100, inclusive.
-skillOfTeamB will be between 0 and 100, inclusive.


EXAMPLES

0)
50
50

Returns: 0.5265618908306351



1)
100
100

Returns: 0.0

Both teams will score a goal in each interval, so the final result will be 18 to 18.

2)
12
89

Returns: 0.6772047168840167



*/
// END CUT HERE
#line 53 "PrimeSoccer.cpp"

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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }


ll nCr(ll n, ll r) {
	ll ans = 1;
	REP(i, r) ans *= n-i;
	REP(i, r) ans /= i+1;
	return ans;
}

class PrimeSoccer {
	public:
	double getProbability(int sA, int sB) {
		double P[2] = {sA/100., sB/100.};
		int np[12] = {0, 1,4,6,8,9,10,12,14,15,16,18};
		double r[2] = {0,0};
		REP(i, 2) {
			REP(sci, 12) {
				r[i] += nCr(18, np[sci]) * pow(P[i], np[sci]) * pow(1-P[i], 18-np[sci]);
			}
		}
		cout<<r[0]<<" "<<r[1]<<endl;
		return 1-r[0]*r[1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 50; int Arg1 = 50; double Arg2 = 0.5265618908306351; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 100; double Arg2 = 0.0; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 89; double Arg2 = 0.6772047168840167; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	PrimeSoccer ___test;

	___test.run_test(-1);

}

// END CUT HERE
