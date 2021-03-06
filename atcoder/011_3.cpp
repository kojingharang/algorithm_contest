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
using namespace std;

#define EPS 1e-12
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

VVI g;
VI prev;
VI used;

int f(const string& a, const string& b) {
	int diff=0;
	REP(i, a.size()) {
		diff += a[i]!=b[i] ? 1 : 0;
		if(diff>=2) return 0;
	}
	return diff==1;
}



int main() {
	//ios::sync_with_stdio(false);
	ll N;
	string S,E;
	while(cin>>S>>E>>N) {
		N+=2;
		vector<string> w(N);
		w[0]=S;
		w[1]=E;
		REP(i, N-2) {
			cin>>w[i+2];
		}
		if(S==E) {
			cout<<0<<endl;
			cout<<S<<endl;
			cout<<E<<endl;
			continue;
		}
		//cout<<w<<endl;
		g = VVI(N, VI());
		prev = VI(N, -1);
		used = VI(N);
		REP(i, N) REP(j, N) if(f(w[i], w[j])) g[i].PB(j);
		//cout<<g<<endl;
		
		deque<int> q;
		q.PB(0);
		used[0]=1;
		int ok=0;
		while(q.size()) {
			int idx = q.front();
			q.pop_front();
			//cout<<"pop "<<idx<<endl;
			if(idx==1) {ok=1;break;}
			REP(i, g[idx].size()) {
				int nidx = g[idx][i];
				if(!used[nidx]) {
					used[nidx]=1;
					prev[nidx] = idx;
					q.PB(nidx);
				}
			}
		}
		if(ok) {
			VI rev;
			int i=1;
			while(prev[i]!=-1) {
				rev.PB(i);
				i = prev[i];
			}
			rev.PB(0);
			reverse(ALL(rev));
			cout<<rev.size()-2<<endl;
			REP(i, rev.size()) {
				cout<<w[rev[i]]<<endl;
			}
			//cout<<prev<<endl;
			//cout<<rev<<endl;
		} else {
			cout<<-1<<endl;
		}
	}
	
	return 0;
}
