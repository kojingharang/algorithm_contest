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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")

#define MOD 1000000007LL
#define INF (1LL<<60)

struct Dijkstra {
    struct edge{int to,cost;};
    vector<vector<edge> > G;
    vector<ll> V;
    Dijkstra(int N) {
        G = vector<vector<edge> >(N);
        V = vector<ll>(N, 1<<30);
    }
    void add_edge(int v0, int v1, int cost) {
        if(v0<G.size() && v1<G.size()) G[v0].PB((edge){v1, cost});
    }
    int run(int S, int E) {
        V[S]=0;
        priority_queue<PII> q;
        q.push(make_pair(0, S));
        while(q.size()) {
            PII el = q.top(); q.pop();
            if(el.second==E) break;
            if(-el.first > V[el.second]) continue;
            for(int i=0;i<(int)G[el.second].size();i++){
                const edge& e=G[el.second][i];
                if(V[e.to]>V[el.second]+e.cost){
                    V[e.to]=V[el.second]+e.cost;
                    q.push(make_pair(-V[e.to], e.to));
                }
            }
        }
        if(E<0) return -1;
        return V[E]==1<<30?-1:V[E];
    }
};

ll H, W;
vector<string> m;
vector<int> lx, ly, ldir;
int inMap(int x, int y) {
	return 0<=x && x<W && 0<=y && y<H;
}
int isFence(int x, int y) {
	char c=m[y][x];
	return c=='<' || c=='>' || c=='^' || c=='v' || c=='#';
}
int dx[] = {0,1,0,-1}; // up right down left
int dy[] = {-1,0,1,0}; // up right down left
int alive(int x, int y, int phase) {
	REP(li, lx.size()) {
		int clx=lx[li];
		int cly=ly[li];
		int cldir=(ldir[li]+phase)%4;
		while(1) {
			if(clx==x && cly==y) return 0; //shoot
			clx+=dx[cldir];
			cly+=dy[cldir];
			if(!inMap(clx, cly)) break;
			if(isFence(clx, cly)) break;
		}
	}
	return 1;
}

int canMove(int x, int y, int phase, int dir) {
	int nx = x+dx[dir];
	int ny = y+dy[dir];
	if(!inMap(nx, ny)) return 0;
	if(isFence(x, y)) return 0;
	if(isFence(nx, ny)) return 0;
	if(!alive(nx, ny, (phase+1)%4)) return 0;
	return 1;
}

ll node(int x, int y, int phase) {
	assert(0<=x && x<W && 0<=y && y<H && 0<=phase && phase<4);
	return phase*H*W + x*H + y;
}

int main() {
	//ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		cin>>H>>W;
		m = vector<string>(H);
		REP(y, H) cin>>m[y];
		ll start;
		vector<ll> goals;
		lx.clear();
		ly.clear();
		ldir.clear();
		REP(y, H) REP(x, W) {
			if(m[y][x]=='S') start = node(x, y, 0);
			if(m[y][x]=='G') {
				REP(p, 4) goals.PB(node(x, y, p));
			}
			if(m[y][x]=='^') {
				lx.PB(x); ly.PB(y); ldir.PB(0);
			}
			if(m[y][x]=='>') {
				lx.PB(x); ly.PB(y); ldir.PB(1);
			}
			if(m[y][x]=='v') {
				lx.PB(x); ly.PB(y); ldir.PB(2);
			}
			if(m[y][x]=='<') {
				lx.PB(x); ly.PB(y); ldir.PB(3);
			}
		}
//		cout<<m<<endl;
		Dijkstra d(W*H*4);
		REP(y, H) REP(x, W) REP(p, 4) REP(dir, 4) {
			if(canMove(x, y, p, dir)) {
				int nx = x+dx[dir];
				int ny = y+dy[dir];
			    d.add_edge(node(x, y, p), node(nx, ny, (p+1)%4), 1);
			}
		}
		d.run(start, -1);
		ll ans = 1LL<<60;
		REP(ni, W*H*4) {
			REP(gi, 4) if(d.V[goals[gi]] < (1<<30)) ans=min<ll>(ans, d.V[goals[gi]]);
		}
		if(ans==1LL<<60) {
			cout<<"Case #"<<CaseID+1<<": "<<"impossible"<<endl;
		} else {
			cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
		}
//		break;
	}
	
	return 0;
}
