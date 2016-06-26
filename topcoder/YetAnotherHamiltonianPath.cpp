// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A Hamiltonian path in an undirected graph with N vertices is a sequence of vertices A1, A2, ..., AN such that all Ai are pairwise distinct and for each i (1 &lt i &le N), there is an edge between vertices Ai-1 and Ai.  A path starts at vertex A1 and visits each vertex of the sequence in order, ending at vertex AN.  The cost of a path is the sum of the weights of the edges connecting the path's consecutive vertices.

You're given a graph where the i-th (0-based) vertex is labeled with string label[i]. There is an edge between each pair of vertices. The cost of the edge between vertices i and j is equal to length^2 (label[i]) + length^2 (label[j]) - length^2 (LCP (label[i], label[j]) ), where "^2" denotes squaring operation, length(X) is the length of string X and LCP(X,Y) is the longest common prefix of strings X and Y.

Return the minimum possible cost of a Hamiltonian path which starts at vertex 0 and ends at vertex 1.

DEFINITION
Class:YetAnotherHamiltonianPath
Method:leastCost
Parameters:vector <string>
Returns:int
Method signature:int leastCost(vector <string> label)


NOTES
-A prefix of string S is a string that can be obtained by removing zero or more contiguous characters from the end of S.
-The longest common prefix of two strings A and B is the longest possible string which is a prefix of both A and B.


CONSTRAINTS
-label will contain between 2 and 50 elements, inclusive.
-Each element of label will be between 1 and 50 characters long, inclusive.
-Each element of label will consist of lowercase letters ('a'-'z') only.


EXAMPLES

0)
{"home", "school", "pub"} 

Returns: 70

The only possible Hamiltonian path from vertex 0 to vertex 1 is 0->2->1. Vertex 0 is labeled "home", and vertex 1 is labeled "pub", so since these two strings have no common prefix, the cost of the edge 0->1 is 4^2+3^2=25. The cost of the edge 2->1 is 45, so the total cost of the path is 70.


1)
{"school", "home", "pub", "stadium"}

Returns: 167

Of the two possible Hamiltonian paths, the cost of the one that visits "stadium" right after "school" is 1 less than the other one's.


2)
{"abcd","aecgh","abef","aecd"}

Returns: 91

The cost matrix of this graph is:
-- 40 28 31
40 -- 40 32
28 40 -- 31
31 32 31 --

The optimal path is "abcd"->"abef"->"aecd"->"aecgh".

3)
{"canada", "cyprus", "croatia", "colombia", "chile", "china", "cameroon"}

Returns: 509



*/
// END CUT HERE
#line 70 "YetAnotherHamiltonianPath.cpp"
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


class YetAnotherHamiltonianPath {
	public:
	int leastCost(vector <string> label) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"home", "school", "pub"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 70; verify_case(0, Arg1, leastCost(Arg0)); }
	void test_case_1() { string Arr0[] = {"school", "home", "pub", "stadium"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 167; verify_case(1, Arg1, leastCost(Arg0)); }
	void test_case_2() { string Arr0[] = {"abcd","aecgh","abef","aecd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 91; verify_case(2, Arg1, leastCost(Arg0)); }
	void test_case_3() { string Arr0[] = {"canada", "cyprus", "croatia", "colombia", "chile", "china", "cameroon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 509; verify_case(3, Arg1, leastCost(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	YetAnotherHamiltonianPath ___test;

	___test.run_test(-1);

}

// END CUT HERE
