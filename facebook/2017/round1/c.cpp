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
/*
increase stack size!!!!!!
// 16MB
g++ -O2 -Wl,-stack_size,10000000 -std=c++11 -Wall d.cpp && ./a.out < corporate_gifting.txt > do2.txt
*/

struct Edge {
	ll v0, v1, cost;
};

ll solve(ll N, ll M, ll K, vector<Edge>& edge, vector<Edge>& c) {
	// dp[i][a] = i人目の集荷をする直前に集荷地点にいて i-1 人目の荷物を持ってるかどうかが a のときのそこまでの最小コスト
	ll INF = 1LL<<60;
/*
i get を始める時点で i-1 の荷物を持ってるかどうかによって 2 通りの選択肢がある。
もってたら
	i-1 put -> i put ... i+1 では i をもってない
	or
	i-1 put -> i+1 get のとこまで移動 ... i+1 では i をもってる
もってなかったら
	i put ... i+1 では i をもってない
	or
	i+1 get のとこまで移動 ... i+1 では i をもってる
*/
	VVI cost(N, VI(N, INF));
	REP(i, N) cost[i][i] = 0;
//	DD(N);DD(M);DD(K);
//	REP(i, M) DD(edge[i].v0),DD(edge[i].v1), DD(edge[i].cost);
	REP(i, M) cost[edge[i].v0][edge[i].v1] = min(cost[edge[i].v0][edge[i].v1], edge[i].cost);
	REP(i, M) cost[edge[i].v1][edge[i].v0] = min(cost[edge[i].v1][edge[i].v0], edge[i].cost);
	REP(k, N) REP(i, N) REP(j, N) cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
//	DD(cost);

	VVI dp(K+1, VI(2, INF));
	dp[0][0] = cost[0][c[0].v0];
	REP(i, K) {
		// here in c[i].v0

		// (have) get i, mv to i-1 dst, put i-1, mv to i+1 src (have)
		if(i-1>=0) {
			ll nv = dp[i][1];
			nv += cost[c[i].v0][c[i-1].v1];
			if(i+1<K) nv += cost[c[i-1].v1][c[i+1].v0];
			dp[i+1][1] = min(dp[i+1][1], nv);
		}

		// (have) get i, mv to i-1 dst, put i-1, mv to i dst, put i, mv to i+1 src (no have)
		if(i-1>=0) {
			ll nv = dp[i][1];
			nv += cost[c[i].v0][c[i-1].v1];
			nv += cost[c[i-1].v1][c[i].v1];
			if(i+1<K) nv += cost[c[i].v1][c[i+1].v0];
			dp[i+1][0] = min(dp[i+1][0], nv);
		}

		// (no have) get i, mv to i dst, put i, mv to i+1 src (no have)
		{
			ll nv = dp[i][0];
			nv += cost[c[i].v0][c[i].v1];
			if(i+1<K) nv += cost[c[i].v1][c[i+1].v0];
			dp[i+1][0] = min(dp[i+1][0], nv);
		}

		// (no have) get i, mv to i+1 src (have)
		{
			ll nv = dp[i][0];
			if(i+1<K) nv += cost[c[i].v0][c[i+1].v0];
			dp[i+1][1] = min(dp[i+1][1], nv);
		}
	}
//	DD(dp);
	return dp[K][0] >= INF ? -1 : dp[K][0];
}

int main() {
	//ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		ll N, M, K;
		cin>>N>>M>>K;
//		cout<<N<<" "<<M<<" "<<K<<endl;
		vector<Edge> edge(M), c(K);
		REP(i, M) {
			cin>>edge[i].v0>>edge[i].v1>>edge[i].cost;
			edge[i].v0--;
			edge[i].v1--;
		}
		REP(i, K) {
			cin>>c[i].v0>>c[i].v1;
			c[i].v0--;
			c[i].v1--;
		}
		ll ans = solve(N, M, K, edge, c);
		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		break;
	}
	
	return 0;
}
