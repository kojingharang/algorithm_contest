// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Wolf Sothe and Cat Snuke are playing a card game.
The game is played with exactly 100 cards.
The cards are numbered from 1 to 100.
The game is played as follows:

First, Cat Snuke chooses the goal: an integer N between 1 and 100, inclusive.
Then, Wolf Sothe chooses exactly K of the 100 cards and gives the chosen cards to Snuke.
Next, Cat Snuke may throw some of those K cards away. He may choose any subset of cards he was given, possibly none or all of them.
Finally, Cat Snuke may write minus signs onto any subset of the cards he still holds. For example, if he currently has the cards {1,3,4,7}, he may alter them to {-1,3,4,-7}.


At the end of the game, Snuke computes the sum of the numbers on his cards (with the added minus signs).
Snuke wins the game if the sum is exactly equal to the goal number N.
Otherwise, Sothe wins.

Your task is to help Wolf Sothe win the game.
We are now in step 2 of the game.
You are given the int N chosen by Snuke and the int K that specifies the number of cards you have to give to Snuke.
Choose those K cards in such a way that Snuke will be unable to win the game.
If you can do that, return a vector <int> with K elements: the numbers on the chosen cards.
If there are multiple solutions, you may return any of them.
If there is no solution, return an empty vector <int> instead.

DEFINITION
Class:WolfCardGame
Method:createAnswer
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> createAnswer(int N, int K)


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-K will be between 1 and 15, inclusive.


EXAMPLES

0)
20
4

Returns: {1, 2, 3, 4 }

If we give Snuke cards with numbers 1, 2, 3, and 4 on them, the largest sum he can form is 1+2+3+4 = 10.
Thus, he cannot reach N=20 and we win.

1)
40
1

Returns: {39 }



2)
97
6

Returns: {7, 68, 9, 10, 62, 58 }



3)
2
12

Returns: {33, 69, 42, 45, 96, 15, 57, 12, 93, 9, 54, 99 }



******************************/
// END CUT HERE
#line 78 "WolfCardGame.cpp"
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
70 73 76 79 82 85 88 91 94 97 100 
-1 -1 -1 -1 -1        1  1  1  1
                           -2  2
*/
bool validate(int N, int K, vector<int> ch) {
	assert(ch.size()==0 || ch.size()==K);
	sort(ALL(ch));
	ch.erase(unique(ALL(ch)), ch.end());
	assert(ch.size()==0 || ch.size()==K);
	DD(ch);
	bool imp = false;
	if(!ch.size()) {
		REP(i, K) ch.PB(i+1);
		imp = true;
	}
	int Mx = 5050, Zero = Mx/2;
	vector<bool> dp(Mx);
	dp[Zero] = true;
	REP(i, ch.size()) {
		vector<bool> ndp(dp);
		REP(j, Mx) if(dp[j]) {
			RANGE(add, -1, 2) {
				int nj = j+add*ch[i];
				if(IN_RANGE(nj, 0, Mx)) {
					ndp[nj] = true;
					auto cand = vector<int>{2,-98,-98-97,-195-94,-289-91,-298,-298+79,-219+76,-143+73};
					for(auto v : cand) if(nj-Zero==v && add!=0) {DD(v);DD(add);DD(ch[i]);}
				}
			}
		}
		dp = ndp;
//		REP(i, Mx) if(dp[i]) cout<<i-Zero<<" ";
//		cout<<endl;
	}
	bool ok = true;
	if(imp) {
		if(!dp[Zero+N]) {
			DD("given win but impossible case exists");
			DD(ch);
			ok=false;
//			assert(0);
		}
	} else {
		if(dp[Zero+N]) {
			DD("given lose but possible");
			DD(ch);
//			DD(dp);
			ok=false;
//			assert(0);
		}
	}
//	DD(dp);
	VI can;
	REP(i, Mx) if(dp[i] && IN_RANGE(i-Zero, 0, 101)) can.PB(i-Zero);
	DD(can);
	return ok;
}

VI make_primes(int N) {
	vector<bool> p(N, true);
	VI out;
	for(int i=2;i*i<=N;i++) if(p[i]) { out.PB(i); for(int j=i*2;j<N;j+=i) p[j]=false; }
	return out;
}

map<int, int> factorize(int n, const VI& primes) { // 60(==2**2 * 3**1 * 5**1), table -> ([2,3,5], [2,1,1])   time:
	map<int, int> out;
	REP(i, primes.size()) {
		int co=0;
		while(n%primes[i]==0) { n/=primes[i]; co++; }
		if(co) { out[primes[i]] = co; }
	}
	if(n>1) { out[n] = 1;}
	return out;
}

