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

void solve(ll W, ll H, ll D) {
	string tb = "YRGB";
	VI dx, dy;
	RANGE(x, -D, D+1) {
		ll y = D-abs(x);
		dx.PB(x);
		dy.PB(y);
		if(abs(x)!=D) {
			dx.PB(x);
			dy.PB(-y);
		}
	}
//	DD(dx);DD(dy);
	VVI m(H, VI(W));
	VI X,Y;
	REP(su, W-1+H-1+1) {
		REP(x, W) {
			ll y = su-x;
			if(IN(y, 0, H)) {
				X.PB(x);
				Y.PB(y);
			}
		}
	}
	DD(X);DD(Y);
	assert(X.size()==W*H);
	REP(ii, H*W) {
		ll x = X[ii];
		ll y = Y[ii];

		VI hi(5);
		REP(di, dx.size()) {
			ll nx = x+dx[di];
			ll ny = y+dy[di];
			if(IN(nx, 0, W) && IN(ny, 0, H)) {
				hi[m[ny][nx]]++;
			}
		}
		DD(x);
		DD(y);
		DD(hi);
		RANGE(i, 1, 5) {
			if(hi[i]==0) {m[y][x] = i; break;}
		}
		if(m[y][x]==0) {
			DD(m);
//			REP(y, H) {
//				REP(x, W) {
//					cout<<tb[m[y][x]];
//				}
//				cout<<endl;
//			}
			assert(m[y][x]);
		}
	}
	REP(y, H) {
		REP(x, W) {
			cout<<tb[m[y][x]-1];
		}
		cout<<endl;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N = 30;
	RANGE(W, 2, N) RANGE(H, 2, N) RANGE(D, 1, H+W-2) {
		DD(W);DD(H);DD(D);
		solve(W, H, D);
	}
	return 0;

	ll W,H,D;
	while(cin>>H>>W>>D) {
		solve(W,H,D);
	}
	
	return 0;
}
