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

const ll L2 = 201;
const ll L3 = 101;
const ll L5 = 101;
double dp[2][L2][L3][L5];


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,D;
	while(cin>>N>>D) {
		VI ps = {2,3,5};
		VI fa(ps.size());
		REP(i, ps.size()) while(D % ps[i]==0) fa[i]++, D/=ps[i];
		VVI tb = {
			{0,0,0},
			{1,0,0},
			{0,1,0},
			{2,0,0},
			{0,0,1},
			{1,1,0},
		};
		double ans = 0;
		if(D==1) {
			CLEAR(dp, 0);
			dp[0][0][0][0] = 1;
			ll m = 1;
			REP(i, N) {
				REP(i2, L2) REP(i3, L3) REP(i5, L5) dp[m][i2][i3][i5]=0;
				REP(i2, L2) REP(i3, L3) REP(i5, L5) if(dp[1-m][i2][i3][i5]>0.0) {
					REP(ti, tb.size()) {
						ll ni2 = i2 + tb[ti][0];
						ll ni3 = i3 + tb[ti][1];
						ll ni5 = i5 + tb[ti][2];
						if(ni2<L2 && ni3<L3 && ni5<L5) dp[m][ni2][ni3][ni5] += dp[1-m][i2][i3][i5] / 6.0;
					}
				}
				m ^= 1;
			}
			RANGE(i2, fa[0], L2) RANGE(i3, fa[1], L3) RANGE(i5, fa[2], L5) {
				ans += dp[1-m][i2][i3][i5];
			}
		}
		cout<<setprecision(20)<<ans<<endl;
	}
	
	return 0;
}
