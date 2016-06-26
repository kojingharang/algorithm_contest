// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are taking a course in analysis of algorithms and now you are learning about efficient multiplication of large integers. This week, your professor wanted to give you a homework: given a list of integers, determine the product of all elements in the list.

However, later your professor decided that the homework is too difficult and gave you an easier version instead. In this version, you are only required to determine the sign of the product. The professor also gave you some hints:


Any integer multiplied by zero is always zero.
The product of two positive integers is always a positive integer.
The product of a positive integer and a negative integer is always a negative integer.
The product of two negative integers is always a positive integer.


More formally, you are given a vector <int> numbers. Let P be the product of all elements of numbers. If P is positive, return "POSITIVE"; if P is negative, return "NEGATIVE"; else return "ZERO".

DEFINITION
Class:EasyHomework
Method:determineSign
Parameters:vector <int>
Returns:string
Method signature:string determineSign(vector <int> A)


NOTES
-It is possible that the product of all elements of numbers is not representable in 32-bit or 64-bit signed integer data type.


CONSTRAINTS
-numbers will contain between 1 and 50 elements, inclusive.
-Each element of numbers will be between -1,000,000,000 and 1,000,000,000, inclusive.


EXAMPLES

0)
{5, 7, 2}

Returns: "POSITIVE"

The product is 70, which is a positive integer.

1)
{-5, 7, 2}

Returns: "NEGATIVE"

This time the product is -70, which is a negative integer.

2)
{5, 7, 2, 0}

Returns: "ZERO"

The product is 0.

3)
{3, -14, 159, -26}

Returns: "POSITIVE"



4)
{-1000000000}

Returns: "NEGATIVE"



5)
{123, -456, 789, -101112, 131415, 161718, 192021, 222324, 252627, 282930, 313233, 343536, 373839, 404142, 434445, 464748, 495051, 525354, 555657}

Returns: "POSITIVE"

The product is 137646845657507645199797549975668224555202443025319758098026743549006534800854109919487361024000, which is a positive integer. Note that this number does not fit even into a 64-bit signed integer data type!

*/
// END CUT HERE
#line 81 "EasyHomework.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class EasyHomework {
	public:
	string determineSign(vector <int> A) {
		int ans=1;
		FOR(e, A) ans*=min(1, max(-1, *e));
		const char* msg[] = {"NEGATIVE", "ZERO", "POSITIVE"};
		return msg[ans+1];
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//mplate<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// os << "{ ";
// for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
// os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const string& Expected, const string& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, EasyHomework().determineSign(A));}
int main(){

CASE(0)
	int A_[] = {5, 7, 2};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string _ = "POSITIVE"; 
END
CASE(1)
	int A_[] = {-5, 7, 2};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string _ = "NEGATIVE"; 
END
CASE(2)
	int A_[] = {5, 7, 2, 0};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string _ = "ZERO"; 
END
CASE(3)
	int A_[] = {3, -14, 159, -26};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string _ = "POSITIVE"; 
END
CASE(4)
	int A_[] = {-1000000000};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string _ = "NEGATIVE"; 
END
CASE(5)
	int A_[] = {123, -456, 789, -101112, 131415, 161718, 192021, 222324, 252627, 282930, 313233, 343536, 373839, 404142, 434445, 464748, 495051, 525354, 555657};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string _ = "POSITIVE"; 
END

}
// END CUT HERE
