#include <vector>
#include <map>
#include <set>
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
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define VVVI vector<vector<vector<ll>>>
#define VVVVI vector<vector<vector<vector<ll>>>>
#define REP(i,n) for(ll i=0,_n=(n);(i)<(ll)_n;++i)
#define REPR(i,n) for(ll i=(ll)(n)-1;0<=(i);--i)
#define RANGE(i,a,b) for(ll i=(ll)a,_b=(ll)(b);(i)<_b;++i)
#define RANGER(i,a,b) for(ll i=(ll)(b)-1,_a=(ll)(a);(_a)<=i;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
#define FI first
#define SE second
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}

#define MOD 1000000007LL
#define INF (1LL<<60)

int main() {
	if(0)
	{
		// 100x1000 random で 13回のループで終わった。意外とすぐ終わるもんなのかもしれない。
//		ll W=100,H=1000;
		ll W=100,H=100;
		VVI m(H, VI(W));
		cout<<1<<"\n"<<H<<" "<<W<<endl;
		REP(y, H) REP(x, W) m[y][x]=UNIFORM_LL(1, 1000001);
		REP(y, H) {
			REP(x, W) {cout<<m[y][x]<<" ";}
			cout<<endl;
		}
		return 0;
	}

	cin.tie(0);
	ios::sync_with_stdio(false);
	int test_cases;
	cin>>test_cases;
	ll W,H;
	string s;
	REP(ttt, test_cases) {
		cin>>H>>W;
		VVI m(H, VI(W));
		vector<vector<vector<PII>>> ne(4, vector<vector<PII>>(H, vector<PII>(W)));
		ll dx[] = {0,0,1,-1};
		ll dy[] = {1,-1,0,0};
		ll opp[] = {1,0,3,2};
		REP(y, H) REP(x, W) REP(d, 4) {
			ll nx = x+dx[d];
			ll ny = y+dy[d];
			ne[d][y][x] = IN(nx, 0, W) && IN(ny, 0, H) ? MP(nx, ny) : MP(-1LL, -1LL);
		}
		REP(y, H) REP(x, W) cin>>m[y][x];
		ll liveSum = 0;
		REP(y, H) REP(x, W) liveSum+=m[y][x];
		VVI live(H, VI(W, 1));

		ll ans = 0;
		set<PII> check;
		REP(y, H) REP(x, W) check.insert(MP(x, y));
		while(check.size()) {
			ans += liveSum;
//			DD(liveSum);
			set<PII> ncheck, rm;

			for(auto p: check) {
				ll x, y;
				tie(x, y) = p;
				if(live[y][x]==0) continue;

				ll cnt = 0, sum = 0;;
				REP(d, 4) {
					auto np = ne[d][y][x];
					ll nx = np.FI;
					ll ny = np.SE;
					if(IN(nx, 0, W) && IN(ny, 0, H)) {
						sum+=m[ny][nx];
						cnt++;
					}
				}
				if(m[y][x]*cnt<sum) rm.insert(p);
			}
//			DD(rm);
			for(auto p: rm) {
				ll x, y;
				tie(x, y) = p;
//				DD("rm");DD(x);DD(y);
				if(live[y][x]==0) {
					DD(x);DD(y);
					assert(0);
				}
				live[y][x]=0;
				liveSum-=m[y][x];
				REP(d, 4) {
					auto np = ne[d][y][x];
					ll nx = np.FI;
					ll ny = np.SE;
					if(IN(nx, 0, W) && IN(ny, 0, H)) {
						ncheck.insert(np);
						ne[opp[d]][ny][nx] = ne[opp[d]][y][x];
					}
				}
			}
//			DD(rm);
//			DD(ne);
//			DD(liveSum);
			check = ncheck;
		}
//		DD(cnt);
		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		return 0;
	}
	return 0;
}



