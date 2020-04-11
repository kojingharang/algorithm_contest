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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int test_cases;
	cin>>test_cases;
	ll N,M,W,H;
	string s;
	REP(ttt, test_cases) {
		cin>>N;
		vector<PII> w(N);
		REP(i, N) cin>>w[i].FI>>w[i].SE;
		ll ans = 0;
		ll A, B;
		PII anss = MP(100000, 100000);
		{
//			cout<<"TRY"<<endl;
//			DD(w);
			ll ok = 1;
			vector<vector<PII>> kbs(2);
			REP(i, N) RANGE(j, i+1, N) {
				ll a = w[j].FI-w[i].FI;
				ll b = w[j].SE-w[i].SE;
				// aA + bB should be > 0
//				cout<<a<<" "<<b<<endl;
				if(a<=0&&b<=0) ok = 0;
				/*
				A >|< xB
				*/
				if(a==0 || b==0) continue;
				ll gt = 0<a;
				long double kb = -b / (long double)a;
				if(a<0) {
					a*=-1;
					b*=-1;
				}
				kbs[gt].PB(MP(-b, a));
			}
//			DD(kbs[1]);
//			DD(kbs[0]);
			ll lok = ok;
			if(kbs[0].size() && kbs[1].size()) {
				for(auto l : kbs[1]) for(auto r : kbs[0]) {
					// la/lb >= ra/rb
					// la*rb >= ra*lb
					if(l.FI*r.SE >= r.FI*l.SE) ok=0;
//					DD(l.FI*r.SE);DD(r.FI*l.SE);
				}
			}
			if(ok) ans++;
			if(ok) {
				RANGE(kA, 1, 1001) RANGE(kB, 1, 1001) {
					ll ok = 1;
					for(auto l : kbs[1]) {
						if(l.FI*kB >= kA*l.SE) ok=0;
					}
					for(auto r : kbs[0]) {
						if(kA*r.SE >= r.FI*kB) ok=0;
					}
					if(ok) {
						minUpdate(anss, MP(kA, kB));
					}
				}
			}
//			DD(ok);
		}
		if(ans) {
			cout<<"Case #"<<ttt+1<<": "<<anss.FI<<" "<<anss.SE<<endl;
		} else {
			cout<<"Case #"<<ttt+1<<": "<<"IMPOSSIBLE"<<endl;
		}
//		return 0;
	}
	return 0;
}



