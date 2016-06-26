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
#define P(v) cout<<#v<<": "<<v<<endl
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

int log2(int N) {
	int rv = 0;
	while(N>1) {
		N/=2;
		rv++;
	}
	return rv;
}

void simulate(VI p, const VVI& w, VI& Min, VI& Max) {
	int N = p.size();
	deque<ll> q;
	REP(i, N) q.PB(p[i]);
	VI won(N);
	VI th(N);
	while(q.size()>1) {
		ll p0 = q.front(); q.pop_front();
		ll p1 = q.front(); q.pop_front();
		ll winner = w[p0][p1] ? p0 : p1;
		won[winner]++;
		q.PB(winner);
	}
	REP(i, N) {
		Min[i] = min(Min[i], won[i]);
		Max[i] = max(Max[i], won[i]);
	}
}

void naive(VVI w, VI& Min, VI& Max) {
	ll N = w.size();
	Min = VI(N, N+10);
	Max = VI(N, 0);

	VI p(N);
	REP(i, N) p[i]=i;
	// 10: 3628800  16: 2.092279e+13
	do {
		simulate(p, w, Min, Max);
	} while(next_permutation(ALL(p)));
}

vector<bool> used;

struct Req {
	int subject;
	int winOrLose;
	int gameCount;
};

// I が gameCount 回戦(0base)で winOrLose できる相手を探す.
// 探せた場合, I, 相手共にそこまで勝ち残ることを保証する.
bool possibleChildren(const VVI& w, deque<Req> rs) {
	int N = w.size();
	if(!rs.size()) return true;

	int I = rs[0].subject;
	int winOrLose = rs[0].winOrLose;
	int gameCount = rs[0].gameCount;
//	cout<<" PossibleChildren "<<I<<" "<<winOrLose<<" "<<gameCount<<endl;
	rs.pop_front();
	REP(i, N) if(!used[i]) {
//		cout<<"  "<<used<<endl;
//		cout<<"  try "<<i<<" -> "<<w[I][i]<<" ( PossibleChildren "<<I<<" "<<winOrLose<<" "<<gameCount<<endl;
		bool lok = w[I][i]==winOrLose;
		if(lok) {
			if(gameCount) {
				int winMin = (1<<(gameCount-1))-1;
				int coi = 0, coI = 0;
				REP(j, N) if(j!=i && !used[j] && w[i][j]==1) coi++;
				REP(j, N) if(j!=I && !used[j] && w[I][j]==1) coI++;
				if(coi<winMin) lok = false;
				if(coI<winMin) lok = false;
			}
		}
		if(lok) {
			vector<bool> old = used;
			used[i] = true;
			bool ok = true;
			deque<Req> nrs = rs;
			if(gameCount) {
				nrs.push_front({i, 1, gameCount-1});
				nrs.push_front({I, 1, gameCount-1});
			}
			if(!possibleChildren(w, nrs)) ok = false;
			if(ok) {
//				cout<<" PossibleChildren "<<I<<" "<<winOrLose<<" "<<gameCount<<" -> 1"<<endl;
				return true;
			}
			used = old;
		}
	}
//	cout<<" PossibleChildren "<<I<<" "<<winOrLose<<" "<<gameCount<<" -> 0"<<endl;
	return false;
}

// can I win winTimes
bool possibleWin(const VVI& w, int I, int winTimes) {
	// win i in [0, win)[th] and lose win[th]
	int N = w.size();
	used = vector<bool>(N);
	REP(i, N) used[i] = I==i;

	if(N==1) return true;
	int winOrLose = winTimes==log2(N);
	int gameCount = min(log2(N)-1, winTimes);
	deque<Req> nrs;
	nrs.push_front({I, winOrLose, gameCount});
	if(!possibleChildren(w, nrs)) return false;
	return true;
}

void solve(VVI w, VI& Min, VI& Max) {
	ll N = w.size();
	Min = VI(N, 100000);
	Max = VI(N, 0);
	ll ln = log2(N);
	REP(i, N) {
//		cout<<endl<<endl<<"----------- "<<i<<endl;
		VI cands;
		REP(j, N) if(i!=j) cands.PB(j);
		REP(win, ln+1) {
//			cout<<"PossibleWin "<<i<<" "<<win<<endl;
			bool can = possibleWin(w, i, win);
//			cout<<"PossibleWin "<<i<<" "<<win<<" -> "<<can<<endl<<endl<<endl;
			if(can) {
				Min[i] = min(Min[i], (ll)win);
				Max[i] = max(Max[i], (ll)win);
			}
		}
//		P(Min[i]);
//		P(Max[i]);
	}
}

/*
N=16として,
自分と対戦相手4人(16*15*14*13*12 = 524,160通り)を決めた時に
それぞれ対戦相手がそこまで勝ち残れるかどうかを O(1) で決めたい.



*/
int main() {
	//ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		ll N;
		cin>>N;
		VVI w(N, VI(N));
		REP(i, N) REP(j, N) cin>>w[i][j];
		VI Min, Max;
		solve(w, Min, Max);
		if(0)
		{
			VI refMin, refMax;
			naive(w, refMin, refMax);
			if(!(Min==refMin && Max==refMax)) {
				cout<<N<<endl;
				cout<<w<<endl;
				P(refMin);
				P(refMax);
				P(Min);
				P(Max);
				assert(Min==refMin);
				assert(Max==refMax);
			}
		}
		cout<<"Case #"<<CaseID+1<<": "<<endl;
		auto won2th = [&](int won) {
			ll rv = N/2;
			REP(i, won) rv/=2;
			return rv+1;
		};
		REP(i, N) {
			cout<<won2th(Max[i])<<" "<<won2th(Min[i])<<endl;
		}
//		break;
	}
	
	return 0;
}
