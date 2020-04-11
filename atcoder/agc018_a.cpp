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

bool naive(const VI& w, ll K) {
	VI t(w);
	sort(ALL(t));
	DD(t);
	while(1) {
		bool upd = false;
		int N = t.size();
		set<ll> s(ALL(t));
		REP(i, N) RANGE(j, i+1, N) {
			s.insert(abs(t[i]-t[j]));
		}
		VI nt(ALL(s));
		if(t.size()<nt.size()) upd=true;
		t = nt;
		if(!upd) break;
	}
	DD(t);
	set<ll> s(ALL(t));
	if(s.count(K)) return true;
	return false;
}

bool solve(const VI& ww, ll K) {
	VI w(ww);
	int N = w.size();
	sort(ALL(w));
	if(w.back()<K) return false;
	if(w.front()==1) return true;
	ll g = w[0];
	REP(i, N) {
		g = __gcd(g, w[i]);
	}
//	DD(g);
	if((w.back()-K)%g==0) return true;
	return false;
}


int main() {
	//ios::sync_with_stdio(false);
	if(0)
	REP(i, 10000) {
		ll N = UNIFORM_LL(1, 100);
		ll K = UNIFORM_LL(1, 100);
		VI w(N);
		REP(i, N) w[i] = UNIFORM_LL(1, 100);
		sort(ALL(w));
		bool ref = naive(w, K);
		bool ans = solve(w, K);
		DD(N);
		DD(K);
		DD(w);
		DD(ref);
		DD(ans);
		assert(ref==ans);
	}
	ll N, K;
	while(cin>>N>>K) {
		VI w(N);
		REP(i, N) cin>>w[i];
//		bool ref = naive(w, K);
		bool ans = solve(w, K);
//		DD(ref);
//		DD(ans);
		
		cout<<(ans?"POSSIBLE":"IMPOSSIBLE")<<endl;
	}
	
	return 0;
}
