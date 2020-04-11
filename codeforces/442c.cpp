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

ll f(ll N, VI w) {
	VI m0(N, 1);
	VI m1(N);
	REP(i, w.size()) {
		ll v = w[i];
		v--;
		if(m0[v]) {
			m0[v]=0;
			if(v-1>=0) m1[v-1]=1;
			if(v+1<N) m1[v+1]=1;
		}
		if(m1[v]) {
			m1[v]=0;
		}
		if(accumulate(ALL(m0), 0LL)==0 && accumulate(ALL(m1), 0LL)==0) return i+1;
	}
	return 2*N;
//	DD(m0);
//	DD(m1);
//	assert(accumulate(ALL(m0), 0LL)==0 && accumulate(ALL(m1), 0LL)==0);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
//		cout<<N*2-2<<endl;
//		VI cs;
//		REP(i, N) REP(l, 2) cs.PB(i+1);
//		ll ans = 2*N;
//		VI best = {N*2};
//		do {
//			ll lans = f(N, cs);
//			if(MP(lans, cs) <= MP(ans, best)) {
//				ans = lans;
//				best = cs;
//			}
//		} while(next_permutation(ALL(cs)));
//		DD(ans);
//		DD(best);
		VI w;
		ll idx = N%2==0 ? 1 : 2;
		ll last = 1;
		for(;idx<=N;) {
			REP(i, 3) {
				ll v = idx-i;
				if(last<=v) w.PB(v);
			}
			last = idx;
			if(idx+2>N) idx++; else idx+=2;
		}
//		DD(w);
//		assert(w.size()==f(N, w));
		cout<<w.size()<<endl;
		cout<<w<<endl;
	}
	
	return 0;
}
