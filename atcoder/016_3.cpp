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

int main() {
	//ios::sync_with_stdio(false);
	ll N,M;
	while(cin>>N>>M) {
		VI cost(M);
		vector<vector<PII> > kuji(M, vector<PII>());
		vector<double> es(1<<N, INF);
		REP(i, M) {
			ll C;
			cin>>C>>cost[i];
			REP(j, C) {
				ll idol, p;
				cin>>idol>>p;
				idol--;
				kuji[i].PB(MP(idol, p));
			}
//			cout<<kuji[i]<<endl;
		}
		es[(1<<N)-1]=0;
		for(int bit=(1<<N)-1;bit>=0;bit--) {
			REP(k, M) {
				int Q=0; // P for take cards already I have
				REP(j, kuji[k].size()) {
					if((bit>>kuji[k][j].first)&1) Q+= kuji[k][j].second;
				}
				if(Q==100) continue;
				double t = cost[k] / (1.0-Q/100.0);
				REP(j, kuji[k].size()) {
					if(!( (bit>>kuji[k][j].first)&1)) {
						t += kuji[k][j].second/(100.0-Q) * es[bit|1<<kuji[k][j].first];
					}
				}
				es[bit] = min(es[bit], t);
			}
		}
//		cout<<"ALL "<<es<<endl;
		cout<<setprecision(20)<<es[0]<<endl;
//		break;
	}
	
	return 0;
}
