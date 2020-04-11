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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << "\n"; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}

#define MOD 1000000007LL
#define INF (1LL<<60)

//map<pair<ll, pair<ll, pair<ll, pair<ll, vector<string>>>>>, ll> memo;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

// 状態が勝ち(1)か負け(0)かを返す
ll f(ll isRoot, ll H, ll W, vector<string>& M) {
	ll cands = 0;
	ll ans = 0;
	REP(y, H) REP(x, W) if(M[y][x]=='.') REP(t, 2) {
		vector<string> MM(M);
		MM[y][x] = 'o';
		ll ok = 1;
		// t==0 -> V
		REP(di, 4) if((t==0 && 2<=di) || (t==1 && di<2)) {
			RANGE(li, 1, max(H, W)*2) {
				ll nx = x+dx[di]*li;
				ll ny = y+dy[di]*li;
				if(IN(nx, 0, W) && IN(ny, 0, H)) {
					if(MM[ny][nx]=='#') {ok=0;break;}
					if(MM[ny][nx]=='o') break;
					MM[ny][nx]='o';
				}
			}
			if(!ok) break;
		}
		if(!ok) continue;
		cands++;
		ll r = f(0, H, W, MM);
		// 相手の選択肢でどれかが負け状態ならこの手を選べばいいので勝ち
		if(!r) {
			if(isRoot) ans++;
			else return 1;
		}
	}
	if(!cands) return 0;
	if(isRoot) return ans;
	// 選択肢あり. すべて相手が勝ちなので負け
	return 0;
}

string SP(ll n) {
	return string(n*2, ' ');
}

ll ans;
// return grundy number for the state
// 0 ... losing state
// !0 ... winning state
ll g(ll isRoot, ll depth, ll x, ll y, ll w, ll h, vector<string>& M, VVVVI& G) {
	ll W = M[0].size();
	ll H = M.size();
	if(w==0 || h==0 || !IN(x, 0, W) || !IN(y, 0, H)) {
//		cout<<SP(depth)<<x<<" "<<y<<" "<<w<<" "<<h<<" -> "<<0<<" (empty cell)"<<endl;
		return 0;
	}
	if(G[x][y][w][h]!=-1) {
//		cout<<SP(depth)<<x<<" "<<y<<" "<<w<<" "<<h<<" -> "<<G[x][y][w][h]<<endl;
		return G[x][y][w][h];
	}
	set<ll> adj;
	// V
	RANGE(X, x, x+w) {
		ll sharp=0;
		RANGE(Y, y, y+h) if(M[Y][X]=='#') sharp=1;
		if(!sharp) {
//			cout<<SP(depth)<<"V "<<X<<endl;
			ll g0 = g(0, depth+1, x, y, X-x, h, M, G);
			ll g1 = g(0, depth+1, X+1, y, x+w-(X+1), h, M, G);
			ll n = g0 ^ g1;
//			cout<<SP(depth)<<x<<" "<<y<<" "<<w<<" "<<h<<" n "<<n<<" "<<g0<<" "<<g1<<endl;
			if(isRoot && n==0) ans+=h;
			adj.insert(n);
		}
	}
	// H
	RANGE(Y, y, y+h) {
		ll sharp=0;
		RANGE(X, x, x+w) if(M[Y][X]=='#') sharp=1;
		if(!sharp) {
//			cout<<SP(depth)<<"H "<<Y<<endl;
			ll g0 = g(0, depth+1, x, y, w, Y-y, M, G);
			ll g1 = g(0, depth+1, x, Y+1, w, y+h-(Y+1), M, G);
			ll n = g0 ^ g1;
//			cout<<SP(depth)<<x<<" "<<y<<" "<<w<<" "<<h<<" n "<<n<<endl;
			if(isRoot && n==0) ans+=w;
			adj.insert(n);
		}
	}
//	cout<<SP(depth)<<x<<" "<<y<<" "<<w<<" "<<h<<" set "<<adj<<endl;
	ll gn = 0;
	while(adj.count(gn)) gn++;
	G[x][y][w][h] = gn;
//	cout<<SP(depth)<<x<<" "<<y<<" "<<w<<" "<<h<<" -> "<<G[x][y][w][h]<<endl;
	return G[x][y][w][h];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int test_cases;
	cin>>test_cases;
	ll W,H;
	REP(ttt, test_cases) {
		cin>>H>>W;
		vector<string> M(H);
		REP(y, H) cin>>M[y];
//		ll ans = f(1, H, W, M);
		VVVVI G(W, VVVI(H, VVI(W+1, VI(H+1, -1))));
		ans = 0;
		g(1, 0, 0, 0, W, H, M, G);
//		DD(G);
		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		return 0;
	}
	return 0;
}



