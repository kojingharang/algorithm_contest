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
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}

#define MOD 1000000007LL
#define INF (1LL<<60)

struct modll {
	static const ll MODVAL;
	ll val;
	modll() : val(0) {}
	modll(ll v) : val(v) { normalize(); }
	void normalize() { val = (val+MODVAL) % MODVAL; }
//	modll  operator+ (ll v) const { return modll(val+v); }
	modll  operator+ (modll v) const { return modll(val+v); }
	modll& operator+=(ll v) { val+=v; normalize(); return *this; }
	modll  operator- (ll v) { return modll(val-v); }
	modll& operator-=(ll v) { val-=v; normalize(); return *this; }
	modll  operator* (const modll v) const { return modll(val)*v; }
//	modll  operator* (ll v) { return modll(val*v); }
	modll& operator*=(ll v) { val*=v; normalize(); return *this; }
	modll  operator^ (ll e) { modll x(val); modll v(1); for(;e;x=x*x,e>>=1) if(e&1) v = v * x; return v; } // pow
	modll inv() { modll x(val); return x^(MODVAL-2); } // MODVAL must be prime number when use this!
	static modll inv(ll v) { return modll(v).inv(); }
	operator ll() { return val; }
};
const ll modll::MODVAL = 1000000007;
std::ostream& operator<<(std::ostream& os, const modll& v) { os << v.val; return os; }


VI vis;
ll cnt;
VVI g;
void dfs(ll prev, ll cur, ll dest) {
	if(cur==dest) cnt++;
	vis[cur] = 1;
	for(ll n : g[cur]) if(prev!=n && !vis[n]) {
		dfs(cur, n, dest);
	}
	vis[cur] = 0;
}
// s->e が何通りあるか
ll countWaysNaive(VVI& g, ll S, ll E) {
	cnt = 0;
	vis = VI(g.size());
	dfs(-1, 0, 1);
	return cnt;
}

// s->e が何通りあるか
ll countWays(VVI& g, ll S, ll E) {
	ll N = g.size();
	vector<vector<modll>> dp(N, vector<modll>(1<<N));
	dp[S][1<<S] = 1;
	REP(bi, 1<<N) REP(last, N) if(dp[last][bi]) {
		for(ll nxt : g[last]) if((bi>>nxt&1)==0) {
			ll nbi = bi | 1<<nxt;
			dp[nxt][nbi] += dp[last][bi];
		}
	}
	modll ans = 0;
	REP(bi, 1<<N) ans += dp[E][bi];
	return ans;
}

/*
サイズ nv の完全グラフで 0->1 に行く方法が何通りあるか
http://oeis.org/A000522
nv: 2
countWays(g, 0, 1): 1
nv: 3
countWays(g, 0, 1): 2
nv: 4
countWays(g, 0, 1): 5
nv: 5
countWays(g, 0, 1): 16
nv: 6
countWays(g, 0, 1): 65
nv: 7
countWays(g, 0, 1): 326
nv: 8
countWays(g, 0, 1): 1957
nv: 9
countWays(g, 0, 1): 13700
nv: 10
countWays(g, 0, 1): 109601
nv: 11
countWays(g, 0, 1): 986410
nv: 12
countWays(g, 0, 1): 9864101
nv: 13
countWays(g, 0, 1): 108505112
nv: 14
countWays(g, 0, 1): 1302061345
nv: 15
countWays(g, 0, 1): 16926797486
nv: 16
countWays(g, 0, 1): 236975164805
dfsだと nv=12あたりで数十秒
*/
void test() {
	RANGE(nv, 2, 17) {
		g = VVI(nv);
		REP(i, nv) REP(j, nv) if(i!=j) g[i].PB(j);
		DD(nv);
		DD(countWaysNaive(g, 0, 1));
		DD(countWays(g, 0, 1));
	}
}


typedef ll number;
//typedef modll number;
//typedef double number;
typedef vector<number> Array;
typedef vector<Array> mat;
//int MATRIX_MOD = 0;
int MATRIX_MOD = 1000000007;
 
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


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
//	test();return 0;

	ll H,N,V;
	while(cin>>H>>N) {
		VVI g(N);
		REP(i, N) REP(j, N) {
			cin>>V;
			if(V) g[i].PB(j);
		}
		
		VVI m(N, VI(N));
		REP(i, N) REP(j, N) m[i][j] = countWays(g, i, j);
//		DD(m);
		mat mh = pow(m, H);
		
		cout<<mh[0][0]<<endl;
	}
	
	return 0;
}
