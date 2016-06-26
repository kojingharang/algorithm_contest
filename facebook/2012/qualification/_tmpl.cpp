#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
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
#define VVI vector<vector<int> >
#define PII pair<int, int> 
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



/////////////////////// [OPTION] matrix
typedef ll number;
//typedef double number;
typedef vector<number> array;
typedef vector<array> mat;
int MATRIX_MOD = 0;

mat identity(int n) {
	mat A(n, array(n));
	//for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) A[i][j] = -INF;   // e for '+'
	for (int i = 0; i < n; ++i) A[i][i] = 1;  // e for '*'
	return A;
}
number inner_product(const array &a, const array &b) {
	number ans = 0;
	for (int i = 0; i < a.size(); ++i) ans += a[i] * b[i];
	return ans;
}
array operator*(const mat &A, const array &x) {
	array y(A.size());
	for (int i = 0; i < A.size(); ++i)
		for (int j = 0; j < A[0].size(); ++j) {
			y[i] += A[i][j] * x[j];
			if(MATRIX_MOD) y[i] = y[i] % MATRIX_MOD;
		}
	return y;
}
mat operator*(const mat &A, const mat &B) {
	mat C(A.size(), array(B[0].size(), 0 /* e for '+' */));
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
	mat C(B.size(), array(B[0].size(), 0 /* e for '+' */));
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[i].size(); ++j) {
			C[i][j] = A * B[i][j];   // '+' and '*'
			if(MATRIX_MOD) C[i][j] = C[i][j] % MATRIX_MOD;
		}
	return C;
}
mat operator+(const mat &A, const mat &B) {
	mat C(A.size(), array(A[0].size(), 0 /* e for '+' */));
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[i].size(); ++j) {
			C[i][j] = A[i][j] + B[i][j];   // '+' and '*'
			//C[i][j] = max(A[i][k], B[k][j]);
			if(MATRIX_MOD) C[i][j] = C[i][j] % MATRIX_MOD;
		}
	return C;
}
// O( n^3 log e )
mat pow(const mat &A, int e) {
	return e == 0 ? identity(A.size()):
		 e % 2 == 0 ? pow(A*A, e/2) : A * pow(A, e-1);
}
mat powsum(const mat &A, int e) { // A^1+..+A^2n = (E+A^n)(A^1+..+A^n), 1+..+A(2n+1) = A(A^1+..+A^n)+A
	return e == 0 ? mat(A.size(), array(A.size())) : 
		 e % 2 == 0 ? (identity(A.size()) + pow(A, e/2)) * powsum(A, e/2) : A * powsum(A, e-1) + A;
}
bool operator==(const mat &A, const mat &B) {
	if(A.size()!=B.size()) return false;
	REP(i, A.size()) if(A[i].size()!=B[i].size()) return false;
	REP(i, A.size()) REP(j, A[i].size()) if(A[i][j]!=B[i][j]) return false;
	return true;
}
std::ostream& operator<<(std::ostream& os, const mat& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << "\n"; } return os; }
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



/////////////////////// minimumCostFlow
#define INF 1000000
typedef int Weight;
struct Edge {
  int src, dst;
  int cap;
  Weight weight;
  Edge(int src, int dst, int cap, Weight weight) :
    src(src), dst(dst), cap(cap), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

#define RESIDUE(u,v) (capacity[u][v] - flow[u][v])
#define RCOST(u,v) (cost[u][v] + h[u] - h[v])
pair<Weight, Weight> minimumCostFlow(const Graph &g, int s, int t) {
  const int n = g.size();
  Matrix capacity(n, Array(n)), cost(n, Array(n)), flow(n, Array(n));
  REP(u,n) FOR(e,g[u]) {
    capacity[e->src][e->dst] += e->cap;
    cost[e->src][e->dst] += e->weight;
  }
  pair<Weight, Weight> total; // (cost, flow)
  vector<Weight> h(n);

  for (Weight F = INF; F > 0; ) { // residual flow
    vector<Weight> d(n, INF); d[s] = 0;
    vector<int> p(n, -1);
    priority_queue<Edge> Q; // "e < f" <=> "e.cost > f.cost"
    for (Q.push(Edge(-2, s, 0, 0)); !Q.empty(); ) {
      Edge e = Q.top(); Q.pop();
      if (p[e.dst] != -1) continue;
      p[e.dst] = e.src;
      FOR(f, g[e.dst]) if (RESIDUE(f->src, f->dst) > 0) {
        if (d[f->dst] > d[f->src] + RCOST(f->src, f->dst)) {
          d[f->dst] = d[f->src] + RCOST(f->src, f->dst);
          Q.push( Edge(f->src, f->dst, 0, d[f->dst]) );
        }
      }
    }
    if (p[t] == -1) break;

    Weight f = F;
    for (int u = t; u != s; u = p[u])
      f = min(f, RESIDUE(p[u], u));
    for (int u = t; u != s; u = p[u]) {
      total.first += f * cost[p[u]][u];
      flow[p[u]][u] += f; flow[u][p[u]] -= f;
    }
    F -= f;
    total.second += f;
    REP(u, n) h[u] += d[u];
  }
  return total;
}

void add_edge(Graph& g, int s, int e, int cap, int w) {
	g[s].push_back(Edge(s, e, cap,  w));
	g[e].push_back(Edge(e, s, 0,   -w));
}
/////////////////////// minimumCostFlow



/////////////////////// 線分と線分の交差判定
int cross(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	double tc=(x1-x2)*(y3-y1)+(y1-y2)*(x1-x3);
	double td=(x1-x2)*(y4-y1)+(y1-y2)*(x1-x4);
	double ta=(x3-x4)*(y1-y3)+(y3-y4)*(x3-x1);
	double tb=(x3-x4)*(y2-y3)+(y3-y4)*(x3-x2);
	return tc*td<=0 && ta*tb<=0;
}
/////////////////////// 線分と線分の交差判定



/////////////////////// prime
int IsPrime(ll n){
	ll i;
	if(n < 2) return 0;
	else if(n == 2) return 1;
	if(n % 2 == 0) return 0;
	for(i = 3; i * i <= n; i += 2) if(n % i == 0) return 0;
	return 1;
}

#define P_SIZE 100000
char ppt[P_SIZE];
void make_prime_table() {
	memset(ppt, 1, sizeof(ppt));
	ppt[0]=ppt[1]=0;
	for(int i=2;i<P_SIZE;i++) {
		for(int j=i*2;j<P_SIZE;j+=i) {
			ppt[j] = 0;
		}
	}
}
/////////////////////// prime

/////////////////////// GCD,LCM
ll GCD( ll a, ll b ) {
	if(a<b) {
		ll tmp=a;
		a=b; b=tmp;
	}
	ll c;
	while ( a != 0 ) {
		c = a; a = b%a;  b = c;
	}
	return b;
}
ll LCM( ll a, ll b ) {
	return a/GCD(a, b)*b;
}
/////////////////////// GCD,LCM



/////////////////////// combination C
ll nCr(ll n, ll r) {
	ll ans = 1;
	REP(i, r) ans *= n-i;
	REP(i, r) ans /= i+1;
	return ans;
}
/////////////////////// combination C



/////////////////////// Split string into ints
VI split(string& s) {
	VI r;
	stringstream ss(s);
	int v;
	while(ss>>v) { r.push_back(v); }
	return r;
}
/////////////////////// Split string into ints
