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

/*

1 1 1 1 1
1 1 1 1 1
1 -6 1 -6 1

15-2-12=1

*/
#define MOD 1000000007LL
#define INF (1LL<<60)

VVI solve(ll H, ll W, ll h, ll w) {
//	if(W%w==0&&H%h==0) return VVI();
//	VVI m(H, VI(W));
//	REP(y, H) REP(x, W) m[y][x] = x%w==w-1&&y%h==h-1 ? -1000*(h*w-1)-1 : 1000;
//	return m;

	ll p = 1000;
	ll nx = W/w, ny = H/h;
	ll hi = -p*(h*w-1)-1;
//	DD(nx);DD(ny);
	bool ok = (H*W-nx*ny)*p + hi*nx*ny > 0;
//	bool tok;
//	{
//		ll p = 1;
//		ll hi = -p*(h*w-1)-1;
//	//	DD(nx);DD(ny);
//		tok = (H*W-nx*ny)*p + hi*nx*ny > 0;
//	}
	if(ok) {
		VVI m(H, VI(W, p));
		REP(y, ny) REP(x, nx) m[h-1+h*y][w-1+w*x] = hi;
//		DD(m);
//		assert(ok==tok);
		return m;
	} else {
//		assert(ok==tok);
		return VVI();
	}
}


void check(ll H, ll W, ll h, ll w, VVI& m) {
	if(m.size()==0) return;
	ll SUM = 0;
	REP(y, H) REP(x, W) SUM+=m[y][x];
	assert(SUM>0);
	REP(y, H-h+1) REP(x, W-w+1) {
		ll sum = 0;
		REP(yy, h) REP(xx, w) sum+=m[y+yy][x+xx];
		assert(sum<0);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	ll H,W,h,w;

	if(0)
	{
		RANGE(H, 1, 30) RANGE(W, 1, 30) RANGE(h, 1, H+1) RANGE(w, 1, W+1) {
			VVI m = solve(H, W, h, w);
			if(m.size()) {
				cout<<"Yes"<<endl;
				REP(y, H) {
					REP(x, W) cout<<m[y][x]<<" ";
					cout<<endl;
				}
			} else {
				cout<<"No"<<endl;
			}
			check(H, W, h, w, m);
		}
		return 0;
	}

	while(cin>>H>>W>>h>>w) {
		VVI m = solve(H, W, h, w);
		if(m.size()) {
			cout<<"Yes"<<endl;
			REP(y, H) {
				REP(x, W) cout<<m[y][x]<<" ";
				cout<<endl;
			}
		} else {
			cout<<"No"<<endl;
		}
//		check(H, W, h, w, m);
	}
	
	return 0;
}
