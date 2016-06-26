// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There is an infinite labyrinth somewhere on Earth. It has an infinite number of rows, a fixed number W of columns and consists of 1x1 cells. 
Each cell can be in one of three states: free cell with a teleport, free cell without a teleport and blocked cell. It is known that each row in the labyrinth
contains either 0 or 2 cells with teleports.
The rows and columns of the labyrinth are numbered using integers. The rows are infinite in both directions, so for every integer i (including negative integers) there's a row numbered i. The columns are numbered 0 to W-1, inclusive. A cell in row i and column j is denoted as (i,j).
If you are located in a free cell (i,j), you can perform one of the following actions:

Walk to another free cell (x,y) adjacent by side to (i,j). In other words, (x,y) must be such that |i-x| + |j-y| = 1. It is impossible to walk outside of the labyrinth.
If cell (i,j) contains a teleport, you can use it to be transferred to another free cell from the same row that contains a teleport (there's always exactly one such cell). Note that when you are located in a cell with a teleport, it isn't necessary to use the teleport.

Each of the described two actions, that is, walking to an adjacent cell and using a teleport, counts as one move.
You are given a vector <string> map containing H rows, with each element consisting of W characters. The character j in element i of map represents the state of cell (i,j), where '#' means a blocked cell, '.' means a free cell and 'T' means a free cell with a teleport. Both indices i and j are 0-based, so map describes the states of all cells in rows 0 to H-1, inclusive. For all other cells the following rule applies: the state of cell (i,j) is exactly the same as the state of cell (x,j) if |i-x| is
divisible by H. In other words, the given pattern of H rows is repeated an infinite number
of times.
Return the minimum number of moves needed to get from cell (r1,c1) to cell (r2,c2). If it is impossible, return -1.


DEFINITION
Class:InfiniteLab
Method:getDistance
Parameters:vector <string>, long long, int, long long, int
Returns:long long
Method signature:long long getDistance(vector <string> map, long long r1, int c1, long long r2, int c2)


NOTES
-The start and finish cells (r1,c1) and (r2,c2) are guaranteed to be distinct free cells.


CONSTRAINTS
-map will contain between 1 and 20 elements, inclusive.
-Each element of map will contain between 1 and 20 characters, inclusive.
-All elements of map will contain the same number of characters.
-Each character in map will be either '#', '.' or 'T'.
-Each element of map will contain either 0 or 2 'T' characters.
-r1 and r2 will each be between -10^15 and 10^15, inclusive.                                        
-c1 and c2 will each be between 0 and W-1, inclusive, where W is the number of characters in each element of map.                                               
-Cells (r1,c1) and (r2,c2) will both be free cells.
-Cells (r1,c1) and (r2,c2) will be distinct.


EXAMPLES

0)
{"#...##",
 ".##...",
 "..#.##",
 "#.#.##"}
1
0
5
3

Returns: 7

The optimal path is drawn below. Here 'S' means the start cell, 'F' means the finish cell and 'P' means an intermediate cell.

#...##
S##...
PP#.##
#P#.##
#PPP##
.##F..
..#.##
#.#.##

Note that the labyrinth is infinite, so only its part with rows 0 to 7, inclusive, is shown here and in subsequent examples.

1)
{"##.#.",
 ".#T#T",
 "...#.",
 "##.#."}
7
4
1
0

Returns: 9


##.#.
F#T#T
PPP#.
##P#.
##P#.
.#T#T
...#P
##.#S

Here we need to use a teleport once.

2)
{"..######.#",
 ".###T###.T",
 "..T#.##T##",
 ".######..#"}
1
0
6
4

Returns: 11


..######.#
S###T###.T
PPT#.##T##
.######PP#
..######P#
.###T###PT
..T#F##T##
.######..#

Here we need to use a teleport twice.

3)
{"..#..",
 ".#.#.",
 "....."}
-29
2
19
2

Returns: 54



4)
{".#.#.",
 "..#..",
 ".....",
 ".....",
 "..#.."}
-999
3
100
2

Returns: -1



*/
// END CUT HERE
#line 150 "InfiniteLab.cpp"
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


class InfiniteLab {
	public:
	long long getDistance(vector <string> map, long long r1, int c1, long long r2, int c2) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#...##",
 ".##...",
 "..#.##",
 "#.#.##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; int Arg2 = 0; long long Arg3 = 5LL; int Arg4 = 3; long long Arg5 = 7LL; verify_case(0, Arg5, getDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"##.#.",
 ".#T#T",
 "...#.",
 "##.#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; int Arg2 = 4; long long Arg3 = 1LL; int Arg4 = 0; long long Arg5 = 9LL; verify_case(1, Arg5, getDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"..######.#",
 ".###T###.T",
 "..T#.##T##",
 ".######..#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; int Arg2 = 0; long long Arg3 = 6LL; int Arg4 = 4; long long Arg5 = 11LL; verify_case(2, Arg5, getDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {"..#..",
 ".#.#.",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = -29LL; int Arg2 = 2; long long Arg3 = 19LL; int Arg4 = 2; long long Arg5 = 54LL; verify_case(3, Arg5, getDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {".#.#.",
 "..#..",
 ".....",
 ".....",
 "..#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = -999LL; int Arg2 = 3; long long Arg3 = 100LL; int Arg4 = 2; long long Arg5 = -1LL; verify_case(4, Arg5, getDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	InfiniteLab ___test;

	___test.run_test(-1);

}

// END CUT HERE
