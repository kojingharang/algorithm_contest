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

ll N, M, D;
VI cum(12);

int getD(const string& s) {
	stringstream ss;
	FOR(e, s) ss<<(*e=='/'?' ':*e);
	ss>>M>>D;
	int d = cum[M-1]+D-1;
	return d;
}

int main() {
	//ios::sync_with_stdio(false);
	string s;
	int days[] = {31,29,31,30,31,30,  31,31,30,31,30,31};
	//REP(i, 12) REP(z, days[i]) cout<<i+1<<"/"<<z+1<<endl;
	RANGE(i, 1, 12) {
		cum[i]+=cum[i-1]+days[i-1];
	}
	REP(i, 12) REP(z, days[i]) {
		stringstream ss;
		ss<<i+1<<"/"<<z+1;
		//cout<<ss.str()<<" "<<getD(ss.str())<<endl;;
	}
	while(cin>>N) {
		//cout<<"--"<<N<<endl;
		VI w(370);
		REP(i, 366) {
			if(i%7==0) w[i]=1;
			if(i%7==6) w[i]=1;
		}
		VI kyu;
		REP(i, N) {
			cin>>s;
			int d = getD(s);
			kyu.PB(d);
			//cout<<M<<" "<<D<<" -> "<<d<<endl;
		}
		sort(ALL(kyu));
		REP(i, kyu.size()) {
			int d = kyu[i];
			for(;d<366 && w[d];d++) {
			}
			if(d<366) w[d]=1;
		}
		//cout<<w<<endl;
		int ans=0;
		int lans = 0;
		REP(i, 366) {
			if(w[i]==0) lans=0;
			else {
				lans++;
				ans=max(ans, lans);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
