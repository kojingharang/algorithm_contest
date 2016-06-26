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
#include <cstdio>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
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
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[x][y]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 


int Ms[310];
char ibuffer[100000];
char obuffer[100000];

int main() {
	cin.sync_with_stdio(false);
	srand((unsigned)time(NULL));
	if(0)
	{
		REP(loop, 100) {
			int N = UNIFORM_LL(2, 500000);
			int M = UNIFORM_LL(1, 300);
			cout<<N<<" "<<M<<endl;
			REP(i, N) cout<<UNIFORM_LL(10, 1000000)<<endl;
			REP(i, M) cout<<UNIFORM_LL(0, 1000000)<<endl;
		}
		return 0;
	}

	setvbuf(stdin, ibuffer, _IOFBF, sizeof(ibuffer));
	setvbuf(stdout, obuffer, _IOFBF, sizeof(obuffer));
	
	int N, M, v, x=0;
	char buf[512];
	while(scanf("%d %d", &N, &M) != EOF) {
//	while(cin>>N>>M) {
		fgets(buf, sizeof(buf), stdin);
		REP(i, N) {
			fgets(buf, sizeof(buf), stdin);
			v = atoi(buf);
//			cout<<v<<endl;
//			scanf("%d", &v);
//			cin>>v;
			x ^= v;
		}
		REP(i, M) {
			fgets(buf, sizeof(buf), stdin);
			v = atoi(buf);
//			scanf("%d", &v);
//			cin>>v;
			x ^= v;
		}
	}
	cout<<x<<endl;
	return 0;
}
