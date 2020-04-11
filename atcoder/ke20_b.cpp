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

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
struct Gcd {
	typedef ll valueType;
	static ll e() {
		return 0;
	}
	static ll op(ll a, ll b) {
		if(a==e()) return b;
		if(b==e()) return a;
		return gcd(llabs(a), llabs(b));
	}
};
struct Max {
	typedef ll valueType;
	static ll e() {
		return 0;
	}
	static ll op(ll a, ll b) {
		return max(a, b);
	}
};
template<typename Traits>
class SegTree {
public:
	typedef typename Traits::valueType T;
	int N;
	vector<T> dat;
	SegTree(int _N) {
		N=1; while(N<_N) N*=2;
		dat = vector<T>(2*N, Traits::e());
	}
	// idx is 0 base
	void update(int idx, T v) {
		idx += N-1;
		dat[idx] = v;
		while(idx>0) {
			idx = (idx-1)/2;
			dat[idx] = Traits::op(dat[idx*2+1], dat[idx*2+2]);
		}
	}
	// [a, b)
	T query(int a, int b) { return query(a, b, 0, 0, N); }
	T query(int a, int b, int k, int l, int r) {
		if(r<=a || b<=l) return Traits::e();
		if(a<=l && r<=b) return dat[k];
		else {
			T vl = query(a, b, k*2+1, l, (l+r)/2);
			T vr = query(a, b, k*2+2, (l+r)/2, r);
			return Traits::op(vl, vr);
		}
	}
};


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
		vector<PII> XL(N);
		set<ll> rset;
		REP(i, N) {
			ll x, l;
			cin>>x>>l;
			rset.insert(x+l);
			XL[i] = MP(x-l, l);
		}
		sort(ALL(XL));
		vector<ll> rs(ALL(rset));
//		vector<ll> cost(rs.size());
		SegTree<Max> cost(rs.size());

		REP(i, N) {
			ll l = XL[i].FI;
			ll r = XL[i].FI+XL[i].SE*2;
			ll rub = distance(rs.begin(), upper_bound(ALL(rs), l));
			ll ri = distance(rs.begin(), lower_bound(ALL(rs), r));
//			ll mx = 0;
//			REP(j, rub) maxUpdate(mx, cost[j]);
//			maxUpdate(cost[ri], mx+1);
			ll mx = cost.query(0, rub);
			cost.update(ri, max(mx+1, cost.query(ri, ri+1)));
		}
//		DD(dp);
		ll ans = cost.query(0, rs.size());
//		ll ans = 0;
//		REP(j, rs.size()) maxUpdate(ans, cost[j]);
		cout<<ans<<endl;
	}
	
	return 0;
}
