// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You've just qualified for the on-site round of a major coding tournament! You now need to sort out a visa to allow you to travel to the event. You know that this is likely to be a long process, but are determined to sort it out as quickly as possible, even if it means working day and night. The process involves filling out a series of forms, which then have to be approved by the embassy. When the last form is approved your visa is granted. The approval process is very quick (instantaneous for the purpose of this problem), but there is a catch: each form has to be approved by the embassy before they will give you the next form to fill out. The embassy opens at exactly the same time each day and remains open for openTime time units. By the non-standard embassy clocks, a day is dayLength time units long, so the embassy then remains closed for dayLength - openTime time units before it opens the next day. Forms can be approved at any point in time between the time that the embassy opens and the time it closes, inclusive. However, if you finish filling in a form when the embassy is closed, you have to wait until it opens again before the form can be approved. The length of time it takes you to fill out form i is forms[i] units and the forms must be completed in the order they are given in forms. You already have the first form in your possession and can start filling it out at any time. Return the minimum length of time between starting to fill out the first form and getting your visa granted.

DEFINITION
Class:Embassy
Method:visaApplication
Parameters:vector <int>, int, int
Returns:int
Method signature:int visaApplication(vector <int> forms, int dayLength, int openTime)


CONSTRAINTS
-forms will contain between 1 and 50 elements, inclusive.
-Each element of forms will be between 1 and 1,000,000 (10^6), inclusive.
-dayLength will be between 1 and 1,000,000 (10^6), inclusive.
-openTime will be between 1 and dayLength, inclusive.


EXAMPLES

0)
{4,4,4}
24
8

Returns: 12

The embassy is open for 8 hours out of a 24 hour day. Each of the three forms takes 4 hours to fill in. If you start filling in the first form 4 hours before the embassy opens, you can get it approved just as the embassy opens. The embassy will still be open 4 hours later to approve the second form and the third form can be approved just as the embassy shuts. Since you never have to wait, the total time is 12 hours.

1)
{4,4,4,4}
24
8

Returns: 28

Now there is an additional form to fill in. You can't complete the process in a single day.

2)
{2,2,2,2}
24
1

Returns: 73

The embassy is only open for one hour each day, so you can only get one form approved per day.

3)
{25,500,630,2500,1000,350,22,58,100,400,500,5000}
1440
360

Returns: 16945

Time is now measured in minutes. It's optimal to start filling in the first form 335 minutes after the embassy first opens.

*/
// END CUT HERE
#line 62 "Embassy.cpp"

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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

VI fo;
int dL;
int op;

int f(int start) {
	int ans=0;
	int t=start;
	int f0=fo[0];
	if(op<t) {
		ans+=dL-t;
		fo[0]=max(fo[0]-(dL-t), 0);
		t=0;
		//cout<<fo[0]<<endl;
	}
	REP(i, fo.size()) {
		ans+=fo[i]/dL*dL;
		int rest=fo[i]%dL;
		if(rest <= op-t) {
			t+=rest;
			ans+=rest;
		} else {
			ans+=max(dL-t, rest);
			t=max(0, rest-(dL-t));
		}
		//cout<<"after "<<i<<" ans "<<ans<<" t "<<t<<" rest "<<rest<<endl;
	}
	//cout<<start<<" "<<ans<<endl;
	fo[0]=f0;
	return ans;
}

class Embassy {
	public:
	int visaApplication(vector<int> _fo, int _dL, int _op) {
		fo=_fo;
		dL=_dL;
		op=_op;
		int ans=100000000;
		REP(i, dL) ans=min(ans, f(i));
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; int Arg2 = 8; int Arg3 = 12; verify_case(0, Arg3, visaApplication(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {4,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; int Arg2 = 8; int Arg3 = 28; verify_case(1, Arg3, visaApplication(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; int Arg2 = 1; int Arg3 = 73; verify_case(2, Arg3, visaApplication(Arg0, Arg1, Arg2)); }
	//void test_case_3() { int Arr0[] = {25,500,630,2500,1000,350,22,58,100,400,500,5000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1440; int Arg2 = 360; int Arg3 = 16945; verify_case(3, Arg3, visaApplication(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {4, 8, 2, 1, 9, 1, 5, 3, 9, 10, 3, 4, 3, 5, 8, 6, 10, 4, 10, 3, 10, 1, 6, 9, 3, 10, 4, 9, 10, 2, 3, 6, 7, 4, 5, 6, 1, 5, 6, 2, 8, 9, 4, 5, 7, 3, 1, 4, 9, 1
	}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 7; int Arg3 = 271; verify_case(3, Arg3, visaApplication(Arg0, Arg1, Arg2)); }


// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	Embassy ___test;

	___test.run_test(-1);
	//___test.test_case_0();

}

// END CUT HERE
