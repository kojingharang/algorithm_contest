// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
John is obsessed with security.
Recently he bought a new electronic lock.
It is protected by a password containing n digits, where each digit is either zero or one.
John decides to change the password every day.
On the first day, the password is all zeroes.
On each day that follows, he will select one or more digits that all have the same value and change their values (so zeroes become ones, and ones become zeroes).
He must select the digits according to the following rules:

During the first 2^n days, he must never use the same password twice.
Each new password must come as early as possible alphabetically while not violating rule 1.




For example, if n is 2, the password on the first day is "00".
The next day, he can change one or both 0's to get "01", "10" or "11".
Of these possibilities, "01" comes earliest alphabetically.
The next day, he can change either the 0 or the 1 to get "11" or "00".
He can't choose "00" because it was already used, so he chooses "11".
The next day, he can change one or both 1's to get "10", "01" or "00".
He has already used "01" and "00", so he must choose "10".



Given ints n and k, return the password that comes latest alphabetically during the first k days.



DEFINITION
Class:TheLockDivOne
Method:password
Parameters:int, long long
Returns:string
Method signature:string password(int n, long long k)


NOTES
-If A and B are two strings of the same length, then A comes earlier alphabetically than B if it contains a smaller character at the first position where the strings differ.


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-k will be between 1 and 2^n, inclusive.


EXAMPLES

0)
2
4

Returns: "11"

This is the example from the statement.
The password sequence is the following - "00", "01", "11", "10".

1)
3
8

Returns: "111"

"000", "001", "011", "010", "110", "100", "101", "111".

2)
4
6

Returns: "0110"



3)
10
1

Returns: "0000000000"



4)
7
100

Returns: "1111110"



*/
// END CUT HERE
#line 96 "TheLockDivOne.cpp"

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


string kth(int n, ll k) {
	ll m = 1LL<<(n-1);
	if(n==1) {
		return k==0?"0":"1";
	}
	if(m>k) {
		return "0"+kth(n-1, k);
	} else {
		return "1"+kth(n-1, (k-1+m)%m);
	}
}

string pw(int n, ll k) {
	ll m = 1LL<<(n-1);
	if(n==1) {
		return k==0?"0":"1";
	}
	if(m>k) {
		return "0"+pw(n-1, k);
	} else {
		string best = kth(n-1, m-1);
		if(k-1-m>0) best = max(best, pw(n-1, k-1-m));
		return "1"+best;
	}
}

class TheLockDivOne {
	public:
	string password(int n, long long k) {
		//return kth(n, k);
		return pw(n, k-1);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 4LL; string Arg2 = "11"; verify_case(0, Arg2, password(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 8LL; string Arg2 = "111"; verify_case(1, Arg2, password(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; long long Arg1 = 6LL; string Arg2 = "0110"; verify_case(2, Arg2, password(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; long long Arg1 = 1LL; string Arg2 = "0000000000"; verify_case(3, Arg2, password(Arg0, Arg1)); }
	//void test_case_4() { int Arg0 = 7; long long Arg1 = 100LL; string Arg2 = "1111110"; verify_case(4, Arg2, password(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 10; long long Arg1 = 513LL; string Arg2 = "1111111001"; verify_case(4, Arg2, password(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	TheLockDivOne ___test;

	___test.run_test(-1);

}

// END CUT HERE
