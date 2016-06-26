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
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<ll> >
#define VVVI vector<vector<vector<ll> > >
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

ll NA, NB;
VI A, B;
PII dp[1010][1010][2];

// a, b, p で回ってきたとき p, 1-p はそれぞれ何点とれるか.
PII f(int a, int b, int p) {
	if(a==NA && b==NB) return MP(0, 0);
	if(dp[a][b][p].first!=-1) return dp[a][b][p];
//	cout<<"f "<<a<<" "<<b<<" "<<p<<endl;
	int ans = 0;
	PII nxt0, nxt1;
	int sel=-1;
	if(a+1<=NA) {
		nxt0 = f(a+1, b, 1-p);
		if(ans < A[a]+nxt0.second) {
			ans = A[a]+nxt0.second;
			sel = 0;
		}
	}
	if(b+1<=NB) {
		nxt1 = f(a, b+1, 1-p);
		if(ans < B[b]+nxt1.second) {
			ans = B[b]+nxt1.second;
			sel = 1;
		}
	}
	assert(sel!=-1);
	int sec = sel==0 ? nxt0.first : nxt1.first;
//	cout<<"f "<<a<<" "<<b<<" "<<p<<" -> "<<MP(ans, sec)<<endl;
	return dp[a][b][p] = MP(ans, sec);
}

int main() {
	//ios::sync_with_stdio(false);
	while(cin>>NA>>NB) {
		REP(i, 1010) REP(j, 1010) REP(k, 2) dp[i][j][k].first=-1;
		A=VI(NA);
		B=VI(NB);
		REP(i, NA) cin>>A[i];
		REP(i, NB) cin>>B[i];
		cout<<f(0, 0, 0).first<<endl;
//		break;
	}
	
	return 0;
}
