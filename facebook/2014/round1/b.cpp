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


//VI w;
//ll ans=10000000;
//VVI hi[1000];
//map<VI, int> mhi;
//void f(ll N, ll K, ll C) {
//	if(N==0) {
//		if(K>0) return;
//		VI h(w), oh(w);
//		sort(ALL(h));
//		sort(ALL(oh));
//		if(mhi.count(oh)) return;
//		mhi[oh]=1;
////		cout<<"try "<<h<<endl;
//		ll P=0, minKnownCount=0, got=0;
//		REP(i, h.size()) {
//			minKnownCount=h[i];
//			ll pull = min(C, minKnownCount * (ll)(h.size()-i));
////			cout<<" pull "<<pull<<" "<<minKnownCount<<endl;
//			P += pull;
//			got += pull;
//			RANGE(j, i+1, h.size()) h[j]-=minKnownCount;
//			C-=pull;
//			if(C==0) {
//				ans=min(ans, P);
//				hi[P].PB(oh);
////				cout<<"UPD "<<P<<" "<<endl;
//				break;
//			}
//			// drill
//			P++;
//		}
//		return;
//	}
//	RANGE(k, 0, K+1) {
//		w.PB(k);
//		f(N-1, K-k, C);
//		w.pop_back();
//	}
//}

int main() {
	//ios::sync_with_stdio(false);
	if(0)
	{
		ll T = 100;
		cout<<T<<endl;
		REP(t, T) {
			ll N = UNIFORM_LL(1, 12);
			ll C = UNIFORM_LL(1, 12);
			ll K = UNIFORM_LL(C, 12);
			cout<<N<<" "<<K<<" "<<C<<endl;
		}
		return 0;
	}
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		ll N, K, C;
		cin>>N>>K>>C;
//		ans=1LL<<40;
//		REP(i, 100) hi[i].clear();
//		mhi.clear();
//		f(N, K, C);
//		cout<<hi[ans]<<endl;
		ll ans = 1LL<<40;
//		cout<<N<<" "<<K<<" "<<C<<endl;
//		RANGE(miss, 0, N+1) {
//			ll w = N-miss;
//			if(C <= K/w*N) {ans=C+miss;break;}
//		}

		RANGE(x, 1, K+1) {
			// C 個を 最大高さ x のビンから取る。
			ll width_x = K/x;
			ll width_leq_x = width_x+(K%x?1:0);
//			cout<<x<<" "<<w<<" "<<C+N-min(w, N)<<endl;
			ll can_pull_leq_x = width_leq_x<=N ? x*width_x+K%x : x*N;
			if(can_pull_leq_x>=C) ans=min(ans, C+N-min(width_x, N));
		}
		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		break;
	}
	
	return 0;
}
