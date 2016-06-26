// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There's a far away country where only builders live.  They have built a number of cities already, and some of them are connected with bidirectional roads.  The existing roads are given in the vector <string> g, where the j-th character of the i-th element is 'Y' if there's a bidirectional road connecting cities i and j, and 'N' otherwise.  Each city contains a number of houses, given in the vector <int> before, where the i-th element is the number of houses in city i.  Exactly one builder lives in each house.

The country will go through a two-phase building process.  In the first phase, new bidirectional roads will be built so that every pair of cities will be connected by some path.  When a road is built between two cities, every builder from both cities will be involved and each builder will be paid roadCost units of money.

In the second phase, new houses will be built.  You are given a vector <int> after, where the i-th element is the number of houses that must exist in city i after this phase is complete.  In other words, after[i] - before[i] new houses must be built in city i during this phase.  When a house is built, all builders in that city and all its neighboring cities will be involved and each one will be paid houseCost[i] units of money.  Two cities are neighboring if they are directly connected by a road.  After each house is built, a new builder will immediately live in that house.  Houses can be built in any order.

Return the minimal possible cost required to finish both phases of the building process.

DEFINITION
Class:BuildersCountry
Method:minCost
Parameters:vector <int>, vector <int>, vector <int>, vector <string>, int
Returns:long long
Method signature:long long minCost(vector <int> before, vector <int> after, vector <int> houseCost, vector <string> g, int roadCost)


CONSTRAINTS
-before will contain between 1 and 50 elements, inclusive.
-Each element of before will be between 1 and 100000, inclusive.
-after will contain the same number of elements as before.
-The i-th element of after will be between the i-th element of before and 100000, inclusive.
-houseCost will contain the same number of elements as before.
-Each element of houseCost will be between 1 and 100000, inclusive.
-g will contain the same number of elements as before.
-Each element of g will contain exactly n characters, where n is the number of elements in g.
-Each element of g will contain only uppercase letters 'Y' and 'N'.
-The i-th character of the i-th element of g will always be 'N'.
-The i-th character of the j-th element of g will always be equal to the j-th character of the i-th element of g.
-roadCost will be between 1 and 100000, inclusive.


EXAMPLES

0)
{2, 1, 3, 5}
{2, 1, 3, 5}
{4, 5, 3, 2}
{"NNNN", "NNNN", "NNNN", "NNNN"}
1000

Returns: 13000

We can build roads from city 1 to all other cities for a total cost (1+2)*1000 + (1+3)*1000 + (1+5)*1000 = 13000. All houses are already built.

1)
{1, 1, 1, 1}
{1, 3, 1, 2}
{8, 5, 3, 2}
{"NYNN", "YNYN", "NYNY", "NNYN"}
100000

Returns: 39

We don't need to add any roads. If we build one house in city 1, we need to pay 5*(1+1+1). After that, build one house in city 3 for a cost of 2*(1+1). Then, build another house in city 1.  This time, the cost will be 5*(1+2+1) since 2 workers now live in city 1. The total cost is 15+4+20=39.

2)
{9, 11}
{10, 11}
{5, 1}
{"NN", "NN"}
15

Returns: 400

Build one road and build one house.

3)
{1}
{1000}
{2}
{"N"}
888

Returns: 999000

Build 999 houses. Total cost is (1+2+...+999)*2 = 999000.

4)
{99, 23, 44, 55, 32}
{99, 23, 44, 55, 32}
{39, 32, 11, 23, 89}
{"NYNNN", "YNNNY", "NNNYY", "NNYNY", "NYYYN"}
54

Returns: 0

*/
// END CUT HERE
#line 93 "BuildersCountry.cpp"

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



class BuildersCountry {
	public:
	long long minCost(vector <int> before, vector <int> after, vector <int> houseCost, vector <string> g, int roadCost) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 1, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 5, 3, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"NNNN", "NNNN", "NNNN", "NNNN"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1000; long long Arg5 = 13000LL; verify_case(0, Arg5, minCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 5, 3, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"NYNN", "YNYN", "NYNY", "NNYN"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 100000; long long Arg5 = 39LL; verify_case(1, Arg5, minCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {9, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"NN", "NN"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 15; long long Arg5 = 400LL; verify_case(2, Arg5, minCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"N"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 888; long long Arg5 = 999000LL; verify_case(3, Arg5, minCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arr0[] = {99, 23, 44, 55, 32}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {99, 23, 44, 55, 32}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {39, 32, 11, 23, 89}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"NYNNN", "YNNNY", "NNNYY", "NNYNY", "NYYYN"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 54; long long Arg5 = 0LL; verify_case(4, Arg5, minCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	BuildersCountry ___test;

	___test.run_test(-1);

}

// END CUT HERE
