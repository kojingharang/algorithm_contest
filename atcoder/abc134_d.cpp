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


void test(VI A, VI w) {
	ll N = A.size();
	DD(A);
	DD(w);
	ll ok=1;
	REP(i, N) {
		ll cnt = 0;
		ll I = i+1;
		for(ll j=I;j<=N;j+=I) cnt ^= w[j-1];
		cout<<"I "<<I<<" "<<A[i]<<" "<<cnt<<endl;
		if(A[i]!=cnt) {
			ok=0;
			DD("NG");
		}
	}
	assert(ok);
}

// I未満の約数を全部反転
void inv(VI& w, ll I) {
//	DD(I);
	ll N = w.size();
	for(ll J=1;J*J<=I;J++) if(I%J==0) {
		ll j = J-1;
		if(J<I) {
			w[j] ^= 1;
//			cout<<I<<" Call J "<<J<<endl;
			inv(w, J);
		}
		if(J*J!=I && I/J<I) {
			w[I/J-1] ^= 1;
//			cout<<I<<" Call I/J "<<I/J<<endl;
			inv(w, I/J);
		}
	}
}

VI solve(VI A) {
	ll N = A.size();
	VI w(N);
	REPR(i, N) {
		ll I = i+1;
		if(A[i]) {
			w[i] ^= 1;
			inv(w, I);
		}
//		DD(w);
	}
//	test(A, w);
	return w;
}

VI solve2(VI A) {
	ll N = A.size();
	VI w(N);
	REPR(i, N) {
		ll I = i+1;
		ll p = 0;
		for(ll J=I;J<=N;J+=I) {
			p ^= w[J-1];
		}
		w[i] = A[i] ^ p;
//		DD(w);
	}
//	test(A, w);
	return w;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	if(0)
	REP(loop, 100) {
		N = 10;
		VI A(N);
		REP(i, N) A[i] = UNIFORM_LL(0, 2);
		VI w = solve2(A);
		test(A, w);
	}
	while(cin>>N) {
		VI A(N);
		REP(i, N) cin>>A[i];
//		DD(A);
		VI w = solve2(A);
//		DD(w);
		ll M = accumulate(ALL(w), 0LL);
		cout<<M<<endl;
		ll m = 0;
		REP(i, N) if(w[i]) {
			cout<<i+1;
			m++;
			if(m<M) cout<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
