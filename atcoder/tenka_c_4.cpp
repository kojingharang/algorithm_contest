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
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
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

int vis[10010];
int check(vector<string>& w, int nh, int sx, int sy) {
	if(sx==-1 || sy==-1) return 0;
	//cout<<sx<<" "<<sy<<" "<<nh<<endl;
	int H = w.size();
	int W = w[0].size();
	deque<PII> q;
	q.PB(MP(sx, sy));
	vis[sy*W+sx]=1;
	int found = 0;
	while(q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		//cout<<x<<" pop "<<y<<"  "<<found<<endl;
		int dx[4] = {1,0,-1,0};
		int dy[4] = {0,1,0,-1};
		REP(dir, 4) {
			int nx=x+dx[dir];
			int ny=y+dy[dir];
			if(0<=nx && nx<W && 0<=ny && ny<H) {
				if(w[ny][nx]=='H') {
					found++;
					//cout<<"found"<<endl;
					w[ny][nx]='h';
				}
				if(w[ny][nx]=='.' && !vis[ny*W+nx]) {
					vis[ny*W+nx]=1;
					q.PB(MP(nx, ny));
				}
			}
		}
	}
	return found==nh;
}

int main() {
	ios::sync_with_stdio(false);
	int H,W;
	while(cin>>H>>W) {
		vector<string> w(H);
		REP(y, H) cin>>w[y];
		//cout<<w<<endl;
		int max_flo=-1;
		REP(pat, 1<<(H*W)) {
			CLEAR(vis, 0);
			vector<string> ww(w);
			int valid=1;
			int flo = 0;
			int sx=-1, sy=-1;
			int house=0;
			REP(y, H) REP(x, W) {
				if((pat>>(y*W+x))&1) { if(ww[y][x]!='.') valid=0; ww[y][x]='F'; flo++;}
				if(ww[y][x]=='.') sx=x,sy=y;
				if(ww[y][x]=='H') house++;
			}
			if(!valid) continue;
			//cout<<ww<<endl;
			if(check(ww, house, sx, sy)) {
				max_flo = max(max_flo, flo);
			}
			//break;
		}
		
		cout<<max_flo<<endl;
	}
	
	return 0;
}
