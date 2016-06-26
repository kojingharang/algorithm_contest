// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Warning: This problem statement contains superscripts and/or subscripts. It may not display properly outside of the applet.

King Dengklek is the perfect king of Kingdom of Ducks, where slimes and ducks live together in peace and harmony.

The palace has N rooms, conveniently numbered 0 through N-1. The rooms are occupied by the ducks King Dengklek loves the most. There are ducks[i] ducks in room i.

Today, King Dengklek realized that two magic spells are affecting the palace. Being a perfect king, he quickly learned that on each day, exactly one of the two magic spells will take place with the same probability (i.e., 50%). The effects of the two magic spells are as follows:

Spell 1: For each i, let D be the number of ducks in room i right before the spell's effect takes place. The number of ducks in room i will become D XOR spellOne[i] (see the Notes section for the definition of XOR).
Spell 2: For each i, all ducks in room i will move to room spellTwo[i]. All these movements will happen simultaneously. This will permute the ducks (i.e., no two elements of spellTwo will be equal).


King Dengklek is worried about these odd magic spells. He is especially worried about room 0, because he has promised that he will grant all ducks in this room to his successor. You are given the vector <int>s ducks, spellOne, spellTwo, and the int K. Return the expected number of ducks in room 0 after the magic spells have affected the palace for K days.

DEFINITION
Class:KingXMagicSpells
Method:expectedNumber
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:double
Method signature:double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K)


NOTES
-The returned value must have an absolute or relative error less than 10-9.
-If a and b are single bits then a XOR b is defined as (a + b) modulo 2. For two integers, A and B, in order to calculate A XOR B, they need to be represented in binary: A = (an...a1)2, B = (bn...b1)2 (if the lengths of their representations are different, the shorter one is prepended with the necessary number of leading zeroes). Then A XOR B = C = (cn...c1)2, where ci = ai XOR bi. For example, 10 XOR 3 = (1010)2 XOR (0011)2 = (1001)2 = 9.


CONSTRAINTS
-ducks, spellOne, and spellTwo will contain the same number of elements, between 1 and 50, inclusive.
-Each element of ducks will be between 0 and 1,000,000,000, inclusive.
-Each element of spellOne will be between 0 and 1,000,000,000, inclusive.
-Each element of spellTwo will be between 0 and N-1, inclusive, where N is the number of elements in ducks.
-All elements of spellTwo will be distinct.
-K will be between 1 and 50, inclusive.


EXAMPLES

0)
{5, 3, 7}
{1, 7, 4}
{1, 0, 2}
1

Returns: 3.5

We want to know the expected number of ducks in room 0 after K=1 day. Exactly one spell will take place. Depending on which spell takes place, there are two possible outcomes:

Spell 1: The numbers of ducks in the rooms become {5 XOR 1, 3 XOR 7, 7 XOR 4} = {4, 4, 3}.
Spell 2: The numbers of ducks in the rooms become {3, 5, 7}.

Therefore, the expected number of ducks in room 0 is (4 + 3)/2 = 3.5.

1)
{5, 8}
{53, 7}
{1, 0}
2

Returns: 21.5

There are four possible outcomes, depending on which two spells take place:

Spell 1 and then spell 1: {48, 15} and then {5, 8}.
Spell 1 and then spell 2: {48, 15} and then {15, 48}.
Spell 2 and then spell 1: {8, 5} and then {61, 2}.
Spell 2 and then spell 2: {8, 5} and then {5, 8}.

Therefore, the expected number of ducks in room 0 is (5 + 15 + 61 + 5)/4 = 21.5.

2)
{123, 456, 789, 1234, 56789}
{0, 0, 0, 0, 0}
{0, 1, 2, 3, 4}
50

Returns: 123.0

In this case, the number of ducks in each room will never change.

3)
{83291232, 3124231, 192412, 3813249, 629231, 9998989}
{58, 37, 44, 66, 72, 19}
{2, 0, 1, 5, 4, 3}
11

Returns: 2.888186784716797E7



*/
// END CUT HERE
#line 97 "KingXMagicSpells.cpp"

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



class KingXMagicSpells {
	public:
	double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
 { os << "{ ";
   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const double& Expected, const double& Received) {
 double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, KingXMagicSpells().expectedNumber(ducks, spellOne, spellTwo, K));}
int main(){

CASE(0)
	int ducks_[] = {5, 3, 7};
	  vector <int> ducks(ducks_, ducks_+sizeof(ducks_)/sizeof(*ducks_)); 
	int spellOne_[] = {1, 7, 4};
	  vector <int> spellOne(spellOne_, spellOne_+sizeof(spellOne_)/sizeof(*spellOne_)); 
	int spellTwo_[] = {1, 0, 2};
	  vector <int> spellTwo(spellTwo_, spellTwo_+sizeof(spellTwo_)/sizeof(*spellTwo_)); 
	int K = 1; 
	double _ = 3.5; 
END
CASE(1)
	int ducks_[] = {5, 8};
	  vector <int> ducks(ducks_, ducks_+sizeof(ducks_)/sizeof(*ducks_)); 
	int spellOne_[] = {53, 7};
	  vector <int> spellOne(spellOne_, spellOne_+sizeof(spellOne_)/sizeof(*spellOne_)); 
	int spellTwo_[] = {1, 0};
	  vector <int> spellTwo(spellTwo_, spellTwo_+sizeof(spellTwo_)/sizeof(*spellTwo_)); 
	int K = 2; 
	double _ = 21.5; 
END
CASE(2)
	int ducks_[] = {123, 456, 789, 1234, 56789};
	  vector <int> ducks(ducks_, ducks_+sizeof(ducks_)/sizeof(*ducks_)); 
	int spellOne_[] = {0, 0, 0, 0, 0};
	  vector <int> spellOne(spellOne_, spellOne_+sizeof(spellOne_)/sizeof(*spellOne_)); 
	int spellTwo_[] = {0, 1, 2, 3, 4};
	  vector <int> spellTwo(spellTwo_, spellTwo_+sizeof(spellTwo_)/sizeof(*spellTwo_)); 
	int K = 50; 
	double _ = 123.0; 
END
CASE(3)
	int ducks_[] = {83291232, 3124231, 192412, 3813249, 629231, 9998989};
	  vector <int> ducks(ducks_, ducks_+sizeof(ducks_)/sizeof(*ducks_)); 
	int spellOne_[] = {58, 37, 44, 66, 72, 19};
	  vector <int> spellOne(spellOne_, spellOne_+sizeof(spellOne_)/sizeof(*spellOne_)); 
	int spellTwo_[] = {2, 0, 1, 5, 4, 3};
	  vector <int> spellTwo(spellTwo_, spellTwo_+sizeof(spellTwo_)/sizeof(*spellTwo_)); 
	int K = 11; 
	double _ = 2.888186784716797E7; 
END

}
// END CUT HERE
