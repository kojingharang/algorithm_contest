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

double P[100010];
double dp[100][100];
double p[100][100];
int main() {
	//ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
		REP(i, N) {
			cin>>P[i];
		}
		double x = 0;
		double ans = 0;
		REP(i, N) {
			ans += (2*x+1)*P[i];
			x = (x+1)*P[i];
		}
		cout<<ans<<endl;
		continue;
		
		//CLEAR(dp, 0);
		//CLEAR(p, 0);
		//p[0][0]=1;
		////REP(i, N+1) dp[0][i]=0;
		//RANGE(i, 0, N+1) {
		//	REP(j, i+1) {
		//		dp[i+1][j+1] += dp[i][j] * P[i] + (2*j+1) * p[i][j] * P[i];
		//		dp[i+1][0]   += dp[i][j] * (1-P[i]);
		//		p[i+1][j+1]  += p[i][j] * P[i];
		//		p[i+1][0]    += p[i][j] * (1-P[i]);
		//	}
		//}
		////PRINT2(dp, N+1, N+1);
		////cout<<endl;
		////PRINT2(p, N+1, N+1);
		////double ans = 0;
		////REP(i, N+1) ans += dp[N][i];
		//
		//
		//cout<<ans<<endl;
	}
	
	return 0;
}
