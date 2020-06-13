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
#define VI vector<int>
#define PII pair<ll, ll> 
#define VVI vector<vector<int> >
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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,Q,v,L;
	while(cin>>N) {
		VI V(N), W(N);
		REP(i, N) cin>>V[i]>>W[i];
		cin>>Q;
		VI v_(Q), L(Q);
		REP(qi, Q) {
			cin>>v_[qi]>>L[qi];
		}

		ll ML = *max_element(ALL(L));
		// 深さDの最初のノードは2^(D-1)
		ll D=10;
		// v<=nDならdp値がある
		ll nD = min(N, (1LL<<(D+1))-1);
		// [v(1base)][weight]: max value
		VVI dp(nD+1, VI(ML+1));
		RANGE(vi, 1, dp.size()) REP(wi, dp[0].size()) {
			maxUpdate(dp[vi][wi], dp[vi/2][wi]);
			if(0<=wi-W[vi-1]) maxUpdate(dp[vi][wi], dp[vi/2][wi-W[vi-1]]+V[vi-1]);
		}
//		DD(dp);

		// O(2^D MaxL + Q T 2^T) (T=18-D)
		REP(qi, Q) {
			ll n = v_[qi];
			VI I;
			while(nD<n) {
				I.PB(n-1);
				n/=2;
			}
//			DD(I);DD(n);
			ll ans=0;
			REP(bi, 1<<I.size()) {
				ll v=0, w=0;
				REP(i, I.size()) if(bi>>i&1) {
					v += V[I[i]];
					w += W[I[i]];
				}
//				DD(v);DD(w);
				if(0<=L[qi]-w) {
					ll lans = v + dp[n][L[qi]-w];
					maxUpdate(ans, lans);
				}
			}
			printf("%lld\n", ans);
		}
//		break;
	}
	
	return 0;
}
