// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A palindrome is a string that reads the same forwards and backwards.
For example, "abba" and "racecar" are palindromes.

Limak has a string s consisting of N lowercase English letters.

For each valid i, let X[i] be the number of palidromic subsequences of s that contain the i-th character of s.

In other words:
For a fixed i, there are exactly 2^(N-1) ways to erase some characters of s other than the character s[i].
X[i] is the number of ways of erasing for which the string that remains is a palindrome.

For each i, compute the value Y[i] = ((i+1) * X[i]) modulo 1,000,000,007.
Then, compute and return the bitwise XOR of all the values Y[i].

DEFINITION
Class:PalindromicSubseq
Method:solve
Parameters:string
Returns:int
Method signature:int solve(string s)


CONSTRAINTS
-s will contain exactly N characters.
-N will be between 1 and 3000, inclusive.
-Each character in s will be a lowercase English letter 'a' - 'z'.


EXAMPLES

0)
"aaba"

Returns: 30

For this string we have X = {5, 5, 3, 6}.
Thus, you should return the value (1*5) XOR (2*5) XOR (3*3) XOR (4*6) = 5 XOR 10 XOR 9 XOR 24 = 30.

Here is an explanation why X[0] = 5:
Given that we want to keep the character s[0], there are 8 possible subsequences of s:

a...  *
a..a  *
a.b.
a.ba  *
aa..  *
aa.a  *
aab.
aaba

Five of these subsequences (marked by stars) are palindromes.
Note that there are two different ways to produce the palindrome "aa".

1)
"abcd"

Returns: 4

X[i] = 1 for all i. You should return (1*1) XOR (2*1) XOR (3*1) XOR (4*1) = 1 XOR 2 XOR 3 XOR 4 = 4.

2)
"tcoct"

Returns: 60

X[] = {7, 6, 4, 6, 7}

3)
"zyzyzzzzxzyz"

Returns: 717



4)
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

Returns: 1025495382

If all characters are the same, all 2^N subsequences are palindromes.
For every index i all 2^(N-1) subseqeunces that contain it are palindromes.
It means that X[i] = 2^(N-1) for all i.

Note that in this case the answer exceeds the modulo value, because we return the XOR of modulo-ed values, without computing the modulo of that XOR.

*/
// END CUT HERE
#line 92 "PalindromicSubseq.cpp"

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

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))

template<int MOD>
struct ModInt {
  static const int Mod = MOD;
  unsigned x;
  ModInt() : x(0) { }
  ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
  ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
  int get() const { return (int)x; }
 
  ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
 
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
};
typedef ModInt<1000000007> mint;
template<int MOD>
ostream& operator<<(ostream& os, const ModInt<MOD>& v) {
	os << v.get();
	return os;
}
 
struct PalindromicSubseqRef {
  int solve(string s) {
    int n = (int)s.size();
    vector<vector<mint>> dp1(n + 1, vector<mint>(n + 1));
	// dp1[i][j] ... [i, j) 内の回文の個数
    rep(i, n) dp1[i][i + 1] = 1;
    rer(len, 2, n) rer(i, 0, n - len) {
      int j = i + len;
      mint x;
      x += dp1[i + 1][j];
      x += dp1[i][j - 1];
      x -= dp1[i + 1][j - 1];
      if (s[i] == s[j - 1])
        x += dp1[i + 1][j - 1] + 1;
      dp1[i][j] = x;
    }
    vector<vector<mint>> dp2(n + 1, vector<mint>(n + 1));
	// dp2[i][j] ... [0, i), [j, N) 内の回文の個数
    dp2[0][n] = 1;
//    for (int len = n - 1; len >= 0; -- len) rer(i, 0, n - len) {
    for (int len = n; len >= 1; -- len) rer(i, 0, n - len+1) {
      int j = i + len-1;
	  	DD(len);
		DD(i);
		DD(j);
      mint x;
      if (i != 0)
        x += dp2[i - 1][j];
      if (j != n)
        x += dp2[i][j + 1];
      if (i != 0 && j != n) {
        x -= dp2[i - 1][j + 1];
        if (s[i - 1] == s[j])
          x += dp2[i - 1][j + 1];
      }
      dp2[i][j] = x;
    }
	DD(dp1);
	DD(dp2);
    vector<mint> X(n);
    rep(i, n) {
		DD(i);
      mint sum;
//      sum += dp2[i][i + 1];
//      for (int j = 0; j < i; ++ j) if (s[j] == s[i])
//        sum += (dp1[j + 1][i] + 1) * dp2[j][i + 1];
//      for (int j = i + 1; j < n; ++ j) if (s[j] == s[i])
//        sum += (dp1[i + 1][j] + 1) * dp2[i][j + 1];
		for (int j = 0; j < n; ++ j) if (s[j] == s[i]) {
			int I=i, J=j;
			if(J>=I) swap(I, J);
			sum += (dp1[J + 1][I] + 1) * dp2[J][I + 1];
			cout<<j<<" ["<<J+1<<" "<<I<<"] "<<dp1[J + 1][I] + 1<<" * ["<<J<<" "<<I+1<<"] "<<dp2[J][I + 1]<<endl;
		}
      X[i] = sum;
	  DD(X[i].get());
    }
    int anssum = 0;
    rep(i, n)
      anssum ^= (X[i] * (i + 1)).get();
	DD(anssum);
    return anssum;
  }
};

