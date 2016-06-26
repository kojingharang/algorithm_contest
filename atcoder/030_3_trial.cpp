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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")

#define MOD 1000000007LL
#define INF (1LL<<60)

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

bool ok;
string ans;
ll K;
string col;

string tr(vector<string>& w, int K) {
	vector<string> ss(w);
//	cout<<"src "<<ss<<endl;
	string s;
	int all = 0;
	REP(i, ss.size()) all+=ss[i].size();
	int rm = all-K;
//	cout<<rm<<endl;
	if(rm>=1) {
		ll rest=K;
		REP(i, ss.size()) {
			while(rm && ss[i].size()) {
				char ref = ss[i].back();
				ll restr = rest-ss[i].size()+1;
				// restr がこれ以降でとれて最小のchar
				char Min='{';
				RANGE(k, i+1, ss.size()) {
					ll ac_rest = 0;
					RANGE(l, k, ss.size()) ac_rest+=ss[l].size();
					if(ac_rest >= restr && ss[k][0] < Min) {
						Min = ss[k][0];
					}
				}
				bool doRM = false;
				if(ref > Min) doRM = true;
//				cout<<"Restr Min "<<Min<<" "<<restr<<endl;
				if(doRM) {
//					cout<<"rm "<<rm<<" "<<i<<" "<<ss[i]<<endl;
					ss[i].pop_back();
					rm--;
				} else break;
			}
			rest-=ss[i].size();
		}
		while(rm && ss.size() && ss.back().size()) {
			ss.back().pop_back();
			rm--;
		}
	}
//	cout<<"ss "<<ss<<endl;
	REP(i, ss.size()) s+=ss[i];
//	cout<<"rm "<<rm<<endl;
//	assert(rm<=0);	
//	assert(s.size()==K);
	return s;
}


void rec(int prev, int cur, vector<vector<int> >& g, vector<vector<int> >& scc, vector<string>& se) {
	string s;
	REP(j, scc[cur].size()) {
		int nid = scc[cur][j];
		s.PB(col[nid]);
		sort(ALL(s));
	}
	se.PB(s);
//	cout<<"vis "<<cur<<" "<<se<<endl;
	int nc = 0;
	REP(i, g[cur].size()) {
		if(prev==g[cur][i]) continue;
		vector<string> ns(se);
		rec(cur, g[cur][i], g, scc, ns);
		nc++;
	}
	if(nc==0)
	{
		vector<string> ss(se);
		string s = tr(se, K);
		s=s.substr(0, K);
		if(s.size()==K) {
//			cout<<"cand "<<s<<endl;
			if(!ok) ans=s;
			else ans = min(ans, s);
			ok=true;
		}
	}
}

string Min;
void rr(int rest, int idx, vector<string>& w, int K, string cur) {
//	cout<<"rr "<<rest<<" "<<idx<<" "<<cur<<endl;
	if(idx==w.size() || rest==0) {
		if(cur.size()==K) {
			Min = min(Min, cur);
		}
		return;
	}
	REP(use, min(rest, K)+1) {
		string ns(cur);
		ns += w[idx].substr(0, use);
		rr(rest-use, idx+1, w, K, ns);
	}
}

int main() {
	if(0) {
		REP(loop, 100) {
			ll K=4;
			vector<string> w(3, string(3, ' '));
			w[0]="adt";
			w[1]="fln";
			w[2]="brr";
			w[0]="qtz";
			w[1]="gjz";
			w[2]="qst";
	//		if(0)
			REP(i, 3) {
				REP(j, 3) w[i][j]=UNIFORM_LL(0, 26)+'a';
				sort(ALL(w[i]));
			}
			cout<<"src "<<w<<endl;
			Min = "zzzzzzzzzzzzzzzzz";
			string s;
			rr(K, 0, w, K, s);
			cout<<"ref "<<Min<<endl;
			string tt = tr(w, K);
			cout<<"try "<<tt<<endl;
			assert(tt==Min);
		}
		return 0;
	}
	
	//ios::sync_with_stdio(false);
	ll N,M;
	string s;
	while(cin>>N>>M>>K) {
//		cout<<"------------"<<endl;
		col = string(N, ' ');
		string ref(col);
		sort(ALL(ref));
		ref=ref.substr(0, K);
		
		REP(i, N) cin>>col[i];
//		cout<<col<<endl;
		SCC scc(N);
		REP(i, M) {
			ll a, b;
			cin>>a>>b;
			a--;b--;
			scc.addEdge(a, b);
		}
		scc.run();

//		cout<<"<<"<<scc.scc<<">>"<<endl;
//		cout<<""<<scc.sccID<<""<<endl;
//		cout<<"##"<<scc.sccG<<"##"<<endl;
		
		ok=false;
		ans = string(N, 'z');
		REP(i, scc.scc.size()) {
			vector<string> se;
			rec(-1, i, scc.sccG, scc.scc, se);
		}
		
		if(ok) {
			cout<<ans<<endl;
		} else {
			cout<<"-1"<<endl;
		}
	}
	
	return 0;
}
