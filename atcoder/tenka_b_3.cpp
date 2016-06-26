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
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

#define MOD 1000000007LL
#define INF (1LL<<60)

int dfs(const VI& S, const VI& E, VI& be, VI& en, int idx) {
	if(idx==S.size()) return 1;
	REP(i, en.size()) {
		int within = E[idx]<24*60;
		int ok = E[idx]<24*60;
		if(E[idx]>=24*60) {
			ok = E[idx]-24*60 <= be[i];
		}
		if(en[i]<=S[idx] && ok) {
			ll oen = en[i];
			ll obe = be[i];
			en[i] = E[idx];
			if(within) be[i] = E[idx]-24*60;
			else be[i] = min(be[i], S[idx]);
			int ret = dfs(S, E, be, en, idx+1);
			if(ret) return ret;
			en[i] = oen;
			be[i] = obe;
		}
	}
	return 0;
}

int main() {
	ll N;
	while(cin>>N) {
		VI S(N), E(N);
		REP(i, N) {
			string s;
			cin>>s;
			S[i] = ((s[0]-'0')*10+(s[1]-'0'))*60+((s[3]-'0')*10+(s[4]-'0'));
			cin>>s;
			E[i] = ((s[0]-'0')*10+(s[1]-'0'))*60+((s[3]-'0')*10+(s[4]-'0'));
		}
		if(N>8) {
			cout<<0<<endl;
			continue;
		}
		
		ll lo=0, hi=N; // hi is OK
		while(lo+1<hi) {
			ll mid=(lo+hi)/2;
			VI be(mid, 24*60);
			VI en(mid);
			if(dfs(S, E, be, en, 0)) hi=mid; else lo=mid;
		}
		//cout<<S<<endl;
		//cout<<E<<endl;
		cout<<hi<<endl;
	}
	
	return 0;
}
