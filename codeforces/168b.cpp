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

int main() {
	vector<string> S, r;
	VI shs;
	string s;
	while(getline(cin, s)) {
		//cout<<s<<endl;
		S.PB(s);
		int sh=0;
		REP(j, s.size()) {
			//cout<<s[j]<<endl;
			if(s[j]=='#') {sh=1;break;}
			else if(s[j]!=' ') break;
		}
		shs.PB(sh);
	}
	
	REP(i, S.size()) {
		if(shs[i]) r.PB(S[i]);
		else {
			string s;
			int j;
			for(j=i;j<S.size() && shs[j]==0;j++) {
				REP(k, S[j].size()) if(S[j][k]!=' ') s.PB(S[j][k]);
			}
			i=j-1;
			r.PB(s);
		}
	}
	
	REP(i, r.size()) {
		cout<<r[i]<<endl;
	}
	
	return 0;
}
