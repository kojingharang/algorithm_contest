#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
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
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(ll i=0,_n=(n);(i)<(int)_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

#define INF (1<<30)

vector<string> s;
VI vis;
//int ans=0;
int N;
map<int, int> memo;
int f(int i, int p) {
	if(memo.count(i)) return memo[i];
	//cout<<i<<endl;
	if(vis[i]) {
		return 0;
	}
	vis[i]=p;
	//p += s[i].size();
	int ans = -INF;
	for(int j=0;j<=i;j++) {
		if(s[i][s[i].size()-1]==s[j][0] && vis[j]) {
			//ans = max(ans, p-vis[j]);
			ans = s[i].size();
			//cout<<i<<" loop: "<<p-vis[j]<<endl;
		}
	}
	for(int j=i+1;j<N;j++) {
		if(s[i][s[i].size()-1]==s[j][0]) {
			//cout<<"go to "<<j<<" from "<<i<<endl;
			if(!vis[j]) ans=max(ans, (int)s[i].size()+f(j, p));
		}
	}
	vis[i]=0;
	//cout<<i<<" "<<ans<<endl;
	return memo[i]=ans;
}


int main() {
	cin>>N;
	s = vector<string>(N);
	REP(i, N) cin>>s[i];
	vis = VI(N);
	int ans = 0;
	REP(i, N) {
		ans = max(ans, f(i, 1));
		//vis[i]=1;
	}
	//cout<<vis<<endl;
	
	cout<<ans<<endl;
	
	return 0;
}
