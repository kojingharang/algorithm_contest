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
#include <functional>
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

/*
197 / 17 = 11.58
198 / 18 = 11
199 / 19 = 10.47
200 / 2 = 100
*/
double f(ll v) {
	string s = to_string(v);
	ll rv=0;
	REP(i, s.size()) rv+=s[i]-'0';
	double r = (double)v / rv;
//	cout<<v<<" "<<rv<<" "<<r<<endl;
	return r;
}

void g(ll v) {
	REP(i, 1) {
		f(v+i);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll K;
	while(cin>>K) {
		VI p10(16, 1LL);
		RANGE(i, 1, p10.size()) p10[i]=p10[i-1]*10;

		VI w;
//		RANGE(i, 1, 10) w.PB(i);
//		RANGE(i, 1, 10) w.PB(i*10+9);
//		RANGE(i, 1, 10) w.PB(i*100+99);
		// h 9*nn
		RANGE(nn, 0, 16) {
			RANGE(h, 0, 1000) {
				ll base = p10[nn];
				ll v = h*base+base-1;
				if(v) w.PB(v);
			}
		}
		set<ll> ww(ALL(w));
		w = VI(ALL(ww));
//		DD(w);
		ll N = w.size();
		vector<double> v(N), Min(N);
		REP(i, N) {
			Min[i] = v[i] = f(w[i]);
		}
		for(int i=N-1;i>=0;i--) {
			if(i+1<N) Min[i] = min(Min[i], Min[i+1]);
		}
//		DD(Min);
		VI a;
		REP(i, N) {
			if(v[i] <= Min[i]) {
				a.PB(w[i]);
			}
		}
		REP(i, K) {
			cout<<a[i]<<endl;
		}
	}
	
	return 0;
}
