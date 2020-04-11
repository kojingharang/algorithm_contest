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
/*
increase stack size!!!!!!
// 16MB
g++ -O2 -Wl,-stack_size,10000000 -std=c++11 -Wall d.cpp && ./a.out < corporate_gifting.txt > do2.txt
*/

template<typename T>
struct BIT {
	vector<T> w;
	BIT(int N) { w = vector<T>(N); }
	// sum of w[i], i in [l, r]
	T sum(int l, int r) {
		if(l==0) {
			T s=0;
			for(;r>=0;r=(r&(r+1))-1) s+=w[r];
			return s;
		}
		return sum(0, r) - sum(0, l-1);
	}
	// i in [0, N)
	void add(int i, T v) {
		for(;i<(int)w.size();i|=i+1) w[i] += v;
	}
};

ll N, X1, XA, XB, XC, H1, HA, HB, HC;
VI X, H;

double naive() {
	double ans = 0;
	ll ZERO = HC*2;
	auto INDEX = [=](ll x) {
		return x*2+ZERO;
	};
	auto toX = [=](ll index) {
		return (index-ZERO)/2.0;
	};
	vector<double> hi((XC+HC*2)*2); // step 0.5. x of [ZERO]=0
	BIT<double> bit((XC+HC*2)*2);
	RANGE(i, 1, N+1) {
		REP(j, i) {
			ll sx = X[j]-H[j];
			ll ex = X[j]+H[j];
			RANGE(k, INDEX(sx), INDEX(ex)+1) {
				double nh = H[j]-fabs(X[j]-toX(k));
				if(hi[k] < nh) {
					bit.add(k, nh-hi[k]);
				}
				hi[k] = max(hi[k], nh);
			}
		}
//			DD(hi);
		double lans = 0;
//			RANGE(i, 1, hi.size()) {
//				lans += (hi[i]+hi[i-1])*0.5*0.5;
//			}
//			lans = accumulate(ALL(hi), 0.0)*0.5;
		lans = bit.sum(0, hi.size()-1)*0.5;
		DD(lans);
		ans += lans;
	}
	return ans;
}

set<PII> w;

// 柱 L〜R がなす面積
double get_area(PII L, PII R) {
	double HL = L.second;
	double HR = R.second;
	double D = R.first - L.first;
	if(D > HL + HR) return (HL*HL+HR*HR)/2.0; // 重複なし
	// HL-cx = HR-(D-cx)
	// HL-HR+D = 2cx

	// _cx = cx + XL
	// HL-(_cx-XL) = HR-(XR-_cx)  XR-cx-XL
	// HL-_cx+XL = HR-XR+_cx
	// (HL-HR+XL+XR)/2 = _cx
	double cx = (HL - HR + D) / 2.0;
	double ans = 0.0;
	ans += (HL + HL-cx) * cx / 2.0;
	ans += (HR + HL-cx) * (D-cx) / 2.0;
	return ans;
}

double get_diff(PII P) {
	auto iter = w.find(P);
	iter--;
	auto L = *iter;
	iter++;
	iter++;
	auto R = *iter;
	return get_area(L, P) + get_area(P, R) - get_area(L, R);
}

// return delta area
double query(ll x, ll h) {
	double ans = 0.0;
	while(1) {
		auto iter = w.lower_bound(MP(x, h));
		auto R = *iter;
		iter--;
		auto L = *iter;
		if(h <= L.second-(x-L.first)) return 0.0;
		if(h <= R.second-(R.first-x)) return 0.0;
		if(R.second <= h - (R.first-x)) {
			ans -= get_diff(R);
			w.erase(R);
			continue;
		}
		if(L.second <= h - (x-L.first)) {
			ans -= get_diff(L);
			w.erase(L);
			continue;
		}
		auto M = MP(x, h);
		w.insert(M);
		ans += get_area(L, M) + get_area(M, R) - get_area(L, R);
		return ans;
	}
}

double solve() {
	w.clear();
	ll INF=1LL<<60;
	w.insert(MP(-INF, 0));
	w.insert(MP(INF, 0));
	double lans = 0;
	double ans = 0;
	REP(i, N) {
		lans += query(X[i], H[i]);
		ans += lans;
	}
	return ans;
}

int main() {
	//ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		cin>>N>>X1>>XA>>XB>>XC>>H1>>HA>>HB>>HC;
		X = VI(N);
		H = VI(N);
		X[0] = X1;
		H[0] = H1;
		RANGE(i, 1, N) {
			X[i] = (XA*X[i-1]+XB)%XC+1;
			H[i] = (HA*H[i-1]+HB)%HC+1;
		}
//		DD(X);
//		DD(H);
//		double ans = naive();
		double ans = solve();
		printf("Case #%d: %.9f\n", CaseID+1, ans);
//		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		break;
	}
	
	return 0;
}
