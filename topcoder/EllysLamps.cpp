// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Elly has a row of N lamps, conveniently numbered from 0 to N-1. Some of them are initially lit and the rest are not. She can control the lamps using a controller. On the controller there is a row of N buttons. Clicking the button with index i changes the state of lamp i: it goes off, if it was on, and it goes on if it was off.

Unfortunately the controller has some defects. Each of the buttons correctly changes the state of the corresponding lamp. However, it is possible that some of the buttons also change the state of one or both adjacent lamps as well. This means that pressing the button with index i has the following effects:

The state of lamp i changes.
If there is a lamp with index i-1, its state might change.
If there is a lamp with index i+1, its state might change.

The girl does not initially know which lamps change their state when each of the buttons is pressed. She knows, however, that every time she clicks a particular button, the same set of lamps will change their states.

Elly wants to reach a configuration in which the number of lamps that are turned on is minimized. Help her determine how many of them will remain lit in the worst possible case. (That is, for the worst possible way how the buttons change the state of the lamps.) She can use each of the buttons as many times as she likes, in any order she likes.

You will be given a string lamps, which gives information about the initial state of the lamps. The i-th character of lamps will be 'Y' if the i-th lamp is lit, and 'N', if it is not. Return the minimal number of lit lamps the girl can get in the worst possible case.

DEFINITION
Class:EllysLamps
Method:getMin
Parameters:string
Returns:int
Method signature:int getMin(string lamps)


NOTES
-The defects in the switches might not be symmetric. This means that if a lamp with index i happens to change the state of lamp i+1, this does not necessarily mean that the using the switch of lamp i+1 changes the state of lamp i.


CONSTRAINTS
-lamps will contain between 1 and 50 elements, inclusive.
-Each element of lamps will be either 'Y' or 'N'.


EXAMPLES

0)
"YNNYN"

Returns: 2

In this case Elly will only make things worse (or the same) by pressing buttons. For example, suppose that:

buttons 0 and 1 each change the state of both lamps 0 and 1
buttons 2 and 3 each change the state of both lamps 2 and 3
button 4 only changes the state of lamp 4

In this situation, Elly cannot reach any configuration with fewer than two lit lamps.

1)
"NNN"

Returns: 0

Obviously, with no initially lit lamps, Elly can just sit and relax.

2)
"YY"

Returns: 0

If one of the lamps influences the other one, then Elly can use it and turn both off with one button press. Otherwise, each button changes the state of its lamp only, thus Elly can turn them both off by pressing both buttons.

3)
"YNYYYNNNY"

Returns: 3


YN YY YN N NY


4)
"YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY"

Returns: 13



YN YYY YN YN NY YN NNNNN YN YN YN YN NY NY YY NY


******************************/
// END CUT HERE
#line 81 "EllysLamps.cpp"
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class EllysLamps {
	public:
	int getMin(string S) {
		int ans=0;
		REP(i, S.size()) {
			int rest=S.size()-i;
//			cout<<S.substr(i,rest)<<endl;
			if(rest>1 && S.substr(i,2)=="YN") {ans++;i++;}
			else if(rest>1 && S.substr(i,2)=="NY") {ans++;i++;}
			else if(rest>2 && S.substr(i,3)=="YYY") {ans++;i+=2;}
		}
		cout<<"ore "<<ans<<endl;
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
#define END	 verify_case(_, EllysLamps().getMin(lamps));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string lamps = "YYY"; 
	int _ = 1; 
END
CASE(0)
	string lamps = "YNNYN"; 
	int _ = 2; 
END
CASE(1)
	string lamps = "NNN"; 
	int _ = 0; 
END
CASE(2)
	string lamps = "YY"; 
	int _ = 0; 
END
CASE(3)
	string lamps = "YNYYYNNNY"; 
	int _ = 3; 
END
CASE(4)
	string lamps = "YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY"; 
	int _ = 13; 
END
#if 01  // DO RANDOM TESTS

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
	string lamps; 
	{
		int N=UNIFORM_LL(1, 5);
		lamps = string(N, ' '); 
		string tb = "YN";
		REP(i, N) {
			lamps[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	int _0 = EllysLamps().getMin(lamps);
	int _1 = EllysLampsRef().getMin(lamps);
	if(!verify_case(_0, _1, true)) {
print(lamps);
	}
}
#endif

}
// END CUT HERE
