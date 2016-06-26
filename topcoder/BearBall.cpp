// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// N bears are playing a game.
For the purpose of this problem, each bear is just a single point in the plane.
You are given the coordinates of the bears: the vector <int>s x and y, each with N elements.
For each valid i there is a bear at (x[i], y[i]).

The game they play is played in rounds.
There is a single ball.
At the beginning of each round one of the bears holds the ball.
This bear chooses a direction and throws the ball in that direction.
The ball will travel along a straight line.
As soon as the ball hits another bear for the first time, that bear will catch the ball and the round will end.
It is not allowed to throw the ball in a direction where it won't hit any other bear.

At the beginning of the game, the bears choose two special roles: 
one bear will be the Startbear and another bear will be the Goalbear.
The Startbear has the ball at the beginning of the game.
The game ends when the Goalbear gets the ball.
Bears always play optimally — they always finish the game in the smallest possible number of rounds.

There are exactly N*(N-1) ways to choose the Startbear and the Goalbear.
For each of those ways, determine the smallest possible number of rounds the game may take.
Return the sum of those N*(N-1) numbers.

DEFINITION
Class:BearBall
Method:countThrows
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int countThrows(vector <int> x, vector <int> y)


CONSTRAINTS
-N will be between 2 and 1500, inclusive.
-x will contain exactly N elements.
-y will contain exactly N elements.
-Each element in x and in y will be between -20,000 and 20,000, inclusive.
-No two points will coincide.


EXAMPLES

0)
{1,4,2}
{1,10,7}

Returns: 6

There are three bears. They stand at (1,1), (4,10), and (2,7).

There are six ways to choose the Startbear and the Goalbear.
In each of those six cases the game will have a single round, because the Startbear can throw the ball directly at the Goalbear.
So, the answer is 6.

1)
{0,0,0,1,1}
{0,1,2,0,1}

Returns: 22

There are five bears. They stand at (0,0), (0,1), (0,2), (1,0), and (1,1).

There are 20 ways to choose the two special bears. In 18 of those 20 ways a single throw is enough. In each of the remaining two ways the bears need two rounds of the game.

Consider the situation when the Startbear is at (0,0) and the Goalbear is at (0,2). 
This game cannot be won in a single round:
if the Startbear throws a ball in the direction of the Goalbear, the ball will hit the bear at (0,1) and that bear will catch it.

There are multiple ways to win that game in two rounds.
For example, after the Startbear hits the bear at (0,1), that bear will throw the ball to the Goalbear.
Another optimal strategy is to start by throwing the ball from (0,0) to (1,1).
This is shown in the figure below; the bear with the ball is painted red.



2)
{5,7,9,11}
{4,3,2,1}

Returns: 20



3)
{10,10,50,50,90,90}
{5,17,5,17,5,17}

Returns: 34



4)
{-100, -90, -80, -70, -85, -90, 0, 20}
{-5, -8, -13, -21, -13, -13, -13, -69}

Returns: 68



******************************/
// END CUT HERE
#line 105 "BearBall.cpp"
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
#define DD(v) cout<<#v<<": "<<(v)<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

int INF = 1<<30;
int N;
int w[1501][1501];


class BearBall1 {
	public:
	int countThrows(vector <int> x, vector <int> y) {
		N = x.size();
		ll ans = 0;
		REP(i, N) {
			map<pair<int, int>, int> chk;
			REP(j, N) if(i!=j) {
				int dx = x[i]-x[j];
				int dy = y[i]-y[j];
				int g = gcd(abs(dx), abs(dy));
				dx/=g; dy/=g;
				++chk[make_pair(dx,dy)];
			}
			for(auto& p: chk) {
				int u = chk.size()-1;
				if(chk.count(MP(-p.first.first, -p.first.second))) u--;
				if(u) ans+=p.second*2-1;
				else ans += p.second*(p.second+1)/2;
			}
		}
		return ans;
	}
};

