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
100以下なら1連続。
100より大きいなら100ひいたうえで
1,1から移動しながら大きければ行全部つかう
あまりを1連続
*/
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int test_cases;
	cin>>test_cases;
	ll N,M,W,H;
	string s;
	REP(ttt, test_cases) {
		cin>>N;
//		DD(p2);
		bool L=true;
		cout<<"Case #"<<ttt+1<<":"<<endl;
		ll rest = 31;
		if(N<=rest) {
			REP(i, N) cout<<1+i<<" "<<1<<endl;
		} else {
			ll M = N-rest;
			ll p2 = 1;
			while(1<<p2 <= M) p2++;
			ll r=1;
//			DD(M);
//			DD(p2);
			REP(i, p2) {
				ll sum = 1LL<<(r-1);
//				DD(M);
//				DD(sum);
				if(M&sum) {
					if(L) {
						REP(i, r) cout<<r<<" "<<i+1<<endl;
					} else {
						REPR(i, r) cout<<r<<" "<<i+1<<endl;
					}
					L=!L;
					M-=sum;
				} else {
					cout<<r<<" "<<(L?1:r)<<endl;
					rest--;
				}
				r++;
			}
//			DD(M);
//			DD(p2);
//			DD(rest);
			assert(M==0);
			REP(i, rest) {
				cout<<r<<" "<<(L?1:r)<<endl;
				r++;
			}
		}
//		return 0;
	}
	return 0;
}



