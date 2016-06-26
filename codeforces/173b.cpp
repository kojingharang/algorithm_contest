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

#define MOD 1000000007LL
#define INF 2000000
#define YET 4000000

int H,W;
vector<string> ta;
VI dp;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

int f(int x, int y, int i) {
	//if(x<0||y<0||x>=W||y>=H) return dp[((y+1)*(W+2)+(x+1))*4+i]=INF;
	cout<<x<<" "<<y<<" "<<i<<endl;
	REP(j, 4) {
		if(x+dx[j]<0||y+dy[j]<0||x+dx[j]>=W||y+dy[j]>=H) continue;
		int t = dp[((y+dy[j]+1)*(W+2)+(x+dx[j]+1))*4+j];
		if(t==YET) t = f(x+dx[j], y+dy[j], j);
		if(i==j) {
			dp[((y+1)*(W+2)+(x+1))*4+i] = min(INF, min(dp[((y+1)*(W+2)+(x+1))*4+i], t));
			//cout<<x<<" "<<y<<" "<<i<<" <- "<<x+dx[j]<<" "<<y+dy[j]<<" "<<j<<"("<<t<<endl;
		} else {
			if(ta[y][x]=='#') {
				dp[((y+1)*(W+2)+(x+1))*4+i] = min(INF, min(dp[((y+1)*(W+2)+(x+1))*4+i], t+1));
			}
		}
	}
	cout<<x<<" "<<y<<" "<<i<<" == "<<dp[((y+1)*(W+2)+(x+1))*4+i]<<endl;
	dp[((y+1)*(W+2)+(x+1))*4+i] = min(dp[((y+1)*(W+2)+(x+1))*4+i], INF);
	return dp[((y+1)*(W+2)+(x+1))*4+i];
}

int main() {
	cin>>H>>W;
	ta = vector<string>(H);
	
	REP(i, H) {
		cin>>ta[i];
	}
	
	dp = VI((H+2)*(W+2)*4, YET);
	
	dp[((0+1)*(W+2)+(0+1))*4+0] = 0;
	//REP(y, H) {
	//	REP(x, W) {
	//		REP(i, 4) {
	//			REP(j, 4) {
	//				int t = dp[((y+dy[j]+1)*(W+2)+(x+dx[j]+1))*4+j];
	//				if(i==j) {
	//					dp[((y+1)*(W+2)+(x+1))*4+i] = min(dp[((y+1)*(W+2)+(x+1))*4+i], t);
	//					//cout<<x<<" "<<y<<" "<<i<<" <- "<<x+dx[j]<<" "<<y+dy[j]<<" "<<j<<"("<<t<<endl;
	//				} else {
	//					if(ta[y][x]=='#') {
	//						dp[((y+1)*(W+2)+(x+1))*4+i] = min(dp[((y+1)*(W+2)+(x+1))*4+i], t+1);
	//					}
	//				}
	//			}
	//			//cout<<x<<" "<<y<<" "<<i<<" == "<<dp[((y+1)*(W+2)+(x+1))*4+i]<<endl;
	//		}
	//	}
	//}
	
	//REP(y, H) {
	//	REP(x, W) REP(i, 4) cout<<dp[((y+1)*(W+2)+(x+1))*4+i]<<" ";
	//	cout<<endl;
	//}
	//int ans = dp[((H-1+1)*(W+2)+(W-1+1))*4+0];
	int ans = f(W-1, H-1, 0);
	if(ans==INF) ans = -1;
	cout<<ans<<endl;
	
	return 0;
}
