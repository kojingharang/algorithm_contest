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

void naive(ll N, const VI& w, ll& minVar, ll& ans) {
	auto f = [&](int ci) {
		ll v = 0;
		REP(i, N) {
			int ni = (i+ci+N)%N+1;
//			DD(ni);
			v += abs(ni-w[i]);
		}
//		DD(v);
		return v;
	};
	minVar = 1LL<<60;
	REP(ci, N) {
		ll v = f(ci);
//		DD(v);
		if(v < minVar) {
			minVar = v;
			ans = ci;
		}
	}
}

void solve(ll N, const VI& ww, ll& minVar, ll& ans) {
	VI w(ww);
	REP(i, N) w[i]--;
	VI A(N*2), B(N*2);
	// add ax+b to [l, r]
	auto add = [&](int l, int r, int a, int b) {
//		if(l>r) return;
//		cout<<"ADD "<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
		A[l] += a;
		A[r+1] -= a;
		B[l] += b;
		B[r+1] -= b;
	};
	REP(i, N) {
		ll c = w[i];
		if(c<=i) {
			// 0 . c . i . N-1
			// x in [0, N-1-i] -> +x+i-c
			add(0, N-1-i, 1, i-c);
			// x in [N-i, c+N-i] -> +c-(x+i-N) = -x -i+N+c
			add(N-i, c+N-i-1, -1, -i+N+c);
			// x in [c+N-i+1, N-1] -> x+i-N-c = x +i-N-c
			add(c+N-i, N-1, 1, i-N-c);
		} else {
			// 0 . i . c . N-1
			// x in [0, c-i] -> +c-(x+i) = -x-i+c
			add(0, c-i, -1, -i+c);
			// x in [c-i+1, N-1-i] -> +x+i-c
			add(c-i+1, N-1-i, 1, i-c);
			// x in [N-i, N-1] -> c-(x+i-N) = -x +c-i+N
			add(N-i, N-1, -1, c-i+N);
		}
//		DD(A);
//		DD(B);
	}
	minVar = 1LL<<60, ans = 0;
	ll a=0, b=0, nv=0;
	REP(i, N) {
		a += A[i];
		b += B[i];
		nv = a * i + b;
//		DD(nv);
		if(nv<minVar) minVar=nv, ans=i;
	}
}


int main() {
	if(0)
	{
		int N = 10;
		VI w(N);
		ll ans, minVar;
		ll ans2, minVar2;
		REP(i, N) w[i]=i+1;
		do {
			solve(N, w, minVar, ans);
			naive(N, w, minVar2, ans2);
			DD(w);
			DD(minVar);
			DD(ans);
			DD(minVar2);
			DD(ans2);
			assert(minVar==minVar2);
			assert(ans==ans2);
		} while(next_permutation(ALL(w)));
		return 0;
	}

	ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
		VI w(N);
		REP(i, N) cin>>w[i];
		ll minVar, ans;
//		naive(N, w, minVar, ans);
		solve(N, w, minVar, ans);
		cout<<minVar<<" "<<ans<<endl;

//		naive(N, w, minVar, ans);
//		cout<<"NAIVE "<<minVar<<" "<<ans<<endl;
	}

	return 0;
}
