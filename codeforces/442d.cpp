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
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v);
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

#define MOD 1000000007LL
#define INF (1LL<<60)

int main() {
//	REP(i, 1000) cout<<string(1000, '.')<<endl;
//	return 0;

	cin.tie(0);
	ios::sync_with_stdio(false);
	int W,H,K,X0,Y0,X1,Y1;
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	while(cin>>H>>W>>K) {
		vector<string> m(H);
		REP(y, H) cin>>m[y];
		cin>>Y0>>X0>>Y1>>X1;
		X0--;Y0--;X1--;Y1--;

		vector<set<int>> vx(W), vy(H);
		REP(y, H) REP(x, W) {
			vx[x].insert(y);
			vy[y].insert(x);
		}
//		DD(vx);
//		DD(vy);

		using V = tuple<int, int, int>;
		queue<V> q;
		VVI po(H, VI(W, 1LL<<60));

		q.push(make_tuple(0, X0, Y0));
		po[Y0][X0]=0;
		vx[X0].erase(Y0);
		vy[Y0].erase(X0);

		auto proc = [&](int nx, int ny, int np) {
			if(IN(nx, 0, W) && IN(ny, 0, H)) {
				q.push(make_tuple(np, nx, ny));
				po[ny][nx] = np;
//				cout<<"PUSH "<<nx<<" "<<ny<<" "<<np<<endl;
				vx[nx].erase(ny);
				vy[ny].erase(nx);
				return true;
			}
			return false;
		};
		
		ll cnt = 0;
		while(q.size()) {
			cnt++;
			int p, x, y;
			tie(p, x, y) = q.front();
//			DD(p);DD(x);DD(y);
			q.pop();
			if(x==X1 && y==Y1) break;

//			DD(vx[x]);
//			DD(vy[y]);
//			DD("E");
			{
				auto& s = vy[y];
				for(auto it = s.lower_bound(x);it!=s.end();) {
					int nx = *it;
					int ny = y;
//					DD(nx);DD(ny);
					if(m[ny][nx]=='#' || abs(nx-x)>K || abs(ny-y)>K) break;
					it++;
					proc(nx, ny, p+1);
				}
			}
//			DD("W");
			{
				auto& s = vy[y];
//				DD(s);
//				DD(x);
				for(auto it = s.lower_bound(x);it!=s.begin();) {
					it--;
					int nx = *it;
					int ny = y;
//					DD(nx);DD(ny);
					if(m[ny][nx]=='#' || abs(nx-x)>K || abs(ny-y)>K) break;
					proc(nx, ny, p+1);
					it = s.lower_bound(x);
				}
			}
//			DD("S");
			{
				auto& s = vx[x];
				for(auto it = s.lower_bound(y);it!=s.end();) {
					int nx = x;
					int ny = *it;
//					DD(nx);DD(ny);
					if(m[ny][nx]=='#' || abs(nx-x)>K || abs(ny-y)>K) break;
					it++;
					proc(nx, ny, p+1);
				}
			}
//			DD("N");
			{
				auto& s = vx[x];
				for(auto it = s.lower_bound(y);it!=s.begin();) {
					it--;
					int nx = x;
					int ny = *it;
//					DD(nx);DD(ny);
					if(m[ny][nx]=='#' || abs(nx-x)>K || abs(ny-y)>K) break;
					proc(nx, ny, p+1);
					it = s.lower_bound(y);
				}
			}
		}
//		DD(po);
		ll ans = po[Y1][X1]==1LL<<60 ? -1 : po[Y1][X1];
//		DD(cnt);
		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}
