// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Limak is a polar bear who often chats online with his friends.
Nowadays, bears often use emoticons to express their feelings.
In this problem we consider one particular emoticon: the crying emoticon.

A crying emoticon consists of an arbitrary positive number of underscores between two semicolons.
Hence, the shortest possible crying emoticon is ";_;" (quotes for clarity).
The strings ";__;" and ";_____________;" are also valid crying emoticons.

Today Limak is sad, so he sent his friend a sequence of crying emoticons.
However, due to a network malfunction all those emoticons got mixed together into a single string.

You are given a string message containing the message Limak's friend received.
You guess that the message can be divided into one or more crying emoticons.
Each emoticon must be a subsequence of the message, and each character of the message must belong to exactly one emoticon.
Note that the subsequences are not required to be contiguous.

Let X be the number of ways in which one can divide the given message into emoticons.
Compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:BearCries
Method:count
Parameters:string
Returns:int
Method signature:int count(string message)


CONSTRAINTS
-message will contain between 1 and 200 characters, inclusive.
-Each character in message will be either semicolon or underscore.


EXAMPLES

0)
";_;;_____;"

Returns: 2

There are two ways to divide this string into two crying emoticons.
One looks as follows:

 ;_;
    ;_____;

and the other looks like this:

 ;_ ;
   ; _____;


1)
";;;___;;;"

Returns: 36

This message consists of 3 semicolons, 3 underscores and 3 semicolons again.
Clearly, we have to divide this message into exactly three crying emoticons, each with a single underscore.
There are 36 different ways to do so.

2)
"_;__;"

Returns: 0

As this message begins with an underscore, it clearly cannot be divided into one or more crying emoticons: each crying emoticon starts with a semicolon.

3)
";_____________________________________;"

Returns: 1



4)
";__;____;"

Returns: 0



5)
";_;;__;_;;"

Returns: 52



******************************/
// END CUT HERE
#line 95 "BearCries.cpp"
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
#define DD(v) cout<<#v<<": "<<(v)<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

/*
;の個数は偶数じゃないとだめ
両端は;じゃないとだめ
各 _ の両端に来る ; という観点ではどうか？ -> 単純な掛け算にならなさそう
最大200文字→3でわって最大66コの顔文字しかない

;  までできてる
;_までできてる
;_;までできてる
↑数を別々な状態として持つDPは？ -> 新規に _ が現れた場合、今までの ; が ;_ になったのか ;_ が ;_ になったのか一意にきまらない
	→この方針が結果的には正解。
		[i番目][;までできてる顔文字の数][;_までできてる顔文字の数]

全探索を書く
最初の文字は; 右の;を決め、その間の _ から全 bit 組み合わせで全通り取る。ただし 1 コ以上。
;_..._; を抜き出した後の文字列を count で計算する。
これは動いた。
が、そこから発展がない...
	途中の ;____; から N コ取るとき、何を取っても答えは一緒なので圧縮できないか？ -> ;__;__;__; ... が30コくらい続くとだめ

最長共通部分列問題 (Longest Common Subsequence) と似たような DP にならないか？

顔文字を決めてくとN^N探索になってしまう。各文字を66コの顔文字のどこに属させるかというアプローチは？

連続する _..._ がすべて _ 1文字だったときの解はすぐ求まるか？それに基いて複数 ____ だったときの効果を掛けられないか？
;_; が何セットかあるやつのシャッフル全通りについて全探索解を印字してみる
なんか規則性はありそう...

;;_;_; -> 2
;;__;; -> 4
;_;;_; -> 2
;_;_;; -> 2
Koji-no-MacBook-Air:topcoder kojih$ G++ BearCries.cpp && ./a.out 
;;;_;_;_; -> 6
;;;_;__;; -> 12
;;;__;;_; -> 12
;;;__;_;; -> 24
;;;___;;; -> 36
;;_;;_;_; -> 8
;;_;;__;; -> 16
;;_;_;;_; -> 12
;;_;_;_;; -> 20
;;_;__;;; -> 24
;;__;;;_; -> 12
;;__;;_;; -> 16
;;__;_;;; -> 12
;_;;;_;_; -> 6
;_;;;__;; -> 12
;_;;_;;_; -> 8
;_;;_;_;; -> 12
;_;;__;;; -> 12
;_;_;;;_; -> 6
;_;_;;_;; -> 8
;_;_;_;;; -> 6

;;;;_;_;_;_; -> 24
;;;;_;_;__;; -> 48
;;;;_;__;;_; -> 48
;;;;_;__;_;; -> 96
;;;;_;___;;; -> 144
;;;;__;;_;_; -> 48
;;;;__;;__;; -> 96
;;;;__;_;;_; -> 96
;;;;__;_;_;; -> 192
;;;;__;__;;; -> 288
;;;;___;;;_; -> 144
;;;;___;;_;; -> 288
;;;;___;_;;; -> 432
;;;;____;;;; -> 576
;;;_;;_;_;_; -> 36
;;;_;;_;__;; -> 72
.....

*/
class BearCriesNaive {
	public:
	int count(string M) {
		int N=M.size();
		if(M[0]=='_'||M[N-1]=='_') return 0;
		if(::count(ALL(M), ';')%2) return 0;
		VI rc;
		RANGE(ri, 1, N) {
			if(M[ri]==';') rc.PB(ri);
		}
		ll ans = 0;
		for(int ri : rc) {
			VI cc;
			RANGE(i, 1, ri) if(M[i]=='_') cc.PB(i);
			if(!cc.size()) continue;
			RANGE(b, 1, 1<<cc.size()) {
				VI choose;
				REP(ci, cc.size()) if((b>>ci)&1) choose.PB(ci);
				string s=M;
				s[0]='+';
				s[ri]='+';
				for(int ci : choose) s[cc[ci]]='-';
				string ns;
				REP(i, N) if(s[i]!='+'&&s[i]!='-') ns.PB(s[i]);
//				cout<<"eliminated: "<<s<<endl;
				ll lans = ns.size() ? count(ns) : 1;
//				cout<<" plus "<<M<<" "<<s<<" "<<lans<<endl;
				ans += lans;
			}
		}
//		cout<<"ans "<<M<<" -> "<<ans<<endl;
		return ans;
	}
};

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

