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
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

vector<ll> divs(11);

int is_prime(ll n, ll r){
	ll i;
	if(n < 2) {assert(0);return 0;}
	else if(n == 2) return 1;
	if(n % 2 == 0) {divs[r] = 2; return 0;}
	for(i = 3; i * i <= n; i += 2) if(n % i == 0) {divs[r] = i; return 0;}
	return 1;
}

int check(const string& s) {
	RANGE(r, 2, 11) {
		ll v = 0;
		ll c = 1;
		REP(i, s.size()) {
			v += (s[s.size()-1-i]-'0') * c;
			c *= r;
		}
//		DD("check");
//		DD(r);
//		DD(v);
		if(is_prime(v, r)) return 0;
		assert(v%divs[r]==0);
		assert(divs[r]!=1);
		assert(divs[r]!=v);
	}
	// divs filled.
	return 1;
}

void f(ll N, ll J) {
	string s(N, '1');
	ll found=0;
	REP(bi, 1<<(N-2)) {
		REP(i, N-2) {
			s[N-2-1-i+1] = (bi>>i&1) ? '1':'0';
		}
//		DD(s);
		if(check(s)) {
			found++;
			cout<<s;
			RANGE(i, 2, 11) cout<<" "<<divs[i];
			cout<<endl;
			if(found==J) return;
		}
	}
}

int main() {
//	DD(check("1001"));
//	DD(divs);
//	return 0;

//	DD(check("100011"));
//	DD(divs);
//	return 0;

	int test_cases;
	cin>>test_cases;
	ll N,J;
	REP(ttt, test_cases) {
		cin>>N>>J;
		cout<<"Case #"<<ttt+1<<": "<<endl;
		f(N, J);
//		return 0;
	}
	return 0;
}



