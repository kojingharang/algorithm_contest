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
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define VVVI vector<vector<vector<ll>>>
#define VVVVI vector<vector<vector<vector<ll>>>>
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define REPR(i,n) for(int i=(int)(n)-1;0<=(i);--i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define RANGER(i,a,b) for(int i=(int)(b)-1,_a=(int)(a);(_a)<=i;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, I, J) REP(i, I) { REP(j, J) cout<<table[i][j]<<" "; cout<<"\n"; }
#define PRINT3(table, I, J, K) REP(i, I) { REP(j, J) { REP(k, K) cout<<table[i][j][k]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}



/////////////////////// Stack size ()
// https://developer.apple.com/library/mac/qa/qa1419/_index.html
// 16MB
// -Wl,-stack_size,1000000
//
// alias G++='g++ -Wall -Wl,-stack_size,10000000 -std=c++11'


// vector<int> → VI
VI toVI(vector<int> v) {
	VI w;
	REP(i, v.size()) w.PB(v[i]);
	return w;
}

/////////////////////// 各方向について何かする
int dx[]={0,1,0,-1}; int dy[]={-1,0,1,0}; // up right down left
REP(dir, 4) {
	int nx=x+dx[dir];
	int ny=y+dy[dir];
	if(IN_RANGE(nx, 0, W) && IN_RANGE(ny, 0, H)) {
	}
}
/////////////////////// 各方向について何かする




/////////////////////// SCC 強連結成分分解
struct SCC {
	vector<vector<int> > g;
	vector<vector<int> > rg;
	vector<int> vs;
	vector<bool> used;
	vector<int> sccID; // vertex id -> groupID (0, 1, ...)
	vector<vector<int> > scc; // groupID -> vertices
	vector<vector<int> > sccG; // graph of group
	SCC(int N) {
		g.resize(N);
		rg.resize(N);
		used.resize(N);
		sccID.resize(N);
	}
	void addEdge(int a, int b) { g[a].PB(b); rg[b].PB(a); }
	void dfs(int v) {
		used[v] = true;
		REP(i, g[v].size()) if(!used[g[v][i]]) dfs(g[v][i]);
		vs.PB(v);
	}
	void rdfs(int v) {
		used[v] = true;
		sccID[v] = scc.size()-1;
		scc.back().PB(v);
		REP(i, rg[v].size()) if(!used[rg[v][i]]) rdfs(rg[v][i]);
	}
	void run() {
		REP(v, g.size()) if(!used[v]) dfs(v);
		used.assign(g.size(), false);
		for(int i=vs.size()-1;i>=0;i--) if(!used[vs[i]]) { scc.PB(vector<int>()); rdfs(vs[i]); }
		
		vector<map<int, int> > h(scc.size());
		REP(i, g.size()) REP(j, g[i].size()) h[sccID[i]][sccID[g[i][j]]] = 1;
		sccG.resize(scc.size());
		REP(i, h.size()) FOR(e, h[i]) if(e->first != i) sccG[i].PB(e->first);
	}
};
/*
SCC scc(N);
REP(i, N) REP(j, N) if(G[i][j]=='Y') scc.addEdge(i, j);
scc.run();

cout<<"<<"<<scc.scc<<">>"<<endl;
cout<<""<<scc.sccID<<""<<endl;
cout<<"##"<<scc.sccG<<"##"<<endl;
*/
/////////////////////// SCC

/////////////////////// Topological sort
template <typename T>
struct TopologicalSort {
	vector<T> sorted;
	vector<bool> visited;
	vector<vector<T> > g;
	TopologicalSort(const vector<vector<T> >& g) {
		this->g = g;
		visited.resize(g.size());
		REP(i, g.size()) if(!visited[i]) dfs(i);
		reverse(ALL(sorted));
	}
	void dfs(int v) {
		visited[v]=true;
		REP(i, g[v].size()) if(!visited[g[v][i]]) dfs(g[v][i]);
		sorted.PB(v);
	}
};
/*
TopologicalSort<ll> ts(g);
cout<<ts.sorted<<endl;
*/
/////////////////////// Topological sort


/////////////////////// BIT (fenwick tree)
/*
	int N=w.size();
	BIT<int> bit(N);
	ll co=0;
	REP(i, N) {
		bit.add(w[i]-1, 1);
		co += bit.sum(w[i], N-1);
	}
	cout<<co<<endl;
*/
template<typename T>
struct BIT {
	vector<T> w;
	BIT(int N) { w = vector<T>(N); }
	// sum of w[i], i in [l, r]
	T sum(int l, int r) {
		if(l==0) {
			T s=0;
			for(;r>=0;r=(r&(r+1))-1) s+=w[r];
			return s;
		}
		return sum(0, r) - sum(0, l-1);
	}
	// i in [0, N)
	void add(int i, T v) {
		for(;i<(int)w.size();i|=i+1) w[i] += v;
	}
};

// 転倒数. i, j in [0, N) のうち i<j and d[i]>d[j] な個数
// O(NlogM) d[i] in [0, M)
template<typename T>
ll inversion_number(const vector<T>& d) {
	ll N = d.size();
	T M = *max_element(ALL(d))+1;
	BIT<T> bit(M);
	ll cnt = 0;
	for(int i=N-1;i>=0;i--) {
		cnt += bit.sum(0, d[i]-1);
		bit.add(d[i], 1);
	}
	return cnt;
}
/////////////////////// BIT (fenwick tree)


/////////////////////// 累積和
template<typename T>
class AccSum2D {
public:
	// acc[y][x] is sum of data[Y][X], Y in [0, y], X in [0, x]
	vector<vector<T>> acc;
	AccSum2D(const vector<vector<T>>& data) {
		int H=data.size();
		int W=data[0].size();
		acc = data;
		REP(y, H) REP(x, W) {
			T v = data[y][x];
			if(0<=x-1) v += acc[y][x-1];
			if(0<=y-1) v += acc[y-1][x];
			if(0<=x-1 && 0<=y-1) v -= acc[y-1][x-1];
			acc[y][x] = v;
		}
	}
	// returns sum of [x0, x1] x [y0, y1]
	T sum(ll x0, ll y0, ll x1, ll y1) {
		T v = acc[y1][x1];
		if(0<=y0-1) v -= acc[y0-1][x1];
		if(0<=x0-1) v -= acc[y1][x0-1];
		if(0<=x0-1 && 0<=y0-1) v += acc[y0-1][x0-1];
		return v;
	}
};
/*
VVI data(H, VI(W));
AccSum2D<ll> ac(data);
ll s = ac.sum(x0, y0, x1, y1);
*/
/////////////////////// 累積和


/////////////////////// iterate over all subset in bitset S
ll S = ...
for(ll a=S; a; --a & S) {
	ll b = S ^ a; // S - a
}

/////////////////////// iterate over all subset in a set

/////////////////////// prime
int is_prime(ll n){
	ll i;
	if(n < 2) return 0;
	else if(n == 2) return 1;
	if(n % 2 == 0) return 0;
	for(i = 3; i * i <= n; i += 2) if(n % i == 0) return 0;
	return 1;
}

// [a, b) の素数を求める。必要メモリ b-a 程度 (b-a がそれなりに小さければ a が 10^9 とかでもOK)
char is_prime[1000010]; // b-a
char is_prime_small[31622+10]; // sqrt(b)
void segment_sieve(ll a, ll b) {
	cout<<a<<" "<<b<<endl;
	for(int i=0; (ll)i*i<b; i++) is_prime_small[i]=1;
	for(int i=0; i<b-a; i++) is_prime[i]=1;
	for(int i=2; (ll)i*i<b; i++) {
		assert(i<(int)sizeof(is_prime_small));
		if(is_prime_small[i]) {
			for(int j=2*i; (ll)j*j<b; j+=i) is_prime_small[j]=0;
			for(ll j=max(2LL, (a+i-1)/i)*i; j<b; j+=i) is_prime[j-a] = 0;
		}
	}
}

//pair<VI, VI> factorize_p(int n, const VI& primes) { // 60(==2**2 * 3**1 * 5**1), table -> ([2,3,5], [2,1,1])   time:
//	VI pf, count;
//	REP(i, primes.size()) {
//		int co=0;
//		while(n%primes[i]==0) { n/=primes[i]; co++; }
//		if(co) { pf.push_back(primes[i]); count.push_back(co); }
//	}
//	return MP(pf, count);
//}

map<int, int> factorize(int n, const VI& primes) { // 60(==2**2 * 3**1 * 5**1), table -> ([2,3,5], [2,1,1])   time:
	map<int, int> out;
	REP(i, primes.size()) {
		int co=0;
		while(n%primes[i]==0) { n/=primes[i]; co++; }
		if(co) { out[primes[i]] = co; }
	}
	if(n>1) { out[n] = 1;}
	return out;
}

{
	int N = 50000;
	// is_prime 
	// 0 1 2 3 ...
	// 1 1 1 1 0 1 0 1 0 0 0 1 0 1 0 0 0 1 0 1 0 0 0 1 0 0 0 0 0 1 0 1 0 0 0 0 0 1 0 0 
	vector<bool> isp(N+1, true);
	RANGE(p, 2, sqrt(N)+2)if(isp[p])for(int q=p*2;q<N+1;q+=p) isp[q]=false; // <20N
}

// return all prime numbers in [0, N)  memory: O(N) time: O(NloglogN)
// make_primes(10^6+1).size() ==  78,498
// make_primes(10^7+1).size() == 664,579
VI make_primes(int N) {
	vector<bool> p(N, true);
	VI out;
	for(int i=2;i*i<=N;i++) if(p[i]) { out.PB(i); for(int j=i*2;j<N;j+=i) p[j]=false; }
	return out;
}
{
	// S in [0, N] について, S = p * q (p<=q) の全ての(p, q)に対してなにかする. 単一の S に対して約数を探すよりかなり効率がいい. <20N
	RANGE(p, 1, N+1) for(int S=p;S<N+1;S+=p) {
		int q=S/p;
		if(p<=q && !isp[p+q-1]) cnt[S]++;
	}
}

// N の約数すべてについて昇順に何かしらする. O(sqrt(N))
ll all_factors(ll N) {
	for(ll d=1; d*d<=N; d++) {
		if(N%d==0) {
			ll m = d;
			cout<<"m "<<m<<endl;
			// (ここで約数１コみつけた)
		}
	}
	ll s = sqrt(N);
	for(ll d=s*s==N?s-1:s; d>=1; d--) {
		if(N%d==0) {
			ll m = N/d;
			cout<<"m "<<m<<endl;
			// (ここで約数１コみつけた)
		}
	}
}

//static const ll MODVAL = 1000000007;
//ll MODADD(ll x, ll y) { return (x+y)%MODVAL; }
//ll MODSUB(ll x, ll y) { return (x-y+MODVAL)%MODVAL; }
//ll MODMUL(ll x, ll y) { return (x*y)%MODVAL; }
//ll MODPOW(ll x, ll e) { ll v = 1; for(;e;x=MODMUL(x,x),e>>=1) if(e&1) v = MODMUL(v, x); return v; }
//ll MODINV(ll x) { return MODPOW(x, MODVAL-2); }
//ll MODCOMB(ll n, ll r) {
//	assert(0<=n && n<MAXN);
//	assert(0<=r && r<=n);
//	return MODMUL(facts[n], MODMUL(inv_facts[r], inv_facts[n-r]));
//}

///////////////////////////// mod 上の演算
struct modll {
	static const ll MODVAL;
	ll val;
	modll() : val(0) {}
	modll(ll v) : val(v) { normalize(); }
	void normalize() { val = (val+MODVAL) % MODVAL; }
	modll  operator+ (ll v) { return modll(val+v); }
	modll& operator+=(ll v) { val+=v; normalize(); return *this; }
	modll  operator- (ll v) { return modll(val-v); }
	modll& operator-=(ll v) { val-=v; normalize(); return *this; }
	modll  operator* (ll v) { return modll(val*v); }
	modll& operator*=(ll v) { val*=v; normalize(); return *this; }
	modll  operator^ (ll e) { modll x(val); modll v(1); for(;e;x=x*x,e>>=1) if(e&1) v = v * x; return v; } // pow
	modll inv() { modll x(val); return x^(MODVAL-2); } // MODVAL must be prime number when use this!
	static modll inv(ll v) { return modll(v).inv(); }
	operator ll() { return val; }
};
const ll modll::MODVAL = 1000000007;
std::ostream& operator<<(std::ostream& os, const modll& v) { os << v.val; return os; }

//usage
modll v = modll(10000) * 4;
modll div = modll(2000) * modll(100000).inv();
ll ans = div;
///////////////////////////// mod 上の演算

#define MAXN 2300
modll facts[MAXN];
modll inv_facts[MAXN];
ll mod_combination(ll n, ll r) {
	assert(0<=n && n<MAXN); assert(0<=r && r<=n);
	return modll(facts[n]) * inv_facts[r] * inv_facts[n-r];
}
void gen_facts() {
	facts[0] = 1;
	inv_facts[0] = modll::inv(facts[0]);
	RANGE(i, 1, MAXN) facts[i] = facts[i-1] * modll(i);
	RANGE(i, 1, MAXN) inv_facts[i] = inv_facts[i-1] * modll::inv(i);
	REP(i, MAXN) assert((facts[i] * inv_facts[i])==1);
}
/////////////////////// mod 上の演算

/////////////////////// GCD,LCM
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
/////////////////////// GCD,LCM

/////////////////////// XOR 1 to N
ll cum_xor(ll n) {
	switch(n%4) {
	case 0: return n;
	case 1: return 1;
	case 2: return n+1;
	case 3: return 0;
	}
	return 0;
}
/////////////////////// XOR 1 to N



/////////////////////// combination C
ll nCr(ll n, ll r) {
	ll ans = 1;
	REP(i, r) ans *= n-i;
	REP(i, r) ans /= i+1;
	return ans;
}

#define MOD 555555555
int comb[2500][2500];
{
	// nCm = n-1Cm-1 + n-1Cm
	REP(n, 2500) comb[n][0] = 1;
	RANGE(n, 1, 2500) RANGE(m, 1, 2500) comb[n][m] = ((ll)comb[n-1][m-1] + comb[n-1][m]) % MOD;
}
/////////////////////// combination C


/////////////////////// next_combination
//VI ww(5);
//REP(i, ww.size()) ww[i] = i;
//do {
//	cout<<ww<<endl;
//} while(next_combination(ww.begin(), ww.begin()+3, ww.end()));
template<class BidirectionalIterator> 
  bool next_combination(BidirectionalIterator first1, BidirectionalIterator last1, BidirectionalIterator first2, BidirectionalIterator last2) {
      if ((first1 == last1) || (first2 == last2)) { return false; }
      BidirectionalIterator m1 = last1, m2 = last2; --m2;
      while (--m1 != first1 && !(*m1 < *m2)) {}
      bool result = (m1 == first1) && !(*first1 < *m2);
      if (!result) { while (first2 != m2 && !(*m1 < *first2)) { ++first2; } first1 = m1; std::iter_swap (first1, first2); ++first1; ++first2; }
      if ((first1 != last1) && (first2 != last2)) {      
          for (m1 = last1, m2 = first2;  (m1 != first1) && (m2 != last2); ++m2) { std::iter_swap (--m1, m2); }
          std::reverse (first1, m1); std::reverse (first1, last1); std::reverse (m2, last2); std::reverse (first2, last2);
      }
      return !result;
  }
template<class BidirectionalIterator> bool next_combination(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last) { return next_combination(first, middle, middle, last); }
/////////////////////// next_combination



/////////////////////// Split string into ints
VI split(string& s) {
	VI r;
	stringstream ss(s);
	int v;
	while(ss>>v) { r.push_back(v); }
	return r;
}
/////////////////////// Split string into ints


/////////////////////// [OPTION] Union-Find
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
// UnionFind uf(N);
// if(uf.Union(ei, ej)) ...
// if(uf.Find(ei, ej)) ...
/////////////////////// [OPTION] Union-Find

/////////////////////// Bopartite matching

/*
応用
	ビショップを互いに取れないように置く
		斜線 x+y in [0, 2N-1), (N-1-x)+y in [0, 2N-1) 同士の最大マッチングを取る。
	ルークを互いに取れないように置く
		縦横 y in [0, N), x in [0, N) 同士の最大マッチング。ただしこれは greedy で解ける。
	see GCJ 2017 Qual D
*/
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
			if(w<0 || (!used[w] && dfs(w))) {
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

//usage
bipartite_matching bm(M*2);
if(lok) bm.add_edge(i, M+j);
int matched=bm.run();
// 前半について bm.match[i]!=-1 なら bm.match[i] とマッチしている。
/////////////////////// Bopartite matching


/////////////////////// Graph (loop detection)

void get_loop_ud_sub(const VVI& g, int idx, int parent, VI& visit, VI& hi, VVI& loops) {
	//cout<<"visit "<<idx<<" "<<visit<<endl;
	hi.PB(idx);
	visit[idx] = 1;
	REP(i, g[idx].size()) {
		int adj = g[idx][i];
		if(adj==parent) continue;
		if(visit[adj]) {
			VI loop;
			for(int j=hi.size()-1; j>=0 && hi[j]!=adj; j--) loop.PB(hi[j]);
			loop.PB(adj);
			if(loop.size()>2) loops.PB(loop);
		} else {
			get_loop_ud_sub(g, adj, idx, visit, hi, loops);
		}
	}
	hi.pop_back();
}

// Get all loops of the undirected graph
VVI get_loop_ud(const VVI& g) {
	VI visit(g.size()), history;
	VVI loops;
	REP(i, g.size()) if(!visit[i]) get_loop_ud_sub(g, i, i, visit, history, loops);
	return loops;
}

void get_loop_d_sub(const VVI& g, int idx, VI& visit, VI& hi, VVI& loops) {
	//cout<<"visit "<<idx<<" "<<visit<<endl;
	hi.PB(idx);
	visit[idx] = 1;
	REP(i, g[idx].size()) {
		int adj = g[idx][i];
		if(visit[adj]==1) {
			VI loop;
			//cout<<"HI "<<hi<<endl;
			for(int j=hi.size()-1; j>=0 && hi[j]!=adj; j--) loop.PB(hi[j]);
			loop.PB(adj);
			reverse(ALL(loop));
			loops.PB(loop);
		} else if(visit[adj]==0) {
			get_loop_d_sub(g, adj, visit, hi, loops);
		}
	}
	visit[idx] = 2;
	hi.pop_back();
}

// Get all loops of the undirected graph
VVI get_loop_d(const VVI& g) {
	VI visit(g.size()), history;
	VVI loops;
	REP(i, g.size()) if(visit[i]==0) get_loop_d_sub(g, i, visit, history, loops);
	return loops;
}

// Case directed==0: edges==[0, 1, 2, 3] (means graph 0--1 2--3) -> [[1], [0], [3], [2]]
// Case else:        edges==[0, 1, 2, 3] (means graph 0->1 2->3) -> [[1], [], [3]]
VVI make_graph_from_edge(VI edges, int directed) {
	VVI g;
	REP(i, edges.size()/2) {
		int a=edges[i*2], b=edges[i*2+1];
		REP(j, directed ? 1 : 2) {
			while(a >= (int)g.size()) g.push_back(VI());
			g[a].push_back(b);
			swap(a, b);
		}
	}
	return g;
}

void test_graph_loop() {
	// 1 -> 2 -> 0 -> 3 -> 4 -> 2
	// 5 -> 6 -> 5
	int edges_raw[] = { 1,2,   2,0,   0,3,   3,4,   4,2,   5,6,   6,5,   7,8,   8,9,   9,7, };
	VI edges = VI(&edges_raw[0], &edges_raw[sizeof(edges_raw)/sizeof(edges_raw[0])]);
	{
		VVI g = make_graph_from_edge(edges,0);
		cout<<"Graph"<<endl;
		cout<<g<<endl;
		cout<<"loop of undirected graph"<<endl;
		cout<<get_loop_ud(g)<<endl;
	}
	{
		VVI g = make_graph_from_edge(edges, 1);
		cout<<"Graph"<<endl;
		cout<<g<<endl;
		cout<<"loop of directed graph"<<endl;
		cout<<get_loop_d(g)<<endl;
	}
}

/////////////////////// Graph (loop detection)





/////////////////////// [OPTION] matrix
typedef ll number;
//typedef double number;
typedef vector<number> Array;
typedef vector<Array> mat;
int MATRIX_MOD = 0;
 
mat identity(int n) {
    mat A(n, Array(n));
    //for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) A[i][j] = -INF;   // e for '+'
    for (int i = 0; i < n; ++i) A[i][i] = 1;  // e for '*'
    return A;
}
number inner_product(const Array &a, const Array &b) {
    number ans = 0;
    for (int i = 0; i < a.size(); ++i) ans += a[i] * b[i];
    return ans;
}
Array operator*(const mat &A, const Array &x) {
    Array y(A.size());
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A[0].size(); ++j) {
            y[i] += A[i][j] * x[j];
            if(MATRIX_MOD) y[i] = y[i] % MATRIX_MOD;
        }
    return y;
}
mat operator*(const mat &A, const mat &B) {
    mat C(A.size(), Array(B[0].size(), 0 /* e for '+' */));
    for (int i = 0; i < C.size(); ++i)
        for (int j = 0; j < C[i].size(); ++j)
            for (int k = 0; k < A[i].size(); ++k) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];   // '+' and '*'
                //C[i][j] = max(C[i][j], A[i][k] + B[k][j]);
                if(MATRIX_MOD) C[i][j] = C[i][j] % MATRIX_MOD;
            }
    return C;
}
mat operator*(const number &A, const mat &B) {
    mat C(B.size(), Array(B[0].size(), 0 /* e for '+' */));
    for (int i = 0; i < C.size(); ++i)
        for (int j = 0; j < C[i].size(); ++j) {
            C[i][j] = A * B[i][j];   // '+' and '*'
            if(MATRIX_MOD) C[i][j] = C[i][j] % MATRIX_MOD;
        }
    return C;
}
mat operator+(const mat &A, const mat &B) {
    mat C(A.size(), Array(A[0].size(), 0 /* e for '+' */));
    for (int i = 0; i < C.size(); ++i)
        for (int j = 0; j < C[i].size(); ++j) {
            C[i][j] = A[i][j] + B[i][j];   // '+' and '*'
            //C[i][j] = max(A[i][k], B[k][j]);
            if(MATRIX_MOD) C[i][j] = C[i][j] % MATRIX_MOD;
        }
    return C;
}
// O( n^3 log e )
mat pow(const mat &A, ll e) {
    return e == 0 ? identity(A.size()):
         e % 2 == 0 ? pow(A*A, e/2) : A * pow(A, e-1);
}
mat powsum(const mat &A, ll e) { // A^1+..+A^2n = (E+A^n)(A^1+..+A^n), 1+..+A(2n+1) = A(A^1+..+A^n)+A
    return e == 0 ? mat(A.size(), Array(A.size())) : 
         e % 2 == 0 ? (identity(A.size()) + pow(A, e/2)) * powsum(A, e/2) : A * powsum(A, e-1) + A;
}
bool operator==(const mat &A, const mat &B) {
    if(A.size()!=B.size()) return false;
    REP(i, A.size()) if(A[i].size()!=B[i].size()) return false;
    REP(i, A.size()) REP(j, A[i].size()) if(A[i][j]!=B[i][j]) return false;
    return true;
}
std::ostream& operator<<(std::ostream& os, const mat& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << "\n"; } return os; }

