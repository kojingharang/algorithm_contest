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

ll naive(VI w) {
	ll N = w.size();
	ll K = 0;
	while(1) {
		ll mx = *max_element(ALL(w));
		if(mx<N) break;
		REP(i, N) {
			if(w[i]==mx) {
				w[i]-=N+1;
				break;
			}
		}
		REP(i, N) w[i]++;
//		DD(w);
		K++;
	}
	return K;
}

ll naive2(VI w) {
	ll N = w.size();
	ll K = 0;
	while(1) {
		bool p=0;
		REP(i, N) if(w[i]>=N) {
			p=1;
			ll co = w[i]/N;
			w[i]-=co*N;
			REP(j, N) if(j!=i) {
				w[j]+=co;
			}
			K += co;
		}
		if(!p) break;
	}
	return K;
}

VI solve(ll K) {
	ll N = 50;
	VI w(N);
	REP(i, N) w[i] = 49+K/N;
	REP(i, K%N) {
		w[i] += N;
		REP(j, N) if(i!=j) w[j]--;
	}
	return w;
}

int main() {
	//ios::sync_with_stdio(false);
//	VI a(10000);
//	RANGE(k, 0, 100000) {
////		DD("kkkkk");
//		DD(k);
//		auto ans = solve(k);
////		DD(ans);
//		assert(k==naive2(ans));
////		a[v]=1;
////		DD(w);
////		DD(v);
//	}
////	DD(a);
//	return 0;

	ll K;
	while(cin>>K) {
		auto w = solve(K);
		cout<<w.size()<<endl;
		cout<<w<<endl;
	}

	return 0;
}