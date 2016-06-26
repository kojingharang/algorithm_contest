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

#define MOD 1000000007LL
#define INF (1LL<<60)

int g=0;
void rec(int v, int co, map<int, int>& m) {
//	if(m.count(v) && m[v]<co) return;
	if(m.count(v)) return;
	m[v] = co;
	g++;
	if(v%2==0) rec(v/2, co+1, m);
	if(v%3==0) rec(v/3*2, co+1, m);
}

map<ll, int> merge(map<int, int>& a, map<int, int>& b) {
	map<ll, int> o;
	FOR(e0, a) FOR(e1, b) {
		ll key = (ll)e0->first*e1->first;
		if(!o.count(key)) o[key] = e0->second+e1->second;
		else o[key] = min(o[key], e0->second+e1->second);
	}
	return o;
}

void find(ll value, int co, map<int, int>& a, map<int, int>& b) {
	int c=0;
	FOR(e0, a) if(value % e0->first==0 && e0->second<=co) FOR(e1, b) if(e1->second<=co) {
		ll key = (ll)e0->first*e1->first;
		int c = e0->second+e1->second;
		if(key==value && c==co) {
			cout<<e0->first<<" "<<e1->first<<endl;
//			cout<<c<<endl;
			return;
		}
	}
}

int main() {
	//ios::sync_with_stdio(false);
	int a,b,c,d;
	string s;
	while(cin>>a>>b>>c>>d) {
		map<int, int> A,B,C,D;
		rec(a, 0, A);
		rec(b, 0, B);
		rec(c, 0, C);
		rec(d, 0, D);
//		cout<<"g "<<g<<endl;
//		cout<<A.size()<<endl;
//		cout<<B.size()<<endl;
//		cout<<C.size()<<endl;
//		cout<<D.size()<<endl;
		map<ll, int> AB = merge(A, B);
		map<ll, int> CD = merge(C, D);
//		cout<<AB.size()<<endl;
//		cout<<CD.size()<<endl;
//		cout<<"AAA"<<endl;
//		cout<<A<<endl;
//		cout<<B<<endl;
//		cout<<C<<endl;
//		cout<<D<<endl;
//		cout<<AB<<endl;
//		cout<<CD<<endl;
		int ans = 1<<30;
		ll value = 0;
		bool found=false;
		int abc, cdc;
		FOR(e, AB) {
			ll v = e->first;
			if(CD.count(v)) {
				ans = min(ans, AB[v]+CD[v]);
				found=true;
				abc = AB[v];
				cdc = CD[v];
				value = v;
			}
		}
		if(!found) ans=-1;
		cout<<ans<<endl;
//		cout<<"BBB"<<endl;
//		cout<<abc<<endl;
//		cout<<cdc<<endl;
		if(found) {
			find(value, abc, A, B);
			find(value, cdc, C, D);
		}
	}
	
	return 0;
}







