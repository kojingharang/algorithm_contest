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
using namespace std;

#define EPS 1e-12
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

double dp[2][210][110][110];

int main() {
	//ios::sync_with_stdio(false);
	ll N, D;
	int tb[]={
		0, 0, 0,
		1, 0, 0,
		0, 1, 0,
		2, 0, 0,
		0, 0, 1,
		1, 1, 0,
	};
	while(cin>>N>>D) {
		int p2=0, p3=0, p5=0;
		while(D%2==0) p2++,D/=2;
		while(D%3==0) p3++,D/=3;
		while(D%5==0) p5++,D/=5;
		if(D>1) {
			cout<<0<<endl;
			continue;
		}
//		cout<<p2<<" "<<p3<<" "<<p5<<endl;
		int men=0;
		REP(m, 2) REP(i, 210) REP(j, 110) REP(k, 110) dp[m][i][j][k]=0;
		dp[men][0][0][0] = 1;
		REP(I, N) {
			REP(i, 210) REP(j, 110) REP(k, 110) {
				if(dp[men][i][j][k]==0.0) continue;
				REP(me, 6) {
					int ni = i+tb[me*3+0];
					int nj = j+tb[me*3+1];
					int nk = k+tb[me*3+2];
					if(ni<210 && nj<110 && nk<110) dp[1-men][ni][nj][nk] += dp[men][i][j][k] / 6.0;
				}
			}
			REP(i, 210) REP(j, 110) REP(k, 110) dp[men][i][j][k]=0;
			men ^= 1;
//			PRINT3(dp, 5, 5, 1);
		}
		double ans = 0;
		REP(i, 210) REP(j, 110) REP(k, 110) if(i>=p2 && j>=p3 && k>=p5) ans += dp[men][i][j][k];
		
		cout<<ans<<endl;
	}
	
	return 0;
}
