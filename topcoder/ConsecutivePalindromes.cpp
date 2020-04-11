// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
A palindrome is a word that reads the same forwards and backwards.
For example, "Z", "ABBA", "RACECAR", and "XXXXXX" are all palindromes.



You are given a string S.
A sequence of integers L is called a consecutive palindromic sequence for S if it has the following properties:

L is a strictly increasing sequence.
All elements of L lie between 0 and length(S)-1, inclusive.
L contains a subsequence of two or more consecutive integers (a, a+1, ..., b) such that the string S[a]S[a+1]...S[b] is a palindrome.




For example, for S = "TOPPAPPOT" the following sequences are some of the consecutive palindromic sequences:
(2, 3), (0, 5, 6), (3, 4, 5), and (0, 1, 2, 3, 4, 5, 6, 7, 8).
The sequences (0, 8) and (0, 1) are not consecutive palindromic sequences: they do not have the third property.



Let C be the number of consecutive palindromic sequences for the given string S.
Compute and return the value (C modulo 10^9+7).


DEFINITION
Class:ConsecutivePalindromes
Method:countStrings
Parameters:string
Returns:int
Method signature:int countStrings(string S)


CONSTRAINTS
-S will contain between 1 and 2,000 characters, inclusive.
-S will contain only uppercase English letters ('A' - 'Z').


EXAMPLES

0)
"AAA"

Returns: 3


The three consecutive palindromic sequences are the sequences (0, 1), (1, 2), and (0, 1, 2).
For example, the entire sequence (0, 1) corresponds to the palindrome S[0]S[1] = "AA".



Note that the sequence (0, 2) is not a consecutive palindromic sequence: it does not contain any subsequence of two or more consecutive integers at all.


1)
"ABCDEF"

Returns: 0



2)
"BBAA"

Returns: 7


The seven consecutive palindromic sequences: (0, 1), (0, 1, 2), (0, 1, 3), (0, 1, 2, 3), (0, 2, 3), (1, 2, 3), and (2, 3).



For example, (0, 2, 3) is a consecutive palindromic sequence because it contains the subsequence (2, 3): two consecutive integers with the property that S[2]S[3] = "AA" is a palindrome.


3)
"ABCBA"

Returns: 4



4)
"TOPPAPPOT"

Returns: 240



5)
"AYUEOPPOLAKIKIKIUYOPZOOLPPPPKMOPOLIURKMQOAPLFKTURIWOOWWWPLOLWWWOPSLAA"

Returns: 216072426



6)
"Z"

Returns: 0



*/
// END CUT HERE
#line 110 "ConsecutivePalindromes.cpp"

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


struct modll {
	static const ll MODVAL;
	ll val;
	modll() : val(0) {}
	modll(ll v) : val(v) { normalize(); }
	void normalize() { val = (val+MODVAL) % MODVAL; }
	modll  operator+ (ll v) { return modll(val+v); }
	modll& operator+=(ll v) { val+=v; normalize(); return *this; }
	modll  operator- (ll v) { return modll(val-v); }
	modll& operator-=(ll v) { val-=v; normalize(); return *this; }
	modll  operator* (ll v) { return modll(val*v); }
	modll& operator*=(ll v) { val*=v; normalize(); return *this; }
	modll  operator^ (ll e) { modll x(val); modll v(1); for(;e;x=x*x,e>>=1) if(e&1) v = v * x; return v; } // pow
	modll inv() { modll x(val); return x^(MODVAL-2); } // MODVAL must be prime number when use this!
	static modll inv(ll v) { return modll(v).inv(); }
	operator ll() { return val; }
};
const ll modll::MODVAL = 1000000007;
std::ostream& operator<<(std::ostream& os, const modll& v) {
	os << v.val;
	return os;
}

