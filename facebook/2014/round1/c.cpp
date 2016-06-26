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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


int main() {
	//ios::sync_with_stdio(false);
	int Cases;
	const ll NO=-1;
	cin>>Cases;
	REP(CaseID, Cases) {
		ll W, H;
		cin>>H>>W;
		vector<string> m(H);
		REP(y, H) cin>>m[y];
		VVI pot(H, VI(W, NO)); // pot[y][x] ... スタートから右下に伸ばして(x, y)にきたときの人数. スタートから来れない場合 NO
		VVI maxL(H, VI(W, 0)); // maxL[y][x] ... (x, y) から右下にできるだけ伸ばしたときの人数
		vector<string> potParent(H, string(W, ' '));
		vector<string> maxLParent(H, string(W, ' '));
		pot[0][0]=1;
		REP(x, W) REP(y, H) {
			if(m[y][x]=='#') continue;
			if(0<=x-1 && pot[y][x-1]!=NO && pot[y][x] < pot[y][x-1]+1) {
				pot[y][x] = pot[y][x-1]+1;
				potParent[y][x] = 'R';
			}
			if(0<=y-1 && pot[y-1][x]!=NO && pot[y][x] < pot[y-1][x]+1) {
				pot[y][x] = pot[y-1][x]+1;
				potParent[y][x] = 'D';
			}
		}
		for(int x=W-1;x>=0;x--) for(int y=H-1;y>=0;y--) {
			if(m[y][x]=='#') continue;
			maxL[y][x] = 1;
			if(x+1<W && maxL[y][x] < maxL[y][x+1]+1) {
				maxL[y][x] = maxL[y][x+1]+1;
				maxLParent[y][x] = 'R';
			}
			if(y+1<H && maxL[y][x] < maxL[y+1][x]+1) {
				maxL[y][x] = maxL[y+1][x]+1;
				maxLParent[y][x] = 'D';
			}
		}
//		cout<<pot<<endl;
//		cout<<maxL<<endl;
		ll ans = 0;
		ll backStartX=-1, backStartY=-1, backL=0, backU=0;
		REP(x, W) REP(y, H) {
			if(pot[y][x]==NO) continue;
			if(ans < pot[y][x]) {
				ans = pot[y][x];
				backStartX=x;
				backStartY=y;
				backL=0;
			}
			if(y+2<H && m[y+1][x]=='.') RANGE(toL, 1, x+1) {
				// x, y から１こ下に行って左に toL だけ戻り、その下から右下にいく. よってy+2まで区画内であることが必要.
				// 例えば左からしかこれないマス（W=5,H=1とか）からは左に行けないのでy+2まで必要。
				if(m[y+1][x-toL]=='#') break;
				ll nl = pot[y][x]+1+toL+maxL[y+2][x-toL];
				if(ans < nl) {
					ans = nl;
					backStartX = x;
					backStartY = y;
					backL = toL;
					backU = 0;
				}
			}
			if(x+2<W && m[y][x+1]=='.') RANGE(toT, 1, y+1) {
				// x, y から１こ右に行って上に toT 戻ってその右から右下へ
				if(m[y-toT][x+1]=='#') break;
				ll nl = pot[y][x]+1+toT+maxL[y-toT][x+2];
				if(ans < nl) {
					ans = nl;
					backStartX = x;
					backStartY = y;
					backL = toT;
					backU = 1;
				}
			}
		}
		string path;
		{
//			cout<<"backXY "<<backStartX<<" "<<backStartY<<endl;
//			REP(y, H) cout<<potParent[y]<<endl;
//			REP(y, H) cout<<maxLParent[y]<<endl;
			// UDLR
			const int dx[] = {0,0,-1,1};
			const int dy[] = {-1,1,0,0};
			int x=backStartX;
			int y=backStartY;
			map<char, int> c2i;
			c2i['U'] = 0;
			c2i['D'] = 1;
			c2i['L'] = 2;
			c2i['R'] = 3;
			while(!(x==0 && y==0)) {
//				cout<<"XY "<<x<<" "<<y<<endl;
				path.PB(potParent[y][x]);
				int nx = x - dx[c2i[potParent[y][x]]];
				int ny = y - dy[c2i[potParent[y][x]]];
				x=nx,y=ny;
			}
			reverse(ALL(path));
//			path.PB(' ');
			if(backL) {
				path.PB(backU ? 'R' : 'D');
				REP(i, backL) path.PB(backU ? 'U' : 'L');
				path.PB(backU ? 'R' : 'D');
				int x=backStartX;
				int y=backStartY;
				if(backU) y-=backL,x+=2;
				else x-=backL,y+=2;
				while(maxLParent[y][x]!=' ') {
					path.PB(maxLParent[y][x]);
					int nx = x + dx[c2i[maxLParent[y][x]]];
					int ny = y + dy[c2i[maxLParent[y][x]]];
					x = nx, y=ny;
				}
			}
//			cout<<"Path: "<<path<<endl;
			{
				VVI vis(H, VI(W));
				int x=0,y=0;
				REP(i, path.size()) {
					assert(vis[y][x]==0);
					vis[y][x]=1;
					int nx = x + dx[c2i[path[i]]];
					int ny = y + dy[c2i[path[i]]];
					x = nx, y=ny;
				}
				{
					int foundL=0,foundU=0;
					REP(i, path.size()) {
						if(path[i]=='L') {
							assert(foundL==0);
							assert(foundU==0);
							while(i<path.size() && path[i]=='L') i++;
							i--;
							foundL=1;
						}
						if(path[i]=='U') {
							assert(foundL==0);
							assert(foundU==0);
							while(i<path.size() && path[i]=='U') i++;
							i--;
							foundU=1;
						}
					}
				}
			}
		}
		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		cout<<path<<endl;
//		break;
	}
	
	return 0;
}
