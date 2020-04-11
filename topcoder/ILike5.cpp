// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
You have certainly seen many tasks that start with some ridiculous made-up story. 
Well, this one is nothing like that.



Ivan A. is a smart boy.
He just got a sequence of nonnegative integers as a birthday present.
You are given this sequence in the vector <int> X.



Ivan A. adores the number 5.
He thinks that a sequence is pretty if the product of all its elements ends with the digit 5.
He now wants to change X into a pretty sequence.
In each step he can choose an element of X and replace one of its digits by any other digit.
For example, in a single step Ivan A. can change the number 1234 into the number 1734.



Compute and return the minimal number of steps needed to change X into a pretty sequence.


DEFINITION
Class:ILike5
Method:transformTheSequence
Parameters:vector <int>
Returns:int
Method signature:int transformTheSequence(vector <int> X)


NOTES
-It can be shown that any sequence X can be transformed into a pretty sequence in finitely many steps.
-It is allowed to change the leading digit of a number into a zero, but this is never needed in the optimal solution.


CONSTRAINTS
-X will contain between 1 and 50 numbers, inclusive.
-Each element of X will be between 0 and 10^6, inclusive.


EXAMPLES

0)
{5, 2, 8, 12}

Returns: 3

One optimal solution looks as follows:

Ivan A. changes the 2 to a 1.
Ivan A. changes the 8 to a 9.
Ivan A. changes the last digit of the number 12 from 2 to 9.

After these three steps he will have the sequence {5, 1, 9, 19}.
The product of its elements is 5 * 1 * 9 * 19 = 855, so this sequence is pretty.

1)
{1555}

Returns: 0

The number already ends in a 5.

2)
{0, 10, 100, 1000, 10000}

Returns: 5

Clearly, Ivan A. must change the last digit in each of these numbers, otherwise the product would end in a 0.
One optimal solution is to change this sequence into {7, 13, 105, 1005, 10003}.

3)
{1, 2, 2, 3, 3, 3, 4, 4, 4, 4}

Returns: 6



4)
{7890, 4861, 65773, 3769, 4638, 46000, 548254, 36185, 115}

Returns: 4



*/
// END CUT HERE
#line 93 "ILike5.cpp"

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
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
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
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class ILike5 {
	public:
	int transformTheSequence(vector <int> X) {
		int N = X.size();
		int ans = 0;
		int c5 = 0;
		REP(i, N) {
			if(X[i]%2==0) ans++;
			if(X[i]%5==0) c5++;
		}
		DD(ans);
		DD(c5);
		if(!c5 && ans==0) ans++;
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, ILike5().transformTheSequence(X));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int X_[] = {0,0};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int _ = 2; 
END

CASE(0)
	int X_[] = {5, 2, 8, 12};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int _ = 3; 
END
CASE(1)
	int X_[] = {1555};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int _ = 0; 
END
CASE(2)
	int X_[] = {0, 10, 100, 1000, 10000};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int _ = 5; 
END
CASE(3)
	int X_[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int _ = 6; 
END
CASE(4)
	int X_[] = {7890, 4861, 65773, 3769, 4638, 46000, 548254, 36185, 115};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int _ = 4; 
END
#if 0  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: int
	vector <int> X; 
	{
		int N=UNIFORM_LL(1, 51);
		X = vector <int>(N); 
		REP(i, N) {
			X[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = ILike5().transformTheSequence(X);
	int _1 = ILike5Ref().transformTheSequence(X);
	if(!verify_case(_0, _1, true)) {
print(X);
	}
}
#endif

}
// END CUT HERE
