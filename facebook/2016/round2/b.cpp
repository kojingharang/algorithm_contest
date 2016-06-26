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
/*
increase stack size!!!!!!
// 16MB
g++ -O2 -Wl,-stack_size,10000000 -std=c++11 -Wall d.cpp && ./a.out < corporate_gifting.txt > do2.txt
*/

#define COMB_MAX 3010
long double comb[COMB_MAX][COMB_MAX];

double naive(ll N, ll K, double p) {
//	P(N);P(K);P(p);
	long double ans = 0;
	auto Exp = [=](int toss) {
		long double pp = 1.0;
		REP(j, K) pp *= p;
		REP(j, toss-K) pp *= 1-p;
		long double exp = 0.0;
		RANGE(i, K, toss+1) {
//			long double pp = 1.0;
//			REP(j, i) pp *= p;
//			REP(j, toss-i) pp *= 1-p;
			// i coins head
//			cout<<" Head "<<i<<" "<<comb[toss][i]<<" pp "<<pp<<" "<<comb[toss][i] * pp<<endl;
			exp += comb[toss][i] * pp;
			pp *= p/(1-p);
		}
//		P(exp);
		return exp;
	};
	vector<long double> exp(N+1);
	REP(i, N+1) exp[i]=Exp(i);
	vector<long double> dp(N+1);
	REP(i, N+1) {
		REP(j, N+1) {
			if(i-j>=0) dp[i] = max(dp[i], dp[i-j]+exp[j]);
		}
	}
	ans = dp[N];
	return ans;
}

int main() {
	{
		// nCm = n-1Cm-1 + n-1Cm
		REP(n, COMB_MAX) comb[n][0] = 1;
		RANGE(n, 1, COMB_MAX) RANGE(m, 1, COMB_MAX) comb[n][m] = (comb[n-1][m-1] + comb[n-1][m]);
	}
	//ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		ll N, K;
		double P;
		cin>>N>>K>>P;
		double ans = naive(N, K, P);
//		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
		printf("Case #%d: %.12f\n", CaseID+1, ans);
//		break;
	}
	
	return 0;
}
