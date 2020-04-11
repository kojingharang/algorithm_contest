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

#define MOD 1000000007LL
#define INF (1LL<<60)
/*
(1),(1,1),(1,2),(1,3),(2),(2,1),(2,2),(2,3),(3),(3,1),(3,2),(3,3)
(1),(1,1),(1,2),(1,3),(1,4),(2),(2,1),(2,2),(2,3),(2,4),(3),(3,1),(3,2),(3,3),(3,4),(4),(4,1),(4,2),(4,3),(4,4)
長さ i のやつは K^i 個
sum K^i for i in [1, N]


Kが偶数ならK/2群の最後のやつ
奇数なら
(K+1)/2 * N の N-3こまえ

3 1 0こまえ
3 2 1こまえ
3 3 1こまえ
3 4 2こまえ
3 5 2こまえ
3 6 3こまえ
...

Kがちいさくても成り立つか???


*/
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,K;
	while(cin>>K>>N) {
		VI ans;
		if(K%2==0) {
			ans.PB(K/2);
			REP(i, N-1) ans.PB(K);
		} else {
			REP(i, N) ans.PB((K+1)/2);
			int back = N/2;
			REP(i, back) {
				if(ans.back()==1) {
					ans.pop_back();
				} else {
					ans.back() -= 1;
					while(ans.size()<N) ans.PB(K);
				}
			}
		}
//		vector<VVI> w(N+1);
//		w[0] = VVI(1, VI());
//		REP(i, N) {
//			for(auto& e : w[i]) {
//				REP(j, K) {
//					VI t(e);
//					t.PB(j+1);
//					w[i+1].PB(t);
//				}
//			}
//		}
//		VVI a;
//		RANGE(i, 1, N+1) for(auto& ee : w[i]) a.PB(ee);
//		sort(ALL(a));
//		DD(a);
//		DD(a.size());
//		DD(a[(a.size()+1)/2-1]);
		
		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}