class WolfCardGame {
	public:
	vector <int> createAnswer(int N, int K) {
		vector<int> ans;
		if(N%2) {
			REP(i, K) ans.PB(2*i+2);
			return ans;
		}
		if(N%3) {
			REP(i, K) ans.PB(100-i*3);
//			REP(i, K) ans.PB(3*i+3);
			return ans;
		}
		if(N%4) {
			REP(i, K) ans.PB(4*i+4);
			return ans;
		}
		if(N%5) {
			REP(i, K) ans.PB(5*i+5);
			return ans;
		}
		if(N%6) {
			REP(i, K) ans.PB(6*i+6);
			return ans;
		}
		REP(i, min(14, K)) ans.PB(7*i+7);
		if(K==15) ans.PB(1);
		return ans;
//		auto primes = make_primes(10000);
//		DD(primes);
//		reverse(ALL(primes));
//		auto f = factorize(N, primes);
//		DD(f);
//		REP(i, primes.size()) if(!f.count(primes[i])) {
//			int m = 100-primes[i];
//			int cnt=0;
//			while(m>0) {
//				if(m==N) continue;
//				ans.PB(m);
//				cnt++;
//				if(cnt>8) break;
//				if(ans.size()==K) return ans;
//				m -= primes[i];
//			}
//		}
//		if(N>K*(K+1)/2) {
//			vector<int> ans;
//			RANGE(i, 1, K+1) ans.PB(i);
//			return ans;
//		}
//		int Mx = 5050, Zero = Mx/2;
//		VI nums;
//		REP(i, 100) if(i+1>3) nums.PB(i+1);
//		REP(loop, 2000) {
//			vector<bool> dp(Mx);
//			dp[Zero] = true;
//			ans.clear();
//			random_shuffle(ALL(nums));
//			DD(nums);
//			if(loop==1050) {
//				nums.clear();
//				REP(i, primes.size()) if(primes[i]>3&&primes[i]!=N) nums.PB(primes[i]);
//			}
//			if(loop==1100) {
//				nums.clear();
//				REP(i, primes.size()) if(primes[i]>20&&abs(primes[i]-N)>3) nums.PB(primes[i]);
//			}
//			REP(ni, nums.size()) {
//				vector<bool> ndp(dp);
//				REP(j, Mx) if(dp[j]) {
//					RANGE(add, -1, 2) {
//						int nj = j+add*nums[ni];
//						if(IN_RANGE(nj, 0, Mx)) {
//							ndp[nj] = true;
//						}
//					}
//				}
//				if(!ndp[N+Zero]) {
//					dp = ndp;
//					ans.PB(nums[ni]);
//					if(ans.size()==K) return ans;
//				} else {
//					if(loop%10==0) {
//						VI nn;
//						REP(i, nums.size()) if(nums[ni]!=nums[i]) nn.PB(nums[i]);
//						nums=nn;
//						break;
//					}
//				}
//			}
//		}
//		DD(N);DD(K);
//		DD("no ans");
//		assert(0);
//		return {};
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(int N, int K, const vector <int>& Received, bool noPASSmsg=false) {
 //bool ok = (Expected == Received);
 bool ok = validate(N, K, Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << 0 << endl << "\tx: " << Received << endl; } return ok;
}
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
//#define END	 verify_case(N, K, WolfCardGame().createAnswer(N, K));}
#define END	 verify_case(N, K, _);}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){
	bool go = true;
	RANGE(N, 1, 101) {
		RANGE(K, 1, 16) {
//			if(N==44&&K==7) go=true;
			if(!go) continue;
			DD(N);DD(K);
			auto tans = WolfCardGame().createAnswer(N, K);
			DD(tans);
			bool ok = validate(N, K, tans);
			if(!ok) {
				assert(0);
			}
		}
	}

//		auto f = factorize(100, make_primes(101));
//		DD(f);

CASE(0)
	int N = 15; 
	int K = 5; 
	int __[] = {100,97,94,91,87};
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
return 0;

CASE(0)
	int N = 20; 
	int K = 4; 
	int __[] = {1, 2, 3, 4 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	int N = 40; 
	int K = 1; 
	int __[] = {39 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	int N = 97; 
	int K = 6; 
	int __[] = {7, 68, 9, 10, 62, 58 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
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
// param type: int
	int N = UNIFORM_LL(0, 100); 
// param type: int
	int K = UNIFORM_LL(0, 100); 
	vector <int> _0 = WolfCardGame().createAnswer(N, K);
	vector <int> _1 = WolfCardGameRef().createAnswer(N, K);
	if(!verify_case(_0, _1, true)) {
print(N);
print(K);
	}
}
#endif

}
// END CUT HERE
