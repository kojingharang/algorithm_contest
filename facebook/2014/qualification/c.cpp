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
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define VD vector<double>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define VVD vector<vector<double> >
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

// Return random integer in [s, e)
#define UNIFORM_INT(s, e)    ( s + (int)((e-s) * UNIFORM_FLOAT_01()) )

// Return random float in [s, e)
#define UNIFORM_FLOAT(s, e)  ( s + (e-s) * UNIFORM_FLOAT_01() )
#define UNIFORM_FLOAT_01()  ( (float)rand()/(1.0f+RAND_MAX) )


#define MOD 1000000007LL
#define INF (1LL<<60)

// [N%2][K][P] ... N set後にK回勝っていて晴れ確率がPである確率
double dp[2][110][1002];

int K;
double ps, pr, pi, pu, pw, pd, pl;

int main() {
	//ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		cin>>K>>ps>>pr>>pi>>pu>>pw>>pd>>pl;
		int iu = pu*1000;
		int id = pd*1000;
		int cur=0;
		CLEAR(dp[cur], 0);
		dp[cur][0][(int)(pi*1000)] = 1;
		double ans = 0;
		REP(matches, 2*K-1) {
			CLEAR(dp[1-cur], 0);
			REP(win, K) {
				int lose = matches-win;
				if(lose >= K) continue;
				REP(sunnyP1000, 1001) {
					double winP = (sunnyP1000 * ps + (1000-sunnyP1000) * pr) / 1000.0;
					int upP = min(1000, sunnyP1000 + iu);
					int downP = max(0, sunnyP1000 - id);
					double curP = dp[cur][win][sunnyP1000];
					dp[1-cur][win+1][upP] += curP * winP * pw;            // win, up
					dp[1-cur][win+1][sunnyP1000] += curP * winP * (1-pw);        // win, stay  
					dp[1-cur][win  ][downP] += curP * (1-winP) * pl;        // lose, down
					dp[1-cur][win  ][sunnyP1000] += curP * (1-winP) * (1-pl);    // lose, stay
				}
			}
			double lans=0;
			REP(sP, 1001) lans += dp[1-cur][K][sP];
			ans+=lans;
//			cout<<"# old"<<endl;
//			PRINT3(dp[cur], K+1, K+1, K+1);
//			cout<<"# new"<<endl;
//			int MK=min(matches+1, K);
//			PRINT3(dp[1-cur], MK+1, MK+1, MK+1);
//			cout<<"LANS "<<lans<<endl;
//			cout<<"ANS  "<<ans<<endl;
			cur ^= 1;
		}
		
		printf("Case #%d: %.6f\n", CaseID+1, ans);
//		break;
	}
	
	return 0;
}
