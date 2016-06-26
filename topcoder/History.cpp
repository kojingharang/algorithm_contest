// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There were N ancient nations.
We will denote them using uppercase letters from 'A' to 'A'+N-1.

All nations were using the same calendar: the new year always started on the same day in each nation.
However, each nation used its own numbering of years.
For example, the years 47, 48, and 49 of nation A could correspond to years 123, 124, and 125 of nation B.

Each nation had several monarchs over its history.
For each nation, the monarchs are numbered starting from 0, in chronological order.
For example, "C0" denotes the earliest ruling monarch of the nation 'C'.
Each monarch started his rule on the first day of some year.
For each monarch we know the exact years when they ruled, according to the corresponding nation's calendar.

Manao wants to determine how the calendars of those nations correspond to each other.
To do this, he collected information about various battles that have occurred throughout the history.
For each battle we know the two monarchs that were involved.
For example, "C0-D3" denotes a battle between the monarchs "C0" and "D3".
The information that this battle has occurred tells us that "C0" and "D3" had to rule in the same year.

Manao now has to answer a bunch of questions.
Each question is of the following form:
"Given all the known information, is it possible that there was a battle between monarchs Xn and Ym?"

You are given the above information encoded as three vector <string>s: dynasties, battles, and queries.

For each i, element i of dynasties contains information about all monarchs of the nation 'A'+i:
the year when each of them started ruling, and finally the first year after the last monarch died.
More precisely, dynasties[i] is a space-separated list of increasing integers: the years described above.
For example, if dynasties[0]="42 47 55 63", nation 'A' had three monarchs: "A0" ruled in years 42-46, "A1" ruled in years 47-54, and "A2" ruled in years 55-62. 

Concatenate the elements of battles to obtain a single string.
The string will represent a space-separated list of battles that are known to have occurred.
Each battle will be given in the above format.

Each element of queries is a single battle given in the same format.

Return a string of the same length as the number of elements in queries.
For each i, character i of this string should be 'Y' if the battle in queries[i] is possible, and 'N' otherwise.

DEFINITION
Class:History
Method:verifyClaims
Parameters:vector <string>, vector <string>, vector <string>
Returns:string
Method signature:string verifyClaims(vector <string> dynasties, vector <string> battles, vector <string> queries)


NOTES
-The Constraints guarantee that there will be at most 10 monarchs in each dynasty. Thus, the number of each monarch will be a single digit.
-Each query should be processed separately. In other words, if you answer 'Y' to some query, this should not be considered as new information for the remaining queries.


CONSTRAINTS
-dynasties will contain between 2 and 26 elements, inclusive.
-Each element of dynasties will be between 3 and 50 characters long, inclusive.
-Each element of dynasties will be a space-separated list containing between 2 and 11 integers, inclusive.
-Each integer in dynasties will be between 1 and 99999, inclusive.
-The sequence of integers in each element of dynasties will be strictly increasing.
-battles will contain between 1 and 50 elements, inclusive.
-Each element of battles will be between 1 and 50 characters long, inclusive.
-The string B obtained by concatenating the elements of battles will be a space-separated list of tokens.
-Each token in the string B will be of the form "Xn-Ym", where X and Y are two distinct uppercase letters that represent valid nations, and n and m are digits that represent valid monarchs of those nations.
-The information given in dynasties and battles will not be contradictory.
-queries will contain between 1 and 50 elements, inclusive.
-Each element of queries will be of the form "Xn-Ym", where X and Y are two distinct uppercase letters that represent valid nations, and n and m are digits that represent valid monarchs of those nations.


EXAMPLES

0)
{"1 2 4",
 "1 2 3"}
{"A1-B0"}
{"A0-B0",
 "A0-B1",
 "A1-B0",
 "A1-B1"}

Returns: "NNYY"

There are two nations. Both had two monarchs. Nation A's monarch 0 ruled in year 1 according to this nation's year numbering. Nation A's monarch 1 ruled in years 2 and 3. Nation B's monarch 0 ruled in year 1 and its monarch 1 ruled in year 2, according to nation B's year numbering.

Manao knows for sure that a battle between nation A's monarch 1 and nation B's monarch 0 occured. He is interested whether the following battles could take place:


A0-B0. Since monarchs A0 and B0 both ruled for 1 year only, the battle between them would mean that their rulings coincided. However, B0 battled A1, thus he had to rule later than A0.
A0-B1. We have already seen that monarch B0 ruled later than A0. Therefore monarch B1 ruled even later and could not battle with A0.
A1-B0. This battle is already provided in battles.
A1-B1. This battle could occur if nation A's year 2 coincides with nation B's year 1.


1)
{"1000 2000 3000 10000",
 "600 650 2000",
 "1 1001 20001"}
{"B1-C0 A0-B0 A2-C1 B1-C1"}
{"A0-B1",
 "A1-B1",
 "A2-B1",
 "C0-A0",
 "B0-A2",
 "C1-B0"}

Returns: "YYYYNN"

Some monarchs can rule for thousands of years.

2)
{"1 4 5",
 "10 13 17"}
{"A0-B0 A0-B0 B0-A0"}
{"A1-B0",
 "A0-B1",
 "A1-B1"}

Returns: "YYY"

