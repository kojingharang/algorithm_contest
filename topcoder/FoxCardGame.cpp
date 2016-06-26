// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Jiro and Haruko play a game with two piles of cards: pile A and pile B. Pile A and pile B contain same number of cards. Each card contains a real number between 1.0 and 100.0. Initially, the two players have 0 points. Then they repeat following operations exactly k times:


They choose two cards from the piles (one from pile A and another from pile B).
The choosen cards are removed from the piles. 
Jiro earns max{a+b, a*b} points and Haruko earns min{a+b, a*b} points (where a and b are the numbers written on the two cards that were removed).


You are given a vector <double> pileA, a vector <double> pileB, and an int k. Return the maximal possible value of (Jiro's points) / (Haruko's points).

DEFINITION
Class:FoxCardGame
Method:theMaxProportion
Parameters:vector <double>, vector <double>, int
Returns:double
Method signature:double theMaxProportion(vector <double> pileA, vector <double> pileB, int k)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-pileA and pileB will contain between 1 and 50 elements, inclusive.
-pileA and pileB will contain the same number of elements.
-Each element of pileA and pileB will be between 1.0 and 100.0, inclusive.
-k will be between 1 and the number of elements in pileA, inclusive.


EXAMPLES

0)
{1, 2, 3}
{4, 5, 6}
2

Returns: 1.7692307692307692


Choosing cards with numbers 3 and 6, Jiro earns 3*6 = 18 points and Haruko earns 3+6 = 9 points.
Choosing cards with numbers 1 and 4, Jiro earns 1+4 = 5 points and Haruko earns 1*4 = 4 points.

So the solution is (18+5) / (9+4) = 1.769230...

1)
{1.234, 5.678, 9.012, 3.456, 7.89}
{2.345, 6.789, 9.876, 5.432, 1.012}
3

Returns: 4.159424420079523



2)
{1, 1.1, 1.2, 1.3, 1.4, 1.5}
{5, 10, 15, 20, 25, 30}
2

Returns: 1.3972602739726028



3)
{85.302, 92.798, 76.813, 37.994, 36.737, 98.659}
{13.352, 7.3094, 54.761, 8.2706, 63.223, 37.486}
3

Returns: 33.58603889836175



*/
// END CUT HERE
#line 78 "FoxCardGame.cpp"
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


class FoxCardGame {
	public:
	double theMaxProportion(vector <double> pileA, vector <double> pileB, int k) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { double Arr0[] = {1, 2, 3}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {4, 5, 6}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; double Arg3 = 1.7692307692307692; verify_case(0, Arg3, theMaxProportion(Arg0, Arg1, Arg2)); }
	void test_case_1() { double Arr0[] = {1.234, 5.678, 9.012, 3.456, 7.89}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {2.345, 6.789, 9.876, 5.432, 1.012}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; double Arg3 = 4.159424420079523; verify_case(1, Arg3, theMaxProportion(Arg0, Arg1, Arg2)); }
	void test_case_2() { double Arr0[] = {1, 1.1, 1.2, 1.3, 1.4, 1.5}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {5, 10, 15, 20, 25, 30}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; double Arg3 = 1.3972602739726028; verify_case(2, Arg3, theMaxProportion(Arg0, Arg1, Arg2)); }
	void test_case_3() { double Arr0[] = {85.302, 92.798, 76.813, 37.994, 36.737, 98.659}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {13.352, 7.3094, 54.761, 8.2706, 63.223, 37.486}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; double Arg3 = 33.58603889836175; verify_case(3, Arg3, theMaxProportion(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	FoxCardGame ___test;

	___test.run_test(-1);

}

// END CUT HERE
