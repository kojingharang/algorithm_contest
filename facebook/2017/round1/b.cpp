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
#define IN(v, lo, hi) ((lo)<=(v) && (v)<=(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
/*
increase stack size!!!!!!
// 16MB
g++ -O2 -Wl,-stack_size,10000000 -std=c++11 -Wall d.cpp && ./a.out < corporate_gifting.txt > do2.txt
*/

struct Rect {
	ll x0, x1, y0, y1;
};

ostream& operator<<(ostream& o, const Rect& r) {
	o<<"Rect x in ["<<r.x0<<" "<<r.x1<<"] y in ["<<r.y0<<" "<<r.y1<<"] ";
	return o;
}

ll N;
VI X, Y;
VI SX, SY;
ll R;

ll memo[51][51][51][51];
//ll hit=0,all=0;
ll points(Rect r0) {
	Rect ri;
	ri.x0 = distance(SX.begin(), lower_bound(ALL(SX), r0.x0));
	ri.y0 = distance(SY.begin(), lower_bound(ALL(SY), r0.y0));
	ri.x1 = distance(SX.begin(), upper_bound(ALL(SX), r0.x1))-1;
	ri.y1 = distance(SY.begin(), upper_bound(ALL(SY), r0.y1))-1;
	assert(0<=ri.x0 && ri.x0<SX.size());
	assert(0<=ri.x1 && ri.x1<SX.size());
	assert(0<=ri.y0 && ri.y0<SY.size());
	assert(0<=ri.y1 && ri.y1<SY.size());

//	DD(SX);DD(SY);
//	cout<<"r0 "<<r0<<endl;
//	cout<<"ri "<<ri<<endl;

//	all++;
	ll& m = memo[ri.x0][ri.x1][ri.y0][ri.y1];
	if(m>=0) {
//		hit++;
		return m;
	}

	ll lans = 0;
	REP(i, N) {
		bool ok = IN(X[i], r0.x0, r0.x1) && IN(Y[i], r0.y0, r0.y1);
		if(ok) lans++;
	}
	return m = lans;
}

Rect rectAnd(Rect a, Rect b) {
	Rect rv = Rect{
		max(a.x0, b.x0),
		min(a.x1, b.x1),
		max(a.y0, b.y0),
		min(a.y1, b.y1)
	};
//	cout<<"rectAnd a "<<a<<" b "<<b<<" rv "<<rv<<endl;
	return rv;
}

ll solve3() {
	vector<tuple<Rect, ll>> ones;

	REP(xp0, 2) REP(yp0, 2)
	REP(xi0, N) REP(yi0, N)
	{
		Rect r0;
		r0.x0 = X[xi0];
		r0.y0 = Y[yi0];
		r0.x1 = r0.x0 + (xp0?1:-1)*R;
		r0.y1 = r0.y0 + (yp0?1:-1)*R;
		if(r0.x0 > r0.x1) swap(r0.x0, r0.x1);
		if(r0.y0 > r0.y1) swap(r0.y0, r0.y1);
		ll lans = points(r0);
		ones.PB(make_tuple(r0, lans));
	}

	ll ans = 0;
	REP(i, ones.size())
	REP(j, ones.size()) {
		Rect a = get<0>(ones[i]);
		Rect b = get<0>(ones[j]);
		Rect ab = rectAnd(a, b);
		ll lans = get<1>(ones[i]) + get<1>(ones[j]) - points(ab);
		ans = max(ans, lans);
	}
	return ans;
}

ll solve2() {
	map<ll, vector<Rect>> rM;

	REP(xp0, 2) REP(yp0, 2)
	REP(xi0, N) REP(yi0, N)
	{
		Rect r0;
		r0.x0 = X[xi0];
		r0.y0 = Y[yi0];
		r0.x1 = r0.x0 + (xp0?1:-1)*R;
		r0.y1 = r0.y0 + (yp0?1:-1)*R;
		ll lans = 0;
		REP(i, N) {
			bool ok =
				   (IN(X[i], r0.x0, r0.x1) && IN(Y[i], r0.y0, r0.y1))
				;
			if(ok) lans++;
		}
		rM[-lans].PB(r0);
	}

	ll ans = 0;
	ll cnt=0;
	for(auto& kv : rM) {
//		DD(kv.first);
		vector<Rect>& ros = kv.second;
		for(Rect& ro : ros) {
			if(cnt++ > N*N/2) break;
//			if(cnt++ > N) break;

			REP(xp0, 2) REP(yp0, 2)
			REP(xi0, N) REP(yi0, N)
			{
				Rect r0, r1;
				r0.x0 = X[xi0];
				r0.y0 = Y[yi0];
				r0.x1 = r0.x0 + (xp0?1:-1)*R;
				r0.y1 = r0.y0 + (yp0?1:-1)*R;

				ll lans = 0;
				REP(i, N) {
					bool ok =
						   (IN(X[i], r0.x0, r0.x1) && IN(Y[i], r0.y0, r0.y1))
						|| (IN(X[i], ro.x0, ro.x1) && IN(Y[i], ro.y0, ro.y1))
						;
					if(ok) lans++;
				}
				ans = max(ans, lans);
			}
		}
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		REP(a, 51) REP(b, 51) REP(c, 51) REP(d, 51) memo[a][b][c][d] = -1;
		cin>>N>>R;
		X = VI(N);
		Y = VI(N);

		REP(i, N) cin>>X[i]>>Y[i];

		SX = X;
		SY = Y;
		sort(ALL(SX));
		sort(ALL(SY));
//		DD(SX);DD(SY);

		ll ans = 0;
//		ans = max(ans, solve2());
		ans = max(ans, solve3());

		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		DD(hit);DD(all);
//		break;
	}
	
	return 0;
}
