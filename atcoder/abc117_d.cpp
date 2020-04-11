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
#include <functional>
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

void pr(ll k, VI& A) {
	ll N = 60;
	string s(N, '0');
	REP(i, N) {
		if(k>>i&1) s[N-1-i] = '1';
	}
	cout<<s<<endl;
	VI w;
	REP(bi, 60) {
		ll co = 0;
		REP(i, A.size()) if((A[i]^k)>>bi&1) co++;
		w.PB(co);
	}
	reverse(ALL(w));
	DD(w);
}

ll solve(ll N, ll K, VI A) {
	VI Ks;
	Ks.PB(K);
	REP(bi, 60) {
		if(K>>bi&1) {
			ll k = (K ^ (1LL<<bi)) | ((1LL<<bi)-1);
//			DD(bi);
//			pr(k, A);
			Ks.PB(k);
		}
	}
//	DD(Ks);
	ll ans = 0;
	REP(ki, Ks.size()) {
		K = Ks[ki];
		ll k = 0;
		REP(bi, 60) {
	//	for(ll bi=60;bi>=0;bi--) {
//			if((k|1LL<<bi) <= K) {
			if(K>>bi&1) {
				ll co = 0;
				REP(i, N) if(A[i]>>bi&1) co++;
//				DD(bi);DD(co);
				if(co<(N-N/2)) k |= 1LL<<bi;
			}
		}
//		pr(k, A);
		ll lans = 0;
		REP(i, N) lans += A[i]^k;
		ans = max(ans, lans);
	}
	return ans;
}

ll naive(ll N, ll K, VI A) {
	ll ans = 0;
	REP(k, K+1) {
		ll lans = 0;
		REP(i, N) lans += A[i]^k;
		ans = max(ans, lans);
	}
	REP(k, K+1) {
		ll lans = 0;
		REP(i, N) lans += A[i]^k;
		if(ans==lans) {
			pr(k, A);
		}
	}
	return ans;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	if(0)
	REP(loop, 1000) {
		ll N = 10;
		ll K = 100;
		VI A(N);
		pr(K, A);
		REP(i, N) A[i] = UNIFORM_LL(0, 10000);
		ll ref = naive(N, K, A);
		ll ans = solve(N, K, A);
		DD(N);DD(K);DD(A);DD(ref);DD(ans);
		assert(ref==ans);
	}
	ll N,K;
	while(cin>>N>>K) {
		VI A(N);
		REP(i, N) cin>>A[i];
		ll ans = solve(N, K, A);
		cout<<ans<<endl;
	}
	
	return 0;
}
