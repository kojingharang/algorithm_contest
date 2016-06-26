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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

int main() {
	//ios::sync_with_stdio(false);
	ll N,M,L,S,T;
	while(cin>>N>>M>>L>>S>>T) {
		if(N==0) return 0;
		S--;
		VVI sw(N, VI(N, INF));
		VI sI(L+1), sT(L+1);
		REP(i, N) sw[i][i]=0;
		REP(i, M) {
			ll n0, n1, cost;
			cin>>n0>>n1>>cost;
			n0--; n1--;
			sw[n0][n1]=min(sw[n0][n1], cost);
			sw[n1][n0]=min(sw[n1][n0], cost);
		}
		sI[0]=S;
		REP(i, L) {
			ll st, cost;
			cin>>st>>cost;
			sI[i+1]=st-1;
			sT[i+1]=cost;
		}
		REP(k, N) REP(i, N) REP(j, N) sw[i][j]=min(sw[i][j], sw[i][k]+sw[k][j]);
//		cout<<sw<<endl;
		
		VVI dp(L+1, VI(1<<L, INF));
		dp[0][0]=0;
		REP(bit, 1<<L) {
			REP(cur, L+1) {
				RANGE(nxt, 1, L+1) {
					if(((bit>>(nxt-1))&1)==0) {
						ll nbit = bit | (1<<(nxt-1));
						ll cost = sw[sI[cur]][sI[nxt]] + sT[nxt];
						dp[nxt][nbit] = min(dp[nxt][nbit], dp[cur][bit] + cost);
					}
				}
			}
		}
		int ans=0;
		REP(bit, 1<<L) {
			RANGE(cur, 1, L+1) {
				dp[0][bit]=min(dp[0][bit], dp[cur][bit]+sw[sI[cur]][S]);
			}
			if(dp[0][bit]<=T) ans=max(ans, POPCOUNT(bit));
		}
//		cout<<dp<<endl;
		
		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}


