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

pair<double, double> f(ll a0, ll b0, ll c0, ll a1, ll b1, ll c1) {
	double y = (double)(c0*a1-c1*a0) / (b0*a1-b1*a0);
	double x = (-b0*y+c0)/a0;
	return MP(x, y);
}

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

template<typename T>
ll inversion_number(const vector<T>& d) {
	ll N = d.size();
	BIT<T> bit(N);
	ll cnt = 0;
	for(int i=N-1;i>=0;i--) {
		cnt += bit.sum(0, d[i]);
		bit.add(d[i], 1);
	}
	return cnt;
}

template<typename T>
ll inversion_number_naive(const vector<T>& d) {
	ll N = d.size();
	ll cnt = 0;
	REP(i, N) RANGE(j, i+1, N) if(d[i]>d[j]) cnt++;
	return cnt;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
		VI A(N), B(N), C(N);
		REP(i, N) cin>>A[i]>>B[i]>>C[i];
//		vector<double> xs, ys;
//		REP(i, N) RANGE(j, i+1, N) {
//			auto p = f(A[i], B[i], C[i], A[j], B[j], C[j]);
//			xs.PB(p.first);
//			ys.PB(p.second);
//		}
		ll M = N*(N-1)/2;
//		DD(M);
		double ansx=0, ansy=0;
		// lo: NG hi: OK
		REP(xy, 2) {
			double lo = -1e10, hi = 1e10;
			REP(loop, 100) {
				double X = (lo+hi)/2;
//				DD(X);
				vector<double> ys;
				vector<double> ks;
				REP(i, N) {
					// Ax + By = C
					// y = -A/Bx + C/B
					double y = (double)(-A[i]*X + C[i])/B[i];
					ys.PB(y);
					double k = (double)-A[i]/B[i];
					ks.PB(k);
				}
//				DD(ys);
//				DD(ks);
				// (Y, idx)[]
				vector<pair<double, ll>> Ys(N);
				REP(i, N) Ys[i] = MP(ys[i], i);
				sort(ALL(Ys));
				// (idx, Yrank)[]
				vector<PII> Ys2(N);
				REP(i, N) Ys2[i] = MP(Ys[i].second, i);
				sort(ALL(Ys2));
				// (K, idx)[]
				vector<pair<double, ll>> Ks(N);
				REP(i, N) Ks[i] = MP(ks[i], i);
				sort(ALLR(Ks));
				VI t(N);
				REP(i, N) t[i] = Ys2[Ks[i].second].second;
//				DD(Ys);
//				DD(Ys2);
//				DD(Ks);
//				DD(t);
				ll sc = inversion_number(t);
//				ll scN = inversion_number_naive(t);
//				DD(sc);DD(scN);
//				assert(sc==scN);
				// p.x <= X なやつの個数
//				ll sc_ = 0;
//				REP(i, N) RANGE(j, i+1, N) if(ys[i]>=ys[j] ^ ks[i] < ks[j]) sc_++;
//				DD(sc);
//				DD(sc_);
//				assert(sc==sc_);
//				DD(M-sc);
				if(sc >= (M+1)/2) hi = X; else lo = X;
			}
			if(xy==0) ansx = hi;
			if(xy==1) ansy = hi;
			REP(i, N) swap(A[i], B[i]);
		}
		cout<<fixed<<setprecision(12)<<ansx<<" "<<ansy<<endl;
//		DD(xs);
//		DD(ys);
//		sort(ALL(xs));
//		sort(ALL(ys));
//		DD(xs);
//		DD(ys);
//		ll mid = (xs.size()-1)/2;
//		DD(xs.size());
//		DD(mid);
//		cout<<fixed<<setprecision(12)<<xs[mid]<<" "<<ys[mid]<<endl;
//		break;
	}
	
	return 0;
}
