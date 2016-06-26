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
#define P(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")

#define MOD 1000000007LL
#define INF (1LL<<60)

ll naive(vector<string> m) {
	ll W = m[0].size();
	ll cells = W*2;
	assert(cells<=20);
	ll ans = cells;
	REP(bit, 1<<cells) {
		vector<string> mm(m);
		REP(ci, cells) {
			ll x=ci%W;
			ll y=ci/W;
			if(((bit>>ci)&1) && mm[y][x]=='.') {
//				if(bit==((1<<3)|(1<<(6+W))|(1<<9))) {
//					cout<<"Put "<<x<<" "<<y<<endl;
//				}
				mm[y][x]='+';
				for(int xx=x-1;xx>=0;xx--) {
					if(mm[y][xx]=='X') break;
					mm[y][xx]='+';
				}
				for(int xx=x+1;xx<W;xx++) {
					if(mm[y][xx]=='X') break;
					mm[y][xx]='+';
				}
				if(mm[1-y][x]=='.') mm[1-y][x]='+';
			}
		}
		ll lans = (ll)POPCOUNT(bit);
//		if(bit==((1<<3)|(1<<(6+W))|(1<<9))) {
//			P(lans);
//			P(mm);
//		}
		bool ok = true;
		REP(y, 2) REP(x, W) if(mm[y][x]=='.') ok=false;
		if(ok) ans = min(ans, lans);
	}
	return ans;
}

int main() {
	//ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		ll W;
		cin>>W;
		vector<string> s(2);
		REP(i, 2) {
			cin>>s[i];
		}
//		if(CaseID%10000) continue;

		VVI bars(2, VI(W));
		ll ans = 0;
		REP(y, 2) {
			REP(i, W) {
				if(s[y][i]=='.' && (i==0 || s[y][i-1]=='X')) {
					ll co=1;
					RANGE(j, i+1, W) {
						if(s[y][j]=='X') break;
						co++;
					}
					bars[y][i]=co;
					ans++;
				}
			}
		}
//		P(ans);
//		P(bars);
		REP(y, 2) {
			REP(i, W) {
				if(bars[y][i]>=(y==0?1:2)) {
					// [i, i+bars[0][i])
					RANGE(j, i, i+bars[y][i]) {
						if(bars[1-y][j]==1) {
							ans--;
							break;
						}
					}
				}
			}
		}
//		ll ref = naive(s);
//		P(ans);
//		P(ref);
//		if(ans!=ref) {
//			P(s);
//			assert(false);
//		}
		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		break;
	}
	
	return 0;
}
