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
#define VVI vector<vector<int> >
#define PII pair<int, int> 
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

void hist(string s, VI& hist) {
	REP(i, 26) hist[i]=0;
	REP(i, s.size()) if(s[i]!='?') hist[s[i]-'a']++;
}

int main() {
	string s, p;
	cin>>s>>p;
	int ans=0;
	VI ph(26);
	VI sh(26);
	hist(p, ph);
	hist(s.substr(0, p.size()), sh);
	REP(i, ph.size()) ph[i]-=sh[i];
	int ok=1;
	REP(i, ph.size()) if(ph[i]<0) ok=0;
	if(ok) ans++;
	
	//cout<<ph<<endl;
	for(int i=p.size();i<s.size();i++) {
		//cout<<s[i-p.size()]<<" "<<s[i]<<endl;
		if(s[i-p.size()]!='?') ph[s[i-p.size()]-'a']++;
		if(s[i]!='?') ph[s[i]-'a']--;
		//cout<<ph<<endl;
		int ok=1;
		REP(k, ph.size()) if(ph[k]<0) ok=0;
		//cout<<sh<<endl;
		if(ok) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
