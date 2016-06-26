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

int main() {
	int H,W;
	cin>>H>>W;
	vector<string> ta(H);
	
	REP(i, H) {
		cin>>ta[i];
	}
	
	VI dp((H+2)*(W+2)*4, INF);
	dp[((0+1)*(W+2)+(0+1))*4+0] = 0;
	int dx[4]={1,0,-1,0};
	int dy[4]={0,1,0,-1};
	REP(y, H) {
		REP(x, W) {
			REP(i, 4) {
				int t = dp[((y+1)*(W+2)+(x+1))*4+i];
				REP(j, 4) {
					//int t = dp[((y+dy[j]+1)*(W+2)+(x+dx[j]+1))*4+j];
					int idx = ((y+dy[j]+1)*(W+2)+(x+dx[j]+1))*4+j;
					if(i==j) {
						dp[idx] = min(dp[idx], t);
						cout<<x<<" "<<y<<" "<<i<<" -> "<<x+dx[j]<<" "<<y+dy[j]<<" "<<j<<"("<<t<<endl;
					} else {
						//if(y+dy[j]>=0 && y+dy[j]<H && x+dx[j]>=0 && x+dx[j]<W && ta[y+dy[j]][x+dx[j]]=='#') {
						if(ta[y][x]=='#') {
							dp[idx] = min(dp[idx], t+1);
						}
					}
				}
				cout<<x<<" "<<y<<" "<<i<<" == "<<t<<endl;
			}
		}
	}
	
	//REP(y, H) {
	//	REP(x, W) REP(i, 4) cout<<dp[((y+1)*(W+2)+(x+1))*4+i]<<" ";
	//	cout<<endl;
	//}
	int ans = dp[((H-1+1)*(W+2)+(W-1+1))*4+0];
	if(ans==INF) ans = -1;
	cout<<ans<<endl;
	
	return 0;
}
