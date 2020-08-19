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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
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

modll naive(ll N, VI L, VI W, VI H) {
	ll h = *max_element(ALL(H));
	ll w = 0;
	REP(i, N) maxUpdate(w, L[i]+W[i]+1);
	vector<vector<bool>> m(h, vector<bool>(w));
	modll ans = 1LL;
//	cout<<" -------- naive "<<endl;
	REP(ni, N) {
		REP(x, W[ni]) REP(y, H[ni]) m[y][L[ni]+x]=1;

//		DD(ni);
//		string l(w, ' ');
//		REPR(y, h) {
//			REP(x, w) l[x] = m[y][x] ? '#' : ' ';
//			cout<<l<<endl;
//		}

		ll p=0;
		REP(y, h) REP(x, w) if(m[y][x]) {
			p+=4;
			if(0<=x-1 && m[y][x-1]) p-=2;
			if(0<=y-1 && m[y-1][x]) p-=2;
		}
		ans *= p;
		DD(p);
	}
//	DD(ans);
	return ans;
}

modll solve(ll N, VI& L, VI& W, VI& H) {
	modll ans = 1LL;
	// x -> (w, h)
	map<ll, PII> m;
//	cout<<" -------- solve "<<endl;
//	DD(L);
//	DD(W);
//	DD(H);
	modll lastP=0LL;
	auto prevH = [&](map<ll, PII>::iterator it) {
		ll l = it->FI;
		if(it==m.begin()) return 0LL;
		it--;
		if(it->FI+it->SE.FI==l) return it->SE.SE;
		return 0LL;
	};
	auto nextH = [&](map<ll, PII>::iterator it) {
		ll r = it->FI+it->SE.FI;
		it++;
		if(it==m.end()) return 0LL;
		if(it->FI==r) return it->SE.SE;
		return 0LL;
	};

	REP(ni, N) {
		// update
		ll l = L[ni];
		ll r = l + W[ni];
		ll h = H[ni];
		// [L, L+W] 内に既存の左端or右端があったらその分引く
		// L, L+W における既存高さを求める
		// 今回の輪郭を足す
		// 完全に含むものを削除, 交差してるやつのサイズを変更しつつ重複分をへらす
		// 見つかったxはl以上。
		auto it = m.lower_bound(L[ni]);
//		cout<<endl;
//		DD(ni);

		if(it!=m.begin()) it--;
		modll sub = 0LL;
		set<ll> seen;
		VI mrm;
		vector<pair<ll, PII>> madd;
		ll elh = 0LL, erh = 0LL;
		while(it->FI <= r) {
			ll el = it->FI;
			ll er = it->FI + it->SE.FI;
			ll eh = it->SE.SE;
//				DD(el);
			modll dupL=0LL, dupR=0LL;
			if(l <= el && el <= r && !seen.count(el)) {
				dupL = abs(eh - prevH(it));
				seen.insert(el);
			}
			if(l <= er && er <= r && !seen.count(er)) {
				dupR = abs(eh - nextH(it));
				seen.insert(er);
			}
			modll dupW = max(0LL, min(r, er) - max(l, el));
//				DD(dupL);
//				DD(dupR);
//				DD(dupW);
			sub += dupL + dupR + dupW*2LL;
			// すこしでも重複していたら一旦消す
			if(!(er<l || r<el)) mrm.PB(el);
			if(el<l) madd.PB(MP(el, MP(min(er, l)-el, eh)));
			if(r<er) madd.PB(MP(max(el, r), MP(er-max(el, r), eh)));
			it++;
		}
//		DD(mrm);
//		DD(madd);
		for(ll x: mrm) m.erase(x);
		for(auto e: madd) m[e.FI] = e.SE;
//		DD(m);

		{
			auto it = m.lower_bound(L[ni]);
			if(it!=m.begin()) it--;
			while(it->FI <= r) {
				ll el = it->FI;
				ll er = it->FI + it->SE.FI;
				ll eh = it->SE.SE;
//				DD(el);DD(er);
				if(el<=l && l<=er) maxUpdate(elh, eh);
				if(el<=r && r<=er) maxUpdate(erh, eh);
				it++;
			}
		}
//		DD(elh);
//		DD(erh);
		m[l] = MP(r-l, h);

		modll add = h-elh + h-erh + (r-l)*2;
//		DD(add);
//		DD(sub);
		modll p = lastP + add - sub;
//		DD(p);
		ans *= p;
		lastP = p;
//		DD(m);
	}
	return ans;
}

int test() {
	REP(loop, 10000) {
		ll N=10;
		VI L(N), W(N), H(N);
		REP(i, N) {
			L[i] = UNIFORM_LL(1, 10);
			W[i] = UNIFORM_LL(1, 10);
			H[i] = i==0 ? 1 : H[i-1] + UNIFORM_LL(0, 10);
		}
		modll nans = naive(N, L, W, H);
		modll ans = solve(N, L, W, H);
		DD(nans);
		DD(ans);
		if(nans!=ans) {
			DD("WA");
			return 1;
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
		ll N,K;
		ll AL, BL, CL, DL;
		ll AW, BW, CW, DW;
		ll AH, BH, CH, DH;
		cin>>N>>K;
		VI L(N), W(N), H(N);

		REP(i, K) cin>>L[i];
		cin>>AL>>BL>>CL>>DL;
		RANGE(i, K, N) L[i] = (AL*L[i-2]+BL*L[i-1]+CL)%DL+1;

		REP(i, K) cin>>W[i];
		cin>>AW>>BW>>CW>>DW;
		RANGE(i, K, N) W[i] = (AW*W[i-2]+BW*W[i-1]+CW)%DW+1;

		REP(i, K) cin>>H[i];
		cin>>AH>>BH>>CH>>DH;
		RANGE(i, K, N) H[i] = (AH*H[i-2]+BH*H[i-1]+CH)%DH+1;

//		DD(L);
//		DD(W);
//		DD(H);

		modll ans = solve(N, L, W, H);
//		modll nans = naive(N, L, W, H);
//		DD(nans);
//		DD(ans);
//		if(nans!=ans) {
//			DD("WA");
//			return 1;
//		}

		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		break;
	}
	
	return 0;
}
