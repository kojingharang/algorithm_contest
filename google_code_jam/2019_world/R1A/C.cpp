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
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

ll Hd, Ad, Hk, Ak, B, D;

ll solBS(ll hd, ll Ad, ll hk, ll Ak, ll bs, ll ds) {
	ll ans = 0;
	bool prevCure = false;
	REP(i, ds) {
		ans++;
		if(hd<=max(0LL, Ak-D)) {
			if(prevCure) return -1;
			prevCure = true;
			hd = Hd;
		} else {
			prevCure = false;
			Ak = max(0LL, Ak-D);
		}
		hd-=Ak;
		if(hd<=0) return -1;
	}
	REP(i, bs) {
		ans++;
		if(hd<=Ak) {
			if(prevCure) return -1;
			prevCure = true;
			hd = Hd;
		} else {
			prevCure = false;
			Ad += B;
		}
		hd-=Ak;
		if(hd<=0) return -1;
	}
	while(1) {
//		DD(hd);
//		DD(hk);
		ans++;
		if(hk<=Ad) return ans;

		if(hd<=Ak) {
			if(prevCure) return -1;
			prevCure = true;
			hd = Hd;
		} else {
			prevCure = false;
			hk -= Ad;
		}
		if(hk<=0) return ans;
		hd-=Ak;
		if(hd<=0) return -1;
	}
	return -1;
}

ll INF = 1LL<<60;

ll solve() {
	ll ans = INF;
	REP(bs, 101) REP(ds, 101) {
//		if(!(bs==0&&ds==0)) continue;
		ll lans = solBS(Hd, Ad, Hk, Ak, bs, ds);
//		DD(lans);
		if(lans!=-1) ans = min(ans, lans);
	}
	if(ans==INF) return -1;
	return ans;
//	// Attackするだけ
//	ll win = (Hk+Ad-1)/Ad;
//	ll lose = (Hd+Ak-1)/Ak;
//	if(win<=lose) return win;
//
//	// 即死
//	if(Hd <= Ak-D) return -1;
//
//	// Cureしかできないので勝てない
//	if(lose<=2) return -1;
//
//	// ぎりぎりでCure
//	ll cure = win/lose;
//	return win+cure;
}

/*

*/
int main() {
	int test_cases;
	cin>>test_cases;
	REP(ttt, test_cases) {
		cin>>Hd>>Ad>>Hk>>Ak>>B>>D;
		ll ans = solve();
		if(ans==-1) {
			cout<<"Case #"<<ttt+1<<": "<<"IMPOSSIBLE"<<endl;
		} else {
			cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
		}
//		return 0;
	}
	return 0;
}



