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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

typedef vector<PII> Edge;
typedef vector<Edge> Graph;
bool tsort(Graph& g, int i, vector<int>& status, vector<int>& topo) {
	status[i]=1;
	for(int j=0;j<g[i].size();j++) {
		int v1 = g[i][j].first;
		if(status[v1]==1) return false;
		if(!status[v1] && !tsort(g, v1, status, topo)) return false;
	}
	topo.push_back(i);
	status[i]=2;
	return true;
}
bool tsort(Graph& g, vector<int>& topo) {
	int vn = g.size();
	vector<int> status(vn, 0);
	for(int i=0;i<vn;i++) {
		if(!status[i] && !tsort(g, i, status, topo)) return false;
	}
	return true;
}

void dfs(Graph& g, Graph& out, int nid, int pid, VI& parent, VI& broken) {
	REP(i, g[nid].size()) {
		int v1 = g[nid][i].first;
		if(v1==pid) continue;
		parent[v1] = nid;
		broken[v1] = g[nid][i].second;
		out[nid].PB(MP(v1, broken[v1]));
		dfs(g, out, v1, nid, parent, broken);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
		Graph gg(N, Edge());
		Graph g(N, Edge());
		VI broken(N);
		VI parent(N, -1);
		VI done(N);
		REP(i, N-1) {
			int v0, v1, t;
			cin>>v0>>v1>>t;
			v0--; v1--;
//			cout<<v0<<" "<<v1<<" "<<t<<endl;
			gg[v0].PB(MP(v1, t==2));
			gg[v1].PB(MP(v0, t==2));
		}
		dfs(gg, g, 0, -1, parent, broken);
//		cout<<g<<endl;
//		cout<<"PA "<<parent<<endl;
//		cout<<"BR "<<broken<<endl;
		vector<int> topo;
		tsort(g, topo);
		VI ans;
		REP(i, N) {
			int nid = topo[i];
			if(broken[nid]) {
				ans.PB(nid+1);
				while(nid && !done[nid]) {
//					cout<<"tr "<<nid<<endl;
					broken[nid] = 0;
					done[nid] = 1;
					nid = parent[nid];
				}
			}
		}
		
//		cout<<topo<<endl;
		cout<<ans.size()<<endl;
		REP(i, ans.size()) {
			cout<<ans[i];
			if(i<ans.size()-1) cout<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
