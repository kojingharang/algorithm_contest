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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


ll MOD;
ll Pow(ll v, int e) {
	return e==0 ? 1:
		e%2==0 ? Pow(v*v%MOD, e/2) : v * Pow(v, e-1) %MOD;
}
ll powsum(ll v, int e) {
	return e==0 ? 1 :
		e%2==0 ? (Pow(v, e) + powsum(v, e-1))%MOD : ((1 + Pow(v, (e+1)/2))%MOD) * powsum(v, (e+1)/2-1)%MOD;
}
ll ndigits(ll v) {
	ll o = 0;
	while(v) {
		o++;
		v/=10;
	}
	return o;
}
ll pow10(ll v) {
	ll o=1;
	REP(i, v) o*=10;
	return o;
}

int main() {
	//ios::sync_with_stdio(false);
	
//	mat shift = mat(1, array(1, pow10(3)));
//	cout<<pow(shift, 0)<<endl;
//	cout<<pow(shift, 1)<<endl;
//	cout<<pow(shift, 2)<<endl;
//	cout<<powsum(shift, 0)<<endl;
//	cout<<powsum(shift, 1)<<endl;
//	cout<<powsum(shift, 2)<<endl;
//	return 0;
	ll N;
	while(cin>>N) {
		VI A(N), L(N);
		REP(i, N) {
			cin>>A[i]>>L[i];
		}
		cin>>MOD;
		ll ans = 0;
		REP(i, N) {
			ll nd = ndigits(A[i]);
			ans = (ans * Pow(pow10(nd)%MOD, L[i]))%MOD;
//			cout<<i<<" "<<ans<<endl;
			
			ans = ( ans + A[i]%MOD * powsum(pow10(nd)%MOD, L[i]-1) )%MOD;
//			cout<<":: "<<A[i]<<" "<<nd<<" "<<powsum(shift, L[i]-1)[0][0]<<endl;
//			cout<<i<<" "<<ans<<endl;
		}
		
		cout<<(ans+MOD)%MOD<<endl;
//		break;
	}
	
	return 0;
}
