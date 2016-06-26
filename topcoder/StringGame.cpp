// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Manao has invented a new unusual two-player game which he calls the String Game. The game is played on a set of strings of the same length comprised of lowercase English letters.

In the beginning, the first player chooses a string X from the set and permutes its characters in any way he wants. He also chooses a permutation of the English alphabet. After that, the second player may permute the characters in each of the strings in the set, except for X. Now X is lexicographically compared to each of the other strings in the set using the permuted English alphabet. If X is strictly smaller than each of the other strings, the first player wins. Otherwise, the second player does.

In order to compare two different strings A and B, first it is necessary to find the first position at which these strings differ. Let the characters at this position in A and B be a and b. If a stands earlier than b in the permuted alphabet, then A is lexicographically smaller than B, otherwise B is lexicographically smaller than A. For example, with alphabet {b, a, c, d, ..., z}, the string "aba" is lexicographically smaller than the string "aab" because 'b' stands earlier than 'a' in the alphabet.

You are given a vector <string> S, the set of strings on which the String Game is played. Determine all strings which, when chosen by the first player, allow him to win if both he and his opponent play optimally. That is, the first player always permutes the string X and the alphabet optimally, and then the second player permutes all the other strings optimally. Return a vector <int> containing the sorted list of all 0-based indices of all such strings.

DEFINITION
Class:StringGame
Method:getWinningStrings
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> getWinningStrings(vector <string> S)


NOTES
-The return value may sometimes be an empty vector <int>.


CONSTRAINTS
-S will contain between 2 and 50 elements, inclusive.
-Each element of S will be between 1 and 50 characters long, inclusive.
-All elements of S will be of equal length.
-Each element of S will consist of lowercase letters ('a'-'z') only.
-The elements of S will be distinct.


EXAMPLES

0)
{"a", "b", "c", "d"}

Returns: {0, 1, 2, 3 }

For each of the given strings, Manao can choose the alphabet which begins with the string's only character and his string will be lexicographically smallest.

1)
{"aabbcc", "aaabbb", "aaaccc"}

Returns: {1, 2 }

Manao can win if he chooses the string "aaabbb" or "aaaccc". For "aaabbb", he can choose permutation of the alphabet {b, a, c, ..., z} and make his string "bbbaaa". For "aaaccc", the permutation can be {c, a, b, d, ..., z} and the string itself can be "cccaaa". In both cases, regardless of which permutations the opponent chooses, the two other strings will always be lexicographically larger than Manao's string.

2)
{"ab", "ba"}

Returns: { }

Note that the first player's string should be strictly smaller than the opponent's strings.

3)
{"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"}

Returns: {1, 3, 4 }



*/
// END CUT HERE
#line 65 "StringGame.cpp"

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
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class StringGame {
	public:
	vector <int> getWinningStrings(vector <string> S) {
		int N=S.size();
		VVI hi(N, VI(26));
		REP(i, N) {
			REP(j, S[i].size()) {
				hi[i][S[i][j]-'a']++;
			}
		}
		cout<<hi<<endl;
		vector<int> ans;
#if 1
		REP(i, N) {
			string alpha;
			VI live(N, 1);
			live[i]=0;
			REP(loop, 26) {
				REP(c, 26) {
					int lose_char=0;
					REP(j, N) {
						if(live[j] && hi[j][c] > hi[i][c]) lose_char=1;
					}
					if(lose_char) continue;
					
					REP(j, N) {
						if(live[j] && hi[j][c] < hi[i][c]) {
							live[j]=0;
							if(alpha.find(c+'a')==string::npos) alpha.PB(c+'a');
						}
					}
				}
			}
			//cout<<live<<endl;
			cout<<i<<" "<<(accumulate(ALL(live), 0LL)==0 ? "OK":"NG")<<" Alphabet: "<<alpha<<endl;
			if(accumulate(ALL(live), 0LL)==0) ans.PB(i);
#else
		REP(i, N) {
			int gok=0;
			REP(c, 26) {
				int ok=1;
				REP(j, N) {
					if(i!=j && hi[j][c] >= hi[i][c]) ok=0;
				}
				if(ok) gok=1;
			}
			if(gok) ans.PB(i);
#endif
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//mplate<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// os << "{ ";
// for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
// os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const vector <int>& Expected, const vector <int>& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, StringGame().getWinningStrings(S));}
int main(){

CASE(0)
	string S_[] = {"abbc", "aacc", "aabb"};
	  vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int __[] = {0, 1, 2};
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
//return 0;
CASE(0)
	string S_[] = {"a", "b", "c", "d"};
	  vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int __[] = {0, 1, 2, 3 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	string S_[] = {"aabbcc", "aaabbb", "aaaccc"};
	  vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int __[] = {1, 2 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	string S_[] = {"ab", "ba"};
	  vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	vector <int> _; 
END
CASE(3)
	string S_[] = {"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"};
	  vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int __[] = {1, 3, 4 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	string S_[] = {"aabcdeffff", "aabbcdefff", "aabbccdeff", "aabbccddef", "aabbccddee"};
	  vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int __[] = {0, 1, 2, 3, 4 };
	 vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	string S_[] = {"aabcdd", "aabbcd", "aabbcc"};
	  vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int __[] = {0, 1, 2 };
	 vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END

}
// END CUT HERE
/*

2 1 1 2
2 2 1 1
2 2 2 0


2 1 1 1 1  4
2 2 1 1 1  3
2 2 2 1 1  2
2 2 2 2 1  1
2 2 2 2 2  


*/

