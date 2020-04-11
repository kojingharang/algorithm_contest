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

ll hc;
void dfs2(const VVI& g, int prev, int cur) {
	hc++;
	REP(i, g[cur].size()) {
		int ne = g[cur][i];
		if(prev!=ne) {
			dfs2(g, cur, ne);
		}
	}
}

VI his1;
void dfs1(const VVI& g, int prev, int cur, int target, VI& his) {
	his.PB(cur);
	if(cur==target) {
		his1=his;
		return;
	}

	REP(i, g[cur].size()) {
		int ne = g[cur][i];
		if(prev!=ne) {
			dfs1(g, cur, ne, target, his);
		}
	}
	his.pop_back();
}

int main() {
	//ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
		VVI g(N);
		REP(i, N-1) {
			ll a, b;
			cin>>a>>b;
			a--;b--;
			g[a].PB(b);
			g[b].PB(a);
		}
		his1.clear();
		VI his;
		dfs1(g, -1, 0, N-1, his);
//		DD(his1);
		ll b=0, h=his1.size()-1;
		bool nextB = true;
		while(b+1<h) {
			if(b+1<h) b++,nextB=false;
			if(b+1<h) h--,nextB=true;
		}
//		DD(b);
//		DD(h);
		hc = 0;
		dfs2(g, his1[b], his1[h]);
//		DD(hc);
		ll restH = hc;
		ll restB = N-restH;

		string ans;
		while(1) {
			if(nextB) {
				if(restB==0) {ans = "Snuke"; break;}
				restB--;
				nextB=!nextB;
			}
			if(!nextB) {
				if(restH==0) {ans = "Fennec"; break;}
				restH--;
				nextB=!nextB;
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
