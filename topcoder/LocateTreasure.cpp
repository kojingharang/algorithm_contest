// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// First of all we define a function dig for all nonnegative integers:

dig(x) := x                          if 0 <= x <= 9
dig(x) := dig(sum of digits of x)    if x >= 10

For example: dig(49) = dig(13) = dig(4) = 4.


Your crew of treasure hunters have recently found a very old map with instructions on how to find the treasure of an old civilization.  There is a variable named Gold number, and it is initially assigned a value of 1.  You are currently standing at position (0, 0), facing north.

Repeat the following instructions K times:
1. Take dig(Gold number) steps forward, and then turn 90 degrees right.
2. Multiply Gold number by multi.

Each step forward moves you one unit in your current direction.  Moving north changes your location by (0, 1), south changes your location by (0, -1), west changes your location by (-1, 0) and east changes your location by (1, 0). After you perform all the instructions, you can start digging.  Return the coordinates (X, Y) of your final location as a string in the form "X Y" (quotes for clarity), where X and Y contain no extra leading zeroes.


DEFINITION
Class:LocateTreasure
Method:location
Parameters:int, int
Returns:string
Method signature:string location(int K, int multi)


CONSTRAINTS
-K will be between 1 and 10^9, inclusive.
-multi will be between 1 and 1000, inclusive.


EXAMPLES

0)
5
2

Returns: "-6 4"

You will go 1 step north, 2 steps east, 4 steps south, 8 steps west and 7 steps north.

1)
99
1

Returns: "1 0"

You will do exactly 1 step in every iteration.

2)
6
9

Returns: "9 1"



*/
// END CUT HERE
#line 63 "LocateTreasure.cpp"

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

#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



int dig(ll n) {
	if(n<10) return n;
	int x=0;
	while(n) {
		x+=n%10;
		n/=10;
	}
	return dig(x);
}

class LocateTreasure {
	public:
	string location(int K, int multi) {
		ll w=1;
		VI hi(1000);
		int dx[4]={0, 1, 0, -1};
		int dy[4]={1, 0, -1, 0};
		int dir=0;
		int px=0, py=0;
		for(int i=0;i<K;i++) {
			int di = dig(w);
			REP(j, hi.size()) {
				if(hi[j] & hi[j]==di) {
					int ival = i-j;
					K=K-(K-1-i)/ival*ival;
					cout<<"REPEAT "<<i<<" "<<K<<endl;
					break;
				}
			}
			if(i<hi.size()) hi[i]=di;
			cout<<i<<" "<<di<<endl;
			w*=multi;
			px+=dx[dir]*di;
			py+=dy[dir]*di;
			dir=(dir+1)%4;
		}
		stringstream ss;
		ss<<px<<" "<<py;
		return ss.str();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 2; string Arg2 = "-6 4"; verify_case(0, Arg2, location(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 99; int Arg1 = 1; string Arg2 = "1 0"; verify_case(1, Arg2, location(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 9; string Arg2 = "9 1"; verify_case(2, Arg2, location(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	LocateTreasure ___test;

	___test.run_test(-1);

}

// END CUT HERE
