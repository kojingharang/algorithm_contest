// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are organizing a party and have bought several pieces of cake for it. The weights of these pieces are given in the vector <int> weights, where each element corresponds to the weight of a single piece.

After looking at the pieces more carefully, you became worried that they have different weights and decided to make these differences smaller. In order to do this, you can make at most maxCuts cuts. With each cut you can choose one of the pieces you currently have and divide it into two distinct pieces. Note that each of these two pieces can be chosen again when making subsequent cuts.

Your goal is to produce cuts in such way that the difference between the maximal and the minimal pieces' weights becomes as small as possible. Find the best way of making cuts and return the optimal difference.

DEFINITION
Class:CakesEqualization
Method:fairDivision
Parameters:vector <int>, int
Returns:double
Method signature:double fairDivision(vector <int> weights, int maxCuts)


NOTES
-Your return value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-weights will contain between 1 and 50 elements, inclusive.
-Each element of weights will be between 1 and 1,000,000,000, inclusive.
-maxCuts will be between 1 and 100,000, inclusive.


EXAMPLES

0)
{1, 3}
2

Returns: 0.0

First, choose the piece with weight 3 and cut it into pieces with weights 1 and 2. Then, choose the piece with weight 2 and cut it into two pieces with weight 1. Now all pieces have the same weight, so the answer is 0.

1)
{1, 1, 1, 1, 1}
4

Returns: 0.0

Even though you are allowed to make 4 cuts, there is no sense in making any of them.

2)
{1, 3}
1

Returns: 0.5

The same case as in example 0, but now you are allowed to make only one cut. The best thing to do is to cut the piece with weight 3 into two pieces with weights 1.5.

3)
{7, 11, 13}
10

Returns: 0.3999999999999999



4)
{13, 69, 41, 37, 80}
27

Returns: 1.4666666666666668



*/
// END CUT HERE
#line 73 "CakesEqualization.cpp"

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

VI W;
int mc;

typedef pair<double, double> PDD;

char memoe[50][1000]
PDD memo[50][1000];

PDD f(int i, int cut) {
	cout<<"f "<<i<<" "<<cut<<endl;
	if(i==0) {
		double a=W[i]/(cut+1);
		return make_pair(a, a);
	}
	PDD ans = make_pair(0, 1000000);
	REP(j, cut+1) {
		//cout<<"cut "<<j<<endl;
		double b = (double)W[i]/(j+1);
		REP(k, cut-j+1) {
			PDD a = f(i-1, k);
			//cout<<a<<" "<<b<<endl;
			a.first = min(a.first, b);
			a.second = max(a.second, b);
			if(a.second-a.first<ans.second-ans.first) ans=a;
		}
	}
	//cout<<"f "<<i<<" "<<cut<<"  "<<ans<<endl;
	return ans;
}

class CakesEqualization {
	public:
	double fairDivision(vector <int> weights, int maxCuts) {
		memset(memoe, 0, sizeof(memoe));
		W=weights;
		mc=maxCuts;
		PDD ans = make_pair(0, 1000000);
		REP(i, mc+1) {
			PDD a=f(W.size()-1, i);
			if(a.second-a.first<ans.second-ans.first) ans=a;
		}
		return ans.second-ans.first;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 0.0; verify_case(0, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 0.0; verify_case(1, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 0.5; verify_case(2, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7, 11, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; double Arg2 = 0.3999999999999999; verify_case(3, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {13, 69, 41, 37, 80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; double Arg2 = 1.4666666666666668; verify_case(4, Arg2, fairDivision(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	CakesEqualization ___test;

	___test.run_test(-1);
	//___test.test_case_2();

}

// END CUT HERE
