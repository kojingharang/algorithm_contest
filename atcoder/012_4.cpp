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


#define INF (1LL<<60)

int main() {
	//ios::sync_with_stdio(false);
	ll N,T,MOD;
	while(cin>>N>>T>>MOD) {
		vector<PII> w(N);
		int skip=0;
		REP(i, N) {
			cin>>w[i].first>>w[i].second;
			if(abs(w[i].first)>100 || abs(w[i].first)>100) skip=1;
		}
		if(skip) {
			cout<<"SKIP"<<endl;
			continue;
		}
		int B=100;
		VVI m[2];
		m[0] = VVI(201, VI(201));
		m[1] = VVI(201, VI(201));
		
		m[0][B+0][B+0]=1;
		RANGE(i, 1, T) {
			// t=i, store to i%2
			m[(i-1)%2] = VVI(201, VI(201));
			REP(y, 201) REP(x, 201) {
				int dx[] = {1,0,-1,0};
				int dy[] = {0,1,0,-1};
				REP(dir, 4) {
					int nx=x+dx[dir];
					int ny=y+dy[dir];
					if(0<=nx&&nx<201&&0<=ny&&ny<201) {
						m[i%2][y][x] += m[(i-1)%2][ny][nx];
					}
				}
			}
		}
		cout<<m[(T-1)%2]<<endl;
		
		
		cout<<""<<endl;
	}
	
	return 0;
}
