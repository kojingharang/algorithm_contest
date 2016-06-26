// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// The prime factorization of a number X is the list of prime numbers that multiply together to form X.  For example, the prime factorization of 12 is 2 * 2 * 3.  Note that 1 is not a prime number.
An underprime is a number whose prime factorization contains a prime number of elements.  For example, 12 is an underprime because its prime factorization contains 3 elements, and 3 is a prime number.  Given ints A and B, return the number of underprimes between A and B, inclusive.

DEFINITION
Class:Underprimes
Method:howMany
Parameters:int, int
Returns:int
Method signature:int howMany(int A, int B)


NOTES
-A positive integer number is called prime if it has exactly two divisors - 1 and itself. For example, 2, 3, 5 and 7 are prime numbers, and 4, 6, 8 and 9 are not prime. By convention, 1 is not considered to be a prime number.
-All prime factorizations of the same integer always contain the same prime numbers and can only differ by the order of primes within them.


CONSTRAINTS
-A will be between 2 and 100000, inclusive.
-B will be between A and 100000, inclusive.


EXAMPLES

0)
2
10

Returns: 5

The underprimes in this interval are: 4, 6, 8, 9, 10.

1)
100
105

Returns: 2

The underprimes in this interval are 102 = 2 * 3 * 17 and 105 = 3 * 5 * 7.

2)
17
17

Returns: 0

17 is a prime number, so its prime factorization contains one element. 1 is not a prime, so 17 is not an underprime.

3)
123
456

Returns: 217



*/
// END CUT HERE
#line 62 "Underprimes.cpp"

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


int ppt[100000];
VI pt;

int up(int N) {
	int ans = 0;
	FOR(v, pt) {
		while(N%*v==0) {ans++; N/=*v;}
		if(N==1) break;
	}
	if(N>1) cout<<N<<endl;
	//cout<<ans<<endl;
	if(ppt[ans]==0) return 1;
	return 0;
}

class Underprimes {
	public:
	int howMany(int A, int B) {
		memset(ppt, 0, sizeof(ppt));
		ppt[0]=ppt[1]=1;
		for(int i=2;i<100000;i++) {
			for(int j=i*2;j<100000;j+=i) {
				ppt[j] = 1;
			}
		}
		pt.clear();
		for(int i=2;i<100000;i++) if(ppt[i]==0) pt.push_back(i);
		//cout<<pt<<endl;
		int ans = 0;
		for(int i=A;i<=B;i++) ans+=up(i);
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 5; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 105; int Arg2 = 2; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = 17; int Arg2 = 0; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	//void test_case_3() { int Arg0 = 123; int Arg1 = 456; int Arg2 = 217; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 100000; int Arg2 = 217; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	Underprimes ___test;

	___test.run_test(-1);
	//___test.test_case_0();

}

// END CUT HERE
