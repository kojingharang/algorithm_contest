// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Alice and Bob are playing a game on an infinite grid. The grid is initially empty. Alice and Bob each have an infinite supply of checkers. Alice's checkers are red, Bob's are blue. In the first turn, Alice places one of her red checkers into the cell (0,0). The game continues by Bob and Alice taking alternate turns. In each turn, the current player places their checkers into some empty cells. The player must always add all the checkers that can be added in their turn by repeatedly applying the following rules:

If cell (x-1,y-1) contains a checker of the other player and cell (x-2,y) is empty, add your checker into the cell (x,y).
If cell (x-2,y) contains a checker of the other player and cell (x-1,y-1) is empty, add your checker into the cell (x,y).

Bob has asked you to simulate the game so that he can understand it better. You are given long longs
t, x0 and y0 and ints w and h. Return a vector <string> containing h elements of w characters each. The j-th character of the i-th element of your return value will represent the contents of cell at x=x0+j and y=y0+h-i-1 after t turns. The character representing a particular cell should be 'A' (quotes for clarity) if it contains one of Alice's checkers, 'B' if it contains one of Bob's checkers and '.' if it is empty. 

DEFINITION
Class:CheckerExpansion
Method:resultAfter
Parameters:long long, long long, long long, int, int
Returns:vector <string>
Method signature:vector <string> resultAfter(long long t, long long x0, long long y0, int w, int h)


CONSTRAINTS
-t will be between 1 and 1000000000000 (10^12), inclusive.
-x0 and y0 will each be between 0 and 1000000000000 (10^12), inclusive.
-w and h will each be between 1 and 50, inclusive. 


EXAMPLES

0)
1
0
0
4
4

Returns: {"....", "....", "....", "A..." }

This is the initial turn.

1)
5
4
1
3
4

Returns: {"A..", "...", "B..", ".B." }

The checker that appears at the top row of this rectangle was placed by Alice just at the fifth turn.

2)
1024
1525
512
20
2

Returns: {"B...B...B...........", ".B.A.B.A.B.........." }



3)
53
85
6
5
14

Returns: {".....", ".....", "B....", ".B.A.", ".....", ".....", ".....", ".....", ".....", ".....", "B....", ".B...", "..B..", ".A.B." }



*/
// END CUT HERE
#line 75 "CheckerExpansion.cpp"

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
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << "\n"; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


void f(ll bx, ll by, ll size, vector<string>& w) {
	if(size==8) return;
	f(bx, by, size/2, w);
	f(bx+size/2, by, size/2, w);
	f(bx+size/2-size/4, by+size/4, size/2, w);
	cout<<"draw "<<bx<<" "<<by<<" "<<size<<endl;
	REP(x, size/2) {
		ll X = bx+x*2;
		ll Y = by;
		if(X>=0 && X<w[0].size() && Y>=0 && Y<w.size()) w[Y][X]='*';
	}
}

class CheckerExpansion {
	public:
	vector <string> resultAfter(long long t, long long x0, long long y0, int W, int H) {
		W=50,H=50;
		vector<string> w(2+W, string(2+H, '.'));
		//w[2+0][2+0]='A';
		//cout<<w<<endl;
		//REP(turn, 50) {
		//	char me = turn&1 ? 'A' : 'B';
		//	char op = me=='A'?'B':'A';
		//	cout<<me<<op<<endl;
		//	REP(y, H) REP(x, W) {
		//		if(w[2+y][2+x-2]=='.' && w[2+y-1][2+x-1]==op) w[2+y][2+x]=me;
		//		if(w[2+y][2+x-2]==op && w[2+y-1][2+x-1]=='.') w[2+y][2+x]=me;
		//	}
		//	cout<<w<<endl;
		//}
		f(0, 0, 8<<2, w);
		cout<<w<<endl;
		//f(0, 0, 1LL<<60);
		return vector<string>();
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
void verify_case(const vector <string>& Expected, const vector <string>& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, CheckerExpansion().resultAfter(t, x0, y0, w, h));}
int main(){

CASE(0)
	long long t = 1LL; 
	long long x0 = 0LL; 
	long long y0 = 0LL; 
	int w = 4; 
	int h = 4; 
	string __[] = {"....", "....", "....", "A..." };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END
return 0;
CASE(1)
	long long t = 5LL; 
	long long x0 = 4LL; 
	long long y0 = 1LL; 
	int w = 3; 
	int h = 4; 
	string __[] = {"A..", "...", "B..", ".B." };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	long long t = 1024LL; 
	long long x0 = 1525LL; 
	long long y0 = 512LL; 
	int w = 20; 
	int h = 2; 
	string __[] = {"B...B...B...........", ".B.A.B.A.B.........." };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	long long t = 53LL; 
	long long x0 = 85LL; 
	long long y0 = 6LL; 
	int w = 5; 
	int h = 14; 
	string __[] = {".....", ".....", "B....", ".B.A.", ".....", ".....", ".....", ".....", ".....", ".....", "B....", ".B...", "..B..", ".A.B." };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END

}
// END CUT HERE
