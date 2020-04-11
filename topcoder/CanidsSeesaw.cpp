// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There are n wolves and n foxes.
Both wolves and foxes are numbered 0 through n-1.
You are given the vector <int>s wolf and fox.
Here, wolf[i] is the weight of wolf i and fox[i] is the weight of fox i.


The wolves and the foxes are playing on a seesaw.
Initially both sides of the seesaw are empty.
Then, there will be n rounds.
In each round a new wolf will sit on the left side of the seesaw and a new fox will sit on the right side of the seesaw.
The wolves and foxes stay on the seesaw also for all future rounds.
Thus, after x rounds there will be x wolves on the left side of the seesaw and x foxes on its right side.


After each round, the side of the seesaw that touches the ground scores a point.
All animals sit very close to the ends of the seesaw, hence the side that touches the ground is always the side where the total weight of animals is greater.
(The constraints guarantee that there will never be a draw: one side will always be heavier than the other.)


The wolves will go sit on the seesaw in numerical order: wolf 0 first, wolf 1 second, and so on.
The foxes may choose any order in which to go on the seesaw.


You are given an int k.
The foxes want to score exactly k points.
Can they do that? If yes, in what order should they go on the seesaw?


Find and return a vector <int> containing a permutation of 0 through n-1: an order in which the foxes should go on the seesaw in order to score exactly k points.
That is, return a vector <int> p such that fox p[0] should go on the seesaw first, fox p[1] second, and so on.


If there are multiple solutions, you may return any of them.
If there is no solution, return an empty vector <int> instead.

DEFINITION
Class:CanidsSeesaw
Method:construct
Parameters:vector <int>, vector <int>, int
Returns:vector <int>
Method signature:vector <int> construct(vector <int> wolf, vector <int> fox, int k)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-wolf will contain exactly n elements.
-fox will contain exactly n elements.
-Each element in wolf will be between 1 and 3000, inclusive.
-Each element in fox will be between 1 and 3000, inclusive.
-k will be between 0 and n, inclusive.
-For every permutation of the foxes, after each round the weights on both sides of the seesaw will be different.


EXAMPLES

0)
{3,1}
{4,2}
1

Returns: {1, 0 }

First, note that after two rounds the wolves on the seesaw will have a total weight of 3+1 = 4, and the foxes will have a total weight of 4+2 = 6.
At that moment the foxes will score a point.
As they want to score exactly one point, they have to make sure that after the first round the wolves score a point.
In order to do that, fox 1 should go on the seesaw first.

1)
{1,3}
{4,2}
1

Returns: { }

This time the foxes will surely score both points, so there is no solution.

2)
{10,10,10,10,10,10,10,10,10,10}
{1,100,1,100,1,100,1,100,1,100}
7

Returns: {0, 2, 4, 1, 6, 3, 5, 7, 9, 8 }



3)
{10,10,10,10,10,10,10,10,10,10}
{1,100,1,100,1,100,1,100,1,100}
4

Returns: { }



4)
{2}
{1}
0

Returns: {0 }



*/
// END CUT HERE
#line 110 "CanidsSeesaw.cpp"

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


vector <int> naive(vector <int> wolf, vector <int> fox, int k) {
	int N = wolf.size();
	DD(k);
	RANGE(i, 1, N) wolf[i] += wolf[i-1];
	vector<int> fi(N);
	REP(i, N) fi[i]=i;
	do {
		ll v = 0;
		ll ans = 0;
		vector<bool> win(N);
		REP(i, N) {
			v+=fox[fi[i]];
			if(wolf[i]<v) ans++;
			if(wolf[i]<v) win[i]=1;
		}
//		if(ans==k) DD("ok"),DD(fi),DD(win);
		if(ans==k) return fi;
	} while(next_permutation(ALL(fi)));
	return {};
}

