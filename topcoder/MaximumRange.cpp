// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Cat Noku was given a calculator for his birthday.
The calculator is very simple.
It can only store a single variable.
The variable is called X and its initial value is 0.
The calculator has only two buttons: + and -.
Pressing + increments X by 1 and pressing - decrements X by 1.
For example, if X is 4 and Noku presses +, X is incremented to 5.



A string of '+' and '-' characters can be seen as a sequence of instructions to press the corresponding buttons.
The range of such a sequence of instructions is the difference between the largest and the smallest value stored in X while executing that sequence of instructions, in order.



For example, the range of "+++++++" is 7: the largest value of X is 7 (at the end) and the smallest value is 0 (in the beginning).
The range of "---" is 3: maximum is 0, minimum is (-3), their difference is 0 - (-3) = 3.
The range of "+-+-+-" is 1.
The range of an empty sequence of instructions is 0.



Noku's calculator came with a piece of paper that contained a string s.
Each character of s was either '+' or '-'.
Noku will choose and execute any (not necessarily contiguous) subsequence of these characters.
Help him do so in a way that maximizes the range of the executed sequence.



Compute and return the maximal range of a subsequence of the string s.


DEFINITION
Class:MaximumRange
Method:findMax
Parameters:string
Returns:int
Method signature:int findMax(string s)


CONSTRAINTS
-s will contain between 1 and 2,500 characters, inclusive.
-Each element of s will be '+' or '-'.


EXAMPLES

0)
"+++++++"

Returns: 7

Cat Noku should choose the entire string s.
As we saw in the problem statement, the range of "+++++++" is 7, and clearly this is the most we can get.

1)
"+--+--+"

Returns: 4

One optimal solution is to skip the fourth instruction (the '+' in the middle of s).
Thus, the sequence of button presses will be "+----+".
The value of X will change as follows: 0,1,0,-1,-2,-3,-2.
The maximum number we see is 1 while the minimum number is -3, so the range is 1 - (-3) = 4.

2)
"++++--------"

Returns: 8



3)
"-+-+-+-+-+-+"

Returns: 6



4)
"+"

Returns: 1



*/
// END CUT HERE
#line 94 "MaximumRange.cpp"

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

int f(string s) {
	ll p=0, m=0;
	REP(i, s.size()) if(s[i]=='-') m++; else p++;
	return max(m, p);
}

int naive(string s) {
	int N = s.size();
	ll ans = 0;
	REP(bits, 1<<N) {
		string ss;
		REP(i, N) if((bits>>i)&1) ss.PB(s[i]);
//		DD(ss);
		ll v = 0, Max=0, Min=0;
		REP(i, ss.size()) {
			v += ss[i]=='+' ? 1 : -1;
			Max=max(Max, v);
			Min=min(Min, v);
		}
//		DD(Max);DD(Min);
		ll lans = Max-Min;
		ans = max(ans, lans);
	}
//	DD(ans);
	return ans;
}



class MaximumRange {
	public:
	int findMax(string s) {
		return f(s);
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
#define END	 verify_case(_, MaximumRange().findMax(s));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

int N = 13;
REP(bits, 1<<N) {
	string s(N, '-');
	REP(i, N) if((bits>>i)&1) s[i]='+';
	ll ans = f(s);
	ll ref = naive(s);
//	DD(s);
//	DD(ans);
//	DD(ref);
	assert(ans==ref);
}

CASE(0)
	string s = "+++++++"; 
	int _ = 7; 
END
CASE(1)
	string s = "+--+--+"; 
	int _ = 4; 
END
CASE(2)
	string s = "++++--------"; 
	int _ = 8; 
END
CASE(3)
	string s = "-+-+-+-+-+-+"; 
	int _ = 6; 
END
CASE(4)
	string s = "+"; 
	int _ = 1; 
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
// param type: String
	string s; 
	{
		int N=UNIFORM_LL(1, 51);
		s = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			s[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	int _0 = MaximumRange().findMax(s);
	int _1 = MaximumRangeRef().findMax(s);
	if(!verify_case(_0, _1, true)) {
print(s);
	}
}
#endif

}
// END CUT HERE
