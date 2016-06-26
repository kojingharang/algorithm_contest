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

struct Node {
	ll minV, minSum, otherSum;
	Node() : minV(0), minSum(0), otherSum(0) {}
};

std::ostream& operator<<(std::ostream& os, const Node& v) {
	os<<"minV "<<v.minV<<" minSum "<<v.minSum<<" otherSum "<<v.otherSum;
	return os;
}

ll N;
VVI g;
Node nodes[200010];

int unused(int idx) {
	map<int, int> vs;
	REP(i, g[idx].size()) vs[ nodes[g[idx][i]].minV ] = 1;

	int un = 1;
	FOR(e, vs) {
		if(un != e->first) return un;
		un = e->first+1;
	}
	return un;
}

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

void f(int idx) {
	REP(i, g[idx].size()) f(g[idx][i]);
	ll un = unused(idx);
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
	mn.add(un, un + minSum);
	if(!g[idx].size()) mn.add(2, 2); // leaf
	FOR(e, m) mn.add(e->first, e->first + minSum - e->second.minSum + e->second.otherSum);
	nodes[idx].minV = mn.minK;
	nodes[idx].minSum = mn.min1;
	nodes[idx].otherSum = mn.min2;
}

ll solve() {
	f(1);
	return nodes[1].minSum;
}

namespace Test {

VI cost;
ll _ref_ans;
bool ref_check(int idx=1) {
	REP(i, g[idx].size()) {
		int ci = g[idx][i];
		if(cost[idx]==cost[ci]) return false;
		if(!ref_check(ci)) return false;
	}
	return true;
}
void ref_f(int idx) {
	if(idx==N+1) {
//		cout<<"Try "<<cost<<endl;
		if(ref_check()) {
			ll lans = accumulate(ALL(cost), 0LL);
			_ref_ans=min(_ref_ans, lans);
		}
		return;
	}
	REP(i, N) {
		cost[idx] = i+1;
		ref_f(idx+1);
	}
}
ll ref_solve() {
	_ref_ans = 1LL<<60;
	cost = VI(N+1);
	ref_f(1);
	return _ref_ans;
}

VVI _tcs;
VI _tc; // [0, N)
void gen_test_cases(int idx=1) {
	if(idx==1) {
//		cout<<"init tc "<<N<<endl;
		_tc = VI(N);
	}
	if(idx==N) {
		_tcs.PB(_tc);
//		cout<<"add "<<_tc<<endl;
		return;
	}
	RANGE(c, 1, idx+1) {
		_tc[idx] = c;
		gen_test_cases(idx+1);
	}
}

void test() {
	RANGE(n, 1, 9) {
		N=n;
		_tcs.clear();
		gen_test_cases();
//		cout<<_tcs<<endl;
//		continue;

		REP(i, _tcs.size()) {
			VI& test_set = _tcs[i];
			g = VVI(N+1);
			REP(i, N) {
				ll parent = test_set[i];
				g[parent].PB(i+1);
			}
	//		cout<<g<<endl;
			ll ans = solve();
			cout<<"solve "<<ans<<endl;
			ll ref_ans = ref_solve();
			cout<<"ref solve "<<ref_ans<<endl;
			if(ans==ref_ans) {
				cout<<"OK for "<<test_set<<" ans="<<ans<<endl;
			} else {
				cout<<"WA. ref:"<<ref_ans<<" "<<ans<<endl;
				cout<<"for "<<test_set<<endl;
				cout<<"cost "<<cost<<endl;
				cout<<"g "<<g<<endl;
				return;
			}
		}
	}
}

}

int main() {
//	Test::test();return 0;

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
		ll ans = solve();
		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		break;
	}
	
	return 0;
}
