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
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

int N, M, L;
VI fr, to;
VI fin;
map<VI, bool> memo;

int f(const VI& st) {
	memo[st]=1;
	int yet = 0;
	VI yets;
	REP(i, N) {
		if(st[i]!=-1 && st[i]!=fin[i]) {
			yet++;
			yets.PB(st[i]);
		}
	}
	cout<<"yets "<<yets<<endl;
	if(yet==0) return 0;
	int minans = 100000;
	REP(pat, 1<<yet) {
		if(POPCOUNT(pat)!=M) continue;
		VI nst(st);
		REP(y, yet) {
			if((pat>>y)&1) {
				// move
				REP(i, N) {
					if(nst[i]==yets[y]) nst[i]=-1;
				}
			}
		}
		// put
		int ok=1;
		VI done(yets.size(), 0);
		REP(y, yet) {
			if((pat>>y)&1) {
				REP(i, N) {
					if(nst[i]==-1 && fin[i]==yets[y]) {
						nst[i]=yets[y];
						done[y]=1;
					}
				}
			}
		}
		REP(y, yet) {
			if(done[y]) continue;
			if((pat>>y)&1) {
				int lok=0;
				REP(i, N) {
					if(nst[i]==-1 && st[i]!=yets[y]) lok=1, nst[i]=yets[y];
				}
				if(!lok) {ok=0;break;}
			}
		}
		if(!ok) continue;
		
		cout<<"BE "<<st<<endl;
		cout<<"AF "<<nst<<endl;
		if(!memo.count(nst)) {
			int ans = f(nst);
			minans = min(minans, 10+ans);
		}
	}
	return minans;
}

int main() {
	ios::sync_with_stdio(false);
	while(cin>>N>>M>>L) {
		memo.clear();
		fr=VI(L);
		to=VI(L);
		VI st(N, -1);
		fin=VI(N, -1);
		REP(i, L) {
			cin>>fr[i]>>to[i];
			st[fr[i]-1]=i;
			fin[to[i]-1]=i;
		}
		//cout<<st<<endl;
		//cout<<fin<<endl;
		if(L<=M) { cout<<10<<endl; continue; }
		
		int ans = f(st);
		cout<<ans<<endl;
		//return 0;
	}
	
	return 0;
}

