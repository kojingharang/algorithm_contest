// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.


There is a kingdom with N cities numbered 0 through N-1. Gogo wants to survey several cities in the kingdom. These cities are described in vector <int> cities containing M elements. He wishes to survey city cities[0], city cities[1], ..., city cities[M-1] in this exact order (i.e., before surveying city cities[i], he must have finished surveying cities cities[0], ..., cities[i-1] in this order). He starts at city 0 and can end at any city.  He may only survey a city when he's inside the city. There are several bidirectional roads, each connecting two different cities and costing some amount of money to traverse. Note that he may wish to survey the same city multiple times.


Gogo also has a time machine. He can use the time machine to go back in time, without affecting which cities he is considered to have already surveyed. For example, suppose he has visited cities A, B, C, D, and E, in that order, and is currently in city E. He can use the time machine to go back to city A, B, C, or D. Suppose he chooses to go back to city C. At that point, he can then go back further to city A or B, but he cannot use the time machine to go forward to city D or E. Note that if he had surveyed city E, going back in time will not change the fact that he is considered to have already surveyed city E.


You are given the roads in the vector <string> roads. Concatenate the elements of roads, in order, to get a single space-separated list of roads. Each road will be formatted "a,b,travelcost" (quotes for clarity), which means that the bidirectional road connects city a and city b, and costs travelcost to traverse.


He can use the time machine any number of times, and it costs nothing to use it. Return the minimum cost required to survey all cities from cities in the given order. Return -1 if it is impossible to survey them all.

DEFINITION
Class:TimeTravellingTour
Method:determineCost
Parameters:int, vector <int>, vector <string>
Returns:long long
Method signature:long long determineCost(int N, vector <int> cities, vector <string> roads)


NOTES
-Surveying a city does not incur any cost.


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-cities will contain between 1 and 50 elements, inclusive.
-Each element of cities will be between 0 and N-1, inclusive.
-No two consecutive elements in cities will be identical.
-cities[0] will not be 0.
-roads will contain between 1 and 50 elements, inclusive.
-Each element of roads will contain between 1 and 50 characters, inclusive.
-Each character in roads will be '0'-'9', ' ', or ','.
-roads will be formatted as described in the problem statement without leading or trailing spaces.
-All integers in the concatenation of all the elements of roads in the order they are given will have no leading zeroes.
-In each road, a and b as described in the problem statement will be different and will each be between 0 and N-1, inclusive.
-In each road, travelcost as described in the problem statement will be between 1 and 10,000,000, inclusive.
-For each two different cities, there will be at most one road connecting them.


EXAMPLES

0)
5
{2,3,2,4}
{"0,2,4 0,1,2 2,1,2 1,3,3 4,0,4"}

Returns: 13



Travel from city 0 to city 1 to city 2. Survey city 2. Go back in time to city 1. Travel from city 1 to city 3. Survey city 3. Go back in time to city 1. Travel from city 1 to city 2. Survey city 2. Go back in time to city 0. Travel from city 0 to city 4. Survey city 4. The total cost is 2+2+3+2+4=13.

1)
3
{1,0,1}
{"0,2,1"," 2",",1,5"}

Returns: 12



Travel from city 0 to city 2 to city 1. Survey city 1. Go back in time to city 0. Survey city 0. Travel from city 0 to city 2 to city 1. Survey city 1.

2)
3
{2}
{"0,1,2"}

Returns: -1



It is not possible to reach city 2.

3)
6
{4, 1, 3, 2}
{"0,1,5 0,2,5 0,5,2 2,3,5 2,4,2 3,4,4 3,5,1"}

Returns: 19




Travel from city 0 to city 2 to city 4. Survey city 4. Travel from city 4 to city 3 to city 5 to city 0 to city 1. Survey city 1. Go back in time to city 3. Survey city 3. Go back in time to city 2. Survey city 2. The total cost is 5+2+4+1+2+5=19

*/
// END CUT HERE
#line 96 "TimeTravellingTour.cpp"
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


class TimeTravellingTour {
	public:
	long long determineCost(int N, vector <int> cities, vector <string> roads) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {2,3,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0,2,4 0,1,2 2,1,2 1,3,3 4,0,4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 13LL; verify_case(0, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0,2,1"," 2",",1,5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 12LL; verify_case(1, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0,1,2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = -1LL; verify_case(2, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arr1[] = {4, 1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0,1,5 0,2,5 0,5,2 2,3,5 2,4,2 3,4,4 3,5,1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 19LL; verify_case(3, Arg3, determineCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	TimeTravellingTour ___test;

	___test.run_test(-1);

}

// END CUT HERE
