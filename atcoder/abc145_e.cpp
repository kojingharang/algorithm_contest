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

ll ref(ll N, ll T, VI a, VI b) {
	ll mi = 0;
	REP(i, N) if(b[mi]<b[i]) mi=i;
//		DD(mi);
	VI A, B;
	REP(i, N) if(i!=mi) {
		A.PB(a[i]);
		B.PB(b[i]);
	}
	N--;
	VI dp(T);
	REP(i, N) {
//		DD(dp);
		VI ndp(dp);
		REP(t, T) if(t+A[i]<T) {
			ll nt = t+A[i];
//			DD(A[i]);DD(B[i]);DD(t);
			maxUpdate(ndp[nt], dp[t]+B[i]);
		}
		dp = ndp;
	}
//	DD(dp);
	ll mx = 0;
	REP(t, T) maxUpdate(mx, dp[t]);
	ll ans = mx + b[mi];
	return ans;
}

ll solve1(ll N, ll T, VI A, VI B) {
	ll ma = *max_element(ALL(A));
	vector<PII> ps(N);
	REP(i, N) ps[i] = MP(A[i], B[i]);
	sort(ALL(ps));
	REP(i, N) {
		A[i] = ps[i].FI;
		B[i] = ps[i].SE;
	}
//	DD(A);DD(B);
	VI dp(T+ma);
	REP(i, N) {
//		DD(dp);
		VI ndp(dp);
		REP(t, T) {
			ll nt = t+A[i];
//			DD(A[i]);DD(B[i]);DD(t);
			maxUpdate(ndp[nt], dp[t]+B[i]);
		}
		dp = ndp;
	}
//	DD(dp);
	return *max_element(ALL(dp));
}

ll solve(ll N, ll T, VI A, VI B) {
	VVI dp(2, VI(T));
	REP(i, N) {
//		DD(dp);
		VVI ndp(dp);
		REP(used, 2) REP(t, T) {
			ll nt = t+A[i];
//			DD(A[i]);DD(B[i]);DD(t);
			if(nt<T) maxUpdate(ndp[used][nt], dp[used][t]+B[i]);
			if(used==0) {
				maxUpdate(ndp[1][t], dp[used][t]+B[i]);
			}
		}
		dp = ndp;
	}
//	DD(dp);
	ll ans = 0;
	REP(used, 2) {
		maxUpdate(ans, *max_element(ALL(dp[used])));
	}
	return ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,T;
	if(0)
	REP(loop, 1000) {
		N = UNIFORM_LL(1, 3);
		T = UNIFORM_LL(1, 10);
		VI A(N), B(N);
		REP(i, N) {
			A[i] = UNIFORM_LL(1, 100);
			B[i] = UNIFORM_LL(1, 100);
		}
		ll a = solve1(N, T, A, B);
		ll b = solve(N, T, A, B);
//		ll b = ref(N, T, A, B);
		if(a!=b) {
			DD(N);DD(T);DD(A);DD(B);
			DD(a);DD(b);
			return 0;
		}
	}
//	return 0;
	while(cin>>N>>T) {
		VI A(N), B(N);
		REP(i, N) cin>>A[i]>>B[i];
		ll ans = solve(N, T, A, B);
		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}
