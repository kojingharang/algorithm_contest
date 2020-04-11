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
#define INF (1LL<<60)

ll CS = 26;
//ll CS = 3;

ll N;
string s;
VVI nxt;

// i以降でcが最初に出てくる位置
ll pos(ll i, ll c) {
//	cout<<"pos "<<i<<" "<<c<<endl;
	return nxt[c][i];
//	RANGE(j, i, N) if(s[j]=='a'+c) return j;
//	return -1;
}

using plll = pair<int, pair<int, int>>;
using pll = pair<int, int>;

vector<vector<plll>> memo;
//map<pair<ll, ll>, pair<ll, pair<ll, ll>>> memo;

// iにいてcを選んだ時の残りstep
plll f(int i, int c) {
//	cout<<"f "<<i<<" "<<c<<endl;
	// 範囲外なのでcでOK
	if(i>=N) return MP(1, MP(-1, -1));

	if(memo[c][i].first!=-1) return memo[c][i];

	ll p = pos(i, c);
//	DD(p);
	if(p==-1) return memo[c][i] = MP(1, MP(-1, -1));
	auto lans = MP(1<<30, MP(-1, -1));
	REP(j, CS) {
		auto a = f(p+1, j);
		if(1+a.first < lans.first) {
			lans = MP(1+a.first, MP(p+1, j));
		}
	}
//	cout<<"f "<<i<<" "<<c<<" -> "<<lans<<endl;
	return memo[c][i] = lans;
}



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	while(cin>>s) {
		N = s.size();
		memo = vector<vector<plll>>(CS, vector<plll>(N, MP(-1, MP(0, 0))));
		nxt = VVI(CS, VI(N+1, -1));
		for(int i=N-1;i>=0;i--) {
			REP(j, CS) if(s[i]-'a'==j) nxt[j][i] = i; else if(i+1<N) nxt[j][i] = nxt[j][i+1];
		}
		auto mv = MP(1<<30, MP(0, 0));
		ll first = -1;
		REP(j, CS) {
			auto vv = f(0, j);
			if(vv.first < mv.first) {
				mv = vv;
				first = j;
			}
		}
//		DD(mv);
//		DD(first);
		string ans;
		ll p = 0;
		ll c = first;
		while(1) {
			ans.PB('a'+c);
			auto v = f(p, c);
			p = v.second.first;
			c = v.second.second;
			if(p==-1) break;
		}
		REP(i, N) REP(j, CS) {
//			DD(i);DD(j);DD(f(i, j));
		}
//		DD(ans);
		cout<<ans<<endl;

//		break;
	}
	
	return 0;
}
