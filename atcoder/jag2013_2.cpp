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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

int main() {
	//ios::sync_with_stdio(false);
	string A,B,C;
	VI c09(10);
	VI c19(9);
	REP(i, 10) c09[i]=i;
	REP(i, 9) c19[i]=i+1;
	while(cin>>A) {
		if(A=="0") return 0;
		cin>>B>>C;
		int N=A.size();
		VVI w(2, VI(N+1));
		w[0][N]=1;
		w[1][N]=0;
		for(int i=N-1;i>=0;i--) {
			VI xa=c09, xb=c09, xc=c09;
			if(i==0) xa=c19, xb=c19, xc=c19;
			if(A[i]!='?') xa=VI(1, A[i]-'0');
			if(B[i]!='?') xb=VI(1, B[i]-'0');
			if(C[i]!='?') xc=VI(1, C[i]-'0');
			REP(up, 2) {
				ll lans0=0, lans1=0;
				REP(xai, xa.size()) 
				REP(xbi, xb.size()) 
				REP(xci, xc.size()) {
					if(xa[xai]+xb[xbi]+up==xc[xci]) lans0++;
					if(xa[xai]+xb[xbi]+up==10+xc[xci]) lans1++;
				}
//				cout<<i<<" "<<up<<" "<<lans0<<" "<<lans1<<endl;
				w[0][i]+=lans0*w[up][i+1];
				w[0][i]%=MOD;
				w[1][i]+=lans1*w[up][i+1];
				w[1][i]%=MOD;
			}
		}
//		cout<<endl;
//		cout<<w<<endl;
		cout<<w[0][0]<<endl;
//		break;
	}
	
	return 0;
}
