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
template<typename T>
struct BIT {
	vector<T> w;
	BIT(int N) { w = vector<T>(N); }
	// sum of w[i], i in [l, r]
	T sum(int l, int r) {
		if(l==0) {
			T s=0;
			for(;r>=0;r=(r&(r+1))-1) s+=w[r];
			return s;
		}
		return sum(0, r) - sum(0, l-1);
	}
	// i in [0, N)
	void add(int i, T v) {
		for(;i<(int)w.size();i|=i+1) w[i] += v;
	}
};

// 転倒数. i, j in [0, N) のうち i<j and d[i]>d[j] な個数
// O(NlogM) d[i] in [0, M)
template<typename T>
ll inversion_number(const vector<T>& d) {
	ll N = d.size();
	T M = *max_element(ALL(d))+1;
	BIT<T> bit(M);
	ll cnt = 0;
	for(int i=N-1;i>=0;i--) {
		cnt += bit.sum(0, d[i]-1);
		bit.add(d[i], 1);
	}
	return cnt;
}

// i, j in [0, N) のうち i<j and d[i]>d[j] な個数
template<typename T>
ll iv(const vector<T>& d) {
	ll N = d.size();
	ll cnt = 0;
	REP(i, N) RANGE(j, i+1, N) if(d[i]>d[j]) cnt++;
	return cnt;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,M,W,H;
	string s;
	if(0)
	REP(i, 100) {
		N = 3;
		VI w(N);
		REP(i, N) w[i]=UNIFORM_LL(0, 2*N);
		ll r = iv(w);
		ll t = inversion_number(w);
		DD(w);
		DD(r);
		DD(t);
		assert(r==t);
//		return 0;
	}
	while(cin>>N) {
		VI w(N);
		REP(i, N) cin>>w[i];
		// M要素数列の中央値が x ... x以上の数字がceil(M/2)個以上あるようなxのうち最大のもの
		// mij (N(N+1)/2個)の中央値が x ... x以上の数字が ceil(N(N+1)/4) 個以上あるようなxのうち最大のもの
		// N(N+1)/2個の区間のうち、x以上の数がceil((r-l+1)/2)個以上ある区間の数が ceil(N(N+1)/4) 個以上あるような x のうち最大のもの
		// x未満を-1, x以上を1とおくと, 区間内の和が0以上
		ll lo=0, hi=1LL<<40; // lo is OK
		while(lo+1<hi) {
			ll x = (lo+hi)/2;
			VI b(N);
			REP(i, N) b[i] = x <= w[i] ? 1 : -1;
//			DD(x);
//			DD(b);
			VI s(N+1); // [i] ... sum of [0, i). sum of [i, j) == s[j]-s[i]
			RANGE(i, 1, N+1) {
				s[i] = s[i-1] + b[i-1];
			}
			// (i, j) 0<=i<j<=N のうち s[i]<=s[j]のものの個数
			REP(i, s.size()) s[i] += s.size();
//			ll v = N*(N+1)/2 - iv(s);
//			DD(s);
//			DD(iv(s));
//			DD(inversion_number(s));
			ll v = N*(N+1)/2 - inversion_number(s);
//			DD(s);
//			DD(v);
			if((N*(N+1)/2+1)/2 <= v) lo=x; else hi=x;
		}
		cout<<lo<<endl;
//		break;
	}
	
	return 0;
}
