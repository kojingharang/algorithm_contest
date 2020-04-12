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

map<int, int> factorize(int n, const VI& primes) { // 60(==2**2 * 3**1 * 5**1), table -> ([2,3,5], [2,1,1])   time:
	map<int, int> out;
	REP(i, primes.size()) {
		int co=0;
		while(n%primes[i]==0) { n/=primes[i]; co++; }
		if(co) { out[primes[i]] = co; }
	}
	if(n>1) { out[n] = 1;}
	return out;
}

VI make_primes(int N) {
	vector<bool> p(N, true);
	VI out;
	for(int i=2;i*i<=N;i++) if(p[i]) { out.PB(i); for(int j=i*2;j<N;j+=i) p[j]=false; }
//	DD(p);
	for(int i=2;i<N;i++) if(p[i]) out.PB(i);
	return out;
}
/*
350000000

75 = 3^1*5^2 *x^8
45 = 3^2*5^1 *x^4
gcd = 3*5=15

A/gcd = 3^0*5^1*x^4
B/gcd = 3^1*5^0*x^0
gcd   = 3^1*5^1*x^4

max/min = 3^1*5^1*x^4


全素数piについて
A=Πpi^ai
B=Πpi^bi
として
(ai+bi) = 3Mi, Mi <= min(ai, bi)ならOK

A*B = p^3M0 p^3M1 p^3M2..
x = p^M0 p^M1 p^M2..
g = p^k0 p^k1 p^k2..
pすべてについて Mi <= ki ならOK

<==>

A*B == x**3 && gcd(x, gcd(A, B))==x



A*B = p^3M0 p^3M1 p^3M2
x = p^M0 p^M1 p^M2
g = p^k0 p^k1 p^k2
pすべてについて Mi <= ki ならいい
<==>
gcd(x, g)==x

//x <= g ならOK

1+2 = 

max/min = A*B/gcd/gcd
min+max = x^3

k^2
k^1

k in gcd

6 6 -> 0 0
5 7 -> 0 2
4 8 -> 0 4

27 = 3^3
216 = 2^3 * 3^3
x = 18 = 2^1*3^2
g = 27 = 3^3
gcd(x, g) = 9 = 3^2

gcd = min
lcd = max
*/
VI ps;
bool naive(ll A, ll B) {
	auto as = factorize(A, ps);
	auto bs = factorize(B, ps);
//			DD(as);
//			DD(bs);
	set<int> ks;
	for(auto kv:as) ks.insert(kv.first);
	for(auto kv:bs) ks.insert(kv.first);
	bool ok=1;
//			DD(ks);
	for(auto k:ks) {
		ll a = as[k];
		ll b = bs[k];
		if(a>b) swap(a, b);
		if(!((a+b)%3==0 && (a+b)/3 <= a)) ok=false;
	}
	return ok;
}
bool solve(ll A, ll B) {
	// lcm = A*B/gcd
	ll v = A*B;
	ll v3 = pow(v, 1.0/3);
	bool ok=0;
	ll v3ok=0;
	for(int d=-1;d<=1;d++) {
		if((v3+d)*(v3+d)*(v3+d)==v) {
			ok=1;
			v3ok=v3+d;
		}
	}
	ll g=__gcd(A, B);
	if(ok) {
		if(!(__gcd(v3ok, g)==v3ok)) ok=0;
	}
	return ok;
}

int main() {
	ios::sync_with_stdio(false);
	if(0)
	{
		ps = make_primes(100000);
		if(0)
		REP(i, 10000) {
			ll A = UNIFORM_LL(1, 1000);
			ll B = UNIFORM_LL(1, 1000);
			A=B=1;
			REP(j, 20) {
				bool w = UNIFORM_LL(0, 1000)<500;
				if(w) continue;
				REP(k, 3) {
					if(A*ps[j]*ps[j]<1000000000 && B*ps[j]*ps[j]<1000000000) {
						bool w = UNIFORM_LL(0, 1000)<500;
	//					DD(ps[j]);
						A *= ps[j];
						B *= ps[j];
						if(w) A *= ps[j];
						else  B *= ps[j];
						if(UNIFORM_LL(0, 1000)<10) A++;
					}
				}
			}
			if(A>1000000000 || B>1000000000) continue;
			bool ref = naive(A, B);
			bool ans = solve(A, B);
			DD(A);
			DD(B);
			DD(ref);
			DD(ans);
			assert(ref==ans);
		}
		RANGE(A, 1, 1000)
		RANGE(B, 1, 1000)
		{
//			ll A=27;
//			ll B=216;
			bool ref = naive(A, B);
			bool ans = solve(A, B);
			DD(A);
			DD(B);
			DD(ref);
			DD(ans);
			assert(ref==ans);
		}
		return 0;
	}

//	DD(ps.size());
	ll N,A,B;
	while(cin>>N) {
		REP(i, N) {
			cin>>A>>B;
//			bool ref = naive(A, B);
			bool ans = solve(A, B);
			if(ans) printf("Yes\n");
			else printf("No\n");
//			assert(ref==ans);
		}
	}
	
	return 0;
}
