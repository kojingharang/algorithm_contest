// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A string S is an interspersal of a set of strings W, if W is a set of disjoint subsequences of S which cover S. Less formally, S can be formed from W by partitioning each member of W into substrings, then concatenating all the substrings, while maintaining the order of the substrings within each element of W. For example, if W contains the strings {"DESIGN", "ALGORITHM", "MARATHON"}, then one possible interspersal would be "ADELGMAORARISIGNTHMTHON", formed as shown below.


?DE?????????SIGN
A??LG??O??RI????THM
?????MA?RA?????????THON
-----------------------
ADELGMAORARISIGNTHMTHON

Given a vector <string> W, return the lexicographically minimum interspersal of the strings in W

DEFINITION
Class:StringInterspersal
Method:minimum
Parameters:vector <string>
Returns:string
Method signature:string minimum(vector <string> W)


NOTES
-The lexicographically minimum of two strings is the one with the alphabetically earlier character at the first position at which they differ.
-The return string will contain no more than 1000 characters.


CONSTRAINTS
-W will contain between 1 and 20 elements, inclusive.
-Each element of W will contain between 1 and 50 uppercase letters ('A'-'Z'), inclusive.


EXAMPLES

0)
{"DESIGN","ALGORITHM","MARATHON"}

Returns: "ADELGMAORARISIGNTHMTHON"

The example from the problem statement.

1)
{"TOMEK","PETR","ACRUSH","BURUNDUK","KRIJGERTJE"}

Returns: "ABCKPERIJGERRTJETOMEKTRURUNDUKUSH"



2)
{"CCCA","CCCB","CCCD","CCCE"}

Returns: "CCCACCCBCCCCCCDE"



3)
{"BKSDSOPTDD","DDODEVNKL","XX","PODEEE","LQQWRT"}

Returns: "BDDKLODEPODEEEQQSDSOPTDDVNKLWRTXX"



4)
{"TOPCODER","BETFAIR","NSA","BT","LILLY"}

Returns: "BBELILLNSATFAIRTOPCODERTY"



5)
{"QITHSQARQV","BYLHVGMLRY","LKMAQTJEAM","AQYICVNIKK","HKGZZFFEWC"}

Returns: "ABHKGLKMAQIQQTHSQARQTJEAMVYICVNIKKYLHVGMLRYZZFFEWC"

6)
{"XHCYBTUQUW","EKBISADSSN","LOOISPOFAK","MIXBDHPJUQ","BNMNDHMOTC"}

Returns: "BEKBILMINMNDHMOOIOSADSPOFAKSSNTCXBDHPJUQXHCYBTUQUW"

*/
// END CUT HERE
#line 83 "StringInterspersal.cpp"

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



class StringInterspersal {
	public:
	string minimum(vector <string> W) {
		string ans;
		VI pos(W.size());
		while(1) {
			string mi;
			int mii=-1;
			//cout<<"begin "<<endl;
			REP(i, W.size()) {
				string co(W[i].substr(pos[i]));
				co+="]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]";
				//cout<<" cand "<<co<<endl;
				if(pos[i]<W[i].size() && (mii==-1 || co<mi)) {
					//cout<<i<<" "<<pos[i]<<" "<<W[i][pos[i]]<<" "<<mi<<endl;
					mi=co;
					mii=i;
				}
			}
			//cout<<"select "<<mi<<endl;
			if(mii==-1) return ans;
			ans+=W[mii][pos[mii]];
			pos[mii]++;
		}
		return "";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"DESIGN","ALGORITHM","MARATHON"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ADELGMAORARISIGNTHMTHON"; verify_case(0, Arg1, minimum(Arg0)); }
	void test_case_1() { string Arr0[] = {"TOMEK","PETR","ACRUSH","BURUNDUK","KRIJGERTJE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABCKPERIJGERRTJETOMEKTRURUNDUKUSH"; verify_case(1, Arg1, minimum(Arg0)); }
	void test_case_2() { string Arr0[] = {"CCCA","CCCB","CCCD","CCCE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CCCACCCBCCCCCCDE"; verify_case(2, Arg1, minimum(Arg0)); }
	void test_case_3() { string Arr0[] = {"BKSDSOPTDD","DDODEVNKL","XX","PODEEE","LQQWRT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BDDKLODEPODEEEQQSDSOPTDDVNKLWRTXX"; verify_case(3, Arg1, minimum(Arg0)); }
	void test_case_4() { string Arr0[] = {"TOPCODER","BETFAIR","NSA","BT","LILLY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BBELILLNSATFAIRTOPCODERTY"; verify_case(4, Arg1, minimum(Arg0)); }
	void test_case_5() { string Arr0[] = {"QITHSQARQV","BYLHVGMLRY","LKMAQTJEAM","AQYICVNIKK","HKGZZFFEWC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABHKGLKMAQIQQTHSQARQTJEAMVYICVNIKKYLHVGMLRYZZFFEWC"; verify_case(5, Arg1, minimum(Arg0)); }
	//void test_case_6() { string Arr0[] = {"XHCYBTUQUW","EKBISADSSN","LOOISPOFAK","MIXBDHPJUQ","BNMNDHMOTC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BEKBILMINMNDHMOOIOSADSPOFAKSSNTCXBDHPJUQXHCYBTUQUW"; verify_case(6, Arg1, minimum(Arg0)); }
	void test_case_6() { string Arr0[] = {"TFGHDFZC", "AASADFZCAB", "XXYZAZCBB", "TRIFFZCDDD", "ZC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AASADFTFGHDFTRIFFXXYZAZCABZCBBZCDDDZCZC"; verify_case(6, Arg1, minimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	StringInterspersal ___test;

	___test.run_test(-1);

}

// END CUT HERE
