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

#define INF (1LL<<60)

ll naive(ll N) {
//	DD(N);
	ll ans = 0;
	map<ll, ll> h;
	VVI w(10);
	while(2<=N) {
		ll v = N;
		map<ll, ll> lh;
		while(v&&v%2==0) {
			v/=2;
			lh[2]++;
		}
		while(v&&v%5==0) {
			v/=5;
			lh[5]++;
		}
//		if(lh[5]) cout<<N<<" "<<lh[5]<<endl;
//		if(lh[5]) w[lh[5]].PB(N);
		h[2]+=lh[2];
		h[5]+=lh[5];
		N-=2;
	}
//	DD(w);
//	REP(i, w.size()) DD(w[i].size());
//	DD(h);
	return min(h[2], h[5]);
}

/*
10 1
20 1
30 1
40 1
50 2
60 1
70 1
80 1
90 1
100 2
150 2
200 2
250 2
625 4
考察: 奇数なら0, 偶数なら2と5の指数の小さい方
2は多いので5の個数
*/
ll solve(ll N) {
	ll ans = 0;
	if(N%2==0) {
		ll div = 10;
		while(N) {
			ans += N/div;
			if(N/div==0) break;
			div *= 5;
		}
	}
	return ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
//	ll a = naive(10000);
//	return 0;
//	RANGE(N, 2, 10000) {
//		ll a = naive(N);
//		ll b = solve(N);
//		if(a!=b) {
//			DD(N);DD(a);DD(b);
//			return 0;
//		}
//	}
	while(cin>>N) {
		ll b = solve(N);
		cout<<b<<endl;
	}
	
	return 0;
}
