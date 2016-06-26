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
#include <numeric>
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

ll f(int K, string& S) {
	int N=S.size();
	VI count(N+1);
	int co=0;
	count[0]=1;
	REP(i, N) {
		if(S[i]=='1') co++;
		count[co]++;
	}
	//cout<<count<<endl;
	ll ans=0;
	REP(i, N+1) {
		if(i+K<N+1) {
			if(K==0) {
				ans += (ll)count[i]*(count[i]-1)/2;
			} else {
				ans += (ll)count[i]*count[i+K];
			}
		}
	}
	return ans;
}

int main() {
	int K;
	string S;
	cin>>K>>S;
	cout<<f(K, S)<<endl;
	//int N = 4;
	//string S(N, 0);
	//REP(pat, 1<<N) {
	//	REP(i, N) S[i] = ((pat>>i)&1) ? '1':'0';
	//	REP(k, N+1) {
	//		int ans = f(k, S);
	//		int ref = 0;
	//		REP(ii, N) REP(jj, N) {
	//			if(ii>jj) continue;
	//			int co=0;
	//			for(int m=ii;m<=jj;m++) co+=S[m]=='1';
	//			ref += co==k;
	//		}
	//		//if(ref!=ans)
	//		{
	//			cout<<ref<<" "<<ans<<" "<<k<<" "<<S<<endl;
	//		}
	//	}
	//}
	
	
	return 0;
}
