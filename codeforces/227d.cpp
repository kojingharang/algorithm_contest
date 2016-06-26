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
#define VI vector<int>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(ll i=0,_n=(n);(i)<(int)_n;++i)
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

ll cum[100010];
ll w[100010];
int main() {
	ios::sync_with_stdio(false);
	ll N,Q;
	while(cin>>N) {
		//VI w(N);
		//vector<ll> cum(N+1); // sum[0, i) for i in [0, N+1]
		REP(i, N) {
			cin>>w[i];
		}
		sort(w, w+N);
		reverse(w, w+N);
		cum[0]=0;
		REP(i, N) {
			cum[i+1] = cum[i]+w[i];
		}
		//cout<<w<<endl;
		//cout<<cum<<endl;
		
		map<ll, ll> memo;
		cin>>Q;
		REP(q, Q) {
			ll k;
			cin>>k;
			ll ans = 0;
			if(memo.count(k)) ans = memo[k];
			else {
				ll v=1;
				ll hd = 0;
				REP(loop, N) {
					ll tl = hd+v;
					tl = min(tl, N);
					ans += (cum[tl]-cum[hd]) * loop;
					//cout<<hd<<" "<<tl<<"  "<<v<<" + "<<(cum[tl]-cum[hd])<<" -> "<<ans<<endl;
					v *= k;
					hd = tl;
					if(tl>=N) break;
				}
				memo[k]=ans;
			}
			cout<<ans<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
