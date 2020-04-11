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
increase stack size!!!!!!
// 16MB
g++ -O2 -Wl,-stack_size,10000000 -std=c++11 -Wall d.cpp && ./a.out < corporate_gifting.txt > do2.txt
*/

vector<double> create(ll X, ll Y) {
	vector<double> c(X*Y+1);
	c[0] = 1.0;
	REP(x, X) {
		vector<double> n(X*Y+1);
		REP(i, c.size()) {
			if(c[i]>0) {
				REP(y, Y) {
					n[i+y+1] += c[i] / (double)Y;
				}
			}
		}
		c = n;
	}
//	DD(c);
	return c;
}

int main() {
	//ios::sync_with_stdio(false);
//	create(20, 20);
//	return 0;
	int Cases;
	cin>>Cases;
	ll H, S;
	REP(CaseID, Cases) {
		cin>>H>>S;
		vector<tuple<ll, ll, ll>> w;
		string s;
		REP(i, S) {
			cin>>s;
			REP(j, s.size()) if(s[j]=='d') s[j]=' ';
			REP(j, s.size()) {
				if(s[j]=='+' || s[j]=='-') {
					s=s.substr(0, j)+string(" ")+s.substr(j);
					break;
				}
			}
			s += " +0";
//			cout<<s<<endl;
			stringstream ss;
			ss<<s;
			ll x, y, z;
			ss>>x>>y>>z;
//			cout<<"xyz "<<x<<" "<<y<<" "<<z<<endl;
			w.push_back(make_tuple(x, y, z));
		}
		double ans = 0.0;
		int ZERO = 10010;
		int SIZE = ZERO + 10001;
		REP(i, w.size()) {
			vector<double> dp(SIZE);
			dp[ZERO] = 1.0;
			vector<double> ndp(SIZE);
			ll x, y, z;
			tie(x, y, z) = w[i];
			auto ldp = create(x, y);
			REP(j, dp.size()) {
				if(dp[j] > 0) {
					if(j==ZERO+H) {
						ndp[j] = dp[j];
					} else {
						REP(k, ldp.size()) {
							int idx = min<int>(j+k+z, ZERO+H);
							assert(idx>0);
							ndp[idx] += dp[j] * ldp[k];
						}
					}
				}
			}
			dp = ndp;
//			cout<<"wi "<<i<<" of "<<S<<endl;
//			REP(i, H+1) DD(dp[ZERO+i]);
			ans = max(ans, dp[ZERO+H]);
		}
		printf("Case #%d: %f\n", CaseID+1, ans);
//		break;
	}
	
	return 0;
}
