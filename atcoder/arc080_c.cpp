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

struct Min {
	// (value, index)
	typedef pair<ll, ll> valueType;
	static valueType e() {
		return MP(1LL<<60, 0);
	}
	static valueType op(valueType a, valueType b) {
		return min(a, b);
	}
};

template<typename Traits>
class SegTree {
public:
	typedef typename Traits::valueType T;
	int N;
	vector<T> dat;
	SegTree(int _N) {
		N=1; while(N<_N) N*=2;
		dat = vector<T>(2*N, Traits::e());
	}
	// idx is 0 base
	void update(int idx, T v) {
		idx += N-1;
		dat[idx] = v;
		while(idx>0) {
			idx = (idx-1)/2;
			dat[idx] = Traits::op(dat[idx*2+1], dat[idx*2+2]);
		}
	}
	// [a, b)
	T query(int a, int b) { return query(a, b, 0, 0, N); }
	T query(int a, int b, int k, int l, int r) {
		if(r<=a || b<=l) return Traits::e();
		if(a<=l && r<=b) return dat[k];
		else {
			T vl = query(a, b, k*2+1, l, (l+r)/2);
			T vr = query(a, b, k*2+2, (l+r)/2, r);
			return Traits::op(vl, vr);
		}
	}
};

// (head value, (s, e)) ... [s, e]
typedef pair<ll, pair<ll, ll>> Range;

VI naive0(VI w) {
	ll N = w.size();
	VI I(N-1);
	REP(i, N-1) I[i]=i;
	ll INF = 1LL<<60;
	VI ans(N, INF);
	do {
		VI ww(w);
		VI lans;
		REP(i, N-1) {
			ll i1 = I[i];
			if(ww[i1]<INF) {
				ll i2 = i1+1;
				while(i2<N && ww[i2]==INF) i2++;
				if(i2<N && ww[i2]<INF) {
					lans.PB(ww[i2]);
					lans.PB(ww[i1]);
//					DD(i1);
//					DD(i2);
					ww[i1] = INF;
					ww[i2] = INF;
				}
			}
		}
		reverse(ALL(lans));
//		DD(I);
//		DD(lans);
		ans = min(ans, lans);
	} while(next_permutation(ALL(I)));
	return ans;
}
VI naive(VI w) {
	ll N = w.size();
	set<PII> rs;
	rs.insert(MP(0, N-1));
	VI ans;
	while(rs.size()) {
		ll minL=1LL<<60;
//		DD(rs);
		for(auto r : rs) {
			ll s, e;
			tie(s, e) = r;
			for(int i=s;i<=e;i+=2) {
				minL = min(minL, w[i]);
			}
		}
		ll ss, ee;
		ll i1, i2;
		for(auto r : rs) {
			ll s, e;
			tie(s, e) = r;
			for(int i=s;i<=e;i+=2) {
				if(w[i]==minL) {
					ll minRi = i+1;
					for(int j=i+1;j<=e;j+=2) {
						if(w[j]<w[minRi]) minRi=j;
					}
					i1 = i;
					i2 = minRi;
					ss = s;
					ee = e;
				}
			}
		}
		ans.PB(w[i1]);
		ans.PB(w[i2]);
		w[i1] = w[i2] = 1LL<<60;
		rs.erase(MP(ss, ee));
		if(ss<i1-1) rs.insert(MP(ss, i1-1));
		if(i1+1<i2-1) rs.insert(MP(i1+1, i2-1));
		if(i2+1<ee) rs.insert(MP(i2+1, ee));
	}
	return ans;
}

VI solve(VI w) {
	ll N = w.size();
	vector<SegTree<Min>> st(2, SegTree<Min>(N));
	REP(i, N) {
		st[i%2].update(i, MP(w[i], i));
	}

	priority_queue<Range, vector<Range>, greater<Range>> q;
	q.push(MP(w[0], MP(0, N-1)));

	VI ans;
	auto Push = [&](ll s, ll e) {
		if(s < e) q.push(MP(st[s%2].query(s, e+1).first, MP(s, e)));
	};
	while(q.size()) {
		ll rmv, s, e;
		forward_as_tuple(rmv, tie(s, e)) = q.top();
//		DD("pop");
//		DD(rmv);
//		DD(s);
//		DD(e);
		q.pop();
		ll p1, p1i, p2, p2i;
		tie(p1, p1i) = st[s%2].query(s, e+1);
		ans.PB(p1);
		tie(p2, p2i) = st[1-s%2].query(p1i+1, e+1);
		ans.PB(p2);
		Push(s, p1i-1);
		Push(p1i+1, p2i-1);
		Push(p2i+1, e);
	}
	return ans;
}

int main() {
	if(0)
	{
		REP(ts, 1000) {
			ll N = UNIFORM_LL(1, 6)*2;
			VI w(N);
			REP(i, N) w[i] = i+1;
			random_shuffle(ALL(w));
//			w = {6, 7, 1, 8, 4, 5, 3, 2};
			auto ref0 = naive0(w);
			auto ref = naive(w);
			auto ans = solve(w);
			DD(N);
			DD(w);
			DD(ref0);
			DD(ref);
			DD(ans);
			assert(ref0==ref);
			assert(ref==ans);
		}
		return 0;
	}
	//ios::sync_with_stdio(false);
	ll N, v;
	while(cin>>N) {
		VI w(N);
		REP(i, N) cin>>w[i];
		auto ans = solve(w);
//		auto ans = naive(w);
		cout<<ans<<endl;
	}
	
	return 0;
}
