// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Elly has a list of several distinct strings given in the vector <string> words. She can apply the following operation as many times as she wants (including zero times):

Choose one of the words and call it S.
Choose an even number k between 2 and |S|, inclusive, where |S| is the length of S (thus, chose a prefix with even length).
Reverse the order of the first k characters of S (thus, reverse the chosen prefix without the rest of the word).

For example, if she has the word "topcoder", she can reverse its first 2, 4, 6, or all 8 characters. If she chooses to reverse its first 4 characters, the change will be: "topcoder" -> "cpotoder". If at a later time she decides to chose the same string and reverse all of its characters (which is also a valid prefix with even length), she would get "cpotoder"->"redotopc".

After performing some operations two strings might become equal. If that happens, Elly crosses them out and continues playing her game with the remaining strings only, i.e. they "disappear" from the list. The girl wonders what is the minimal number of strings she can end up with.

For example, suppose she has the strings {"esprit", "god", "redotopc", "odcpoter", "dog"}. The word "redotopc" can be converted to "topcoder" by first reversing all 8 characters and then reversing the first 4. The word "odcpoter" can also be converted to "topcoder" by performing "odcpoter" -> "docpoter" -> "topcoder". At that point the words become equal and disappear, leaving Elly only with {"esprit", "god", "dog"}. This is where she gets stuck: The words "god" and "dog" cannot become equal, because she can only reverse prefixes with even length. Thus, the minimal number of words she can get is 3.

Given her initial strings in vector <string> words, return an int indicating the minimal number of strings she can be left with.

DEFINITION
Class:EllysReversals
Method:getMin
Parameters:vector <string>
Returns:int
Method signature:int getMin(vector <string> words)


CONSTRAINTS
-words will contain between 1 and 50 elements, inclusive.
-Each element of words will contain between 1 and 50 characters, inclusive.
-Each element of words will consist only of lowercase letters of the English alphabet ('a'-'z').
-All elements of words will be distinct.


EXAMPLES

0)
{"esprit", "god", "redotopc", "odcpoter", "dog"}

Returns: 3

The example from the problem statement.

1)
{"no", "zaphod", "just", "very", "improbable"}

Returns: 5

It is possible that she cannot get rid of any of the words.

2)
{"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"}

Returns: 0

It is possible that she ends up with zero words.

3)
{"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"}

Returns: 1

Sometimes it is possible to match different words when using a different sequence of operations.

4)
{"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
 "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
 "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
 "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
 "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"}

Returns: 16



*/
// END CUT HERE
#line 77 "EllysReversals.cpp"

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



class EllysReversals {
	public:
	int getMin(vector <string> W) {
		int N=W.size();
		map<string, int> hi;
		REP(i, N) {
			vector<string> ww;
			REP(j, W[i].size()/2*2) {
				string ss;
				ss.PB(W[i][j]);
				ss.PB(W[i][j+1]);
				j++;
				sort(ALL(ss));
				ww.PB(ss);
			}
			sort(ALL(ww));
			string sn;
			FOR(e, ww) sn+=*e;
			if(W[i].size() & 1) sn+=W[i][W[i].size()-1];
			hi[sn]++;
		}
		cout<<hi<<endl;
		int ans = 0;
		FOR(e, hi) if(e->second & 1) ans++;
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
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, EllysReversals().getMin(words));}
int main(){
CASE(0)
	string words_[] = {"topcoder", "redocpot", "doretopc", "cpotdoer", "reodtopc"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int _ = 1; 
END
//return 0;

CASE(0)
	string words_[] = {"esprit", "god", "redotopc", "odcpoter", "dog"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int _ = 3; 
END
CASE(1)
	string words_[] = {"no", "zaphod", "just", "very", "improbable"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int _ = 5; 
END
CASE(2)
	string words_[] = {"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int _ = 0; 
END
CASE(3)
	string words_[] = {"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int _ = 1; 
END
CASE(4)
	string words_[] = {"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
 "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
 "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
 "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
 "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int _ = 16; 
END

}
// END CUT HERE
