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
200
まるを通るL 180+5PI = 195.7...
まるを通る- 180+10PI = 211.7...

X1==X2 or Y1==Y2 の場合
	o を通る場合 1 回. 180 度またぐ
else
	なるべくoをとおる. すべて90度まがる.
	180 度またぐことはない.
	180とすると行列に1こしかないのでそこで90曲がれば通る箇所を変えずに減らせるので.


set : index ... +1されるぽいんと

0 0 0 0 1 2 2 3
0 0 0 0 1 2 2 2
0 0 0 0 1 1 2 2
0 0 0 0 1 1 1 1

0 0 1 2 2 2 2 2
0 0 1 2 2 2 2 2
0 0 1 1 1 1 1 1
0 0 0 0 1 1 1 1
*/
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll X1,X2,Y1,Y2,N,x,y;
	while(cin>>X1>>Y1>>X2>>Y2>>N) {
		int xsign = 1, ysign = 1;
		if(X1>X2) xsign = -1;
		if(Y1>Y2) ysign = -1;
		X1 *= xsign;
		X2 *= xsign;
		Y1 *= ysign;
		Y2 *= ysign;
		vector<PII> ps(N); // y x
		REP(i, N) {
			cin>>ps[i].second>>ps[i].first;
			ps[i].second *= xsign;
			ps[i].first *= ysign;
		}
		sort(ALL(ps));
		// X1 =< X2, Y1 =< Y2
//		DD(X1);
//		DD(X2);
//		DD(Y1);
//		DD(Y2);
//		DD(ps);
		set<int> s;
		REP(i, N) {
			tie(y, x) = ps[i];
			if(Y1 <= y && y <= Y2 && X1 <= x && x <= X2) {
				auto nxt = s.lower_bound(x);
				if(nxt!=s.end()) {
					s.erase(nxt);
				}
				s.insert(x);
			}
		}
		ll S = abs(X2-X1) + abs(Y2-Y1);
		ll p = s.size();
		ll q = 0;
		if(s.size()==min(X2-X1, Y2-Y1)+1) {
			p = s.size()-1;
			q = 1;
		}
		long double ans = S*100.0 + (-20.0 + 5*M_PI)*p + (-20.0 + 10*M_PI)*q;
//		DD(s.size());
		printf("%.20Lf\n", ans);
	}
	
	return 0;
}
