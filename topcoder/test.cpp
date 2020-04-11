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
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, I, J) REP(i, I) { REP(j, J) cout<<table[i][j]<<" "; cout<<"\n"; }
#define PRINT3(table, I, J, K) REP(i, I) { REP(j, J) { REP(k, K) cout<<table[i][j][k]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<(v)<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }


ll LCS(string a, string b) {
	ll al=a.size();
	ll bl=b.size();
	if(al==0 || bl==0) return 0;

	VVI dp(al, VI(bl));
	dp[0][0] = a[0]==b[0];
	REP(ai, al) REP(bi, bl) {
		ll v = 0;
		if(ai-1>=0 && bi-1>=0) v = max(v, dp[ai-1][bi-1]+(a[ai]==b[bi]));
		if(ai-1>=0) v = max(v, dp[ai-1][bi]);
		if(bi-1>=0) v = max(v, dp[ai][bi-1]);
		dp[ai][bi] = max(dp[ai][bi], v);
	}
	DD(a);
	DD(b);
	DD(dp);
	DD(dp[al-1][bl-1]);
	return dp[al-1][bl-1];
}

ll LCScomb(string a, string b) {
	ll al=a.size();
	ll bl=b.size();
	if(al==0 || bl==0) return 0;

	VVI dp(al, VI(bl));
	dp[0][0] = a[0]==b[0];
	REP(ai, al) REP(bi, bl) {
		ll v = 0;
		if(ai-1>=0 && bi-1>=0) v += dp[ai-1][bi-1] * (1+(a[ai]==b[bi]));
		if(ai-1>=0) v += dp[ai-1][bi];
		if(bi-1>=0) v += dp[ai][bi-1];
		dp[ai][bi] = dp[ai][bi] + v;
	}
	DD(a);
	DD(b);
	DD(dp);
	DD(dp[al-1][bl-1]);
	return dp[al-1][bl-1];
}






int main(){
	assert(LCS("", "a")==0);
	assert(LCS("a", "a")==1);
	assert(LCS("aaba", "abaa")==3);
	assert(LCS("1224533324", "69283746")==3);
	assert(LCScomb("", "a")==0);
	assert(LCScomb("a", "a")==1);
	assert(LCScomb("aaba", "abaa")==7);
//	assert(LCScomb("1224533324", "69283746")==3);
}







