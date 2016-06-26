// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You have to load a ship with some cargo. All the cargo is put in boxes. There are some cranes and each of them can put one box in the ship per minute. All cranes can work simultaneously. Each crane has a weight limit - it cannot move a box whose weight is greater than that limit. Return the minimal time (measured in minutes) needed to load the ship with all cargo or -1 if it is impossible.You are given a vector <int> cranes, the i-th element of which is the weight limit of the i-th crane.  You are also given a vector <string> boxes.  Concatenate the elements of boxes to get a space-separated list of the boxes' weights.


DEFINITION
Class:ShipLoading
Method:minimumTime
Parameters:vector <int>, vector <string>
Returns:int
Method signature:int minimumTime(vector <int> cranes, vector <string> boxes)


CONSTRAINTS
-cranes will contain between 1 and 50 elements, inclusive. 
-boxes will contain between 1 and 50 elements, inclusive. 
-Each element of boxes will contain between 0 and 50 characters, inclusive. 
-The concatenation of all elements of boxes will be a non-empty space-separated list of integers with no leading zeroes. It will contain no leading, trailing, or consecutive spaces. 
-Each element of cranes will be between 1 and 1,000,000, inclusive. 
-Each box weight will be between 1 and 1,000,000, inclusive. 


EXAMPLES

0)
{6,8,9}
{"2 5 2 4 7"}

Returns: 2

Everything can be done in 2 minutes.

1)
{19,20}
{"14 12 16 19 16 1 5"}

Returns: 4

Only two cranes, but each of them can move any of the boxes.

2)
{23,32,25,28}
{"5 27 10 16 24 20 2 32 18 7"}

Returns: 3

3)
{11,17,5,2,20,7,5,5,20,7}
{"18 18 15 15 17"}

Returns: 2

4)
{56,114,979,120,120,87,480}
{"221 882 504 358 642 674 212 679 203 279 632 799 79","6 502 275 823 372 594 482 343"}

Returns: 12

Note that you should not add spaces between elements of boxes during their concatenation.

*/
// END CUT HERE
#line 65 "ShipLoading.cpp"

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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class ShipLoading {
	public:
	int minimumTime(vector <int> cranes, vector <string> boxes) {
		VI bx;
		stringstream ss;
		FOR(v, boxes) ss<<*v;
		
		int vv;
		while(ss>>vv) bx.push_back(vv);
		
		sort(ALL(bx));
		reverse(ALL(bx));
		sort(ALL(cranes));
		reverse(ALL(cranes));
		cout<<bx<<endl;
		
		int ans=0;
		int rest=bx.size();
		while(rest) {
			int rr=rest;
			REP(i, cranes.size()) {
				REP(j, bx.size()) {
					if(bx[j]>0 && bx[j]<=cranes[i]) { bx[j]=0; rest--; break; }
				}
			}
			if(rr==rest) return -1;
			ans++;
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 5 2 4 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, minimumTime(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {19,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"14 12 16 19 16 1 5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minimumTime(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {23,32,25,28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 27 10 16 24 20 2 32 18 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, minimumTime(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {11,17,5,2,20,7,5,5,20,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"18 18 15 15 17"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minimumTime(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {56,114,979,120,120,87,480}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"221 882 504 358 642 674 212 679 203 279 632 799 79","6 502 275 823 372 594 482 343"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(4, Arg2, minimumTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	ShipLoading ___test;

	___test.run_test(-1);

}

// END CUT HERE
