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

struct Gcd {
	typedef ll valueType;
	static ll e() {
		return 0;
	}
	static ll op(ll a, ll b) {
		if(a==e()) return b;
		if(b==e()) return a;
		return __gcd(llabs(a), llabs(b));
	}
};

struct Add {
	typedef ll valueType;
	static ll e() {
		return 0;
	}
	static ll op(ll a, ll b) {
		return a+b;
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
/*
SegTree<Gcd> st(N+1);
SegTree<Add> cum(N+1);
cum.update(i, diff[i]);
ll head = cum.query(0, L+1);
*/

int main() {
	ios::sync_with_stdio(false);
	ll N, M, v, T, L, R;
	while(cin>>N) {
		SegTree<Gcd> st(N+1);
		SegTree<Add> cum(N+1);
		VI cur(N), diff(N+1);
		REP(i, N) {
			cin>>v;
			cur[i] = v;
		}
		diff[0]=cur[0];
		cum.update(0, diff[0]);
		RANGE(i, 1, N) {
			diff[i]=cur[i]-cur[i-1];
			cum.update(i, diff[i]);
			st.update(i, diff[i]);
		}
		cin>>M;
		REP(i, M) {
			cin>>T>>L>>R;
			L--; R--;
			if(T==0) {
				ll head = cum.query(0, L+1);
				ll v = st.query(L+1, R+1);
//				cout<<"H "<<head<<endl;
//				cout<<"V "<<v<<endl;
//				cout<<"dat "<<st.dat<<endl;
				cout<<Gcd::op(head, v)<<endl;
			} else {
				diff[L] += T;
				diff[R+1] -= T;
				st.update(L, diff[L]);
				st.update(R+1, diff[R+1]);
				cum.update(L, diff[L]);
				cum.update(R+1, diff[R+1]);
			}
//			cout<<"DIFF "<<diff<<endl;
//			cout<<cur<<endl;
//			cout<<"SEG "<<st.dat<<endl;
		}
//		return 0;
	}
	
	return 0;
}
