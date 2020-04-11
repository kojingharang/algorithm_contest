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
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

#define MOD 1000000007LL
#define INF (1LL<<60)

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

///////////////////////////// mod 上の演算

#define MAXN 200009
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


void dfs(int idx, int prev, VVI& g, VI& vis, VI& vs) {
	vis[idx]=1;
	vs.PB(idx);
	for(int i : g[idx]) if(i!=prev && !vis[i]) {
		dfs(i, idx, g, vis, vs);
	}
}

void dfs2(int idx, int prev, VVI& g, VI& vis, VI& hi, VI& loop) {
//	DD(idx);
	vis[idx]=1;
	hi.PB(idx);
	for(int i : g[idx]) if(i!=prev) {
//		DD(i);
		if(vis[i]) {
			if(loop.size()==0) {
//				DD("vis");
//				DD(hi);
				for(int j=hi.size()-1;j>=0;j--) {
					loop.PB(hi[j]);
					if(hi[j]==i) break;
				}
//				DD(loop);
			}
		} else {
			dfs2(i, idx, g, vis, hi, loop);
		}
	}
	hi.pop_back();
}

void dfs3(int idx, int prev, VVI& g, VI& P) {
	P[idx] = prev;
	for(int i : g[idx]) if(i!=prev) {
		dfs3(i, idx, g, P);
	}
}

using PLM = pair<ll, modll>;

PLM combine(PLM x, PLM y) {
	// (lx+ly)!/lx!/ly!
	ll lx = x.first;
	ll ly = y.first;
	return {lx+ly, x.second * y.second * mod_combination(lx+ly, ly)};
}

PLM dfs4(int idx, int prev, VVI& g) {
	PLM v = MP(0, modll(1));
	vector<PLM> w;
	int cnt=0;
	for(int i : g[idx]) if(i!=prev) {
		auto son = dfs4(i, idx, g);
		w.PB(son);
		v = combine(v, son);
		cnt++;
	}
	if(cnt==0) return MP(1, modll(1));
	v.first++;

//	DD("dfs4");
//	DD(idx);
//	DD(w);
//	DD(v);
	return v;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	gen_facts();
	ll N;
	while(cin>>N) {
		VI X(N*2), Y(N*2);
		REP(i, N*2) {
			cin>>X[i]>>Y[i];
			X[i]--; Y[i]--;
		}
		VVI g(N*2);
		auto add_edge = [&](int x, int y) {
			g[x].PB(y);
			g[y].PB(x);
		};
		REP(i, N*2) {
			add_edge(X[i], Y[i]+N);
		}
//		DD(g);
		VI vis(N*2);
		VVI vss;
		REP(i, N*2) if(!vis[i]) {
			VI vs;
			dfs(i, -1, g, vis, vs);
			vss.PB(vs);
		}
//		DD(vss);
		bool ok = 1;
		PLM ans = MP(0, modll(1));

		REP(i, vss.size()) {
			VI w(N*2);
			REP(j, vss[i].size()) {
				w[vss[i][j]] = 1;
			}
			ll e = 0;
			REP(i, g.size()) if(w[i]) {
				for(int j : g[i]) {
					if(w[j]) e++;
				}
			}
			e/=2;
//			DD(vss[i].size());
//			DD(e);
			if(vss[i].size()!=e) {
				ok=0;
				break;
			}

			// ループ検出
			VI vis(N*2);
			VI hi;
			VI loop;
			dfs2(vss[i][0], -1, g, vis, hi, loop);
//			DD(loop);

			// ループ以外の部分について点と辺の対応付け
			VI P(N*2);
			REP(j, loop.size()) {
				int c = loop[j];
				int n = loop[(j+1)%loop.size()];
				int p = loop[(j-1+loop.size())%loop.size()];
				for(int k : g[c]) if(k!=n&&k!=p) {
//					DD(c);
//					DD(k);
					dfs3(k, c, g, P);
				}
			}
//			DD(P);
			PLM lans = MP(vss[i].size(), modll(0));
			REP(l, 2) {
				// ループの部分について点と辺の対応付け
				REP(k, loop.size()) {
					P[loop[k]] = loop[(k+1)%loop.size()];
				}

//				DD(P);

				// 頂点の依存関係をグラフ化
				VVI g2(N*2);
				VVI g3(N*2);
				auto add_edge2 = [&](int x, int y) {
					g2[x].PB(y);
				};
				auto add_edge3 = [&](int x, int y) {
					g3[x].PB(y);
				};
				REP(j, vss[i].size()) {
					int v = vss[i][j];
					for(auto ai : g[v]) {
						if(ai < P[v]) {
							add_edge2(ai, v); // leaf -> root   v depends on ai
							add_edge3(v, ai); // root -> leaf
						}
					}
				}
//				DD(g2);
//				DD(g3);

				// 有向グラフ→その通りに並べる組み合わせ数
				// 出ていく辺がないやつはroot
				VI roots;
				REP(j, vss[i].size()) {
					int v = vss[i][j];
					if(g2[v].size()==0) roots.PB(v);
				}
//				DD(roots);

				// 木DPで各rootまで行く組み合わせ数を求め、それらのcombineを求める
				PLM a = MP(0LL, modll(1));
				for(int ri : roots) {
					PLM z = dfs4(ri, -1, g3);
//					DD(ri);
//					DD(z);
					a = combine(a, z);
				}
//				DD(a);
				lans.second += a.second;

				reverse(ALL(loop));
			}
//			DD(lans);
			ans = combine(ans, lans);
		}
//		DD(ok);
		if(!ok) ans.second = 0LL;
//		DD(ans);
		cout<<ans.second<<endl;
//		break;
	}
	return 0;
}
