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
/*
a+b b-c c+d d-e
a+2b-c b-2c-d c+2d-e
a+b+c+d b-c+d-e
a+2c+e

1 2 0 2 -1

+-+-+-
+-+-+
-+-+
-+-
+-
+

+-+-+-+
-+-+-+
-+-+-
+-+-
+-+
-+
-

c: 0: 1 1: -1
 2: 49 3: -49 
 	49 = 49 C 1

 4: 1176 5: -1176 
 	1176 = 49 * 48 / 2! = 49 C 2

 6: 18424 7: -18424 
 	18424 = 49 * 48 * 47 / 3! = 49 C 3

 8: 211876 9: -211876 
 	211876 = 49 * 48 * 47 * 46 / 4! = 49 C 4

 10: 1906884 

4k回やると nC0 0 nC1 0 nC2 0 ... nCn になるので
4k 個まではシミュレートして上記を計算するとできる。

*/
struct modll {
	static const ll MODVAL;
	ll val;
	modll() : val(0) {}
	modll(ll v) : val(v) { normalize(); }
	void normalize() { val = (val+MODVAL) % MODVAL; }
	modll  operator+ (ll v) { return modll(val+v); }
	modll& operator+=(ll v) { val+=v; normalize(); return *this; }
	modll  operator- (ll v) { return modll(val-v); }
	modll& operator-=(ll v) { val-=v; normalize(); return *this; }
	modll  operator* (ll v) { return modll(val*v); }
	modll& operator*=(ll v) { val*=v; normalize(); return *this; }
	modll  operator^ (ll e) { modll x(val); modll v(1); for(;e;x=x*x,e>>=1) if(e&1) v = v * x; return v; } // pow
	modll inv() { modll x(val); return x^(MODVAL-2); } // MODVAL must be prime number when use this!
	static modll inv(ll v) { return modll(v).inv(); }
	operator ll() { return val; }
};
const ll modll::MODVAL = 1000000007;

#define MAXN 200010
modll facts[MAXN];
modll inv_facts[MAXN];
ll mod_combination(ll n, ll r) {
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

int main() {
	//ios::sync_with_stdio(false);
	gen_facts();
//	ll N = 13;
//	vector<map<ll, ll>> c(N);
//	REP(i, N) c[i][i] = 1;
//	ll sign = 1;
//	REP(i, N-1) {
//		vector<map<ll, ll>> n(c.size()-1);
//		REP(j, c.size()-1) {
////			n[j] = c[i] + sign * c[i+1];
//			map<ll, ll> e = c[j];
//			for(auto& kv : c[j+1]) e[kv.first] += sign * kv.second;
////			DD(j);DD(n.size());
//			n[j] = e;
//			sign *= -1;
//		}
//		c = n;
//		DD(c);
//	}
//	VI w = {3, 6, 9, 12, 15};
//	ll ans = 0;
//	for(auto& kv : c[0]) {
//		ans += w[kv.first] * kv.second;
//	}
//	DD(ans);
//	return 0;

	ll N;
	while(cin>>N) {
		vector<modll> w(N);
		REP(i, N) {
			ll v;
			cin>>v;
			w[i] = v;
		}
		ll sign = 1;
		while(w.size()%4!=1) {
			vector<modll> nw(w.size()-1);
			REP(i, w.size()-1) {
				nw[i] = w[i] + sign * w[i+1];
				sign *= -1;
			}
			w = nw;
//			DD(w.size());
//			REP(i, w.size()) DD(w[i]);
		}
		modll ans = 0;
		ll n = (w.size()-1)/2;
		REP(i, n+1) {
			ans += mod_combination(n, i) * w[2*i];
		}
		ans += modll::MODVAL;
		cout<<ans<<endl;
	}
	
	return 0;
}
