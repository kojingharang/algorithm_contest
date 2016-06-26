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

struct modll {
	static const ll MODVAL;
	ll val;
	modll() : val(0) {}
	modll(ll v) { val = v; normalize(); }
	void normalize() { val = (val+MODVAL) % MODVAL; }
	modll  operator+ (ll v) { return modll(val+v); }
	modll& operator+=(ll v) { val+=v; normalize(); return *this; }
	modll  operator- (ll v) { return modll(val-v); }
	modll& operator-=(ll v) { val-=v; normalize(); return *this; }
	modll  operator* (ll v) { return modll(val*v); }
	modll& operator*=(ll v) { val*=v; normalize(); return *this; }
	modll  operator^ (ll e) { modll x(val); modll v(1); for(;e;x=x*x,e>>=1) if(e&1) v = v * x; return v; } // pow
	modll inv() { modll x(val); return x^(MODVAL-2); } // MODVAL must be prime number when use this!
	operator ll() { return val; }
};
const ll modll::MODVAL = 1000000007;

modll refdp[100][101];
modll dp[100][101];

int main() {
	//ios::sync_with_stdio(false);
	ll N,M,Q,k,x;
	string s;
	while(cin>>N>>M>>Q) {
		VI num(N);
		if(!(N<=100 && M<=100)) {
			cout<<"0"<<endl;
			continue;
		}
		REP(i, N) cin>>num[i];
		{
			ll k=-1;
			CLEAR(refdp, 0);
			for(int i=N-1;i>=0;i--) {
				REP(m, M+1) {
					if(i==N-1) {
						if(i==k && m!=x) continue;
						if(m <= num[i]) refdp[i][m] = 1;
					} else {
						REP(t, m+1) {
							if(i==k && t!=x) continue;
							if(t <= num[i] && m-t>=0) refdp[i][m] += refdp[i+1][m-t];
						}
					}
				}
			}
		}
//		cout<<"ref "<<endl;
//		PRINT2(refdp, N, M+1);
//		cout<<"eref "<<endl;
		REP(qi, Q) {
			cin>>k>>x;
			k--;
			CLEAR(dp, 0);
			RANGE(i, k+1, N)REP(j, M+1)dp[i][j]=refdp[i][j];
			for(int i=k;i>=0;i--) {
//			for(int i=N-1;i>=0;i--) {
				REP(m, M+1) {
					if(i==N-1) {
						if(i==k && m!=x) continue;
						if(m <= num[i]) dp[i][m] = 1;
					} else {
						REP(t, m+1) {
							if(i==k && t!=x) continue;
							if(t <= num[i] && m-t>=0) dp[i][m] += dp[i+1][m-t];
						}
					}
				}
			}
//			PRINT2(dp, N, M+1);
			cout<<dp[0][M]<<endl;
		}
	}
	
	return 0;
}
