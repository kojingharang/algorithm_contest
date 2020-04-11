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

VI put(const VI& w) {
	ll N = w.size();
	ll bi=-1;
	ll bMin=-1;
	ll bMax=-1;
	REP(i, N) {
		if(w[i]) continue;
		ll Ls=0, Rs=0;
		for(int j=i-1;j>=0;j--) if(w[j]) break; else Ls++;
		for(int j=i+1;j<N;j++) if(w[j]) break; else Rs++;
		ll Min = min(Ls, Rs);
		ll Max = max(Ls, Rs);
		if(bMin<Min || (bMin==Min&&bMax<Max)) {
			bMin=Min;
			bMax=Max;
			bi=i;
		}
	}
	assert(bi>=0);
	return {bi, bMin, bMax};
}

// return: min, max
VI naive(ll N, ll K) {
	VI w(N);
	VI c;
	REP(i, K) {
		c = put(w);
//		DD(c);
		w[c[0]]=1;
//		DD(w);
	}
	return {c[1], c[2]};
}

/*
分割した結果のmax-min≦1
5 5 5 6 5 6 5 6

6(->2,3)が3回, 5(->2,2)が5回


w: 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 

2 2 2 2 2 2 2 3 2 2 2 3 2 2 2 3

foo
2の累乗回目の分割後、スペースの大きさは2種類しかないのでM0, M1とおく。M0がC0回, M1がC1回とわかっているとする.
M0 -> (M0-1)/2 M0-(M0-1)/2 に分割される
M1 -> (M1-1)/2 M1-(M1-1)/2 に分割される
この4種類の数値のmax-min≦1なので foo に戻る


*/
void foo(ll M0) {
	ll M1 = M0+1;
	M0--; M1--;
	VI a = {
		M0/2,
		M0-M0/2,
		M1/2,
		M1-M1/2,
	};
	sort(ALL(a));
	assert(a[3]-a[0]<=1);
}

// return: min, max
VI solve(ll N, ll K) {
	ll M0 = 0;
	ll M1 = N;
	ll C0 = 0;
	ll C1 = 1;
	REP(po, 100) {
//		DD(po);
//		DD(M0);
//		DD(M1);
//		DD(C0);
//		DD(C1);
		ll co = 1LL<<po;
		ll M10 = (M1-1)/2;
		ll M11 = (M1-1)-M10;
		ll M00 = (M0-1)/2;
		ll M01 = (M0-1)-M00;
//		DD(M00);
//		DD(M01);
//		DD(M10);
//		DD(M11);
		if(K-co<=0) {
			if(K<=C1) return {M10, M11};
			else      return {M00, M01};
		}
		VI cands;
		if(M0) cands.PB(M00), cands.PB(M01);
		if(M1) cands.PB(M10), cands.PB(M11);
		assert(cands.size());
		ll NM0 = *min_element(ALL(cands));
		ll NM1 = *max_element(ALL(cands));
		ll NC0 = 0, NC1 = 0;
		vector<pair<ll, ll>> ps = {
			{M00, C0},
			{M01, C0},
			{M10, C1},
			{M11, C1},
		};
		REP(i, 4) {
			if(NM0==ps[i].first) NC0 += ps[i].second;
			else if(NM1==ps[i].first) NC1 += ps[i].second;
		}
		M0 = NM0;
		M1 = NM1;
		C0 = NC0;
		C1 = NC1;
		K-=co;
	}
	assert(false);
	return {0, 0};
}

int main() {
//	RANGE(M, 1, 1000) foo(M);
//	return 0;

//	RANGE(N, 1, 1000) RANGE(K, 1, N+1) {
//		cout<<endl<<endl;
//		DD(N);
//		DD(K);
//		auto nans = naive(N, K);
//		auto ans = solve(N, K);
//		if(ans!=nans) {
//			DD("diff");
//			DD(nans);
//			DD(ans);
//			assert(false);
//		}
//	}

	int test_cases;
	cin>>test_cases;
	ll N,K;
	string s;
	REP(ttt, test_cases) {
		cin>>N>>K;
//		auto nans = naive(N, K);
		auto ans = solve(N, K);
//		if(ans!=nans) {
//			DD("diff");
//			DD(nans);
//			DD(ans);
//			assert(false);
//		}
		cout<<"Case #"<<ttt+1<<": "<<ans[1]<<" "<<ans[0]<<endl;
//		return 0;
	}
	return 0;
}



