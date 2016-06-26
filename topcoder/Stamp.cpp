// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Little Fox Jiro has a rectangular board.
On the board there is a row of N unit cells.
The cells are numbered 0 through N-1 from the left to the right.
Initially, the cells are not colored.
Jiro must color each of the cells red, green, or blue.

You are given a string desiredColor with N characters.
For each i, character i of desiredColor represents the color Jiro must use for cell i.
If a character is one of 'R' (as red), 'G' (as green), and 'B' (as blue), it means that Jiro must use that particular color.
If a character is '*', Jiro may use any of the three colors for the particular cell.

You are also given the ints stampCost and pushCost that describe the cost of the coloring process.
The coloring process consists of two phases.
In the first phase, Jiro must pick a single stamp he will then use to color all the cells.
The length L of the stamp can be any integer between 1 and N, inclusive.
A stamp of length L costs L*stampCost.

In the second phase, Jiro must repeatedly use the stamp to color the cells.
Each use of the stamp works as follows:

Jiro picks one of the three colors and pushes the stamp into ink of the chosen color C.
Jiro picks a segment of L contiguous cells such that each of them is either uncolored or already has the color C.
The segment must be completely inside the board.
That is, the leftmost cell of the segment must be one of the cells 0 through N-L.
Jiro pushes the stamp onto the chosen segment of cells. All the cells now have color C.

Each use of the stamp costs pushCost.

Return the smallest possible total cost of coloring all the cells using the above process.


DEFINITION
Class:Stamp
Method:getMinimumCost
Parameters:string, int, int
Returns:int
Method signature:int getMinimumCost(string desiredColor, int stampCost, int pushCost)


CONSTRAINTS
-desiredColor will contain between 1 and 50 characters, inclusive.
-Each character of desiredColor will be either 'R' or 'G' or 'B' or '*'.
-stampCost will be between 1 and 100,000, inclusive.
-pushCost will be between 1 and 100,000, inclusive.


EXAMPLES

0)
"RRGGBB"
1
1

Returns: 5

The optimal solution is to choose L=2 and then stamp three times: using red color for cells [0,1], green for [2,3], and blue for [4,5].
The stamp costs 2*1 = 2, each of the three uses costs 1, so the total costs is 2*1 + 3*1 = 5.

1)
"R**GB*"
1
1

Returns: 5

The optimal solution is the same as in the previous example.
Note that you must color all the cells, so choosing L=1 and then using the stamp three times is not a valid solution.

2)
"BRRB"
2
7

Returns: 30

Also, note that once a cell is colored, you are not allowed to stamp over it using a different color.
Therefore, you can only choose L=1 in this case.

3)
"R*RR*GG"
10
58

Returns: 204

It is allowed to stamp the same cell multiple times if all of those stamps use the same color.

4)
"*B**B**B*BB*G*BBB**B**B*"
5
2

Returns: 33



5)
"*R*RG*G*GR*RGG*G*GGR***RR*GG"
7
1

Returns: 30



*/
// END CUT HERE
#line 112 "Stamp.cpp"

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
#define RANGE(i,a,b) for(ll i=(int)a,_b=(int)(b);(i)<_b;++i)
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

#define INF (1LL<<50)

class Stamp {
	public:
	int getMinimumCost(string DC, int SC, int PC) {
		int N = DC.size();
		ll ans = INF;
		string CT("RGB");
		RANGE(L, 1, N+1) {
			VVI dp(3, VI(N, INF));
			
			REP(c, 3) {
				int okeru=1;
				REP(i, L) {
					if(!(DC[L-1-i]=='*' || DC[L-1-i]==CT[c])) okeru=0;
				}
				if(okeru) dp[c][L-1] = 1;
			}
			//cout<<"PRE   L "<<L<<endl;
			//cout<<dp<<endl;
			
			RANGE(i, L-1, N) {
				RANGE(sub, 1, L+1) {
					int idx = i-sub;
					if(idx>=0) {
						//cout<<"i "<<i<<" idx "<<idx<<endl;
						REP(c, 3) {
							int okeru = 1;
							REP(j, L) {
								if(!(DC[i-j]=='*' || DC[i-j]==CT[c])) okeru=0;
							}
							//cout<<"C "<<c<<" -> "<<okeru<<endl;
							if(!okeru) continue;
							REP(pc, 3) {
								if(sub<L && pc!=c) continue;
								if(dp[pc][idx]!=INF)
								dp[c][i] = min(dp[c][i], dp[pc][idx]+1);
							}
						}
					}
				}
			}
			//cout<<"L "<<L<<endl;
			//cout<<dp<<endl;
			
			ll co = INF;
			REP(c, 3) co = min(co, dp[c][N-1]);
			if(co>=INF) continue;
			ans = min(ans, L*SC+co*PC);
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
#define END	 verify_case(_, Stamp().getMinimumCost(desiredColor, stampCost, pushCost));}
int main(){

CASE(5)
	string desiredColor = "RB"; 
	int stampCost = 47185; 
	int pushCost = 16261; 
	int _ = 79707; 
END
return 0;
CASE(5)
	string desiredColor = "RR*GG"; 
	int stampCost = 1; 
	int pushCost = 100000; 
	int _ = 300002; 
END
CASE(3)
	string desiredColor = "R*RR*GG"; 
	int stampCost = 10; 
	int pushCost = 58; 
	int _ = 204; 
END
//return 0;
CASE(0)
	string desiredColor = "RRGGBB"; 
	int stampCost = 1; 
	int pushCost = 1; 
	int _ = 5; 
END
//return 0;
CASE(1)
	string desiredColor = "R**GB*"; 
	int stampCost = 1; 
	int pushCost = 1; 
	int _ = 5; 
END
CASE(2)
	string desiredColor = "BRRB"; 
	int stampCost = 2; 
	int pushCost = 7; 
	int _ = 30; 
END
CASE(4)
	string desiredColor = "*B**B**B*BB*G*BBB**B**B*"; 
	int stampCost = 5; 
	int pushCost = 2; 
	int _ = 33; 
END
CASE(5)
	string desiredColor = "*R*RG*G*GR*RGG*G*GGR***RR*GG"; 
	int stampCost = 7; 
	int pushCost = 1; 
	int _ = 30; 
END
CASE(5)
	string desiredColor = "**************************************************"; 
	int stampCost = 100000; 
	int pushCost = 100000; 
	int _ = 30; 
END



}
// END CUT HERE
