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
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define VVVI vector<vector<vector<ll>>>
#define VVVVI vector<vector<vector<vector<ll>>>>
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define REPR(i,n) for(int i=(int)(n)-1;0<=(i);--i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define RANGER(i,a,b) for(int i=(int)(b)-1,_a=(int)(a);(_a)<=i;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}

#define MOD 1000000007LL
#define INF (1LL<<60)
string BS(int v) {
	int N = 16;
	string s(N, '0');
	REP(i, N) s[N-1-i] = (v>>i&1)+'0';
	return s;
}
int SB(string s) {
	int v = 0;
	REP(i, s.size()) v |= (s[s.size()-1-i]-'0')<<i;
	return v;
}

double ref(int s0) {
	int f,r,i,j,k,l, x,y,z;
	vector<double> F((1<<16)+10);
	REP(i,1<<17) {
		if((i & s0) != i) continue;
		if(i==0) continue;
		
		F[i]=1e9;
		
		for(j=1;j<=14;j++) {
			double aa=0;
			int pat = (i >> (j-1)) & 7;
			double f1=F[i^(1<<(j-1))];
			double f2=F[i^(1<<(j))];
			double f3=F[i^(1<<(j+1))];
			
			if(pat==0) continue;
			if(pat==7) aa = 1 + (f1+f2+f3)/3;
			if(pat==6) aa = (1 + (f2+f3)/3)*1.5;
			if(pat==5) aa = (1 + (f1+f3)/3)*1.5;
			if(pat==3) aa = (1 + (f1+f2)/3)*1.5;
			if(pat==4) aa = (1 + f3/3)*3;
			if(pat==2) aa = (1 + f2/3)*3;
			if(pat==1) aa = (1 + f1/3)*3;
			
			F[i]=min(F[i],aa);
		}
	}
	return F[s0];
}

double solve(int s0) {
	// [b] : b -> 0 にするための期待値
	vector<double> dp(s0+1, INF);
	dp[0] = 0;
	RANGE(b, 1, s0+1) {
//		cout<<"### "<<BS(b)<<endl;
		REP(si, 16-3+1) {
			int wp = b>>si&7;
			if(wp==0) continue;
			int self = 0;
			double rhs = 0.0;
//			cout<<BS(7<<si)<<endl;
			REP(rmi, 3) {
				if(wp>>rmi&1) {
					int nb = b ^ 1<<(si+rmi);
					rhs += 1+dp[nb];
//					cout<<" <- "<<BS(nb)<<" "<<dp[nb]<<endl;
				} else {
					self++;
//					cout<<" <- self "<<endl;
				}
			}
//			DD(dp);
			// dp[b] = (1+dp[b])*self/3.0 + rhs
			double lv = (rhs + self) / 3.0 / (1-self/3.0);
//			cout<<"LV "<<lv<<endl;
			minUpdate(dp[b], lv);
		}
	}
//	REP(i, s0+1) if(dp[i]<INF) cout<<BS(i)<<" "<<dp[i]<<endl;
	return dp[s0];
}

// 1011(0) -> 1001 (1.5) -> 0001 or 1000 (4.5) -> 0000 (7.5)
// 1011(0) -> 1010 (1.5) -> 1000 or 0010 (3) -> 0000 (6)
// の 2 通りあり別々に使われる必要があるが, この方法では一律最小値の 6 が採用されるのが間違っている.
// なので配る dp はここでは使えない.
double ng(int s0) {
	// [b] : s0 -> b にするための期待値
	vector<double> dp(s0+1, INF);
	dp[s0] = 0;
	vector<double> cost2 = {0, 3, 1.5, 1};
	REPR(b, s0+1) if(dp[b]<INF) {
		REP(si, 16-3) {
			int wp = b>>si&7;
			REP(rmi, 3) {
				if(wp>>rmi&1) {
					int nb = b ^ 1<<(si+rmi);
					minUpdate(dp[nb], dp[b]+cost2[POPCOUNT(wp)]);
				}
			}
		}
	}
//	REP(i, s0+1) if(dp[i]<INF) cout<<BS(i)<<" "<<dp[i]<<endl;
	return dp[0];
}

/*
E3 = 1/3(1+E2)+1/3(1+E2)+1/3(1+E2) = 1+E2
E2 = 1/3(1+E2)+1/3(1+E1)+1/3(1+E1) = 3/2+E1
E1 = 1/3(1+E1)+1/3(1+E1)+1/3(1) = 3
*/
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,X;
//	RANGE(s0, 1, 1<<16) {
//		s0 = SB("0000000000001011");
////		double r0 = ref(s0);
//		double r0 = ng(s0);
//		double r1 = solve(s0);
//		DD(BS(s0));
////		return 0;
//		if(abs(r0-r1) > 1e-6) {
//			cout<<"DIFF"<<endl;
//			DD(BS(s0));
//			DD(r0);
//			DD(r1);
//			return 0;
//		}
//	}
	while(cin>>N) {
		int s0 = 0;
		REP(i, N) cin>>X, s0|=1<<X;
//		DD(s0);
		cout<<setprecision(20)<<solve(s0)<<endl;
//		break;
	}
	
	return 0;
}

/*
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,X;
	while(cin>>N) {
		int s0 = 0;
		REP(i, N) cin>>X, s0|=1<<X;
		// [b] : s0 -> b にするための期待値
		vector<double> dp(s0+1, INF);
		dp[s0] = 0;
		vector<double> cost2 = {0, 3, 1.5, 1};
		REPR(b, s0+1) if(dp[b]<INF) {
			REP(si, 16-3) {
				int wp = b>>si&7;
				REP(rmi, 3) {
					if(wp>>rmi&1) {
						int nb = b ^ 1<<(si+rmi);
						minUpdate(dp[nb], dp[b]+cost2[POPCOUNT(wp)]);
					}
				}
			}
		}
		REP(i, s0+1) if(dp[i]<INF) cout<<BS(i)<<" "<<dp[i]<<endl;
		cout<<dp[0]<<endl;
	}
	
	return 0;
}
*/
