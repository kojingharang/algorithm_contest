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
/*
+ Aの倍数
+ Bの倍数
+ Cの倍数
- lcm(A,B)の倍数
- lcm(A,C)の倍数
- lcm(B,C)の倍数
+ lcm(A,B,C)の倍数
*/

ll naive(VI w) {
	ll N = w.size();
	ll ans = -(1LL<<60);
	REP(bits, 1<<N) {
		VI z(w);
		REP(i, N) if(bits>>i&1) {
			for(int j=i+1;j<=N;j+=i+1) {
				z[j-1] = 0;
			}
		}
		ll lans = accumulate(ALL(z), 0LL);
		ans = max(ans, lans);
	}
	return ans;
}

class Dinic {
public:
	struct Edge {
		int to;
		ll cap;
		int rev;
	};
	int N;
	vector<vector<Edge>> g, orig;
	vector<int> level, iter;
	Dinic(int N) : N(N) {
		g = vector<vector<Edge>>(N);
		level = vector<int>(N);
		iter = vector<int>(N);
	}
	void add_edge(int from, int to, ll cap) {
		g[from].push_back(Edge{to, cap, (int)g[to].size()});
		g[to].push_back(Edge{from, 0, (int)g[from].size()-1});
	}
	void bfs(int s) {
		level.assign(N, -1);
		queue<int> q;
		level[s] = 0;
		q.push(s);
		while(!q.empty()) {
			int v = q.front(); q.pop();
			for(int i=0;i<g[v].size(); i++) {
				Edge& e = g[v][i];
				if(e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
	}
	ll dfs(int v, int t, ll f) {
		if(v==t) return f;
		for(int& i=iter[v]; i<g[v].size(); i++) {
			Edge& e = g[v][i];
			if(e.cap > 0 && level[v] < level[e.to]) {
				ll d = dfs(e.to, t, min(f, e.cap));
				if(d > 0) {
					e.cap -= d;
					g[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		orig = g;
		ll flow = 0;
		ll INF = 1LL<<60;
		for(;;) {
			bfs(s);
			if(level[t] < 0) {
				REP(i, N) {
					REP(j, g[i].size()) {
						orig[i][j].cap = max(0LL, orig[i][j].cap - g[i][j].cap);
					}
				}
				return flow;
			}
			iter.assign(N, 0);
			int f;
			while((f=dfs(s, t, INF)) > 0) flow += f;
		}
		return -1;
	}
};
ostream& operator<<(ostream& os, const Dinic::Edge& e) {
	os<<"(Edge) to "<<e.to<<" cap "<<e.cap<<" rev "<<e.rev<<endl;
	return os;
}

ll f(VI w) {
	ll N = w.size();

	ll S=N, T=N+1;
	Dinic d(N+2);
	ll ans = 0;
	// S : すてる  T : とる
	REP(i, N) {
		if(w[i]>0) {
//			d.add_edge(S, i, 0); // 容量0の辺はなくても同じ
			d.add_edge(i, T, w[i]);
		} else {
			d.add_edge(S, i, -w[i]);
//			d.add_edge(i, T, 0);
		}
		for(int j=(i+1)*2;j<=N;j+=i+1) {
			// i:S, j-1:SはOK
			// i:S, j-1:TはNG
			// i:T, j-1:SはOK
			// i:T, j-1:TはOK
			d.add_edge(i, j-1, 1LL<<60); // i:S j-1:T のときだけペナルティ無限
//			d.add_edge(j-1, i, 1LL<<60); // i:T j-1:S のときだけペナルティ無限. この問題ではこれはだめ
		}
		if(w[i]>0) ans += w[i];
	}
//	DD(d.g);
	ans -= d.max_flow(S, T);
	return ans;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
		VI w(N);
		REP(i, N) cin>>w[i];
//		ll ref = naive(w);
		ll ans = f(w);
		
//		cout<<ref<<endl;
		cout<<ans<<endl;
	}
	
	return 0;
}
