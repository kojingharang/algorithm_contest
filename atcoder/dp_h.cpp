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
//#define ll long long
#define ll int
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define VVVI vector<vector<vector<ll>>>
#define VVVVI vector<vector<vector<vector<ll>>>>
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define REPR(i,n) for(int i=(int)(n)-1;0<=(i);--i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define RANGER(i,a,b) for(int i=(int)(b)-1,_a=(int)(a);(_a)<=i;--i)
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
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}

#define MOD 1000000007LL
//#define INF (1LL<<60)
#define INF (1<<30)

struct EL {
	ll w, v, c;
	bool operator<(const EL& b) const {
		return c < b.c;
	}
};
std::ostream& operator<<(std::ostream& os, const EL& v) {
	os <<"wvc "<< v.w << " "<<v.v<<" "<<v.c;
	return os;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,W,C, w,v,c;
	ll MC = 50;
	while(cin>>N>>W>>C) {
		// http://kmjp.hatenablog.jp/entry/2013/09/06/0900
		map<ll, vector<PII>> m;
		REP(i, N) {
			cin>>w>>v>>c;
			m[c].PB(MP(w, v));
		}
		// [c][w] : c 色使って重さ w のときの価値の最大値
		VVI dp(C+1, VI(W+1, -INF));
		dp[0][0] = 0;
		ll ans = 0;
		for(auto& kv : m) REPR(c, C) {
			VI dpw(dp[c]);
			dpw[0] = 0;
			for(auto wv : kv.second) REPR(w, W+1) {
				int nw = w + wv.first;
				if(nw < W+1) maxUpdate(dpw[nw], dpw[w]+wv.second);
			}
//			DD(kv.second);
//			DD(dpw);
			REP(w, W+1) maxUpdate(dp[c+1][w], dpw[w]), maxUpdate(ans, dp[c+1][w]);
//			DD(dp);
		}
		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}

// https://suikaba.hatenablog.com/entry/2017/08/21/022215
//int main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	ll N,W,C;
//	ll MC = 50;
//	while(cin>>N>>W>>C) {
//		vector<EL> d(N);
//		REP(i, N) cin>>d[i].w>>d[i].v>>d[i].c;
//		sort(ALL(d));
////		DD(d);
//		// [i][w][c][k] : d[0, i) までにおいて合計 w で c 種類使ってて最後に使った色が k なときの価値の最大値
//		VVVI dp(W+1, VVI(C+1, VI(MC+1, -INF)));
//		dp[0][0][MC] = 0;
//		REP(i, N) {
//			for(int wi=W;0<=wi;wi--) for(int ci=C;0<=ci;ci--) REP(ki, MC+1) if(0 <= dp[wi][ci][ki]) {
//				// skip
////				maxUpdate(dp[wi][ci][ki], dp[wi][ci][ki]);
//				// add
//				ll nw = wi+d[i].w;
//				ll nc = ci + (ki!=d[i].c);
//				if(nw<=W && nc<=C) {
//					maxUpdate(dp[nw][nc][d[i].c], dp[wi][ci][ki] + d[i].v);
//				}
//			}
//		}
////		DD(dp[N]);
//		ll ans = 0;
//		REP(wi, W+1) REP(ci, C+1) REP(ki, MC+1) ans = max(ans, dp[wi][ci][ki]);
//		cout<<ans<<endl;
////		break;
//	}
//	
//	return 0;
//}
