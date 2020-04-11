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

#define MOD 1000000007LL
#define INF (1LL<<60)

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,K;
	while(cin>>N>>K) {
		VI X(N), Y(N), C(N);
		REP(i, N) cin>>X[i]>>Y[i]>>C[i];
		auto f = [&](double x, double y) -> double {
			double lo=0, hi=4000*100*2; // hi is OK
			REP(loop, 100) {
				double t = (lo+hi)/2;
				ll cnt=0;
				REP(i, N) if(C[i]*sqrt((X[i]-x)*(X[i]-x)+(Y[i]-y)*(Y[i]-y)) <= t) cnt++;
				if(K<=cnt) hi=t; else lo=t;
			}
//			DD(x);DD(y);DD(hi);
			return hi;
		};
		double ans = 1e300;
		REP(i, N) minUpdate(ans, f(X[i], Y[i]));
		REP(i, N) RANGE(j, i+1, N) {
			double x = (double)(X[i]*C[i]+X[j]*C[j])/(C[i]+C[j]);
			double y = (double)(Y[i]*C[i]+Y[j]*C[j])/(C[i]+C[j]);
			minUpdate(ans, f(x, y));
		}
		REP(i, N) RANGE(j, i+1, N) RANGE(k, j+1, N) {
			double x = (double)(X[i]*C[i]+X[j]*C[j]+X[k]*C[k])/(C[i]+C[j]+C[k]);
			double y = (double)(Y[i]*C[i]+Y[j]*C[j]+Y[k]*C[k])/(C[i]+C[j]+C[k]);
			minUpdate(ans, f(x, y));
		}
//		auto sq = [](double x) {
//			return x*x;
//		};
//		REP(i, N) RANGE(j, i+1, N) RANGE(k, j+1, N) {
//			double x1=X[i]*C[i];
//			double x2=X[j]*C[j];
//			double x3=X[k]*C[k];
//			double y1=Y[i]*C[i];
//			double y2=Y[j]*C[j];
//			double y3=Y[k]*C[k];
//			double G=( y2*x1-y1*x2 +y3*x2-y2*x3 +y1*x3-y3*x1 );
//			double Xc= (sq(x1)+sq(y1))*(y2-y3)+(sq(x2)+sq(y2))*(y3-y1)+(sq(x3)+sq(y3))*(y1-y2)/(2*G);
//			double Yc=-(sq(x1)+sq(y1))*(x2-x3)+(sq(x2)+sq(y2))*(x3-x1)+(sq(x3)+sq(y3))*(x1-x2)/(2*G);
//			minUpdate(ans, f(Xc, Yc));
//		}
		cout<<setprecision(20)<<ans<<endl;
	}
	
	return 0;
}
