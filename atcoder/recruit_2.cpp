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
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[x][y]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000009LL

int dp[2][21][512][512];

int main() {
	//ios::sync_with_stdio(false);
	int TESTS, R, B, rn, rk, bn, bk;
	cin>>TESTS;
	REP(test, TESTS) {
		CLEAR(dp, 0);
		int men=0;
		dp[men][0][0][0]=1;
		cin>>R>>B>>rn>>rk>>bn>>bk;
		REP(i, R+B) {
			CLEAR(dp[1-men], 0);
			REP(cr, R+1) REP(ri, 1<<rn) REP(bi, 1<<bn) {
				int cb = i-cr;
				if(!(0<=cb && cb<=B)) continue;
				if(dp[men][cr][ri][bi]==0) continue;
				int nri = (ri<<1)&((1<<rn)-1);
				int nbi = (bi<<1)&((1<<bn)-1);
				if(POPCOUNT(nri)+1<rk && cr<R) dp[1-men][cr+1][nri|1][nbi] = (dp[1-men][cr+1][nri|1][nbi] + dp[men][cr][ri][bi]) % MOD;
				if(POPCOUNT(nbi)+1<bk && cb<B) dp[1-men][cr][nri][nbi|1] = (dp[1-men][cr][nri][nbi|1] + dp[men][cr][ri][bi]) % MOD;
			}
			men ^= 1;
		}
		ll ans = 0;
		REP(ri, 1<<rn) REP(bi, 1<<bn) ans = (ans + dp[men][R][ri][bi]) % MOD;
		
		cout<<ans<<endl;
	}
	
	return 0;
}
