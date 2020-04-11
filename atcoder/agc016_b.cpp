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

/*

0 1 2...
A B C...

0 が 1以降のどれとも違う
	-> 全部で 1+A 種類
どれかと同じ
	-> 全部で A 種類

1 が 1以外のどれとも違う
	-> 全部で 1+B 種類
どれかと同じ
	-> 全部で B 種類

全部で k 種類とすると k は {i, i+1 for i in A〜Z} のどれか。その k に対して k==i or k==i+1 である必要あり。

k-1 <= Ai <= k
k = max Ai

4 3 4 3 4

全部で4種類
0 は 2 4 のどれかと同じ
1 はほかのどれとも違う
2 は 0 4 のどれかと同じ
3 はほかのどれとも違う
4 は 0 2 のどれかと同じ

1 3 の他に2種類.
0==2とすると0==2==4となりだめ
おなじ集合 N-uniq 個で k-uniq 色作れればOK

0 -> 1 2 3
1 -> 0 2 3
2 -> 0 1 3
3 -> 0 1 2
0==1 とすると 2==3 ならOK -> 2色
0==1==2 とするとぜんぶおなじ -> 1色

ぜんぶ同じ -> 1色
4以上 なら 2以上 2以上 にわけられれば2色
5以上なら 2 色まで
6以上なら3色まで
2個ずつとる

1 2 2
k=2
0ちがう
1 = 2
2 = 1
0 1=2 の2種類


3 3 3 -> NG
2 2 2 -> k=3 OK ぜんぶ違う
1 1 1 -> k=1 0 0 0 OK ぜんぶどれかと同じ

7 7 7 7 7 7 7 -> NG
6 6 6 6 6 6 6 -> k=7
5 5 5 5 5 5 5 -> NG
4 4 4 4 4=4=4 -> NG
1 1 1 1 1 1 1 -> k=1 OK


*/
#define MOD 1000000007LL
#define INF (1LL<<60)

int main() {
	//ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
		VI w(N);
		REP(i, N) cin>>w[i];
//		DD(w);
		ll Max = *max_element(ALL(w));
		ll Min = *min_element(ALL(w));
		if(Max==Min) {
			// k == Max+1 -> Max==N-1
			// k == Max -> 
			bool ok = Max==N-1 || (N>1 && 1 <= Max && Max <= N/2);
			cout<<(ok ? "Yes" : "No")<<endl;
		} else if(Max==Min+1) {
			ll k = Max;
			ll uniq = 0;
			REP(i, N) if(w[i]==k-1) uniq++;
			// のこりはすべてどれかと同じ
			ll sg = N-uniq; // >0
			// sg個でk-uniq色つくれればOK
			bool ok = sg>1 && 1 <= k-uniq && k-uniq <= sg/2;
			cout<<(ok ? "Yes" : "No")<<endl;
		} else {
			cout<<"No"<<endl;
		}
	}

	return 0;
}
