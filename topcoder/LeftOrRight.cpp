// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// The Very Heterogeneous State of Feudalia's army is designing a new spy robot. Currently, the robot can only accept two commands: L and R. L moves the robot one unit of distance to the left, and R moves the robot one unit to the right. A program for the robot is a sequence of commands. For a given program, its reach is the distance between the starting point and the farthest point visited during the execution of the program. For example, the reach of the program "LLLR" is 3, because after the first three steps we reach a location 3 units away from the starting point.

Unfortunately, Feudalia is world famous for the ineptitude of its public officials. Some coffee was spilled all over the program before it could be installed to the robot. Therefore, some of the commands may now be illegible.
Your task is to repair the program by replacing each illegible command with an L or an R. 
If there are multiple ways to repair the program, you have to pick one that maximizes its reach.

You are given a string program which describes the program in its current state. The i-th character in program represents the i-th command that is executed and will be 'L', 'R' or '?' (quotes for clarity). 'L' represents a legible move left, 'R' a legible move right and '?' a command that is illegible so you can choose 'L' or 'R' in its place. Return the largest reach a repaired program can have.

DEFINITION
Class:LeftOrRight
Method:maxDistance
Parameters:string
Returns:int
Method signature:int maxDistance(string program)


CONSTRAINTS
-program will contain between 1 and 50 characters, inclusive.
-Each character of program will be 'L', 'R' or '?' (quotes for clarity).


EXAMPLES

0)
"LLLRLRRR"

Returns: 3

All commands are legible. The reach of this program is 3: both after three steps and after five steps we are 3 units to the left of the starting location.

1)
"R???L"

Returns: 4

We can replace all of the question marks with a right command.

2)
"??????"

Returns: 6



3)
"LL???RRRRRRR???"

Returns: 11



4)
"L?L?"

Returns: 4



*/
// END CUT HERE
#line 65 "LeftOrRight.cpp"

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



class LeftOrRight {
	public:
	int maxDistance(string P) {
		int pos = 0;
		int L = 0;
		int r = 0;
		int maxidx=-1;
		REP(i, P.size()) {
			r += P[i]=='?';
			if(P[i]=='L') pos -= 1;
			if(P[i]=='R') pos += 1;
			L = max(L, abs(pos)+r);
			L = max(L, abs(pos)-r);
		}
		return L;
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
#define END	 verify_case(_, LeftOrRight().maxDistance(program));}
int main(){

CASE(0)
	string program = "LLLRLRRR"; 
	int _ = 3; 
END
CASE(1)
	string program = "R???L"; 
	int _ = 4; 
END
CASE(2)
	string program = "??????"; 
	int _ = 6; 
END
CASE(3)
	string program = "LL???RRRRRRR???"; 
	int _ = 11; 
END
CASE(4)
	string program = "L?L?"; 
	int _ = 4; 
END
CASE(4)
	string program = "LLLLLRRRRR???"; 
	int _ = 5; 
END
CASE(4)
	string program = "LR??????"; 
	int _ = 6; 
END

}
// END CUT HERE

/*
LR??????
??????????????????????????????????????????????????
*/
