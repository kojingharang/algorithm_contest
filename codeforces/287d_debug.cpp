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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")

#define MOD 1000000007LL
#define INF (1LL<<60)

struct modll {
	static ll MODVAL;
	ll val;
	modll() : val(0) {}
	modll(ll v) : val(v) { normalize(); }
	void normalize() { val = (val+MODVAL) % MODVAL; }
	modll  operator+ (ll v) { return modll(val+v); }
	modll& operator+=(ll v) { val+=v; normalize(); return *this; }
	modll  operator- (ll v) { return modll(val-v); }
	modll& operator-=(ll v) { val-=v; normalize(); return *this; }
	modll  operator* (ll v) { return modll(val*v); }
	modll& operator*=(ll v) { val*=v; normalize(); return *this; }
	modll  operator^ (ll e) { modll x(val); modll v(1); for(;e;x=x*x,e>>=1) if(e&1) v = v * x; return v; } // pow
	modll inv() { modll x(val); return x^(MODVAL-2); } // MODVAL must be prime number when use this!
	static modll inv(ll v) { return modll(v).inv(); }
	operator ll() { return val; }
};
ll modll::MODVAL;

modll dp[2][2][101];
ll p10[10];

ll naive(ll N, ll K, ll M) {
	ll ans = 0;
	RANGE(i, pow(10, N-1), pow(10, N)) {
		ll div=10;
//		cout<<i<<endl;
		bool ok=false;
		while(div/10<=i) {
			ll v = i%div;
			if(v>=div/10) {
				if(v%K==0) ok=true;
//				cout<<"try "<<v<<endl;
			}
			div*=10;
		}
		if(ok) ans++;
	}
	return ans;
}

int main() {
	//ios::sync_with_stdio(false);
	ll N,K,M;
	while(cin>>N>>K>>M) {
		modll::MODVAL = M;
		CLEAR(dp, 0);
		CLEAR(p10, 0);
		int set=0;
		dp[set][0][0]=1;
		modll donelz;
//		REP(i, 10) {
//			int ndone = i!=0 && i%K==0;
//			dp[set][ndone][i%K]+=1;
//			if(i==0 && ndone) donelz+=1;
//		}
//		REP(done, 2) {
//			REP(k, K) cout<<dp[set][done][k]<<" ";
//			cout<<endl;
//		}
		REP(i, 10) p10[i] = i%K;
		REP(i, N) {
//			cout<<"p10 ";
//			REP(j, 10) cout<<p10[j]<<" ";
//			cout<<endl;
			
			donelz = 0;
			int nset = 1-set;
			CLEAR(dp[nset], 0);
			REP(done, 2) REP(k, K) REP(nd, 10) {
				ll nk = (p10[nd] + k) % K;
				int ndone = done || (nd!=0 && nk==0);
				if(nd==0 && ndone) donelz+=dp[set][done][k];
//				cout<<" kernel "<<done<<" "<<mk<<" "<<nd<<" -> modK "<<nmk<<endl;
				dp[nset][ndone][nk] += dp[set][done][k];
			}
//			cout<<"i "<<i<<endl;
//			REP(done, 2) {
//				REP(k, K) cout<<dp[nset][done][k]<<" ";
//				cout<<endl;
//			}
			modll all=0;
			REP(done, 2) {
				REP(k, K) all+=dp[nset][done][k];
			}
			modll refall=1;
			REP(j, i+1) refall*=10;
//			cout<<all<<" refall "<<refall<<endl;
			assert(all==refall);
//			cout<<"donelz "<<donelz<<endl;
			REP(i, 10) p10[i] = (p10[i]*10)%K;
			set = nset;
		}
		
		modll ans = -donelz;
		REP(k, K) ans+=dp[set][1][k];
		cout<<ans<<endl;
//		cout<<"naive "<<naive(N, K, M)<<endl;
//		break;
	}
	
	return 0;
}
/*
590
75594
*/