// https://community.topcoder.com/stat?c=problem_solution&rm=329655&rd=16852&pm=14526&cr=22263204
class PalindromicSubseqT {
public:
  int solve(string);
};
 
const int md = 1000000007;
 
inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}
 
inline int mul(int a, int b) {
  return (long long) a * b % md;
}
 
const int N = 3010;
 
int outer[N][N], inner[N][N];
 
int PalindromicSubseqT::solve(string s) {
  int n = s.length();
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      outer[i][j] = 0;
    }
  }
  outer[0][max(0, n - 1)] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j >= i; j--) {
      int ft = outer[i][j];
      if (ft == 0) {
        continue;
      }
      if (i < j) {
        add(outer[i + 1][j], ft);
        add(outer[i][j - 1], ft);
      }
      if (i + 1 <= j - 1) {
        add(outer[i + 1][j - 1], md - ft);
      }
      if (i + 1 <= j - 1 && s[i] == s[j]) {
        add(outer[i + 1][j - 1], ft);
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      inner[i][j] = 0;
      if (i < j) {
        add(inner[i][j], inner[i + 1][j]);
        add(inner[i][j], inner[i][j - 1]);
      } else {
        add(inner[i][j], 2);
      }
      if (i + 1 <= j - 1) {
        add(inner[i][j], md - inner[i + 1][j - 1]);
      } else {
        add(inner[i][j], md - 1);
      }
      if (s[i] == s[j]) {
        if (i + 1 <= j - 1) {
          add(inner[i][j], inner[i + 1][j - 1]);
        } else {
          add(inner[i][j], 1);
        }
      }
    }
  }
//  DD("inner");
//  REP(i, n) {
//  	REP(j, n) cout<<inner[i][j]<<" ";
//	cout<<endl;
//  }
//  DD("outer");
//  REP(i, n) {
//  	REP(j, n) cout<<outer[i][j]<<" ";
//	cout<<endl;
//  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int X = 0;
    for (int j = 0; j < n; j++) {
      if (s[i] != s[j]) {
        continue;
      }
      int a = i, b = j;
      if (a > b) {
        swap(a, b);
      }
      if (a == b || a + 1 == b) {
        add(X, outer[a][b]);
        continue;
      }
      add(X, mul(outer[a][b], inner[a + 1][b - 1]));
    }
//	DD(X);
    ans ^= mul(i + 1, X);
  }
  return ans;
}
 

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
ostream& operator<<(ostream& os, const modll& v) {
	os << v.val;
	return os;
}
const ll modll::MODVAL = 1000000007;

