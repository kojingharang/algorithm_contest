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
#define VVVI vector<vector<vector<ll>>>
#define VVVVI vector<vector<vector<vector<ll>>>>
#define REP(i,n) for(ll i=0,_n=(n);(i)<(ll)_n;++i)
#define REPR(i,n) for(ll i=(ll)(n)-1;0<=(i);--i)
#define RANGE(i,a,b) for(ll i=(ll)a,_b=(ll)(b);(i)<_b;++i)
#define RANGER(i,a,b) for(ll i=(ll)(b)-1,_a=(ll)(a);(_a)<=i;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
#define FI first
#define SE second
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}

#define MOD 1000000007LL
#define INF (1LL<<60)

struct Dijkstra {
	struct edge{int to; ll cost;};
	vector<vector<edge> > G;
	vector<ll> V;
	const ll Max = 1LL<<60;
	Dijkstra(int N) {
		G = vector<vector<edge> >(N);
		V = vector<ll>(N, Max);
	}
	void add_edge(int v0, int v1, ll cost) {
		if(v0<G.size() && v1<G.size()) G[v0].PB((edge){v1, cost});
	}
	ll run(int S, int E) {
		V[S]=0;
		priority_queue<PII> q;
		q.push(make_pair(0, S));
		while(q.size()) {
			PII el = q.top(); q.pop();
			if(el.second==E) break;
			if(-el.first > V[el.second]) continue;
			for(int i=0;i<(int)G[el.second].size();i++){
				const edge& e=G[el.second][i];
				if(V[e.to]>V[el.second]+e.cost){
					V[e.to]=V[el.second]+e.cost;
					q.push(make_pair(-V[e.to], e.to));
				}
			}
		}
		if(E<0) return -1;
		return V[E]==Max?-1:V[E];
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,M,U,V,S,T;
	while(cin>>N>>M) {
		Dijkstra d(N*3);
		REP(i, M) {
			cin>>U>>V;
			U--;V--;
			REP(j, 3) {
				d.add_edge(U*3+j, V*3+(j+1)%3, 1);
			}
		}
		cin>>S>>T;
		S--;T--;
		ll p = d.run(S*3, T*3);
		ll ans = p != -1 ? p/3 : -1;
		cout<<ans<<endl;
	}
	
	return 0;
}
