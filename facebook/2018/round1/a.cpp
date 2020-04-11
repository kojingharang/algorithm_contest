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

void check(const VI& w) {
	ll N = w.size();
//	cerr<<w<<endl;
	assert(N%4==0);
	REP(i, N/4) {
		ll a = w[i*4+0];
		ll b = w[i*4+1];
		ll c = w[i*4+2];
		ll d = w[i*4+3];
		assert(a<b);
		assert(b<c);
		assert(c<d);
		assert(b-a<=10);
		assert(c-b<=10);
		assert(d-c<=10);
		if(!(1<=a&&a<=100) || !(1<=b&&b<=100) || !(1<=c&&c<=100) || !(1<=d&&d<=100))cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
//		assert(1<=a&&a<=100);
//		assert(1<=b&&b<=100);
//		assert(1<=c&&c<=100);
//		assert(1<=d&&d<=100);
	}
//	cout<<w<<endl;
//	cout<<"ok"<<endl;
}

int main() {
	ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		ll N;
		cin>>N;
		VI w(N);
		REP(i, N) cin>>w[i];
		ll last = 0;
		ll ans = 0;
		ll th = 0;
//		cout<<w<<endl;
		VI neu;
		REP(i, N) {
			if(th==4) th=0;
			if(th==0) {
				last = w[i];
				neu.PB(w[i]);
				th++;
			} else {
				if(!(last < w[i])) {
					while(th<4) {
						th++;
						last++;
						ans++;
						neu.PB(last);
					}
					i--;
				} else if(!(w[i]<=last+10)) {
					while(th<4 && !(w[i]<=last+10)) {
						last += 10;
						th++;
						ans++;
						neu.PB(last);
					}
					i--;
				} else {
					last = w[i];
					neu.PB(w[i]);
					th++;
				}
			}
		}
		while(th<4) {
			last++;
			th++;
			ans++;
			neu.PB(last);
		}
		assert(w.size()+ans==neu.size());
		check(neu);
		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		break;
	}
	
	return 0;
}
