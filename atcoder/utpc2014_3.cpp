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


using namespace std;
struct edge{int to,cost;};
vector<vector<edge> > G;
typedef pair<int, int> P;
const int INF=1<<30;

int dijkstra(int S, int* out) {
  vector<int> V(G.size(), INF);
  V[S]=0;
  priority_queue<P> q;
  q.push(make_pair(0, S));
  while(q.size()) {
    P el = q.top(); q.pop();
	out[el.second] = min(out[el.second], -el.first);
    if(-el.first > V[el.second]) continue;
    for(int i=0;i<(int)G[el.second].size();i++){
      const edge& e=G[el.second][i];
      if(V[e.to]>V[el.second]+e.cost){
        V[e.to]=V[el.second]+e.cost;
        q.push(make_pair(-V[e.to], e.to));
      }
    }
  }
  return 0;
}


int pot[1000];
int mx0[1000];
int mx1[1000];
int main() {
	//ios::sync_with_stdio(false);
	ll N, N0, N1, M0, M1, a, b;
	edge e;
	while(cin>>N0>>M0) {
		CLEAR(mx0, 0);
		CLEAR(mx1, 0);
		N=N0;
	    G = vector<vector<edge> >(N, vector<edge>());
		REP(i, M0) {
			cin>>a>>b;
			e.to=b; e.cost=1;
			G[a].PB(e);
			e.to=a;
			G[b].PB(e);
		}
		REP(i,N) {
			REP(i, N)pot[i]=1<<30;
			dijkstra(i, pot);
			REP(j,N) mx0[i] = max(mx0[i], pot[j]);
		}
		int l0=0;
		REP(i, N) l0=max(l0, mx0[i]);
		
		cin>>N1>>M1;
		N=N1;
	    G = vector<vector<edge> >(N, vector<edge>());
		REP(i, M1) {
			cin>>a>>b;
			e.to=b; e.cost=1;
			G[a].PB(e);
			e.to=a;
			G[b].PB(e);
		}
		REP(i,N) {
			REP(i, N)pot[i]=1<<30;
			dijkstra(i, pot);
//			PRINT1(pot, N);
			REP(j,N) mx1[i] = max(mx1[i], pot[j]);
		}
		int l1=0;
		REP(i, N) l1=max(l1, mx1[i]);
//		PRINT1(mx0, N0);
//		PRINT1(mx1, N1);
		
		int Mn=1<<30,Mx=0;
		REP(c0, N0) REP(c1, N1) {
			int lans = max(1 + mx0[c0] + mx1[c1], max(l0, l1));
//			cout<<c0<<" "<<c1<<" "<<lans<<endl;
			Mn=min(Mn, lans);
			Mx=max(Mx, lans);
		}
		cout<<Mn<<" "<<Mx<<endl;
	}
	
	return 0;
}
