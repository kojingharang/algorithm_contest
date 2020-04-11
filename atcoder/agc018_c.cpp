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

ll naive(VVI w, ll X, ll Y, ll Z) {
	ll N = X+Y+Z;
	VI idx(N);
	RANGE(i, X, X+Y) idx[i]=1;
	RANGE(i, X+Y, N) idx[i]=2;
	ll ans = 0;
	do {
		ll lans = 0;
		REP(i, N) lans += w[i][idx[i]];
//		DD(lans);
//		DD(idx);
		ans = max(ans, lans);
	} while(next_permutation(ALL(idx)));
	do {
		ll lans = 0;
		REP(i, N) lans += w[i][idx[i]];
		if(lans==ans) {
			DD(lans);
			DD(idx);
		}
	} while(next_permutation(ALL(idx)));
	return ans;
}

ll solve(VVI w, ll X, ll Y, ll Z) {
	ll N = X+Y+Z;
	vector<PII> gs(N);
	REP(i, N) gs[i] = MP(w[i][0]-w[i][1], i);
	sort(ALL(gs));
	ll ans = 0;
//	DD(gs);
	// Y   X
	RANGE(k, Y, Y+Z+1) {
//		DD(k);
		vector<PII> sb(k);
		ll lans = 0;
		REP(i, k) {
			int I = gs[i].second;
			sb[i] = MP(w[I][1]-w[I][2], I);
		}
		sort(ALLR(sb));
		REP(j, Y) lans += w[sb[j].second][1];
		RANGE(j, Y, k) lans += w[sb[j].second][2];

		vector<PII> gb(N-k);
		RANGE(i, k, N) {
			int I = gs[i].second;
			gb[i-k] = MP(w[I][0]-w[I][2], I);
		}
		sort(ALLR(gb));
		REP(j, X) lans += w[gb[j].second][0];
		RANGE(j, X, N-k) lans += w[gb[j].second][2];
//		DD(lans);
//		DD(used);
		ans = max(ans, lans);
	}
	return ans;
}

ll solve2(VVI w, ll X, ll Y, ll Z) {
	ll N = X+Y+Z;
	vector<PII> gs(N);
	REP(i, N) gs[i] = MP(w[i][0]-w[i][1], i);
	sort(ALL(gs));
//	DD(gs);
	VI vSB(N+1);
	// Y   X
	{
		ll S=0, B=0;
		priority_queue<PII, vector<PII>, greater<PII>> q;
		REP(i, Y) {
			int I = gs[i].second;
			q.push(MP(w[I][1]-w[I][2], I));
			S += w[I][1];
		}
//		DD(S);
//		RANGE(k, Y, Y+Z+1) {
//			vector<PII> sb(k);
//			ll lans = 0;
//			REP(i, k) {
//				int I = gs[i].second;
//				sb[i] = MP(w[I][1]-w[I][2], I);
//			}
//			sort(ALLR(sb));
//			REP(j, Y) lans += w[sb[j].second][1];
//			RANGE(j, Y, k) lans += w[sb[j].second][2];
//			vv[k] += lans;
//		}
		REP(i, Z+1) {
			ll k = Y+i;
			vSB[k] += S+B;
			int I = gs[Y+i].second;
			q.push(MP(w[I][1]-w[I][2], I));
			S += w[I][1];
			auto Min = q.top();q.pop();
			S -= w[Min.second][1];
			B += w[Min.second][2];
		}
	}
	VI vGB(N+1);
//	VI vv(N+1);
	{
		ll G=0, B=0;
		priority_queue<PII, vector<PII>, greater<PII>> q;
		REP(i, X) {
			int I = gs[N-1-i].second;
			q.push(MP(w[I][0]-w[I][2], I));
			G += w[I][0];
		}
//		DD(G);
		REP(i, Z+1) {
			ll k = Y+(Z-i);
			vGB[k] += G+B;
			int I = gs[N-X-1-i].second;
			q.push(MP(w[I][0]-w[I][2], I));
			G += w[I][0];
			auto Min = q.top();q.pop();
			G -= w[Min.second][0];
			B += w[Min.second][2];
		}
//		RANGE(k, Y, Y+Z+1) {
//			ll lans = 0;
//			vector<PII> gb(N-k);
//			RANGE(i, k, N) {
//				int I = gs[i].second;
//				gb[i-k] = MP(w[I][0]-w[I][2], I);
//			}
//			sort(ALLR(gb));
//			REP(j, X) lans += w[gb[j].second][0];
//			RANGE(j, X, N-k) lans += w[gb[j].second][2];
//	//		DD(lans);
//	//		DD(used);
//			vv[k] += lans;
//		}
	}
//	DD(vGB);
//	DD(vv);
	ll ans = 0;
	RANGE(k, Y, Y+Z+1) {
		ans = max(ans, vSB[k]+vGB[k]);
	}
	return ans;
}

int main() {
	//ios::sync_with_stdio(false);
	if(0)
	REP(i, 1000) {
		ll X = UNIFORM_LL(1, 5);
		ll Y = UNIFORM_LL(1, 5);
		ll Z = UNIFORM_LL(1, 5);
		ll N = X+Y+Z;
		VVI w(N, VI(3));
		REP(i, N) REP(j, 3) w[i][j] = UNIFORM_LL(1, 1000);
//		ll ref = naive(w, X, Y, Z);
		ll ref = solve(w, X, Y, Z);
		ll ans = solve2(w, X, Y, Z);
		DD(X);
		DD(Y);
		DD(Z);
		DD(w);
		DD(ref);
		DD(ans);
		assert(ref==ans);
	}
	ll X,Y,Z;
	while(cin>>X>>Y>>Z) {
		ll N = X+Y+Z;
		VVI w(N, VI(3));
		REP(i, N) REP(j, 3) cin>>w[i][j];
		ll ans = solve2(w, X, Y, Z);
		cout<<ans<<endl;
	}
	
	return 0;
}
