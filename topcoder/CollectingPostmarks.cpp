// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Your hoBy is collecting postmarks.  There is a total of N distinct postmarks, numbered from 0 to N-1.  Their prices are given in the vector <int> prices, where the i-th element (0-indexed) is the price of postmark i.  The price of a postmark is the amount of money you would get for selling it, and the amount of money it would cost you to buy it.  The values of the postmarks are given in the vector <int> values, where the i-th element (0-indexed) is the value of postmark i.  Only one of each postmark exists.

The postmarks you currently have are given in the vector <int> have.  Your goal is to have a postmark collection with a total value of at least K.  You can sell postmarks to get money to buy different postmarks.  Initially, you have no money.  Return the minimum additional amount of money you need to achieve your goal, or -1 if it is impossible.

DEFINITION
Class:CollectingPostmarks
Method:amountOfMoney
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:int
Method signature:int amountOfMoney(vector <int> prices, vector <int> have, vector <int> values, int K)


CONSTRAINTS
-N will be between 1 and 32, inclusive. 
-K will be between 0 and 1,000,000,000, inclusive. 
-prices will contain exactly N elements. 
-Each element of prices will be between 1 and 30,000,000, inclusive. 
-values will contain exactly N elements. 
-Each element of values will be between 1 and 30,000,000, inclusive. 
-have will contain between 0 and N elements, inclusive. 
-All elements of have will be distinct. 
-Each element of have will be between 0 and N-1, inclusive. 


EXAMPLES

0)
{2,15}
{}
{2,21}
13

Returns: 15

You initially have no postmarks.  You need 15 units of money to buy postmark 1, which has a value of 21.

1)
{9,18,7,6,18}
{4,0}
{12,27,10,10,25}
67

Returns: 22

2)
{14,14,12,6}
{3,2,1}
{19,23,20,7}
10

Returns: 0

You already have enough postmarks.

3)
{43,33,14,31,42,37,17,42,40,20}
{6}
{116,71,38,77,87,106,48,107,91,41}
811

Returns: -1

The total value of all available postmarks is less than 811.

*/
// END CUT HERE
#line 71 "CollectingPostmarks.cpp"

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
#define PII pair<ll, ll> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

//map<pair<int, int>, int> memo;

#define INF (30000000*32+1)
//int f(int n, int k, VI& pri, VI& val) {
//	PII key = make_pair(n, k);
//	if(memo.count(key)) return memo[key];
//	if(k<=0) return 0;
//	if(n==0) return INF;
//	return memo[key] = min(pri[n-1]+f(n-1, k-val[n-1], pri, val), f(n-1, k, pri, val));
//}

class CollectingPostmarks {
	public:
	int amountOfMoney(vector <int> prices, vector <int> have, vector <int> values, int K) {
		int N=prices.size();
		vector<PII> A, B;
		int As = N/2;
		REP(i, 1<<As) {
			ll p=0, v=0;
			REP(j, As) {
				if(i&1<<j) {
					p+=prices[j];
					v+=values[j];
				}
			}
			A.push_back(make_pair(v, p));
		}
		int Bs = N-As;
		REP(i, 1<<Bs) {
			ll p=0, v=0;
			REP(j, Bs) {
				if(i&1<<j) {
					p+=prices[As+j];
					v+=values[As+j];
				}
			}
			B.push_back(make_pair(v, p));
		}
		sort(ALL(A));
		sort(ALL(B));
		//cout<<A<<endl;
		//cout<<B<<endl;
		
		int sub=0;
		REP(i, have.size()) sub+=prices[have[i]];
		
		ll ans = INF;
		int j = B.size()-1;
		ll mi = INF;
		REP(i, A.size()) {
			for(;0<=j && A[i].first+B[j].first>=K;j--) {
				mi = min(mi, (ll)B[j].second);
			}
			ans = min(ans, A[i].second+mi);
			//ans = min(ans, A[i].second+lower_bound(ALL(B), make_pair((ll)K-A[i].first, 0LL))->second);
			//cout<<A[i].second+lower_bound(ALL(B), make_pair((ll)K-A[i].first, 0LL))->second - sub<<endl;
		}
		if(ans>=INF) return -1;
		//memo.clear();
		//if(K<=0) return 0;
		//int ans = f(prices.size(), K, prices, values);
		return max(0LL, ans-sub);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,21}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 13; int Arg4 = 15; verify_case(0, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {9,18,7,6,18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {12,27,10,10,25}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 67; int Arg4 = 22; verify_case(1, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {14,14,12,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {19,23,20,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; int Arg4 = 0; verify_case(2, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }
	//void test_case_3() { int Arr0[] = {43,33,14,31,42,37,17,42,40,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {116,71,38,77,87,106,48,107,91,41}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 811; int Arg4 = -1; verify_case(3, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }
	//void test_case_3() { int Arr0[] = {
	//	30000000,30000000,30000000,30000000,30000000,30000000,30000000,30000000,30000000,30000000,
	//	30000000,30000000,30000000,30000000,30000000,30000000,30000000,30000000,30000000,30000000,
	//	30000000,30000000,
	//}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	//int Arr1[] = {6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	//int Arr2[] = {
	//	30000000,30000000,30000000,30000000,30000000,30000000,30000000,30000000,30000000,30000000,
	//	30000000,30000000,30000000,30000000,30000000,30000000,30000000,30000000,30000000,30000000,
	//	30000000,30000000,
	//}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	//int Arg3 = 30000000*32; int Arg4 = -1; verify_case(3, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }
	
//	void test_case_3() { int Arr0[] = {
//7926025, 18288365, 9446884, 13692942, 8347479, 12539150, 13193411, 11311634, 8430877, 15264147, 10758333, 12814610, 7130588, 16440028, 17533821, 747394, 5274443, 4461421, 16907140, 793361, 12095180, 14632696, 1652989, 866572, 6892565, 753357, 18233830, 1776011, 4818429, 3284046
//	}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
//	int Arr1[] = {24, 12, 1, 7, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
//	int Arr2[] = {
//30000000, 30000000, 30000000, 30000000, 30000000, 30000000, 30000000, 30000000, 30000000, 30000000, 30000000, 30000000, 30000000, 30000000, 30000000, 6155910, 30000000, 30000000, 30000000, 7674180, 30000000, 30000000, 12209803, 7837277, 30000000, 5686338, 30000000, 15322534, 30000000, 30000000
//	}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
//	int Arg3 = 434780920; int Arg4 = 47013717; verify_case(3, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }

	void test_case_3() { int Arr0[] = {
3614405, 2502059, 6183850, 3534570, 7232985, 2326055, 2038641, 8546717, 2522353, 8452864, 2596672, 8158310, 224840, 7761178, 6059806, 9363870, 1302744, 1443619, 10156527, 3039511, 3052029, 5606484, 10454864, 1640839, 9523920
	}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {20, 6, 4, 21, 2, 14, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {
392638, 242568, 760288, 384710, 719491, 229912, 233263, 959031, 238163, 790120, 249827, 846746, 28045, 843109, 715057, 868375, 154820, 178248, 1167466, 305230, 381021, 571271, 1274392, 151475, 936351
	}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	int Arg3 = 9475567; int Arg4 = 51597892; verify_case(3, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	CollectingPostmarks ___test;

	___test.run_test(-1);
	//___test.test_case_3();

}

// END CUT HERE
