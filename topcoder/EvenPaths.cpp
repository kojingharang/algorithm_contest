// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Cucumberman built a maze. The maze consists of rooms and one-directional corridors. Each corridor leads from one room to another. Rooms are numbered 0 through N-1, where N is the number of rooms. The maze has a special property: for each room X, once you leave room X (by using one of the corridors), you will never be able to get back to room X.


The layout of the maze is described by a vector <string> maze. The j-th character of the i-th element of maze will be 'Y' if there is a one-directional corridor from room i to room j, and it will be 'N' otherwise. You are also given a string rooms. Some rooms may contain an obstacle. A room with an obstacle cannot be entered. If the i-th character of rooms is '?', room i may contain an obstacle. If it is '-', room i doesn't contain an obstacle.


Cucumberman is interested in the number of paths from room 0 to room 1 (see Notes for a formal definition). If the number of different paths is even, he calls the maze nice. There are 2^K possible states of the maze, where K is the number of '?'s in rooms. Out of these 2^K mazes, some are nice. Find and return their count.


DEFINITION
Class:EvenPaths
Method:theCount
Parameters:vector <string>, string
Returns:long long
Method signature:long long theCount(vector <string> maze, string rooms)


NOTES
-A path from room 0 to room 1 is a sequence of rooms that satisfies the following conditions:1) The first element of the sequence is room 0 and the last element of the sequence is room 1.2) For each element of the sequence (except for the last element), there is a one-directional corridor to the next element.3) No room in the sequence contains an obstacle.


CONSTRAINTS
-maze will contain between 2 and 50 elements, inclusive.
-Each element of maze will contain N characters, where N is the number of elements of maze.
-Each character in maze will be 'Y' or 'N'.
-maze will satisfy the property from the problem statement. I.e., there is no sequence of corridors that leads from some room X back to the same room X.
-maze will contain at most 500 'Y'.
-rooms will contain N characters.
-Each character in rooms will be '-' or '?'.
-The number of '?' in rooms will be between 0 and 32, inclusive.
-The first two characters of rooms will be '-'.


EXAMPLES

0)
{"NYY", "NNN", "NYN"}
"--?"

Returns: 1

If room 2 contains an obstacle, there is one path from room 0 to room 1: 0 -> 1. This is not a nice maze.

If room 2 doesn't contain an obstacle, there are two paths from room 0 to room 1: 0 -> 1 and 0 -> 2 -> 1. This is a nice maze.


1)
{"NYYNN", "NNNNY", "NYNNN", "YNNNN", "NNNNN"}
"--???"

Returns: 4

The maze is nice if and only if room 2 doesn't contain an obstacle.

2)
{"NNNNN", "NNYYN", "YNNNY", "NNNNN", "NNNNN"}
"--???"

Returns: 8

There is no path from room 0 to room 1 regardless of obstacles.

3)
{"NNYNYNNY", "NNNNNNNN", "NNNNNYYY", "NYNNNNNN", "NNNNNNNN", "NYNYNNNN", "NYNNYNNN", "NNNYYNYN"}
"----???-"

Returns: 4

4)
{"NYNNNNYYYYYYYNYNYNNN",
"NNNNNNNNNNNNNNNNNNNN",
"NNNNYNYYNYNNNNYNYNYN",
"NNNNNNNNNNNNNNNNYYNN",
"NNNYNNNNNNYYNNYYNNNY",
"NYNNYNYYYYNYNYNYYYNN",
"NNNYYNNNYNYYNNYNYYNY",
"NNNYNNYNYNYNYNYYYYYN",
"NYNYYNNNNNNYYNNYYNNN",
"NNNNNNNNNNYNYNNNYYNN",
"NYNNNNNNNNNYNNNNYNNY",
"NNNNNNNNNNNNNNNNNNNN",
"NNNYNNNNNNNNNNYNNYNN",
"NNNYYNYNNYNNNNNYYYNN",
"NNNNNNNNNNNNNNNNNYNN",
"NYNYNNNNNNNNNNYNNNNN",
"NNNNNNNNNNNNNNNNNNNN",
"NYNNNNNNNNNNNNNNNNNN",
"NYNNNNNNNYNYYNNYYYNN",
"NYNNNNNNNNNNYNYNYYNN"}
"---??-??--??--?-?---"

