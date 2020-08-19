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
#define VVVI vector<vector<vector<ll>>>
#define VVVVI vector<vector<vector<vector<ll>>>>
#define REP(i,n) for(ll i=0,_n=(n);(i)<(ll)_n;++i)
#define REPR(i,n) for(ll i=(ll)(n)-1;0<=(i);--i)
#define RANGE(i,a,b) for(ll i=(ll)a,_b=(ll)(b);(i)<_b;++i)
#define RANGER(i,a,b) for(ll i=(ll)(b)-1,_a=(ll)(a);(_a)<=i;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
#define FI first
#define SE second
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}

#define MOD 1000000007LL
#define INF (1LL<<60)

/*
increase stack size!!!!!!
// 16MB
g++ -O2 -Wl,-stack_size,10000000 -std=c++11 -Wall d.cpp && ./a.out < corporate_gifting.txt > do2.txt
*/

template<ll MODVAL>
struct Modll {
	ll val;
	Modll() : val(0) {}
	Modll(ll v) : val(v) { normalize(); }
	void normalize() { val = (val+MODVAL) % MODVAL; }
	Modll  operator+ (ll v) { return Modll(val+v); }
	Modll& operator+=(ll v) { val+=v; normalize(); return *this; }
	Modll  operator- (ll v) { return Modll(val-v); }
	Modll& operator-=(ll v) { val-=v; normalize(); return *this; }
	Modll  operator* (ll v) { return Modll(val*v); }
	Modll& operator*=(ll v) { val*=v; normalize(); return *this; }
	Modll  operator^ (ll e) { Modll x(val); Modll v(1); for(;e;x=x*x,e>>=1) if(e&1) v = v * x; return v; } // pow
	Modll inv() { Modll x(val); return x^(MODVAL-2); } // MODVAL must be prime number when use this!
	static Modll inv(ll v) { return Modll(v).inv(); }
	operator ll() { return val; }
};
template<ll MODVAL>
std::ostream& operator<<(std::ostream& os, const Modll<MODVAL>& v) { os << v.val; return os; }
using modll = Modll<1000000007>;

modll naive(ll N, ll W, VI L, VI H) {
	ll h = *max_element(ALL(H));
	ll w = L[N-1]+W+1;
	vector<vector<bool>> m(h, vector<bool>(w));
	modll ans = 1LL;
	REP(ni, N) {
		REP(x, W) REP(y, H[ni]) m[y][L[ni]+x]=1;
//		string l(w, ' ');
		DD(ni);
//		REPR(y, h) {
//			REP(x, w) l[x] = m[y][x] ? '#' : ' ';
//			cout<<l<<endl;
//		}
		ll co=0;
		REP(y, h) REP(x, w) if(m[y][x]) {
			co+=4;
			if(0<=x-1 && m[y][x-1]) co-=2;
			if(0<=y-1 && m[y-1][x]) co-=2;
		}
		ans *= co;
	}
	DD(ans);
	return ans;
}

modll solve(ll N, ll W, VI L, VI H) {
	// height
	deque<ll> q(W+1);
	modll ans = 1LL;
	modll fixed=0LL;
	REP(i, N) {
		// shift
		ll sc = min(W+1, L[i] - (0<=i-1 ? L[i-1] : L[i]));
		REP(si, sc) {
			ll add = abs(q[1]-q[0]) + (0 < q[1] ? 2 : 0);
			fixed += add;
			q.pop_front();
			q.push_back(0);
		}
		// fill
		RANGE(qi, 1, q.size()) {
			maxUpdate(q[qi], H[i]);
		}
		modll fl = 0;
		RANGE(qi, 1, q.size()) {
			fl += abs(q[qi]-q[qi-1]) + (0 < q[qi] ? 2 : 0);
		}
		fl += q[q.size()-1];
		modll p = fixed + fl;
		ans *= p;
//		DD(p);
//		DD(fixed);
//		DD(fl);
//		DD(sc);
	}
	return ans;
}

int test() {
	REP(loop, 10000) {
		ll N=10, W=3;
		VI L(N), H(N);
		REP(i, N) {
			L[i] = 0<=i-1 ? L[i-1] + UNIFORM_LL(1, 10) : 1;
			H[i] = UNIFORM_LL(1, 10);
		}
		modll nans = naive(N, W, L, H);
		modll ans = solve(N, W, L, H);
		DD(nans);
		DD(ans);
		if(nans!=ans) {
			DD("WA");
			assert(false);
		}
	}
	return 0;
}

int main() {
	//ios::sync_with_stdio(false);
//	return test();

	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		ll N,K,W;
		ll AL, BL, CL, DL;
		ll AH, BH, CH, DH;
		cin>>N>>K>>W;
		VI L(N), H(N);
		REP(i, K) cin>>L[i];
		cin>>AL>>BL>>CL>>DL;
		RANGE(i, K, N) L[i] = (AL*L[i-2]+BL*L[i-1]+CL)%DL+1;
		REP(i, K) cin>>H[i];
		cin>>AH>>BH>>CH>>DH;
		RANGE(i, K, N) H[i] = (AH*H[i-2]+BH*H[i-1]+CH)%DH+1;
//		DD(L);
//		DD(H);
		modll ans = solve(N, W, L, H);
//		modll nans = naive(N, W, L, H);
//		DD(nans);
//		DD(ans);
//		if(nans!=ans) {
//			DD("WA");
//			return 1;
//		}
		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		if(CaseID==1) break;
	}
	
	return 0;
}
