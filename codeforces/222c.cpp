#include <stdio.h>
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
#define VI vector<int>
#define PII pair<ll, ll> 
#define VVI vector<vector<int> >
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
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

int A[100000];
int B[100000];
int pw[10000010];
int ps[700000];
int psN;
void make_primes(int N) { // return all prime numbers less than N  memory: O(N) time: O(N^2)?
	REP(i, N) pw[i] = 1;
	for(int i=2;i<N;i++) if(pw[i]==1) { pw[i]=i; ps[psN++] = i; for(int j=i*2;j<N;j+=i) pw[j]=i; }
}

int main() {
	ios::sync_with_stdio(false);
	int N,M;
	make_primes(10000001);
	while(scanf("%d", &N)==1) {
		scanf("%d", &M);
		int v;
		map<int, int> hi;
		REP(i, N) {
			scanf("%d", &v);
			A[i] = v;
			while(pw[v]>1) {
				hi[pw[v]]++;
				v /= pw[v];
			}
		}
		REP(i, M) {
			scanf("%d", &v);
			B[i] = v;
			while(pw[v]>1) {
				hi[pw[v]]--;
				v /= pw[v];
			}
		}
		printf("%d %d\n", N, M);
		REP(i, N) {
			int v = A[i];
			int out = 1;
			while(pw[v]>1) {
				if(hi[pw[v]]>0) hi[pw[v]]--, out*=pw[v];
				v /= pw[v];
			}
			printf("%d ", out);
		}
		printf("\n");
		REP(i, M) {
			int v = B[i];
			int out = 1;
			while(pw[v]>1) {
				if(hi[pw[v]]<0) hi[pw[v]]++, out*=pw[v];
				v /= pw[v];
			}
			printf("%d ", out);
		}
		printf("\n");
	}
	
	return 0;
}
