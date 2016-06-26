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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

VVI nor(VVI& w) {
	int H = w.size();
	int W = w[0].size();
	map<int, int> col;
	VVI ret(w);
	int p=0;
	REP(y, H) REP(x, W) {
		if(!col.count(w[y][x])) col[w[y][x]] = p++;
		ret[y][x] = col[w[y][x]];
	}
	return ret;
}

int main() {
	//ios::sync_with_stdio(false);
	ll N, H, W;
	while(cin>>N) {
		VI col(N);
		REP(i, N) cin>>col[i];
		sort(ALL(col));
		cin>>H>>W;
//		if(!(N<=5 && H<=5 && W<=5)) continue;
		if(!(N<=9)) continue;
		VVI ref(H, VI(W));
		REP(y, H) REP(x, W) cin>>ref[y][x];
		VI x0(N), y0(N), x1(N), y1(N);
		REP(i, N) {
			int minX=100, maxX=-1, minY=100, maxY=-1;
			REP(y, H) REP(x, W) if(ref[y][x]==i) {
				minX = min(minX, x);
				minY = min(minY, y);
				maxX = max(maxX, x);
				maxY = max(maxY, y);
			}
			x0[i] = minX, x1[i] = maxX, y0[i] = minY, y1[i] = maxY;
		}
		VI order(N);
		REP(i, N) order[i] = i;
		int ans=0;
		do {
			VVI w(H, VI(W, -1));
			VVI al(H, VI(W, -1));
			int lok = 1;
			REP(i, N) {
				int o = order[i];
				RANGE(x, x0[o], x1[o]+1)
				RANGE(y, y0[o], y1[o]+1) {
					if(al[y][x]>=col[i]) lok=0;
					al[y][x] = col[i];
					w[y][x] = i;
				}
				if(!lok) break;
			}
			if(lok && nor(w)==nor(ref)) {
				ans = 1;
				break;
			}
		} while(next_permutation(ALL(order)));
		
		cout<<ans<<endl;
	}
	
	return 0;
}