Returns: 136



5)
{"NNYNNNNYNYYYNYNNYYNYNNYYNYNNNYYYNNNNYNNNYYNNNNYNNY",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNYNNNNNYNNNYNNYNNYNNYYYNYNYNNYYYNYNYYNYYNNNNYNNN",
"NNNNNNNNNYNNNNYNNNNNNNNYNNNNYNNNNNNNNNNYNNNNNNNNYN",
"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NYNNYNNNNNNNNNYNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNYNNN",
"NNNYYNNYNNYNNYNYNNNYYNYYNNNNYNNNYNNNNNYYNYNYYNNYYN",
"NYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NYNYYNNYNYNYNNNNNNNNNNNNNNNNNYNNNNNNNNNYNNNNNYYNNN",
"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNYNNYN",
"NYNNYNNYNYNNNNYNNNNNNYNNNNNNNNNNNNNNNNNNNYNNNNNNNN",
"NYNNNNNYNNNNNNNNNNNYNNNYNNNNYNNNNNNNNNNNNNNNNNYNNN",
"NYNNNYNYNYNNNNNNNNYYNYYNNNNYNNNNNNYNNYYNNNNNYNYNYN",
"NNNNYYNNNNNNNNYNNYNYYYNYNNNNNNNYNNYNNNNNYNNNNNNYNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NYNYNYNNNYYNNNYNNNNNYYYNYNNNNYNNNNNNNYNYNYNNNYYNYN",
"NNNNYYNYYYYYNNYNNYNYYNNNNNYNYYNNYNYNNYYYNYYYNNNNYN",
"NNNNNNNNYNNYNNNNNNNNNNNNNNNNYYNNYNYNNNNYNNNNNYNYNN",
"NNNYNYNYYYYYNNNNNNNNYNYNYNNNYNYNYNYNNNNNYYYNYNNYYN",
"NYNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NNNYYYNYNYNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNYNNN",
"NNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNYN",
"NNNNNYNNYYYNNNYNNNNYNNNNNNNNNYNNYNYNNYNYNNNNNNNYNN",
"NYNNYNNNNNNNNNYNNNNYNYNNNNNNNNNNNNNNNNNNNYNNNYYNNN",
"NNNNNYNYYYNNNNYNNYNNNNNNNNNNNYNYNNNNNNNNNNNNNYYYNN",
"NNNNYYNYYYYNYNNNYYNYNYYNNNYYNYNNYNNYNYYNYYNYYNYYNY",
"NYNNNNNNNYYNNNNNNNNNNNNYNNNNYYNNNNYNNNYNNYNNNYNNYN",
"NNNYNYNYNYNNNNNNNNNYNYYNNNYNNYNYYNNNNNNNYNNNNYNNYN",
"NYNNNYNNNYNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNYNNN",
"NYNYNNNYNYYNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNYNNNYYNNN",
"NYNNNNNNYNNNNYYYNYNYNNNNNNNNYYNNNNNNNNNNNNNNNYYNNN",
"NNNYYNNNNNYYNNYNNNNNNYNYNNNNYYNNNNYNNNNYNNNNNNYNNN",
"NYNYNYNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNYYNNYNNNYNNYN",
"NYNNNNNNNYYNNNNYYYNNNNYNYNYNYNNYYNNYNYNNNNNNNNNNYN",
"NNNNYNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNYNNYN",
"NYNYYNNYNYNNNNNYNNNYNYNNYNNNNNNNYNNNNNYNNYNYNNNNNN",
"NYNNNNNNYNNNNYYNNNYNNYYNNYYYYYNNNYNNNNNYNYYNNNNNNY",
"NYNNNYNNNYYNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNNNNNNYNNN",
"NNNNNYNNYYNYNNNNNNNNNYNYNNNNYNNNNNNNNNNNNYNNNNNNNN",
"NNNNNYNYNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN",
"NNNNYNNNYNNNNNNYNNNYNYNYYNNNNYNNNNNNNNNNNYNNNYYNNN",
"NNNNYNNYNYNNNNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNYYNYN",
"NYNNYYNNYNNNNNNNNNNYYYNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
"NNNYYNNYYNNNNNYYNNNYNNNNYNYNNNNNNNNNNNNYNNNNNYNNNN",
"NNNNNYNYYNYNNNNNYNNYYYYNYNYYYYYNYNYYNNNNYNNNNYYYYN",
"NNNNNNNYNNNNNNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NNNYYNNNYYNYNNNNNNNNNYNNNNNNYNNNNNYNNNNNNYNNNNYNNN",
"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NYNNNNYYYNYYYYNYNNNNNNNNNNNYNYNNNNNNNNNYNYNYNNNNYN"}
"---??--??-????-??????--?????-?-?-??--?-??--??????-"

