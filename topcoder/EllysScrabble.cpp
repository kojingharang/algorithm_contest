// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Elly is playing Scrabble with her family. The exact rules of the game are not important for this problem. You only need to know that Elly has a holder that contains a row of N tiles, and that there is a single letter on each of those tiles. (Tiles are small square pieces of wood. A holder is a tiny wooden shelf with room for precisely N tiles placed in a row.)

While Elly waits for the other players, she entertains herself in the following way. She slightly taps the table, causing the tiles on her holder jump a little and some of them switch places.
Formally, suppose that Elly has N tiles. There are N positions on the holder, we will label them 0 through N-1 from left to right.
When Elly taps the table, the tiles on her holder will form some permutation of their original order.
You are given an int maxDistance with the following meaning: in the permutation that Elly produces by tapping the table, no tile will be more than maxDistance positions away from its original position (in either direction).

For example, suppose that before a tap the letters in Elly's holder formed the string "TOPCODER" when read from left to right.
If maxDistance is 3, one possible string after Elly taps the table is "CODTEPOR".
This can happen in the following way:

The letter 'T' at position 0 moves three positions to the right (to position 3).
The letter 'O' at position 1 remains on its initial position (position 1).
The letter 'P' at position 2 moves three positions to the right (to position 5).
The letter 'C' at position 3 moves three positions to the left (to position 0).
The letter 'O' at position 4 moves two positions to the right (to position 6).
The letter 'D' at position 5 moves three positions to the left (to position 2).
The letter 'E' at position 6 moves two positions to the left (to position 4).
The letter 'R' at position 7 remains on its initial position (position 7).

Note that the letter 'D' (at position 5) cannot move to position 1, because this would require it to move more than the maximal distance 3.

It turns out that the string "CODTEPOR" is the lexicographically smallest one Elly can get from "TOPCODER" with a single tap and maxDistance = 3. Now you want to write a program that, given the string letters and the int maxDistance, returns the lexicographically smallest string the girl can get after a single tap.

DEFINITION
Class:EllysScrabble
Method:getMin
Parameters:string, int
Returns:string
Method signature:string getMin(string letters, int maxDistance)


NOTES
-Given two different strings A and B of equal length, the lexicographically smaller one is the one that contains a smaller character at the first position where they differ.


CONSTRAINTS
-letters will contain between 1 and 50 characters, inclusive.
-letters will contain only uppercase letters from the English alphabet ('A'-'Z').
-maxDistance will be between 1 and 9, inclusive.


EXAMPLES

0)
"TOPCODER"
3

Returns: "CODTEPOR"

The example from the problem statement.

1)
"ESPRIT"
3

Returns: "EIPRST"

In this example the letters 'E', 'P', 'R', and 'T' stay on their initial places, and the letters 'S' and 'I' swap. Since the distance between them is exactly 3 (which also happens to be the maximal distance they can move), this is a valid final configuration.

2)
"BAZINGA"
8

Returns: "AABGINZ"

Note that the maximal distance may be greater than the number of letters Elly has. In such cases, the lexicographically smallest result is, obviously, the sorted sequence of letters.

3)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
9

Returns: "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

As the input letters are already sorted, we can assume they'll just fall back to their initial places.

4)
"GOODLUCKANDHAVEFUN"
7

Returns: "CADDGAHEOOFLUKNNUV"



5)
"AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"
6

Returns: "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW"



6)
"ABRACADABRA"
2

Returns: "AABARACBDAR"


The letter 'A' at position 0 remains on its initial place (position 0).
The letter 'B' at position 1 moves one position to the right (to position 2).
The letter 'R' at position 2 moves two positions to the right (to position 4).
The letter 'A' at position 3 moves two positions to the left (to position 1).
The letter 'C' at position 4 moves two positions to the right (to position 6).
The letter 'A' at position 5 moves two positions to the left (to position 3).
The letter 'D' at position 6 moves two positions to the right (to position 8).
The letter 'A' at position 7 moves two positions to the left (to position 5).
The letter 'B' at position 8 moves one position to the left (to position 7).
The letter 'R' at position 9 moves one position to the right (to position 10).
The letter 'A' at position 10 moves one position to the left (to position 9).


******************************/
// END CUT HERE
#line 119 "EllysScrabble.cpp"
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

/*
TCO Round1A ooo (pos 99/2425) 

*/
class EllysScrabble {
	public:
	string getMin(string S, int MD) {
		int N=S.size();
		string ans;
		REP(i, N) {
			string s;
			REP(j, N) if(abs(i-j)<=MD && S[j]!='.') s.PB(S[j]);
			sort(ALL(s));
			if(i-MD>=0 && S[i-MD]!='.') s[0]=S[i-MD];
			ans.PB(s[0]);
			REP(j, N) if(S[j]==s[0]) {S[j]='.';break;}
//			cout<<S<<endl;
		}
		return ans;
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
#define END	 verify_case(_, EllysScrabble().getMin(letters, maxDistance));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string letters = "TOPCODER"; 
	int maxDistance = 3; 
	string _ = "CODTEPOR"; 
END
CASE(1)
	string letters = "ESPRIT"; 
	int maxDistance = 3; 
	string _ = "EIPRST"; 
END
CASE(2)
	string letters = "BAZINGA"; 
	int maxDistance = 8; 
	string _ = "AABGINZ"; 
END
CASE(3)
	string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	int maxDistance = 9; 
	string _ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
END
CASE(4)
	string letters = "GOODLUCKANDHAVEFUN"; 
	int maxDistance = 7; 
	string _ = "CADDGAHEOOFLUKNNUV"; 
END
CASE(5)
	string letters = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"; 
	int maxDistance = 6; 
	string _ = "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW"; 
END
CASE(6)
	string letters = "ABRACADABRA"; 
	int maxDistance = 2; 
	string _ = "AABARACBDAR"; 
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
	string letters; 
	{
		int N=UNIFORM_LL(1, 51);
		letters = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			letters[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
// param type: int
	int maxDistance = UNIFORM_LL(0, 100); 
	string _0 = EllysScrabble().getMin(letters, maxDistance);
	string _1 = EllysScrabbleRef().getMin(letters, maxDistance);
	if(!verify_case(_0, _1, true)) {
print(letters);
print(maxDistance);
	}
}
#endif

}
// END CUT HERE
