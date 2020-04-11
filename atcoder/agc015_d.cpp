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

int main() {
	//ios::sync_with_stdio(false);
	ll A,B;
	while(cin>>A>>B) {
		if(A==B) {
			cout<<1<<endl;
			continue;
		}
		int N = 100;
		string a(N, '0'), b(N, '0');
		ll A_=A, B_=B;
		REP(i, N) {
			if(A_&1) a[N-1-i]='1';
			if(B_&1) b[N-1-i]='1';
			A_>>=1;
			B_>>=1;
		}
		ll r = 0;
		REP(i, N) {
			if(a[i]!=b[i]) {
				r = N-i;
				break;
			}
		}
//		DD(A);DD(B);
		A = A&((1LL<<r)-1);
		B = B&((1LL<<r)-1);

		// 0... だけつかう -> [A, 2^(r-1))
		ll r00 = A;
		ll r01 = (1LL<<(r-1))-1;
		ll k = 0;
		REP(i, r-1) {
			if(b[N-1-i]=='1') k=i+1;
		}
		// 1... だけつかう -> [2^(r-1), 2^(r-1)+2^k-1]
		ll r10 = 1LL<<(r-1);
		ll r11 = r10 + (1LL<<k)-1;
		// 0... 1... をつかう -> [2^(r-1)+A, 2^r)
		ll r20 = (1LL<<(r-1))+A;
		ll r21 = (1LL<<r)-1;
//		DD(a);DD(b);DD(A);DD(B);DD(r);DD(k);DD(r00);DD(r01);DD(r10);DD(r11);DD(r20);DD(r21);
		ll ans = max(0LL, r01-r00+1) + max(0LL, r11-r10+1) + max(0LL, r21-r20+1) - max(0LL, r11-r20+1);
		cout<<ans<<endl;
	}
	
	return 0;
}
