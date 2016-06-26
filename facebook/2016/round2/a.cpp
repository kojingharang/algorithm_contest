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

int naive(string A, string B) {
	int N = A.size();
	ll ans = N;
	REP(si, N+1) {
		ll coA=0, coB=0;
		{
			int flg=0;
			char last=0;
			for(int i=si;i>=0;i--) {
				if(A[i]!=B[i]) flg=1;
				if(flg) {
					coA+=last!=B[i];
					last=B[i];
				}
			}
		}
		{
			int flg=0;
			char last=0;
			for(int i=si+1;i<N;i++) {
				if(A[i]!=B[i]) flg=1;
				if(flg) {
					coB+=last!=B[i];
					last=B[i];
				}
			}
		}
		ans = min(ans, max(coA, coB));
	}
	return ans;
}

int f(const string& A, const string& B) {
	ll N = A.size();
	VI diff0(N); // [i] most right diff idx in [0, i]
	VI diff1(N); // [i] most left diff idx in [i, N-1]
	ll last = -1;
	REP(i, N) {
		if(A[i]!=B[i]) last = i;
		diff0[i] = last;
	}
	last = -1;
	for(int i=N-1;i>=0;i--) {
		if(A[i]!=B[i]) last = i;
		diff1[i] = last;
	}
	VI ng0(N);
	VI ng1(N);
	{
		ll co = 1;
		ng0[0] = 1;
		RANGE(i, 1, N) {
			if(B[i-1]!=B[i]) co++;
			ng0[i] = co;
		}
	}
	{
		ll co = 1;
		ng1[N-1] = 1;
		for(int i=N-2;i>=0;i--) {
			if(B[i+1]!=B[i]) co++;
			ng1[i] = co;
		}
	}
//	P(diff0);
//	P(diff1);
//	P(ng0);
//	P(ng1);
	ll ans = N;
	REP(si, N+1) {
		ll coA = si-1>=0 ? (diff0[si-1]==-1 ? 0 : ng0[diff0[si-1]]) : 0;
		ll coB = si<N ? (diff1[si]==-1 ? 0 : ng1[diff1[si]]) : 0;
		ans = min(ans, max(coA, coB));
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		int N;
		cin>>N;
		string A, B;
		cin>>A>>B;
		ll ans = f(A, B);
//		{
//			ll ref = naive(A, B);
//			if(ans!=ref) {
//				cout<<"DIFF"<<endl;
//				P(A);P(B);
//				assert(0);
//			}
//		}
		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		break;
	}
	
	return 0;
}