/*
Test Case #0..."inner": inner
2 4 5 11 
0 2 3 6 
0 0 2 3 
0 0 0 2 
"outer": outer
1 1 1 1 
0 2 2 1 
0 0 3 1 
0 0 0 1 
PASSED (0 msec)
*/
class PalindromicSubseq {
	public:
	int solve(string s) {
//		PalindromicSubseqRef().solve(s);
//		PalindromicSubseqT().solve(s);

		ll N = s.size();
		// dp1[i][j] ... [i, j] 内での回文の個数
		vector<vector<modll>> dp1(N, vector<modll>(N));
		// dp2[i][j] ... [0, i), (j, N) 内での回文の個数
		vector<vector<modll>> dp2(N, vector<modll>(N));
		RANGE(L, 0, N+1) REP(i, N-L+1) {
			int j = i+L-1;
			if(L==0) {
				if(0<=j && i<N) dp1[i][j] = 1; // empty
			} else {
				modll v = 0;
				// s[i] を採用しない場合
				if(i+1<N) v += dp1[i+1][j];
				// s[j] を採用しない場合
				if(0<=j-1) v += dp1[i][j-1];
				// s[i], s[j] を採用しない場合が 2 回数えられている分を減らす
				if(0<=j-1 && i+1<N) v -= dp1[i+1][j-1];
				if(s[i]==s[j]) {
					// s[i], s[j] を採用できる。採用するとその内側の組み合わせ総数だけ増える
					if(0<=j-1 && i+1<N) v += dp1[i+1][j-1];
				}
				dp1[i][j] = v;
			}
		}
		for(int L=N;L>=1;L--) REP(i, N-L+1) {
			int j = i+L-1;
			if(L==N) {
				dp2[i][j] = 1; // empty
			} else {
				modll v = 0;
				if(0<=i-1) v += dp2[i-1][j];
				if(j+1<N) v += dp2[i][j+1];
				if(0<=i-1 && j+1<N) {
					v -= dp2[i-1][j+1];
					if(s[i-1]==s[j+1]) {
						// s[i-1], s[j+1] を採用できる。採用するとその外側の組み合わせ総数だけ増える
						v += dp2[i-1][j+1];
					}
				}
				dp2[i][j] = v;
			}
		}
//		DD(dp1);
//		DD(dp2);
		ll ans = 0;
		REP(i, N) {
			modll X = 0;
//			DD(i);
			REP(j, N) {
				if(s[i]==s[j]) {
					ll I=i, J=j;
					if(I>J) swap(I, J);
					// I, J がどちらも採用され回文にて対応関係にある。
					// 内側は [I+1, J-1] 内の回文の個数
					// 外側は [0, I), (J, N) 内の回文の個数
					// これらの積が "I, J がどちらも採用され回文にて対応関係にある" 場合の組み合わせ総数。
					// I=1 J=1 のとき [2][0] = 0 になってるがこのばあい 1 をかけたいのでこれだとだめ
//					X += (0<=J-1 && I+1<N ? dp1[I+1][J-1] : modll(1)) * dp2[I][J];
					X += (I+1<=J-1 ? dp1[I+1][J-1] : modll(1)) * dp2[I][J];
//					cout<<j<<" ["<<I<<" "<<J<<"] "<<dp1[I][J]<<" * ["<<I-1<<" "<<J+1<<"] "<<(0<=I-1 && J+1<N ? dp2[I-1][J+1] : modll(1))<<endl;
				}
			}
//			DD(X);
			ans ^= modll(i+1LL)*X;
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
#define END	 verify_case(_, PalindromicSubseq().solve(s));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string s = "aaba"; 
	int _ = 30; 
END
//return 0;
CASE(1)
	string s = "abcd"; 
	int _ = 4; 
END
CASE(2)
	string s = "tcoct"; 
	int _ = 60; 
END
CASE(3)
	string s = "zyzyzzzzxzyz"; 
	int _ = 717; 
END
CASE(4)
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; 
	int _ = 1025495382; 
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
	string s; 
	{
		int N=UNIFORM_LL(1, 51);
		s = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			s[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	int _0 = PalindromicSubseq().solve(s);
	int _1 = PalindromicSubseqRef().solve(s);
	if(!verify_case(_0, _1, true)) {
print(s);
	}
}
#endif

}
// END CUT HERE