// [i][j][k] ... M[I], I in [0, i] の範囲で, ;で終わってる顔文字が j コ, ;_+ な顔文字が k コあるような状態の個数
modll dp[202][202][202];
class BearCries {
	public:
	int count(string M) {
		CLEAR(dp, 0);
		int N=M.size();
		dp[0][0][0]=1;
		REP(i, N) REP(j, N) REP(k, N) {
			auto cur = dp[i][j][k];
			if(M[i]==';') {
				dp[i+1][j+1][k] += cur; // 新規 ;
				if(k-1>=0) dp[i+1][j][k-1] += cur*modll(k); // ;_+ -> ;_+; (k コある)
			} else {
				dp[i+1][j][k] += cur*modll(k); // ;_+ -> ;_+ (k コある)
				if(j-1>=0) dp[i+1][j-1][k+1] += cur*modll(j); // ; -> ;_+ (j コある)
			}
		}
		return dp[N][0][0];
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
#define END	 verify_case(_, BearCries().count(message));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

//string m = ";;;;;;;;____";
////string m = ";;;;;;___";
////string m = ";;;;__";
//sort(ALL(m));
//do {
//	int v=BearCries().count(m);
//	if(v) cout<<m<<" -> "<<v<<endl;
//} while(next_permutation(ALL(m)));
//return 0;


CASE(5)
	string message = ";_;;__;_;;"; 
	int _ = 52; 
END
//return 0;
CASE(0)
	string message = ";_;;_____;"; 
	int _ = 2; 
END
CASE(1)
	string message = ";;;___;;;"; 
	int _ = 36; 
END
//return 0;
CASE(2)
	string message = "_;__;"; 
	int _ = 0; 
END
CASE(3)
	string message = ";_____________________________________;"; 
	int _ = 1; 
END
CASE(4)
	string message = ";__;____;"; 
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
	string message; 
	{
		int N=UNIFORM_LL(1, 51);
		message = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			message[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	int _0 = BearCries().count(message);
	int _1 = BearCriesRef().count(message);
	if(!verify_case(_0, _1, true)) {
print(message);
	}
}
#endif

}
// END CUT HERE