class ConsecutivePalindromes {
	public:
	int countStrings(string S) {
		int N = S.size();
		// ok[i] ... [0, i) での答え ... ..AA... ..A?A...
		vector<modll> ok(N+1), all(N+1);
		all[0] = 1;
		RANGE(i, 1, N+1) {
			ok[i] = ok[i-1]*2LL;
			all[i] = all[i-1] * 2LL;
			int r = i-1;
			if(r-1>=0 && S[r]==S[r-1]) {
				if(!(r-2>=0 && S[r-2]==S[r])) {
					// ... Z A A
					// ...
					ok[i] += all[i-2]-ok[i-2];
				}
			}
			if(r-2>=0 && S[r]==S[r-2]) {
				if(S[r]!=S[r+1]) {
					// ... A ? A
					// ...
					ok[i] += all[i-3]-ok[i-3];
				}
			}
		}
		DD("\n");
		DD(S);
		DD(ok);
		DD(all);
		return ok[N];
	}
};
/*
S: AAA
ok: 0 0 1 5 
all: 1 2 4 8 
FAILED (0 msec)
	o: "3"
	x: "5"
Test Case #1..."\n": 

AA -> AAA にあたって ok[2]==1 なので ok[3] = 2 となる. AA? に対応
	+
	01
	012
AAA の最後の2文字がAAだから no[i-2]=2 をたす
	+
	 12
	012
AAA が A?A だから no[i-3]=1 をたす
	+
	012

-> 012が3回数えられてる。

答えは3通り
01
 12
012


*/

class ConsecutivePalindromesRef {
	public:
	int countStrings(string S) {
		int N = S.size();
		// ok[i] ... [0, i) での答え ... ..AA... ..A?A...
		// no0[i+1] ... [0, i) での答えじゃないやつ
		// no1[i] ... [0, i) での
		// no2[i] ... [0, i) での
		// (ok+no0+no1+no2)[i] = 2**i
		// (no0+no1+no2)[i] ... [0, i) での答えじゃないやつ
		vector<modll> ok(N+1), no0(N+1), no1(N+1), no2(N+1);
		vector<modll> okno0(N+1);
		no0[0] = 1;
		RANGE(i, 1, N+1) {
			int r = i-1;
			ok[i] = ok[i-1]*2LL;
			no0[i] = no0[i-1]+(i-2>=0 ? (ll)no0[i-2] : 0LL)+no2[i-1];
			if(r>0 && S[r]==S[r-1]) {
				// ... A A
				// ...
				// ... .
				ok[i] += no2[i-1];
				ok[i] += no0[i-2];
			} else if(r>1 && S[r]==S[r-2]) {
				// ... A ? A
				// ...       no2[i-1]
				ok[i] += no2[i-1];
				no2[i] += no0[i-2];
			} else {
				// ... A B C
				no2[i] += no2[i-1];
				no2[i] += (i-2>=0?(ll)no0[i-2]:0);
			}
		}
//		REP(i, N+1) okno0[i] = ok[i]+no0[i]+(i-1>=0?(ll)no0[i-1]:0)+no2[i];
		REP(i, N) okno0[i] = ok[i]+no0[i+1];
		DD("\n");
		DD(S);
		DD(ok);
		DD(no0);
//		DD(no1);
		DD(no2);
		DD(okno0);
//		REP(i, N+1) if(i-2>=0) assert(no0[i-2]==no2[i]);
		return ok[N];
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
#define END	 verify_case(_, ConsecutivePalindromes().countStrings(S));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string S = "AA"; 
	int _ = 1; 
END
//return 0;
CASE(0)
	string S = "AAA"; 
	int _ = 3; 
END
CASE(1)
	string S = "ABCDEF"; 
	int _ = 0; 
END
CASE(2)
	string S = "BBAA"; 
	int _ = 7; 
END
//return 0;
CASE(3)
	string S = "ABCBA"; 
	int _ = 4; 
END
CASE(3)
	string S = "ZABCBA"; 
	int _ = 8; 
END
CASE(4)
	string S = "TOPPAPPOT"; 
	int _ = 240; 
END
CASE(5)
	string S = "AYUEOPPOLAKIKIKIUYOPZOOLPPPPKMOPOLIURKMQOAPLFKTURIWOOWWWPLOLWWWOPSLAA"; 
	int _ = 216072426; 
END
CASE(6)
	string S = "Z"; 
	int _ = 0; 
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
	string S; 
	{
		int N=UNIFORM_LL(1, 51);
		S = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			S[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	int _0 = ConsecutivePalindromes().countStrings(S);
	int _1 = ConsecutivePalindromesRef().countStrings(S);
	if(!verify_case(_0, _1, true)) {
print(S);
	}
}
#endif

}
// END CUT HERE
