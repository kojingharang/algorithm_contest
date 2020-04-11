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
#include <functional>
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


#include <time.h>
#include <sys/time.h>
double nowMs()
{
	struct timeval t;
	gettimeofday( &t, NULL );
	double time_base = t.tv_sec * 1000.0 + t.tv_usec*0.001; 
	//printf("gettimeofday %d %d %f\n", t.tv_sec, t.tv_usec, time_base);
	return time_base;
}


/*
 x
 x

U L DD RR UUU LLL DDDD RRRR
*/

ll sim(vector<string> m, int H, int W, const string& cmd) {
	int x=-1, y=-1;
	REP(iy, H) REP(ix, W) {
		if(m[iy][ix]=='@') {
			x = ix, y = iy;
			m[y][x] = ' ';
			break;
		}
	}
//	DD(x);DD(y);
	assert(IN(x, 0, W) && IN(y, 0, H));
	map<char, int> tb = {{'U', 0}, {'L', 1}, {'D', 2}, {'R', 3}};
	int dx[] = {0, -1, 0, 1};
	int dy[] = {-1, 0, 1, 0};
	int got = 0;
	for(char c : cmd) {
		int d = tb[c];
//		DD(x);DD(y);
//		DD(d);
		int nx = x+dx[d];
		int ny = y+dy[d];
		if(m[ny][nx]=='o') {
			m[ny][nx] = ' ';
			got++;
			x = nx, y = ny;
		}
		if(m[ny][nx]==' ') {
			x = nx, y = ny;
		}
		if(m[ny][nx]=='x') break;
	}
	return got;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N, K, H, W, T;
	string s;
	double st = nowMs();
	while(cin>>N>>K>>H>>W>>T) {
		string cmd;
		string tb = "ULDR";
		REP(i, 10000000) {
			char c = tb[i%4];
			int n = i/2+1;
			if(cmd.size()==T) break;
			REP(j, n) {
				if(cmd.size()==T) break;
				cmd.PB(c);
			}
		}
//		DD(cmd);
		vector<vector<string>> m(N, vector<string>(H));
		REP(i, N) {
			REP(y, H) cin>>m[i][y];
		}
		string bestCmd;
		ll bestS = 0;
		vector<PII> best(N);
		REP(tt, 10000000) {
			if(tt%10==0) {
				if(tt/10==0) {
					cmd = "";
					REP(i, W) {
						REP(i, H) cmd.PB('U');
						cmd.PB('L');
						REP(i, H) cmd.PB('D');
						cmd.PB('L');
					}
					REP(i, W) {
						REP(i, H) cmd.PB('U');
						cmd.PB('R');
						REP(i, H) cmd.PB('D');
						cmd.PB('R');
					}
					cmd = cmd.substr(0, T);
//					cerr<<cmd<<endl;
				} else if(tt/10==1) {
					cmd = "";
					ll step = UNIFORM_LL(2, 10);
					ll rn = UNIFORM_LL(2, 10);
					REP(i, T/step) {
						int v = UNIFORM_LL(0, 4);
						REP(loop, 2) {
							char c = tb[v];
							REP(j, step) cmd.PB(c);
							REP(j, rn) cmd.PB(tb[UNIFORM_LL(0, 2)]);
							v = (v+2)%4;
						}
					}
					cmd = cmd.substr(0, T);
//					cerr<<cmd.size()<<" "<<cmd<<endl;
				} else {
					cmd = "";
					ll step = UNIFORM_LL(2, 20);
					REP(i, T/step) {
						int v = UNIFORM_LL(0, 4);
						char c = tb[v];
						REP(j, step) cmd.PB(c);
					}
					cmd = cmd.substr(0, T);
				}
			} else {
				REP(ns, UNIFORM_LL(5, 30)) {
					ll a = UNIFORM_LL(0, cmd.size());
					ll b = UNIFORM_LL(0, cmd.size());
					swap(cmd[a], cmd[b]);
				}
			}
			vector<PII> score(N);
			REP(i, N) {
				PII v = MP(0, i);
				v.first = sim(m[i], H, W, cmd);
				score[i] = v;
			}
			sort(ALLR(score));
			ll lb = 0;
			REP(i, K) lb+=score[i].first;
//			DD(cmd);
			if(bestS < lb) {
				bestS = lb;
				best = score;
				bestCmd = cmd;
				cerr<<bestS<<endl;
			}
			if(st+3500<nowMs()) break;
		}
		REP(i, K) {
			cout<<best[i].second;
			if(i<K-1) cout<<" ";
		}
		cout<<endl;
		cout<<bestCmd<<endl;
	}
	
	return 0;
}
