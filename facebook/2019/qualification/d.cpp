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
increase stack size!!!!!!
// 16MB
g++ -O2 -Wl,-stack_size,10000000 -std=c++11 -Wall d.cpp && ./a.out < corporate_gifting.txt > do2.txt
*/

int main() {
	//ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		ll N, M, X, Y, Z;
		cin>>N>>M;
		VI XS(M), YS(M), ZS(M);
		vector<set<ll>> CH(N);
		REP(i, M) {
			cin>>X>>Y>>Z;
			X--;Y--;Z--;
			if(Z!=X) CH[Z].insert(X);
			if(Z!=Y) CH[Z].insert(Y);
			XS[i]=X;
			YS[i]=Y;
			ZS[i]=Z;
		}
		VI vis(N);
		ll visC=0;
		ll ok = 1;
		VI pa(N, -1);
		ll root = -1;
		VI depth(N);
		while(visC<N) {
			ll upd = 0;
			REP(i, N) if(!vis[i]) {
				ll noch = 1;
				REP(j, N) if(!vis[j] && CH[j].count(i)) {noch = 0;break;}
				if(noch) {
					if(visC) {
						pa[i] = root;
						ll md = -1;
						REP(pi, N) {
							if(CH[pi].count(i)) {
								if(md < depth[pi]) {
									pa[i] = pi;
									depth[i] = depth[pi]+1;
								}
							}
						}
					} else {
						root = i;
					}
					vis[i]=1;
					visC++;
//					DD(i+1);
					upd=1;
				}
			}
			if(!upd) {ok=0;break;}
		}
//		DD(depth);
		if(ok) {
			auto pf = [&](ll i) {
				VI p;
				p.PB(i);
				while(pa[i]!=-1) {
					i = pa[i];
					p.PB(i);
				}
				reverse(ALL(p));
				return p;
			};
			REP(i, N) REP(j, N) if(i!=j) {
				VI p0 = pf(i);
				VI p1 = pf(j);
				ll lca = -1;
				REP(i, min(p0.size(), p1.size())) {
					if(p0[i]!=p1[i]) {
						break;
					} else {
						lca = p0[i];
					}
				}
				REP(mi, M) {
					if(XS[mi]==i&&YS[mi]==j&&ZS[mi]!=lca) ok=0;
				}
			}
		}
		if(ok) {
			cout<<"Case #"<<CaseID+1<<": ";
			REP(i, N) {
				cout<<pa[i]+1;
				if(i<N-1) cout<<" ";
			}
			cout<<endl;
		} else {
			cout<<"Case #"<<CaseID+1<<": "<<"Impossible"<<endl;
		}
//		break;
	}
	
	return 0;
}
