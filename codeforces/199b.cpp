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
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
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


int cross(int x, int y, int r, int X, int Y, int R) {
	int D2 = (X-x)*(X-x)+(Y-y)*(Y-y);
	return (R-r)*(R-r) < D2 && D2 < (R+r)*(R+r);
}

int main() {
	int x[2], y[2], r[2], R[2];
	while(cin>>x[0]) {
		cin>>y[0]>>r[0]>>R[0];
		cin>>x[1]>>y[1]>>r[1]>>R[1];
		int ans = 0;
		REP(i, 2) {
			{
				int ok=1;
				if(cross(x[i], y[i], r[i], x[1-i], y[1-i], r[1-i])) ok=0;
				if(cross(x[i], y[i], r[i], x[1-i], y[1-i], R[1-i])) ok=0;
				if(ok) ans++;
			}
			{
				int ok=1;
				if(cross(x[i], y[i], R[i], x[1-i], y[1-i], r[1-i])) ok=0;
				if(cross(x[i], y[i], R[i], x[1-i], y[1-i], R[1-i])) ok=0;
				if(ok) ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
