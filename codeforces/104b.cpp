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
#define VVI vector<vector<int> >
#define PII pair<int, int> 
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }


int within(int x, int y, int hx, int hy, int hr) {
	return (x-hx)*(x-hx)+(y-hy)*(y-hy) <= hr*hr;
}

int main() {
	int x1,y1,x2,y2,N;
	cin>>x1>>y1>>x2>>y2>>N;
	if(x1>x2) swap(x1,x2);
	if(y1>y2) swap(y1,y2);
	VI w;
	for(int x=x1;x<=x2;x++) {
		w.PB(x);
		w.PB(y1);
		w.PB(0);
		w.PB(x);
		w.PB(y2);
		w.PB(0);
	}
	for(int y=y1+1;y<=y2-1;y++) {
		w.PB(x1);
		w.PB(y);
		w.PB(0);
		w.PB(x2);
		w.PB(y);
		w.PB(0);
	}
	REP(i, N) {
		int hx, hy, hr;
		cin>>hx>>hy>>hr;
		REP(j, w.size()/3) {
			if(within(w[j*3+0], w[j*3+1], hx, hy, hr)) w[j*3+2]=1;
		}
	}
	int ans = 0;
	REP(j, w.size()/3) {
		if(w[j*3+2]==0) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
