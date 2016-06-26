// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Consider the following function:
f(X) = Waai + X + Akari + X + Daisuki
Here, X is a string and + denotes string concatenation.
Waai, Akari and Daisuki are constant non-empty strings.



You are given 5 strings Waai, Akari, Daisuki, S and F, and a  int k. 
Compute how many times F occurs in f^k(S) as its substring. (The notation f^k(S) means that f is applied to S exactly k times in a row. See Notes for a formal definition.) Since the number can be quite large, compute the number modulo 1,000,000,007.


DEFINITION
Class:AkariDaisukiDiv1
Method:countF
Parameters:string, string, string, string, string, int
Returns:int
Method signature:int countF(string Waai, string Akari, string Daisuki, string S, string F, int k)


NOTES
-Formally, we have f^1(X)=f(X) and for k greater than one we have f^k(X)=f(f^(k-1)(X)).
-String A is substring of B if A can be obtained by erasing some (possibly zero) characters from the beginning of B and some (possibly zero) characters from the end of B.


CONSTRAINTS
-Waai, Akari, Daisuki, S, and F will contain between 1 and 50 characters, inclusive.
-Each character of Waai, Akari, Daisuki, S, and F will be a lowercase letter ('a'-'z').
-k will be between 1 and 10,000,000, inclusive.


EXAMPLES

0)
"a"
"b"
"c"
"x"
"axb"
2

Returns: 2

S = "x",
f(S) = "axbxc",
f^2(S) = f("axbxc") = "aaxbxcbaxbxcc".
This string contains the substring "axb" twice.

1)
"a"
"b"
"c"
"x"
"abcdefghij"
1

Returns: 0

The answer can be zero.

2)
"a"
"a"
"a"
"b"
"aba"
2

Returns: 4

S = "b",
f(S) = "ababa",
f^2(S) = f("ababa") = "aababaaababaa".
This string contains the substring "aba" four times. You must count overlapping substrings.

3)
"a"
"b"
"c"
"d"
"baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba"
58

Returns: 191690599



4)
"a"
"x"
"y"
"b"
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
49

Returns: 1



5)
"waai"
"akari"
"daisuki"
"usushio"
"id"
10000000

Returns: 127859200



6)
"vfsebgjfyfgerkqlr"
"ezbiwls"
"kjerx"
"jbmjvaawoxycfndukrjfg"
"bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs"
1575724

Returns: 483599313

*/
// END CUT HERE
#line 128 "AkariDaisukiDiv1.cpp"

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
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T> v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class AkariDaisukiDiv1 {
	public:
	int countF(string Waai, string Akari, string Daisuki, string S, string F, int k) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
 { os << "{ ";
   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k));}
int main(){

CASE(0)
	string Waai = "a"; 
	string Akari = "b"; 
	string Daisuki = "c"; 
	string S = "x"; 
	string F = "axb"; 
	int k = 2; 
	int _ = 2; 
END
CASE(1)
	string Waai = "a"; 
	string Akari = "b"; 
	string Daisuki = "c"; 
	string S = "x"; 
	string F = "abcdefghij"; 
	int k = 1; 
	int _ = 0; 
END
CASE(2)
	string Waai = "a"; 
	string Akari = "a"; 
	string Daisuki = "a"; 
	string S = "b"; 
	string F = "aba"; 
	int k = 2; 
	int _ = 4; 
END
CASE(3)
	string Waai = "a"; 
	string Akari = "b"; 
	string Daisuki = "c"; 
	string S = "d"; 
	string F = "baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba"; 
	int k = 58; 
	int _ = 191690599; 
END
CASE(4)
	string Waai = "a"; 
	string Akari = "x"; 
	string Daisuki = "y"; 
	string S = "b"; 
	string F = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"; 
	int k = 49; 
	int _ = 1; 
END
CASE(5)
	string Waai = "waai"; 
	string Akari = "akari"; 
	string Daisuki = "daisuki"; 
	string S = "usushio"; 
	string F = "id"; 
	int k = 10000000; 
	int _ = 127859200; 
END
CASE(6)
	string Waai = "vfsebgjfyfgerkqlr"; 
	string Akari = "ezbiwls"; 
	string Daisuki = "kjerx"; 
	string S = "jbmjvaawoxycfndukrjfg"; 
	string F = "bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs"; 
	int k = 1575724; 
	int _ = 483599313; 
END

}
// END CUT HERE
