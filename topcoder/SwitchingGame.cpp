// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// You're playing a game with lamps.
There are M lamps in a row.
The lamps are numbered 0 through M-1.
Initially, all lamps are turned off.

The game consists of N levels.
The levels are numbered 0 through N-1.
Each level is described by a string of M characters.
For each i, character i of that string gives the required state of lamp i.
Each of these characters will be either '+', '-', or '?'.
Here, '+' means that the lamp must be on, '-' means that the lamp must be off, and '?' means that the lamp may be in either state.

The game is played in turns.
Each turn takes one second.
In each turn, you may do one of three things:

You may choose any subset of lamps that are all turned off, and turn all of them on.
You may choose any subset of lamps that are all turned on, and turn all of them off.
You may press the big red button that says "Check!".

Whenever you press the button, the current states of all lamps are checked against the requirements of the current level.
If all lamps satisfy the requirements, you solved the current level.
You win the game by solving all N levels.
You must solve the levels in the given order, starting with level 0.
Note that the lamps do not reset between levels: you continue playing the next level from the state you had when you solved the previous level.

Return the smallest number of seconds it takes to win the game if you play optimally.


DEFINITION
Class:SwitchingGame
Method:timeToWin
Parameters:vector <string>
Returns:int
Method signature:int timeToWin(vector <string> states)


CONSTRAINTS
-states will contain exactly N elements.
-N will be between 1 and 50, inclusive.
-Each element of states will contain exactly M characters.
-M will be between 1 and 50, inclusive.
-Each character of states will be '+', '-' or '?'.


EXAMPLES

0)
{"++--",
 "--++"}

Returns: 5

The following sequence of actions wins the game in five seconds:

Turn lamps 0 and 1 on.
Press the button to win level 0.
Turn lamps 0 and 1 off.
Turn lamps 2 and 3 on.
Press the button to win level 1 and thus win the game.


1)
{"+-++",
 "+-++"}

Returns: 3

Each time you press the button you can only win a single level.
Even though levels 0 and 1 are identical, you have to press the button twice in a row to win both of them.


2)
{"++",
 "+?",
 "?+",
 "++"}

Returns: 5

Here we can simply turn both lamps on, and then use that configuration to win all four levels.

3)
{"+", 
 "?",
 "?",
 "?",
 "-"}

Returns: 7

At some point between winning level 0 and winning level 4 we have to turn the lamp off.

4)
{"+??+++",
 "++??+-",
 "?++??+",
 "?-+-??",
 "??+?++",
 "++-?+?",
 "?++?-+",
 "?--+++",
 "-??-?+"}


Returns: 20



******************************/
// END CUT HERE
#line 116 "SwitchingGame.cpp"
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "<<endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class SwitchingGame {
	public:
	int timeToWin(vector <string> S) {
		int N=S.size(), M=S[0].size();
		string cur(M, '-');
		int ans=0;
		REP(i, N) {
			int mp=0, pm=0;
			REP(j, M) {
				if(cur[j]=='-' && S[i][j]=='+') cur[j]=S[i][j], mp=1;
				if(cur[j]=='+' && S[i][j]=='-') cur[j]=S[i][j], pm=1;
			}
			if(mp) {
				REP(j, M)if(S[i][j]=='?') {
					char nxt='?';
					RANGE(k, i+1, N) if(S[k][j]!='?') {nxt=S[k][j];break;}
					if(nxt=='+') cur[j]=nxt;
				}
			}
			if(pm) {
				REP(j, M)if(S[i][j]=='?') {
					char nxt='?';
					RANGE(k, i+1, N) if(S[k][j]!='?') {nxt=S[k][j];break;}
					if(nxt=='-') cur[j]=nxt;
				}
			}
			ans+=1+mp+pm;
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
#define END	 verify_case(_, SwitchingGame().timeToWin(states));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string states_[] = {
"?+??",
"-?++"
};
	  vector <string> states(states_, states_+sizeof(states_)/sizeof(*states_)); 
	int _ = 3; 
END

CASE(0)
	string states_[] = {"++--",
 "--++"};
	  vector <string> states(states_, states_+sizeof(states_)/sizeof(*states_)); 
	int _ = 5; 
END
//return 0;
CASE(1)
	string states_[] = {"+-++",
 "+-++"};
	  vector <string> states(states_, states_+sizeof(states_)/sizeof(*states_)); 
	int _ = 3; 
END
CASE(2)
	string states_[] = {"++",
 "+?",
 "?+",
 "++"};
	  vector <string> states(states_, states_+sizeof(states_)/sizeof(*states_)); 
	int _ = 5; 
END
CASE(3)
	string states_[] = {"+", 
 "?",
 "?",
 "?",
 "-"};
	  vector <string> states(states_, states_+sizeof(states_)/sizeof(*states_)); 
	int _ = 7; 
END
CASE(4)
	string states_[] = {
"+??+++",
 "++??+-",
 "?++??+",
 "?-+-??",
 "??+?++",
 "++-?+?",
 "?++?-+",
 "?--+++",
 "-??-?+"}
;
	  vector <string> states(states_, states_+sizeof(states_)/sizeof(*states_)); 
	int _ = 20; 
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
	vector <string> states; 
	{
		int N=UNIFORM_LL(1, 4);
		states = vector <string>(N, string(N, '-')); 
		string tb = "+-?";
		REP(i, N)REP(j,N) {
			states[i][j] = tb[UNIFORM_LL(0, 1000)%3];
		}
	}
	int _0 = SwitchingGame().timeToWin(states);
	int _1 = SwitchingGameRef().timeToWin(states);
	if(!verify_case(_0, _1, true)) {
print(states);
	}
}
#endif

}
// END CUT HERE
