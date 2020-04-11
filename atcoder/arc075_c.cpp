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

#define MOD 1000000007LL
#define INF (1LL<<60)

/*
	int N=w.size();
	BIT<int> bit(N);
	ll co=0;
	REP(i, N) {
		bit.add(w[i]-1, 1);
		co += bit.sum(w[i], N-1);
	}
	cout<<co<<endl;
*/
template<typename T>
struct BIT {
	vector<T> w;
	BIT(int N) { w = vector<T>(N); }
	// sum of w[i], i in [l, r]
	T sum(int l, int r) {
		if(l==0) {
			T s=0;
			for(;r>=0;r=(r&(r+1))-1) s+=w[r];
			return s;
		}
		return sum(0, r) - sum(0, l-1);
	}
	// i in [0, N)
	void add(int i, T v) {
		for(;i<(int)w.size();i|=i+1) w[i] += v;
	}
};


/*
iより右側にある累積和のうちそれより左の累積和以上のものの個数が logN でわかれば全体 NlogN でいける。
しかし set を使うと lower_bound のあと distance が O(N) かかるのでだめ。

あとで
座標圧縮 + BITで数えられる.
なるほど。
*/
int main() {
	//ios::sync_with_stdio(false);
	ll N,K;
	while(cin>>N>>K) {
		VI w(N), acc(N+1);
		REP(i, N) cin>>w[i];
		REP(i, N) w[i]-=K;
		REP(i, N) acc[i+1] = acc[i] + w[i];
//		DD(acc);

		ll ans = 0;
		VI se;
		VI z(N+1);
		{
			vector<PII> p(acc.size());
			REP(i, acc.size()) p[i] = MP(acc[i], i);
//			DD(p);
			sort(ALL(p));
			REP(i, acc.size()) z[p[i].second] = i;
		}
//		DD(z);

		BIT<int> bit(N+1);
		REP(ii, N) {
			ll i = N-1-ii;
//			ll k = i==0 ? 0 : acc[i-1];
			// insert acc[i]
//			se.PB(acc[i]);
			bit.add(z[i+1], 1);
			// query >=k
//			sort(ALL(se));
//			ll cnt = 0;
//			for(ll v : se) if(v>=k) cnt++;
//			DD(z[i+1]);
//			DD(z[i-1+1]);
			ll cnt2 = bit.sum(z[i], N);
//			DD(i);DD(cnt);DD(cnt2);
//			assert(cnt==cnt2);
			ans += cnt2;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
