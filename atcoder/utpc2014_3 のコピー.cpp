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

int mat[100][100];
int wm[100][100];
int main() {
	//ios::sync_with_stdio(false);
	ll N0, N1, M0, M1, a, b;
	while(cin>>N0>>M0) {
		REP(i, 100)REP(j,100)mat[i][j]=1<<25;
		REP(i, M0) {
			cin>>a>>b;
			mat[a][b]=mat[b][a]=1;
		}
		cin>>N1>>M1;
		REP(i, M1) {
			cin>>a>>b;
			a+=N0;b+=N0;
			mat[a][b]=mat[b][a]=1;
		}
		int N=N0+N1;
		if(N0>20 || N1>20) {
			cout<<"0 0"<<endl;
			continue;
		}
		REP(i, N)mat[i][i]=0;
//		PRINT2(mat, N, N);
		int Mn=100000,Mx=0;
		REP(c0, N0) REP(c1, N1) {
			memcpy(wm, mat, sizeof(mat));
			wm[c0][c1+N0]=wm[c1+N0][c0]=1;
			
			REP(k,N)REP(i,N)REP(j,N) wm[i][j]=min(wm[i][j], wm[i][k]+wm[k][j]);
			int lans=0;
			REP(i, N)REP(j,N)if(i!=j) {
				if(wm[i][j] < 1<<25) lans=max(lans, wm[i][j]);
			}
			Mn=min(Mn, lans);
			Mx=max(Mx, lans);
		}
		cout<<Mn<<" "<<Mx<<endl;
	}
	
	return 0;
}
