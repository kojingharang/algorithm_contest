// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A prefix tree (also called trie) is a rooted tree data structure used to efficiently store a set of words, S. In a trie every edge has a letter associated with it. Every node in the trie is associated with the string which we get when we read all the edge letters on the path from the root to this node. So the root of the trie is associated with the empty string and every leaf of the trie is associated with some word from S.

A trie is constructed so that from each node at most one child edge is associated with each letter. So not only do all the descendants of a node have a common prefix (which is the string associated with this node) but also every word with this string as prefix is the descendant of this node. It is necessary that for every word from S there is a node in trie with which is this word associated.

An example of a trie for the set of words {"aab", "ca"}:


It is not hard to see that if we change the order of letters in the given words then we will get a different trie (constructed from these different words) which might possibly have fewer nodes.
For example the trie constructed from words {"aab","ca"} would have 6 nodes (see image above), but if we change "ca" to "ac" then the trie would have only 5 nodes:


Given vector <string> words which represents the set of words. You are allowed to permute the letters in each word in any way you like. Find the optimal permutation of the letters of the words so the trie constructed from them would have the minimal number of nodes. Return this number of nodes.

DEFINITION
Class:PrefixTree
Method:getNumNodes
Parameters:vector <string>
Returns:int
Method signature:int getNumNodes(vector <string> words)


CONSTRAINTS
-words will contain between 1 and 16 elements, inclusive.
-Each element of words will contain between 1 and 50 characters.
-Each element of words will consist of lowercase letters ('a'-'z').


EXAMPLES

0)
{"topcoder"}

Returns: 9

With only one word, every permutation gives the same answer.

1)
{"topcoder","topcoder"}

Returns: 9

Words in the input can repeat. The optimal permutation is the one in which the words are equal.

2)
{"aab","ca"}

Returns: 5

Example from the problem statement. The optimum is if we change "ca" to "ac".

3)
{"aab","ca","ba"}

Returns: 5

The optimum is when the words are: "aba", "ac", "ab".

4)
{"ab","cd","ef"}

Returns: 7

Sometimes nothing can be optimized.

5)
{"a","aa","aaa"}

Returns: 4

One word can be also a prefix of another word.

*/
// END CUT HERE
#line 78 "PrefixTree.cpp"
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


class PrefixTree {
	public:
	int getNumNodes(vector <string> words) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(0, Arg1, getNumNodes(Arg0)); }
	void test_case_1() { string Arr0[] = {"topcoder","topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(1, Arg1, getNumNodes(Arg0)); }
	void test_case_2() { string Arr0[] = {"aab","ca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, getNumNodes(Arg0)); }
	void test_case_3() { string Arr0[] = {"aab","ca","ba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, getNumNodes(Arg0)); }
	void test_case_4() { string Arr0[] = {"ab","cd","ef"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, getNumNodes(Arg0)); }
	void test_case_5() { string Arr0[] = {"a","aa","aaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(5, Arg1, getNumNodes(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	PrefixTree ___test;

	___test.run_test(-1);

}

// END CUT HERE
