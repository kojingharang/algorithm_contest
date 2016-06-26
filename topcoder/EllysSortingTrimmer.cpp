// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Elly has a string S of uppercase letters and a magic device that can modify the string. The strength of the device is an int L.

The device is used in the following way. The user enters a 0-based index i such that 0 <= i <= length(S)-L. The device then performs the following changes:

It leaves the first i characters (i.e., characters with indices 0 through i-1) untouched.
It rearranges the next L characters (i.e., characters with indices i through i+L-1) into alphabetical order.
It erases all the remaining characters (i.e., characters with indices i+L and more). Note that for i=length(S)-L no characters are erased.

The girl can use this "sorting trimmer" as many times as she likes. After each use she is left with the new version of the string.

In the examples below we use brackets to highlight the region that shall be sorted. For example, "ABRA[CADAB]RA" means that L=5 and Elly chose i=4. The device keeps the letters in front of the brackets, sorts the letters in the brackets, and throws away the rest.

Here is one way how Elly could have used a device with L = 5, starting with the string S = "ABRACADABRA":

"ABRAC[ADABR]A" -> "ABRACAABDR"
"ABR[ACAAB]DR" -> "ABRAAABC"
"A[BRAAA]BC" -> "AAAABR"


You are given the string S and the int L. Return the lexicographically smallest string Elly can obtain.

DEFINITION
Class:EllysSortingTrimmer
Method:getMin
Parameters:string, int
Returns:string
Method signature:string getMin(string S, int L)


NOTES
-A string A is lexicographically smaller than string B if A contains a smaller character in the first position where they differ. In case one of the strings ends before they have a different character, the shorter one is considered smaller.


CONSTRAINTS
-S will contain between 2 and 50 characters, inclusive.
-L will be between 2 and |S|, inclusive, where |S| denotes the number of characters in S.
-S will consist of uppercase characters of the English alphabet, only ('A'-'Z').


EXAMPLES

0)
"ABRACADABRA"
5

Returns: "AAAAA"

Please note that the example in the problem statement does not obtain the lexicographically smallest string. In fact, it is optimal to start by using the device on the last five characters of the string, transforming it from ABRACA[DABRA] to ABRACAAABDR.

1)
"ESPRIT"
3

Returns: "EIP"

We can obtain the answer in the following steps:

ES[PRI]T -> ESIPR
E[SIP]R -> EIPS
[EIP]S -> EIP
 

2)
"BAZINGA"
7

Returns: "AABGINZ"

We can use the sorting trimmer on the entire word.

3)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
13

Returns: "ABCDEFGHIJKLM"

Even though the string is already sorted, shorter strings are considered lexicographically smaller, so we can use the device once to make the string as short as possible.

4)
"GOODLUCKANDHAVEFUN"
10

Returns: "AACDDEFGHK"



5)
"AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"
21

Returns: "AAAAAAAAABBDDDDDDDEEI"



6)
"TOPCODER"
3

Returns: "CDT"



******************************/
// END CUT HERE
#line 109 "EllysSortingTrimmer.cpp"
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

class EllysSortingTrimmer {
	public:
	string getMin(string S, int L) {
		while(S.size()>L) {
			sort(S.begin()+(S.length()-L),S.end());
			S.erase(S.end()-1);
		}
		sort(ALL(S));
		return S;
	}
};

class EllysSortingTrimmerRef {
	public:
	string getMin(string S, int L) {
		vector<string> res;
		string s(S);
		for(int i=s.size()-L;i>=0;i--) {
			sort(&s[i], &s[i+L]);
			s = s.substr(0, i+L);
			res.PB(s);
		}
//		cout<<res<<endl;
		sort(ALL(res));
		return res[0];
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const string& Expected, const string& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, EllysSortingTrimmer().getMin(S, L));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string S = "ABRACADABRA"; 
	int L = 5; 
	string _ = "AAAAA"; 
END
CASE(1)
	string S = "ESPRIT"; 
	int L = 3; 
	string _ = "EIP"; 
END
CASE(2)
	string S = "BAZINGA"; 
	int L = 7; 
	string _ = "AABGINZ"; 
END
CASE(3)
	string S = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	int L = 13; 
	string _ = "ABCDEFGHIJKLM"; 
END
CASE(4)
	string S = "GOODLUCKANDHAVEFUN"; 
	int L = 10; 
	string _ = "AACDDEFGHK"; 
END
CASE(5)
	string S = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"; 
	int L = 21; 
	string _ = "AAAAAAAAABBDDDDDDDEEI"; 
END
CASE(6)
	string S = "TOPCODER"; 
	int L = 3; 
	string _ = "CDT"; 
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
for(int loop=0;loop<1000;loop++) {
// param type: String
//-S will contain between 2 and 50 characters, inclusive.
//-L will be between 2 and |S|, inclusive, where |S| denotes the number of characters in S.
//-S will consist of uppercase characters of the English alphabet, only ('A'-'Z').

	string S; 
	{
		int N=UNIFORM_LL(2, 51);
		S = string(N, ' '); 
		string tb = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		REP(i, N) {
			S[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
// param type: int
	int L = UNIFORM_LL(2, S.size()+1); 
	string _0 = EllysSortingTrimmer().getMin(S, L);
	string _1 = EllysSortingTrimmerRef().getMin(S, L);
	if(!verify_case(_0, _1, true)) {
print(S);
print(L);
	}
}
#endif

}
// END CUT HERE
