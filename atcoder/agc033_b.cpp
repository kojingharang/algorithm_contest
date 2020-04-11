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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,W,H;
	VI D(2);//x,y
	VI P(2);
	vector<string> S(2);
	while(cin>>D[1]>>D[0]>>N>>P[1]>>P[0]>>S[0]>>S[1]) {
		// player, axis(x==0,y), min/max
		VVVI rng(2, VVI(2, VI(2)));
		string ans = "YES";
		REP(i, N) {
			REP(pi, 2) {
				if(S[pi][i]=='D') rng[pi][1][1]++;
				if(S[pi][i]=='U') rng[pi][1][0]--;
				if(S[pi][i]=='R') rng[pi][0][1]++;
				if(S[pi][i]=='L') rng[pi][0][0]--;
				if(pi==0) REP(ai, 2) {
					if(P[ai]+rng[pi][ai][0]+rng[1-pi][ai][1] < 1) ans = "NO";
					if(P[ai]+rng[pi][ai][1]+rng[1-pi][ai][0] > D[ai]) ans = "NO";
				}
				if(pi==1) {
					REP(ai, 2) {
						minUpdate(rng[pi][ai][1], D[ai]+rng[1-pi][ai][1]-P[ai]);
						maxUpdate(rng[pi][ai][0], -(P[ai]-(1+rng[1-pi][ai][0])));
					}
				}
//				if(pi==0) DD(rng);
			}
		}
		
		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}
