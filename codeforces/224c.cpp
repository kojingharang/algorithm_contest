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
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

int cum[100010]; // i is # of '[' in S[k] for k in [0, i)

int count(int L, int R) {
	return cum[R+1]-cum[L];
}

int main() {
	//ios::sync_with_stdio(false);
	string S;
	while(cin>>S) {
		cum[0] = 0;
		REP(i, S.size()) {
			cum[i+1] = cum[i] + (S[i]=='[');
		}
		deque<pair<char, int> > mo;
		int N=S.size();
		int L=-1, R=-1;
		int co = 0;
		int start = 0;
		REP(i, N) {
			char op = S[i]==']' ? '[' : '(';
			if(S[i]=='[' || S[i]=='(') {
				mo.PB(MP(S[i], i));
			} else {
				if(mo.size() && mo.back().first==op) {
					mo.pop_back();
					int NL = start;
					if(mo.size()) NL = mo.back().second + 1;
					int NR = i;
					int nco = count(NL, NR);
					if( co < nco ) {
						co = nco;
						L=NL;
						R=NR;
					}
				} else {
					mo.clear();
					start = i+1;
				}
			}
		}
		cout<<co<<endl;
		if(co>0) cout<<S.substr(L, R-L+1)<<endl;
	}
	
	return 0;
}
