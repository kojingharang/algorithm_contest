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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,M,K;
	while(cin>>N) {
		vector<deque<ll>> l(N);
		set<ll> rm2;
		VI t2(N);
		// t, idx
		priority_queue<PII> q1, q2;
		REP(i, N) {
			cin>>K;
			REP(j, K) {
				ll T;
				cin>>T;
				l[i].PB(T);
			}
		}
//		REP(i, N) DD(l[i]);
		REP(i, N) {
			if(l[i].size()) {
				ll t = l[i].front();
				l[i].pop_front();
				q1.push(MP(t, i));
			}
			if(l[i].size()) {
				ll t = l[i].front();
				l[i].pop_front();
				t2[i] = t;
				q2.push(MP(t, i));
			}
		}
//		REP(i, N) DD(l[i]);
//		DD(t2);
		cin>>M;
		REP(i, M) {
			ll a;
			cin>>a;
			ll ans=0;
			if(a==1) {
				PII take = q1.top();
				q1.pop();
				// fill q1
				if(t2[take.SE]) q1.push(MP(t2[take.SE], take.SE));
				rm2.insert(t2[take.SE]);
				// fill q2
				ll t = 0;
				if(l[take.SE].size()) {
					t = l[take.SE].front();
					l[take.SE].pop_front();
					q2.push(MP(t, take.SE));
				}
				t2[take.SE] = t;
				ans = take.FI;
			} else {
				PII take1 = MP(0, 0);
				if(q1.size()) take1 = q1.top();
				PII take2 = MP(0, 0);
				while(q2.size()) {
					PII take2_ = q2.top();
					if(!rm2.count(take2_.FI)) {
						take2 = take2_;
						break;
					}
					q2.pop();
					rm2.erase(take2.FI);
				}
				if(take1.FI>0 && take1.FI > take2.FI) {
					q1.pop();
					auto take = take1;

					// fill q1
					if(t2[take.SE]) q1.push(MP(t2[take.SE], take.SE));
					rm2.insert(t2[take.SE]);
					// fill q2
					ll t = 0;
					if(l[take.SE].size()) {
						t = l[take.SE].front();
						l[take.SE].pop_front();
						q2.push(MP(t, take.SE));
					}
					t2[take.SE] = t;
					ans = take.FI;
				} else {
					q2.pop();
					auto take = take2;

					// fill q2
					ll t = 0;
					if(l[take.SE].size()) {
						t = l[take.SE].front();
						l[take.SE].pop_front();
						q2.push(MP(t, take.SE));
					}
					t2[take.SE] = t;
					ans = take.FI;
				}
			}
//			DD(q1.size());
//			DD(q2.size());
//			DD(t2);
//			REP(i, N) DD(l[i]);
			cout<<ans<<endl;
		}
//		break;
	}
	
	return 0;
}
