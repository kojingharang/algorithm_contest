// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Little Elephant from the Zoo of Lviv likes balls.
He has some balls that he wants to arrange into a row on the table.
Each of those balls has one of three possible colors: red, green, or blue.




You are given a string S.
This string represents all of the balls Little Elephant has, in the order in which he will be placing them onto the table.
Red, green, and blue balls are represented by the characters 'R', 'G', and 'B', respectively.
Each time Little Elephant places a new ball onto the table, he may add it anywhere into the row of already placed balls.




Additionally, each time Little Elephant adds a ball to the table, he scores some points (possibly zero).
The number of points is calculated as follows:

If this is the first ball being placed on the table, there are 0 points for it.
If he adds the current ball to one of the ends of the row, the number of points scored is equal to the number of different colors of the balls on the table, excluding the current ball.
If he adds the current ball between two other balls, the number of points scored is equal to the number of different colors of the balls before the current ball, plus the number of different colors of the balls after the current ball.





For example, suppose that the balls currently on the table form the row "GBBG". 
Little Elephant now wants to add a new red ball ('R').
One of the options is to add it to the beginning.
This scores 2 points and produces the row "RGBBG".
Another option is to add it between "GBB" and "G".
There are 2 distinct colors in "GBB" and 1 in "G", so this move is worth 2+1 = 3 points.
This move produces the row "GBBRG".




Return the maximum total number of points that Little Elephant can earn for placing the balls onto the table.


DEFINITION
Class:LittleElephantAndBalls
Method:getNumber
Parameters:string
Returns:int
Method signature:int getNumber(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-S will consist only of characters 'R', 'G' and 'B'.


EXAMPLES

0)
"RGB"

Returns: 3

Any strategy is optimal here. Each strategy scores 0+1+2 = 3 points.

1)
"RGGRBBB"

Returns: 21



2)
"RRRGBRR"

Returns: 16



3)
"RRRR"

Returns: 5



4)
"GGRRRGR"

Returns: 18



5)
"G"

Returns: 0



*/
// END CUT HERE
#line 105 "LittleElephantAndBalls.cpp"

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



class LittleElephantAndBalls {
	public:
	int getNumber(string S) {
		VI w(64, -1), wn(64, -1);
		w[0]=0;
		int N=S.size();
		map<char, int> cm;
		cm['R']=0;
		cm['G']=1;
		cm['B']=2;
		REP(i, N) {
			REP(p, 2) {
				REP(j, 64) {
					if(w[j]==-1) continue;
					int nj = j|(1<<(cm[S[i]]+p*3));
					int pt = POPCOUNT(j);
					wn[nj] = max(wn[nj], w[j]+pt);
				}
			}
			w = wn;
			//cout<<w<<endl;
		}
		ll ans = 0;
		REP(j, 64) ans=max(ans, w[j]);
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
#define END	 verify_case(_, LittleElephantAndBalls().getNumber(S));}
int main(){
//CASE(5)
//	string S = "G"; 
//	int _ = 0; 
//END
//return 0;

CASE(0)
	string S = "RGB"; 
	int _ = 3; 
END
CASE(1)
	string S = "RGGRBBB"; 
	int _ = 21; 
END
CASE(2)
	string S = "RRRGBRR"; 
	int _ = 16; 
END
CASE(3)
	string S = "RRRR"; 
	int _ = 5; 
END
CASE(4)
	string S = "GGRRRGR"; 
	int _ = 18; 
END
CASE(5)
	string S = "G"; 
	int _ = 0; 
END

}
// END CUT HERE
