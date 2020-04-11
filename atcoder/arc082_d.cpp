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

struct M {
	ll ah, ch, al, cl;
};
ostream& operator<<(ostream& os, const M& m) {
	os<<m.ah<<" "<<m.ch<<" "<<m.al<<" "<<m.cl<<endl;
	return os;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll X,K,Q;
	while(cin>>X>>K) {
		VI r(K+2);
		REP(i, K) cin>>r[i+1];
		r[K+1] = 1LL<<60;
		vector<M> ms;
		ms.push_back(M{X, X, 0, 0});
		RANGE(i, 1, K+2) {
			ll sign = (i-1)%2==0 ? -1 : 1;
			M& p = ms[i-1];
			M m;
			ll nh = p.ch + sign * (r[i]-r[i-1]);
			ll nl = p.cl + sign * (r[i]-r[i-1]);
			m.ch = min(max(nh, 0LL), X);
			m.cl = min(max(nl, 0LL), X);
			m.ah = p.ah;
//			DD(nh);
			if(nh>X) m.ah -= nh-X;
			if(nh<0) m.ah += -nh;
			m.al = p.al;
			if(nl>X) m.al -= nl-X;
			if(nl<0) m.al += -nl;
			ms.push_back(m);
		}
//		DD(ms);
		cin>>Q;
		REP(qi, Q) {
			ll T, A;
			cin>>T>>A;
			ll i = max<ll>(1, distance(r.begin(), lower_bound(ALL(r), T)));
//			DD(i);
//			RANGE(i, 1, K+2) {
//				if(T <= r[i]) {
					// between i-1 and i
//					DD(i);
					ll sign = (i-1)%2==0 ? -1 : 1;
//					DD(sign);
//					DD(T-r[i-1]);
//					DD(ms[i-1].ah-A);
//					DD(max(ms[i-1].ch - max(ms[i-1].ah-A, ms[i-1].al), 0LL));
					ll v = ms[i-1].ch - (ms[i-1].ah - min(max(A, ms[i-1].al), ms[i-1].ah)) + sign * (T-r[i-1]);
					v = max(min(v, X), 0LL);
					cout<<v<<endl;
//					break;
//				}
//			}
		}
	}
	
	return 0;
}
