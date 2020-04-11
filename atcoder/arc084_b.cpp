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
/*
Kの各桁の和が上限。
Kの桁数*9程度
K<=10^5=100000だから5*9程度
最小値は 100..000 = Kn になれば 1 なので桁数に制限がないようにみえる。これをどうするか。


*/
ll f(ll v) {
//	ll ans = 1LL<<60;
//	ll mins = -1;
//	RANGE(s, 1, 1000*100) {
//		string ss = to_string(v*s);
//		ll lans = 0;
//		for(char c: ss) lans+=c-'0';
//		if(lans < ans) {
//			ans = min(ans, lans);
//			mins = s;
//		}
//	}
//	DD(mins);
//	DD(v*mins);
//	return ans;
	ll K = v;
	VI po(K, 1LL<<60);
	deque<ll> q;
	q.push_front(1);
	po[1]=1;
	while(q.size()) {
		ll n = q.front();q.pop_front();
		if(n==0) break;
		if(po[n]+1 < po[(n+1)%K]) {q.push_back((n+1)%K); po[(n+1)%K]=po[n]+1;}
		if(po[n] < po[(n*10)%K]) {q.push_front((n*10)%K); po[(n*10)%K]=po[n];}
	}
	return po[0];
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	if(0)
	{
		ll mi = 0;
		RANGE(v, 2, 1000) {
			DD(v);
			ll ans = f(v);
			DD(ans);
			mi = max(mi, ans);
		}
		DD(mi);
		return 0;
	}

	ll K;
	while(cin>>K) {
		cout<<f(K)<<endl;
	}
	
	return 0;
}
