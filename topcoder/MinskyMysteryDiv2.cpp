/*
// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Marvin plays a simple game. The game is played with an infinite supply of marbles and five bags, labeled "bag 0" through "bag 4".



At the beginning, Marvin takes N marbles (where N is a nonnegative integer) and places them into bag 0. The remaining four bags are left empty.
Marvin then follows this simple algorithm:



    Add a marble into bag 1.
    Repeat forever:
        Add a marble into bag 1.
        Empty bag 4.
        While there are marbles in bag 0:
            While there are marbles both in bag 0 and in bag 1:
                Remove a marble from bag 0.
                Remove a marble from bag 1.
                Add a marble into bag 2.
                Add a marble into bag 3.
            End While
            Add a marble into bag 4.
            If bags 0 and 1 are both empty:
                Move all marbles from bag 3 to bag 4.
                TERMINATE THE GAME
            End If
            Move all marbles from bag 3 to bag 1.
        End While
        Move all marbles from bag 2 to bag 0.
    End Repeat



You are given a long long N. Return a long long containing the number of marbles that will be in bag 4 at the end of Marvin's game. If Marvin's game does not terminate for the given N, return -1 instead.


DEFINITION
Class:MinskyMysteryDiv2
Method:computeAnswer
Parameters:long long
Returns:long long
Method signature:long long computeAnswer(long long N)


NOTES
-You may assume that the answer always fits into a long long.
-Note that N is allowed to be zero.


CONSTRAINTS
-N will be between 0 and 10^12, inclusive.


EXAMPLES

0)
2

Returns: 3



1)
3

Returns: 4



2)
4

Returns: 4



3)
15

Returns: 8



4)
24

Returns: 14

// END CUT HERE
*/
#line 95 "MinskyMysteryDiv2.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
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
#define VVI vector<vector<int> >
#define PII pair<int, int> 
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }


ll f(VI& m) {
	if(m[0]<2) return -1;
	
	for(int i=2;i*i<=m[0];i++) {
		if(m[0]%i==0) return i+m[0]/i;
	}
	//cout<<m<<endl;
	return m[0]+1;
}

class MinskyMysteryDiv2 {
	public:
	long long computeAnswer(long long N) {
//		VI m(5);
//		m[0]=N;
//		return f(m);
		if(N<2) return -1;
		if(N%2==0) return 2+N/2;
		for(ll i=3;i*i<=N;i+=2) {
			if(N%i==0) return i+N/i;
		}
		return N+1;
	}
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 3LL; verify_case(0, Arg1, computeAnswer(Arg0)); }
	void test_case_1() { long long Arg0 = 3LL; long long Arg1 = 4LL; verify_case(1, Arg1, computeAnswer(Arg0)); }
	void test_case_2() { long long Arg0 = 4LL; long long Arg1 = 4LL; verify_case(2, Arg1, computeAnswer(Arg0)); }
	void test_case_3() { long long Arg0 = 15LL; long long Arg1 = 8LL; verify_case(3, Arg1, computeAnswer(Arg0)); }
	//void test_case_4() { long long Arg0 = 24LL; long long Arg1 = 14LL; verify_case(4, Arg1, computeAnswer(Arg0)); }
	void test_case_4() { long long Arg0 = 999663912463LL; long long Arg1 = 14LL; verify_case(4, Arg1, computeAnswer(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  MinskyMysteryDiv2 ___test;
  ___test.run_test(-1);
  //___test.test_case_0();
  //REP(i, 100) cout<<i<<" -> "<<___test.computeAnswer(i)<<endl;
}
// END CUT HERE
