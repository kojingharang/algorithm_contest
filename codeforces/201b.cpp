#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define PII pair<int, int> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(ll i=0,_n=(n);(i)<(int)_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

#define MOD 1000000007LL
#define INF (1LL<<60)

int main() {
	int N, M;
	while(cin>>N>>M) {
		VVI w(N, VI(M));
		REP(y, N) REP(x, M) cin>>w[y][x];
		//cout<<w<<endl;
		VI cx(M);
		REP(x, M) REP(y, N) cx[x] += w[y][x];
		VI cy(N);
		REP(y, N) REP(x, M) cy[y] += w[y][x];
		//cout<<cy<<endl;
		ll minxv = INF, minx = 10000;
		REP(px, M+1) {
			ll a=0;
			REP(x, M) {
				ll d = ( x*4+2 - px*4 );
				a += cx[x] * d * d;
			}
			if(a < minxv) { minxv = a; minx = px; }
		}
		ll minyv = INF, miny = 10000;
		REP(py, N+1) {
			ll a=0;
			REP(y, N) {
				ll d = ( y*4+2 - py*4 );
				a += cy[y] * d * d;
			}
			if(a < minyv) { minyv = a; miny = py; }
		}
		
		cout<<minxv+minyv<<endl;
		cout<<miny<<" "<<minx<<endl;
	}
	
	return 0;
}
