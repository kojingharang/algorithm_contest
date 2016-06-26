// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You have decided to sell your stamp collection, which consists of n stamps numbered 0 to n-1.  You have already found some buyers.  The i-th buyer wants to buy the stamps listed in demand[i].  This will be a space-separated list containing either one or two stamps.  He is willing to pay a total of price[i].  If he wants to buy two stamps, he will not agree to buy only one of them.

To make this task simpler, for each stamp, there will be no more than two buyers who want to buy it.  Return the maximum amount of money you can get from selling your stamps.

DEFINITION
Class:StampsCollection
Method:sell
Parameters:int, vector <string>, vector <int>
Returns:int
Method signature:int sell(int n, vector <string> demand, vector <int> price)


NOTES
-You don't have to sell all of your stamps.


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-demand will contain between 1 and 50 elements, inclusive.
-price will contain the same number of elements as demand.
-Each element of demand will be a space-separated list of one or two distinct integers.
-All numbers in demand will be between 0 and n-1, inclusive, with no leading zeroes.
-All numbers in price will be between 1 and 1000000, inclusive.
-For each stamp, there will be at most 2 buyers who want to buy it.


EXAMPLES

0)
10
{"0 4"}
{3}

Returns: 3

There is only one buyer, so all we can do is to sell two stamps.

1)
2
{"1 0","0"}
{3,5}

Returns: 5

There are two buyers, but both want to buy stamp 0. 

2)
3
{"0 1","0 2","1 2"}
{10,11,12}

Returns: 12

Only one buyer can get what he wants - we choose the third one, who is willing to pay the most.

3)
3
{"0","1 0","1 2"}
{5,9,5}

Returns: 10

Although the second buyer will pay the most, it is better to choose the first and third buyers.

4)
20
{"0 1","1 2","2 3","3 0","4 5","5 6","6 4","8","8","9","9 10","10 11","11 12","12"}
{3,7,4,1,3,3,1,5,6,5,18,10,1,5}

Returns: 40



*/
// END CUT HERE
#line 80 "StampsCollection.cpp"

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

map<pair<ll, int>, int> memo;

int f(ll rest, int n, VVI& dem, VI& pri) {
	if(n==0 || rest==0) return 0;
	pair<ll, int> key(rest, n);
	if(memo.count(key)) return memo[key];
	int i=n-1;
	ll pat=0;
	REP(j, dem[i].size()) pat |= 1LL<<dem[i][j];
	int ma = f(rest, n-1, dem, pri);
	if((rest&pat)==pat) ma=max(ma, pri[i]+f(rest&~pat, n-1, dem, pri));
	//cout<<"f "<<rest<<" "<<n<<" -> "<<ma<<endl;
	return memo[key] = ma;
}


class StampsCollection {
	public:
	int sell(int n, vector <string> dema, vector <int> pri) {
		memo.clear();
		VVI dem(dema.size());
		REP(i, dem.size()) {
			stringstream ss(dema[i]);
			int v;
			while(ss>>v) { dem[i].push_back(v); }
		}
		cout<<dem<<endl;
		int ans = f((1LL<<n)-1, dem.size(), dem, pri);
		cout<<memo.size()<<endl;
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; string Arr1[] = {"0 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"1 0","0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(1, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"0 1","0 2","1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,11,12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(2, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; string Arr1[] = {"0","1 0","1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,9,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(3, Arg3, sell(Arg0, Arg1, Arg2)); }
	//void test_case_4() { int Arg0 = 20; string Arr1[] = {"0 1","1 2","2 3","3 0","4 5","5 6","6 4","8","8","9","9 10","10 11","11 12","12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,7,4,1,3,3,1,5,6,5,18,10,1,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 40; verify_case(4, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 50; string Arr1[] = {
		"17", "35 27", "9 23", "41 1", "4", "36", "45", "12 14", "16 0", "18 39", "38 40", "44 9", "32 22", "3 34", "46", "36", "40 0", "4 12", "18 25", "20 48", "11", "27 34", "38 16", "33", "46 33", "39", "35 24", "17 1", "29 7", "19", "7 25", "23 28", "8 47", "31 32", "20 49", "5 26", "8 24", "42 43", "28", "26 2", "15", "43 15", "44 48", "13 21", "21 42", "47", "3 30", "2", "22 10", "5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {1, 2, 2, 4, 5, 2, 2, 1, 2, 2, 5, 4, 3, 4, 5, 5, 3, 1, 5, 2, 1, 5, 5, 3, 1, 2, 5, 5, 4, 2, 5, 1, 3, 1, 5, 2, 2, 1, 4, 5, 4, 3, 1, 2, 2, 5, 3, 1, 2, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	int Arg3 = 99; verify_case(4, Arg3, sell(Arg0, Arg1, Arg2)); }



// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	StampsCollection ___test;

	___test.run_test(-1);

}

// END CUT HERE
