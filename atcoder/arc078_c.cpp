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

#define MOD 1000000007LL
#define INF (1LL<<60)

string st(ll v) {
	stringstream ss;
	ss<<v;
	return ss.str();
}

bool f(ll a, ll b) {
	string sa = st(a);
	string sb = st(b);
	if((a<=b && sa<=sb) || (a>b && sa>sb)) return true;
	return false;
}

ll refN;

bool ask(ll v) {
//	return f(v, refN);
	cout<<"? "<<v<<endl<<flush;
	string s;
	cin>>s;
	return s=="Y";
}

ll solve() {
	ll t = 10;
	REP(p, 18) {
		bool v = ask(t);
		if(!v) {
//			DD("get NO");
//			DD(t);
			ll lo = t; // N
			ll hi = t*10; // Y
			while(lo+1<hi) {
				ll mid = (lo+hi)/2;
				if(ask(mid))hi=mid;
				else lo=mid;
			}
			return hi/10;
		}
		t*=10;
	}
	t = 1;
	REP(p, 18) {
		bool v = ask(t+1);
		if(v) {
			return t;
		}
		t*=10;
	}
	return -1;
}

int main() {
	if(0)
	{
		ll n = 1;
		bool pfv=false;
		bool isFirst=true;
		RANGE(i, 1, 100001) {
			bool fv = f(i, n);
			if(pfv!=fv || isFirst) {
				isFirst=false;
				cout<<i<<" "<<n<<" "<<fv<<endl;
				pfv=fv;
			}
		}
		return 0;
	}

	if(0)
	{
		RANGE(n, 1, 100010) {
			refN = n;
			ll ans = solve();
			DD(refN);
			DD(ans);
			assert(ans==refN);
		}
		return 0;
	}

	ll n = solve();
	cout<<"! "<<n<<endl;

	return 0;
}
