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
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

struct Entry {
	ll s, e, type;
};

int main() {
	int test_cases;
	cin>>test_cases;
	ll A,B, s, e;
	REP(ttt, test_cases) {
		cin>>A>>B;
		ll ra = 720, rb = 720;
		ll fr = 1440;
		vector<Entry> es;
		REP(i, A) {
			cin>>s>>e;
			ra -= e-s;
			fr -= e-s;
			es.push_back(Entry{s, e, 1});
		}
		REP(i, B) {
			cin>>s>>e;
			rb -= e-s;
			fr -= e-s;
			es.push_back(Entry{s, e, -1});
		}
//		DD(ra);
//		DD(rb);
//		DD(tl);
		VI pa, pb; // dur
		ll N = 1440;
		sort(ALL(es), [](const Entry& a, const Entry& b){return a.s<b.s;});

		ll ans = 0;
		ll M = es.size();
		REP(i, M) {
			ll ni = (i+1)%M;
			if(es[i].e%N != es[ni].s%N) {
				// すきまはっけん
				if(es[i].type == es[ni].type) {
					ll dur = (es[ni].s-es[i].e+N)%N;
					if(es[i].type==1) pa.PB(dur);
					if(es[i].type==-1) pb.PB(dur);
				}
			}
			if(es[i].type!=es[ni].type) ans++;
//			DD(i);
//			DD(ans);
		}
//		DD(ans);
		
		sort(ALL(pa));
		sort(ALL(pb));
		REP(i, pa.size()) fr -= pa[i];
		REP(i, pb.size()) fr -= pb[i];
//		DD(pa);
//		DD(pb);
//		DD("begin");
//		DD(fr);
//		DD(ra);
//		DD(rb);
		REP(i, pa.size()) {
			ll use = min(ra, pa[i]);
			ra -= use;
			pa[i]-=use;
		}
		REP(i, pb.size()) {
			ll use = min(rb, pb[i]);
			rb -= use;
			pb[i]-=use;
		}
//		DD("- prefer");
//		DD(ra);
//		DD(rb);
		{
			ll use = min(ra, fr);
			ra -= use;
			fr -= use;
		}
		{
			ll use = min(rb, fr);
			rb -= use;
			fr -= use;
		}
//		DD("- no cost");
//		DD(ra);
//		DD(rb);

		REP(i, pb.size()) {
			ll use = min(ra, pb[i]);
			if(use) ans+=2;
			ra -= use;
		}
		REP(i, pa.size()) {
			ll use = min(rb, pa[i]);
			if(use) ans+=2;
			rb -= use;
		}
//		DD(ans);
//		DD(pa);
//		DD(pb);
//		DD(ra);
//		DD(rb);
		assert(ra==0);
		assert(rb==0);

		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		cout<<"\n\n\n";
//		return 0;
	}
	return 0;
}



