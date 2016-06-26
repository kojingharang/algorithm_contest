// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Elly and Kristina play a game called "Bulls". Initially each of them thinks of a non-negative integer with K digits, possibly containing leading zeroes. Then they take alternating turns, trying to guess the opponent's number. After each guess, the other person says how many positions were guessed correctly. For example if Kristina's number was "1337" and Elly's guess was "1738", Kristina should answer 2, since the digits at positions 0 and 2 (zero-based indices from the left) are correct. A guessed position is called "bull's hit", or simply a "bull", thus the name of the game.

Elly has already made several guesses. She wonders if the information she has is enough to uniquely determine Kristina's number.

You are given the guesses so far in a vector <string> guesses and the corresponding number of bull's hits in vector <int> bulls. If a unique number satisfies the given information, return it as a string. If there is more than one number that is valid according to the current guesses, return "Ambiguity" (quotes for clarity only). If no number satisfies the given information, then Kristina has lied and you should return "Liar" instead.

DEFINITION
Class:EllysBulls
Method:getNumber
Parameters:vector <string>, vector <int>
Returns:string
Method signature:string getNumber(vector <string> guesses, vector <int> bulls)


NOTES
-The game "Bulls" is a simplification of a game played in Bulgaria, called "Kravi & Bikove" ("Cows & Bulls").


CONSTRAINTS
-guesses will contain between 1 and 50 elements, inclusive.
-Each element of guesses will contain between 2 and 9 characters, inclusive.
-All elements of guesses will contain the same number of characters.
-All elements of guesses will consist only of digits ('0'-'9').
-bulls will contain the same number of elements as guesses.
-Each element of bulls will be between 0 and K-1, inclusive, where K is the length of each element of guesses.


EXAMPLES

0)
{"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"}
{2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0}

Returns: "1337"

From {1234->2, 2222->0, 4444->0} it follows that the number is {1?3?}. The additional information {4321->1} tells us that either the digit at position 1 (0-indexed) is 3, or that the one at position 3 is 1. However, since {1111->1} and we already know that the 0-th digit is 1, then the third digit cannot be 1. Now we know that the number is {133?}. When trying {7777->1} we see that Kristina's number contains a 7, which cannot be anywhere else except in the last position. Thus, her number is 1337.


1)
{"0000", "1111", "2222"}
{2, 2, 2}

Returns: "Liar"

There are supposed to be two 0s, two 1s and two 2s in a four-digit number. Thus, Kristina is clearly a liar.


2)
{"666666", "666677", "777777", "999999"}
{2, 3, 1, 0}

Returns: "Ambiguity"

Some of the possible configurations that satisfy the current results are the numbers 636172, 336617, 660007. Thus, the answer is ambiguous.


3)
{"000", "987", "654", "321", "100", "010"}
{2, 1, 0, 0, 1, 1}

Returns: "007"

The guesses, as well as the answer, can have leading zeroes.

4)
{"28", "92", "70", "30", "67", "63", "06", "65",
 "11", "06", "88", "48", "09", "65", "48", "08"}
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

Returns: "54"



5)
{"0294884", "1711527", "2362216", "7666148", "7295642",
 "4166623", "1166638", "2767693", "8650248", "2486509",
 "6138934", "4018642", "6236742", "2961643", "8407361",
 "2097376", "6575410", "6071777", "3569948", "2606380"}
{1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1}

Returns: "4266642"



*/
// END CUT HERE
#line 91 "EllysBulls.cpp"

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
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int> 
#define PII pair<int, int> 
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



