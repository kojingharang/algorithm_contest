// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A permutation A[0], A[1], ..., A[N-1] is a sequence containing each integer between 0 and N-1, inclusive, exactly once.  Each permutation A of length N has a corresponding child array B of the same length, where B is defined as follows:


B[0] = 0
B[i] = A[B[i-1]], for every i between 1 and N-1, inclusive.


A permutation is considered perfect if its child array is also a permutation.

Below are given all permutations for N=3 with their child arrays. Note that for two of these permutations ({1, 2, 0} and {2, 0, 1}) the child array is also a permutation, so these two permutations are perfect.


Permutation		Child array
{0, 1, 2}		{0, 0, 0}
{0, 2, 1}		{0, 0, 0}
{1, 0, 2}		{0, 1, 0}
{1, 2, 0}		{0, 1, 2}
{2, 0, 1}		{0, 2, 1}
{2, 1, 0}		{0, 2, 0}


You are given a vector <int> P containing a permutation of length N.  Find a perfect permutation Q of the same length such that the difference between P and Q is as small as possible, and return this difference.  The difference between P and Q is the number of indices i for which P[i] and Q[i] are different.

DEFINITION
Class:PerfectPermutation
Method:reorder
Parameters:vector <int>
Returns:int
Method signature:int reorder(vector <int> P)


CONSTRAINTS
-P will contain between 1 and 50 elements, inclusive.
-P will contain each integer between 0 and N-1, inclusive, exactly once, where N is the number of elements in P.


EXAMPLES

0)
{2, 0, 1}

Returns: 0

P is a perfect permutation, so we can use the same permutation for Q.  The difference is then 0 because P and Q are the same.

1)
{2, 0, 1, 4, 3}

Returns: 2

Q might be {2, 0, 3, 4, 1}.

2)
{2, 3, 0, 1}

Returns: 2

Q might be {1, 3, 0, 2}.

3)
{0, 5, 3, 2, 1, 4}

Returns: 3



4)
{4, 2, 6, 0, 3, 5, 9, 7, 8, 1}

Returns: 5



*/
// END CUT HERE
#line 80 "PerfectPermutation.cpp"

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



class PerfectPermutation {
	public:
	int reorder(vector <int> P) {
		VI done(P.size());
		int ans=0;
		REP(i, P.size()) {
			if(done[i]) continue;
			ans++;
			int idx=i;
			while(done[idx]==0) { done[idx]=1; idx=P[idx]; }
		}
		return ans==1 ? 0 : ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, reorder(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 0, 1, 4, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, reorder(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 3, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, reorder(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 5, 3, 2, 1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, reorder(Arg0)); }
	void test_case_4() { int Arr0[] = {4, 2, 6, 0, 3, 5, 9, 7, 8, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, reorder(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	PerfectPermutation ___test;

	___test.run_test(-1);

}

// END CUT HERE
