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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { os<<"\n";for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << "\n"; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}

#define MOD 1000000007LL
#define INF (1LL<<60)

//map<pair<ll, pair<ll, pair<ll, pair<ll, vector<string>>>>>, ll> memo;

// 0: becca
// return: 1: turnの人が勝つ
// t==0 -> V
ll f(ll turn, ll X, ll Y, ll T, ll H, ll W, vector<string>& M) {
//	auto key = MP(turn, MP(X, MP(Y, MP(T, M))));
//	if(memo.count(key)) return memo[key];
//	DD(M);
//	cout<<turn<<" "<<X<<" "<<Y<<" "<<T<<endl;
	vector<string> MM(M);
	if(T==0) {
		// V
		RANGE(y, Y, H) {
			if(MM[y][X]=='#') return 0;
			if(MM[y][X]!='.') break;
			MM[y][X]='o';
		}
		for(int y=Y-1;y>=0;y--) {
			if(MM[y][X]=='#') return 0;
			if(M[y][X]!='.') break;
			MM[y][X]='o';
		}
	} else {
		// H
		RANGE(x, X, W) {
			if(MM[Y][x]=='#') return 0;
			if(MM[Y][x]!='.') break;
			MM[Y][x]='o';
		}
		for(int x=X-1;x>=0;x--) {
			if(MM[Y][x]=='#') return 0;
			if(MM[Y][x]!='.') break;
			MM[Y][x]='o';
		}
	}
//	DD(MM);
	ll empty = 0;
	REP(y, H) REP(x, W) if(MM[y][x]=='.') REP(t, 2) {
		empty=1;
		ll r = f(1-turn, x, y, t, H, W, MM);
//		cout<<"RESULT "<<1-turn<<" "<<x<<" "<<y<<" "<<t<<" -> "<<r<<endl;
		// 相手の選択肢でどれかが相手勝ちなら負け
		if(r) return memo[key] = 0;
	}
	if(!empty) {
//		cout<<"NO EMPTY CELL"<<endl;
		return memo[key] = 1;
	}
	// 選択肢あり. すべて相手が負けなら勝ち
//	cout<<"ALL OPP LOSE"<<endl;
	return memo[key] = 1;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int test_cases;
	cin>>test_cases;
	ll W,H;
	REP(ttt, test_cases) {
		cin>>H>>W;
		vector<string> M(H);
		REP(y, H) cin>>M[y];
		ll ans = 0;
		REP(y, H) REP(x, W) if(M[y][x]=='.') REP(t, 2) {
			ll r = f(0, x, y, t, H, W, M);
//			cout<<"ROOT_RESULT "<<x<<" "<<y<<" "<<t<<" -> "<<r<<endl;
			if(r) ans++;
		}
		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		return 0;
	}
	return 0;
}



