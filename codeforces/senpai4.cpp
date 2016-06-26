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
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[x][y]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 


#define MOD 1000000007LL
#define INF (1LL<<60)

const int MAX_V = 1000010;
int v2i[MAX_V]; // value -> w[i] <= value なる最大の i
int w[500010];
int bigger[500010];
//char ibuffer[500000*20];
//char obuffer[300*20];

int main() {
//	setvbuf(stdin, ibuffer, _IOFBF, sizeof(ibuffer));
//	setvbuf(stdout, obuffer, _IOFBF, sizeof(obuffer));
	srand((unsigned)time(NULL));
	if(0)
	REP(loop, 100) {
		int N = UNIFORM_LL(2, 100);
		int M = UNIFORM_LL(1, 100);
		cout<<N<<" "<<M<<endl;
		REP(i, N) cout<<UNIFORM_LL(10, 100000)<<endl;
		REP(i, M) cout<<UNIFORM_LL(1, 10000)<<endl;
		return 0;
	}
	
	int N, M, v;
	while(scanf("%d %d", &N, &M) != -1) {
		CLEAR(v2i, -1);
		REP(i, N) {
			scanf("%d", &w[i]);
			v2i[w[i]] = i;
		}
		sort(&w[0], &w[N]);
		REP(i, N) v2i[w[i]] = i;
		int last = -1;
		REP(i, MAX_V) if(v2i[i]!=-1) last = v2i[i]; else v2i[i] = last;
		
		REP(i, N) bigger[i] = N;
		int latest_next = N;
		for(int i=N-2; i>=0; i--) {
			if(w[i]!=w[i+1]) latest_next=i+1;
			bigger[i] = latest_next;
		}
		
//		PRINT1(v2i, 100);
		REP(i, M) {
			scanf("%d", &v);
			int ans=0;
			// w[nlo]+w[nhi]<=v, nlo<nhi, for nlo, nhi in [lo, hi]
			if(0 <= v-w[0]) {
				int hi = v2i[v-w[0]];
				int lo = 0;
				while(lo<hi) {
					int nhi = v2i[w[hi]];
					if(nhi==-1 || v-w[nhi] <= 0) break;
					int nlo = min(nhi-1, v2i[v-w[nhi]]);
					if(nlo==-1) break;
//					cout<<"lo hi "<<lo<<" "<<hi<<endl;
//					cout<<"nlo nhi "<<nlo<<" "<<nhi<<"  "<<w[nlo]<<" "<<w[nhi]<<endl;
					int sum = w[nlo]+w[nhi];
					if(v-sum < v-ans) {
						ans = sum;
						if(v-sum==0) break;
					}
					lo = bigger[nlo];
					if(lo>=hi) break;
					hi = v2i[v-w[lo]];
				}
			}
			printf("%d\n", ans);
		}
//		break;
	}
	
	return 0;
}
