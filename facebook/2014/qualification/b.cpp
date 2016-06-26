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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

// Return random integer in [s, e)
#define UNIFORM_INT(s, e)    ( s + (int)((e-s) * UNIFORM_FLOAT_01()) )

// Return random float in [s, e)
#define UNIFORM_FLOAT(s, e)  ( s + (e-s) * UNIFORM_FLOAT_01() )
#define UNIFORM_FLOAT_01()  ( (float)rand()/(1.0f+RAND_MAX) )


#define MOD 1000000007LL
#define INF (1LL<<60)

struct person {
	string name;
	int shot;
	int tall;
	int in;
	int in_time;
	ll score() const {
		return in * 100000000LL + in_time * 100000 + (100-shot)*1000 + (240-tall);
	}
	void print() {
		cout<<"  "<<name<<" "<<in<<" "<<in_time<<endl;
	}
};

bool operator<(const person& a, const person& b) {
	return a.score() < b.score();
}

int main() {
	//ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		ll N, M, P;
		cin>>N>>M>>P;
		vector<person> w(N);
		REP(i, N) {
			cin>>w[i].name>>w[i].shot>>w[i].tall;
			w[i].in = 0;
			w[i].in_time = 0;
		}
		sort(ALL(w));
//		REP(i, N) cout<<w[i].name<<endl;
		vector<vector<person> > team(2);
		REP(i, N) {
			team[i%2].PB(w[i]);
		}
		REP(ti, 2) REP(pi, P) team[ti][pi].in=1;
		REP(t, M) {
//			cout<<"M "<<t<<endl;
			REP(ti, 2) {
				REP(pi, team[ti].size()) if(team[ti][pi].in) team[ti][pi].in_time++;
//				cout<<"Team "<<ti<<endl;
//				REP(pi, team[ti].size()) team[ti][pi].print();
				if(team[ti].size() > P) {
					sort(ALL(team[ti]));
					assert(team[ti][0].in==0);
					assert(team[ti][team[ti].size()-1].in==1);
					team[ti][0].in=1;
					team[ti][team[ti].size()-1].in=0;
				}
			}
		}
		
		vector<string> out;
		REP(ti, 2) REP(pi, team[ti].size()) if(team[ti][pi].in) out.PB(team[ti][pi].name);
		sort(ALL(out));
		cout<<"Case #"<<CaseID+1<<": ";
		REP(i, out.size()) {
			cout<<out[i];
			if(i<out.size()-1) cout<<" ";
		}
		cout<<endl;
//		break;
	}
	
	return 0;
}
