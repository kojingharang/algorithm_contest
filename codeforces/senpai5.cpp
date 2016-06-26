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
int leq[MAX_V]; // value -> w[i] <= value なる最大の w[i]
int gt[MAX_V]; // value -> w[i] > value なる最小の w[i]
int co[MAX_V]; // value -> w[i] <= value なる最大の w[i]
//int Ms[310];
//char ibuffer[500000*20];
//char obuffer[300*20];
char buf[512];

int main() {
//	setvbuf(stdin, ibuffer, _IOFBF, sizeof(ibuffer));
//	setvbuf(stdout, obuffer, _IOFBF, sizeof(obuffer));
	srand((unsigned)time(NULL));
	
	int N, M, v;
	while(scanf("%d %d", &N, &M) != -1) {
		fgets(buf, sizeof(buf), stdin);
		CLEAR(leq, -1);
		int Mn=10000000, Mx=-1;
		REP(i, N) {
			fgets(buf, sizeof(buf), stdin);
			v = atoi(buf);
//			scanf("%d", &v);
			Mn=min(Mn, v);
			Mx=max(Mx, v);
			leq[v] = v;
			co[v]++;
		}
		int last = -1;
		for(int i=MAX_V-1;i>=0;i--) {gt[i] = last; if(leq[i]!=-1) last = leq[i]; }
		last=-1;
		REP(i, MAX_V) if(leq[i]!=-1) last = leq[i]; else leq[i] = last;
		
//		PRINT1(leq, 100);
//		PRINT1(gt, 100);
//		PRINT1(co, 100);
//		REP(i, M) scanf("%d", &Ms[i]);
		REP(i, M) {
			fgets(buf, sizeof(buf), stdin);
			v = atoi(buf);
//			v = Ms[i];
			int ans=0;
			// w[nlo]+w[nhi]<=v, nlo<nhi, for nlo, nhi in [lo, hi]
			if(0<=v-Mn) {
				int hi = leq[v-Mn];
				int lo = Mn;
				int nhi=-1;
//				cout<<"first lo hi "<<lo<<" "<<hi<<endl;
				while(lo<hi) {
					nhi = leq[hi];
					if(nhi==-1 || v-nhi <= 0) break;
					int nlo = leq[v-nhi];
					if(nlo==nhi) nlo=leq[nlo-1];
//					cout<<"nlo "<<nlo<<endl;
					if(nlo==-1) break;
//					cout<<"lo hi "<<lo<<" "<<hi<<endl;
//					cout<<"nlo nhi "<<nlo<<" "<<nhi<<"  "<<endl;
//					cout<<"ans "<<ans<<endl;
					int sum = nlo+nhi;
					if(v-sum < v-ans) {
						ans = sum;
						if(v-sum==0) break;
					}
					lo = gt[nlo];
					if(lo==-1 || lo>=hi) break;
					hi = leq[v-lo];
				}
				if(nhi!=-1 && co[nhi]>1) {
					int sum=nhi*2;
					if(sum <= v && v-sum < v-ans) ans = sum;
				}
			}
			printf("%d\n", ans);
		}
//		break;
	}
	
	return 0;
}
