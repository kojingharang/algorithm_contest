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

int chL[110000]; // L child, 1base
int chR[110000]; // R child, 1base
int rL[7007];
int rR[7007];
// hint level
int T[7007];
int L[7007];
int R[7007];
int X[7007];

// 109332
int main() {
	ios::sync_with_stdio(false);
//	ll cnt=1;
//	REP(lvl, 7000) {
//		ll ncnt=0;
//		RANGE(i, 1, cnt+1) ncnt+=(POPCOUNT(i)==1)?2:1;
//		cout<<ncnt<<endl;
//		cnt=ncnt;
//	}
	ll N,M;
	ll type,t,v;
	while(cin>>N>>M) {
		int cs=1;
		REP(i, 110000) {
			int ch = (POPCOUNT(i+1)==1) ? 2:1;
			chL[i+1]=ch==2?cs++:-1;
			chR[i+1]=cs++;
		}
//		PRINT1(chL, 20);
//		PRINT1(chR, 20);
//		return 0;
		int hints=0;
		REP(i, M) {
			cin>>type;
			if(type==1) {
				cin>>T[hints]>>L[hints]>>R[hints]>>X[hints];
				hints++;
			} else {
				cin>>t>>v;
				REP(j, t) rL[j]=rR[j]=-1;
				rL[t]=rR[t]=v;
				RANGE(j, t, N) {
					rL[j+1]=chL[rL[j]]==-1 ? chR[rL[j]] : chL[rL[j]];
					rR[j+1]=chR[rR[j]];
				}
//				cout<<i<<endl;
//				PRINT1(rL, N+1);
//				PRINT1(rR, N+1);
				map<int, int> ma;
				REP(hi, hints) {
					if(rL[T[hi]]==-1) continue;
					bool in = !(R[hi]<rL[T[hi]] || rR[T[hi]]<L[hi]);
					if(in) ma[X[hi]]=1;
				}
				cout<<ma.size()<<endl;
			}
		}
	}
	
	return 0;
}
