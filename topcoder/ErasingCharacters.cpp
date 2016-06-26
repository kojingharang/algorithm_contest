// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Fox Ciel received a string as a birthday present. However, the string was too long for her, so she decided to make it shorter by erasing some characters.


The erasing process will look as follows:

Find the smallest i such that the i-th character and the (i+1)-th character of the string are same.
If there is no such i, end the process.
Remove the i-th and the (i+1)-th character of the string, and repeat from 1.



For example, if she receives "cieeilll", she will change the string as follows: "cieeilll" -> "ciilll" -> "clll" -> "cl". You are given a string s. Return the string she will get after she erases characters as described above.

DEFINITION
Class:ErasingCharacters
Method:simulate
Parameters:string
Returns:string
Method signature:string simulate(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"cieeilll"

Returns: "cl"

This is the example from the statement.

1)
"topcoder"

Returns: "topcoder"

She won't erase any characters at all.

2)
"abcdefghijklmnopqrstuvwxyyxwvutsrqponmlkjihgfedcba"

Returns: ""



3)
"bacaabaccbaaccabbcabbacabcbba"

Returns: "bacbaca"



4)
"eel"

Returns: "l"



******************************/
// END CUT HERE
#line 70 "ErasingCharacters.cpp"
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

class ErasingCharacters {
	public:
	string simulate(string s) {
		REP(l, 1000)REP(i, s.size()-1)if(s[i]==s[i+1]){s.erase(i,2);break;}
		return s;
	}
};

class ErasingCharactersTry {
	public:
	string simulate(string s) {
		REP(l, 1000)REP(i, s.size()-1)if(s[i]==s[i+1]){s.erase(i,2);break;}
		return s;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
void verify_case(const string& Expected, const string& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, ErasingCharacters().simulate(s));}
int main(){

CASE(0)
	string s = "cieeilll"; 
	string _ = "cl"; 
END
CASE(1)
	string s = "topcoder"; 
	string _ = "topcoder"; 
END
CASE(2)
	string s = "abcdefghijklmnopqrstuvwxyyxwvutsrqponmlkjihgfedcba"; 
	string _ = ""; 
END
CASE(3)
	string s = "bacaabaccbaaccabbcabbacabcbba"; 
	string _ = "bacbaca"; 
END
CASE(4)
	string s = "eel"; 
	string _ = "l"; 
END
#if 01  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10;loop++) {
// param type: String
	start_time=clock();
	string s; 
	{
		int N=UNIFORM_LL(1, 50);
		s = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			s[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	string _0 = ErasingCharacters().simulate(s);
	string _1 = ErasingCharactersTry().simulate(s);
	verify_case(_0, _1);
}
#endif

}
// END CUT HERE
