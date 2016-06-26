/*
// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Every good encyclopedia has an index. The entries in the index are usually sorted in alphabetic order. However, there are some notable exceptions. In this task we will consider one such exception: the names of kings.



In many countries it was common that kings of the same name received ordinal numbers. This ordinal number was written as a Roman numeral and appended to the actual name of the king.
For example, "Louis XIII" (read: Louis the thirteenth) was the thirteenth king of France having the actual name Louis.



In the index of an encyclopedia, kings who share the same name have to be sorted according to their ordinal numbers. For example, Louis the 9th should be listed after Louis the 8th.



You are given a vector <string> kings. Each element of kings is the name of one king. The name of each king consists of his actual name, a single space, and a Roman numeral. Return a vector <string> containing the names
rearranged into their proper order: that is, the kings have to be in ascending lexicographic order according to their actual name, and kings with the same name have to be in the correct numerical order.


DEFINITION
Class:KingSort
Method:getSortedList
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> getSortedList(vector <string> kings)


NOTES
-The Roman numerals for 1 through 10 are I, II, III, IV, V, VI, VII, VIII, IX, and X.
-The Roman numerals for 20, 30, 40, and 50 are XX, XXX, XL, and L.
-The Roman numeral for any other two-digit number less than 50 can be constructed by concatenating the numeral for its tens and the numeral for its ones. For example, 47 is 40 + 7 = "XL" + "VII" = "XLVII".
-Standard string comparison routines give the correct ordering for the actual names of kings.
-Formally, given two different strings A and B we say that A is lexicographically smaller than B if either (A is a prefix of B) or (there is at least one index where A and B differ, and for the smallest such index the character in A has a lower ASCII value than the character in B).


CONSTRAINTS
-Each actual name of a king will be a string containing between 1 and 20 characters, inclusive.
-Each actual name will start by an uppercase letter ('A'-'Z').
-Each other character in each actual name will be a lowercase letter ('a'-'z').
-kings will contain between 1 and 50 elements, inclusive.
-Each element of kings will have the form "ACTUALNAME ORDINAL", where ACTUALNAME is an actual name as defined above, and ORDINAL is a valid Roman numeral representing a number between 1 and 50, inclusive.
-The elements of kings will be pairwise distinct.


EXAMPLES

0)
{"Louis IX", "Louis VIII"}

Returns: {"Louis VIII", "Louis IX" }

Louis the 9th should be listed after Louis the 8th.

1)
{"Louis IX", "Philippe II"}

Returns: {"Louis IX", "Philippe II" }

Actual names take precedence over ordinal numbers.

2)
{"Richard III", "Richard I", "Richard II"}

Returns: {"Richard I", "Richard II", "Richard III" }



3)
{"John X", "John I", "John L", "John V"}

Returns: {"John I", "John V", "John X", "John L" }



4)
{"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"}

Returns: {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" }

These are the French monarchs who ruled between 1328 and 1483.

5)
{"Philippe II", "Philip II"}

Returns: {"Philip II", "Philippe II" }

"Philippe" and "Philip" are distinct names, and "Philip" is lexicographically smaller than "Philippe".

// END CUT HERE
*/
#line 94 "KingSort.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
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
#define VI vector<int>
#define VVI vector<vector<int> >
#define PII pair<int, int> 
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class KingSort {
	public:
	string i2o(int i) {
		string m1[]={"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		string m2[]={"", "X", "XX", "XXX", "XL", "L"};
		return m2[i/10]+m1[i%10];
	}
	int ord(string s) {
		//The Roman numerals for 1 through 10 are I, II, III, IV, V, VI, VII, VIII, IX, and X.
		//The Roman numerals for 20, 30, 40, and 50 are XX, XXX, XL, and L.
		if(s.substr(0,1)=="L") return 50+ord(s.substr(1));
		if(s.substr(0,2)=="XL") return 40+ord(s.substr(2));
		if(s.substr(0,3)=="XXX") return 30+ord(s.substr(3));
		if(s.substr(0,2)=="XX") return 20+ord(s.substr(2));
		if(s.substr(0,1)=="X") return 10+ord(s.substr(1));
		if(s.substr(0,2)=="IX") return 9;
		if(s.substr(0,4)=="VIII") return 8;
		if(s.substr(0,3)=="VII") return 7;
		if(s.substr(0,2)=="VI") return 6;
		if(s.substr(0,1)=="V") return 5;
		if(s.substr(0,2)=="IV") return 4;
		if(s.substr(0,3)=="III") return 3;
		if(s.substr(0,2)=="II") return 2;
		if(s.substr(0,1)=="I") return 1;
		return 0;
	}
	vector <string> getSortedList(vector <string> kings) {
		REP(i, 51) if(i!=ord(i2o(i))) cout<<i2o(i)<<endl;
		vector<pair<pair<string, int>, string> > w;
		REP(i, kings.size()) {
			stringstream ss(kings[i]);
			string name, o;
			ss>>name>>o;
			w.push_back(make_pair(make_pair(name, ord(o)), kings[i]));
		}
		sort(ALL(w));
		vector<string> ans(w.size());
		REP(i, w.size()) ans[i]=w[i].second;
		return ans;
	}
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Louis IX", "Louis VIII"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Louis VIII", "Louis IX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getSortedList(Arg0)); }
	void test_case_1() { string Arr0[] = {"Louis IX", "Philippe II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Louis IX", "Philippe II" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getSortedList(Arg0)); }
	void test_case_2() { string Arr0[] = {"Richard III", "Richard I", "Richard II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Richard I", "Richard II", "Richard III" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getSortedList(Arg0)); }
	void test_case_3() { string Arr0[] = {"John X", "John I", "John L", "John V"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"John I", "John V", "John X", "John L" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getSortedList(Arg0)); }
	void test_case_4() { string Arr0[] = {"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getSortedList(Arg0)); }
	void test_case_5() { string Arr0[] = {"Philippe II", "Philip II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Philip II", "Philippe II" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getSortedList(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  KingSort ___test;
  ___test.run_test(-1);
  //___test.test_case_0();
}
// END CUT HERE