Returns: 2165839872



*/
// END CUT HERE
#line 159 "EvenPaths.cpp"

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



class EvenPaths {
	public:
	long long theCount(vector <string> maze, string rooms) {
		
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
void verify_case(const long long& Expected, const long long& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, EvenPaths().theCount(maze, rooms));}
int main(){

CASE(0)
	string maze_[] = {"NYY", "NNN", "NYN"};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	string rooms = "--?"; 
	long long _ = 1LL; 
END
CASE(1)
	string maze_[] = {"NYYNN", "NNNNY", "NYNNN", "YNNNN", "NNNNN"};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	string rooms = "--???"; 
	long long _ = 4LL; 
END
CASE(2)
	string maze_[] = {"NNNNN", "NNYYN", "YNNNY", "NNNNN", "NNNNN"};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	string rooms = "--???"; 
	long long _ = 8LL; 
END
CASE(3)
	string maze_[] = {"NNYNYNNY", "NNNNNNNN", "NNNNNYYY", "NYNNNNNN", "NNNNNNNN", "NYNYNNNN", "NYNNYNNN", "NNNYYNYN"};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	string rooms = "----???-"; 
	long long _ = 4LL; 
END
CASE(4)
	string maze_[] = {"NYNNNNYYYYYYYNYNYNNN",
"NNNNNNNNNNNNNNNNNNNN",
"NNNNYNYYNYNNNNYNYNYN",
"NNNNNNNNNNNNNNNNYYNN",
"NNNYNNNNNNYYNNYYNNNY",
"NYNNYNYYYYNYNYNYYYNN",
"NNNYYNNNYNYYNNYNYYNY",
"NNNYNNYNYNYNYNYYYYYN",
"NYNYYNNNNNNYYNNYYNNN",
"NNNNNNNNNNYNYNNNYYNN",
"NYNNNNNNNNNYNNNNYNNY",
"NNNNNNNNNNNNNNNNNNNN",
"NNNYNNNNNNNNNNYNNYNN",
"NNNYYNYNNYNNNNNYYYNN",
"NNNNNNNNNNNNNNNNNYNN",
"NYNYNNNNNNNNNNYNNNNN",
"NNNNNNNNNNNNNNNNNNNN",
"NYNNNNNNNNNNNNNNNNNN",
"NYNNNNNNNYNYYNNYYYNN",
"NYNNNNNNNNNNYNYNYYNN"};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	string rooms = "---??-??--??--?-?---"; 
	long long _ = 136LL; 
END
CASE(5)
	string maze_[] = {"NNYNNNNYNYYYNYNNYYNYNNYYNYNNNYYYNNNNYNNNYYNNNNYNNY",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNYNNNNNYNNNYNNYNNYNNYYYNYNYNNYYYNYNYYNYYNNNNYNNN",
"NNNNNNNNNYNNNNYNNNNNNNNYNNNNYNNNNNNNNNNYNNNNNNNNYN",
"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NYNNYNNNNNNNNNYNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNYNNN",
"NNNYYNNYNNYNNYNYNNNYYNYYNNNNYNNNYNNNNNYYNYNYYNNYYN",
"NYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NYNYYNNYNYNYNNNNNNNNNNNNNNNNNYNNNNNNNNNYNNNNNYYNNN",
"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNYNNYN",
"NYNNYNNYNYNNNNYNNNNNNYNNNNNNNNNNNNNNNNNNNYNNNNNNNN",
"NYNNNNNYNNNNNNNNNNNYNNNYNNNNYNNNNNNNNNNNNNNNNNYNNN",
"NYNNNYNYNYNNNNNNNNYYNYYNNNNYNNNNNNYNNYYNNNNNYNYNYN",
"NNNNYYNNNNNNNNYNNYNYYYNYNNNNNNNYNNYNNNNNYNNNNNNYNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NYNYNYNNNYYNNNYNNNNNYYYNYNNNNYNNNNNNNYNYNYNNNYYNYN",
"NNNNYYNYYYYYNNYNNYNYYNNNNNYNYYNNYNYNNYYYNYYYNNNNYN",
"NNNNNNNNYNNYNNNNNNNNNNNNNNNNYYNNYNYNNNNYNNNNNYNYNN",
"NNNYNYNYYYYYNNNNNNNNYNYNYNNNYNYNYNYNNNNNYYYNYNNYYN",
"NYNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NNNYYYNYNYNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNYNNN",
"NNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNYN",
"NNNNNYNNYYYNNNYNNNNYNNNNNNNNNYNNYNYNNYNYNNNNNNNYNN",
"NYNNYNNNNNNNNNYNNNNYNYNNNNNNNNNNNNNNNNNNNYNNNYYNNN",
"NNNNNYNYYYNNNNYNNYNNNNNNNNNNNYNYNNNNNNNNNNNNNYYYNN",
"NNNNYYNYYYYNYNNNYYNYNYYNNNYYNYNNYNNYNYYNYYNYYNYYNY",
"NYNNNNNNNYYNNNNNNNNNNNNYNNNNYYNNNNYNNNYNNYNNNYNNYN",
"NNNYNYNYNYNNNNNNNNNYNYYNNNYNNYNYYNNNNNNNYNNNNYNNYN",
"NYNNNYNNNYNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNYNNN",
"NYNYNNNYNYYNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNYNNNYYNNN",
"NYNNNNNNYNNNNYYYNYNYNNNNNNNNYYNNNNNNNNNNNNNNNYYNNN",
"NNNYYNNNNNYYNNYNNNNNNYNYNNNNYYNNNNYNNNNYNNNNNNYNNN",
"NYNYNYNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNYYNNYNNNYNNYN",
"NYNNNNNNNYYNNNNYYYNNNNYNYNYNYNNYYNNYNYNNNNNNNNNNYN",
"NNNNYNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNYNNYN",
"NYNYYNNYNYNNNNNYNNNYNYNNYNNNNNNNYNNNNNYNNYNYNNNNNN",
"NYNNNNNNYNNNNYYNNNYNNYYNNYYYYYNNNYNNNNNYNYYNNNNNNY",
"NYNNNYNNNYYNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNNNNNNYNNN",
"NNNNNYNNYYNYNNNNNNNNNYNYNNNNYNNNNNNNNNNNNYNNNNNNNN",
"NNNNNYNYNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN",
"NNNNYNNNYNNNNNNYNNNYNYNYYNNNNYNNNNNNNNNNNYNNNYYNNN",
"NNNNYNNYNYNNNNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNYYNYN",
"NYNNYYNNYNNNNNNNNNNYYYNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
"NNNYYNNYYNNNNNYYNNNYNNNNYNYNNNNNNNNNNNNYNNNNNYNNNN",
"NNNNNYNYYNYNNNNNYNNYYYYNYNYYYYYNYNYYNNNNYNNNNYYYYN",
"NNNNNNNYNNNNNNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NNNYYNNNYYNYNNNNNNNNNYNNNNNNYNNNNNYNNNNNNYNNNNYNNN",
"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NYNNNNYYYNYYYYNYNNNNNNNNNNNYNYNNNNNNNNNYNYNYNNNNYN"};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	string rooms = "---??--??-????-??????--?????-?-?-??--?-??--??????-"; 
	long long _ = 2165839872LL; 
END

}
// END CUT HERE
