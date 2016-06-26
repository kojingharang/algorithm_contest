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
#define VI vector<ll>
#define VVI vector<vector<ll> >
#define PII pair<int, int> 
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
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

#define INF 1000000000LL

int s2i(string s) {
	stringstream ss(s);
	int v;
	ss>>v;
	return v;
}

int check(int v, int M) {
	return 1<=v && v<=M;
}

int main() {
	int TT;
	cin>>TT;
	REP(tt, TT) {
		int M;
		string S;
		cin>>M>>S;
		VI dp(S.size());
		for(int i=S.size()-1;i>=0;i--) {
			if(check(s2i(S.substr(i, 1)), M)) dp[i] += i+1<dp.size() ? dp[i+1]:1;
			if(i+1<S.size() && S[i]!='0' && check(s2i(S.substr(i, 2)), M)) dp[i] += i+2<dp.size() ? dp[i+2]:1;
			if(i+2<S.size() && S[i]!='0' && check(s2i(S.substr(i, 3)), M)) dp[i] += i+3<dp.size() ? dp[i+3]:1;
			dp[i] = dp[i] % 0xFACEB00CLL;
		}
		//cout<<M<<" "<<S<<endl;
		//REP(i, S.size()) {
		//	cout<<S[i]<<" ";
		//}
		//cout<<endl;
		//cout<<dp<<endl;
		
		cout<<"Case #"<<tt+1<<": "<<dp[0]<<endl;
	}
	return 0;
}