/*
MATRIX_MOD = 10000;
// [列]
Array a = {0, 1};
// [行][列]
mat A = {{0, 1}, {1, 1}};
Array b = pow(A, n) * a;
// Fib n
// (n  ) = (0 1)^n (0)
// (n+1)   (1 1)   (1)
*/
/////////////////////// [OPTION] matrix



/////////////////////// [OPTION] Topological sorting with cycle checker
typedef vector<int> Edge;
typedef vector<Edge> Graph;
bool tsort(Graph& g, int i, vector<int>& status, vector<int>& topo) {
	status[i]=1;
	for(int j=0;j<g[i].size();j++) {
		if(status[g[i][j]]==1) return false;
		if(!status[g[i][j]] && !tsort(g, g[i][j], status, topo)) return false;
	}
	topo.push_back(i);
	status[i]=2;
	return true;
}
bool tsort(Graph& g) {
	int vn = g.size();
	vector<int> status(vn, 0), topo;
	for(int i=0;i<vn;i++) {
		if(!status[i] && !tsort(g, i, status, topo)) return false;
	}
	return true;
}
/////////////////////// [OPTION] Topological sorting with cycle checker


/////////////////////// [OPTION] maximumFlow
#define INF 1000000
typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Weight maximumFlow(const Graph &g, int s, int t) {
  int n = g.size();
  Matrix flow(n, Array(n)), capacity(n, Array(n));
  REP(u,n) FOR(e,g[u]) capacity[e->src][e->dst] += e->weight;

  Weight total = 0;
  while (1) {
    queue<int> Q; Q.push(s);
    vector<int> prev(n, -1); prev[s] = s;
    while (!Q.empty() && prev[t] < 0) {
      int u = Q.front(); Q.pop();
      FOR(e,g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
        prev[e->dst] = u;
        Q.push(e->dst);
      }
    }
    if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
    Weight inc = INF;
    for (int j = t; prev[j] != j; j = prev[j])
      inc = min(inc, RESIDUE(prev[j], j));
    for (int j = t; prev[j] != j; j = prev[j])
      flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
    VI path;
    for (int j = t; prev[j] != j; j = prev[j]) path.push_back(j);
    path.push_back(s);
    reverse(ALL(path));
    total += inc;
    cout<<"Update "<<path<<" -> total "<<total<<endl;
  }
}
void add_edge(Graph& g, int s, int e, int w) {
	g[s].push_back(Edge(s, e, w));
	g[e].push_back(Edge(e, s, 0));
}
/////////////////////// maximumFlow

