#include <vector>
#include <map>
#include <set>
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

#define MOD 1000000007LL
#define INF (1LL<<60)
/*
3
0100100100010001000000
1は反転しなくてoK
	1000000を反転するより
	000000だけ反転するほうが連続数は大きい

K回でT連続できるか?

区間内の連続0の数がわかると?
その数だけ反転すれば連続"区間長さ"までいける


*/
VI acc(string S, VI& co, VI& seqS) {
	ll N = S.size();
	ll f0 = -1;
	RANGE(i, 1, N+1) {
		if(S[i-1]=='1') {
			co[i] = co[i-1];
			f0 = i-1;
		} else {
			if(0<=i-2 && S[i-2]=='0') {
				co[i] = co[i-1];
			} else {
				co[i] = co[i-1] + 1;
				f0 = i-1;
			}
		}
		seqS[i-1] = f0;
	}
//	REP(i, N+1) {
//		ll c = 0;
//		REP(k, i) {
//			if(S[k]=='0') {
//				if(!(0<=k-1 && S[k-1]=='0')) c++;
//			}
//		}
//		assert(c==co[i]);
//	}
	return co;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,K;
	string S;
	if(0)
	{
		REP(loop, 1000) {
			ll N = 1000;
			string S(N, '0');
			REP(i, N) S[i] = UNIFORM_LL(0, 100) < 50 ? '0' : '1';
			DD(S);
			VI co(N+1), seqS(N);
			acc(S, co, seqS);
		}
		return 0;
	}
	while(cin>>N>>K>>S) {
		// [i] ... [0, i) までに含まれる連続0の個数
		VI co(N+1), seqS(N);
		acc(S, co, seqS);
//		DD(co);
//		DD(first0);
		ll ans = 0;
		REP(i, N) {
			// [i, j)で連続0がK個以下になるような最大のjに対してK回で連続j-iが作れる
			if(co[N]-co[seqS[i]] <= K) {
//				DD(i);DD(N-i);
				maxUpdate(ans, N-i);
			} else {
				// lo ... K以下
				// hi ... Kより大きい
				ll lo=i, hi=N;
				while(lo+1<hi) {
					ll mid = (lo+hi)/2;
					if(co[mid]-co[seqS[i]] <= K) lo = mid; else hi = mid;
				}
//				DD(i);DD(lo-i);
				maxUpdate(ans, lo-i);
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
