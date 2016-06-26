// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// A palindrome is a word that reads the same forwards and backwards. For example, "a", "abba", and "zzz" are palindromes, while "ab" and "xxxyx" are not.

The anagram of a string S is any string we can obtain from S by rearranging its letters. For example, the string "haha" has exactly six anagrams: "aahh", "ahah", "ahha", "haah", "haha", and "hhaa".

We are given a string word. We will choose one of its anagrams uniformly at random. Return the probability that the chosen anagram will be a palindrome.

DEFINITION
Class:PalindromePermutations
Method:palindromeProbability
Parameters:string
Returns:double
Method signature:double palindromeProbability(string word)


NOTES
-The returned value must have an absolute or a relative error of less than 1e-9.


CONSTRAINTS
-word will contain between 1 and 50 characters, inclusive.
-Each character of word will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"haha"

Returns: 0.3333333333333333

Each of the six anagrams of "haha" will be selected with probability 1/6.
Two of them are palindromes: "ahha" and "haah".
Hence, the probability of selecting a palindrome is 2/6.

1)
"xxxxy"

Returns: 0.2



2)
"xxxx"

Returns: 1.0

This word only has one anagram: "xxxx". That is a palindrome.

3)
"abcde"

Returns: 0.0

Regardless of how we rearrange the letters of "abcde", we will never get a palindrome.

4)
"hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff"

Returns: 0.025641025641025637



******************************/
// END CUT HERE
#line 69 "PalindromePermutations.cpp"
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

long double f(int n) {
	long double all = 1;
	REP(i, n) all *= (long double)(i+1);
	return all;
}

class PalindromePermutations {
	public:
	double palindromeProbability(string w) {
		int N=w.size();
		map<char, int> hi;
		REP(i, N) hi[w[i]]++;
		char odd=0;
		FOR(e, hi) if(e->second&1) {if(odd) return 0; else odd=e->first; }
		if((N&1)==0 && odd) return 0;
		
//		map<int, int> U,D;
//		REP(i, N) D[i+1]++;
//		FOR(e, hi) REP(i, e->second) U[i+1]++;
//		REP(i, N/2) U[i+1]++;
//		FOR(e, hi) REP(i, e->second/2) D[i+1]++;
//		FOR(e, D) if(U.count(e->first) && U[e->first]>=e->second) {U[e->first]-=e->second; D[e->first]=0;}
//		long double ans = 1;
//		FOR(e, U) REP(i, e->second) ans *= e->first;
//		FOR(e, D) REP(i, e->second) ans /= e->first;
//		cout<<U<<endl;
//		cout<<D<<endl;
		
		long double all = f(N);
		FOR(e, hi) all /= f(e->second);
		long double ch = f(N/2);
		FOR(e, hi) ch /= f(e->second/2);
//		return ans;
		return ch / all;
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
#define END	 verify_case(_, PalindromePermutations().palindromeProbability(word));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string word = "aaabbbccc"; 
	double _ = 0; 
END
CASE(0)
	string word = "aaabbb"; 
	double _ = 0; 
END
CASE(0)
	string word = "abcd"; 
	double _ = 0; 
END
CASE(0)
	string word = "abc"; 
	double _ = 0; 
END
CASE(0)
	string word = "hbh"; 
	double _ = 0.3333333333333333; 
END
CASE(0)
	string word = "hb"; 
	double _ = 0; 
END
CASE(0)
	string word = "hh"; 
	double _ = 1; 
END
CASE(0)
	string word = "h"; 
	double _ = 1; 
END
CASE(0)
	string word = "haha"; 
	double _ = 0.3333333333333333; 
END
CASE(1)
	string word = "xxxxy"; 
	double _ = 0.2; 
END
CASE(2)
	string word = "xxxx"; 
	double _ = 1.0; 
END
CASE(3)
	string word = "abcde"; 
	double _ = 0.0; 
END
CASE(4)
	string word = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff"; 
	double _ = 0.025641025641025637; 
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
for(int loop=0;loop<10000;loop++) {
// param type: String
	string word; 
	{
		int N=UNIFORM_LL(1, 51);
		word = string(N, ' '); 
		string tb = "abcdefghijklmnopqrstuvwxyz";
		REP(i, N) {
			word[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	double _0 = PalindromePermutations().palindromeProbability(word);
	double _1 = PalindromePermutationsRef().palindromeProbability(word);
	if(!verify_case(_0, _1, true)) {
print(word);
	}
}
#endif

}
// END CUT HERE