class BearBall {
	public:
	int countThrows(vector <int> x, vector <int> y) {
		N = x.size();
		REP(i, N) REP(j, N) w[i][j]=i==j?0:INF;
		REP(i, N) {
			map<pair<int, int>, vector<pair<ll, int>>> m;
			REP(j, N) if(i!=j) {
				ll dx = x[j]-x[i];
				ll dy = y[j]-y[i];
				int g = gcd(abs(dx), abs(dy));
				ll l2 = dx*dx+dy*dy;
				m[MP(dx/g, dy/g)].PB(MP(l2, j));
			}
			if(m.size()==1) {
				ll ans = 0;
				RANGE(i, 1, N) ans += (N-i)*i;
				return ans*2;
			}
			for(auto& kv:m) {
				auto& ls = kv.second;
				sort(ALL(ls));
				if(ls.size()) {
//					REP(ii, ls.size()) cout<<ii<<" "<<ls[ii]<<endl;
//					cout<<i<<" "<<kv.first<<" "<<ls[0].second<<endl;
					w[i][ls[0].second] = 1;
				}
			}
		}
		REP(i, N) REP(j, N) if(i!=j) {
			if(w[i][j]==INF) {
				w[i][j]=w[j][i]=2;
			}
		}
//		REP(k, N) REP(i, N) REP(j, N) if(w[i][k]!=INF && w[k][j]!=INF) w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
////		DD("AFTER");
		ll ans = 0;
		REP(i, N) REP(j, N) ans += w[i][j];
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
#define END	 verify_case(_, BearBall().countThrows(x, y));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int x_[] = {-8192, 0, -8192, 8192, 8192, 8192, 0, -16384, -16384, 0, -16384, 16384, 0, 8192, 8192, 16384, 16384, -16384, -16384, 16384, -8192, 0, -8192, 16384, -8192};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {8192, 0, -16384, 8192, -8192, 16384, 8192, -16384, 16384, 16384, -8192, 16384, -16384, 0, -16384, -8192, -16384, 0, 8192, 8192, 16384, -8192, 0, 0, -8192};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 800; 
END
return 0;

CASE(0)
	vector<int> x, y;
	REP(xi, 40) REP(yi, 37) {
		x.PB(xi);
		y.PB(yi);
	}
//	cout<<"{";
//	REP(i, x.size()) {
//		cout<<x[i];
//		if(i<x.size()-1) cout<<",";
//	}
//	cout<<"}"<<endl;
//	cout<<"{";
//	REP(i, y.size()) {
//		cout<<y[i];
//		if(i<y.size()-1) cout<<",";
//	}
//	cout<<"}"<<endl;
	int _ = 3044802; 
END
CASE(0)
	vector<int> x, y;
	REP(i, 1500) {
		x.PB(i);
		y.PB(i);
	}
//	cout<<"{";
//	REP(i, x.size()) {
//		cout<<x[i];
//		if(i<x.size()-1) cout<<",";
//	}
//	cout<<"}"<<endl;
//	cout<<"{";
//	REP(i, y.size()) {
//		cout<<y[i];
//		if(i<y.size()-1) cout<<",";
//	}
//	cout<<"}"<<endl;
	int _ = 1124999500; 
END
//return 0;

CASE(0)
	int x_[] = {1,4,2};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {1,10,7};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 6; 
END
CASE(1)
	int x_[] = {0,0,0,1,1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,1,2,0,1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 22; 
END
//return 0;
CASE(2)
	int x_[] = {5,7,9,11};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {4,3,2,1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 20; 
END
CASE(3)
	int x_[] = {10,10,50,50,90,90};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {5,17,5,17,5,17};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 34; 
END
CASE(4)
	int x_[] = {-100, -90, -80, -70, -85, -90, 0, 20};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-5, -8, -13, -21, -13, -13, -13, -69};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 68; 
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
	int N=UNIFORM_LL(1, 1500);
	vector<PII> cn(N);
	REP(i, N) cn[i]=MP(UNIFORM_LL(0, 20000), UNIFORM_LL(0, 20000));
	sort(ALL(cn));
	cn.erase(unique(ALL(cn)), cn.end());
	N = cn.size();
	DD(N);
	vector <int> x(N), y(N); 
	REP(i, N) x[i]=cn[i].first,y[i]=cn[i].second;

	int _0 = BearBall().countThrows(x, y);
	int _1 = BearBallRef().countThrows(x, y);
	if(!verify_case(_0, _1, true)) {
print(x);
print(y);
	}
}
#endif

}
// END CUT HERE
