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

bool solve3(ll N, ll A, ll B, ll C, ll D) {
	ll diff = abs(A-B);
	REP(i, N) {
		ll Min = C*i-D*(N-1-i);
		ll Max = D*i-C*(N-1-i);
		if(Min<=diff && diff<=Max) return true;
	}
	return false;
}

bool solve2(ll N, ll A, ll B, ll C, ll D) {
//	DD("solve2");
//	DD(C);
//	DD(D);
	if(C==D) {
		if(C==0) return A==B;

		ll Max = C*(N-1);
		if(abs(A-B) % C) return false;
		if(abs(A-B) > Max) return false;
		return (abs(A-B) / C)%2 == (N-1)%2;
	}

	ll a = C+D;
	ll b = 0;
	ll d = 0;
	REP(i, N-1) {
		b+=D-C;
		d+=D;
	}
	ll diff = abs(A-B);
//	DD(diff);
//	DD(d);
//	DD(C+D);
//	DD(b);
	if(a-b<=0) {
//		DD("fill");
		return diff<=d;
	} else {
		if(diff<=d) {
//			DD(d-diff);
//			DD((d-diff)%(C+D));
			if((d-diff)%(C+D)<=b) return true;
			else return false;
		} else {
			return false;
		}
	}

//	vector<PII> w;
//	w.PB({0, 0});
//	ll d = abs(A-B);
//	REP(i, N-1) {
//		vector<PII> nw;
//		auto add = [&](ll a, ll b) {
////			if(abs(a-d)>) return;
////			if(abs(b-d)>abs(A-B)) return;
//			REP(j, nw.size()) {
//				if(!(b<nw[j].first || nw[j].second<a)) {
//					nw[j].first = min(nw[j].first, a);
//					nw[j].second = max(nw[j].second, b);
//					return;
//				}
//			}
//			nw.PB(MP(a, b));
//		};
//		REP(j, w.size()) {
//			add(w[j].first+C, w[j].second+D);
//			add(w[j].first-D, w[j].second-C);
//		}
//		w = nw;
////		sort(ALL(w));
////		DD(w);
//	}
//	ll diff = B-A;
//	REP(i, w.size()) {
//		if(w[i].first<=diff && diff<=w[i].second) return true;
//	}
//	return false;
}
bool solve(ll N, ll A, ll B, ll C, ll D) {
	DD("solve");
	vector<PII> w;
	w.PB({0, 0});
	REP(i, N-1) {
		vector<PII> nw;
		auto add = [&](ll a, ll b) {
			REP(j, nw.size()) {
				if(!(b<nw[j].first || nw[j].second<a)) {
					nw[j].first = min(nw[j].first, a);
					nw[j].second = max(nw[j].second, b);
					return;
				}
			}
			nw.PB(MP(a, b));
		};
		REP(j, w.size()) {
			add(w[j].first+C, w[j].second+D);
			add(w[j].first-D, w[j].second-C);
		}
		w = nw;
		sort(ALL(w));
	}
//	DD(w);
	ll diff = B-A;
	REP(i, w.size()) {
		if(w[i].first<=diff && diff<=w[i].second) return true;
	}
	return false;
}

int main() {
	//ios::sync_with_stdio(false);
	if(0)
	{
		RANGE(N, 20, 24) RANGE(C, 0, 20) RANGE(D, C, 20) REP(A, 1) RANGE(B, 21, 100) {
			DD(N);
			DD(A);
			DD(B);
			DD(C);
			DD(D);
			bool ref = solve2(N, A, B, C, D);
			bool ans = solve3(N, A, B, C, D);
			DD(ref);
			DD(ans);
			assert(ref==ans);
		}
		return 0;
	}
	ll N,A,B,C,D;
	while(cin>>N>>A>>B>>C>>D) {
		bool ans = solve3(N, A, B, C, D);
		
		cout<<(ans?"YES":"NO")<<endl;
	}
	
	return 0;
}
