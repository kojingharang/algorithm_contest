// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Consider the 3x3x3 cube shown above.  There are nine squares on each of its six faces, and each face is colored using the following pattern:
	
		The four corner squares are red.
		The center square is green.
		The remaining four squares are blue.
	
There is a robot standing in the green square of the top face of the cube, facing one of the blue squares.  It receives a sequence of commands.  Each command is one of the following:
	
		'L': Stay in the current square and turn left 90 degrees.
		'R': Stay in the current square and turn right 90 degrees.
		'W': Walk forward in the current direction to the next square.
	
Note that the robot can cross an edge of the cube into another face.  When that happens, the cube will rotate automatically to keep the robot on the top face.
You are given a string movement containing the sequence of commands received by the robot.  The robot will execute all of the commands in order.  Return the color of the robot's final landing square - "RED", "GREEN" or "BLUE" (all quotes for clarity).

DEFINITION
Class:CubeWalking
Method:finalPosition
Parameters:string
Returns:string
Method signature:string finalPosition(string movement)


NOTES
-The answer does not depend on the initial direction of the robot.


CONSTRAINTS
-movement will contain between 1 and 50 characters, inclusive.
-Each character in movement will be 'L', 'R' or 'W'.


EXAMPLES

0)
"LLRR"

Returns: "GREEN"

In this example, the robot only turns left or right without ever moving to a different square.

1)
"WWWWWWWWWWWW"

Returns: "GREEN"

Walking 12 squares forward in the same direction will lead the robot back to its original position.

2)
"WLWRW"

Returns: "RED"



3)
"WWLLWRWLWLLRWW"

Returns: "BLUE"



*/
// END CUT HERE
#line 70 "CubeWalking.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class CubeWalking {
	public:
	string finalPosition(string mov) {
		const char* col[] = {"RED", "BLUE", "RED", "BLUE", "GREEN", "BLUE", "RED", "BLUE", "RED"};
		int pos = 4;
		int dir = 0;
		int add[] = {6, 1, 3, 8};
		FOR(v, mov) {
			if(*v=='L') {
				dir=(dir-1+4)%4;
			} else if(*v=='R') {
				dir=(dir+1)%4;
			} else if(*v=='W') {
				pos+=add[dir];
			}
		}
		return col[pos%9];
	}
	//string finalPosition(string mov) {
	//	const char* col[] = {"RED", "BLUE", "RED", "BLUE", "GREEN", "BLUE", "RED", "BLUE", "RED"};
	//	int pos = 4;
	//	int dir = 0;
	//	FOR(v, mov) {
	//		if(*v=='L') {
	//			dir=(dir-1+4)%4;
	//		} else if(*v=='R') {
	//			dir=(dir+1)%4;
	//		} else if(*v=='W') {
	//			if(dir==0) {
	//				pos+=-3;
	//				if(pos<0) pos+=9;
	//			} else if(dir==2) {
	//				pos+=3;
	//				if(pos>=9) pos-=9;
	//			} else if(dir==1) {
	//				pos+=pos%3==2 ? -2 : 1;
	//			} else if(dir==3) {
	//				pos+=pos%3==0 ? +2 : -1;
	//			}
	//		}
	//	}
	//	return col[pos];
	//}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLRR"; string Arg1 = "GREEN"; verify_case(0, Arg1, finalPosition(Arg0)); }
	void test_case_1() { string Arg0 = "WWWWWWWWWWWW"; string Arg1 = "GREEN"; verify_case(1, Arg1, finalPosition(Arg0)); }
	void test_case_2() { string Arg0 = "WLWRW"; string Arg1 = "RED"; verify_case(2, Arg1, finalPosition(Arg0)); }
	void test_case_3() { string Arg0 = "WWLLWRWLWLLRWW"; string Arg1 = "BLUE"; verify_case(3, Arg1, finalPosition(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	CubeWalking ___test;

	___test.run_test(-1);

}

// END CUT HERE
