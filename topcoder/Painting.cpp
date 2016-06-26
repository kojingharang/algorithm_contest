// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Normally Mr. Grey is not a painter, but he recently had an absolutely brilliant idea for a picture. He thinks that once drawn, it will bring him world-wide fame.

The picture will be painted on an NxM sheet of white paper consisting of 1x1 squares. Its rows are numbered from 0 to N-1 and the columns are numbered from 0 to M-1. The cell in row i, column j is denoted as (i, j).

Of course, Mr. Grey already has a picture plan in his mind. It is given in a vector <string> picture, which contains exactly N elements, where each element contains exactly M characters. „Rharacter j in element i of picture will be 'B' if the cell (i, j) must be painted black, and it will be 'W' if this cell must be left white.

Mr. Grey has a lot of black paint, but unfortunately he doesn't have a brush, so he went to a local shop to buy one. The shop offers square brushes of different sizes. More exactly, for each positive integer S, one can buy an SxS brush in the shop. Using an SxS brush, Mr. Grey will be able to paint entirely black SxS squares on the sheet of paper. In other words, he can choose row R and column C such that 0 <= R <= N - S, 0 <= C <= M - S, and then paint all cells (r, c) such that R <= r < R + S and C <= c < C + S in black paint. He can repeat this operation infinitely many times. If a cell must be black according to picture, it may be painted black several times. However, if a cell must be white, then it must never be painted black.

It's easy to see that every picture can be drawn using a 1x1 brush, but it will be impossible to draw some pictures using larger brushes. Buying a 1x1 brush seems to be the most practical choice. However, Mr. Grey is sure that big masters must use big brushes. Therefore, he would like to buy the largest possible brush that will still allow him to draw the picture that he has in mind.

Return the maximum value of S such that it's possible to draw picture using a brush of size SxS.

DEFINITION
Class:Painting
Method:largestBrush
Parameters:vector <string>
Returns:int
Method signature:int largestBrush(vector <string> picture)


CONSTRAINTS
-picture will contain between 1 and 50 elements, inclusive.
-Each element of picture will contain between 1 and 50 characters, inclusive.
-All elements of picture will contain the same number of characters.
-Each character in picture will be 'B' or 'W'.
-There will be at least one 'B' character in picture.


EXAMPLES

0)
{"BBBB",
 "BBBB",
 "BBBB",
 "BBBB"}

Returns: 4

It's easy to see that a solid 4x4 black square can be drawn using a 4x4 brush.

1)
{"BBBB",
 "BWWB",
 "BWWB",
 "BBBB"}

Returns: 1

This time we have only a border of a 4x4 square and it's necessary to have a 1x1 brush in order to draw it.

2)
{"WBBBBB",
 "BBBBBB",
 "BBBBBB",
 "BBBBBB"}


Returns: 3

A completely black 4x6 rectangle can be drawn using a 4x4 brush. However, if we want just one cell within it to remain white, the size of the brush will have to be reduced. In this example, a 3x3 brush would work.

3)
{"BBBB",
 "BBBB",
 "WBBB",
 "BBBB",
 "BBBB",
 "BBBB"}


Returns: 2

This is very similar to the previous example, but the white cell is in a different location. Mr. Grey will have to buy a 2x2 brush in this case.

4)
{"WBBBBBWWWWWWWWW",
 "WBBBBBBWWWWWWWW",
 "WBBBBBBBBBBBWWW",
 "WBBBBBBBBBBBWWW",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBWWBBBBB",
 "BBBBBBBBWBBBBBB",
 "WBBBBBBBWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBWWWBBBBBW",
 "BBBBBWWWWWWWWWW",
 "BBBBBWWWWWWWWWW"}


Returns: 5



*/
// END CUT HERE
#line 103 "Painting.cpp"
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


class Painting {
	public:
	int largestBrush(vector <string> p) {
printf("%s %d\n", __FILE__, __LINE__);
		int maxs = min(p[0].SZ, p.SZ);
		int ans = maxs;
		FORD(s, maxs, 1)
		{
			if(s==1) return s;
			REP(y, p.SZ-s+1)
			{
				REP(x, p[0].SZ-s+1)
				{
					int lok = 1;
					REP(xx, s) REP(yy, s) { if(p[y+yy][x+xx]=='W') lok=0; }
					if(lok)
					{
						REP(xx, s) REP(yy, s) { p[y+yy][x+xx]='O'; }
						cout<<x<<" "<<y<<endl;
						REP(zy, p.SZ) cout<<p[zy]<<endl;
					}
				}
			}
			int ok = 1;
			REP(y, p.SZ) REP(x, p[0].SZ) if(p[y][x]=='B') ok=0;
			if(ok) {ans = s; break;}
			cout<<"NO"<<endl;
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BBBB",
 "BBBB",
 "BBBB",
 "BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, largestBrush(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBBB",
 "BWWB",
 "BWWB",
 "BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, largestBrush(Arg0)); }
	void test_case_2() { string Arr0[] = {"WBBBBB",
 "BBBBBB",
 "BBBBBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, largestBrush(Arg0)); }
	void test_case_3() { string Arr0[] = {"BBBB",
 "BBBB",
 "WBBB",
 "BBBB",
 "BBBB",
 "BBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, largestBrush(Arg0)); }
	void test_case_4() { string Arr0[] = {"WBBBBBWWWWWWWWW",
 "WBBBBBBWWWWWWWW",
 "WBBBBBBBBBBBWWW",
 "WBBBBBBBBBBBWWW",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBWWBBBBB",
 "BBBBBBBBWBBBBBB",
 "WBBBBBBBWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBWWWBBBBBW",
 "BBBBBWWWWWWWWWW",
 "BBBBBWWWWWWWWWW"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, largestBrush(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	Painting ___test;

	___test.run_test(-1);

}

// END CUT HERE
