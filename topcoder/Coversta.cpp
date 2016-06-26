// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// There is a rectangular field divided into a grid of n rows by m columns of unit square cells.
Each cell (i, j) has some strategic value which is an integer between 0 and 9, inclusive.
You are given these values as a vector <string> a where each a[i][j] is a digit between '0' and '9', inclusive.

It is possible to build stations in some cells.
A station built in a cell covers some set of cells.
You are given the offsets of those cells as vector <int>s x and y.
More precisely, for each valid k, a station in the cell (i, j) covers the cell (i + x[k], j + y[k]) if a cell with those coordinates exists.
Note that it may be the case that a station in (i, j) does not cover the cell (i, j).

Your task is to place two stations into two distinct cells.
The total strategic value of the two stations is the sum of strategic values of all cells that are covered by at least one of the stations.
Return the largest possible total strategic value of the two stations.

DEFINITION
Class:Coversta
Method:place
Parameters:vector <string>, vector <int>, vector <int>
Returns:int
Method signature:int place(vector <string> a, vector <int> x, vector <int> y)


NOTES
-The two stations must be built in two distinct cells of the given rectangular array. It is not allowed to build the stations at coordinates that are outside the given array.


CONSTRAINTS
-n will be between 2 and 100, inclusive.
-m will be between 2 and 100, inclusive.
-a will contain exactly n elements.
-Each element of a will contain exactly m characters.
-Each character in a will be a digit ('0'-'9').
-x will contain between 1 and 10 elements, inclusive.
-x and y will contain the same number of elements.
-Each element in x will be between -(n-1) and (n-1), inclusive.
-Each element in y will be between -(m-1) and (m-1), inclusive.
-The pairs (x[k], y[k]) will be distinct.


EXAMPLES

0)
{"11",
 "11"}
{0,0}
{0,1}

Returns: 4

A station at (i, j) covers the cells (i, j) and (i, j+1). The optimal solution is to place the two stations at (0, 0) and (1, 0).

1)
{"11",
 "11"}
{0,1}
{0,1}

Returns: 3

Here a station at (i, j) also covers (i+1, j+1). One optimal solution is to place the two stations at (0, 0) and (0, 1). The first station also covers the cell (1, 1).

2)
{"15",
 "61"}
{0}
{0}

Returns: 11

In this test case each station only covers its own cell. The optimal solution is to build the two stations in the two most important locations.

3)
{"151",
 "655",
 "661"}
{0,0,-1}
{0,1,0}

Returns: 33



4)
{"303",
 "333",
 "000"}
{-1,-1}
{-1,1}

Returns: 12

Note that in this test case the offset (0, 0) is not among the offsets (x[k], y[k]).

5)
{"0000000",
 "1010101"}

{-1,-1}
{-1,1}

Returns: 0

The stations must be built on some cells of the given field. They cannot be built outside the field.

******************************/
// END CUT HERE
#line 111 "Coversta.cpp"
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
#define ull unsigned long long
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
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, I, J) REP(i, I) { REP(j, J) cout<<table[i][j]<<" "; cout<<"\n"; }
#define PRINT3(table, I, J, K) REP(i, I) { REP(j, J) { REP(k, K) cout<<table[i][j][k]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

struct Pos {
	int x, y;
	bool operator<(const Pos v) const {
		return x*1000+y < v.x*1000+v.y;
	}
	bool operator==(const Pos v) const {
		return x==v.x && y==v.y;
	}
};
std::ostream& operator<<(std::ostream& os, const Pos& v) {
	os << "("<<v.x<<", "<<v.y<<") ";
	return os;
}

struct Pat {
	Pos ref;
	vector<Pos> pos;
};

