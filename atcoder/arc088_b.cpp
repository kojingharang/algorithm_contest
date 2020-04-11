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
左から貪欲に0にして、左から連続K個以上0があればOK

101100
100100 a
010100
110110 a
001000

*/
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	while(cin>>s) {
		ll ans = 0;

		{
			ll N = s.size();
			ll lo = 1, hi = N+1;
			while(lo+1<hi) {
				ll k = (lo+hi)/2;
				ll L = k-1;
				ll R = N-k;
				bool ok = 1;
				RANGE(i, R, L+1) if(s[i]!=s[L]) ok=0;
//				DD(k);
//				DD(L);
//				DD(R);
//				DD(ok);
				(ok?lo:hi) = k;
			}
			cout<<lo<<endl;
			continue;
		}

		ll N = s.size();
		ll co = count(ALL(s), '0');
		if(co==0 || co==N) {
			ans = N;
		} else {
			ll lo=1, hi=N; // lo is possible
			while(lo+1<hi) {
				ll mid = (lo+hi)/2;
				vector<bool> acc(N+1);
//				DD(mid);
				bool a=0;
				REP(i, N) {
					if(i+mid-1 > N-1) break;
					a ^= acc[i];
					if(((s[i]-'0')^a)==1) {
						a=!a;
						acc[i]=!acc[i];
						acc[i+mid]=!acc[i+mid];
//						REP(j, mid) {
//							ss[i+j] = ss[i+j]=='0' ? '1' : '0';
//						}
					}
//					DD(acc);
				}
//				DD(ss);
				bool ok=1;
				a=0;
				REP(i, mid) {
					a^=acc[i];
					if(((s[i]-'0')^a)==1) ok=0;
				}
//				REP(i, mid) if(ss[i]=='1') ok=0;
				if(ok) lo=mid; else hi=mid;
			}
			ans = lo;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
