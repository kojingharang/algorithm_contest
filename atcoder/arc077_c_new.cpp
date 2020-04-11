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

ll solve2(ll N, ll M, const VI& w) {
	// Am+B
	VI A(M*2), B(M*2);
	auto plus = [&](int l, int r, int a, int b) {
		A[l] += a;
		A[r+1] -= a;
		B[l] += b;
		B[r+1] -= b;
	};
	RANGE(i, 1, N) {
		ll pv = w[i-1];
		ll cv = w[i];
		if(pv < cv) {
			// x in [1, pv] -> +cv-pv
			plus(1, pv, 0, cv-pv);
			// x in [pv+1, cv] -> +1+cv-x
			plus(pv+1, cv, -1, 1+cv);
			// x in [cv+1, M] -> +cv-pv
			plus(cv+1, M, 0, cv-pv);
		} else if(cv < pv) {
			// x in [1, cv] -> +1+cv-x
			plus(1, cv, -1, 1+cv);
			// x in [cv+1, pv] -> +cv+M-pv
			plus(cv+1, pv, 0, cv+M-pv);
			// x in [pv+1, M] -> +1+cv+M-x
			plus(pv+1, M, -1, 1+cv+M);
		}
	}
//	DD(A);
//	DD(B);
	VI vs(M+1);
	ll ans = 1LL<<60;
	ll a=0, b=0;
	RANGE(i, 1, M+1) {
		a += A[i];
		b += B[i];
		ll v = a * i + b;
		vs[i] = v;
		ans = min(ans, v);
	}
//	DD(vs);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	ll N,M,v;
	
	while(cin>>N>>M) {
		VI w(N);
		REP(i, N) {
			cin>>w[i];
		}
		ll ans = solve2(N, M, w);

		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}
