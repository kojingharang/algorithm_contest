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
#include <cstdio>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
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
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[x][y]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

int main() {
	int N, M, v;
	while(scanf("%d %d", &N, &M) != -1) {
		VI w(N);
		VI prev(N, -1);
		VI next(N, N);
		REP(i, N) scanf("%d", &w[i]);
		sort(ALL(w));
		int latest_prev = -1, latest_next = N;
		RANGE(i, 1, N) {
			if(w[i]!=w[i-1]) latest_prev=i-1;
			prev[i] = latest_prev;
		}
		for(int i=N-2; i>=0; i--) {
			if(w[i]!=w[i+1]) latest_next=i+1;
			next[i] = latest_next;
		}
//		cout<<w<<endl;
//		cout<<prev<<endl;
//		cout<<next<<endl;
		REP(i, M) {
			scanf("%d", &v);
			int ans = 0;
			int lo = 0, hi = N;
			int first=1;
			while(lo<hi) {
				// candidate nlo<nhi is in [lo, hi)
				
//				cout<<"lo hi "<<lo<<" "<<hi<<endl;
				// k<j and w[k] + w[j] <= v
				int nhi;
				if(first) {
					nhi = distance(&w[0], upper_bound(&w[lo], &w[hi], v-w[lo]))-1;
				} else {
					nhi = hi-1;
					for(;lo<=nhi;nhi=prev[nhi]) {
						if(w[nhi] <= v-w[lo]) break;
					}
				}
				// nhi==lo-1 ... w[kk] is too big -> give up
				// else ... w[nhi] <= v-w[lo]
//				cout<<"nhi "<<nhi<<endl;
//				if(nhi==lo-1) break;
				if(!(lo<nhi)) break;
				int nlo = distance(&w[0], upper_bound(&w[lo], &w[nhi], v-w[nhi]))-1;
				// nlo==lo-1 ... w[kk] is too big for kk in [lo, nhi) -> skip for j
				// else ... w[nlo] <= v-w[hi]
//				cout<<"nlo "<<nlo<<endl;
//				if(nlo==nhi-1) break;
				if(lo <= nlo) {
	//				cout<<"nlo nhi "<<nlo<<" "<<nhi<<endl;
					int sum=w[nlo]+w[nhi];
					if(v-sum < v-ans) ans = sum;
					lo = next[nlo];
	//				while(lo<hi && w[lo]+w[hi] > v) hi = prev[hi]; // skip until w[lo]+w[hi] <= v
				} else {
					lo = next[lo];
				}
				hi = nhi;
			}
			printf("%d\n", ans);
		}
//		break;
	}
	
	return 0;
}