/////////////////////// maximumFlow(Dinic)
// O(|E| |V|^2)だが実際はもっと速い.
class Dinic {
public:
	struct Edge {
		int to;
		ll cap;
		int rev;
	};
	int N;
	vector<vector<Edge>> g, orig;
	vector<int> level, iter;
	Dinic(int N) : N(N) {
		g = vector<vector<Edge>>(N);
		level = vector<int>(N);
		iter = vector<int>(N);
	}
	void add_edge(int from, int to, ll cap) {
		g[from].push_back(Edge{to, cap, (int)g[to].size()});
		g[to].push_back(Edge{from, 0, (int)g[from].size()-1});
	}
	void bfs(int s) {
		level.assign(N, -1);
		queue<int> q;
		level[s] = 0;
		q.push(s);
		while(!q.empty()) {
			int v = q.front(); q.pop();
			for(int i=0;i<g[v].size(); i++) {
				Edge& e = g[v][i];
				if(e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
	}
	ll dfs(int v, int t, ll f) {
		if(v==t) return f;
		for(int& i=iter[v]; i<g[v].size(); i++) {
			Edge& e = g[v][i];
			if(e.cap > 0 && level[v] < level[e.to]) {
				ll d = dfs(e.to, t, min(f, e.cap));
				if(d > 0) {
					e.cap -= d;
					g[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		orig = g;
		ll flow = 0;
		ll INF = 1LL<<60;
		for(;;) {
			bfs(s);
			if(level[t] < 0) {
				REP(i, N) {
					REP(j, g[i].size()) {
						orig[i][j].cap = max(0LL, orig[i][j].cap - g[i][j].cap);
					}
				}
				return flow;
			}
			iter.assign(N, 0);
			int f;
			while((f=dfs(s, t, INF)) > 0) flow += f;
		}
		return -1;
	}
};
ostream& operator<<(ostream& os, const Dinic::Edge& e) {
	os<<"(Edge) to "<<e.to<<" cap "<<e.cap<<" rev "<<e.rev<<endl;
	return os;
}

void dinicTest() {
	// verified with:
	// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
	ll V, E, u, v, c;
	cin>>V>>E;
	Dinic d(V);
	REP(i, E) {
		cin>>u>>v>>c;
		d.add_edge(u, v, c);
	}
	DD(d.g);
	ll ans = d.max_flow(0, V-1);
	cout<<ans<<endl;
	DD(d.level);
	DD(d.iter);
	DD(d.g);
	DD(d.orig);
	// d.orig[i][j].cap ... flow in node i -> d.orig[i][j].to
//	REP(i, d.g.size()) {
//		for(auto& e : d.g[i]) {
//			DD(e);
//		}
//	}
}
/////////////////////// maximumFlow(Dinic)


/////////////////////// minimumCostFlow
using Flow = int;
using Cost = int;
const int MAX_V = 100000;
const Cost INF = std::numeric_limits<Cost>::max() / 8;

struct PrimalDual {
    struct Edge {
        int d;
        Flow c, f;
        Cost w;
        int r, is_r;
        Edge(int d_, Flow c_, Flow f_, Cost w_, int r_, bool is_r_)
            : d(d_), c(c_), f(f_), w(w_), r(r_), is_r(is_r_) {}
    };

    int n;
    std::vector<std::vector<Edge> > g;
    PrimalDual(int n_) : n(n_), g(std::vector<std::vector<Edge> >(n_)) {}

    void add_edge(int src, int dst, Flow cap, Cost cost) {  // 有向辺
        int rsrc = g[dst].size();
        int rdst = g[src].size();
        g[src].emplace_back(dst, cap, 0, cost, rsrc, false);
        g[dst].emplace_back(src, cap, cap, -cost, rdst, true);
    }

	// f 流した時の最小コストをかえす
    Cost solve(int s, int t, Flow f) {
        Cost res = 0;

        static Cost h[MAX_V + 10], dist[MAX_V];
        static int prevv[MAX_V + 10], preve[MAX_V + 10];
        // std::vector<Cost> h(g.size()), dist(g.size());
        // std::vector<int> prevv(g.size()), preve(g.size());

        using pcv = std::pair<Cost, int>;
        std::priority_queue<pcv, std::vector<pcv>, std::greater<pcv> > q;
        std::fill(h, h + n, 0);
        while (f > 0) {
            std::fill(dist, dist + n, INF);
            dist[s] = 0;
            q.emplace(0, s);
            while (q.size()) {
                Cost cd;
                int v;
                std::tie(cd, v) = q.top();
                q.pop();
                if (dist[v] < cd) continue;
                for (int i = 0; i < (int)(g[v].size()); ++i) {
                    Edge &e = g[v][i];
                    if (residue(e) == 0) continue;
                    if (dist[e.d] + h[e.d] > cd + h[v] + e.w) {
                        dist[e.d] = dist[v] + e.w + h[v] - h[e.d];
                        prevv[e.d] = v;
                        preve[e.d] = i;
                        q.emplace(dist[e.d], e.d);
                    }
                }
            }

            if (dist[t] == INF) return -1;  // 経路が見つからなかった

            // s-t 間最短路に沿って目一杯流す
            for (int i = 0; i < n; ++i) h[i] += dist[i];
            Flow d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = std::min(d, residue(g[prevv[v]][preve[v]]));
            }
            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                Edge &e = g[prevv[v]][preve[v]];
                e.f += d;
                g[v][e.r].f -= d;
            }
        }
        return res;
    }

    Flow residue(const Edge &e) { return e.c - e.f; }

    // 流量を表示
    void show() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (int)(g[i].size()); ++j) {
                Edge &e = g[i][j];
                if (e.is_r) continue;
                printf("%3d->%3d (flow:%d)\n", i, e.d, e.f);
            }
        }
    }
};
/////////////////////// minimumCostFlow



/////////////////////// 線分(x1, y1)-(x2, y2)と線分(x3, y3)-(x4, y4)の交差判定

struct P {
	double x, y;
};
ostream& operator<<(ostream& os, const P& p) {
	os<<"("<<p.x<<" "<<p.y<<")";
	return os;
}

pair<bool, P> intersection(P p1, P p2, P p3, P p4) {
	double d = (p2.x - p1.x)*(p4.y - p3.y) - (p2.y - p1.y)*(p4.x - p3.x);
//	DD(d);
	if (fabs(d) < EPS) {
		// parallel lines
		return make_pair(false, P{0, 0});
	}
	double u = ((p3.x - p1.x)*(p4.y - p3.y) - (p3.y - p1.y)*(p4.x - p3.x))/d;
	double v = ((p3.x - p1.x)*(p2.y - p1.y) - (p3.y - p1.y)*(p2.x - p1.x))/d;
//	DD(u);
//	DD(v);
	if (u < 0.0 || u > 1.0)
		// intersection point not between p1 and p2
		return make_pair(false, P{0, 0});
	if (v < 0.0 || v > 1.0)
		// intersection point not between p3 and p4
		return make_pair(false, P{0, 0});
	return make_pair(true, P{p1.x + u * (p2.x - p1.x), p1.y + u * (p2.y - p1.y)});
}

/*
int intersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	// この最初のチェックがないと、(0, 0)-(10, 0) と (11, 0)-(12, 0) が交差と判定されてしまう。
	if(max(x1, x2) < min(x3, x4)) return 0;
	if(max(x3, x4) < min(x1, x2)) return 0;
	if(max(y1, y2) < min(y3, y4)) return 0;
	if(max(y3, y4) < min(y1, y2)) return 0;
	
	ll tc=(x1-x2)*(y3-y1)+(y1-y2)*(x1-x3);
	ll td=(x1-x2)*(y4-y1)+(y1-y2)*(x1-x4);
	ll ta=(x3-x4)*(y1-y3)+(y3-y4)*(x3-x1);
	ll tb=(x3-x4)*(y2-y3)+(y3-y4)*(x3-x2);
//	cout<<"XX "<<ta<<" "<<tb<<" "<<tc<<" "<<td<<endl;
	return tc*td<=0 && ta*tb<=0; // 接するときも交差とする
}

int intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	double tc=(x1-x2)*(y3-y1)+(y1-y2)*(x1-x3);
	double td=(x1-x2)*(y4-y1)+(y1-y2)*(x1-x4);
	double ta=(x3-x4)*(y1-y3)+(y3-y4)*(x3-x1);
	double tb=(x3-x4)*(y2-y3)+(y3-y4)*(x3-x2);
	return tc*td<=0 && ta*tb<=0;
}
*/
/////////////////////// 線分と線分の交差判定




/////////////////////// Dijkstra
struct Dijkstra {
	struct edge{int to; ll cost;};
	vector<vector<edge> > G;
	vector<ll> V;
	const ll Max = 1LL<<60;
	Dijkstra(int N) {
		G = vector<vector<edge> >(N);
		V = vector<ll>(N, Max);
	}
	void add_edge(int v0, int v1, ll cost) {
		if(v0<G.size() && v1<G.size()) G[v0].PB((edge){v1, cost});
	}
	ll run(int S, int E) {
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
		return V[E]==Max?-1:V[E];
	}
};

/*
Dijkstra d(V);
// have, clipboard
REP(i, n) REP(j, n) {
    d.add_edge(i*n+j, i*n+i, 1); // copy
    d.add_edge(i*n+j, (i+j)*n+j, 1); // paste
    d.add_edge(i*n+j, (i-1)*n+j, 1); // delete
}
d.run(1*n+0, -1);
*/
/////////////////////// Dijkstra


/////////////////////// 座標圧縮
VI compress(VI v) {
	VI w;
	REP(i, v.size()) RANGE(r, -1, 2) w.PB(v[i]+r);
	sort(ALL(w));
	w.erase(unique(ALL(w)), w.end());
	return w;
}
/////////////////////// 座標圧縮



/////////////////////// Segment Tree / Range minimum query (RMQ)
struct Gcd {
	typedef ll valueType;
	static ll e() {
		return 0;
	}
	static ll op(ll a, ll b) {
		if(a==e()) return b;
		if(b==e()) return a;
		return __gcd(llabs(a), llabs(b));
	}
};

struct Add {
	typedef ll valueType;
	static ll e() {
		return 0;
	}
	static ll op(ll a, ll b) {
		return a+b;
	}
};

struct Min {
	typedef ll valueType;
	static ll e() {
		return 1LL<<60;
	}
	static ll op(ll a, ll b) {
		return min(a, b);
	}
};

template<typename Traits>
class SegTree {
public:
	typedef typename Traits::valueType T;
	int N;
	vector<T> dat;
	SegTree(int _N) {
		N=1; while(N<_N) N*=2;
		dat = vector<T>(2*N, Traits::e());
	}
	// idx is 0 base
	void update(int idx, T v) {
		idx += N-1;
		dat[idx] = v;
		while(idx>0) {
			idx = (idx-1)/2;
			dat[idx] = Traits::op(dat[idx*2+1], dat[idx*2+2]);
		}
	}
	// [a, b)
	T query(int a, int b) { return query(a, b, 0, 0, N); }
	T query(int a, int b, int k, int l, int r) {
		if(r<=a || b<=l) return Traits::e();
		if(a<=l && r<=b) return dat[k];
		else {
			T vl = query(a, b, k*2+1, l, (l+r)/2);
			T vr = query(a, b, k*2+2, (l+r)/2, r);
			return Traits::op(vl, vr);
		}
	}
};
/*
SegTree<Gcd> st(N+1);
SegTree<Add> cum(N+1);
cum.update(i, diff[i]);
ll head = cum.query(0, L+1);
*/
/////////////////////// Segment Tree


/////////////////////// Simplex (最適な変数の値も返す)
typedef double Num; typedef vector<Num> Vec; typedef vector<Vec> Mat;
const Num Inf = numeric_limits<Num>::infinity();
const Num NoSolution = numeric_limits<Num>::quiet_NaN();
#define IsSolution(x) (x == x)
const Num EPS = 1e-10;

// Maximize: c * x
// A * x <= b
// x     >= 0
// A : Mat[constraints][vars]
// b : Vec[constraints]
// c : Vec[vars]
// return: score, vars
// see https://www.sist.ac.jp/~suganuma/kougi/other_lecture/SE/opt/linear/linear.htm
// see GCJ 2017 qual D
pair<Num, Vec> simplex(const Mat& A, const Vec& b, const Vec& c) {
	const int m = A.size(), n = A[0].size();
	Mat D(m+1, Vec(n+1)); vi id(n+m+1);
	rer(i, 0, n+m) id[i] = i;
	rep(i, m) {
		rep(j, n) D[i][j] = -A[i][j];
		D[i][n] = b[i];
	}
	Vec names(m);
	REP(i, m) names[i] = n+i;

//	DD(id);
//	DD(names);
//	DD(D);

	rep(j, n) D[m][j] = c[j];
	while(1) {
//		DD(id);
//		DD(names);
//		DD(D);
		int r = m, s = n+m;
		rep(i, m) if(D[i][n] < -EPS && id[n+r] > id[n+i]) r = i;
		rep(j, n) if(D[m][j] > EPS && id[s] > id[j]) s = j;
		if(r == m && s == n + m) break;
		if(id[n + r] < id[s]) {
			s = n + m;
			rep(j, n) if(D[r][j] > EPS && id[s] > id[j]) s = j;
		}else {
			r = m;
			rep(i, m) if(D[i][s] < -EPS && id[n+r] > id[n+i]) r = i;
		}
		if(r == m) { /* Unbounded */ return make_pair<Num, Vec>(-7777, {}); }
		if(s == n + m) { /* NoSolution */ return make_pair<Num, Vec>(-7777, {}); }

//		DD(r);
//		DD(s);

		// r: 行 s: 列
		names[r] = id[s];

		swap(id[s], id[n+r]);
		D[r][s] = 1. / D[r][s];
		rer(j, 0, n) if(j != s) D[r][j] *= -D[r][s];
		rer(i, 0, m) if(i != r && abs(D[i][s]) > EPS) {
			rer(j, 0, n) if(j != s) D[i][j] += D[r][j] * D[i][s];
			D[i][s] *= D[r][s];
		}
	}
//	DD(id);
//	DD(names);
//	DD(D);
	Vec vs(n);
	REP(i, m) {
//		DD(names[i]);
//		DD(D[i][n]);
		if(names[i]<n) vs[names[i]] = D[i][n];
//		if(id[i]<m) vs[i] = D[id[i]][n];
	}
//	DD(vs);
	return make_pair(D[m][n], vs);
}
/////////////////////// Simplex



/////////////////////// しゃくとり法
// check : bool(int S, int E) ... [S, E] である条件が成り立つかどうかを返す.
// onMove : void(int index, int sign) ... sign=1 : index 要素が範囲に入った sign=-1 : 出た
void syakutori(int N, function<bool(int, int)> check, function<void(int, int)> onMove) {
	int hd = 0, tl = -1; // [hd, tl]
	REP(hd, N) {
		// assert !check
		while(tl<N && !check(hd, tl)) tl++, onMove(tl, 1);
		// assert check
		onMove(hd, -1);
	}
}
/////////////////////// しゃくとり法



/////////////////////// 文字列のユニークな部分列の個数についてのDP
// validated with Typical DP Contest G - 辞書順
// https://tdpc.contest.atcoder.jp/tasks/tdpc_lexicographical
template<typename T>
class SubSeq {
public:
	// ユニークな部分列すべて(naive)
	T countUniqNaive(const string& S) {
		auto se = set<string>();
		REP(bi, 1<<S.size()) {
			string s;
			REP(i, S.size()) if(bi>>i&1) s.PB(S[i]);
			se.insert(s);
		}
		elements = vector<string>(ALL(se));
//		DD(elements);
		REP(i, elements.size()) cout<<i<<" "<<elements[i]<<endl;
		return T(se.size());
	}
	VVI next;
	vector<T> dp;
	void genNext(const string& S) {
		ll N = S.size();
		// [i][ci] : i <= j に対して S[j]==ci+'a' となる最小の j. なければ N
		next = VVI(N+1, VI(26, N));
		for(int i=N-1;0<=i;i--) {
			REP(ci, 26) next[i][ci] = next[i+1][ci];
			next[i][S[i]-'a'] = i;
		}
//		DD(next);
	}
	// ユニークな部分列すべて
	T countUniqR(const string& S, T upto=1LL<<62) {
		ll N = S.size();
		genNext(S);
		// [i] : S[i-1] は使うとして, S[idx] : idx in [i-1, N) までで何通りあるか
		// 最低1通りはある
		dp = vector<T>(N+1, T(1LL));
		for(int i=N;0<=i;i--) {
			REP(ci, 26) {
				ll I = i-1; // 今見てるのは S[I]
				// 今見てるとこの次以降の ci のところから持ってくる
				if(next[I+1][ci] < N) {
					dp[i] += dp[next[I+1][ci]+1];
					dp[i] = min(dp[i], upto);
//					cout<<i<<" ("<<dp[i]<<")"<<" += "<<next[i][ci]+1<<endl;
				}
			}
//			DD(dp);
		}
		return dp[0];
	}
};
cout<<SubSeq<ll>().countUniqR("abcbc")<<endl;
cout<<SubSeq<ll>().countUniqNaive("abcbc")<<endl;
/////////////////////// 文字列のユニークな部分列の個数についてのDP
