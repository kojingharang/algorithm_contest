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

ll sim(const vector<PII>& t) {
	ll v = 0;
	REP(i, t.size()-1) {
		v += abs(t[i].first-t[i+1].first) + abs(t[i].second-t[i+1].second);
	}
	cerr<<"Score "<<v<<endl;
	return v;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll D,K,W,H;
	while(cin>>H>>W>>D>>K) {
		vector<PII> w(D);
		REP(i, D) {
			cin>>w[i].first>>w[i].second;
		}

		VI best;
		ll bestS = 1LL<<60;
		{
			vector<PII> t(w);
			VI lans;
			REP(i, K) {
				int v = i/W%2==0 ? i%W : W-1-(i%W);
				lans.PB(v);
				lans.PB(i/W);
				lans.PB(w[i].first);
				lans.PB(w[i].second);
				t[i].first = v;
				t[i].second = i/W;
			}
			ll s = sim(t);
			if(s < bestS) {
				bestS = s;
				best = lans;
			}
		}
		{
			vector<PII> t(w);
			VI lans;
			vector<PII> aa;
			REP(i, D/2) {
				if(w[i*2].first<H-1) {
					PII p(abs(t[i*2].first-t[i*2+1].first) + abs(t[i*2].second-t[i*2+1].second), i);
				}
			}
			sort(ALLR(aa));
			REP(j, min((ll)aa.size(), K)) {
				int i = aa[j].second;
				lans.PB(w[i*2].first+1);
				lans.PB(w[i*2].second);
				lans.PB(w[i*2+1].first);
				lans.PB(w[i*2+1].second);
				t[i*2+1].first = w[i*2].first+1;
				t[i*2+1].second = w[i*2].second;
			}
			ll s = sim(t);
			if(s < bestS) {
				bestS = s;
				best = lans;
			}
		}
		REP(i, best.size()/4) {
			REP(j, 4) {
				cout<<best[i*4+j];
				if(j<3) cout<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}
