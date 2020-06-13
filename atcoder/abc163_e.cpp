#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>
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
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define VVVI vector<vector<vector<ll>>>
#define VVVVI vector<vector<vector<vector<ll>>>>
#define REP(i,n) for(ll i=0,_n=(n);(i)<(ll)_n;++i)
#define REPR(i,n) for(ll i=(ll)(n)-1;0<=(i);--i)
#define RANGE(i,a,b) for(ll i=(ll)a,_b=(ll)(b);(i)<_b;++i)
#define RANGER(i,a,b) for(ll i=(ll)(b)-1,_a=(ll)(a);(_a)<=i;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
#define FI first
#define SE second
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}
string YN(bool v) { return v ? "Yes":"No"; }
void uniq(VI& es) { sort(ALL(es)); es.erase(unique(ALL(es)), es.end()); }

#define INF (1LL<<60)

ll f(VI A) {
	ll N=A.size();
	VI I(N);
	REP(i, N) I[i]=i;
	ll mx=0;
	do{
		ll v=0;
		VI a(N);
		REP(i, N) a[i]=A[I[i]];
		REP(i, N) v+=abs(i-I[i])*A[I[i]];
		maxUpdate(mx, v);
//			DD(I);DD(a);DD(v);
	}while(next_permutation(ALL(I)));
	set<VI> ss;
	do{
		ll v=0;
		VI a(N);
		REP(i, N) a[i]=A[I[i]];
		REP(i, N) v+=abs(i-I[i])*A[I[i]];
		if(mx==v) {
//				DD(I);DD(a);DD(v);
			ss.insert(a);
		}
	}while(next_permutation(ALL(I)));
//	DD(mx);
	DD(ss);
	return mx;
}
/*
アイデア
	A[i]*|x-y|というコスト関数の性質により1個ずつ動かした時のコストに分解できる
		iをjにうごかしたときのコストを列挙しておいて????
		N^2個の差分をソートして大きい方から採用?
	N^2やN^2logNまでOK
		バブルソート的な
	最小費用流?
		FElogVでE=N^2,FがN*10^9ででかすぎる
	優先する数字を決めてあとは貪欲
		厳密解と一致しない場合がある
	ある数字の最終位置は2通りくらいに絞られないか?
		→最終位置ではないが左or右の2通りだった
*/
ll h(VI A) {
	ll N=A.size();
//	DD(A);
	vector<PII> a(N);
	REP(i, N) a[i]=MP(A[i], i);
	sort(ALLR(a));
//	DD(a);
	VVI dp(N+1, VI(N+1));
	REP(i, N) {
		//A[i]を置く.
		// すでに置かれてるのはi個
		REP(nl, i+1) {
			ll nr = i-nl;
			// put left
			maxUpdate(dp[nl+1][nr], dp[nl][nr] + abs(nl-a[i].SE)*a[i].FI);
			// put right
			maxUpdate(dp[nl][nr+1], dp[nl][nr] + abs(N-1-nr-a[i].SE)*a[i].FI);
		}
//		DD(i);
//		DD(dp);
	}
//	DD(dp);
	ll ans=0;
	REP(i, N+1) maxUpdate(ans, dp[i][N-i]);
	return ans;
}
int main() {
	if(0)
	REP(loop, 1000) {
		ll N=6;
		VI A(N);
		REP(i, N) A[i]=UNIFORM_LL(0, 100);
		ll ref=f(A);
		ll a=h(A);
		if(ref!=a) {
			DD(A);DD(ref);DD(a);
			return 0;
		}
	}

	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
		VI A(N);
		REP(i, N) cin>>A[i];
//		f(A);
		ll ans = h(A);
		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}
