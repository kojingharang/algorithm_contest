// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A new starport has just started working. Starting from some moment of time (call it minute 0), a new spaceship arrives at the starport every M minutes. In other words, spaceships arrive at the starport at minutes 0, M, 2*M, 3*M and so on. 

Similarly, starting from minute 0 and repeating each N minutes, all arrived spaceships that are still placed at the port are teleported to the shed. If a spaceship arrives at the exact same minute when such a teleportation happens, it will be teleported immediately. Otherwise it will need to wait until the next teleportation happens.

Let the waiting time of a spaceship be the time between its arrival and its teleportation to the shed. Return the average waiting time of a spaceship in minutes. See notes for an exact definition.


DEFINITION
Class:Starport
Method:getExpectedTime
Parameters:int, int
Returns:double
Method signature:double getExpectedTime(int N, int M)


NOTES
-Let W(i) be the waiting time for the spaceship that arrives at minute M * i. The average waiting time can be defined as the limit of (W(0) + W(1) + ... + W(P - 1)) / P when P tends to positive infinity. This limit will always exist.
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-N and M will each be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
4
2

Returns: 1.0

Spaceships arrive at the starport at minutes 0, 2, 4, 6, 8, and so on. Teleportations are done at minutes 0, 4, 8, and so on. The waiting times for the spaceships are, correspondingly, 0, 2, 0, 2, 0, and so on, so the expected waiting time is 1.

1)
5
3

Returns: 2.0



2)
6
1

Returns: 2.5



3)
12345
2345

Returns: 6170.0



*/
// END CUT HERE
#line 65 "Starport.cpp"
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


class Starport {
	public:
	double getExpectedTime(int N, int M) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; double Arg2 = 1.0; verify_case(0, Arg2, getExpectedTime(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 3; double Arg2 = 2.0; verify_case(1, Arg2, getExpectedTime(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 1; double Arg2 = 2.5; verify_case(2, Arg2, getExpectedTime(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 12345; int Arg1 = 2345; double Arg2 = 6170.0; verify_case(3, Arg2, getExpectedTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	Starport ___test;

	___test.run_test(-1);

}

// END CUT HERE
