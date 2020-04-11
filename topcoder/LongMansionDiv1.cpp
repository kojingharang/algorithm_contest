// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// LYC is the pet dog of Emperor Zhangzj of Yali Empire. Zhangzj has a huge affluence. Besides his palace, he has multiple estates. One of them is the Long Mansion, a famous site in Yali. LYC loves to play. One day, he accidentally enters the labyrinthine Long Mansion.

The mansion can be seen as a grid of unit square cells. There are N rows, indexed from 0 to (N - 1). The number of columns is infinite in one direction. The columns are indexed by nonnegative integers, starting from 0. You are given ints sX, sY, eX, eY. Initially LYC is standing on the cell on the sXth row, and the sYth column. The exit is at the cell on the eXth row, and the eYth column. LYC can walk to a cell that shares an edge with the cell he is at. He wished to reach the exit as soon as possible.

Unfortunately, each cell contains some obstacles that slow LYC down. For each cell we know the time LYC needs to spend there while passing through the cell. LYC also needs to spend that amount of time in the initial cell and in the exit cell as well. There is a pattern to the obstacles: each column of the mansion looks the same. In other words, all cells within any given row contain the same obstacle type, and therefore they delay LYC by the same amount of time. For example, the entire first row are some bushes, the entire second row contains some walls, and so on. You are given the times in the vector <int> t. More precisely, LYC will spend t[i] time in each cell he visits in row i.

You are given one vector <int> t and 4 ints sX, sY, eX, eY. Return the minimal time LYC needs to spend to reach the exit.

DEFINITION
Class:LongMansionDiv1
Method:minimalTime
Parameters:vector <int>, int, int, int, int
Returns:long long
Method signature:long long minimalTime(vector <int> t, int sX, int sY, int eX, int eY)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-t will contain exactly N elements.
-Each element of t will be between 1 and 1,000, inclusive.
-sX and eX will be between 0 and (N - 1), inclusive.
-sY and eY will be between 0 and 1,000,000,000 inclusive.


EXAMPLES

0)
{5, 3, 10}
2
0
2
2

Returns: 29

The optimal path would be (2, 0) &rarr (1, 0) &rarr (1, 1) &rarr (1, 2) &rarr (2, 2). The total time would be 10 + 3 + 3 + 3 + 10 = 29. Note that you should count the time LYC spends on the inital cell and the cell of the exit as well.


1)
{5, 3, 10}
0
2
0
0

Returns: 15

This time the optimal path would be (0, 2) &rarr (0, 1) &rarr (0, 0).


2)
{137, 200, 184, 243, 252, 113, 162}
0
2
4
2

Returns: 1016



3)
{995, 996, 1000, 997, 999, 1000, 997, 996, 1000, 996, 1000, 997, 999, 996, 1000, 998, 999, 995, 995, 998, 995, 998, 995, 997, 998, 996, 998, 996, 997, 1000, 998, 997, 995, 1000, 996, 997, 1000, 997, 997, 999, 998, 995, 999, 999, 1000, 1000, 998, 997, 995, 999}
18
433156521
28
138238863

Returns: 293443080673



4)
{1}
0
0
0
0

Returns: 1



*/
// END CUT HERE
#line 90 "LongMansionDiv1.cpp"

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
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class LongMansionDiv1 {
	public:
	long long minimalTime(vector <int> t, int sX, int sY, int eX, int eY) {
		int N = t.size();
		ll ans = 1LL<<60;
		REP(i, N) {
			ll lans = 0;
			{
				ll a = i;
				ll b = sX;
				if(a>b) swap(a, b);
				RANGE(j, a, b+1) lans += t[j];
			}
			{
				ll a = i;
				ll b = eX;
				if(a>b) swap(a, b);
				RANGE(j, a, b+1) lans += t[j];
			}
			lans += (abs(sY-eY)-1LL) * t[i];
			ans = min(ans, lans);
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const long long& Expected, const long long& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, LongMansionDiv1().minimalTime(t, sX, sY, eX, eY));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){


CASE(0)
	int t_[] = {5, 3, 10};
	  vector <int> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	int sX = 2; 
	int sY = 0; 
	int eX = 0; 
	int eY = 0; 
	long long _ = 18LL; 
END

CASE(0)
	int t_[] = {5, 3, 10};
	  vector <int> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	int sX = 0; 
	int sY = 0; 
	int eX = 2; 
	int eY = 0; 
	long long _ = 18LL; 
END

CASE(0)
	int t_[] = {5, 3, 10};
	  vector <int> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	int sX = 2; 
	int sY = 0; 
	int eX = 1; 
	int eY = 0; 
	long long _ = 13LL; 
END

CASE(0)
	int t_[] = {5, 3, 10};
	  vector <int> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	int sX = 2; 
	int sY = 0; 
	int eX = 2; 
	int eY = 1; 
	long long _ = 20LL; 
END

CASE(0)
	int t_[] = {5, 3, 10};
	  vector <int> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	int sX = 2; 
	int sY = 0; 
	int eX = 2; 
	int eY = 0; 
	long long _ = 10LL; 
END

CASE(0)
	int t_[] = {5, 3, 10};
	  vector <int> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	int sX = 2; 
	int sY = 0; 
	int eX = 2; 
	int eY = 2; 
	long long _ = 29LL; 
END
CASE(1)
	int t_[] = {5, 3, 10};
	  vector <int> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	int sX = 0; 
	int sY = 2; 
	int eX = 0; 
	int eY = 0; 
	long long _ = 15LL; 
END
CASE(2)
	int t_[] = {137, 200, 184, 243, 252, 113, 162};
	  vector <int> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	int sX = 0; 
	int sY = 2; 
	int eX = 4; 
	int eY = 2; 
	long long _ = 1016LL; 
END
CASE(3)
	int t_[] = {995, 996, 1000, 997, 999, 1000, 997, 996, 1000, 996, 1000, 997, 999, 996, 1000, 998, 999, 995, 995, 998, 995, 998, 995, 997, 998, 996, 998, 996, 997, 1000, 998, 997, 995, 1000, 996, 997, 1000, 997, 997, 999, 998, 995, 999, 999, 1000, 1000, 998, 997, 995, 999};
	  vector <int> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	int sX = 18; 
	int sY = 433156521; 
	int eX = 28; 
	int eY = 138238863; 
	long long _ = 293443080673LL; 
END
CASE(4)
	int t_[] = {1};
	  vector <int> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	int sX = 0; 
	int sY = 0; 
	int eX = 0; 
	int eY = 0; 
	long long _ = 1LL; 
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
	vector <int> t; 
	{
		int N=UNIFORM_LL(1, 51);
		t = vector <int>(N); 
		REP(i, N) {
			t[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int sX = UNIFORM_LL(0, 100); 
// param type: int
	int sY = UNIFORM_LL(0, 100); 
// param type: int
	int eX = UNIFORM_LL(0, 100); 
// param type: int
	int eY = UNIFORM_LL(0, 100); 
	long long _0 = LongMansionDiv1().minimalTime(t, sX, sY, eX, eY);
	long long _1 = LongMansionDiv1Ref().minimalTime(t, sX, sY, eX, eY);
	if(!verify_case(_0, _1, true)) {
print(t);
print(sX);
print(sY);
print(eX);
print(eY);
	}
}
#endif

}
// END CUT HERE
