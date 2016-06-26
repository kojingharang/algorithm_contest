// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Ms. Ciel loves rabbits. She has a large special cage for her rabbits. The cage is protected by a special lock: a board containing a grid.



The board contains an N times M grid.
We can assign integer coordinates to the vertices of the grid.
(Vertices are the points where horizontal and vertical grid lines intersect.)
The top left corner of the grid will get the coordinates (0,0) and the bottom right corner coordinates (N,M).
Each line segment between two adjacent vertices is labeled by an integer from 0 to 9, inclusive.
You are given two vector <string>s horizontal and vertical containing these labels in the format defined below.

For all i, j such that 0 <= i <= N and 0 <= j <= M-1, there is a line segment between the points (i,j) and (i,j+1).
This line segment has the label horizontal[i][j].
For all i, j such that 0 <= i <= N-1 and 0 <= j <= M, there is a line segment between the points (i,j) and (i+1,j).
This line segment has the label vertical[i][j].




To unlock this board, you must put your finger on the point (0, 0), and move to the point (N, M).
In each step you can only go down or right.
I.e., if you are currently at the point (i,j), your next step may take you either to (i,j+1), or to (i+1,j).
By moving your finger you picked one of the paths from the top left to the bottom right corner.
The path consists of N+M line segments, and each of those line segments has an integer label.
The cost of a path is the sum of those labels.
Let S be the smallest value among the costs of all valid paths from the top left to the bottom right corner.
Inside the board there is a counter that computes the sum of all numbers that are on the line segments you used in your path.
The lock will open if and only if you picked a path with cost exactly S, i.e., a path with the smallest possible cost.



Finding the way to unlock a given board is a shortest path problem.
You could surely solve it, but Ciel is just a young fox.
She does not know any complicated algorithms such as Dijkstra, Bellman-Ford, or Floyd-Warshall.
Thus unlocking the board is too hard for her.
She wants you to modify her board to a state in which it can be unlocked by any path from the top left to the bottom right corner.
In other words, on the resulting board all valid paths must have exactly the same cost T. 
The only allowed operation is to increase some of the labels.
(The new labels must again be integers, but they are allowed to exceed 9.)
Compute and return the smallest possible value of T.

DEFINITION
Class:PasswordXGrid
Method:minSum
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int minSum(vector <string> horizontal, vector <string> vertical)


NOTES
-Note that Ciel can always achieve her goal: for example, she can increase every number to X, where X is the maximal number over all numbers on the board.


CONSTRAINTS
-N and M will be between 1 and 40, inclusive.
-horizontal will contain N+1 elements.
-Each element of horizontal will contain M characters.
-vertical will contain N elements.
-Each element of vertical will contain M+1 characters.
-Each character in each element of horizontal and vertical will be a digit: '0'-'9'.


EXAMPLES

0)
{"1","4"}
{"32"}

Returns: 7

We have two possible paths.
One of them has the cost 1+2 = 3, the other one 3+4 = 7.
As the costs are not equal, we have to modify some of the labels.
One possible solution is to increase the label 1 to 5.
Then both paths have the same cost: 7.

1)
{"47", "59"}
{"361"}

Returns: 19

This is how the grid looks like:

+--4--+--7--+
|     |     |
3     6     1
|     |     |
+--5--+--9--+

One possible solution is to increase 3 to 5 and 7 to 14.

2)
{"36", "23", "49"}
{"890", "176"}

Returns: 28



3)
{"8888585","5888585"}
{"58585858"}

Returns: 58



4)
{"7777777","7777777","7777777","7777777"}
{"44444444","44444444","44444444"}

Returns: 61



*/
// END CUT HERE
#line 123 "PasswordXGrid.cpp"

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
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T> v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class PasswordXGrid {
	public:
	int minSum(vector <string> H, vector <string> V) {
		int N=H.size()-1;
		int M=H[0].size();
		VVI m(N+1, VI(M+1));
		cout<<M<<" "<<N<<endl;
		REP(y, N+1) {
			REP(x, M+1) {
				if(x-1>=0) m[y][x] = max(m[y][x], m[y][x-1]+H[y][x-1]-'0');
				if(y-1>=0) m[y][x] = max(m[y][x], m[y-1][x]+V[y-1][x]-'0');
			}
		}
		//cout<<m<<endl;
		return m[N][M];
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//mplate<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// os << "{ ";
// for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
// os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, PasswordXGrid().minSum(horizontal, vertical));}
int main(){

CASE(0)
	string horizontal_[] = {"1","4"};
	  vector <string> horizontal(horizontal_, horizontal_+sizeof(horizontal_)/sizeof(*horizontal_)); 
	string vertical_[] = {"32"};
	  vector <string> vertical(vertical_, vertical_+sizeof(vertical_)/sizeof(*vertical_)); 
	int _ = 7; 
END
//return 0;
CASE(1)
	string horizontal_[] = {"47", "59"};
	  vector <string> horizontal(horizontal_, horizontal_+sizeof(horizontal_)/sizeof(*horizontal_)); 
	string vertical_[] = {"361"};
	  vector <string> vertical(vertical_, vertical_+sizeof(vertical_)/sizeof(*vertical_)); 
	int _ = 19; 
END
CASE(2)
	string horizontal_[] = {"36", "23", "49"};
	  vector <string> horizontal(horizontal_, horizontal_+sizeof(horizontal_)/sizeof(*horizontal_)); 
	string vertical_[] = {"890", "176"};
	  vector <string> vertical(vertical_, vertical_+sizeof(vertical_)/sizeof(*vertical_)); 
	int _ = 28; 
END
CASE(3)
	string horizontal_[] = {"8888585","5888585"};
	  vector <string> horizontal(horizontal_, horizontal_+sizeof(horizontal_)/sizeof(*horizontal_)); 
	string vertical_[] = {"58585858"};
	  vector <string> vertical(vertical_, vertical_+sizeof(vertical_)/sizeof(*vertical_)); 
	int _ = 58; 
END
CASE(4)
	string horizontal_[] = {"7777777","7777777","7777777","7777777"};
	  vector <string> horizontal(horizontal_, horizontal_+sizeof(horizontal_)/sizeof(*horizontal_)); 
	string vertical_[] = {"44444444","44444444","44444444"};
	  vector <string> vertical(vertical_, vertical_+sizeof(vertical_)/sizeof(*vertical_)); 
	int _ = 61; 
END
CASE(4)
	string horizontal_[] = {
		"0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000",
		"0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000",
		"0000000000090000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000",
		"0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000","0000000000000000000000000000000000000000",
		"0000000000000000000000000000000000000000"
	};
	  vector <string> horizontal(horizontal_, horizontal_+sizeof(horizontal_)/sizeof(*horizontal_)); 
	string vertical_[] = {
		"90000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000",
		"00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000",
		"00000000000000000700000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000",
		"00080000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000","00000000000000000000000000000000000000000",
	};
	  vector <string> vertical(vertical_, vertical_+sizeof(vertical_)/sizeof(*vertical_)); 
	int _ = 0; 
END

}
// END CUT HERE
