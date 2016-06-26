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
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }


/*

*/
typedef VI Reach;
Reach OK = VI(1, -1);
Reach NG = VI(1, -2);
vector<vector<Reach>> rt;
VI cand(3);
VI vis;
VI memo;
int bro(int from) {
	auto Return = [&](int rv) {
//		cout<<"bro "<<from<<" -> "<<rv<<endl;
		return memo[from] = rv;
	};
	if(vis[from]) {
		return -1;
	}

//	cout<<"bro "<<from<<" vis "<<vis[from]<<endl;
	if(memo[from]!=-10) {
		return Return(memo[from]);
	}
	int ok=0;
	Reach r[3];
	REP(ci, 3) {
		r[ci] = rt[from][ci];
//		cout<<" reach of "<<cand[ci]<<": "<<r[ci]<<endl;
		if(r[ci]==NG) {
			return Return(-1);
		}
		if(r[ci]==OK) ok++;
	}
	if(ok==3) {
		return Return(1);
	}
	int mx=0;
	REP(ci, 3) {
		if(r[ci]!=OK) {
//			cout<<"bro "<<from<<" ci "<<ci<<" goto "<<r[ci]<<endl;
			int ng=0;
			int lans=100000;
			vis[from]++;
			for(auto nf : r[ci]) {
				int br = bro(nf);
				if(br==-1) ng++;
				else lans=min(lans, 1+br);
			}
			vis[from]--;
			if(ng==r[ci].size()) {
				return Return(-1);
			}
			mx=max(mx, lans);
		}
	}
//	cout<<"bro "<<from<<" -> "<<mx<<endl;
	assert(mx!=0);
	return Return(mx);
};
int main() {
	ll N, M, u, v;
	while(cin>>N>>M) {
		VVI g(N);
		rt = vector<vector<Reach>>(N, vector<Reach>(3)); // [i][j] ... reach from node i, cand[j] steps
		vis = VI(N);
		memo = VI(N, -10);
		REP(i, 3) cin>>cand[i];
		REP(i, M) {
			cin>>u>>v;
			u--;v--;
			g[u].PB(v);
		}
		auto calcReach = [&](int from, int step) {
			Reach r={from};
			REP(i, step) {
				set<ll> nxt;
				for(auto frm : r) {
					for(auto to : g[frm]) {
						nxt.insert(to);
					}
				}
				if(i==step-1 && nxt.count(N-1)) return OK;
				if(nxt.size()==0) return NG;
				r=Reach();
				for(auto v : nxt) r.PB(v);
			}
			if(r.size()==0) return NG;
			return r;
		};
		REP(i, N) REP(ci, 3) {
			rt[i][ci] = calcReach(i, cand[ci]);
			assert(rt[i][ci].size());
		}
		int ans = bro(0);
//		cout<<g<<endl;
//		cout<<rt<<endl;
		if(ans==-1) cout<<"IMPOSSIBLE"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}



