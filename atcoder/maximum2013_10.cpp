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
#define ll unsigned long long
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
#define INF (ULLONG_MAX-10)

const int MAX_N=1<<18;
ll n, dat[2*MAX_N-1];

void init(int n_) {
	n=1;
	while(n<n_) n*=2;
	REP(i, 2*n) dat[i]=INF;
}

void update(int k, ll a) {
	k+=n-1;
	dat[k] = a;
	while(k>0) {
		k = (k-1)/2;
		dat[k] = min(dat[k*2+1], dat[k*2+2]);
	}
}

ll _query(int a, int b, int k, int l, int r) {
	if(r<=a||b<=l) return INF;
	if(a<=l && r<=b) return dat[k];
	else {
		ll vl = _query(a, b, k*2+1, l, (l+r)/2);
		ll vr = _query(a, b, k*2+2, (l+r)/2, r);
		return min(vl, vr);
	}
}
ll query(int a, int b) {
	return _query(a, b, 0, 0, n);
}

int main() {
	//ios::sync_with_stdio(false);
	ll N, K;
//	cout<<(1ULL<<63)<<endl;
//	cout<<ULLONG_MAX<<endl;
	while(cin>>N>>K) {
		if(N==-1 && K==-1) break;
		init(N);
		VI w(N);
		REP(i, N) {
			cin>>w[i];
			update(i, w[i]);
		}
//		cout<<w<<endl;
//		cout<<query(0, 1)<<endl;
//		cout<<query(1, 2)<<endl;
//		cout<<query(2, 3)<<endl;
		string ans = "Yes";
		REP(i, N) {
			if(i+K+1 >= N) continue;
			ll Min = query(i+K+1, N);
//			cout<<"Min "<<Min<<endl;
			if(w[i] > Min) {ans="No";break;}
		}
		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}
