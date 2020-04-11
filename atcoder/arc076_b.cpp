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

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool Union(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool Find(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};
// UnionFind uf(N);
// if(uf.Union(ei, ej)) ...
// if(uf.Find(ei, ej)) ...


int main() {
	//ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
//		vector<PII> w(N);
		vector<PII> xs(N), ys(N);
		REP(i, N) {
//			cin>>w[i].first>>w[i].second;
			cin>>xs[i].first>>ys[i].first;
//			xs[i].first = UNIFORM_LL(1, 100000000);
//			ys[i].first = UNIFORM_LL(1, 100000000);
			xs[i].second = i;
			ys[i].second = i;
		}
		sort(ALL(xs));
		sort(ALL(ys));
		vector<tuple<ll, int, int>> c;
//		RANGE(l, 1, min(N, 1000000/N)) REP(i, N-l) {
		RANGE(l, 1, 3) REP(i, N-l) {
			int j = i+l;
			if(i<N&&j<N) {
				c.PB(make_tuple(abs(xs[i].first-xs[j].first), xs[i].second, xs[j].second));
				c.PB(make_tuple(abs(ys[i].first-ys[j].first), ys[i].second, ys[j].second));
			}
		}
//		DD(c.size());
//		REP(i, N) RANGE(j, i+1, N) {
////			ll v = min(abs(w[i].first-w[j].first), abs(w[i].second-w[j].second));
////			DD(v);
////			c.PB(make_tuple(v, i, j));
//			c.PB(make_tuple(abs(w[i].first-w[j].first), i, j));
//			c.PB(make_tuple(abs(w[i].second-w[j].second), i, j));
//		}
		sort(ALL(c));
//		DD(c);
		UnionFind uf(N);
		ll ans = 0;
		REP(i, c.size()) {
			ll v;
			int si, ei;
			tie(v, si, ei) = c[i];
			if(!uf.Find(si, ei)) {
				uf.Union(si, ei);
//				DD(si);DD(ei);
				ans += v;
			}
		}
		
		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}
