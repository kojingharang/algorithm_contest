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
#define P(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")

ll Common(string a, string b) {
	ll co = 0;
	REP(ci, min(a.size(), b.size())) if(a[ci]==b[ci]) co++; else break;
	return co;
}

ll naive(ll N, ll K, vector<string> s) {
	assert(N<=10);
	sort(ALL(s));
	ll ans = 1LL<<60;
	do {
		ll lans = 0;
		REP(i, K) {
			string prev = i==0 ? "" : s[i-1];
			lans += prev.size()+s[i].size()+1 - Common(prev, s[i])*2;
		}
		lans += s[K-1].size();
		ans = min(ans, lans);
	} while(next_permutation(ALL(s)));
	return ans;
}

#define INF 1LL<<60
ll dp[2][302][302];
ll common[302][302];
char buf[100010];
int main(int args, char**argv) {
	ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;


//	int TH_ALL = 1;
//	int TH_ID = 0;
//	int lo=0, hi=Cases-1;
//	{
//		if(args > 2) {
//			TH_ALL = atoi(argv[1]);
//			TH_ID = atoi(argv[2]);
//		}
//		cerr<<"TH_ALL TH_ID "<<TH_ALL<<" "<<TH_ID<<endl;
//		lo = Cases/TH_ALL*TH_ID;
//		hi = TH_ID==TH_ALL-1 ? Cases-1 : Cases/TH_ALL*(TH_ID+1)-1;
//		cerr<<"lo hi "<<lo<<" "<<hi<<endl;
//	}
	REP(CaseID, Cases) {
		ll N, K;
		cin>>N>>K;
		vector<string> s(N);
		REP(i, N) {
			scanf("%s", buf);
			s[i] = buf;
		}
//		REP(i, N) cin>>s[i];

//		cerr<<"CaseID "<<CaseID<<endl;
//		if(!(lo <= CaseID && CaseID <= hi)) continue;

		sort(ALL(s));
//		cout<<s<<endl;
		s.PB("");

		REP(men, 2) REP(i, N+1) REP(j, N+1) dp[men][i][j]=INF;
		int men=0;
		dp[men][0][N] = 0;
//		cout<<"init "<<endl;
//		PRINT2(dp[men], K+1, N+1);

		CLEAR(common, 0);
		REP(i, N+1) REP(j, N+1) {
			ll co = 0;
			REP(ci, min(s[i].size(), s[j].size())) if(s[i][ci]==s[j][ci]) co++; else break;
			common[i][j]=co;
		}

		REP(i, N) {
			int nmen = 1-men;
			REP(k, K+1) REP(last, N+1) dp[nmen][k][last]=INF;

			REP(k, K+1) REP(last, N+1) if(dp[men][k][last] < INF) {
				dp[nmen][k][last] = min(dp[nmen][k][last], dp[men][k][last]);

				int cost = s[last].size()+s[i].size()+1 - common[last][i]*2;
				dp[nmen][k+1][i] = min(dp[nmen][k+1][i], dp[men][k][last] + cost);
			}
//			cout<<"after "<<i<<endl;
//			PRINT2(dp[nmen], K+1, N+1);
			men = nmen;
		}
		ll ans = INF;
		REP(last, N) ans = min<ll>(ans, dp[men][K][last]+s[last].size());
		
//		{
//			s.pop_back();
//			ll ref = naive(N, K, s);
//			if(ref!=ans) {
//				P(N);
//				P(K);
//				P(s);
//				P(ref);
//				P(ans);
//				assert(false);
//			}
//		}
		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		cout<<N<<" "<<K<<endl;
//		cout<<s<<endl;
//		break;
	}
	
	return 0;
}
