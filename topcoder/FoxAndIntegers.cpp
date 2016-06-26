// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Jiro and Eel Saburo are good friends. One day Jiro received a letter from Saburo. The letter contains four integers representing an encrypted message. Please help Jiro to decrypt the message.

You are given four ints: AminusB, BminusC, AplusB, and BplusC. Your task is to find three integers A, B, and C such that:

AminusB = A - B
BminusC = B - C
AplusB = A + B
BplusC = B + C

There is always at most one triplet of integers A, B, C that satisfies all four equalities.

If it exists, return a vector <int> with exactly three elements: { A, B, C }. If there are no such integers, return an empty vector <int> instead.


DEFINITION
Class:FoxAndIntegers
Method:get
Parameters:int, int, int, int
Returns:vector <int>
Method signature:vector <int> get(int AminusB, int BminusC, int AplusB, int BplusC)


CONSTRAINTS
-AminusB will be between -30 and 30, inclusive.
-BminusC will be between -30 and 30, inclusive.
-AplusB will be between -30 and 30, inclusive.
-BplusC will be between -30 and 30. inclusive.


EXAMPLES

0)
1
-2
3
4

Returns: {2, 1, 3 }

A - B = 2 - 1 = 1
B - C = 1 - 3 = -2
A + B = 2 + 1 = 3
B + C = 1 + 3 = 4

1)
0
0
5
5

Returns: { }

A = B = C = 2.5 satisfy all four equalities, but A, B, and C must all be integers.

2)
10
-23
-10
3

Returns: {0, -10, 13 }

A, B, and C may be negative or zero.

3)
-27
14
13
22

Returns: { }



4)
30
30
30
-30

Returns: {30, 0, -30 }



*/
// END CUT HERE
#line 91 "FoxAndIntegers.cpp"

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



class FoxAndIntegers {
	public:
	vector <int> get(int AminusB, int BminusC, int AplusB, int BplusC) {
		//if((AminusB+AplusB)%2==1) return VI();
		//if((BminusC+BplusC)%2==1) return VI();
		int A=(AminusB + AplusB)/2;
		int B=AplusB-A;
		int C=BplusC-B;
		VI ans;
		ans.PB(A);
		ans.PB(B);
		ans.PB(C);
		if(A-B!=AminusB) return VI();
		if(A+B!=AplusB) return VI();
		if(B-C!=BminusC) return VI();
		if(B+C!=BplusC) return VI();
		return ans;
	}
	vector <int> get2(int AminusB, int BminusC, int AplusB, int BplusC) {
		//if((AminusB+AplusB)%2==1) return VI();
		//if((BminusC+BplusC)%2==1) return VI();
		int A=(AminusB + AplusB)/2;
		int B=(BplusC+BplusC)/2;
		int C=BplusC-B;
		VI ans;
		if(A+B!=AplusB) return ans;
		ans.PB(A);
		ans.PB(B);
		ans.PB(C);
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// { os << "{ ";
//   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
//   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const vector <int>& Expected, const vector <int>& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, FoxAndIntegers().get(AminusB, BminusC, AplusB, BplusC));}
int main(){

CASE(0)
	int AminusB = 1; 
	int BminusC = -2; 
	int AplusB = 3; 
	int BplusC = 4; 
	int __[] = {2, 1, 3 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	int AminusB = 0; 
	int BminusC = 0; 
	int AplusB = 5; 
	int BplusC = 5; 
	vector <int> _; 
END
CASE(2)
	int AminusB = 10; 
	int BminusC = -23; 
	int AplusB = -10; 
	int BplusC = 3; 
	int __[] = {0, -10, 13 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	int AminusB = -27; 
	int BminusC = 14; 
	int AplusB = 13; 
	int BplusC = 22; 
	vector <int> _; 
END
CASE(4)
	int AminusB = 30; 
	int BminusC = 30; 
	int AplusB = 30; 
	int BplusC = -30; 
	int __[] = {30, 0, -30 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	int AminusB = 0; 
	int BminusC = 0; 
	int AplusB = 0; 
	int BplusC = 0; 
	vector <int> _; 
END

for(int a=-30;a<=30;a++)
for(int b=-30;b<=30;b++)
for(int d=-30;d<=30;d++)
for(int c=-30;c<=30;c++) {
	if(FoxAndIntegers().get(a,b,c,d)!=FoxAndIntegers().get2(a,b,c,d)) {
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		cout<<"REF "<<FoxAndIntegers().get(a,b,c,d)<<endl;
		cout<<"TES "<<FoxAndIntegers().get2(a,b,c,d)<<endl;
		return 0;
	}
}

}
// END CUT HERE