class CanidsSeesaw {
	public:
	vector <int> construct(vector <int> wolf, vector <int> fox, int k) {
		int N = wolf.size();
		RANGE(i, 1, N) wolf[i] += wolf[i-1];
		auto Cnt = [&](const vector<int>& fi) {
			ll v = 0;
			ll ans = 0;
			REP(i, N) {
				v+=fox[fi[i]];
				if(wolf[i]<v) ans++;
			}
			return ans;
		};
		{
			vector<pair<int, int>> w(N);
			REP(i, N) w[i]=MP(fox[i], i);
			sort(ALL(w));
			vector<int> fi(N);
			REP(i, N) fi[i]=w[i].second;
			ll Min = Cnt(fi);
			if(Min==k) return fi;
			REP(i, N) for(int j=i-1;j>=0;j--) {
				swap(fi[j], fi[j+1]);
				if(Cnt(fi)==k) return fi;
			}
		}
		return {};
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const vector <int>& Expected, const vector <int>& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, CanidsSeesaw().construct(wolf, fox, k));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

REP(i, 1000) {
	int N=UNIFORM_LL(1, 11);
	vector <int> wolf; 
	{
		wolf = vector <int>(N); 
		REP(i, N) {
			wolf[i] = UNIFORM_LL(1, 3000);
		}
	}
	vector <int> fox; 
	{
		fox = vector <int>(N); 
		REP(i, N) {
			fox[i] = UNIFORM_LL(1, 3000);
		}
	}
	int k = UNIFORM_LL(0, N+1); 
	auto t = CanidsSeesaw().construct(wolf, fox, k);
	auto ref = naive(wolf, fox, k);
	DD(wolf);
	DD(fox);
	DD(k);
	DD(t);
	DD(ref);
	assert(ref.size()==t.size());
}

CASE(0)
	int wolf_[] = {3,1};
	  vector <int> wolf(wolf_, wolf_+sizeof(wolf_)/sizeof(*wolf_)); 
	int fox_[] = {4,2};
	  vector <int> fox(fox_, fox_+sizeof(fox_)/sizeof(*fox_)); 
	int k = 1; 
	int __[] = {1, 0 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	int wolf_[] = {1,3};
	  vector <int> wolf(wolf_, wolf_+sizeof(wolf_)/sizeof(*wolf_)); 
	int fox_[] = {4,2};
	  vector <int> fox(fox_, fox_+sizeof(fox_)/sizeof(*fox_)); 
	int k = 1; 
	vector <int> _; 
END
CASE(2)
	int wolf_[] = {10,10,10,10,10,10,10,10,10,10};
	  vector <int> wolf(wolf_, wolf_+sizeof(wolf_)/sizeof(*wolf_)); 
	int fox_[] = {1,100,1,100,1,100,1,100,1,100};
	  vector <int> fox(fox_, fox_+sizeof(fox_)/sizeof(*fox_)); 
	int k = 7; 
	int __[] = {0, 2, 4, 1, 6, 3, 5, 7, 9, 8 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	int wolf_[] = {10,10,10,10,10,10,10,10,10,10};
	  vector <int> wolf(wolf_, wolf_+sizeof(wolf_)/sizeof(*wolf_)); 
	int fox_[] = {1,100,1,100,1,100,1,100,1,100};
	  vector <int> fox(fox_, fox_+sizeof(fox_)/sizeof(*fox_)); 
	int k = 4; 
	vector <int> _; 
END
CASE(4)
	int wolf_[] = {2};
	  vector <int> wolf(wolf_, wolf_+sizeof(wolf_)/sizeof(*wolf_)); 
	int fox_[] = {1};
	  vector <int> fox(fox_, fox_+sizeof(fox_)/sizeof(*fox_)); 
	int k = 0; 
	int __[] = {0 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
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
	vector <int> wolf; 
	{
		int N=UNIFORM_LL(1, 51);
		wolf = vector <int>(N); 
		REP(i, N) {
			wolf[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> fox; 
	{
		int N=UNIFORM_LL(1, 51);
		fox = vector <int>(N); 
		REP(i, N) {
			fox[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int k = UNIFORM_LL(0, 100); 
	vector <int> _0 = CanidsSeesaw().construct(wolf, fox, k);
	vector <int> _1 = CanidsSeesawRef().construct(wolf, fox, k);
	if(!verify_case(_0, _1, true)) {
print(wolf);
print(fox);
print(k);
	}
}
#endif

}
// END CUT HERE
