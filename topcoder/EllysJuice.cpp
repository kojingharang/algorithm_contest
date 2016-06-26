// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Elly's memories of last night's sleepover with her friends are rather blurry. She recalls that they played a game involving drinking orange and apple juice. In the beginning there were two identical bottles. One contained a gallon of orange juice, the other a gallon of apple juice. The game was played in turns, starting with turn zero. In even-numbered turns (turn 0, 2, 4, ...) the current player drank half of the remaining orange juice. In odd-numbered turns (turn 1, 3, 5, ...) the current player drank half of the remaining apple juice. The winner of the game is the player who drank the greatest total amount of liquid during the game. If multiple players are tied for the greatest amount, there is no winner.

For example, consider a game consisting of five turns. Suppose that the players to drink were, in order, Elly, Kriss, Stancho, Elly, and Stancho. (That is, Elly and Stancho both drank twice: Elly in turns 0 and 3, Stancho in turns 2 and 4.) In this game, Elly drank 0.75 gallons of liquid (0.5 gallons of orange juice and 0.25 of apple juice), Kriss drank 0.5 gallons of apple juice, and Stancho drank 0.375 gallons of orange juice (0.25 gallons in turn 2 and another 0.125 gallons in turn 4). In this game Elly would be the winner.

Elly knows all the people who played the game yesterday, and for each of them the number of times they drank. However, she remembers nothing about the order in which the players drank.

You are given a vector <string> players, containing the names of all players. If a player's name is contained X times in players that means that he or she drank exactly X times during the game. Determine all people who could have possibly won the game (for some particular order of turns). Return their names as a lexicographically sorted vector <string>. The return value should only contain each of the names once.

DEFINITION
Class:EllysJuice
Method:getWinners
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> getWinners(vector <string> players)


NOTES
-A sequence of distinct strings is sorted if each element is lexicographically smaller than all the ones following it.
-string A is lexicographically smaller than string B if A contains smaller character at the first index where they differ. If there is no index where they differ, the shorter one is lexicographically smaller. For example "ariadne" is smaller than "elly", "abc" is smaller than "abd", "aaa" is smaller than "aaaaa", and "czzzzzzz" is smaller than "kaaaaaaa".


CONSTRAINTS
-players will contain between 1 and 8 elements, inclusive.
-Each element of players will contain between 1 and 20 characters, inclusive.
-Each element of players will consist only of lowercase English letters ('a'-'z').


EXAMPLES

0)
{ "elly", "kriss", "stancho", "elly", "stancho" }

Returns: {"elly", "stancho" }

Elly would win for the order given in the problem statement. If Stancho and Elly swapped all their turns, Stancho would win the game. Kriss cannot win.

1)
{"torb", "elly", "stancho", "kriss"}

Returns: { }

In any valid game two of the four players would be tied for the lead (with half a gallon each).

2)
{"elly", "elly", "elly", "elly", "elly"}

Returns: {"elly" }

Since she was the only player, apparently she won.

3)
{ "ariadne", "elly", "ariadne", "stancho", "stancho", "kriss", "stancho", "elly" }

Returns: {"ariadne", "elly", "stancho" }

Although Stancho has drunk three times, there are orderings in which someone else wins.

*/
// END CUT HERE
#line 64 "EllysJuice.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T> v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class EllysJuice {
	public:
	vector <string> getWinners(vector <string> P) {
		sort(ALL(P));
		map<string, int> win;
		do {
			map<string, int> w;
			VI r(2, 1<<8);
			REP(i, P.size()) {
				w[P[i]] += r[i&1]/2;
				r[i&1]/=2;
			}
			//cout<<w<<endl;
			int maxv = 0;
			FOR(e, w) {
				//cout<<*e<<endl;
				maxv = max(maxv, e->second);
			}
			int count = 0;
			string winner;
			FOR(e, w) {
				//cout<<*e<<endl;
				if(e->second==maxv) {
					count ++;
					winner = e->first;
				}
			}
			if(count==1) win[winner]=1;
		} while(next_permutation(ALL(P)));
		vector<string> ans;
		FOR(e, win) {
			ans.PB(e->first);
		}
		sort(ALL(ans));
		
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// { os << "{ ";
//   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
//   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const vector <string>& Expected, const vector <string>& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, EllysJuice().getWinners(players));}
int main(){

CASE(0)
	string players_[] = { "elly", "kriss", "stancho", "elly", "stancho" };
	  vector <string> players(players_, players_+sizeof(players_)/sizeof(*players_)); 
	string __[] = {"elly", "stancho" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	string players_[] = {"torb", "elly", "stancho", "kriss"};
	  vector <string> players(players_, players_+sizeof(players_)/sizeof(*players_)); 
	vector <string> _; 
END
CASE(2)
	string players_[] = {"elly", "elly", "elly", "elly", "elly"};
	  vector <string> players(players_, players_+sizeof(players_)/sizeof(*players_)); 
	string __[] = {"elly" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	string players_[] = { "ariadne", "elly", "ariadne", "stancho", "stancho", "kriss", "stancho", "elly" };
	  vector <string> players(players_, players_+sizeof(players_)/sizeof(*players_)); 
	string __[] = {"ariadne", "elly", "stancho" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	string players_[] = { "a","a","a","a","b","b","c","c", };
	  vector <string> players(players_, players_+sizeof(players_)/sizeof(*players_)); 
	string __[] = {"ariadne", "elly", "stancho" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END

}
// END CUT HERE
