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

int check(vector<string>& call, vector<vector<string> >& defs) {
	int ans = 0;
	REP(i, defs.size()) {
		if(defs[i].size() != call.size()) continue;
		int ok=1;
		REP(j, defs[i].size()) {
			if(!(defs[i][j]=="T" || defs[i][j]==call[j])) ok=0;
		}
		ans += ok;
	}
	return ans;
}


int main() {
	int N,M,K;
	while(cin>>N) {
		vector<vector<string> > defs;
		map<string, string> vars;
		
		string s;
		getline(cin, s);
		REP(i, N) {
			vector<string> def;
			
			getline(cin, s);
			//cout<<"LINE "<<s<<endl;
			//continue;
			REP(i, s.size()) {
				if(s[i]=='(' || s[i]==')' || s[i]==',') s[i]=' ';
			}
			stringstream ss(s);
			ss>>s; // void
			//cout<<"S "<<s<<endl;
			ss>>s;
			//cout<<"S "<<s<<endl;
			def.PB(s);
			
			while(ss>>s) {
				//cout<<"S "<<s<<endl;
				def.PB(s);
			}
			//cout<<"def "<<def<<endl;
			defs.PB(def);
		}
		cin>>M;
		REP(i, M) {
			string ty, name;
			cin>>ty>>name;
			vars[name] = ty;
		}
		//cout<<vars<<endl;
		
		cin>>K;
		getline(cin, s);
		REP(i, K) {
			getline(cin, s);
			//cout<<"LINE "<<s<<endl;
			REP(i, s.size()) {
				if(s[i]=='(' || s[i]==')' || s[i]==',') s[i]=' ';
			}
			stringstream ss(s);
			vector<string> call;
			ss>>s;
			call.PB(s);
			while(ss>>s) {
				//cout<<"S "<<s<<endl;
				call.PB(vars[s]);
			}
			//cout<<call<<endl;
			cout<<check(call, defs)<<endl;
		}
	}
	
	return 0;
}
