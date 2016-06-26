/*

Initially, Manao has an integer A and his friend has an integer B. Note that neither A nor B contain a zero digit in their base 10 representation. The players make moves alternatively with Manao starting first. In each move, the player can either reverse his current number, or he can divide it by 10 (using integer division).
For example, if the current number is 12849, the player can either reverse it to obtain 94821, or he can divide it by 10 to obtain 1284.
Note that we always round down when using integer division.
Also note that each player is only allowed to change his own number, and not the number of the other player.

If after some move the players' numbers become equal, Manao is declared the winner. If after 1000 moves (that is, 500 moves by Manao and 500 by his friend) Manao has not won, he loses. Given A and B, determine whether Manao would win if both players play optimally. Return "Manao wins" or "Manao loses" accordingly.

DEFINITION
Class:TheNumberGame
Method:determineOutcome
Parameters:int, int
Returns:string
Method signature:string determineOutcome(int A, int B)


CONSTRAINTS
-A will be between 1 and 999,999,999, inclusive.
-B will be between 1 and 999,999,999, inclusive.
-A and B will not contain a zero digit in base 10 representation.
-A and B will be distinct.


EXAMPLES

0)
45
4

Returns: "Manao wins"

Manao can win in one move by dividing his number by 10.

1)
45
5

Returns: "Manao wins"

There are several possible scenarios this game can follow:

Manao divides by 10 and obtains 4. Now his opponent can reverse his number and obtain 5 again. Obviously, no matter what Manao does in his next 499 moves, his opponent can evade him.
Manao reverses his number and obtains 54. His opponent reverses his 5. Manao divides 54 by 10 and obtains 5, thus making the numbers equal
Manao reverses his number and obtains 54. His opponent divides by 10 and obtains zero. Manao will win in three moves, dividing his number by 10 twice.

Obviously, Manao will not choose to divide by 10 in his first move and will win.

2)
99
123

Returns: "Manao loses"

No matter how Manao plays, the opponent can perform reverse moves until the end of the game.

3)
2356236
5666

Returns: "Manao loses"

*/

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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

class TheNumberGame {
	public:
	string determineOutcome(int A, int B) {
		vector<string> w;
		stringstream ss, sb;
		sb<<B;
		ss<<A;
		string s=ss.str();
		REP(i, 2) {
			if(i==1) reverse(ALL(s));
			REP(sj, s.size()) {
				RANGE(ej, sj, s.size()) {
//					cout<<s.substr(sj, ej-sj+1)<<endl;
					if(s.substr(sj, ej-sj+1)==sb.str()) return "Manao wins";
				}
			}
		}
		return "Manao loses";
	}
};

/*

int main() {
	string s;
	s = TheNumberGame().determineOutcome(45, 4);
	cout<<s<<endl;
	s = TheNumberGame().determineOutcome(45, 5);
	cout<<s<<endl;
	s = TheNumberGame().determineOutcome(99, 123);
	cout<<s<<endl;
	s = TheNumberGame().determineOutcome(2356236, 5666);
	cout<<s<<endl;
	return 0;
}


*/















