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

/*
l, r が決まった時、全 m に対して f(l,m), f(m+1,r) が高速に求まるか?
奇数回現れる文字が回文にならない原因なので、その文字が変化するところだけ調べる
l, r が回文じゃないとき、f(l,m)が1なmすべてに対してf(m+1,r)を呼ぶ
	最大のmだけについてやってみる? -> sampleでだめ
*/
string s;
VVI nxt; // [c][i] : i以降で最初のcのindex
VI isOdd(26);
map<PII, ll> memo;
// [l, r]
ll f(ll l, ll r, ll N, VVI& hi) {
	auto key = MP(l, r);
	if(memo.count(key)) return memo[key];

	ll odd = 0;
//	cout<<" f "<<l<<" "<<r<<endl;
//	DD(l);
//	DD(r);
	REP(c, 26) if((hi[c][r+1] - hi[c][l-1+1])%2==1) odd++,isOdd[c]=1;
//	DD(odd);
	if(odd<=1) {
		return memo[key] = 1;
	} else {
		ll lans = 1LL<<60;
//		for(int m = r-1;m>=l;m--) {
//			ll odd = 0;
//			REP(c, 26) if((hi[c][m+1] - hi[c][l-1+1])%2==1) odd++;
//			if(odd<=1) {
//				lans = min(lans, f(l, m, N, hi)+f(m+1, r, N, hi));
////				break;
//			}
//		}
//		return memo[key] = lans;
		REP(c, 26) if(isOdd[c]) {
			// here l < N-1
//			DD(l);
			ll m = s[l]==c ? 1 : nxt[c][l+1];
			if(m==-1) continue;
			m--;
			ll odd = 0;
			REP(c, 26) if((hi[c][m+1] - hi[c][l-1+1])%2==1) odd++;
			if(odd<=1) {
//			DD(c);
//			DD(l);
//			DD(r);
//			DD(m);
//		RANGE(m, l, r) {
			if(m<r)
			lans = min(lans, f(l, m, N, hi)+f(m+1, r, N, hi));
//			break;
			}
		}
		return memo[key] = lans;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	while(cin>>s) {
		memo.clear();
		ll N = s.size();
		nxt = VVI(26, VI(N, -1));
		VVI hi(26, VI(N+1)); // [c][i] : count s[j] for j in [0, i)
		REP(i, N) {
			REP(j, 26) hi[j][i+1] = hi[j][i];
			hi[s[i]-'a'][i+1]++;
		}
		for(ll i=N-1;i>=0;i--) {
			if(i+1<N) REP(c, 26) nxt[c][i] = nxt[c][i+1];
			nxt[s[i]-'a'][i] = i;
		}
//		DD(nxt);
//		DD(hi);
		ll ans = f(0, N-1, N, hi);
		cout<<ans<<endl;
	}
	
	return 0;
}
