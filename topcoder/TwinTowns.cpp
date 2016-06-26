// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Twin Towns are towns which are paired together to encourage human contact and cultural links.  The government of your country has decided to establish such relationships among a given set of towns.  The following rules must be followed:

Each town must have between 0 and maxPartners twins, inclusive.
The distance between each pair of twin towns must be at least minDistance.  The distance between two towns located at (x1, y1) and (x2, y2) is defined as |x1-x2| + |y1-y2|.



The government will establish as many relationships as possible.  If there are multiple ways to do this, the government will choose the one that minimizes the sum of the distances between each pair of twin towns.  You are given vector <int>s x and y, where (x[i], y[i]) are the coordinates of the i-th town.  Return a vector <int> containing exactly two elements, where the first element is the number of relationships the government will establish, and the second element is the sum of the distances between each pair of twin towns.

DEFINITION
Class:TwinTowns
Method:optimalTwinTowns
Parameters:vector <int>, vector <int>, int, int
Returns:vector <int>
Method signature:vector <int> optimalTwinTowns(vector <int> x, vector <int> y, int maxPartners, int minDistance)


CONSTRAINTS
-maxPartners will be between 1 and 3, inclusive.
-x and y will contain between 1 and 10 elements, inclusive.
-x and y will contain the same number of elements.
-Each element of x and y will be between 0 and 1,000, inclusive.
-minDistance will be between 1 and 2,000, inclusive.
-No two towns will have the same coordinates.


EXAMPLES

0)
{0,0,10}
{0,10,4}
1
1

Returns: {1, 10 }

We have 3 towns here at coordinates (0,0), (0,10), and (10,4).  Each town can have at most one twin.  Since we have only 3 towns, we can establish at most one pair of twin towns.  The best solution pairs the first and second towns, where the distance is 10.

1)
{0,0,10}
{0,10,4}
1
11

Returns: {1, 14 }

These are the same towns from Example 0, but minDistance is now 11.  The first and second towns cannot be twins.  The best solution is to pair the first and third towns, where the distance is 14.

2)
{0,10,0,10}
{0,0,20,20}
1
1

Returns: {2, 20 }

Here we have 4 towns located at the vertices of a rectangle.  Each town can have at most one twin.  The best solution is to pair the first town with the second, and the third town with the fourth.  The distance between each pair is 10.


3)
{0,10,0,10}
{0,0,20,20}
2
10

Returns: {4, 60 }

These are the same towns from Example 2, but now, each town can have up to two twins.  The best solution establishes 4 pairs of twin towns:

the first city at (0,0) with the second city at (10,0), where the distance is 10
the first city at (0,0) with the third city at (0,20), where the distance is 20
the second city at (10,0) with the fourth city at (10,20), where the distance is 20
the third city at (0,20) with the fourth city at (10,20), where the distance is 10

The sum of the distances is 60.

4)
{0,0,0,0,0,0,0,0,0}
{1,2,3,4,5,6,7,8,9}
3
6

Returns: {6, 40 }

We can pair the following list of towns (indexed from 1): 1-7, 1-8, 1-9, 2-8, 2-9, 3-9.

*/
// END CUT HERE
#line 93 "TwinTowns.cpp"

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

#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define PII pair<int, int> 
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



#define INF 10000000

map<VI, PII > memo;

// solve subset problem with only i<=k<N nodes
PII f(int i, int N, VI& rest, VVI& cost) {
	if(i==N) return make_pair(0, 0);
	
	VI key(rest.begin()+i, rest.end());
	if(memo.count(key)) return memo[key];
	
	// choose 0 from node i
	PII best = f(i+1, N, rest, cost);
	
	// choose 1 from node i
	if(rest[i]>=1) {
		for(int i0=i+1;i0<N;i0++) if(cost[i][i0]!=INF && rest[i0])
		{
			rest[i0]--;
			PII lans = f(i+1, N, rest, cost);
			lans.first+=1;
			lans.second-=cost[i][i0];
			best = max(best, lans);
			rest[i0]++;
		}
	}
	// choose 2 from node i
	if(rest[i]>=2) {
		for(int i0=i+1;i0<N;i0++) if(cost[i][i0]!=INF && rest[i0])
		for(int i1=i0+1;i1<N;i1++) if(cost[i][i1]!=INF && rest[i1])
		{
			rest[i0]--;
			rest[i1]--;
			PII lans = f(i+1, N, rest, cost);
			lans.first+=2;
			lans.second-=cost[i][i0]+cost[i][i1];
			best = max(best, lans);
			rest[i0]++;
			rest[i1]++;
		}
	}
	// choose 3 from node i
	if(rest[i]>=3) {
		for(int i0=i+1;i0<N;i0++) if(cost[i][i0]!=INF && rest[i0])
		for(int i1=i0+1;i1<N;i1++) if(cost[i][i1]!=INF && rest[i1])
		for(int i2=i1+1;i2<N;i2++) if(cost[i][i2]!=INF && rest[i2])
		{
			rest[i0]--;
			rest[i1]--;
			rest[i2]--;
			PII lans = f(i+1, N, rest, cost);
			lans.first+=3;
			lans.second-=cost[i][i0]+cost[i][i1]+cost[i][i2];
			best = max(best, lans);
			rest[i0]++;
			rest[i1]++;
			rest[i2]++;
		}
	}
	return memo[key] = best;
}

class TwinTowns {
	public:
	vector <int> optimalTwinTowns(vector <int> x, vector <int> y, int maxp, int mind) {
		memo.clear();
		int N=x.size();
		VVI cost(N, VI(N));
		REP(i, N) REP(j, N) {
			cost[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
			if(cost[i][j]<mind) cost[i][j]=INF;
		}
		
		VI rest(N, maxp);
		PII r = f(0, N, rest, cost);
		
		VI ans;
		ans.push_back(r.first);
		ans.push_back(-r.second);
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0,0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; int Arr4[] = {1, 10 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, optimalTwinTowns(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 11; int Arr4[] = {1, 14 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, optimalTwinTowns(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,10,0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,20,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; int Arr4[] = {2, 20 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, optimalTwinTowns(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,10,0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,20,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 10; int Arr4[] = {4, 60 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, optimalTwinTowns(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; int Arr4[] = {6, 40 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, optimalTwinTowns(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	TwinTowns ___test;

	___test.run_test(-1);
	//___test.test_case_1();

}

// END CUT HERE
