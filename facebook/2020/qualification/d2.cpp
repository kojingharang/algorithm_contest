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

// cur を根とする木 g において根から target まで至る path (頂点番号のリスト)を返す.
// deque<ll> work;
// VI result;
// pathFromRoot(g, target, 0, -1, work, result);
void pathFromRoot(const VVI& g, ll target, ll cur, ll prev, deque<ll>& work, VI& result) {
	if(result.size()) {
		return;
	}
	work.PB(cur);
	if(cur==target) {
		result = VI(ALL(work));
		return;
	}
	ll N = g.size();
	REP(i, g[cur].size()) if(prev!=g[cur][i]) {
		pathFromRoot(g, target, g[cur][i], cur, work, result);
	}
	work.pop_back();
}

// root を根とする木 g において from から to に至る path を返す.
VI getPath(const VVI& g, ll root, ll from, ll to) {
	VI pf, pt;
	{
		deque<ll> work;
		pathFromRoot(g, from, root, -1, work, pf);
	}
	{
		deque<ll> work;
		pathFromRoot(g, to, root, -1, work, pt);
	}
	ll lcaLevel=0;
	REP(i, min(pf.size(), pt.size())) {
		if(pf[i]==pt[i]) lcaLevel=i;
		else break;
	}
	VI res;
	RANGER(i, lcaLevel, pf.size()) res.PB(pf[i]);
	RANGE(i, lcaLevel+1, pt.size()) res.PB(pt[i]);
	return res;
}

void dfs(const VVI& g, ll cur, ll prev, ll height, function<void(ll vIdx, ll height)> callback) {
	callback(cur, height);
	REP(i, g[cur].size()) if(prev!=g[cur][i]) {
		dfs(g, g[cur][i], cur, height+1, callback);
	}
}

struct Min {
	typedef ll valueType;
	static ll e() {
		return 1LL<<60;
	}
	static ll op(ll a, ll b) {
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


int main() {
	//ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		ll N, M, A, B, P;
		cin>>N>>M>>A>>B;
		A--;B--;
		VI C(N);
		VVI g(N);
		REP(i, N) {
			cin>>P>>C[i];
			P--;
			if(P!=-1) {
				g[i].PB(P);
				g[P].PB(i);
			}
		}
		VI ps = getPath(g, 0, A, B);
//		DD(ps);
//		continue;

		REP(i, N) if(C[i]==0) C[i]=INF;

		ll stSize = M+1;
		SegTree<Min> st(stSize);
		ll head = 0;
		auto getMin = [&](ll s, ll e) {
			assert(0<=s && s<stSize);
			assert(0<=e-1&&e-1<stSize);
			ll rS = (s+head)%stSize;
			ll rE = (e-1+head)%stSize;
			if(rS<=rE) {
				return st.query(rS, rE+1);
			} else {
				return min(st.query(rS, stSize), st.query(0, rE+1));
			}
		};
		auto update = [&](ll idx, ll v) {
			st.update((idx+head)%stSize, v);
		};
		REP(i, stSize) {
			ll v = i==M ? 0 : INF;
			st.update(i, v);
		}
		auto cb = [&](ll vIdx, ll height) {
//			cout<<"on Node "<<vIdx<<" height "<<height<<endl;
			if(!(0 <= M-height) || stSize-1<=height) return;

			ll v = getMin(M-height, M-height+1);
			ll nv = getMin(height, stSize) + C[vIdx];
//			cout<<"v nv "<<v<<" "<<nv<<endl;
			if(nv < v) {
//				cout<<"Update."<<endl;
//				REP(i, stSize) cout<<"ST "<<i<<" "<<getMin(i, i+1)<<endl;
//				cout<<"before "<<v<<endl;
				update(M-height, nv);
//				cout<<"after "<<getMin(M-height, M-height+1)<<endl;
//				REP(i, stSize) cout<<"ST "<<i<<" "<<getMin(i, i+1)<<endl;
			}
		};
		REP(i, ps.size()) {
			ll cur = ps[i];
			if(0<i) {
				head = (head+1)%stSize;
				ll v = min(INF, getMin(0, stSize-1) + C[cur]);
				update(M, v);
			}
//			DD(i);
//			DD(cur);
			ll prevP = 0<=i-1?ps[i-1]:-1;
			ll nextP = i+1<ps.size() ? ps[i+1] : -1;
//			DD(prevP);
//			DD(nextP);
			REP(i, g[cur].size()) {
				ll ai = g[cur][i];
//				DD(ai);
				if(ai!=prevP && ai!=nextP) {
					dfs(g, ai, cur, 1, cb);
				}
			}
		}
		ll ans = getMin(0, stSize);
		if(INF<=ans) ans=-1;
		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		break;
	}
	
	return 0;
}
