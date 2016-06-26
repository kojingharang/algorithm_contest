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
using namespace std;

#define EPS 1e-12
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


struct modll {
	static const ll MODVAL;
	ll val;
	modll(ll v) { val = v; normalize(); }
	void normalize() { val = (val+MODVAL) % MODVAL; }
	modll  operator+ (ll v) { return modll(val+v); }
	modll& operator+=(ll v) { val+=v; normalize(); return *this; }
	modll  operator- (ll v) { return modll(val-v); }
	modll& operator-=(ll v) { val-=v; normalize(); return *this; }
	modll  operator* (ll v) { return modll(val*v); }
	modll& operator*=(ll v) { val*=v; normalize(); return *this; }
	modll  operator^ (ll e) { modll x(val); modll v(1); for(;e;x=x*x,e>>=1) if(e&1) v = v * x; return v; }
	modll inv() { modll x(val); return x^(MODVAL-2); } // MODVAL must be prime number when use this!
	operator ll() { return val; }
};
const ll modll::MODVAL = 1000000007;


#define MAXN 10010
ll facts[MAXN];
ll inv_facts[MAXN];

ll mod_combination(ll n, ll r) {
	assert(0<=n && n<MAXN); assert(0<=r && r<=n);
	return modll(facts[n]) * inv_facts[r] * inv_facts[n-r];
}

ll comb_naive(ll n, ll r) {
	assert(0<=n && n<MAXN);
	assert(0<=r && r<=n);
	ll v = 1;
	RANGE(i, 1, n+1) {v*=i;if(v>(1LL<<60)) return -1;}
	RANGE(i, 1, r+1) v/=i;
	RANGE(i, 1, n-r+1) v/=i;
//	cout<<"naive "<<n<<" "<<r<<" = "<<v<<endl;
	return v;
}

int main() {
	facts[0] = 1;
	inv_facts[0] = modll(facts[0]).inv();
	RANGE(i, 1, MAXN) facts[i] = modll(facts[i-1]) * (ll)i;
	RANGE(i, 1, MAXN) inv_facts[i] = modll(inv_facts[i-1]) * modll(i).inv();
//	REP(i, 10) cout<<i<<" "<<facts[i]<<endl;
//	REP(i, 10) cout<<i<<" "<<inv_facts[i]<<endl;
	
	REP(i, MAXN) assert(modll(facts[i]) * inv_facts[i]==1);
//	REP(n, MAXN) REP(r, n+1) {
//		ll r0 = comb_naive(n, r);
//		ll r1 = MODCOMB(n, r);
//		if(r0!=-1) {
//			if(r0%MODVAL!=r1) {
//				cout<<"diff "<<n<<" "<<r<<"  :  "<<r0<<" "<<r1<<endl;
//				return 0;
//			}
//		}
//	}
	
	int T;
	cin>>T;
	REP(ttt, T) {
		ll N, K;
		cin>>N>>K;
		VI w(N);
		REP(i, N) cin>>w[i];
		sort(ALL(w));
//		cout<<w<<endl;
		modll ans = 0;
		REP(i, N) {
			if(i-(K-1)>=0) {
//				cout<<w[i]<<" "<<i<<" C "<<i-(K-1)<<endl;
				//ans += MODMUL(w[i], MODCOMB(i, i-(K-1)));           // だめ
				ans += modll(w[i]) * mod_combination(i, i-(K-1)); // OK
			}
		}
		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		break;
	}
	return 0;
}


