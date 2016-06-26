// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel likes sequences.  One day, she invented a new type of sequence and named it the fox sequence.  A sequence seq containing N elements is called a fox sequence if and only if there exist four integers a, b, c and d such that 0 < a < b <= c < d < N-1 and the following five conditions are met:

seq[0], seq[1], ... , seq[a] forms an arithmetic progression with a positive common difference.  An arithmetic progression is a sequence where the difference between successive elements is equal.  The difference between successive elements is called the common difference.  Note that 0 is neither positive nor negative.
seq[a], seq[a+1], ... , seq[b] forms an arithmetic progression with a negative common difference.
seq[b], seq[b+1], ... , seq[c] are all equal.
seq[c], seq[c+1], ... , seq[d] forms an arithmetic progression with a positive common difference.
seq[d], seq[d+1], ... , seq[N-1] forms an arithmetic progression with a negative common difference.


In the following image, the top 3 sequences are fox sequences, while the bottom 3 sequences are not:



You are given a sequence seq.  Return "YES" if it is a fox sequence, or "NO" if it is not (all quotes for clarity).

DEFINITION
Class:FoxSequence
Method:isValid
Parameters:vector <int>
Returns:string
Method signature:string isValid(vector <int> seq)


CONSTRAINTS
-seq will contain between 1 and 50 elements, inclusive.
-Each element of seq will be between 1 and 2,000, inclusive.


EXAMPLES

0)
{1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}


Returns: "YES"

This is the top-left sequence of the image shown in the statement.  The next five examples are also from that image.

1)
{1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}


Returns: "YES"



2)
{3,6,9,1,9,5,1}


Returns: "YES"



3)
{1,2,3,2,1,2,3,2,1,2,3,2,1}


Returns: "NO"



4)
{1,3,4,3,1,1,1,1,3,4,3,1}


Returns: "NO"



5)
{6,1,6}


Returns: "NO"



*/
// END CUT HERE
#line 85 "FoxSequence.cpp"
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


class FoxSequence {
	public:
	string isValid(vector <int> seq) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isValid(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, isValid(Arg0)); }
	void test_case_2() { int Arr0[] = {3,6,9,1,9,5,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isValid(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,3,2,1,2,3,2,1,2,3,2,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, isValid(Arg0)); }
	void test_case_4() { int Arr0[] = {1,3,4,3,1,1,1,1,3,4,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, isValid(Arg0)); }
	void test_case_5() { int Arr0[] = {6,1,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(5, Arg1, isValid(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	FoxSequence ___test;

	___test.run_test(-1);

}

// END CUT HERE
