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

template<ll MODVAL>
struct Modll {
	ll val;
	Modll() : val(0) {}
	Modll(ll v) : val(v) { normalize(); }
	void normalize() { val = (val+MODVAL) % MODVAL; }
	Modll  operator+ (ll v) { return Modll(val+v); }
	Modll& operator+=(ll v) { val+=v; normalize(); return *this; }
	Modll  operator- (ll v) { return Modll(val-v); }
	Modll& operator-=(ll v) { val-=v; normalize(); return *this; }
	Modll  operator* (ll v) { return Modll(val*v); }
	Modll& operator*=(ll v) { val*=v; normalize(); return *this; }
	Modll  operator^ (ll e) { Modll x(val); Modll v(1); for(;e;x=x*x,e>>=1) if(e&1) v = v * x; return v; } // pow
	Modll inv() { Modll x(val); return x^(MODVAL-2); } // MODVAL must be prime number when use this!
	static Modll inv(ll v) { return Modll(v).inv(); }
	operator ll() { return val; }
};
template<ll MODVAL>
std::ostream& operator<<(std::ostream& os, const Modll<MODVAL>& v) { os << v.val; return os; }
using modll = Modll<1000000007>;


#define MAXN 200010
modll facts[MAXN];
modll inv_facts[MAXN];
// Call gen_facts() before call this
ll modC(ll n, ll r) {
	assert(0<=n && n<MAXN); assert(0<=r && r<=n);
	return modll(facts[n]) * inv_facts[r] * inv_facts[n-r];
}
void gen_facts() {
	facts[0] = 1;
	inv_facts[0] = modll::inv(facts[0]);
	RANGE(i, 1, MAXN) facts[i] = facts[i-1] * modll(i);
	RANGE(i, 1, MAXN) inv_facts[i] = inv_facts[i-1] * modll::inv(i);
	REP(i, MAXN) assert((facts[i] * inv_facts[i])==1);
}

// そのノード以下の書き方組み合わせ数
vector<modll> dp;
// そのノード含めて親方向の書き方組み合わせ数
vector<modll> dp2;
// そのノード以下のノード数
VI size;
// そのノード含めて親方向のノード数
VI size2;
void dfs(ll cur, ll prev, VVI& g) {
	ll ch = 0;
	for(ll adj: g[cur]) if(adj!=prev) ch++;
	if(ch==0) {
		dp[cur] = 1;
		size[cur]=1;
		return;
	}
	modll v = 1LL;
	for(ll adj: g[cur]) if(adj!=prev) {
		dfs(adj, cur, g);
		size[cur]+=size[adj];
		v *= dp[adj]*inv_facts[size[adj]];
	}
	size[cur]++;
	dp[cur] = facts[size[cur]-1] * v;
}
void dfs2(ll cur, ll prev, VVI& g) {
	// 自分の分
	size2[cur]++;
	if(prev!=-1) {
		size2[cur] += size2[prev];
		// 兄弟ただし自分以外
		size2[cur] += size[prev] - size[cur] - 1;
	}

	/*
	親を塗った後, 親の周りただし自分以外を塗る方法の数
		(size2[prev]-1)!Πdp/size
	親の親方向は
		dp2[prev] / (size2[prev]-1)!
	親の子方向は
		dp[prev]からN!と自分方向の寄与を消したものなので
		dp[prev] / (size[prev]-1)! * size[cur]! / dp[cur]
	*/
//	DD("");
//	DD(cur);
//	DD(prev);
	modll v = 1LL;
	if(prev!=-1) {
		v *= dp2[prev] * inv_facts[size2[prev]-1];
//		DD("parent of parent");
//		DD(dp2[prev]);
//		DD(size2[prev]-1);
//		DD(facts[size2[prev]-1]);
//		DD(dp2[prev] * inv_facts[size2[prev]-1]);
	}
	if(prev!=-1) {
		v *= dp[prev] * inv_facts[size[prev]-1] * facts[size[cur]] * dp[cur].inv();
//		DD("bro");
//		DD(dp[prev]);
//		DD(size[prev]);
//		DD(facts[size[prev]-1]);
//		DD(size[cur]);
//		DD(facts[size[cur]]);
//		DD(dp[cur]);
//		DD(dp[prev] * inv_facts[size[prev]-1] * facts[size[cur]] * dp[cur].inv());
	}
	dp2[cur] = 1LL;
	if(prev!=-1) {
		dp2[cur] = facts[size2[cur]-2] * v;
//		DD("total");
//		DD(size2[cur]-2);
//		DD(facts[size2[cur]-2]);
	}
//	DD(dp2[cur]);
	for(ll adj: g[cur]) if(adj!=prev) {
		dfs2(adj, cur, g);
	}
}
int main() {
	gen_facts();
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,A,B;
	while(cin>>N) {
		VVI g(N);
		REP(i, N-1) {
			cin>>A>>B;
			A--;B--;
			g[A].PB(B);
			g[B].PB(A);
		}
//		REP(i, N) {
//			dp = vector<modll>(N);
//			size = VI(N);
//			dfs(i, -1, g);
//			DD(dp);DD(size);
//			cout<<dp[i]<<endl;
//		}
		dp = vector<modll>(N);
		size = VI(N);
		dfs(0, -1, g);
		dp2 = vector<modll>(N);
		size2 = VI(N);
		dfs2(0, -1, g);
//		DD(dp);
//		DD(dp2);
//		DD(size);
//		DD(size2);
		REP(i, N) {
			/*
			(N-1)!*dp2[cur]/(size2[cur]-1)!*dp[cur]/(size[cur]-1)!
			*/
			modll ans = facts[N-1]*dp2[i]*inv_facts[size2[i]-1]*dp[i]*inv_facts[size[i]-1];
			cout<<ans<<endl;
		}
//		break;
	}
	
	return 0;
}
