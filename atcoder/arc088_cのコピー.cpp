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
00A000B00
000A00B00
0000A0B00
00000AB00
00000BA00
0000B0A00
000B00A00
00B000A00
swap A, B ... |A-B|*2-1回

ataa tmma
amta atma
正解パターンがわかれば回数は(Σ移動距離)/2

文字ごとに移動距離をもとめる
m
	ataa tmma
	amta atma
	4 + 0回
	ataa tmma
	atma amta
	3 + 1回
	...
	すべての場合で4回
a
	ataa tmma
	atat mama
	2回
t
	ataa tmma
	aaat tmma
	2
	ataa tmma
	ataa mmta
	2
	ataa tmma
	aata mtma
	2


*/
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	while(cin>>s) {
		ll ans = 0;
		map<char, int> hi;
		ll N = s.size();
		REP(i, N) hi[s[i]]++;
		VI co(2);
		for(auto kv : hi) {
			co[kv.second % 2]++;
		}
		if(co[1]>=2) ans = -1;
		else {
			ll m = 0;
			REP(ci, 26) {
				VI d;
				REP(i, N) {
					if(s[i]=='a'+ci) d.PB(i);
				}
//				DD(d);
				int hf = d.size()/2;
				ll mv = 0;
				REP(i, hf) {
					ll a = d[i];
					ll b = N-1-d[d.size()-1-i];
					ll c = min(a, b);
//					cout<<(char)('a'+ci)<<" "<<a<<" "<<b<<" "<<c<<endl;
					mv += abs(c-a) + abs(c-b);
				}
				if(d.size()%2==1) {
					mv += abs(N/2-d[hf]);
				}
//				if(mv) cout<<(char)('a'+ci)<<" "<<mv<<endl;
				m += mv;
			}
			ans = m/2;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
