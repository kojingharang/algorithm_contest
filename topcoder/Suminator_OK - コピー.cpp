// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Suminator is a very limited programming language.
A program in this language is simply a sequence of nonnegative integers.
The program is evaluated using a stack of nonnegative integers.
Initially, the stack is empty.
Trying to pop an element from an empty stack returns a zero.
(Alternately, you can imagine that the stack already contains a sufficient number of zeros in the beginning.)

A Suminator program is evaluated using the following algorithm:

for i = 0 to length(program) - 1 {
    if ( program[i] is 0) {
         Pop the top two elements from the stack, add them together
         and push the result to the top of the stack.
    } else {
         Push program[i] to the top of the stack.
    }
}
Pop the top element of the stack and print it.

For example, when executing the program {1}, we first push the 1 to the stack, and then we print it. 
When executing the program {5,0,1,2,0}, we take the following steps:

We push the 5 to the top of the stack.
We pop the top two elements (5 and 0), add them together and push the result (5).
We push the 1 to the top of the stack.
We push the 2 to the top of the stack. At this moment, the stack contains the values 5, 1, and 2 (from bottom to top).
We pop the top two elements (2 and 1), add them together and push the result (3).
We print the top element of the stack: the number 3. Note that the stack also contains the value 5, which is ignored.


You are given a vector <int> program containing a Suminator program (a sequence of nonnegative integers), in which one of the elements of the sequence was changed to -1.
You are also given a int wantedResult.
Your task is to change the -1 back to a nonnegative integer X in such a way that the resulting program prints the number wantedResult.
Return X.
If there are multiple possible values of X, return the smallest one.
If there is no way to make the program print wantedResult, return -1 instead.

DEFINITION
Class:Suminator
Method:findMissing
Parameters:vector <int>, int
Returns:int
Method signature:int findMissing(vector <int> program, int wantedResult)


NOTES
-The return value always fits into an int. This follows from the constraints and the nature of the problem.


CONSTRAINTS
-program will contain between 1 and 50 elements, inclusive.
-Each element of program will be between -1 and 1000000000 (10^9), inclusive.
-program will contain -1 exactly once.
-wantedResult will be between 1 and 1000000000 (10^9), inclusive.


EXAMPLES

0)
{7,-1,0}
10

Returns: 3



1)
{100, 200, 300, 0, 100, -1}
600

Returns: 0



2)
{-1, 7, 3, 0, 1, 2, 0, 0}
13

Returns: 0

We can replace the first element with many other values, but 0 is the smallest that achieves the wanted result.

3)
{-1, 8, 4, 0, 1, 2, 0, 0}
16

Returns: -1

It does not matter what value we use in the first element of the array, the result will always be 15.

4)
{1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0}
1000000000

Returns: -1

It does not matter what we replace the -1 with, the result will be larger than 1000000000.

5)
{7, -1, 3, 0}
3

Returns: -1



*/
// END CUT HERE
#line 113 "Suminator.cpp"

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
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <iomanip>
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


ll f(vector<int> P, int X) {
	REP(i, P.size()) if(P[i]==-1) P[i]=X;
	deque<ll> q;
	REP(i, 100) q.push_back(0);
	
	REP(i, P.size()) {
		if(P[i]==0) {
			ll a=q.back();q.pop_back();
			ll b=q.back();q.pop_back();
			q.PB(a+b);
		} else {
			q.PB(P[i]);
		}
	}
	return q.back();
}

class Suminator {
	public:
	int findMissing(vector <int> P, int WR) {
		cout<<P<<endl;
		if(WR==f(P, 0)) return 0;
		//return -1;
		ll lo=1, hi=INT_MAX;
		int cnt=0;
		while(lo<hi) {
			ll mid=(lo+hi)/2;
			ll R = f(P, mid);
			if(WR==R) return mid;
			if(WR<R) hi=mid; else lo=mid;
			//cout<<lo<<" "<<hi<<" "<<cnt<<" "<<mid<<endl;
			if(cnt++>1000) return -1;
		}
		return -1;
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
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, Suminator().findMissing(program, wantedResult));}
int main(){

CASE(0)
	int program_[] = {7,-1,0};
	  vector <int> program(program_, program_+sizeof(program_)/sizeof(*program_)); 
	int wantedResult = 10; 
	int _ = 3; 
END
CASE(1)
	int program_[] = {100, 200, 300, 0, 100, -1};
	  vector <int> program(program_, program_+sizeof(program_)/sizeof(*program_)); 
	int wantedResult = 600; 
	int _ = 0; 
END
CASE(2)
	int program_[] = {-1, 7, 3, 0, 1, 2, 0, 0};
	  vector <int> program(program_, program_+sizeof(program_)/sizeof(*program_)); 
	int wantedResult = 13; 
	int _ = 0; 
END
CASE(3)
	int program_[] = {-1, 8, 4, 0, 1, 2, 0, 0};
	  vector <int> program(program_, program_+sizeof(program_)/sizeof(*program_)); 
	int wantedResult = 16; 
	int _ = -1; 
END
CASE(4)
	int program_[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0};
	  vector <int> program(program_, program_+sizeof(program_)/sizeof(*program_)); 
	int wantedResult = 1000000000; 
	int _ = -1; 
END
CASE(5)
	int program_[] = {7, -1, 3, 0};
	  vector <int> program(program_, program_+sizeof(program_)/sizeof(*program_)); 
	int wantedResult = 3; 
	int _ = -1; 
END
CASE(0)
	int program_[] = {100, 0, -1, 0};
	  vector <int> program(program_, program_+sizeof(program_)/sizeof(*program_)); 
	int wantedResult = 10; 
	int _ = 3; 
END

}
// END CUT HERE
