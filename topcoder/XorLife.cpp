// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Magical Girl Madoka just learned about Conway's Game of Life. She is now thinking about new rules for this game.
In the Game of Life, an infinite plane is divided into a grid of unit square cells. 
At any moment, each cell is either alive or dead. 
Every second the state of each cell changes according to a fixed rule.
In Madoka's version of the game the following rule is used: 

 Consider any cell C.
Look at the current states of the cell C and all four cells that share a side with C. 
 If an odd number of these cells is alive (i.e., 1 cell, 3 cells, or 5 cells), cell C will be alive in the next second.
Otherwise, cell C will be dead in the next second. 
 Note that each second the rule is applied on all cells at the same time.   
Madoka wants to know how many cells are alive after K seconds.
You are given the int K and a vector <string> field that describes the initial state of the plane. field describes only some rectangular area of the plane. More precisely, character j of element i of field is 'o' if the cell in the i-th row of the j-th column of the rectangular area is alive, and it is '.' otherwise. Cells which aren't described in field is initially all dead. 
Return the number of alive cells after K seconds.


DEFINITION
Class:XorLife
Method:countAliveCells
Parameters:vector <string>, int
Returns:long long
Method signature:long long countAliveCells(vector <string> field, int K)


NOTES
-You can assume that the result will fit into a signed 64-bit integer.


CONSTRAINTS
-field will contain between 1 and 50 elements, inclusive.
-Each elements of field will contain between 1 and 50 characters, inclusive.
-All elements of field will contain the same number of characters.
-Each character in each element of field will be either 'o' or '.'.
-K will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{"oo"
,"o."}
3

Returns: 23

The status after 3 seconds is below.

...oo...
..oo.o..
.o.oooo.
ooooo..o
o.oo....
.oo.....
..o.....
...o....

1)
{".."
,".."}
23

Returns: 0

All cells of the plane can be dead.

2)
{"o"}
1234567

Returns: 11018125



3)
{"o.oo.ooo"
,"o.o.o.oo"
,"ooo.oooo"
,"o.o..o.o"
,"o.o..o.o"
,"o..oooo."
,"..o.o.oo"
,"oo.ooo.o"}
987654321

Returns: 447104494375



*/
// END CUT HERE
#line 95 "XorLife.cpp"

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



class XorLife {
	public:
	long long countAliveCells(vector <string> field, int K) {
		
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
void verify_case(const long long& Expected, const long long& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, XorLife().countAliveCells(field, K));}
int main(){

CASE(0)
	string field_[] = {"oo"
,"o."};
	  vector <string> field(field_, field_+sizeof(field_)/sizeof(*field_)); 
	int K = 3; 
	long long _ = 23LL; 
END
CASE(1)
	string field_[] = {".."
,".."};
	  vector <string> field(field_, field_+sizeof(field_)/sizeof(*field_)); 
	int K = 23; 
	long long _ = 0LL; 
END
CASE(2)
	string field_[] = {"o"};
	  vector <string> field(field_, field_+sizeof(field_)/sizeof(*field_)); 
	int K = 1234567; 
	long long _ = 11018125LL; 
END
CASE(3)
	string field_[] = {"o.oo.ooo"
,"o.o.o.oo"
,"ooo.oooo"
,"o.o..o.o"
,"o.o..o.o"
,"o..oooo."
,"..o.o.oo"
,"oo.ooo.o"};
	  vector <string> field(field_, field_+sizeof(field_)/sizeof(*field_)); 
	int K = 987654321; 
	long long _ = 447104494375LL; 
END

}
// END CUT HERE
