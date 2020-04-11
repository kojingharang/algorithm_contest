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
1 2
3 4

0
	1 0
	1 0
	a1=1
	b1=1
	a1u1=0
	b1u1=1
	c=2
	u=1
1
	0 1
	1 0
	c=2
	u=1
	ほんとはu=2
		a0u0*b0u0
		a0u0*b0u1
		a0u0*b1u0
		a0u0*b1u1
		a0u1*b0u0
		a0u1*b0u1
		a0u1*b1u0
		a0u1*b1u1
		b1u1 * (a1-a1u1) + (b1-b1u1) * a1u1
2
	0 0
	0 1
	c=2
	u=0

001
010
011
100

4 5 5 6
100
101
101
110

*/
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,M,W,H;
	string s;
	while(cin>>N) {
		vector<int> a(N), b(N);
		REP(i, N) cin>>a[i];
		REP(i, N) cin>>b[i];
		ll u = 0;
		ll ans = 0;
		REP(bi, 30) {
			VI ca(4), cb(4);
			REP(i, N) {
				int p = 0;
				if(a[i]>>bi&1) p |= 1;
				if(bi && a[i]>>(bi-1)&1) p |= 2;
				ca[p]++;

				p = 0;
				if(b[i]>>bi&1) p |= 1;
				if(bi && b[i]>>(bi-1)&1) p |= 2;
				cb[p]++;
			}
//			DD(ca);
//			DD(cb);
//			ll a1 = ca[1]+ca[3];
//			ll b1 = cb[1]+cb[3];
//			DD(a1);
//			DD(b1);
//			DD(co);
			u = 0;
			ll co = 0;
//			 = a1 * (N-b1) + b1 * (N-a1) + u;
			REP(pa, 4) REP(pb, 4) {
				int z = (pa&1) + (pb&1) + (pa&2 && pb&2);
//				if(z==2) u += ca[pa]*cb[pb];
				if(z&1) co += ca[pa]*cb[pb];
			}
			ans |= ((co)&1) << bi;
//			DD(u);
		}
		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}
