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
std::ostream& operator<<(std::ostream& os, const vector<string>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << "\n"; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}

#define MOD 1000000007LL
#define INF (1LL<<60)

vector<string> m;
VVI P, VIS;

void f(ll sx, ll sy, ll& fx, ll& fy) {
	DD(sx);DD(sy);
	queue<PII> q;
	ll H = m.size();
	ll W = m[0].size();
	P = VVI(H, VI(W, INF));
	VIS = VVI(H, VI(W));
	P[sy][sx] = 0;
	q.push(MP(sx, sy));
	while(q.size()) {
		auto xy = q.front();
		q.pop();
		ll x = xy.FI;
		ll y = xy.SE;
		if(VIS[y][x]) continue;
		VIS[y][x] = 1;
		ll dx[] = {-1,0,1,0};
		ll dy[] = {0,-1,0,1};
		REP(dir, 4) {
			ll nx = x + dx[dir];
			ll ny = y + dy[dir];
			if(IN(nx, 0, W) && IN(ny, 0, H) && m[ny][nx]=='.' && !VIS[ny][nx]) {
				minUpdate(P[ny][nx], P[y][x]+1);
				q.push(MP(nx, ny));
			}
		}
	}
	DD(P);
	DD(VIS);
	fx=0;
	fy=0;
	REP(y, H) REP(x, W) if(P[y][x]==INF) P[y][x] = -1;
	REP(y, H) REP(x, W) if(P[y][x] > P[fy][fx]) {fx=x;fy=y;}
}

/*
#..
...
...

木の直径の方法だとこれでstart=(2,2) -> (1,0)になり3になってしまうが
ほんとは(2,0)->(0,2)で4が最長
*/
ll wa(vector<string> m) {
	::m = m;
	ll W=m[0].size(),H=m.size();
	ll sx, sy, fx, fy;
	REP(y, H) REP(x, W) if(m[y][x]=='.') {sx=x;sy=y;}
	f(sx, sy, fx, fy);
	sx=fx;
	sy=fy;
	f(sx, sy, fx, fy);
	ll ans = P[fy][fx] - P[sy][sx];
	return ans;
}

ll ref(vector<string> m) {
	::m = m;
	ll W=m[0].size(),H=m.size();
	ll sx, sy, fx, fy, ans=0;
	REP(y, H) REP(x, W) if(m[y][x]=='.') {
		sx=x;
		sy=y;
		f(sx, sy, fx, fy);
		ll lans = P[fy][fx] - P[sy][sx];
		maxUpdate(ans, lans);
	}
	return ans;
}

int main() {
	REP(loop, 10000) {
		ll W = 3, H = 3;
		vector<string> m(H, string(W, ' '));
		REP(y, H) REP(x, W) m[y][x] = UNIFORM_LL(0, 100) < 10 ? '#' : '.';
		DD(m);
		ll a = ref(m);
		DD(a);
		ll b = wa(m);
		DD(b);
		if(a!=b) {
			assert(false);
		}
	}
	return 0;
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll W,H;
	while(cin>>H>>W) {
		m = vector<string>(H);
		REP(i, H) cin>>m[i];
		ll ans = ref(m);
		cout<<ans<<endl;
	}
	
	return 0;
}
