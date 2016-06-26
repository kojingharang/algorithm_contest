// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Little Petya likes convex polygons a lot. Recently he has received a convex polygon as a gift from his mother. The only thing that Petya likes more than convex polygons is playing with little Masha. Petya invented the following game for two players that involves his polygon.
At the beginning of the game there is a convex polygon drawn on the plane. The coordinates of vertices of this polygon are given in vector <int> X and vector <int> Y. Petya and Masha take alternate turns, Masha plays first. On his or her turn the player draws a new convex polygon that has the following properties:

 All vertices of the new polygon have integer coordinates.

 Each new vertex is located either strictly inside the old polygon or on an edge of the old polygon.

 No vertex of the new polygon coincides with any vertex of the old polygon.

 No three vertices of the new polygon lie on the same line.

 The new polygon has non-zero area.


Note that the new polygon and the old polygon are not required to have the same number of vertices. 
After drawing a new polygon the player erases the old one. A player who can't make a move loses the game. Determine who will be the winner if both kids play optimally. If the winner is Masha, return the string "Masha" (without quotes), otherwise return "Petya".

DEFINITION
Class:ConvexPolygonGame
Method:winner
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string winner(vector <int> X, vector <int> Y)


CONSTRAINTS
-X will contain between 3 and 50 elements, inclusive.
-Y will contain between 3 and 50 elements, inclusive.
-X and Y will contain the same number of elements.
-Each element of X will be between -100 000 and 100 000, inclusive.
-Each element of Y will be between -100 000 and 100 000, inclusive.
-The polygon represented by X and Y will be convex, will have non-zero area and won't contain any 3 vertices that are located on the same line.
-Vertices of the polygon will be listed in counter-clockwise order.


EXAMPLES

0)
{0, 1, 0}
{0, 0, 1}

Returns: "Petya"

Masha has no valid moves, so she loses the game immediately.

1)
{0, 4, 2}
{0, 0, 2}

Returns: "Masha"

One of the possible Masha's moves is to select the triangle (1, 0), (3, 1), (1, 1). Regardless of her first move Petya will never be able to make the next move.

2)
{0, 100, 100, 0}
{0, 0, 100, 100}

Returns: "Masha"



3)
{0, 50, 100, 50}
{0, -1, 0, 1}

Returns: "Petya"



4)
{-100000, 100000, 100000, -100000}
{-1, -1, 1, 1}

Returns: "Masha"



******************************/
// END CUT HERE
#line 84 "ConvexPolygonGame.cpp"
#include <vector>
#include <map>
#include <set>
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
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

int CEIL(int a, int b) {
	int sgn = (a/abs(a))*(b/abs(b));
	
}

class ConvexPolygonGame {
	public:
	string winner(vector <int> X, vector <int> Y) {
		cout<<-1/10<<endl;
		int N=X.size();
		int MinX = *min_element(ALL(X));
		int MaxX = *max_element(ALL(X));
		int Li=-1, Ri=-1;
		REP(i, N) {
			if(MinX==X[i]) Li=i;
			if(MaxX==X[i]) Ri=i;
		}
		if(X[(Li+1)%N]==MinX) Li=(Li+1)%N;
		if(X[(Ri+1)%N]==MaxX) Ri=(Ri+1)%N;
		
		cout<<Li<<" "<<Ri<<endl;
		int len=MaxX-MinX+1;
		VI lb(len), ub(len);
		REP(ii, N) {
			int ci=(Li+ii)%N;
			int ni=(Li+ii+1)%N;
			if(X[ci]==MaxX) break;
			lb[-MinX+X[ci]] = max(lb[-MinX+X[ci]], Y[ci]+1);
			lb[-MinX+X[ni]] = max(lb[-MinX+X[ni]], Y[ni]+1);
			for(int j=X[ci]+1;j<X[ni];j++) {
				lb[-MinX+j] = Y[ci] + (Y[ni]-Y[ci]) * (j-X[ci]) / (X[ni]-X[ci]);
			}
		}
		REP(ii, N) {
			int ci=(Ri+ii)%N;
			int ni=(Ri+ii+1)%N;
			if(X[ci]==MinX) break;
			ub[-MinX+X[ci]] = min(ub[-MinX+X[ci]], Y[ci]-1);
			ub[-MinX+X[ni]] = min(ub[-MinX+X[ni]], Y[ni]-1);
			for(int j=X[ci]-1;j>X[ni];j--) {
				ub[-MinX+j] = Y[ci] + (Y[ni]-Y[ci]) * (X[ci]-j) / (-X[ni]+X[ci]);
			}
		}
		cout<<lb<<endl;
		cout<<ub<<endl;
		int exist=0;
		REP(i, len) {
			if(lb[i] <= ub[i]) exist = 1;
		}
		return exist ? "Masha" : "Petya";
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
void verify_case(const string& Expected, const string& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, ConvexPolygonGame().winner(X, Y));}
int main(){
CASE(3)
	int X_[] = {0, 5, 10, 5};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0, -1, 0, 1};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	string _ = "Petya"; 
END
return 0;
CASE(0)
	int X_[] = {0, 1, 0};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0, 0, 1};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	string _ = "Petya"; 
END
//return 0;
CASE(1)
	int X_[] = {0, 4, 2};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0, 0, 2};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	string _ = "Masha"; 
END
//return 0;
CASE(2)
	int X_[] = {0, 100, 100, 0};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0, 0, 100, 100};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	string _ = "Masha"; 
END
CASE(3)
	int X_[] = {0, 50, 100, 50};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0, -1, 0, 1};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	string _ = "Petya"; 
END
CASE(4)
	int X_[] = {-100000, 100000, 100000, -100000};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {-1, -1, 1, 1};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	string _ = "Masha"; 
END

}
// END CUT HERE
