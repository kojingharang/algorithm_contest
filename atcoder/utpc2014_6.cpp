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


struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool Union(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool Find(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

struct ed {
	ll w,u,v;
};

bool operator<(const ed& a, const ed&b) {
	return a.w<b.w;
}

int main() {
	//ios::sync_with_stdio(false);
	ll N,M,Q, p, q;
	while(cin>>N>>M) {
		vector<ed> e(M);
		REP(i, M) {
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		sort(ALL(e));
		REP(i, M) cout<<e[i].u<<" -> "<<e[i].v<<endl;
		UnionFind uf(N);
		cin>>Q;
		vector<set<int> > vs(N); // node -> edges
		REP(i, M) {
			vs[e[i].u].insert(i);
			vs[e[i].v].insert(i);
		}
		REP(qi, Q) {
			cin>>p>>q;
			p=uf.root(p);
			q=uf.root(q);
			
			uf.Union(p, q);
			int root = uf.root(p);
			
			REP(i, N) cout<<" set "<<vs[i]<<endl;
			int other = root==p ? q : p;
			cout<<"join "<<p<<" "<<q<<" -> root "<<root<<endl;
			cout<<" root "<<vs[root]<<endl;
			cout<<" othe "<<vs[other]<<endl;
			FOR(ee, vs[other]) vs[root].insert(*ee);
			vs[other].clear();
			
			UnionFind luf(N);
			ll lans = 0;
			FOR(ee, vs[root]) {
				cout<<" judge connect "<<*ee<<endl;
				int i=*ee;
//				if(uf.root(e[i].u)==root && uf.root(e[i].v)==root) {
					if(luf.Union(e[i].u, e[i].v)) {
						lans += e[i].w;
					}
//				}
			}
			map<ll, ll> hi;
			REP(i, N) if(uf.root(i)==root) {
				hi[luf.root(i)]++;
			}
			if(hi.size()==1) cout<<lans<<endl;
			else cout<<"IMPOSSIBLE"<<endl;
		}
	}
	
	return 0;
}

