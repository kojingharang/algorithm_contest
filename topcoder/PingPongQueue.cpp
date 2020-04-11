// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// This task is about a group of people who like to play ping pong.
All games of ping pong mentioned in this task are one-on-one games.

You are given a vector <int> skills.
Each element of skills is the skill level of one person in the group.
The skill levels are all distinct.
Whenever two people play a game of ping pong, the one with the higher skill level always wins.

All people in the group would like to play but they only have a single table.
Therefore, only two people can play at any given time.

There will be a sequence of games, numbered starting from 1.
Game 1 will be played by the players who correspond to skills[0] and skills[1].
All the remaining people will form a queue, in the order in which they are given in skills.
After each game the following things will happen, in order:

The person who lost the game leaves the table and goes to the end of the queue.
If the person who won the game has already won N games in a row, they also leave the table and they go to the end of the queue (behind the person who lost the last game).
While there are fewer than two people at the table, the first person in the queue leaves the queue and goes to the table.
The two people at the table play the next game.


You are given the vector <int> skills, the int N, and an int K.
Return the two-element vector <int> { L, W }, where L and W are the skills of the loser and the winner of game K, in this order.

DEFINITION
Class:PingPongQueue
Method:whoPlaysNext
Parameters:vector <int>, int, int
Returns:vector <int>
Method signature:vector <int> whoPlaysNext(vector <int> skills, int N, int K)


CONSTRAINTS
-skills will contain between 2 and 50 elements, inclusive.
-Each element of skills will be between 1 and 50, inclusive.
-All elements of skills will be distinct.
-N will be between 1 and 100, inclusive.
-K will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1, 2, 3}
2
2

Returns: {2, 3 }

In all annotations, we call people by their skill. For example, "player 7" means "the player whose skill level is 7".

In this example players 1 and 2 play the first game, and player 2 wins.
For the second game, player 3 joins player 2, so we return { 2, 3 }.

1)
{1, 2, 3}
2
4

Returns: {1, 2 }

The sequence of games is as follows:

Player 1 loses to player 2.
Player 2 loses to player 3.
Player 1 loses to player 3. After this player 1 joins the queue, player 3 also steps down because he just won 2 games in a row and joins the queue.
Player 1 loses to player 2.


2)
{49, 24, 26, 12, 5, 33, 25, 30, 35, 41, 46, 23, 21, 3, 38, 43, 11, 19, 34, 29, 20, 32, 39, 7, 50}
10
399

Returns: {12, 50 }



3)
{30, 12}
34
80

Returns: {12, 30 }



*/
// END CUT HERE
#line 95 "PingPongQueue.cpp"

#include <vector>
#include <map>
#include <set>
#include <deque>
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



class PingPongQueue {
	public:
	vector <int> whoPlaysNext(vector <int> skills, int N, int K) {
		deque<int> q(ALL(skills));
		map<int, int> seq;
		REP(i, K) {
//			DD(i);
//			cout<<q<<endl;
//			cout<<seq<<endl;
			int L = min(q[0], q[1]);
			int W = max(q[0], q[1]);
			q.pop_front();
			q.pop_front();
			q.push_back(L);
			seq[L]=0;
			seq[W]++;
			if(seq[W]==N) {
				q.push_back(W);
				seq[W]=0;
			}
			else q.push_front(W);
			if(i==K-1) return {L, W};
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
#define END	 verify_case(_, PingPongQueue().whoPlaysNext(skills, N, K));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int skills_[] = {1, 2, 3};
	  vector <int> skills(skills_, skills_+sizeof(skills_)/sizeof(*skills_)); 
	int N = 2; 
	int K = 2; 
	int __[] = {2, 3 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	int skills_[] = {1, 2, 3};
	  vector <int> skills(skills_, skills_+sizeof(skills_)/sizeof(*skills_)); 
	int N = 2; 
	int K = 4; 
	int __[] = {1, 2 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	int skills_[] = {49, 24, 26, 12, 5, 33, 25, 30, 35, 41, 46, 23, 21, 3, 38, 43, 11, 19, 34, 29, 20, 32, 39, 7, 50};
	  vector <int> skills(skills_, skills_+sizeof(skills_)/sizeof(*skills_)); 
	int N = 10; 
	int K = 399; 
	int __[] = {12, 50 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	int skills_[] = {30, 12};
	  vector <int> skills(skills_, skills_+sizeof(skills_)/sizeof(*skills_)); 
	int N = 34; 
	int K = 80; 
	int __[] = {12, 30 };
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
	vector <int> skills; 
	{
		int N=UNIFORM_LL(1, 51);
		skills = vector <int>(N); 
		REP(i, N) {
			skills[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int N = UNIFORM_LL(0, 100); 
// param type: int
	int K = UNIFORM_LL(0, 100); 
	vector <int> _0 = PingPongQueue().whoPlaysNext(skills, N, K);
	vector <int> _1 = PingPongQueueRef().whoPlaysNext(skills, N, K);
	if(!verify_case(_0, _1, true)) {
print(skills);
print(N);
print(K);
	}
}
#endif

}
// END CUT HERE
