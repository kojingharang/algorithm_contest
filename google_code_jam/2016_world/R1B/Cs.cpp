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
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }



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
			if(w<0 || !used[w] && dfs(w)) {
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
//bipartite_matching bm(M*2);
//if(lok) bm.add_edge(i, M+j);
//int matched=bm.run();

int solve(vector<string> A, vector<string> B) {
	int N = A.size();
	vector<string> VA, VB;
	REP(i, A.size()) {
		if(!count(ALL(VA), A[i])) {
			VA.PB(A[i]);
		}
		if(!count(ALL(VB), B[i])) {
			VB.PB(B[i]);
		}
	}
//	return N-max(VA.size(), VB.size());
	int V = VA.size() + VB.size();

	bipartite_matching bm(V);
	REP(i, A.size()) {
		int ia=-1, ib=-1;
		REP(j, VA.size()) if(VA[j]==A[i]) ia=j;
		REP(j, VB.size()) if(VB[j]==B[i]) ib=j;
		assert(ia!=-1 && ib!=-1);
		bm.add_edge(ia, VA.size()+ib);
	}
	int matched=bm.run();
	return N-(V-matched);
}

int naive(vector<string> A, vector<string> B) {
	int N = A.size();
	int ans = 0;
	REP(bits, 1<<N) {
		vector<vector<string>> normal, fake;
		REP(i, N) {
			if((bits>>i)&1) {
				normal.PB({A[i], B[i]});
			} else {
				fake.PB({A[i], B[i]});
			}
		}
		auto wnormal(normal);
		sort(ALL(fake));
		do {
			int ok=1;
			REP(i, fake.size()) {
				int okA=0, okB=0;
				REP(j, wnormal.size()) if(wnormal[j][0]==fake[i][0]) okA=1;
				REP(j, wnormal.size()) if(wnormal[j][1]==fake[i][1]) okB=1;
				if(okA&&okB) {
					wnormal.PB(fake[i]);
				} else {
					ok=0;
					break;
				}
			}
			if(ok) ans=max(ans, (int)fake.size());
			break;
		} while(next_permutation(ALL(fake)));
	}
	return ans;
}

int main() {
	int test_cases;
	cin>>test_cases;
	ll N;
	REP(ttt, test_cases) {
		cin>>N;
		vector<string> A(N), B(N);
		REP(i, N) {
			cin>>A[i]>>B[i];
		}
		int ans = naive(A, B);
		int tans = solve(A, B);
		DD(A);DD(B);DD(ans);DD(tans);
		assert(ans==tans);
		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		return 0;
	}
	return 0;
}



