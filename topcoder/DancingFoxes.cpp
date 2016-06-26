// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel and Fox Jiro both went to spend an evening in the dancing room.
Together, there are N foxes in the room.
The foxes are numbered 0 through N-1.
In particular, Ciel is fox 0 and Jiro is fox 1.



You are given a vector <string> friendship that describes the initial friendship between the foxes in the room.
More precisely, friendship contains N elements with N characters each.
Character j of element i of friendship is 'Y' if foxes i and j are friends at the beginning of the evening, and 'N' otherwise.
Note that friendship is symmetric: whenever X is a friend of Y, Y is a friend of X.



During the evening, multiple songs will be played in succession.
During each song, some pairs of foxes will be dancing together.
Foxes are not allowed to change partners during the dance.
Thus in each dance each fox either dances with a single partner, or sits the dance out.



Foxes are not allowed to form the pairs for a dance arbitrarily.
It is only allowed for two foxes to dance together if they are friends, or if they have a common friend who can introduce them.
That is, if foxes A and B are not friends at the moment, they can only dance together if there is a fox C such that A and B are both friends with C.
After two foxes dance together, they become friends.



Fox Ciel wants to become friends with Fox Jiro.
Return the smallest number of dances in which this can be achieved (assuming that all other foxes cooperate and form pairs for the dances optimally).
If it's impossible to make Ciel and Jiro friends, return -1 instead.

DEFINITION
Class:DancingFoxes
Method:minimalDays
Parameters:vector <string>
Returns:int
Method signature:int minimalDays(vector <string> friendship)


NOTES
-Gender does not matter for the foxes when choosing their dance partners.


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-friendship will contain exactly N elements.
-Each element of friendship will contain exactly N characters.
-Each character in friendship will be 'Y' or 'N'.
-For each i, friendship[i][i] = 'N'.
-For each i and j, friendship[i][j] = friendship[j][i].


EXAMPLES

0)
{"NNY",
 "NNY",
 "YYN"}

Returns: 1

There are 3 foxes. Ciel and Jiro are not friends, but they are both friends with fox 2. Thus, they may dance together in the first dance and become friends.

1)
{"NNNNN",
 "NNYYY",
 "NYNYY",
 "NYYNY",
 "NYYYN"}

Returns: -1

Ciel does not know any other fox at the dance, so she cannot dance with anybody.

2)
{"NNYYNN",
 "NNNNYY",
 "YNNNYN",
 "YNNNNY",
 "NYYNNN",
 "NYNYNN"}

Returns: 2



3)
{"NNYNNNNYN",
 "NNNNYNYNN",
 "YNNYNYNNN",
 "NNYNYNYYN",
 "NYNYNNNNY",
 "NNYNNNYNN",
 "NYNYNYNNN",
 "YNNYNNNNY",
 "NNNNYNNYN"}

Returns: 3



4)
{"NY",
 "YN"}

Returns: 0

Ciel and Jiro are already friends in the beginning, no dances are needed. In such a case, the correct return value is 0.

*/
// END CUT HERE
#line 117 "DancingFoxes.cpp"

#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

#define INF (1<<30)

class DancingFoxes {
	public:
	int minimalDays(vector <string> F) {
		int H=F.size(), W=F[0].size();
		VVI w(H, VI(W, INF));
		REP(y, H) REP(x, W) if(F[y][x]=='Y') w[y][x] = 1;
		REP(k, H) REP(y, H) REP(x, W) w[y][x] = min(w[y][x], w[y][k]+w[k][x]);
		int D=w[1][0];
		if(D==INF) return -1;
		
		int ans=0;
		while(D>1) {
			ans++;
			D-=(D+1)/3;
		}
		return ans;
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
#define END	 verify_case(_, DancingFoxes().minimalDays(friendship));}
int main(){

CASE(0)
	string friendship_[] = {"NNY",
 "NNY",
 "YYN"};
	  vector <string> friendship(friendship_, friendship_+sizeof(friendship_)/sizeof(*friendship_)); 
	int _ = 1; 
END
CASE(1)
	string friendship_[] = {"NNNNN",
 "NNYYY",
 "NYNYY",
 "NYYNY",
 "NYYYN"};
	  vector <string> friendship(friendship_, friendship_+sizeof(friendship_)/sizeof(*friendship_)); 
	int _ = -1; 
END
CASE(2)
	string friendship_[] = {"NNYYNN",
 "NNNNYY",
 "YNNNYN",
 "YNNNNY",
 "NYYNNN",
 "NYNYNN"};
	  vector <string> friendship(friendship_, friendship_+sizeof(friendship_)/sizeof(*friendship_)); 
	int _ = 2; 
END
CASE(3)
	string friendship_[] = {"NNYNNNNYN",
 "NNNNYNYNN",
 "YNNYNYNNN",
 "NNYNYNYYN",
 "NYNYNNNNY",
 "NNYNNNYNN",
 "NYNYNYNNN",
 "YNNYNNNNY",
 "NNNNYNNYN"};
	  vector <string> friendship(friendship_, friendship_+sizeof(friendship_)/sizeof(*friendship_)); 
	int _ = 3; 
END
CASE(4)
	string friendship_[] = {"NY",
 "YN"};
	  vector <string> friendship(friendship_, friendship_+sizeof(friendship_)/sizeof(*friendship_)); 
	int _ = 0; 
END

}
// END CUT HERE
