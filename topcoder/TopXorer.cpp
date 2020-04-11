// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Like Topcoder, TopXorer uses a rating system.
The rating of each person is a non-negative integer.



You are a coach.
You want to select an n-person team.
The team members will be labeled 0 through n-1.
You have a set of constraints decribed by the vector <int> x with n elements.
For each valid i, the rating of team member i must be between 0 and x[i], inclusive.



As the name suggests, the rating of a team in TopXorer is computed as the bitwise xor of the ratings of all team members.



You are given the vector <int>s x.
Please compute and return the maximal team rating your team can have.

DEFINITION
Class:TopXorer
Method:maximalRating
Parameters:vector <int>
Returns:int
Method signature:int maximalRating(vector <int> x)


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-Each element in x will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
{2,2,2}

Returns: 3

One optimal solution is to select people with ratings (2, 0, 1).
The team rating will then be (2 xor 0 xor 1) = 3.

1)
{1,2,4,8,16}

Returns: 31

This time the only optimal solution is to select people with the largest possible ratings.

2)
{1024,1024}

Returns: 2047



3)
{7,4,12,33,6,8,3,1}

Returns: 47



4)
{0}

Returns: 0



*/
// END CUT HERE
#line 78 "TopXorer.cpp"

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

ll ans, lans;
void f(int idx, const vector<int>& x) {
	if(idx==x.size()) {
		ans = max(ans, lans);
		return;
	}
	REP(v, x[idx]+1) {
		lans ^= v;
		f(idx+1, x);
		lans ^= v;
	}
}

ll naive(vector<int> x) {
	ans = lans = 0;
	f(0, x);
	return ans;
}

class TopXorer {
	public:
	int maximalRating(vector <int> x) {
//		return naive(x);
		ll N = x.size();
		sort(ALLR(x));
		VI w(60);
		REP(i, N) for(int j=60;j>=0;j--) if(((ll)x[i])>>j&1) { w[j]++; }
//		DD(w);
		REP(i, w.size()) if(w[i]>=2) REP(j, i) w[j]=1;
		ll ans = 0;
		REP(i, w.size()) if(w[i]) ans |= 1LL<<i;
//		DD(w);
		return ans;
	}
};

class TopXorerRef {
	public:
	int maximalRating(vector <int> x) {
		multiset<int, greater<int>> s(ALL(x));
		int ans = 0;
		vector<char> used(31);
		s.erase(0);
		while(!s.empty()) {
			int v = *s.begin();
			s.erase(s.begin());
			bool done = 0;
			for(int i=30;i>=0;--i) {
				if(used[i]) continue;
				if(v>=1 << i) {
					v-=1<<i;
					ans+=1<i;
					if(v) s.insert(v);
					used[i]=1;
					done=1;
				}
			}
			if(!done) break;
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
#define END	 verify_case(_, TopXorer().maximalRating(x));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

if(0)
REP(loop, 1000) {
	ll N = UNIFORM_LL(1, 8);
	vector<int> x(N);
	REP(i, N) x[i] = UNIFORM_LL(0, 20);
	ll ref = naive(x);
	ll ans = TopXorer().maximalRating(x);
	DD(x);
	DD(ref);
	DD(ans);
	assert(ref==ans);
}

CASE(0)
	int x_[] = {2,2,2};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int _ = 3; 
END
CASE(1)
	int x_[] = {1,2,4,8,16};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int _ = 31; 
END
CASE(2)
	int x_[] = {1024,1024};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int _ = 2047; 
END
CASE(3)
	int x_[] = {7,4,12,33,6,8,3,1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int _ = 47; 
END
CASE(4)
	int x_[] = {0};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int _ = 0; 
END
#if 01  // DO RANDOM TESTS

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
for(int loop=0;loop<10000;loop++) {
// param type: int
	vector <int> x; 
	{
		int N=UNIFORM_LL(1, 51);
		x = vector <int>(N); 
		REP(i, N) {
			x[i] = UNIFORM_LL(0, 1000000);
		}
	}
	int _0 = TopXorer().maximalRating(x);
	int _1 = TopXorerRef().maximalRating(x);
	if(!verify_case(_0, _1, true)) {
print(x);
	}
}
#endif

}
// END CUT HERE
