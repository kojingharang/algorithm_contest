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
#include <functional>
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

#define MOD 1000000007LL
#define INF (1LL<<60)

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
std::ostream& operator<<(std::ostream& os, const modll& v) { os << v.val; return os; }

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,K;
	while(cin>>N>>K) {
		// [i][t] : iまでみた場合に右端がt==0 -> skip, t==1 -> stop
		vector<vector<modll>> dp(N, vector<modll>(2));
		dp[0][1] = 1;
		RANGE(i, 1, N) {
			dp[i][0] = dp[i][1] = dp[i-1][0] + dp[i-1][1];
			// dp[i-1][?]はK連続を含まない. dp[i][1] は K 連続を含んでいるのでその分を引く.
			// その分というのは i-K で止まらずにその後 K 回止まるパターンなので dp[i-K][0]
			// dp[i-K][0] 通りそれぞれについて, その後 K 回止まるやり方が 1 通りずつあるのでこうしてよい.
			// i-K == -1 のときは止まらなかった場合が 1 通りとする必要がある. 最初から K 連続のやつを正しく引くため.
			// i-K < -1 の場合は止まらなかった場合は 0 通りでよい. i-K の次から K 連続で止まろうとしても i-K+1 で止まることはできないため.
			if(-1<=i-K) dp[i][1] -= i-K==-1 ? modll(1LL) : dp[i-K][0];
		}
//		DD(dp);
		cout<<dp[N-1][1]<<endl;
//		break;
	}
	
	return 0;
}