class EllysBulls {
	public:
	string getNumber(vector <string> G, vector <int> B) {
		int N=G.size(), K=G[0].size();
		map<VI, PII> rests;
		int K0=K/2, K1=K-K0;
		VI ten(1, 1);
		REP(i, 6) ten.PB(ten.back()*10);
		cout<<ten<<endl;
		cout<<K0<<" "<<K1<<endl;
		//return "";
		REP(v, ten[K0]) {
			//cout<<"p1 "<<v<<endl;
			char buf[20];
			sprintf(buf, "%0*d", K0, v);
			//cout<<"buf: "<<string(buf)<<endl;
			VI rest(N);
			int ok=1;
			REP(gi, N) {
				int match=0;
				REP(k, K0) match += buf[k]==G[gi][k];
				if(B[gi]-match<0) {ok=0;break;}
				rest[gi] = B[gi]-match;
			}
			if(ok) {
				rests[rest].first++;
				rests[rest].second = v;
			}
		}
		//cout<<rests<<endl;
		string ans;
		REP(v, ten[K1]) {
			char buf[20];
			sprintf(buf, "%0*d", K1, v);
			VI key(N);
			REP(gi, N) {
				int match=0;
				REP(k, K1) match += buf[k]==G[gi][K0+k];
				key[gi] = match;
			}
			//cout<<"key: "<<key<<endl;
			{
				if(rests.count(key)) {
					//cout<<"p2 count "<<v<<" "<<rests.count(key)<<endl;
					if(rests[key].first > 1) return "Ambiguity";
					if(ans.size()) return "Ambiguity";
					char buf[30];
					sprintf(buf, "%0*d", K0, rests[key].second);
					sprintf(&buf[K0], "%0*d", K1, v);
					ans = string(buf);
				}
			}
		}
		if(ans.size()==0) return "Liar";
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
void verify_case(const string& Expected, const string& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, EllysBulls().getNumber(guesses, bulls));}
int main(){

CASE(0)
	string guesses_[] = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int bulls_[] = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0};
	  vector <int> bulls(bulls_, bulls_+sizeof(bulls_)/sizeof(*bulls_)); 
	string _ = "1337"; 
END
//return 0;
CASE(1)
	string guesses_[] = {"0000", "1111", "2222"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int bulls_[] = {2, 2, 2};
	  vector <int> bulls(bulls_, bulls_+sizeof(bulls_)/sizeof(*bulls_)); 
	string _ = "Liar"; 
END
CASE(2)
	string guesses_[] = {"666666", "666677", "777777", "999999"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int bulls_[] = {2, 3, 1, 0};
	  vector <int> bulls(bulls_, bulls_+sizeof(bulls_)/sizeof(*bulls_)); 
	string _ = "Ambiguity"; 
END
CASE(3)
	string guesses_[] = {"000", "987", "654", "321", "100", "010"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int bulls_[] = {2, 1, 0, 0, 1, 1};
	  vector <int> bulls(bulls_, bulls_+sizeof(bulls_)/sizeof(*bulls_)); 
	string _ = "007"; 
END
CASE(4)
	string guesses_[] = {"28", "92", "70", "30", "67", "63", "06", "65",
 "11", "06", "88", "48", "09", "65", "48", "08"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int bulls_[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	  vector <int> bulls(bulls_, bulls_+sizeof(bulls_)/sizeof(*bulls_)); 
	string _ = "54"; 
END
CASE(5)
	string guesses_[] = {"0294884", "1711527", "2362216", "7666148", "7295642",
 "4166623", "1166638", "2767693", "8650248", "2486509",
 "6138934", "4018642", "6236742", "2961643", "8407361",
 "2097376", "6575410", "6071777", "3569948", "2606380"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int bulls_[] = {1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1};
	  vector <int> bulls(bulls_, bulls_+sizeof(bulls_)/sizeof(*bulls_)); 
	string _ = "4266642"; 
END
CASE(5)
	string guesses_[] = {"000000000", "111111111", "222222222"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int bulls_[] = {0, 0, 0};
	  vector <int> bulls(bulls_, bulls_+sizeof(bulls_)/sizeof(*bulls_)); 
	string _ = "Ambiguity"; 
END

}
// END CUT HERE
