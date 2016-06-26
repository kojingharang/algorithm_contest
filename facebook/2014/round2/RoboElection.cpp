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

int naive() {
	int T;
	cin>>T;
	REP(ttt, T) {
		ll N, K, P;
		cin>>N>>K>>P;
		ll nz = 0;
		VI w(N);
		ll ans = 1;
		for(int i=N-N%K;i>=0;i-=K) {
			ll all = N-i;
			if(all==0) continue;
			ll n = min(K, all);
			ll vote=n;
			RANGE(j, i+n, N) {
				//vote += w[j]==0;
			}
			vote += nz;
			int win=0;
			if(vote * 100 >= all * P) {
				nz=0;
				win=1;
				ans = 1;
				//REP(j, n) w[i+j]=1;
				//RANGE(j, i+n, N) {
				//	w[j]=1;
				//}
			} else {
				ans++;
				nz += n;
			}
			cout<<i<<" "<<n<<" "<<all<<" vote "<<vote<<" r "<<(float)vote/all<<" -> "<<win<<endl;
			//cout<<w<<endl;
		}
		REP(i, N) {
		}
		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		break;
	}
	return 0;
}

ll N, K, P;

int main() {
	int T;
	cin>>T;
	REP(ttt, T) {
		cin>>N>>K>>P;
		ll nz = 0;
		ll ans = 1;
		if(P==100) {
			ans = (N+K-1)/K;
		} else {
			for(ll all=N%K==0 ? K : N%K;all<=N;all+=K) {
				ll n = min(K, all);
				ll vote=n + nz;
				if(vote * 100 >= all * P) {
					nz=0;
					ans = 1;
				} else {
					if(n==K && (N-all)/K > 10) {
						ll lo=0,hi=(N-all)/K;
						int hiv;
						{
							ll n_vote = K + nz + K*hi;
							ll n_all = all + K*hi;
							hiv = (n_vote * 100 >= n_all * P);
						}
						if(hiv) {
							while(lo+1<hi) {
								ll mid = (lo+hi)/2;
								ll n_vote = K + nz + K*mid;
								ll n_all = all + K*mid;
								//cout<<"BS "<<mid<<" "<<(float)n_vote/n_all<<" "<<n_vote<<" "<<n_all<<endl;
								if(n_vote * 100 >= n_all * P) hi=mid; else lo=mid;
							}
							//cout<<"BSS hi="<<hi<<" init hi:"<<(N-all)/K<<" hiv:"<<hiv<<endl;
							ans += hi;
							nz += K*hi;
							all += K*hi - K;
						} else {
							ans++;
							nz += n;
						}
					} else {
						ans++;
						nz += n;
					}
				}
				//all += n;
				//cout<<" "<<n<<" "<<all<<" vote "<<vote<<" r "<<(float)vote/all<<" -> "<<(vote * 100 >= all * P)<<endl;
			}
		}
		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		break;
	}
	return 0;
}


