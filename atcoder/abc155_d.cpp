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

/*

K=4
1以下の個数: 1個 -> 2番目は2以上
2以下の個数: 1個 -> 2番目は3以上
3以下の個数: 5個 -> 6番目は4以上
1 3 3 3 3

-8
-4 -2 3 3
-4 ... 3 3
-2 ... 
3 ... -4
3 ... -4

v <= -8/3 = -2.6

mid=-8
-3 ... -8/-3 = 2.6 < v
mid=8
-3 ... 8/-3=-2.6 < v === (8+2)/-3=10/-3=-3.3=-3<v

-7 5
-35

mid=-35
-7
(-34-6)/-7 = -40/-7 = 5.7 < v
-35/-7 = 5 < v

*/
ll t1(ll K, VI A) {
	ll N = A.size();
	VI cs;
	REP(i, N) RANGE(j, i+1, N) cs.PB(A[i]*A[j]);
	sort(ALL(cs));
	DD(cs);
	return cs[K-1];
}

ll t0(ll K, VI A) {
	ll N = A.size();
	sort(ALL(A));
	ll BIG = 1LL<<62;
	// lo以下の個数<=K-1<hi以下の個数
	ll lo = -BIG, hi = BIG;
	while(lo+1<hi) {
		ll mid = (lo+hi)/2;
		ll co = 0;
		REP(i, N) {
			ll lco = 0;
			if(A[i]==0) lco += (0<=mid) * N;
			else if(0<A[i]) {
				// A[i]>=0 -> v <= mid/A[i]
				// floor
				ll v = 0<=mid ? mid/A[i] : (mid-(A[i]-1))/A[i];
				ll n = upper_bound(ALL(A), v) - A.begin();
//				DD((double)mid/A[i]);DD(v);DD(n);
				lco += n;
			} else {
				// A[i]<0 -> v => mid/A[i]
				// ceil
				ll v = 0>mid ? (mid-(abs(A[i])-1))/A[i] : (mid)/A[i];
				ll n = lower_bound(ALL(A), v) - A.begin();
//				DD((double)mid/A[i]);DD(v);DD(n);
				lco += N-n;
			}
			if(A[i]*A[i]<=mid) lco--;
			co+=lco;
//			DD(i);DD(A[i]);DD(lco);
		}
		co/=2;
//		DD(mid);DD(co);
		if(co<=K-1) lo=mid; else hi=mid;
	}
	ll ans = lo+1;
	return ans;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
//	DD(34/7);
//	DD(-34/-7);
	if(0)
	REP(loop, 10000) {
		ll N = 3;
		ll K = UNIFORM_LL(1, N*(N-1)/2+1);
		VI A(N);
		REP(i, N) A[i]=UNIFORM_LL(-10, 10);
		ll a = t0(K, A);
		ll b = t1(K, A);
		if(a!=b) {
			DD(K);
			DD(A);
			DD(a);DD(b);
			return 0;
		}
	}
	ll N,K;
	while(cin>>N>>K) {
		VI A(N);
		REP(i, N) cin>>A[i];
		ll ans = t0(K, A);
		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}