class Coversta {
	public:
	int place(vector <string> a, vector <int> X, vector <int> Y) {
		int W=a.size(), H=a[0].size();
		int N=X.size();
		VVI one(W, VI(H));
		vector<Pat> pat;
		map<PII, int> ng;
		REP(x, W) REP(y, H) REP(i, N) {
			if(IN_RANGE(x+X[i], 0, W) && IN_RANGE(y+Y[i], 0, H)) {
				one[x][y]+=a[x+X[i]][y+Y[i]]-'0';
			}
		}
		REP(i, N) REP(j, N) if(i!=j) {
			// i-j
			int dx = X[i]-X[j];
			int dy = Y[i]-Y[j];
			auto key = MP(dx, dy);
			if(ng.count(key)) continue;
			if(dx==0 && dy==0) continue;
			ng[key] = 1;
			vector<Pos> v;
			REP(k, N) v.PB(Pos{X[k], Y[k]});
			REP(k, N) v.PB(Pos{X[k]+dx, Y[k]+dy});
			sort(ALL(v));
			v.erase(unique(ALL(v)), v.end());
			pat.PB({Pos{dx, dy}, v});
		}
		REP(i, pat.size()) {
//			cout<<pat[i].ref<<" -> "<<pat[i].pos<<endl;
//			cout<<pat[i].ref.x<<" "<<pat[i].ref.y<<endl;
		}
		ll ans = 0;
		REP(pi, pat.size()) {
			auto& p = pat[pi];
			REP(x0, W) REP(y0, H) {
				int xx = x0+p.ref.x;
				int yy = y0+p.ref.y;
				if(IN_RANGE(xx, 0, W) && IN_RANGE(yy, 0, H)) {
					ll lans = 0;
					REP(i, p.pos.size()) {
						int ex = x0 + p.pos[i].x;
						int ey = y0 + p.pos[i].y;
						if(IN_RANGE(ex, 0, W) && IN_RANGE(ey, 0, H)) {
							lans += a[ex][ey]-'0';
						}
					}
					ans = max(ans, lans);
				}
			}
		}
//		cout<<"one "<<one<<endl;
		REP(x0, W) REP(y0, H) REP(x1, W) REP(y1, H) if(!(x0==x1 && y0==y1)) {
			int dx = x0-x1;
			int dy = y0-y1;
			PII k = MP(dx, dy);
			if(!ng.count(k)) {
//				cout<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<" -> "<<one[x0][y0]+one[x1][y1]<<endl;
				ans = max(ans, one[x0][y0]+one[x1][y1]);
			}
		}
		return ans;
	}
};


// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, Coversta().place(a, x, y));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string a_[] = {"11",
 "11"};
	  vector <string> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int x_[] = {0,0};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 4; 
END
CASE(1)
	string a_[] = {"11",
 "11"};
	  vector <string> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int x_[] = {0,1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 3; 
END
CASE(2)
	string a_[] = {"15",
 "61"};
	  vector <string> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int x_[] = {0};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 11; 
END
CASE(3)
	string a_[] = {"151",
 "655",
 "661"};
	  vector <string> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int x_[] = {0,0,-1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,1,0};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 33; 
END
CASE(3)
	string a_[] = {
"101",
"111",
"101"};
	  vector <string> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int x_[] = {0,0,-1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,1,0};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 5; 
END
CASE(4)
	string a_[] = {"303",
 "333",
 "000"};
	  vector <string> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int x_[] = {-1,-1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-1,1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 12; 
END
CASE(5)
	string a_[] = {"0000000",
 "1010101"}
;
	  vector <string> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int x_[] = {-1,-1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-1,1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 0; 
END
#if 0  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: String
	int N=UNIFORM_LL(1, 10);
	int M=UNIFORM_LL(1, 10);
	vector <string> a; 
	{
		a = vector <string>(N, string(N, ' ')); 
		REP(i, N)REP(j, N) {
			a[i][j] = UNIFORM_LL(0, 10)+'0';
		}
	}
// param type: int
	vector <int> x; 
	{
		x = vector <int>(M); 
		REP(i, N) {
			x[i] = UNIFORM_LL(-(N-1), N-1);
		}
	}
// param type: int
	vector <int> y; 
	{
		y = vector <int>(M); 
		REP(i, M) {
			y[i] = UNIFORM_LL(-(N-1), N-1);
		}
	}
	cout<<a<<endl;
	int _0 = Coversta().place(a, x, y);
	int _1 = CoverstaRef().place(a, x, y);
	if(!verify_case(_0, _1, true)) {
print(a);
print(x);
print(y);
	}
}
#endif

}
// END CUT HERE
