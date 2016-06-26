// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
John and Brus are studying string theory at the university.  Their task is to create a list of all the palindromes that contain between 1 and n lowercase letters ('a'-'z'), inclusive.  A palindrome is a string that reads the same forward and backward.  Additionally, each palindrome in their list must contain no more than k distinct letters.  Return the number of palindromes in the list modulo 1234567891.


DEFINITION
Class:TheLongPalindrome
Method:count
Parameters:int, int
Returns:int
Method signature:int count(int n, int k)


CONSTRAINTS
-n will be between 1 and 1,000,000,000, inclusive.
-k will be between 1 and 26, inclusive.


EXAMPLES

0)
1
1

Returns: 26

All palindromes in the list are single character strings.

1)
2
10

Returns: 52

Now we have single and double character palindromes.

2)
3
2

Returns: 728

A slightly longer list.

3)
44
7

Returns: 240249781

*/
// END CUT HERE
#line 56 "TheLongPalindrome.cpp"

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
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



/////////////////////// [OPTION] matrix
typedef ll number;
//typedef double number;
typedef vector<number> array;
typedef vector<array> matrix;

// O( n )
matrix identity(int n) {
	matrix A(n, array(n));
	//for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) A[i][j] = -INF;   // e for '+'
	for (int i = 0; i < n; ++i) A[i][i] = 1;  // e for '*'
	return A;
}
// O( n )
number inner_product(const array &a, const array &b) {
  number ans = 0;
  for (int i = 0; i < a.size(); ++i)
    ans += a[i] * b[i];
  return ans;
}
// O( n^2 )
array mul(const matrix &A, const array &x) {
  array y(A.size());
  for (int i = 0; i < A.size(); ++i)
    for (int j = 0; j < A[0].size(); ++j)
      y[i] += A[j][i] * x[j];
  return y;
}
// O( n^3 )
matrix mul(const matrix &A, const matrix &B) {
	matrix C(A.size(), array(B[0].size(), 0 /* e for '+' */));
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[i].size(); ++j)
			for (int k = 0; k < A[i].size(); ++k)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j])%1234567891;   // '+' and '*'
				//C[i][j] = max(C[i][j], A[i][k] + B[k][j]);
	return C;
}
// O( n^2 )
matrix add(const matrix &A, const matrix &B) {
	matrix C(A.size(), array(A[0].size(), 0 /* e for '+' */));
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[i].size(); ++j)
			C[i][j] = (A[i][j] + B[i][j])%1234567891;   // '+' and '*'
			//C[i][j] = max(A[i][k], B[k][j]);
	return C;
}
// O( n^3 log e )
matrix pow(const matrix &A, int e) {
	return e == 0 ? identity(A.size()):
		 e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}
matrix powsum(const matrix &A, int e) {
	return e == 0 ? matrix(A.size(), array(A.size(), 0)):
		 e % 2 == 0 ? mul(add(identity(A.size()), pow(A, e/2)), powsum(A, e/2)) : add(pow(A, e), powsum(A, e-1));
}
std::ostream& operator<<(std::ostream& os, const matrix& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << "\n"; } return os; }
/////////////////////// [OPTION] matrix


class TheLongPalindrome {
	public:
	int count(int n, int k) {
		matrix A(27, array(27, 0));
		REP(i, 27) {
			A[i][i]=i;
			if(i>0) A[i-1][i]=27-i;
		}
		//cout<<A<<endl;
		array V(27);
		V[0]=1;
		
		matrix B=add(powsum(A, (n+1)/2), powsum(A, n/2));
		//cout<<B<<endl;
		//cout<<V<<endl;
		V=mul(B, V);
		cout<<V<<endl;
		
		ll ans=0;
		REP(i, k+1) ans=(ans+V[i])%1234567891;
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 26; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 52; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 728; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 44; int Arg1 = 7; int Arg2 = 240249781; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	TheLongPalindrome ___test;

	___test.run_test(-1);
	//___test.test_case_0();

}

// END CUT HERE
