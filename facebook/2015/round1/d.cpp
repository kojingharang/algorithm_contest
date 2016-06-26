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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")

//std::ostream& operator<<(std::ostream& os, const Node& v) {
//	os<<"minV "<<v.minV<<" minSum "<<v.minSum<<" otherSum "<<v.otherSum;
//	return os;
//}

struct Node {
	ll minV, minSum, otherSum;
	Node() : minV(0), minSum(0), otherSum(0) {}
};

struct Min2 {
	ll minK, min1, min2;
	Min2() : minK(1LL<<60), min1(1LL<<60), min2(1LL<<60) {}
	void add(ll k, ll v) {
		if(v<min1) {
			min2 = min1;
			min1 = v;
			minK = k;
		} else if(v<min2) {
			min2 = v;
		}
	}
};

ll N;
VVI g;
Node nodes[200010];

VI unused2(int idx) {
	map<int, int> vs;
	REP(i, g[idx].size()) vs[ nodes[g[idx][i]].minV ] = 1;

	VI uns;
	int un = 1;
	FOR(e, vs) {
		while(un != e->first) {
			uns.PB(un);
			if(uns.size()==2) return uns;
			un++;
		}
		un = e->first+1;
	}
	uns.PB(un);
	uns.PB(un+1);
	return uns;
}

void f(int idx) {
	REP(i, g[idx].size()) f(g[idx][i]);
	VI un = unused2(idx);
	ll minSum = 0;
	map<ll, Node> m;
	REP(i, g[idx].size()) {
		auto& n = nodes[g[idx][i]];
		Node& gr = m[n.minV];
		gr.minV = n.minV;
		gr.minSum += n.minSum;
		gr.otherSum += n.otherSum;
		minSum += n.minSum;
	}
	Min2 mn;
	REP(i, 2) mn.add(un[i], un[i] + minSum);
	FOR(e, m) mn.add(e->first, e->first + minSum - e->second.minSum + e->second.otherSum);
	nodes[idx].minV = mn.minK;
	nodes[idx].minSum = mn.min1;
	nodes[idx].otherSum = mn.min2;
}

int main() {
	ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		cin>>N;
		g = VVI(N+1);
		REP(i, N) {
			ll parent;
			cin>>parent;
			g[parent].PB(i+1);
		}
		f(1);
		ll ans = nodes[1].minSum;
		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
	}
	return 0;
}
