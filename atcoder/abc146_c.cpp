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

ll solve(ll A, ll B, ll X) {
	ll lb = 1, ub=10, ans=0;
	RANGE(di, 1, 11) {
		ll N = (X - B*di) / A;
		minUpdate(N, ub-1);
		minUpdate(N, 1000000000LL);
//		DD(di);
//		DD(N);
		if(lb<=N && N<ub) {
			maxUpdate(ans, N);
		}
		lb*=10;
		ub*=10;
	}
	return ans;
}

ll cost(ll A, ll B, ll N) {
	ll di = 0;
	ll n = N;
	while(n) {
		di++;
		n/=10;
	}
//	DD(N);DD(di);
	return A*N+B*di;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	if(0)
	REP(loop, 100000000) {
//		ll A = UNIFORM_LL(1, 1000000001);
//		ll B = UNIFORM_LL(1, 1000000001);
//		ll X = UNIFORM_LL(1, 1000000000000000001LL);
		ll A = UNIFORM_LL(1, 10001);
		ll B = UNIFORM_LL(1, 10001);
		ll X = UNIFORM_LL(1, 10000000001LL);
		ll N = solve(A, B, X);
		ll t9 = 1000000000LL;
		if(cost(A, B, N) <= X && ((0<=N && N < t9 && cost(A, B, N+1) > X) || N==t9)) {
		} else {
			DD(A);DD(B);DD(X);DD(N);
			DD(cost(A, B, N));
			DD(cost(A, B, N+1));
			return 0;
		}
	}
	ll A,B,X;
	while(cin>>A>>B>>X) {
		ll ans = solve(A,B,X);
		cout<<ans<<endl;
	}
	
	return 0;
}
