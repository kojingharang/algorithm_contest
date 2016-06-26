// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are playing a simple one-player game in which you are given a set of cards. 
Each card has a string written on the front and a number on the back. 
The strings on all the cards have the same length. 
You must choose some of these cards (at least one, possibly all) 
and place them in a row with the front sides visible, 
such that the concatenated string is a palindrome. 
A palindrome is a string that reads the same forward and backward. 
Your score is the sum of the numbers on the back sides of the chosen cards. 


You are given a vector <string> front and a vector <int> back 
describing the set of cards you are given. 
The i-th card has front[i] written on the front and back[i] on the back. 
Return the maximum possible score you can achieve with these cards. 
If it is impossible to compose a palindrome from the given cards, return 0 instead.


DEFINITION
Class:PalindromeGame
Method:getMaximum
Parameters:vector <string>, vector <int>
Returns:int
Method signature:int getMaximum(vector <string> front, vector <int> back)


CONSTRAINTS
-front will contain between 1 and 50 elements, inclusive. 
-Each element of front will contain between 1 and 50 characters, inclusive. 
-Each element of front will contain the same number of characters. 
-Each character in front will be a lowercase letter ('a' - 'z'). 
-front and back will contain the same number of elements. 
-Each element of back will be between 1 and 1,000,000, inclusive. 


EXAMPLES

0)
{ "topcoder", "redcoder", "redocpot" }
{ 7, 5, 3 }

Returns: 10

You?can?choose?"topcoder"?with?7?and?"redocpot"?with?3?to?get?a?palindrome?"topcoderredocpot". 


1)
{ "rabbit" }
{ 1000000 }

Returns: 0

No palindrome can be made. 


2)
{ "abc", "abc", "def", "cba", "fed" }
{ 24, 7, 63, 222, 190 }

Returns: 499

*/
// END CUT HERE
#line 67 "PalindromeGame.cpp"
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
std::ostream& operator<<(std::ostream& os, const vector<T>& v)
{
	for( int i = 0; i < v.size(); i++ )
	{
		os << v[i] << " ";
	}
	return os;
}


class PalindromeGame {
	public:
	int isV(string& s)
	{
		int a = s.size() / 2;
		REP(i, a) if(s[i]!=s[s.size()-i-1]) return 0;
		return 1;
	}
	int isPair(string& a, string& b)
	{
		REP(i, a.SZ) if(a[i]!=b[a.SZ-i-1]) return 0;
		return 1;
	}
	int getMaximum(vector <string> front, vector <int> back) {
printf("%s %d\n", __FILE__, __LINE__);
		int maxans = 0;
		REP(ca, 2)
		{
			VI used(front.SZ);
			//cout<<used<<endl;
			
			int ansv = 0;
			if(ca==0)
			{
				// find type V
				int ansv_idx = -1;
				REP(i, front.SZ) if(isV(front[i]) && ansv < back[i]) { ansv_idx = i; ansv = back[i]; };
				cout<<ansv<<endl;
				if(ansv_idx!=-1) used[ansv_idx] = 1;
			}
			//cout<<used<<endl;
			
			// find pairs
			int ansp = 0;
			REP(i, front.SZ)
			{
				int maxv_j = -1;
				int maxv = 0;
				FOR(j, i+1, front.SZ)
				{
					if(used[i]) continue;
					if(used[j]) continue;
					if(isPair(front[i], front[j]))
					{
						maxv = back[i]+back[j];
						maxv_j = j;
					}
				}
				if(maxv_j!=-1)
				{
					ansp += maxv;
					used[i] = used[maxv_j] = 1;
				}
			}
			//cout<<used<<endl;
			cout<<ca<<" "<<ansp<<endl;
			int ans = ansv + ansp;
			cout<<ca<<" "<<ans<<endl;
			if(maxans<ans) maxans = ans;
		}
		cout<<maxans<<endl;
		return maxans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "topcoder", "redcoder", "redocpot" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 7, 5, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "rabbit" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1000000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "abc", "abc", "def", "cba", "fed" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 24, 7, 63, 222, 190 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 499; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	PalindromeGame ___test;

	___test.run_test(-1);
	vector<string> a;
	a.push_back("a");
	a.push_back("b");
	a.push_back("a");
	a.push_back("a");
	vector<int> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	___test.getMaximum(a, b);

}

// END CUT HERE
