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

/*
連結成分 (x, y)[]
それぞれに対して矩形内かどうかを合計したもの
矩形に対してそれに入る連結成分をどうインデックス化しておけば O(NlogN) 程度でリストアップできるか？

x, yまでの連結成分の個数がすべてわかってれば、
矩形に対して差分と境界の隣接具合から O(N) で求まる気がする
x, yまでの連結成分の個数はどうやって求まるか？
同じく上と左の個数と境界パターンから求まるので O(N^3) で求まる。がそれでは間に合わない。

ぜんぜんわからん。
*/
template<typename T>
class AccSum2D {
public:
	// data[y][x] is sum of [0, x) x [0, y)
	vector<vector<T>> acc;
	AccSum2D(const vector<vector<T>>& data) {
		int H=data.size();
		int W=data[0].size();
		acc = data;
		REP(y, H) REP(x, W) {
			T v = data[y][x];
			if(0<=x-1) v += acc[y][x-1];
			if(0<=y-1) v += acc[y-1][x];
			if(0<=x-1 && 0<=y-1) v -= acc[y-1][x-1];
			acc[y][x] = v;
		}
	}
	// returns sum of [x0, x1] x [y0, y1]
	T sum(ll x0, ll y0, ll x1, ll y1) {
		T v = acc[y1][x1];
		if(0<=y0-1) v -= acc[y0-1][x1];
		if(0<=x0-1) v -= acc[y1][x0-1];
		if(0<=x0-1 && 0<=y0-1) v += acc[y0-1][x0-1];
		return v;
	}
};

int main() {
	//ios::sync_with_stdio(false);
	ll W,H,Q;
	string s;
	while(cin>>H>>W>>Q) {
		vector<string> w(H);
		REP(i, H) cin>>w[i];
		VVI v(H, VI(W));
		VVI l(H, VI(W));
		VVI t(H, VI(W));
		REP(y, H) REP(x, W) {
			v[y][x] = w[y][x]=='1';
			if(0<=x-1) l[y][x] = w[y][x]=='1' && w[y][x-1]=='1';
			if(0<=y-1) t[y][x] = w[y][x]=='1' && w[y-1][x]=='1';
		}
		AccSum2D<ll> vs(v), ls(l), ts(t);
//		DD(vs.acc);
//		DD(ls.acc);
//		DD(ts.acc);
		REP(i, Q) {
			ll x1, y1, x2, y2;
			cin>>y1>>x1>>y2>>x2;
			x1--;y1--;x2--;y2--;
//			DD(vs.sum(x1, y1, x2, y2));
//			DD(ls.sum(x1+1, y1, x2, y2));
//			DD(ts.sum(x1, y1+1, x2, y2));
			// 左との間に辺があるか? なので 1 マス右から見る
			// 上も同様
			ll ans = vs.sum(x1, y1, x2, y2) - ls.sum(x1+1, y1, x2, y2) - ts.sum(x1, y1+1, x2, y2);
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
