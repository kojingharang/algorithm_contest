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

#define INF (1LL<<60)

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
		VI A(N);
		REP(i, N) cin>>A[i];

		// naive
//		VVVI ref;
//		{
//			VVVI dp(2, VVI(N, VI(N/2+1, -INF)));
//			dp[0][0][0] = 0;
//			dp[1][0][1] = A[0];
//			RANGE(i, 1, N) REP(j, N/2+1) {
//				dp[0][i][j] = max(dp[0][i-1][j], dp[1][i-1][j]);
//				if(0<=j-1) dp[1][i][j] = dp[0][i-1][j-1]+A[i];
//			}
//			ll ans = max(dp[0][N-1][N/2], dp[1][N-1][N/2]);
//			DD(dp);
//			ref = dp;
//			cout<<ans<<endl;
//		}

		
		{
			// 何も考えずiでは(i+2)/2からlimit-1個少ない分だけ持つようにする
			// [0, i] では最大 (i+2)/2 個, [i+1, N-1] では (N-1-(i+1)+1+1)/2個, 合計N/2個になればいいので N/2-(N-i)/2個〜(i+2)/2個まで考えればいい...とかぎりぎりまで考察しなくても
			// [0, i] までで最大 (i+2)/2 個, それより10以上少ないものは考慮しなくていい, という難易度の低い考察で正解にたどり着ける.
			ll limit=10;
			vector<vector<map<ll, ll>>> dp(2, vector<map<ll, ll>>(N, map<ll, ll>()));
			dp[0][0][0] = 0;
			dp[1][0][1] = A[0];
			auto Base = [](ll i) {
				return (i+2)/2;
			};
			auto Get = [](map<ll, ll>& m, ll key) {
				return m.count(key) ? m[key] : -INF;
			};
			RANGE(i, 1, N) RANGE(j, Base(i)-limit+1, Base(i)+1) {
				dp[0][i][j] = max(Get(dp[0][i-1], j), Get(dp[1][i-1], j));
				dp[1][i][j] = Get(dp[0][i-1], j-1)+A[i];
			}
			ll ans = max(Get(dp[0][N-1], N/2), Get(dp[1][N-1], N/2));
//			DD(dp);
			cout<<ans<<endl;
		}

		if(0)
		{
			// 何も考えずiでは(i+2)/2からlimit-1個少ない分だけ持つようにする
			// [limit-1] : (i+2)/2
			// [limit-1-((i+2)/2-idx)] : idx
			ll limit=10;
			auto BaseCount = [](ll i) {
				return (i+2)/2;
			};
			auto Idx = [&](ll i, ll count) {
				return limit-1-(BaseCount(i)-count);
			};
			auto Count = [&](ll i, ll idx) {
				return BaseCount(i) - (limit-1-idx);
			};
			auto In = [&](ll i, ll count) {
				ll idx = Idx(i, count);
				return 0 <= idx && idx < limit;
			};
			VVVI dp(2, VVI(N, VI(limit, -INF)));
			if(In(0, 0)) dp[0][0][Idx(0, 0)] = 0;
			if(In(0, 1)) dp[1][0][Idx(0, 1)] = A[0];
			RANGE(i, 1, N) REP(j, limit) {
				ll co = Count(i, j);
				if(In(i-1, co)) dp[0][i][j] = max(dp[0][i-1][Idx(i-1, co)], dp[1][i-1][Idx(i-1, co)]);
				if(In(i-1, co-1)) dp[1][i][j] = dp[0][i-1][Idx(i-1, co-1)]+A[i];
			}
			ll ans = max(dp[0][N-1][Idx(N-1, N/2)], dp[1][N-1][Idx(N-1, N/2)]);
	//		DD(dp);
	//		REP(li, 2) REP(i, N) REP(ci, limit) {
	//			if(0<=Count(i, ci) && Count(i, ci)<N/2+1 && dp[li][i][ci]!=ref[li][i][Count(i, ci)]) {
	//				cout<<"diff "<<li<<" "<<i<<" "<<ci<<" "<<Count(i, ci)<<endl;
	//				DD(dp[li][i][ci]);DD(ref[li][i][Count(i, ci)]);
	//			}
	//		}
			cout<<ans<<endl;
	//		break;
		}

//		// dp[l][s][i] 0〜iまででl=1...最後のを選んだ, s...連続して選んでない場所がs箇所
//		VVVI dp(2, VVI(3, VI(N, -INF)));
//		dp[0][1][0] = 0;
//		dp[1][0][0] = A[0];
//		RANGE(i, 1, N) REP(s, 3) {
//			// 選ばない
//			dp[0][s][i] = max(0<=s-1 ? dp[0][s-1][i-1] : -INF, dp[1][s][i-1]);
//			// 選ぶ
//			dp[1][s][i] = dp[0][s][i-1]+A[i];
//		}
////		DD(dp);
//		ll ans = 0;
//		if(N%2==0) {
//			ans = max(dp[0][0][N-1], dp[1][1][N-1]);
//		} else {
//			ans = max(dp[0][1][N-1], dp[1][2][N-1]);
//		}
//		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}
