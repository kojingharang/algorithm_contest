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
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

// dp[i][j][k][l]
// = 最初の割当が i (0:A 1:B), j+1分終わった時点, A の割当時間が k 分, 最後の割当が l (0:A 1:B) な状態での最小切り替え回数
int dp[2][1440][721][2];

int INF = 1<<30;

int main() {
	int test_cases;
	cin>>test_cases;
	ll A,B, s, e;
	REP(ttt, test_cases) {
		cin>>A>>B;
		VI tl(1440, -1); // 0: A 1: B -1: none
		REP(i, A) {
			cin>>s>>e;
			RANGE(i, s, e) tl[i] = 0;
		}
		REP(i, B) {
			cin>>s>>e;
			RANGE(i, s, e) tl[i] = 1;
		}
		REP(bi, 2) REP(mi, 1440) REP(ai, 721) REP(ei, 2) dp[bi][mi][ai][ei] = INF;
		REP(bi, 2) REP(ei, 2) dp[bi][0][ei==0][ei] = bi!=ei;
		REP(bi, 2) REP(mi, 1440) REP(ai, 721) REP(ei, 2) REP(nei, 2) {
			int old = dp[bi][mi][ai][ei];
			int nbi = bi;
			int nmi = mi+1;
			int nai = ai + (nei==0);
			int cost = ei!=nei;
			if(nmi<1440 && tl[nmi]!=nei && nai<=720) {
				dp[nbi][nmi][nai][nei] = min(dp[nbi][nmi][nai][nei], old + cost);
			}
		}
		int ans = INF;
		REP(bi, 2) REP(ei, 2) {
			// 日をまたぐ切り替えの考慮
			int lans = dp[bi][1439][720][ei]+(bi!=ei);
			ans = min(ans, lans);
		}

		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		cout<<"\n\n\n";
//		return 0;
	}
	return 0;
}



