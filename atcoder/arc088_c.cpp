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





template<typename T>
struct BIT {
	vector<T> w;
	BIT(int N) { w = vector<T>(N); }
	// sum of w[i], i in [l, r]
	T sum(int l, int r) {
		if(l==0) {
			T s=0;
			for(;r>=0;r=(r&(r+1))-1) s+=w[r];
			return s;
		}
		return sum(0, r) - sum(0, l-1);
	}
	// i in [0, N)
	void add(int i, T v) {
		for(;i<(int)w.size();i|=i+1) w[i] += v;
	}
};
template<typename T>
ll inversion_number(const vector<T>& d) {
	ll N = d.size();
	BIT<T> bit(N);
	ll cnt = 0;
	for(int i=N-1;i>=0;i--) {
		cnt += bit.sum(0, d[i]);
		bit.add(d[i], 1);
	}
	return cnt;
}

ll sol(string s) {
	map<char, int> hi;
	for(char c : s) hi[c]++;
	int odds = 0;
	for(auto kv : hi) if(kv.second%2==1) odds++;
	if(odds>1) return -1;

	ll N = s.size();
	map<char, VI> is;
	VI th(N);
	REP(i, N) {
		th[i] = is[s[i]].size();
		is[s[i]].PB(i);
	}
	VI p(N); // s[i] -> t[p[i]]
	int ti = 0;
	REP(i, N) {
		if(th[i] < is[s[i]].size()/2) {
			p[i] = ti;
			int ci = is[s[i]][is[s[i]].size()-1-th[i]];
			p[ci] = N-1-ti;
			ti++;
		}
		if(is[s[i]].size()%2==1 && is[s[i]].size()/2==th[i]) p[i] = N/2;
	}
//	string t(N, ' ');
//	REP(i, N) t[p[i]] = s[i];
//	DD(s);
//	DD(p);
//	DD(t);
	return inversion_number(p);
}

ll solve(string s) {
	ll ans = 0;
	map<char, int> hi;
	ll N = s.size();
	REP(i, N) hi[s[i]]++;
	VI co(2);
	for(auto kv : hi) co[kv.second % 2]++;
	if(co[1]>=2) ans = -1;
	else {
		VI p(N);
		vector<bool> isL(N);
		map<int, VI> cvs;
		REP(ci, 26) {
			VI vs;
			REP(i, N) if(s[i]=='a'+ci) vs.PB(i);
			REP(i, vs.size()/2) isL[vs[i]] = 1;
			if(vs.size()%2==1) p[N/2] = vs[vs.size()/2];
			cvs[ci] = vs;
		}
//			DD(isL);
		int ai=0;
		REP(i, N) if(isL[i]) p[ai++] = i;
		VI co(26);
		REP(i, N/2) {
			int ci = s[p[i]]-'a';
			auto& vs = cvs[ci];
			p[N-1-i] = vs[vs.size()-1-co[ci]];
			co[ci]++;
		}
//			DD(p);
		string t(N, ' ');
		REP(i, N) t[i] = s[p[i]];
		DD(t);
		REP(i, N) assert(0<=p[i]&&p[i]<N);
		ans = inversion_number(p);
	}
	return ans;
}
void test() {
	REP(loop, 1000) {
		ll N = UNIFORM_LL(3, 20);
		string s(N, ' ');
		REP(i, N) s[i] = UNIFORM_LL(0, 5)+'a';
		N += N;
		s += s;
//		ll refAns = ref(s);
		ll refAns = solve(s);
		ll ans = sol(s);
		DD(s);
		if(refAns!=ans) {
			DD(s);
			DD(refAns);
			DD(ans);
			assert(0);
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
//	test();
	string s;
	while(cin>>s) {
		ll ans = sol(s);
		cout<<ans<<endl;
	}
	
	return 0;
}
