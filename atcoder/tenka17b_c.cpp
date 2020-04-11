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

#define MOD 1000000007LL
#define INF (1LL<<60)

bool loop;
VI color;
VI vis;
void dfs(ll prev, ll cur, ll col, VVI& g) {
	ll N = g.size();
	if(color[cur]>=0 && color[cur]!=col) loop=1;
	color[cur] = col;
	if(vis[cur]) return;
	vis[cur]=1;
	for(auto adj : g[cur]) if(prev!=adj) {
		dfs(cur, adj, 1-col, g);
	}
}

/*
辺の数は少ない
深さ3
任意の4頂点について3辺あったら1辺加える
完全グラフとの関係は?
0から深さ2の木が大量に生えてる時 N(N-1) 本追加が必要。→実際に追加するアプローチはだめ
ある頂点から深さ{0,3}, {1,2}の組み合わせのノード同士を結ぶ
*/
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,M,u,v;
	while(cin>>N>>M) {
		VVI g(N);
		REP(i, M) {
			cin>>u>>v;
			u--;v--;
			g[u].PB(v);
			g[v].PB(u);
		}
		loop = 0;
		color = VI(N, -1);
		vis = VI(N);
		dfs(-1, 0, 0, g);
		ll ans = 0;
//		DD(loop);
		if(loop) {
			ans = N*(N-1)/2 - M;
		} else {
			VI cnt(2);
			REP(i, N) cnt[color[i]]++;
			ans = cnt[0]*cnt[1]-M;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
