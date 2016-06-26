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
#define PII pair<ll, ll> 
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

int main() {
	//ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
		VI w(N);
		REP(i, N) cin>>w[i];
		VVI wb(N, VI(N)), wf(N, VI(N));
		REP(i, N) for(int k=i-1;k>=0;k--) wb[i][k] = wb[i][k+1] + (w[k]>w[i]) - (w[k]<w[i]);
		REP(i, N) for(int k=i+1;k<N;k++) wf[i][k] = wf[i][k-1] + (w[k]<w[i]) - (w[k]>w[i]);
//		cout<<wb<<endl;
//		cout<<wf<<endl;
		int Max=0;
		int co=0;
		RANGE(r, 1, N) REP(l, r) {
//			cout<<l<<" "<<r<<" -> "<<wb[r][l]+wf[l][r-1]<<endl;
			Max = max(Max, wb[r][l]+wf[l][r-1]);
		}
		RANGE(r, 1, N) REP(l, r) {
			if(Max==wb[r][l]+wf[l][r-1]) co++;
		}
		int def=0;
		RANGE(i, 1, N) {
			int j=i;
			while(j>0 && w[j] < w[j-1]) {
				swap(w[j], w[j-1]);
				def++;
				j--;
			}
		}
//		cout<<def<<" "<<Max<<" "<<co<<endl;
		cout<<def-Max<<" "<<co<<endl;
	}
	
	return 0;
}
