// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel lives in a beautiful countryside.
She loves climbing mountains.
Yesterday, she went hiking in the mountains.



Her trip can be described as a sequence of (n+1) integers: h[0], h[1], ..., h[n]. 
These values represent altitudes visited by Fox Ciel during the trip, in order.
Fox Ciel does not remember the precise sequence, but she remembers the following:

for each i, h[i] >= 0
h[0] = h0
h[n] = hn
for each i, abs(h[i+1]-h[i]) = 1




The last condition means that in each step the altitude of Fox Ciel either increased by 1, or decreased by 1.
We will call the two types of steps "steps up" and "steps down", respectively.
Steps up will be denoted 'U' and steps down will be denoted 'D'.



You are given the ints n, h0, and hn: the length of the trip, the altitude at the beginning, and the altitude at the end.
In addition to these, Fox Ciel remembers some contiguous segment of her trip.
You are given this segment as a string history.
Each character of history is either 'U' or 'D'.



Check whether there is a valid trip that matches everything Fox Ciel remembers.
Return "YES" (quotes for clarity) if there is at least one such trip, or "NO" if there is none.

DEFINITION
Class:FoxAndMountainEasy
Method:possible
Parameters:int, int, int, string
Returns:string
Method signature:string possible(int n, int h0, int hn, string history)


CONSTRAINTS
-n will be between 1 and 100,000, inclusive.
-history will contain between 1 and min(50,n) characters, inclusive.
-Each character in history will be either 'U' or 'D'.
-h0 will be between 0 and 100,000, inclusive.
-hn will be between 0 and 100,000, inclusive.


EXAMPLES

0)
4
0
4
"UU"

Returns: "YES"

The only solution is: h[] = {0, 1, 2, 3, 4}, the history of the entire trip will be "UUUU".

1)
4
0
4
"D"

Returns: "NO"

Based on n, h0 and hn, the history of the entire trip must be "UUUU". There is no 'D' in this history.

2)
4
100000
100000
"DDU"

Returns: "YES"

We have the following solution: h[] = {100000, 100001, 100000, 99999, 100000}, the history of the entire trip is "UDDU".

3)
4
0
0
"DDU"

Returns: "NO"



4)
20
20
20
"UDUDUDUDUD"

Returns: "YES"



5)
20
0
0
"UUUUUUUUUU"

Returns: "YES"



6)
20
0
0
"UUUUUUUUUUU"

Returns: "NO"



*/
// END CUT HERE
#line 129 "FoxAndMountainEasy.cpp"

#include <vector>
#include <map>
#include <set>
#include <stack>
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
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class FoxAndMountainEasy {
	public:
	string possible(int n, int h0, int hn, string HI) {
		if(abs(h0-hn)>n) return "NO";
		if( (n-abs(h0-hn))%2 != 0 ) return "NO";
		int U=0, D=0, UD=0;
		if(h0<hn) U=abs(h0-hn);
		else      D=abs(h0-hn);
		UD = n-abs(h0-hn);
		U += UD/2;
		D += UD/2;
		int u=count(ALL(HI), 'U');
		int d=count(ALL(HI), 'D');
		if(U<u || D<d) return "NO";
		int Min=0;
		int pos=0;
		FOR(e, HI) {
			if(*e=='D') pos--;
			if(*e=='U') pos++;
			Min = min(Min, pos);
		}
		//if(abs(Min) > max(h0, hn)) return "NO";
		//if(abs(Min) > max(h0, hn-(int)HI.size())+U-u) return "NO";
		if(abs(Min) > h0+U-u) return "NO";
		return "YES";
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
#define END	 verify_case(_, FoxAndMountainEasy().possible(n, h0, hn, history));}
int main(){

CASE(0)
	int n = 4; 
	int h0 = 0; 
	int hn = 4; 
	string history = "UU"; 
	string _ = "YES"; 
END
CASE(1)
	int n = 4; 
	int h0 = 0; 
	int hn = 4; 
	string history = "D"; 
	string _ = "NO"; 
END
CASE(2)
	int n = 4; 
	int h0 = 100000; 
	int hn = 100000; 
	string history = "DDU"; 
	string _ = "YES"; 
END
CASE(3)
	int n = 4; 
	int h0 = 0; 
	int hn = 0; 
	string history = "DDU"; 
	string _ = "NO"; 
END
CASE(4)
	int n = 20; 
	int h0 = 20; 
	int hn = 20; 
	string history = "UDUDUDUDUD"; 
	string _ = "YES"; 
END
CASE(5)
	int n = 20; 
	int h0 = 0; 
	int hn = 0; 
	string history = "UUUUUUUUUU"; 
	string _ = "YES"; 
END
CASE(6)
	int n = 20; 
	int h0 = 0; 
	int hn = 0; 
	string history = "UUUUUUUUUUU"; 
	string _ = "NO"; 
END
CASE(6)
	int n = 67994; 
	int h0 = 2675; 
	int hn = 645; 
	string history = "DDDDDDDUUDUUDDDUDDDDDDDDDDDDDDDDUDDDDD"; 
	string _ = "YES"; 
END
CASE(6)
	int n = 3; 
	int h0 = 0; 
	int hn = 1; 
	string history = "DUU"; 
	string _ = "NO"; 
END
}
// END CUT HERE
