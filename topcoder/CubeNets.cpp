// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// In geometry a cube net is an arrangement of identical edge-joined squares in the plane which can be folded (along the edges) to become the faces of a cube.

In this problem you need to check if the given figure is a cube net. The given figure will be a union of six identical squares lying in the same plane and will be given to you as a vector <string> figure. Each element of figure will consist of '.' (dot) and '#' (sharp) characters only. A sharp represents one of the six squares, whereas a dot represents an empty space. Return "YES" if figure represents a cube net, or "NO" otherwise (all quotes for clarity).

DEFINITION
Class:CubeNets
Method:isCubeNet
Parameters:vector <string>
Returns:string
Method signature:string isCubeNet(vector <string> figure)


CONSTRAINTS
-figure will contain between 1 and 6 elements, inclusive.
-Each element of figure will contain between 1 and 6 characters, inclusive.
-Each element of figure will contain '.' (dot) and '#' (sharp) characters only.
-All elements of figure will contain the same number of characters.
-There will be exactly 6 '#' (sharp) characters among all the elements of figure.


EXAMPLES

0)
{"..#.",
 "####",
 "..#."}

Returns: "YES"

Here you can first fold across all the vertical edges to make the middle four squares become the down, right, up and left faces of the cube-to-be. One then finishes off the construction by folding across the remaining two edges to make the other two squares become the front and back faces of the cube.

1)
{"###",
 "###"}

Returns: "NO"

This is not a cube net.

2)
{"..#.",
"####",
".#.."}

Returns: "YES"



3)
{"##..",
 ".##.",
 "..##"}

Returns: "YES"



4)
{"####",
 "...#",
 "...#"}

Returns: "NO"



*/
// END CUT HERE
#line 73 "CubeNets.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

int f(int x, int y, vector<string>& fig, VI& w) {
	//cout<<x<<" "<<y<<" "<<fig[y][x]<<endl;
	fig[y][x]='-';
	int dx[4]={-1, 1, 0, 0};
	int dy[4]={0, 0, -1, 1};
	int rot[4][6]={
		{2,3,1,0,4,5}, //left
		{3,2,0,1,4,5}, //right
		{5,4,2,3,0,1}, //up
		{4,5,2,3,1,0}, //down
	};
	if(w[0]) return 0;
	w[0]=1;
	if(accumulate(ALL(w), 0)==6) return 1;
	REP(i, 4) {
		int yy=y+dy[i];
		int xx=x+dx[i];
		VI nw(6);
		REP(j, 6) nw[rot[i][j]]=w[j];
		if(0<=yy && yy<fig.size() && 0<=xx && xx<fig[0].size() && fig[yy][xx]=='#') if(f(xx, yy, fig, nw)) return 1;
		REP(j, 6) w[j]=nw[rot[i][j]];
	}
	return 0;
}

class CubeNets {
	public:
	string isCubeNet(vector <string> fig) {
		VI w(6);
		REP(y, fig.size()) REP(x, fig[0].size()) if(fig[y][x]=='#') return f(x, y, fig, w) ? "YES":"NO";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..#.",
 "####",
 "..#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isCubeNet(Arg0)); }
	void test_case_1() { string Arr0[] = {"###",
 "###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(1, Arg1, isCubeNet(Arg0)); }
	void test_case_2() { string Arr0[] = {"..#.",
"####",
".#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isCubeNet(Arg0)); }
	void test_case_3() { string Arr0[] = {"##..",
 ".##.",
 "..##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(3, Arg1, isCubeNet(Arg0)); }
	void test_case_4() { string Arr0[] = {"####",
 "...#",
 "...#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, isCubeNet(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	CubeNets ___test;

	___test.run_test(-1);

}

// END CUT HERE
