#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
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
string YN(bool v) { return v ? "Yes":"No"; }

#define INF (1LL<<60)

ll bfs(const vector<string>& m) {
	ll H = m.size(), W = m[0].size();
	deque<PII> q;
	auto start = MP(0, 0);
	q.push_back(start);
	VVI p(H, VI(W, INF));
	VVI vis(H, VI(W));
	p[start.SE][start.FI] = 0;
	ll dx[]={0,1,0,-1}; ll dy[]={-1,0,1,0}; // up right down left
	while(q.size()) {
		auto c = q.front();q.pop_front();
		ll x = c.FI;
		ll y = c.SE;
		if(vis[y][x]) continue;
		vis[y][x] = 1;
		REP(dir, 4) {
			ll nx=x+dx[dir];
			ll ny=y+dy[dir];
			if(IN(nx, 0, W) && IN(ny, 0, H) && m[ny][nx]=='.') {
				if(p[y][x]+1<p[ny][nx]) {
					q.PB(MP(nx, ny));
					p[ny][nx] = p[y][x]+1;
				}
			}
		}
	}
//	DD(p);
	if(p[H-1][W-1]==INF) return -1;
	return p[H-1][W-1];
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,M,W,H;
	while(cin>>H>>W) {
		vector<string> m(H);
		REP(i, H) cin>>m[i];
		ll step = bfs(m);
//		DD(step);
		ll ans = -1;
		if(step!=-1) {
			ll c = 0;
			REP(y, H) REP(x, W) if(m[y][x]=='#') c++;
			ans = H*W-(step+1)-c;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
