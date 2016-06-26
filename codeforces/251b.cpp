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

ll N, K;
VI Q, S, P, W;
VI Same; // idx [-K K]  [0 2K]

int apply(int sign) {
	if(sign==1) {
		REP(i, N) W[i]=P[Q[i]-1];
	} else {
		REP(i, N) W[Q[i]-1]=P[i];
	}
	REP(i, N) P[i]=W[i];
	return 1;
}

int main() {
	//ios::sync_with_stdio(false);
	while(cin>>N>>K) {
		Q=VI(N);
		S=VI(N);
		P=VI(N);
		W=VI(N);
		Same=VI(2*K+1);
		REP(i, N) {
			cin>>Q[i];
		}
		REP(i, N) {
			cin>>S[i];
		}
		
		for(int sign=-1;sign<=1;sign+=2) {
			REP(i, N) P[i]=i+1;
			REP(i, K+1) {
				int same=1;
				REP(j, N) if(P[j]!=S[j]) same=0;
				//cout<<P<<endl;
				Same[i*sign + K] = same;
				apply(sign);
			}
		}
		//cout<<Same<<endl;
		//break;
		
		deque<int> q;
		q.PB(0);
		int OK=0;
		REP(loop, K+1) {
			deque<int> nq;
			VI vis(2*K+1);
			while(q.size()) {
				int idx = q.front();q.pop_front();
				//cout<<"loop "<<loop<<" pop "<<idx<<endl;
				if(loop==K && Same[idx+K]) {
					//cout<<" same at Kth"<<endl;
					OK=1;break;
				}
				if(loop<K && !Same[idx+K]) {
					//cout<<" not same"<<endl;
					if(!vis[idx-1+K]) {vis[idx-1+K]=1; nq.PB(idx-1); }
					if(!vis[idx+1+K]) {vis[idx+1+K]=1; nq.PB(idx+1); }
				}
			}
			//cout<<"NQ "<<nq<<endl;
			q = nq;
			if(q.size()==0) break;
		}
		
		
		cout<<(OK?"YES":"NO")<<endl;
		//break;
	}
	
	return 0;
}
