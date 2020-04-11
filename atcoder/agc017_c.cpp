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

void solve(ll N, ll M, VI w, VI xs, VI ys) {
	VI h(N); // h[i] ... cover count for [i, i+1]
	ll cov = 0;
	VI co(N+1);
//	DD(N);
//	DD(M);
	REP(i, N) {
		co[w[i]]++;
	}
	RANGE(i, 1, N+1) {
		if(co[i]) {
			// cover [i-co[i], i]
			RANGE(j, max<int>(0, i-co[i]), i) h[j]++;
		}
	}
	REP(i, N) if(h[i]) cov++;
//		DD(w);
//		DD(h);
//		DD(co);
//		DD(cov);

	REP(i, M) {
		ll X=xs[i], Y=ys[i];
		ll ov = w[X-1];
		ll nv = Y;

		{
			int idx = ov-co[ov];
//				DD(idx);
			if(idx>=0 && idx<N) {
				h[idx]--;
				if(h[idx]==0) cov--;
			}
			co[ov]--;
		}

		{
			co[nv]++;
			int idx = nv-co[nv];
			if(idx>=0 && idx<N) {
//					DD(idx);
				if(h[idx]==0) cov++;
				h[idx]++;
			}
		}
		w[X-1] = Y;
//			DD(w);
//			DD(h);
//			DD(co);
//			DD(cov);

		cout<<N-cov<<endl;
	}
}

int main() {
	//ios::sync_with_stdio(false);
	if(0)
	{
		REP(i, 1000) {
			ll N = UNIFORM_LL(1, 200000), M = UNIFORM_LL(1, 200000);
			VI w(N), xs(M), ys(M);
			REP(i, N) w[i]=UNIFORM_LL(1, N+1);
			REP(i, M) xs[i]=UNIFORM_LL(1, N+1);
			REP(i, M) ys[i]=UNIFORM_LL(1, N+1);
			solve(N, M, w, xs, ys);
		}
		return 0;
	}

	ll N,M;
	while(cin>>N>>M) {
		VI w(N);
		REP(i, N) cin>>w[i];
		VI xs(M), ys(M);
		REP(i, M) {
			cin>>xs[i]>>ys[i];
		}
		solve(N, M, w, xs, ys);
//		break;
	}
	
	return 0;
}
