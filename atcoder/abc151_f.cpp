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

struct V2 {
	double x, y;
	double angle() const {
		return atan2(y, x);
	}
	double length() const {
		return sqrt(x*x+y*y);
	}
	V2 operator+(const V2& v) const {
		return V2{x+v.x, y+v.y};
	}
	V2 operator-(const V2& v) const {
		return V2{x-v.x, y-v.y};
	}
	V2 operator*(const double& v) const {
		return V2{x*v, y*v};
	}
};
// 外心 (3点を通る円の中心)
V2 circumcenter(const vector<V2>& vs) {
	assert(vs.size()==3);
	vector<double> angles(3);
	vector<double> s2(3);
	REP(i, 3) angles[i] = (vs[(i+1)%3]-vs[i]).angle() - (vs[(i+2)%3]-vs[i]).angle();
	REP(i, 3) s2[i] = sin(2*angles[i]);
	return (vs[0]*s2[0]+vs[1]*s2[1]+vs[2]*s2[2]) * (1.0 / (s2[0]+s2[1]+s2[2]));
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	if(0) {
		auto vs = vector<V2>{
			V2{0.0, 0.0},
			V2{0.0, 1.0},
			V2{1.0, 0.0},
		};
		V2 c = circumcenter(vs);
		DD(c.x);DD(c.y);
		return 0;
	}
	while(cin>>N) {
		VI X(N), Y(N);
		REP(i, N) cin>>X[i]>>Y[i];
		vector<V2> cands;
		REP(i, N) RANGE(j, i+1, N) {
			cands.PB(V2{(X[j]+X[i])/2.0, (Y[j]+Y[i])/2.0});
		}
		REP(i, N) RANGE(j, i+1, N) RANGE(k, j+1, N) {
			auto vs = vector<V2>{
				V2{(double)X[i], (double)Y[i]},
				V2{(double)X[j], (double)Y[j]},
				V2{(double)X[k], (double)Y[k]},
			};
			V2 c = circumcenter(vs);
			cands.PB(c);
		}
		double ans = INF;
		for(auto v: cands) {
			double lans = 0;
			REP(i, N) maxUpdate(lans, (v - V2{(double)X[i], (double)Y[i]}).length());
			minUpdate(ans, lans);
		}
		cout<<setprecision(20)<<ans<<endl;
	}
	
	return 0;
}
