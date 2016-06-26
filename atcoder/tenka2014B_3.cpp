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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

int main() {
	//ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
//		if(N>9) {
//			cout<<""<<endl;
//			continue;
//		}
		int dx[] = {-1,1,0,0};
		int dy[] = {0,0,-1,1};
		vector<string> ref(N);
		vector<string> w(N, string(N, '.'));
		vector<string> sim(N, string(N, '.'));
		REP(i, N) cin>>ref[i];

//		REP(bits, 1<<N)
//		REP(i, N) w[0][i] = ((bits>>i)&1) ? '.' : '#';
		REP(i, N) w[0][i] = '.';
		{
//			cout<<"Try "<<w[0]<<endl;
			REP(y, N-1) REP(x, N) {
				int co=0;
				REP(dir, 4) {
					int nx=x+dx[dir], ny=y+dy[dir];
					if(0<=nx&&nx<N && 0<=ny&&ny<=y) co += w[ny][nx]=='#';
				}
				w[y+1][x]=(ref[y][x]=='#') ^ (co%2) ? '#' : '.';
			}
			REP(y, N) REP(x, N) {
				int co=0;
				REP(dir, 4) {
					int nx=x+dx[dir], ny=y+dy[dir];
					if(0<=nx&&nx<N && 0<=ny&&ny<N) co += w[ny][nx]=='#';
				}
				sim[y][x]=co%2 ? '#' : '.';
			}
//			cout<<"Ref "<<ref[N-1]<<endl;
//			cout<<"Sim "<<sim[N-1]<<endl;
			if(ref==sim) {
//			cout<<N<<endl;
				REP(i, N) cout<<w[i]<<endl;
//				break;
			} else {
//				cout<<"NG"<<endl;
			}
		}
	}
	
	return 0;
}
