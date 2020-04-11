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

ll ref(ll T1, ll T2, ll A1, ll A2, ll B1, ll B2) {
    long long X = T1*(A1-B1);
    long long Y = T2*(A2-B2);
    if (X<0)
        X *= -1,
        Y *= -1;
    if (X+Y>0) return 0;
    if (X+Y==0) return -1;
    if (X+Y<0)
    {
        long long t = -(X+Y);
        return(X/t)*2+1-(X%t==0?1:0);
    }
    return -1;
}
ll solve(ll T1, ll T2, ll A1, ll A2, ll B1, ll B2) {
	ll R1 = (B1-A1)*T1;
	ll R2 = (B2-A2)*T2;
	auto f = [&]() {
//		DD(R1);DD(R2);
		if(R1+R2==0) return -1LL;
		if(0 > R1) {R1=-R1;R2=-R2;}
		// now 0 < R1
		ll R12=R1+R2;
		if(0 < R12) return 0LL;
		// now 0 < R1 && R1+R2 < 0
//		DD(R1/R12);DD(R12);
		ll ans = 0;
		ll pos = 0;
		ll i = 0;
		bool skipDone=false;
		while(1) {
			if(1<i && !skipDone) {
				ll cnt = R1/abs(R12);
				ll skip = max(0LL, cnt-10000);
//				DD(skip);
				if(skip) {
//					DD(pos+R12*skip);
//					DD(ans+2*skip);
					pos += R12 * skip;
					ans += 2 * skip;
					skipDone = true;
				}
			}
			bool x = false;
			if(pos<0 && 0<=pos+R1) ans++,x=true;
			if(0<pos+R1 && pos+R12<0) ans++,x=true;
			if(!x) break;
			pos += R12;
			i++;
//			DD(pos);DD(ans);
		}
		return ans;
	};
	return f();
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll T1, T2, A1, A2, B1, B2;
	if(0)
	REP(loop, 100000) {
		ll T1 = UNIFORM_LL(1, 100001);
		ll T2 = UNIFORM_LL(1, 100001);
		ll A1 = UNIFORM_LL(1, 10000000001LL);
		ll A2 = UNIFORM_LL(1, 10000000001LL);
		ll B1 = UNIFORM_LL(1, 10000000001LL);
		ll B2 = UNIFORM_LL(1, 10000000001LL);
		ll t0 = solve(T1, T2, A1, A2, B1, B2);
		ll tr = ref(T1, T2, A1, A2, B1, B2);
		if(t0!=tr) {
			DD(t0);
			DD(tr);
			DD(T1);
			DD(T2);
			DD(A1);
			DD(A2);
			DD(B1);
			DD(B2);
			return 0;
		}
	}
	while(cin>>T1>>T2>>A1>>A2>>B1>>B2) {
		ll ans = solve(T1, T2, A1, A2, B1, B2);
		if(ans==-1) cout<<"infinity"<<endl;
		else cout<<ans<<endl;
	}
	
	return 0;
}
