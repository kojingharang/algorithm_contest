// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Byteasar is playing a tabletop role-playing game with his friends. To determine the effectiveness of their heroes' actions the players use a rather unique set of dice which may have nonequal number of faces. Each die has between 1 and 9 faces, inclusive. If a die has m faces, they contain precisely all the values between 1 and m, inclusive. More precisely, for each k between 1 and m, inclusive, there is one face that shows exactly k pips. When a die is cast, every face has equal probability to come out on top.


Every time all the dice were thrown at once, Byteasar wrote down the numbers of pips visible on each of the topmost faces (in any order). The results of the i-th throw are given in throws[i]; the length of throws[i] is equal to the number of dice and each character of throws[i] denotes the number of pips visible on one of the topmost faces. For example, if throws[3][0]='7', this means that in throw 3 (0-based index) one of the dice showed exactly 7 pips on the top. Please note that the ordering of dice may be different for different throws.


Given the vector <string> throws containing Byteasar's notes, return the minimum possible total number of faces of all dice.

DEFINITION
Class:RollingDiceDivTwo
Method:minimumFaces
Parameters:vector <string>
Returns:int
Method signature:int minimumFaces(vector <string> rolls)


NOTES
-Please note that a die can have as few as one or two faces.


CONSTRAINTS
-rolls will contain between 1 and 50 elements, inclusive.
-rolls[0] will contain between 1 and 50 characters, inclusive.
-All elements of rolls will contain the same number of characters.
-Each character in each element of rolls will be one of '1'-'9'.


EXAMPLES

0)
{"137", "364", "115", "724"}

Returns: 14

In the first throw the numbers of pips on the topmost faces of the dice were 1, 3 and 7; in the second throw they were 3, 6 and 4, in the third they were 1, 1 and 5 and in the fourth roll they were 7, 2 and 4. The players may have used dice with 3, 4 and 7 faces, giving a total of 14 faces. No other possible set of dice has less faces in total.

1)
{"1112", "1111", "1211", "1111"}

Returns: 5

The players could have used three dice with one face each and one die with two faces.

2)
{"24412", "56316", "66666", "45625"}

Returns: 30

The players could have used five dice with six faces each.

3)
{"931", "821", "156", "512", "129", "358", "555"}

Returns: 19



4)
{"3", "7", "4", "2", "4"}

Returns: 7



5)
{"281868247265686571829977999522", "611464285871136563343229916655", "716739845311113736768779647392", "779122814312329463718383927626",
"571573431548647653632439431183", "547362375338962625957869719518", "539263489892486347713288936885", "417131347396232733384379841536"}

Returns: 176



*/
// END CUT HERE
#line 79 "RollingDiceDivTwo.cpp"

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



class RollingDiceDivTwo {
	public:
	int minimumFaces(vector <string> R) {
		REP(i, R.size()) sort(ALL(R[i]));
		int ans = 0;
		REP(i, R[0].size()) {
			int l=0;
			REP(j, R.size()) {
				l=max(l, R[j][i]-'0');
			}
			ans+=l;
		}
		return ans;
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
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, RollingDiceDivTwo().minimumFaces(rolls));}
int main(){

CASE(0)
	string rolls_[] = {"137", "364", "115", "724"};
	  vector <string> rolls(rolls_, rolls_+sizeof(rolls_)/sizeof(*rolls_)); 
	int _ = 14; 
END
CASE(1)
	string rolls_[] = {"1112", "1111", "1211", "1111"};
	  vector <string> rolls(rolls_, rolls_+sizeof(rolls_)/sizeof(*rolls_)); 
	int _ = 5; 
END
CASE(2)
	string rolls_[] = {"24412", "56316", "66666", "45625"};
	  vector <string> rolls(rolls_, rolls_+sizeof(rolls_)/sizeof(*rolls_)); 
	int _ = 30; 
END
CASE(3)
	string rolls_[] = {"931", "821", "156", "512", "129", "358", "555"};
	  vector <string> rolls(rolls_, rolls_+sizeof(rolls_)/sizeof(*rolls_)); 
	int _ = 19; 
END
CASE(4)
	string rolls_[] = {"3", "7", "4", "2", "4"};
	  vector <string> rolls(rolls_, rolls_+sizeof(rolls_)/sizeof(*rolls_)); 
	int _ = 7; 
END
CASE(5)
	string rolls_[] = {"281868247265686571829977999522", "611464285871136563343229916655", "716739845311113736768779647392", "779122814312329463718383927626",
"571573431548647653632439431183", "547362375338962625957869719518", "539263489892486347713288936885", "417131347396232733384379841536"};
	  vector <string> rolls(rolls_, rolls_+sizeof(rolls_)/sizeof(*rolls_)); 
	int _ = 176; 
END

}
// END CUT HERE
