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

ll p[100010][3];
ll w[100010];
ll len[100010];
int main() {
	ios::sync_with_stdio(false);
	ll N,M;
	while(cin>>M) {
		len[0]=0;
		REP(i, M) {
			cin>>p[i][0];
			if(p[i][0]==1) {
				cin>>p[i][1];
				len[i+1] = len[i]+1;
				if(len[i]<100000) w[len[i]] = p[i][1];
			}
			if(p[i][0]==2) {
				cin>>p[i][1]>>p[i][2];
				len[i+1] = len[i]+p[i][1]*p[i][2];
				for(int j=0;j<p[i][1]*p[i][2] && len[i]+j<100000;j++) {
					w[len[i]+j]=w[j%p[i][1]];
				}
			}
		}
//		PRINT1(w, len[M]);
//		PRINT1(len, M+1);
		cin>>N;
		VI ans(N);
		REP(i, N) {
			ll idx;
			cin>>idx;
			int d = distance(&len[0], lower_bound(&len[0], &len[M+1], idx));
//			cout<<i<<" "<<d<<endl;
			if(p[d-1][0]==1) {
				assert(idx==len[d]);
				ans[i] = p[d-1][1];
			} else {
				int j = (idx-1-len[d-1]) % p[d-1][1];
				ans[i] = w[j];
			}
		}
		
		REP(i, N) {
			if(i) cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
	}
	
	return 0;
}
