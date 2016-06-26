// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// John is standing at the origin of an infinite two-dimensional grid.
He is going to move along this grid.
During each second he can either stay where he is or he can move by one unit in one of the four cardinal directions (north, south, east, or west).
Some of the grid points are blocked.
John is not allowed to move to a blocked grid point.


You are given the coordinates of the blocked grid points as vector <int>s x and y.
For each valid i, the grid point that is x[i] units east and y[i] units north of the origin is blocked.
You are also given an int k.
Compute and return the maximal possible x-coordinate of a point John can reach in k seconds.


DEFINITION
Class:TheGridDivOne
Method:find
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int find(vector <int> x, vector <int> y, int k)


CONSTRAINTS
-x will contain between 0 and 47 elements, inclusive.
-x and y will contain the same number of elements.
-Each element of x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-Each element of y will be between -1,000,000,000 and 1,000,000,000, inclusive.
-All pairs (x[i], y[i]) will be distinct.
-Each pair (x[i], y[i]) will be different from (0, 0).
-k will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1,1,1,1}
{-2,-1,0,1}
4

Returns: 2

The optimal strategy is to move two times north to (0, 2) and then two times east to (2,2).

1)
{-1, 0, 0, 1}
{0, -1, 1, 0}
9

Returns: 0

John can not make any moves.

2)
{}
{}
1000

Returns: 1000



3)
{1,0,0,-1,-1,-2,-2,-3,-3,-4,-4}
{0,-1,1,-2,2,-3,3,-4,4,-5,5}
47

Returns: 31



*/
// END CUT HERE
#line 76 "TheGridDivOne.cpp"

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
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
std::ostream& operator<<(std::ostream& os, const vector<string>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << "\n"; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }


struct EL {
	int x, y;
	ll v;
};

struct Dijkstra {
	struct edge{int to; ll cost;};
	vector<vector<edge> > G;
	vector<ll> V;
	const ll Max = 1LL<<60;
	Dijkstra(int N) {
		G = vector<vector<edge> >(N);
		V = vector<ll>(N, Max);
	}
	void add_edge(int v0, int v1, ll cost) {
		if(v0<G.size() && v1<G.size()) G[v0].PB((edge){v1, cost});
	}
	int run(int S, int E) {
		V[S]=0;
		priority_queue<PII> q;
		q.push(make_pair(0, S));
		while(q.size()) {
			PII el = q.top(); q.pop();
			if(el.second==E) break;
			if(-el.first > V[el.second]) continue;
			for(int i=0;i<(int)G[el.second].size();i++){
				const edge& e=G[el.second][i];
				if(V[e.to]>V[el.second]+e.cost){
					V[e.to]=V[el.second]+e.cost;
					q.push(make_pair(-V[e.to], e.to));
				}
			}
		}
		if(E<0) return -1;
		return V[E]==Max?-1:V[E];
	}
};

VI compress(VI v) {
	VI w;
	REP(i, v.size()) RANGE(r, -1, 2) w.PB(v[i]+r);
	sort(ALL(w));
	w.erase(unique(ALL(w)), w.end());
	return w;
}

VI toVI(vector<int> v) {
	VI w;
	REP(i, v.size()) w.PB(v[i]);
	return w;
}

class TheGridDivOne {
	public:
	int W, H;
	vector<string> m;
	int node(int x, int y) {
		return y*W + x;
	}
	int find(vector <int> X, vector <int> Y, int k) {
		VI vix = toVI(X);
		VI viy = toVI(Y);
		vix.PB(0);
		viy.PB(0);
		VI CX = compress(vix);
		VI CY = compress(viy);
		cout<<CX<<endl;
		cout<<CY<<endl;
		W = CX.size();
		H = CY.size();
		m = vector<string>(H, string(W, '.'));
		int sx, sy;
		REP(x, W) if(CX[x]==0) sx=x;
		REP(y, H) if(CY[y]==0) sy=y;
		REP(y, H) REP(x, W) REP(i, X.size()) {
			if(CX[x]==X[i] && CY[y]==Y[i]) m[y][x]='x';
		}
		m[sy][sx] = 's';
		cout<<m<<endl;
//		return 0;
		
		Dijkstra d(W*H);
		int dx[]={0,0,1,-1};
		int dy[]={1,-1,0,0};
		REP(y, H) REP(x, W) REP(dir, 4) {
			int nx=x+dx[dir];
			int ny=y+dy[dir];
			if(0<=nx && nx<W && 0<=ny && ny<H) {
				if(m[ny][nx]=='.') {
					ll cost = abs(CX[nx]-CX[x]) + abs(CY[ny]-CY[y]);
					d.add_edge(node(x, y), node(nx, ny), cost);
				}
			}
		}
		d.run(node(sx, sy), -1);
		ll ans = 0;
		REP(y, H) REP(x, W) if(d.V[node(x, y)]<=k) {
			ll nv = CX[x] + max<ll>(0, k-d.V[node(x, y)]);
			if(x<W-1) nv = min<ll>(nv, CX[x+1]-1);
			ans = max<ll>(ans, nv);
		}
		
//		cout<<X<<endl;
//		cout<<Y<<endl;
//		cout<<"---"<<endl;
//		REP(y, H) {
//			REP(x, W) {
//				cout<<d.V[node(x,y)]<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<"---"<<endl;
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
#define END	 verify_case(_, TheGridDivOne().find(x, y, k));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int x_[] = {168, -621, -631, -543, 968, -743, 756, -641, -92, 366, 954, 576, -227, -245, 795};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-206, 681, -430, -495, 858, -205, 701, 39, -13, -81, 832, 7, 167, 605, -849};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int k = 275; 
	int _ = 275; 
END
return 0;

CASE(0)
	int x_[] = {1,1,1,1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-2,-1,0,1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int k = 4; 
	int _ = 2; 
END
//return 0;
CASE(1)
	int x_[] = {-1, 0, 0, 1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0, -1, 1, 0};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int k = 9; 
	int _ = 0; 
END
CASE(2)
	vector <int> x; 
	vector <int> y; 
	int k = 1000; 
	int _ = 1000; 
END
CASE(3)
	int x_[] = {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,-1,1,-2,2,-3,3,-4,4,-5,5};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int k = 47; 
	int _ = 31; 
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
// param type: int
	vector <int> x; 
	{
		int N=UNIFORM_LL(1, 51);
		x = vector <int>(N); 
		REP(i, N) {
			x[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> y; 
	{
		int N=UNIFORM_LL(1, 51);
		y = vector <int>(N); 
		REP(i, N) {
			y[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int k = UNIFORM_LL(0, 100); 
	int _0 = TheGridDivOne().find(x, y, k);
	int _1 = TheGridDivOneRef().find(x, y, k);
	if(!verify_case(_0, _1, true)) {
print(x);
print(y);
print(k);
	}
}
#endif

}
// END CUT HERE
