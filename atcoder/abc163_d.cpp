#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>
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
void uniq(VI& es) { sort(ALL(es)); es.erase(unique(ALL(es)), es.end()); }

#define INF (1LL<<60)
/*
1 ... N+1とおり
2 ... (N+1)*Nとおり N+1CN+1-i

0 1 2 3
i=1 ... 0-3 0 3

i=2 ... 1-5 0+1 2+3
0 1 1
0 2 2
0 3 3
1 2 3
1 3 4 
2 3 5
i=3 ... 3-6 0+1+2
*/
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
// combination
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
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,K;
//	gen_facts();
	while(cin>>N>>K) {
		modll ans=0LL;
		ll lb=0, ub=N;
		RANGE(i, 1, N+2) {
			// N+1 C N+1-i
//			DD(i);DD(lb);DD(ub);
			if(K<=i) ans+=max(0LL, ub-lb+1);
			lb+=i;ub+=N-i;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
