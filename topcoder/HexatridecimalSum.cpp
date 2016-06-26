// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Hexatridecimal notation is base 36 notation.  The digits are '0' to '9' (with values 0 to 9) and 'A' to 'Z' (with values 10 to 35).

You are given a vector <string> numbers, where each element represents a positive integer in hexatridecimal notation.  You must select exactly k digits (from the set of all digits - '0' to '9' and 'A' to 'Z') and replace all of their occurrences in all of the numbers with 'Z'.  Then, calculate the sum of all the numbers.

Return the maximal possible sum you can get.  The return value must be in hexatridecimal format with no leading zeroes.

DEFINITION
Class:HexatridecimalSum
Method:maximizeSum
Parameters:vector <string>, int
Returns:string
Method signature:string maximizeSum(vector <string> numbers, int k)


CONSTRAINTS
-numbers will contain between 1 and 50 elements, inclusive.
-Each element of numbers will contain between 1 and 50 characters, inclusive.
-Each element of numbers will contain only characters '0' to '9' and 'A' to 'Z'.
-Each element of numbers will not start with '0'.
-k will be between 0 and 36, inclusive.


EXAMPLES

0)
{"HELLO"}
2

Returns: "ZZLLO"

It is optimal to change the two most significant digits in the given number.

1)
{"500", "POINTS", "FOR", "THIS", "PROBLEM"}
5

Returns: "1100TC85"



2)
{"TO", "BE", "OR", "NOT", "TO", "BE"}
0

Returns: "QNO"

k = 0 means that you're not allowed to change any digits, so the answer is the sum of the given numbers.

3)
{"KEQUALS36"}
36

Returns: "ZZZZZZZZZ"

k = 36 means that you have to replace all the letters with 'Z'.

4)
{"GOOD", "LUCK", "AND", "HAVE", "FUN"}
7

Returns: "31YUB"



*/
// END CUT HERE
#line 71 "HexatridecimalSum.cpp"

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


int c2i(char c) {
	if('0'<=c&&c<='9') return c-'0';
	if('A'<=c&&c<='Z') return c-'A'+10;
	return -1;
}

class HexatridecimalSum {
	public:
	string maximizeSum(vector <string> nu, int k) {
		VVI nn(nu.size());
		REP(i, nu.size()) FOR(c, nu[i]) nn[i].push_back(c2i(*c));
		//cout<<nn<<endl;
		string tb("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		vector<double> adt(36);
		REP(i, 36) {
			REP(j, nu.size()) {
				double v=0;
				REP(m, nu[j].size()) {
					v=v*36+(nn[j][m]==i?35-nn[j][m]:0);
				}
				adt[i]+=v;
			}
		}
		cout<<adt<<endl;
		vector<pair<double, int> > vp;
		REP(i, adt.size()) { vp.push_back(make_pair(adt[i], i)); }
		sort(ALL(vp));
		reverse(ALL(vp));
		//cout<<vp<<endl;
		double base = 0;
		REP(j, nu.size()) {
			double v=0;
			REP(m, nu[j].size()) {
				v=v*36+nn[j][m];
			}
			base+=v;
		}
		REP(i, k) {
			//cout<<vp[i].first<<endl;
			base+=vp[i].first;
		}
		//cout<<base<<endl;
		string ans;
		REP(i, 100) {
			ans=tb[base%36]+ans;
			base/=36;
			if(base==0) break;
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"HELLO"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "ZZLLO"; verify_case(0, Arg2, maximizeSum(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"500", "POINTS", "FOR", "THIS", "PROBLEM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; string Arg2 = "1100TC85"; verify_case(1, Arg2, maximizeSum(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"TO", "BE", "OR", "NOT", "TO", "BE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; string Arg2 = "QNO"; verify_case(2, Arg2, maximizeSum(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"KEQUALS36"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; string Arg2 = "ZZZZZZZZZ"; verify_case(3, Arg2, maximizeSum(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"GOOD", "LUCK", "AND", "HAVE", "FUN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; string Arg2 = "31YUB"; verify_case(4, Arg2, maximizeSum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	HexatridecimalSum ___test;

	___test.run_test(-1);

}

// END CUT HERE
