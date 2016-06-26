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
using namespace std;

#define EPS 1e-12
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

long double f0(vector<PII>& w) {
	long double total = 0;
	int last = 0;
	VI vis(w.size());
	vis[last]=1;
	REP(loop, w.size()-1) {
		vector<pair<long double, int> > cand;
		REP(i, w.size()) {
			if(!vis[i]) {
				long double dx = w[last].first - w[i].first;
				long double dy = w[last].second - w[i].second;
				long double l=dx*dx+dy*dy;
				cand.PB(MP(l, i));
			}
		}
		sort(ALL(cand));
		long double Min = cand[0].first;
		int idx = cand[0].second;
		total += sqrt(Min);
		vis[idx] = 1;
		last = idx;
	}
	return total;
}

long double f1(vector<PII>& w) {
	long double total = 0;
	int last = 0;
	VI vis(w.size());
	vis[last]=1;
	REP(loop, w.size()-1) {
		vector<pair<long double, int> > cand;
		REP(i, w.size()) {
			if(!vis[i]) {
				long double dx = w[last].first - w[i].first;
				long double dy = w[last].second - w[i].second;
				long double l=dx*dx+dy*dy;
				cand.PB(MP(l, i));
			}
		}
		sort(ALL(cand));
		long double Min = cand.size() >= 3 ? cand[1].first : cand[0].first;
		int idx = cand.size() >= 3 ? cand[1].second : cand[0].second;
		total += sqrt(Min);
		vis[idx] = 1;
		last = idx;
	}
	return total;
}

double r01() {
	return (double)rand()/RAND_MAX;
}

/*
11
4420 4238
812 4
5870 7900
6714 2388
4359 7163
9761 2309
2886 4313
4087 885
3993 8130
6791 7613
477 8468
*/
int main() {
	//ios::sync_with_stdio(false);
	srand(time(NULL));
	vector<PII> w;
	REP(loop, 100000) {
		w.clear();
		REP(i, 100) {
//			w.PB(MP(r01()*10000, r01()*10000));
			w.PB(MP(i, i%2?0:2));
		}
		long double v0 = f0(w);
		long double v1 = f1(w);
		if(v0 >= v1 + 1e-8) {
			cout<<v0<<" "<<v1<<endl;
			cout<<w.size()<<endl;
			REP(i, w.size()) cout<<w[i].first<<" "<<w[i].second<<endl;
		}
	}
	
	return 0;
}




