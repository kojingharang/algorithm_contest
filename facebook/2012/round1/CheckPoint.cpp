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

int main() {
	int MAXS=10000000;
	//int MAXS=10;
	
	VI w(MAXS, 0);
	w[0]=1;
	VI tab(MAXS+1, INF);
	REP(yo, MAXS+1) {
		int bat=w.size();
		for(int i=1;i<w.size();i++) {
			w[i]=w[i-1]+w[i];
			if(w[i]>=tab.size()) {
				bat=i;
				break;
			}
			tab[w[i]] = min(tab[w[i]], (ll)yo+i);
		}
		//if(yo<10000) {
		//	cout<<"break "<<yo<<" "<<bat<<endl;
		//	REP(i, min(bat,100)) {
		//		cout<<w[i]<<" ";
		//	}
		//	cout<<endl;
		//}
		//cout<<w<<endl;
	}
	//REP(i, 10000) cout<<tab[i]<<" "; cout<<endl;
	
	
	int TT;
	cin>>TT;
	REP(tt, TT) {
		int S;
		cin>>S;
		
		int ans = INF;
		for(int i=1;i*i<=S;i++) {
			if(S%i==0) {
				int L = tab[i]+tab[S/i];
				ans=min(ans, L);
				//cout<<i<<" "<<S/i<<" -> "<<L<<"("<<tab[i]<<" + "<<tab[S/i]<<endl;
			}
		}
		
		cout<<"Case #"<<tt+1<<": "<<ans<<endl;
	}
	return 0;
}


