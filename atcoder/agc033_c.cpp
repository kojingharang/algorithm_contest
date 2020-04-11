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
#define REP(i,n) for(ll i=0,_n=(n);(i)<(ll)_n;++i)
#define REPR(i,n) for(ll i=(ll)(n)-1;0<=(i);--i)
#define RANGE(i,a,b) for(ll i=(ll)a,_b=(ll)(b);(i)<_b;++i)
#define RANGER(i,a,b) for(ll i=(ll)(b)-1,_a=(ll)(a);(_a)<=i;--i)
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
#define FI first
#define SE second
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

/*
どの時点でも、コインがある頂点からなる木は常に連結
コインを何枚取るかは無関係なので状態としてはコインの有無(T/F)だけ考えればよい
vからとった場合、そこから見てTな葉がすべてFになる
Tな葉の数は単調減少
ある木で考えた場合、各ノードに対する操作は上(root方向への移動)か下(leaf方向への移動)にわけられる
	上の場合各ノードの子だけが影響する
	下の場合各ノードの子以外だけが影響する
各ノード, 上下ごとに「何回操作するとFになるか」が決まる
あるノードを選んだ場合、Tはいくつ減るか?
	Tな葉の場合Tな葉の個数-1
	else Tな葉の個数


状態遷移木を考えて、葉からFirstかSecondか決めていき根の値が答え。
問題は状態が大きいのと遷移が多い
*/
PII dfs(ll prev, ll cur, VVI& g) {
	PII r = MP(0, cur);
	for(ll nxt : g[cur]) if(nxt!=prev) {
		PII t = dfs(cur, nxt, g);
		t.first++;
		if(r.first < t.first) r = t;
	}
	return r;
}
ll treeDiameter(VVI& g) {
	PII a = dfs(-1, 0, g);
	PII b = dfs(-1, a.second, g);
	return b.first;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,A,B;
	while(cin>>N) {
		VVI g(N);
		REP(i, N-1) {
			cin>>A>>B;
			A--;B--;
			g[A].PB(B);
			g[B].PB(A);
		}
//		DD(g);
		ll d = treeDiameter(g);
//		DD(d);
		string ans = d%3==1 ? "Second" : "First";
		cout<<ans<<endl;
	}
	
	return 0;
}
