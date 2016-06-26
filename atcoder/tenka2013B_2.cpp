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

int main() {
	//ios::sync_with_stdio(false);
	ll Q, N;
	while(cin>>Q>>N) {
		int ok=1;
		ll num = 0;
		deque<pair<int, int> > q;
		REP(i, Q) {
			string op;
			cin>>op;
			ll n, m;
			if(op=="Push") {
				cin>>n>>m;
				if(ok) {
					num += n;
					if(num > N) {
						cout<<"FULL"<<endl;
						ok=0;
					}
					if(ok) q.PB(MP(n, m));
				}
			}
			if(op=="Pop") {
				cin>>n;
				if(ok) {
					num -= n;
					if(num < 0) {
						cout<<"EMPTY"<<endl;
						ok=0;
					}
					if(ok) while(n>0) {
						if(n < q.back().first) {
							q.back().first-=n;
							n=0;
						} else {
							n-=q.back().first;
							q.pop_back();
						}
					}
				}
			}
			if(op=="Top") {
				if(ok) {
					if(num==0) {
						cout<<"EMPTY"<<endl;
						ok=0;
					}
					if(ok) cout<<q.back().second<<endl;
				}
			}
			if(op=="Size") {
				if(ok) {
					cout<<num<<endl;
				}
			}
		}
		if(ok) cout<<"SAFE"<<endl;
	}
	
	return 0;
}



