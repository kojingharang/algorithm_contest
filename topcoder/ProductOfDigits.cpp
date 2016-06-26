// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are given an int N.  Find the smallest positive integer X such that the product of its digits (in decimal notation) is equal to N.  Return the number of digits in X, or return -1 if such a number does not exist.

DEFINITION
Class:ProductOfDigits
Method:smallestNumber
Parameters:int
Returns:int
Method signature:int smallestNumber(int N)


CONSTRAINTS
-N will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
1

Returns: 1

Just take X = 1. It contains 1 digit.

1)
10

Returns: 2

Here the smallest possible X is 25.

2)
26

Returns: -1



3)
100

Returns: 3

The number 455 has 3 digits and the product of its digits is 4 * 5 * 5 = 100.

4)
2520

Returns: 4



5)
864

Returns: 4



*/
// END CUT HERE
#line 65 "ProductOfDigits.cpp"

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



class ProductOfDigits {
	public:
	int smallestNumber(int N) {
		if(N==1) return 1;
		VI w;
		for(int i=2;i*i<=N;i++) {
			while(N%i==0) {
				if(i>9) return -1;
				N/=i;
				w.push_back(i);
			}
		}
		if(N>9) return -1;
		if(N>0) w.push_back(N);
		int ans=w.size();
		sort(ALL(w));
		reverse(ALL(w));
		cout<<w<<"  "<<N<<endl;
		REP(i, w.size()) {
			if(w[i]==0)continue;
			for(int j=i+1;j<w.size();j++) {
				if(w[j]==0)continue;
				if(w[i]*w[j]<10) {
					ans--;
					w[i]*=w[j];
					w[j]=0;
				}
			}
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, smallestNumber(Arg0)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 2; verify_case(1, Arg1, smallestNumber(Arg0)); }
	void test_case_2() { int Arg0 = 26; int Arg1 = -1; verify_case(2, Arg1, smallestNumber(Arg0)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 3; verify_case(3, Arg1, smallestNumber(Arg0)); }
	void test_case_4() { int Arg0 = 2520; int Arg1 = 4; verify_case(4, Arg1, smallestNumber(Arg0)); }
	void test_case_5() { int Arg0 = 864; int Arg1 = 4; verify_case(5, Arg1, smallestNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	ProductOfDigits ___test;

	___test.run_test(-1);

}

// END CUT HERE
