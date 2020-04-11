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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}

#define MOD 1000000007LL
#define INF (1LL<<60)
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
const ll modll::MODVAL = 998244353;
std::ostream& operator<<(std::ostream& os, const modll& v) { os << v.val; return os; }

ll naive(ll N, VI A) {
	ll total = accumulate(ALL(A), 0LL);
	map<PII, modll> h;
	h[MP(0, 0)] = 1LL;
	REP(i, N) {
		map<PII, modll> nh;
		for(auto& kv : h) {
			PII v = kv.first;
			if((v.FI+A[i])*2<total) nh[MP(v.FI+A[i], v.SE)]+=kv.SE;
			if((v.SE+A[i])*2<total) nh[MP(v.FI, v.SE+A[i])]+=kv.SE;
			nh[MP(v.FI, v.SE)]+=kv.SE;
		}
		h = nh;
	}
//		DD(h);
	modll ans = 0;
	for(auto& kv : h) {
		auto p = kv.FI;
		ll a = p.FI;
		ll b = p.SE;
		ll c = total-a-b;
		if(0<a && 0<b&&0<c&&a*2<total && b*2<total && c*2<total) ans += kv.SE;
	}
	return ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
		VI A(N);
		REP(i, N) cin>>A[i];
		ll total = accumulate(ALL(A), 0LL);
		// P[i] ... R>=G,B としたときの R==i となる組み合わせ数
		vector<modll> P(total+1);
		P[0] = 1;
		// P2[i] ... R>=G && B==0 としたときの R==i となる組み合わせ数
		vector<modll> P2(total+1);
		P2[0] = 1;
		REP(i, N) {
			vector<modll> NP(total+1);
			vector<modll> NP2(total+1);
			REP(j, P.size()) {
				if(P[j]) {
					// use
					NP[j+A[i]] += P[j];
					// don't use
					// 2or3つめに加算
					NP[j] += P[j]*2LL;
				}
				if(P2[j]) {
					// use
					NP2[j+A[i]] += P2[j];
					// don't use
					// 3つめには入れない。2つめに加算
					NP2[j] += P2[j];
				}
			}
			P = NP;
			P2=NP2;
//			DD(P);
		}
//		DD(P);
//		DD(P2);
		modll ans = 1LL;
		REP(i, N) ans *= 3;
		REP(a, P.size()) if(2*a>=total) {
			ans -= P[a] * 3LL;
		}
//		DD(ans);
		if(total%2==0) {
//			DD(P2[total/2]);
			ans += P2[total/2] * 3LL;
		}
//		ll ans = naive(N, A);
		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}
