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

ll N;
VVI g;
VI X;
VI dp;
bool ans;

void dfs(int idx) {
	ll all = 0;
	vector<bool> idp(X[idx]+1);
	idp[0] = 1;
	REP(i, g[idx].size()) {
		int ch = g[idx][i];
		dfs(ch);
		vector<bool> nidp(X[idx]+1);
		REP(idi, idp.size()) {
			ll di = idp.size()-1-idi;
			if(idp[di]) {
				{
					ll ndi = di + X[ch];
					if(ndi < idp.size()) nidp[ndi]=1;
				}
				{
					ll ndi = di + dp[ch];
					if(ndi < idp.size()) nidp[ndi]=1;
				}
			}
		}
		idp = nidp;
		all += X[ch]+dp[ch];
	}
	bool any = 0;
	REP(idi, idp.size()) {
		ll di = idp.size()-1-idi;
		if(idp[di]) {
			any = 1;
			dp[idx] = all - di;
			break;
		}
	}
	if(!any) ans = 0;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll p;
	while(cin>>N) {
		g = VVI(N);
		REP(i, N-1) {
			cin>>p;
			p--;
			g[p].PB(i+1);
		}
		X = VI(N);
		REP(i, N) cin>>X[i];
		dp = VI(N, INF);
		ans = 1;
		dfs(0);
//		DD(dp);
		cout<<(ans?"POSSIBLE":"IMPOSSIBLE")<<endl;
	}
	
	return 0;
}
