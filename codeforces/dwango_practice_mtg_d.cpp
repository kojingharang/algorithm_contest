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

ll naive(string s, VI w) {
	ll ans = 0;
	REP(i, s.size()) RANGE(j, i, s.size()) {
		VI co(10);
		RANGE(k, i, j+1) co[s[k]-'0']++;
		bool ok=1;
		for(auto v : w) if(!co[v]) ok=0;
		if(ok) ans++;
	}
	return ans;
}

// check : bool(int S, int E) ... [S, E] である条件が成り立つかどうかを返す.
// onMove : void(int index, int sign) ... sign=1 : index 要素が範囲に入った sign=-1 : 出た
void syakutori(int N, function<bool(int, int)> check, function<void(int, int)> onMove) {
	int hd = 0, tl = -1; // [hd, tl]
	REP(hd, N) {
		// assert !check
		while(tl<N && !check(hd, tl)) tl++, onMove(tl, 1);
		// assert check
		onMove(hd, -1);
	}
}

// verified with https://www.hackerearth.com/ja/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/string-matching-google-3dc355a5/
ll solve(string s, VI w) {
	VI co(10);
	ll N = w.size();
	ll ans = 0;
	auto check = [&](int hd, int tl) {
//		cout<<"CHECK "<<hd<<" "<<tl<<endl;
		bool ok = 1;
		REP(i, N) if(co[w[i]] <= 0) ok=0;
		if(ok) {
			ans += s.size() - tl;
		}
		return ok;
	};
	auto onMove = [&](int index, int sign) {
		co[s[index]-'0']+=sign;
	};
	syakutori(s.size(), check, onMove);
	return ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	if(0)
	REP(loop, 10000) {
		ll sn = 5;
		string s(sn, ' ');
		REP(i, sn) s[i] = UNIFORM_LL(0, 10)+'0';
		VI w = {1,2,3};
		ll ans = solve(s, w);
		ll ref = naive(s, w);
		DD(s);
		DD(w);
		DD(ref);
		DD(ans);
		assert(ref==ans);
	}
//	return 0;

	ll N;
	string s;
	while(cin>>s>>N) {
		VI w(N);
		REP(i, N) cin>>w[i];
		ll ans = solve(s, w);
//		ll ref = naive(s, w);
//		DD(ref);
//		DD(ans);
//		assert(ref==ans);
		cout<<ans<<endl;
	}
	
	return 0;
}
