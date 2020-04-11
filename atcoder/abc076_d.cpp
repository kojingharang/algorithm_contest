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

double ref(ll N, VI T, VI _V) {
	VI L(N+2), R(N+2), V(N+2);
	ll tot = 0;
	REP(i, N) {
		L[i] = tot;
		R[i] = tot+T[i];
		tot+=T[i];
	}
	REP(i, N) V[i] = _V[i];
	L[N+1] = R[N+1] = tot;
//	DD(L);DD(R);DD(V);

	auto f = [&](int i, double t) {
		if(L[i]<=t && t<=R[i]) return (double)V[i];
		return V[i]+min(abs(t-L[i]), abs(t-R[i]));
	};
	auto ff = [&](double t) {
		double v = 1e100;
		REP(i, L.size()) v = min(v, f(i, t));
		return v;
	};
//	REP(i, N+2) DD(f(i, 35));

	vector<double> w(tot*2+1);
	REP(i, w.size()) {
		double t = (double)i/2.0;
		w[i] = ff(t);
	}
//	DD(w);
//	REP(i, w.size()) {
//		cout<<i*0.5<<" "<<w[i]<<endl;
//	}
	double ans = 0;
	REP(i, w.size()-1) {
		ans += (w[i]+w[i+1])*0.5/2;
	}
	return ans;
}

double ref2(ll N, VI _T, VI _V) {
	VI L(N+2), R(N+2), V(N+2);
	ll tot = 0;
	REP(i, N) {
		L[i+1] = tot;
		R[i+1] = tot+_T[i];
		V[i+1] = _V[i];
		tot += _T[i];
	}
	L[N+1] = R[N+1] = tot;
//	DD(L);DD(R);DD(V);

	vector<double> limit(L.size()); // [i] ... i が始まる時の最大速度
	auto f = [&](int i) {
		double v = 1e100;
		RANGE(j, i, L.size()) {
			double lv = L[j] - L[i] + V[j];
			v = min(v, lv);
		}
		return v;
	};
	REP(i, L.size()) limit[i] = f(i);
//	DD(limit);

	double pv = 0;
	double ans = 0;
	RANGE(i, 1, L.size()-1) {
		// / - \
		// a   b
		double nv = limit[i+1];
		double l = R[i]-L[i];
		double a = (nv-pv+l)/2.0;
		double b = a;
//		DD(i);
//		DD(pv);
//		DD(nv);
//		DD(L[i]);
//		DD(V[i]);
//		DD(l);
//		DD(a);DD(b);
		a = min({a, V[i]-pv, l});
		a = max(0.0, a);
		b = max(b, nv+l-V[i]);
		b = min(l, b);
//		DD(a);DD(b);
		double lans = (pv+pv+a)*a*0.5 + V[i]*(b-a) + (nv+(l-b)+nv)*(l-b)*0.5;
		ans += lans;
		pv = pv+a-(l-b);
	}
	return ans;
}

double ref3(ll N, VI T, VI V) {
	vector<double> L(N), R(N);
	RANGE(i, 1, N) L[i] = min({L[i-1]+T[i-1], V[i-1]+0.0, V[i]+0.0});
	for(int i=N-2;i>=0;i--) R[i] = min({R[i+1]+T[i+1], V[i+1]+0.0, V[i]+0.0});
	REP(i, N) {
		L[i] = min(L[i], R[i]+T[i]);
		R[i] = min(R[i], L[i]+T[i]);
	}
	double ans = 0;
	REP(i, N) {
		double y = min((R[i]+L[i]+T[i])*0.5, (double)V[i]);
		ans += T[i]*y - (y-L[i])*(y-L[i])*0.5 - (y-R[i])*(y-R[i])*0.5;
	}
	return ans;
}

double ref4(ll N, VI T, VI V) {
	ll tot = accumulate(ALL(T), 0LL);
	vector<double> vs(tot*2+1, 1e100);
	tot = 0;
	REP(i, N) {
		RANGE(ti, tot*2, (tot+T[i])*2+1) vs[ti] = min<double>(vs[ti], V[i]);
		tot += T[i];
	}
	vs[0] = vs[tot*2] = 0;
	RANGE(i, 1, tot*2+1) vs[i] = min(vs[i], vs[i-1]+0.5);
	for(int i=tot*2-1;i>=0;i--) vs[i] = min(vs[i], vs[i+1]+0.5);
//	DD(vs);
	double ans = 0;
	REP(i, tot*2) {
		ans += (vs[i]+vs[i+1])*0.25;
	}
	return ans;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	if(0)
	REP(loop, 1000) {
		ll N = 100;
		VI T(N), V(N);
		REP(i, N) T[i] = UNIFORM_LL(1, 100);
		REP(i, N) V[i] = UNIFORM_LL(1, 100);
		double ans = ref(N, T, V);
		double ans2 = ref2(N, T, V);
		double ans3 = ref3(N, T, V);
		double ans4 = ref4(N, T, V);
		DD(N);
		DD(T);
		DD(V);
		DD(ans);DD(ans2);DD(ans3);DD(ans4);
		assert(ans==ans2 && ans2==ans3 && ans2==ans4);
	}
	
	ll N;
	while(cin>>N) {
		VI T(N), V(N);
		REP(i, N) cin>>T[i];
		REP(i, N) cin>>V[i];
		double ans = ref(N, T, V);
//		double ans2 = ref2(N, T, V);
//		double ans3 = ref3(N, T, V);
		double ans4 = ref4(N, T, V);
//		DD(ans3);DD(ans4);
//		assert(ans==ans2);
//		assert(ans3==ans4);
		printf("%.20f\n", ans4);
//		break;
	}
	
	return 0;
}
