// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
In this problem we will use the terms XHTML and CSS. They do not match the real-world XHTML and CSS standards exactly. Read the problem statement to clarify the meanings of these terms in the problem context.


You are given a vector <string> xhtml. Concatenate elements of xhtml to get a single string formatted as tags. We use BNF to describe tags formally.


	tags ::= tag | tag tags


	tagContent ::= EMPTY | tags


	tag ::= <TAG id='ID' style='color:COLOR'>tagContent</TAG>


Where 


EMPTY means an empty string, 


TAG is one of the strings "b", "u", "i", which are called tag names.


ID means unique non-empty tag identifier containing only lowercase letters,


COLOR is one of the following seven standard colors: "black", "blue", "gray", "green",
            "red", "white", "yellow".


The tags in tagContent are called strict descendants of the surrounding tag.


We will say that each tag is assigned the specified color. For example, if tags = "<b id='x' style='color:white'><u id='y' style='color:red'></u><u id='z' style='color:red'></u>", then the tag with id='x' is assigned the color white, and the tags with id='y' and id='z' are assigned the color red.


You decided to extract the information about assigned colors to CSS rules. Each CSS rule looks like "selector {color:COLOR;}" and assigns a specific color to one or more tags. In this problem we will accept only two types of selectors:


"#id" ? means that CSS rule will be applied to the tag with the given id (example, "#x").


"#id tagName" ? means that CSS rule will be applied to all tags with the specified tag name which are the strict descendants of the tag with the given id (example, "#x u"). 


CSS rules are applied in the order they are given, and it is possible for some later rules to override earlier rules for certain tags.


Return the minimal number of CSS rules you need to assign the proper color to each tag.



DEFINITION
Class:CssRules
Method:getMinimalCssRuleCount
Parameters:vector <string>
Returns:int
Method signature:int getMinimalCssRuleCount(vector <string> xthml)


CONSTRAINTS
-xhtml will contain between 1 and 50 elements, inclusive.
-Each element of xhtml will contain between 1 and 50 characters, inclusive.
-The concatenation of all elements of xhtml will satisfy the grammar given in the problem statement and conditions given after it.


EXAMPLES

0)
{"<b id='x' style='color:red'>"}

Returns: 1

Use only the rule "#x {color:red;}".


1)
{"<b id='x' style='color:red'>","<b id='y' style='color:red'>",
 "<b id='z' style='color:red'>",""}


Returns: 2

Use two rules "#x {color:red;}" and "#x b {color:red;}".

2)
{"<b id='x' style='color:red'>",
"<b id='y' style='color:red'>",
"<b id='w' style='color:red'>",
"",
"",
"<u id='z' style='color:red'>",
"</u>",
""}

Returns: 3



3)
{"<b id='x' style='color:red'>",
"<i id='y' style='color:black'>",
"<u id='w' style='color:white'>",
"</u>",
"",
"<u id='z' style='color:yellow'>",
"</u>",
""}

Returns: 4



4)
{"<b id='x' style='col", "or:red'>", "<b id=", "'xx' style='color", ":red'>"}

Returns: 2



*/
// END CUT HERE
#line 129 "CssRules.cpp"
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define B begin()
#define E end()
#define SZ size()
#define PB(v) push_back(v)
using namespace std;
#define REP(i, n) for(int i=0, _n=(n);(i)<_n;i++)
#define FOR(i, a, b) for(int i=(a),_b=(b);(i)<_b;i++)
#define FORD(i, a, b) for(int i=(a),_b=(b);(i)>=_b;i--)
#define CLR(a) memset(a, 0, sizeof(a))
#define SORT(v) sort(v.B, v.E)
template <typename T>
void UNIQ(T& v)
{
	typename T::iterator end = unique(v.B, v.E);
	v.erase(end, v.end());
}
template <typename T0, typename T1>
std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v)
{
	for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ )
	{
		os << p->first << ": " << p->second << " ";
	}
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v)
{
	for( int i = 0; i < v.size(); i++ )
	{
		os << v[i] << " ";
	}
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const set<T>& v)
{
	vector<T> tmp(v.B, v.E);
	os << tmp;
	return os;
}

vector<vector<int> > combination(vector<int> vi, int K)
{
	sort(vi.begin(), vi.end());

	set<vector<int> > se;
	do
	{
		vector<int> tm(vi.begin(), vi.begin()+K);
		sort(tm.begin(), tm.end());
		se.insert(tm);
	}
	while(next_permutation(vi.begin(), vi.end()));
	return vector< vector<int> >(se.begin(), se.end());
}

int ans=0;
int pos=0;

class CssRules {
	public:
	int tags(string& s, map<string, int> hi)
	{
printf("%s %d\n", __FILE__, __LINE__);
		if(pos >= s.SZ) return 0;
		//map<string, int> hi;
		do
		{
			// tag
			char tag = s[pos+1];
			string id;
			pos+=7;
			REP(i, 100)
			{
				if(s[pos]=='\'') break;
				id += s[pos];
				pos++;
			}
			pos+=9;
			string col;
			REP(i, 100)
			{
				if(s[pos]=='\'') break;
				col += s[pos];
				pos++;
			}
			cout<<"TAG "<<tag<<" id "<<id<<" col "<<col<<endl;
			hi[tag+"_"+col]=1;
			
			while(s[pos]!='>') pos++;
			pos++;
			cout<<"NEXT "<<s[pos]<<endl;
			if(s[pos+1]!='/')
				tags(s, hi);
			if(s[pos+1]=='/')
			{
				pos+=4;
				cout<<"END NEXT "<<s[pos]<<endl;
				break;
			}
		}
		while(pos < s.SZ);
		map<string, int>::iterator p;
		for(p=hi.begin(); p!=hi.end(); p++)
		{
		}
		cout<<"ADD "<<hi.SZ<<endl;
		
		return 0;
	}
	int getMinimalCssRuleCount(vector <string> x) {
printf("%s %d\n", __FILE__, __LINE__);
		string s;
		ans = 0;
		pos = 0;
		REP(xi, x.SZ) s+=x[xi];
		map<string, int> hi;
		tags(s, hi);
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"<b id='x' style='color:red'></b>"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getMinimalCssRuleCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"<b id='x' style='color:red'>","<b id='y' style='color:red'>",
 "<b id='z' style='color:red'>","</b></b></b>"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getMinimalCssRuleCount(Arg0)); }
	void test_case_2() { string Arr0[] = {"<b id='x' style='color:red'>",
"<b id='y' style='color:red'>",
"<b id='w' style='color:red'>",
"</b>",
"</b>",
"<u id='z' style='color:red'>",
"</u>",
"</b>"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, getMinimalCssRuleCount(Arg0)); }
	void test_case_3() { string Arr0[] = {"<b id='x' style='color:red'>",
"<i id='y' style='color:black'>",
"<u id='w' style='color:white'>",
"</u>",
"</i>",
"<u id='z' style='color:yellow'>",
"</u>",
"</b>"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, getMinimalCssRuleCount(Arg0)); }
	void test_case_4() { string Arr0[] = {"<b id='x' style='col", "or:red'></b>", "<b id=", "'xx' style='color", ":red'></b>"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, getMinimalCssRuleCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	CssRules ___test;

	___test.run_test(-1);

}

// END CUT HERE
