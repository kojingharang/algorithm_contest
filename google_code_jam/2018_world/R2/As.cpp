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
int main() {
	int test_cases;
	cin>>test_cases;
	ll W,H;
	string s;
	REP(ttt, test_cases) {
		cin>>H>>W;
		vector<string> w(H), ed, tr;
		int N=0;
		REP(y, H) {
			cin>>w[y];
			REP(x, W) {
				if(s[x]!='.') N++;
			}
		}
		string ch = "><^v";
		map<char, int> di;
		int dx[] = {1,-1,0,0};
		int dy[] = {0,0,-1,1};
		di['>'] = 0;
		di['<'] = 1;
		di['^'] = 2;
		di['v'] = 3;
		ed = w;
		ll ans = 0;
		int imp=0;
		REP(y, H) REP(x, W) {
			if(ed[y][x]!='.') {
				VI ok(4);
				REP(d, 4) {
					int xx=x, yy=y;
					while(1) {
						xx+=dx[d]; yy+=dy[d];
						if(!(IN_RANGE(xx, 0, W) && IN_RANGE(yy, 0, H))) break;
						if(w[yy][xx]!='.') {ok[d]=1;ed[y][x]=ch[d];break;}
					}
				}
				int anyok=0;
				int nochange=0;
				REP(i, 4) if(ok[i]) {
					anyok=1;
					if(ch[i]==w[y][x]) nochange=1;
				}
				if(anyok && !nochange) ans++;
				if(!anyok) imp=1;
//				cout<<"xy "<<x<<" "<<y<<" "<<ok<<" -> "<<nochange<<" "<<ans<<endl;
			}
		}
//		cout<<w<<endl;
//		cout<<ed<<endl;
//		REP(b, 1<<N) {
//			tr = w;
//			int n=0;
//			REP(y, H) REP(x, W) {
//				if(tr[y][x]!='.') {
//					if((b>>n)&1) {
//						tr[y][x] = ed[y][x];
//					}
//					n++;
//				}
//			}
//		}
		if(imp) {
			cout<<"Case #"<<ttt+1<<": IMPOSSIBLE"<<endl;
		} else {
			cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
		}
//		return 0;
	}
	return 0;
}



