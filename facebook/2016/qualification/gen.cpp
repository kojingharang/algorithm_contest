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
//#pragma comment(linker,"/STACK:20000000")

int main() {
	ios::sync_with_stdio(false);
	if(0)
	{
		int T = 50;
		int N = 2000;
		cout<<T<<endl;
		REP(t, T) {
			cout<<N<<endl;
			REP(i, N) {
				ll x = UNIFORM_LL(-10000, 10000);
				ll y = UNIFORM_LL(-10000, 10000);
				cout<<x<<" "<<y<<endl;
			}
		}
	}
	if(0)
	{
		int T = 200;
		cout<<T<<endl;
		REP(t, T) {
			int N = UNIFORM_LL(1, 1000);
			cout<<N<<endl;
			vector<string> s(2, string(N, '.'));
			REP(y, 2) REP(i, N) s[y][i] = UNIFORM_DOUBLE(0, 1)<0.5 ? '.':'X';
			REP(y, 2) cout<<s[y]<<endl;
		}
	}
	if(0)
	{
		int T = 40;
		cout<<T<<endl;
		REP(t, T) {
			int N = UNIFORM_LL(1, 100000);
			int P = UNIFORM_LL(1, 1000000000);
			cout<<N<<" "<<P<<endl;
			REP(i, N) cout<<UNIFORM_LL(1, 1000000000)<<" ";
			cout<<endl;
		}
	}
	// d random
//	if(0)
	{
		int T = 100;
		cout<<T<<endl;
		REP(t, T) {
			int N = 10;
			int K = UNIFORM_LL(1, N+1);
			cout<<N<<" "<<K<<endl;
			REP(i, N) {
				string s(UNIFORM_LL(1, 20), 'a');
				REP(j, s.size()) s[j]='a'+(j%2);
				random_shuffle(ALL(s));
				printf("%s\n", s.c_str());
			}
		}
	}
	// d big
	if(0)
	{
		int T = 100;
		cout<<T<<endl;
		REP(t, T) {
			int N = 300;
			int K = 300;
			cout<<N<<" "<<K<<endl;
			REP(i, N) {
				string s(1000, 'a');
				REP(j, s.size()) s[j]='a'+(j%26);
				random_shuffle(ALL(s));
				REP(loop, 100) printf("%s", s.c_str());
				puts("\n");
			}
		}
	}
	return 0;
}
