// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Hero is inviting his friends to the party.
He has n friends, numbered 0 through n-1.
For each of his friends there is at most one other person the friend dislikes.
You are given this information as a vector <int> a with n elements.
For each i, a[i] is either the number of the person disliked by friend i, we have a[i]=i if friend i likes everybody else.

Hero is inviting his friends one at a time.
Whenever he invites friend i, they will accept if and only if the friend a[i] didn't accept an earlier invitation.
(That includes two cases: either Hero didn't invite friend a[i] yet, or he did but the friend rejected the invitation.)

Hero noticed that the order in which he invites his friends matters: different orders may produce different numbers of accepted invitations.
He thought about finding the best order but the task was too hard for him.
Therefore he has decided that he will invite his friends in a randomly chosen order.
(Each permutation of his friends is equally likely to be chosen.)

Return the expected number of friends that will accept Hero's invitation.

DEFINITION
Class:Privateparty
Method:getexp
Parameters:vector <int>
Returns:double
Method signature:double getexp(vector <int> a)


NOTES
-Your solution is correct if the absolute error or the relative error is at most 10^-9.


CONSTRAINTS
-a will contain exactly n elements.
-n will be between 1 and 50, inclusive.
-Each element of a will be between 0 and n - 1, inclusive.


EXAMPLES

0)
{0,1}

Returns: 2.0

There are two friends.
As a[0]=0 and a[1]=1, each friend likes the other.
Regardless of the order of invitations, both will always accept.

1)
{0,0}

Returns: 1.5

In this test case friend 1 dislikes friend 0.
If Hero invites 0 first and 1 next, 0 will accept and then 1 will reject.
If Hero invites 1 first and 0 next, 1 will accept (as 0 didn't accept yet) and then 0 will accept as well (because he likes 1).

2)
{0,1,1}

Returns: 2.5

Now there are three friends.
Friend 0 likes everybody else, friend 1 likes everybody else, and friend 2 dislikes friend 1.
Given three friends, there are six possible orders.
Hero will choose one of these orders uniformly at random.
For example, if he invites them in the order (1,0,2), friend 1 will accept, friend 0 will accept, and friend 2 will reject the invitation.
However, if he invites them in the order (2,1,0), all three friends will accept the invite.

3)
{0,1,1,2}

Returns: 3.166666666666667



4)
{3,2,1,0}

Returns: 2.0



******************************/
// END CUT HERE
#line 88 "Privateparty.cpp"
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

class Privateparty {
	public:
	double getexp(vector <int> a) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const double& Expected, const double& Received, bool noPASSmsg=false) {
 double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, Privateparty().getexp(a));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int a_[] = {0,1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	double _ = 2.0; 
END
CASE(1)
	int a_[] = {0,0};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	double _ = 1.5; 
END
CASE(2)
	int a_[] = {0,1,1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	double _ = 2.5; 
END
CASE(3)
	int a_[] = {0,1,1,2};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	double _ = 3.166666666666667; 
END
CASE(4)
	int a_[] = {3,2,1,0};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	double _ = 2.0; 
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
	vector <int> a; 
	{
		int N=UNIFORM_LL(1, 51);
		a = vector <int>(N); 
		REP(i, N) {
			a[i] = UNIFORM_LL(0, 1000);
		}
	}
	double _0 = Privateparty().getexp(a);
	double _1 = PrivatepartyRef().getexp(a);
	if(!verify_case(_0, _1, true)) {
print(a);
	}
}
#endif

}
// END CUT HERE
