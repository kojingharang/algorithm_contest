#include <vector>
#include <map>
#include <set>
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
#include <cassert>
#include <cctype>
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



struct bipartite_matching {
	VVI g;
	VI match;
	VI used;
	
	bipartite_matching(int N) {
		g = VVI(N);
	}
	
	int dfs(int v) {
		used[v]=1;
		for(int i=0;i<(int)g[v].size();i++) {
			int u=g[v][i], w=match[u];
			if(w<0 || !used[w] && dfs(w)) {
				match[v]=u;
				match[u]=v;
				return 1;
			}
		}
		return 0;
	}
	
	int run() {
		int res=0;
		match=VI(g.size(), -1);
		for(int v=0;v<(int)g.size();v++){
			if(match[v]<0) {
				used=VI(g.size());
				if(dfs(v)) res++;
			}
		}
		return res;
	}
	
	void add_edge(int u, int v){
		g[u].push_back(v);
		g[v].push_back(u);
	}
};

ll N, M, L;
string K1, K2;

int check() {
	bipartite_matching bm(M*2);
	
	// i in K1, j in K2
	REP(i, M) REP(j, M) {
		int lok=1;
		REP(li, L) {
			char a=K1[i*L+li], b=K2[j*L+li];
			if(!(a=='?' || b=='?') && a!=b) lok=0;
		}
//		cout<<"[match] "<<K1.substr(i*L, L)<<" "<<K2.substr(j*L, L)<<" -> "<<lok<<endl;
		if(lok) bm.add_edge(i, M+j);
	}
	int matched=bm.run();
//	cout<<"[result] result: "<<matched<<endl;
	return matched==M;
}

int main() {
	int T;
	cin>>T;
	REP(ttt, T) {
		cin>>M;
		cin>>K1>>K2;
		N=K1.size();
		L=N/M;
		
		int gok=1;
		REP(ci, N) {
			if(K1[ci]=='?') {
				int ok=0;
				REP(cand, 6) {
					K1[ci]=cand+'a';
//					cout<<"[try] idx: "<<ci<<" char: "<<string(1, cand+'a')<<endl;
					if(check()) {ok=1;break;}
				}
				if(!ok) {gok=0;break;}
			}
		}
		if(!check()) gok=0;
		
		if(gok) {
			cout<<"Case #"<<ttt+1<<": "<<K1<<endl;
		} else {
			cout<<"Case #"<<ttt+1<<": IMPOSSIBLE"<<endl;
		}
//		break;
	}
	return 0;
}


