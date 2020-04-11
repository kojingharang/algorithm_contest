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
#include <functional>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cassert>
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
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

/*
idx->そこをとるのが何step目か
がわかればにぶたんでOK

3  5  7  11  13
x<=4
1  2  3  4  5
x<=6
2  1  3  4  5
x=7
4  3  1  2  5


3  5  9  10  20
x<=4
1 2 3 4 5
x<=6
2 1 3 4 5
x<=7
4 1 2 3 5

xから距離r以内の左端右端はlogNでわかる→何個とったかわかる
rに対して右端と何個取ったかlogNでわかる
*/
#define MOD 1000000007LL
#define INF (1LL<<60)

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,Q,x;
	while(cin>>N>>Q) {
		VI A(N);
		REP(i, N) cin>>A[i];
		// sum[i, N)
		VI rsum(N+1);
		VI rsum2(N+1);
		REP(i, N) rsum2[i+1]=rsum2[i]+A[i];
		for(int i=N-1;i>=0;i--) {
			rsum[i]=rsum[i+1]+A[i];
		}
//		DD(rsum);DD(rsum2);
		// sum[0, i, step2]
//		VI lsum(N);
//		REP(i, N) {
//			if(i<=1) lsum[i]=A[i];
//			else lsum[i]=A[i]+lsum[i-2];
//		}
		VI lsum2(N+1);
		lsum2[1]=A[0];
		RANGE(i, 1, N) lsum2[i+1]=lsum2[i-1]+A[i];

		REP(i, N) A[i]=A[i]*10+1;
//		DD(rsum);
//		DD(lsum);
		REP(i, Q) {
			cin>>x;
			x *= 10;
//			DD(x);
			// lo: ?手終了時点で後攻の右端<=先攻の左端
			ll lo=-1, hi=1LL<<60;
			while(lo+1<hi) {
				ll r = (lo+hi)/2;
				ll L = lower_bound(ALL(A), x-r)-A.begin();
				ll R = upper_bound(ALL(A), x+r)-A.begin();
//				ll co = R-L;
//				ll al = N-co;
//				DD(r);
//				DD(L);DD(R);DD(co);DD(al);
//				if(R<=al) lo=r; else hi=r;
				if(N-R >= R-L) lo=r; else hi=r;
			}
			ll r = lo;
			ll L = lower_bound(ALL(A), x-r)-A.begin();
			ll R = upper_bound(ALL(A), x+r)-A.begin();
//			ll co = R-L;
//			ll al = N-co;
			ll ans = 0;
			assert ((N - R) - (R - L) >= 0);
			assert ((N - R) - (R - L) <= 1);
//			DD(r);
//			DD(L);DD(R);DD(co);DD(al);
			// R==al or R+1==al
//			if(R==al) {
			if(N-R==R-L) {
				// 先攻はsum[R, N) + L-2から1ことび
//				ans = accumulate(A.begin()+R, A.end(), 0LL);
//				ans = rsum[R-1];
//				if(0<=L-2) for(int i=(L-2)%2;i<=L-2;i+=2) ans += A[i];
//				if(0<=L-2) ans += lsum[L-2];
				ans = rsum[R] + lsum2[L];
//				if(0<=L-1) ans += lsum[L-1];
//				if(0<=L-2) ans += lsum[L-2];
//				ans = rsum2[N]-rsum2[R] + lsum2[L];
			} else {
				// 先攻はsum[R+1, N) + L-1から1ことび
//				ans = accumulate(A.begin()+R+1, A.end(), 0LL);
//				ans = rsum[R];
//				if(0<=L-1) for(int i=(L-1)%2;i<=L-1;i+=2) ans += A[i];
//				if(0<=L-2) ans += lsum[L-2];
//				ans = rsum2[N]-rsum2[R]+ (0<=L-1 ? lsum2[L-1] : 0);
				ans = rsum[R] + (0<=L-1 ? lsum2[L-1] : 0);
			}
			cout<<ans<<endl;
		}
//		break;
	}
	
	return 0;
}
