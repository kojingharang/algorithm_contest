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

int win(char col, vector<string>& w) {
	int dx[]={1,1,0,-1,-1,-1,0,1};
	int dy[]={0,1,1,1,0,-1,-1,-1};
	REP(y, 19) REP(x, 19) {
		REP(dir, 8) {
			int win=1;
			REP(st, 5) {
				int nx=x+dx[dir]*st;
				int ny=y+dy[dir]*st;
				if(!(0<=nx&&nx<19&&0<=ny&&ny<19)) {win=0;break;}
				if(w[ny][nx]!=col) {win=0;break;}
			}
			if(win) return 1;
		}
	}
	return 0;
}

int solve(vector<string>& w) {
	int Bs=0, Ws=0;
	REP(i, 19) REP(j, 19) Bs+=w[i][j]=='o';
	REP(i, 19) REP(j, 19) Ws+=w[i][j]=='x';
	
	//cout<<"count: "<<Bs<<" "<<Ws<<endl;
	if(!(Bs==Ws || Bs==Ws+1)) return 0;
	
	string col("ox");
	int Bwin = win('o', w);
	int Wwin = win('x', w);
	//cout<<"win: "<<Bwin<<" "<<Wwin<<endl;
	
	if(Bwin && Wwin) return 0;
	if(!(!Bwin || (Bwin && Bs==Ws+1))) return 0;
	if(!(!Wwin || (Wwin && Bs==Ws))) return 0;
	if(Bwin) {
		int ok=0;
		REP(y, 19) REP(x, 19) {
			if(ok) break;
			if(w[y][x]=='o') {
				w[y][x]='.';
				if(!win('o', w)) {ok=1;break;}
				w[y][x]='o';
			}
		}
		if(!ok) return 0;
	}
	if(Wwin) {
		int ok=0;
		REP(y, 19) REP(x, 19) {
			if(ok) break;
			if(w[y][x]=='x') {
				w[y][x]='.';
				if(!win('x', w)) {ok=1;break;}
				w[y][x]='x';
			}
		}
		if(!ok) return 0;
	}
	return 1;
}

int main() {
	//ios::sync_with_stdio(false);
	string s;
	while(getline(cin, s)) {
		vector<string> w(19);
		w[0] = s;
		RANGE(i, 1, 19) getline(cin, w[i]);
		//cout<<w<<endl;
		int ok = solve(w);
		
		
		cout<<(ok?"YES":"NO")<<endl;
		//break;
	}
	
	return 0;
}
