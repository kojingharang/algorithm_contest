// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Typically, telephone numbers are sequences of digits (0-9) that all have the same length.
However, some prefixes may be reserved for special purposes.
This limits the total number of possible full-length telephone numbers that are available for general use in the system.

As an example, in much of the United States and Canada the local telephone numbers are 7 digits long.
However, dialing 1 starts a special sequence for long distance, dialing 0 connects to the operator, and dialing 911 connects to emergency services.
Thus, there are fewer than the theoretical 10,000,000 possible valid telephone numbers.

You are given the int digits: the length of the standard telephone numbers in the system.
You are also given a vector <string> specialPrefixes.
Each element of specialPrefixes is a string of digits that defines one reserved prefix.
Standard telephone numbers cannot start with any of the reserved prefixes.

Compute and return the number of different standard telephone numbers in the system.


DEFINITION
Class:TCPhoneHome
Method:validNumbers
Parameters:int, vector <string>
Returns:long long
Method signature:long long validNumbers(int digits, vector <string> specialPrefixes)


CONSTRAINTS
-digits will be between 1 and 17, inclusive.
-specialPrefixes will contain beteween 0 and 50 elements, inclusive.
-The length of each element of specialPrefixes will be between 1 and digits, inclusive.
-Each character of each element of specialPrefixes will be a digit ('0'...'9').
-No two elements of specialPrefixes will be the same.


EXAMPLES

0)
7
{"0", "1", "911"}

Returns: 7990000

The example from the problem statement.

1)
10
{"0", "1", "911"}

Returns: 7990000000

Same prefixes, longer numbers.

2)
8
{"1", "12", "123"}

Returns: 90000000

The sets of numbers reserved by different special prefixes may sometimes overlap.
For example, in this case the net effect of these three special prefixes is that all numbers that start with "1" are reserved.

3)
9
{"12", "13", "14"}

Returns: 970000000



4)
3
{"411"}

Returns: 999

Sometimes a "prefix" is actually a full length phone number that is specially reserved for some reason.

*/
// END CUT HERE
#line 82 "TCPhoneHome.cpp"

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



class TCPhoneHome {
	public:
	long long validNumbers(int d, vector <string> s) {
		ll ans = 1;
		REP(i, d) ans *= 10;
		ll N = s.size();
		vector<string> us;
		REP(i, N) {
			bool ok = 1;
			REP(j, N) if(i!=j) {
				if(s[i].find(s[j])==0) ok=0;
			}
			if(ok) us.PB(s[i]);
		}
//		DD(s);
//		DD(us);
		REP(i, us.size()) {
			ans -= (ll)pow(10, d-us[i].size());
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const long long& Expected, const long long& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, TCPhoneHome().validNumbers(digits, specialPrefixes));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int digits = 17; 
	string specialPrefixes_[] = {"977392277598422", "591019474348328", "986196259", "20116488438", "60208574457", "855099650", "7462799575", "32699778416", "62198", "56350284687597285", "80919", "630199500528", "724051", "1929077807937696", "7462", "434357040499", "6110127025", "068523057459462", "8575480250623461", "53985263421116", "9394504", "5691", "812741823023", "10", "91332305257", "132", "0952937071", "26149455557", "50758471", "87315765436177801", "75779250127860", "64983369012138384", "605107065537"};
	  vector <string> specialPrefixes(specialPrefixes_, specialPrefixes_+sizeof(specialPrefixes_)/sizeof(*specialPrefixes_)); 
	long long _ = 98877888774597677LL; 
END

CASE(0)
	int digits = 1; 
	string specialPrefixes_[] = {"0", "1", "3"};
	  vector <string> specialPrefixes(specialPrefixes_, specialPrefixes_+sizeof(specialPrefixes_)/sizeof(*specialPrefixes_)); 
	long long _ = 7LL; 
END
CASE(0)
	int digits = 2; 
	string specialPrefixes_[] = {"0", "01", "13"};
	  vector <string> specialPrefixes(specialPrefixes_, specialPrefixes_+sizeof(specialPrefixes_)/sizeof(*specialPrefixes_)); 
	long long _ = 89LL; 
END
CASE(0)
	int digits = 3; 
	string specialPrefixes_[] = {"000", "012", "021"};
	  vector <string> specialPrefixes(specialPrefixes_, specialPrefixes_+sizeof(specialPrefixes_)/sizeof(*specialPrefixes_)); 
	long long _ = 997LL; 
END
CASE(0)
	int digits = 3; 
	string specialPrefixes_[] = {"000", "0", "111"};
	  vector <string> specialPrefixes(specialPrefixes_, specialPrefixes_+sizeof(specialPrefixes_)/sizeof(*specialPrefixes_)); 
	long long _ = 899LL; 
END


CASE(0)
	int digits = 7; 
	string specialPrefixes_[] = {"0", "1", "911"};
	  vector <string> specialPrefixes(specialPrefixes_, specialPrefixes_+sizeof(specialPrefixes_)/sizeof(*specialPrefixes_)); 
	long long _ = 7990000LL; 
END
CASE(1)
	int digits = 10; 
	string specialPrefixes_[] = {"0", "1", "911"};
	  vector <string> specialPrefixes(specialPrefixes_, specialPrefixes_+sizeof(specialPrefixes_)/sizeof(*specialPrefixes_)); 
	long long _ = 7990000000LL; 
END
CASE(2)
	int digits = 8; 
	string specialPrefixes_[] = {"1", "12", "123"};
	  vector <string> specialPrefixes(specialPrefixes_, specialPrefixes_+sizeof(specialPrefixes_)/sizeof(*specialPrefixes_)); 
	long long _ = 90000000LL; 
END
CASE(3)
	int digits = 9; 
	string specialPrefixes_[] = {"12", "13", "14"};
	  vector <string> specialPrefixes(specialPrefixes_, specialPrefixes_+sizeof(specialPrefixes_)/sizeof(*specialPrefixes_)); 
	long long _ = 970000000LL; 
END
CASE(4)
	int digits = 3; 
	string specialPrefixes_[] = {"411"};
	  vector <string> specialPrefixes(specialPrefixes_, specialPrefixes_+sizeof(specialPrefixes_)/sizeof(*specialPrefixes_)); 
	long long _ = 999LL; 
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
	int digits = UNIFORM_LL(0, 100); 
// param type: String
	vector <string> specialPrefixes; 
	{
		int N=UNIFORM_LL(1, 51);
		specialPrefixes = vector <string>(N); 
		REP(i, N) {
			specialPrefixes[i] = UNIFORM_LL(0, 1000);
		}
	}
	long long _0 = TCPhoneHome().validNumbers(digits, specialPrefixes);
	long long _1 = TCPhoneHomeRef().validNumbers(digits, specialPrefixes);
	if(!verify_case(_0, _1, true)) {
print(digits);
print(specialPrefixes);
	}
}
#endif

}
// END CUT HERE
