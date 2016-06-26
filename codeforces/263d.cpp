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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")

/*
MEMO
つなぐ/つながない　と　何通りかをかける処理の関係性がわからない。
例えば、白の子が白の時、つないでもつながなくても そのノードとしては白状態になる。
[わかった] 白の子が白の時、繋がないと子の白が確定してしまう。それは条件を満たさないのでだめ. だから繋ぐ一択。ので２倍しなくていい
例えば、白の子が黒の時、つながないようにしないと そのノードとして白状態にならない。
[わかった] 正しい。繋がない一択なので１倍.
*/

struct modll {
	static const ll MODVAL;
	ll val;
	modll() : val(0) {}
	modll(ll v) { val = v; normalize(); }
	void normalize() { val = (val+MODVAL) % MODVAL; }
	modll  operator+ (ll v) { return modll(val+v); }
	modll& operator+=(ll v) { val+=v; normalize(); return *this; }
	modll  operator- (ll v) { return modll(val-v); }
	modll& operator-=(ll v) { val-=v; normalize(); return *this; }
	modll  operator* (ll v) { return modll(val*v); }
	modll& operator*=(ll v) { val*=v; normalize(); return *this; }
	modll  operator^ (ll e) { modll x(val); modll v(1); for(;e;x=x*x,e>>=1) if(e&1) v = v * x; return v; } // pow
	modll inv() { modll x(val); return x^(MODVAL-2); } // MODVAL must be prime number when use this!
	operator ll() { return val; }
};
const ll modll::MODVAL = 1000000007;

VVI g;
VVI memo;
vector<bool> black;

// g(idx, all, b)
ll dfs(int prev, int idx, int b) {
	if(memo[b][idx]>=0) return memo[b][idx];

	// このノードと子ノード[0-i]以下からなる subtree を条件を満たすように区切ったとき, node を含む領域に含まれる黒の数 -> 何通り
	modll dp[2];
	dp[0] = (modll)!black[idx];
	dp[1] = (modll)black[idx];
	REP(i, g[idx].size()) {
		int ni = g[idx][i];
		if(prev==ni) continue;
		modll ndp[2] = {0, 0};
		modll ch[2] = {dfs(idx, ni, 0), dfs(idx, ni, 1)};
		REP(pi, 2) REP(ci, 2) REP(cut, 2) {
			int obi = pi + (cut ? 0 : ci);
			if(cut && ci==0) continue; // 切断して子以下に黒がなかったらだめ
			if(obi < 2) ndp[obi] += dp[pi] * ch[ci];
		}
		dp[0] = ndp[0];
		dp[1] = ndp[1];
	}
	return memo[b][idx] = dp[b];
}

int main() {
	ll N,p,v;
	while(cin>>N) {
		g = VVI(N);
		memo = VVI(2, VI(N, -1));
		black = vector<bool>(N);
		REP(i, N-1) {
			cin>>p;
			g[i+1].PB(p);
			g[p].PB(i+1);
		}
		REP(i, N) {
			cin>>v;
			black[i] = v;
		}
		ll ans = dfs(-1, 0, 1);
		cout<<ans<<endl;
	}
	
	return 0;
}