Note that a battle between the same monarchs can occur multiple times. Also note that they all may occur during the same year.

3)
{"1 5 6",
 "1 2 5"}
{"A0",
 "-B0 A",
 "1-B1"}
{"A0-B0",
 "A1-B0",
 "A0-B1",
 "A1-B1"}

Returns: "YNYY"

Note that you need to concatenate the elements of battles before parsing the tokens.

4)
{"2294 7344","366 384 449 965 1307 1415","307 473 648 688 1097","1145 1411 1569 2606","87 188 551 598 947 998 1917 1942"}

{"A0-B4 B4-E2 B3-E2 D2-E4 A0-E4 B1-C3 A0-E3 A0-E6 D0","-E2 B2-E1 B4-E3 B4-D0 D0-E3 A0-D1 B2-C3 B1-C3 B4-E","3 D0-E1 B3-D0 B3-E2"}

{"A0-C2","E6-C2","A0-E4","B3-C1","C0-D2","B0-C1","D1-C3","C3-D0","C1-E3","D1-A0"}

Returns: "YNYNNYNNNY"



*/
// END CUT HERE
#line 152 "History.cpp"

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



class History {
	public:
	string verifyClaims(vector <string> dynasties, vector <string> battles, vector <string> queries) {
		
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
#define END	 verify_case(_, History().verifyClaims(dynasties, battles, queries));}
int main(){

CASE(0)
	string dynasties_[] = {"1 2 4",
 "1 2 3"};
	  vector <string> dynasties(dynasties_, dynasties_+sizeof(dynasties_)/sizeof(*dynasties_)); 
	string battles_[] = {"A1-B0"};
	  vector <string> battles(battles_, battles_+sizeof(battles_)/sizeof(*battles_)); 
	string queries_[] = {"A0-B0",
 "A0-B1",
 "A1-B0",
 "A1-B1"};
	  vector <string> queries(queries_, queries_+sizeof(queries_)/sizeof(*queries_)); 
	string _ = "NNYY"; 
END
CASE(1)
	string dynasties_[] = {"1000 2000 3000 10000",
 "600 650 2000",
 "1 1001 20001"};
	  vector <string> dynasties(dynasties_, dynasties_+sizeof(dynasties_)/sizeof(*dynasties_)); 
	string battles_[] = {"B1-C0 A0-B0 A2-C1 B1-C1"};
	  vector <string> battles(battles_, battles_+sizeof(battles_)/sizeof(*battles_)); 
	string queries_[] = {"A0-B1",
 "A1-B1",
 "A2-B1",
 "C0-A0",
 "B0-A2",
 "C1-B0"};
	  vector <string> queries(queries_, queries_+sizeof(queries_)/sizeof(*queries_)); 
	string _ = "YYYYNN"; 
END
CASE(2)
	string dynasties_[] = {"1 4 5",
 "10 13 17"};
	  vector <string> dynasties(dynasties_, dynasties_+sizeof(dynasties_)/sizeof(*dynasties_)); 
	string battles_[] = {"A0-B0 A0-B0 B0-A0"};
	  vector <string> battles(battles_, battles_+sizeof(battles_)/sizeof(*battles_)); 
	string queries_[] = {"A1-B0",
 "A0-B1",
 "A1-B1"};
	  vector <string> queries(queries_, queries_+sizeof(queries_)/sizeof(*queries_)); 
	string _ = "YYY"; 
END
CASE(3)
	string dynasties_[] = {"1 5 6",
 "1 2 5"};
	  vector <string> dynasties(dynasties_, dynasties_+sizeof(dynasties_)/sizeof(*dynasties_)); 
	string battles_[] = {"A0",
 "-B0 A",
 "1-B1"};
	  vector <string> battles(battles_, battles_+sizeof(battles_)/sizeof(*battles_)); 
	string queries_[] = {"A0-B0",
 "A1-B0",
 "A0-B1",
 "A1-B1"};
	  vector <string> queries(queries_, queries_+sizeof(queries_)/sizeof(*queries_)); 
	string _ = "YNYY"; 
END
CASE(4)
	string dynasties_[] = {"2294 7344","366 384 449 965 1307 1415","307 473 648 688 1097","1145 1411 1569 2606","87 188 551 598 947 998 1917 1942"}
;
	  vector <string> dynasties(dynasties_, dynasties_+sizeof(dynasties_)/sizeof(*dynasties_)); 
	string battles_[] = {"A0-B4 B4-E2 B3-E2 D2-E4 A0-E4 B1-C3 A0-E3 A0-E6 D0","-E2 B2-E1 B4-E3 B4-D0 D0-E3 A0-D1 B2-C3 B1-C3 B4-E","3 D0-E1 B3-D0 B3-E2"}
;
	  vector <string> battles(battles_, battles_+sizeof(battles_)/sizeof(*battles_)); 
	string queries_[] = {"A0-C2","E6-C2","A0-E4","B3-C1","C0-D2","B0-C1","D1-C3","C3-D0","C1-E3","D1-A0"};
	  vector <string> queries(queries_, queries_+sizeof(queries_)/sizeof(*queries_)); 
	string _ = "YNYNNYNNNY"; 
END

}
// END CUT HERE
