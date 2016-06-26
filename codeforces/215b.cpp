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

int main() {
	//ios::sync_with_stdio(false);
	ll N, M, P;
	while(cin>>N>>M>>P) {
		VI A(N), B(M);
		REP(i, N) cin>>A[i];
		REP(i, M) cin>>B[i];
		if((M-1)*P>=N) {
			cout<<0<<endl<<endl;
			continue;
		}
		sort(ALL(B));
		VI w(N);
		REP(i, N) {
			int idx = distance(B.begin(), lower_bound(ALL(B), A[i]));
			w[i] = (idx < M && B[idx]==A[i]) ? idx : M;
		}
		VI ref(M+1);
		REP(i, M) {
			int idx = distance(B.begin(), lower_bound(ALL(B), B[i]));
			ref[idx]++;
		}
//		cout<<"w "<<w<<endl;
//		cout<<"ref "<<ref<<endl;
		VI hi(M+1);
		VI ans;
		REP(off, P) {
			if(off+(M-1)*P >= N) continue;
			
			hi.assign(M+1, 0);
			REP(i, M) hi[w[off+i*P]]++;
			ll ok_count=0;
			REP(i, M+1) {
				if(hi[i]==ref[i]) ok_count++;
			}
//			cout<<"hi "<<hi<<endl;
//			cout<<"ok init "<<ok_count<<endl;
			
			if(ok_count==M+1) ans.PB(off);
			for(int i=off+M*P; i<N; i+=P) {
				int rm = w[i-M*P];
				int add = w[i];
				if(hi[rm]==ref[rm]) ok_count--;
				hi[rm]--;
				if(hi[rm]==ref[rm]) ok_count++;
				if(hi[add]==ref[add]) ok_count--;
				hi[add]++;
				if(hi[add]==ref[add]) ok_count++;
				if(ok_count==M+1) ans.PB(i-M*P+P);
//				cout<<"hi "<<hi<<endl;
//				cout<<"ok "<<ok_count<<endl;
			}
		}
		sort(ALL(ans));
		
//		cout<<B<<endl;
//		cout<<ref<<endl;
		cout<<ans.size()<<endl;
		REP(i, ans.size()) {
			cout<<ans[i]+1;
			if(i<ans.size()-1) cout<<" ";
		}
		cout<<endl;
//		break;
	}
	
	return 0;
}
