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

typedef pair<int, pair<int, pair<int, string> > > Score;

string inv(string A) {
	REP(i, A.size()) A[i] = (25 - (A[i]-'A')) + 'A';
	//cout<<A<<endl;
	return A;
}

map<string, Score> add(map<string, Score> res, string A, string B, int sa, int sb) {
	if(res.count(A)==0) res[A] = MP(0, MP(0, MP(0, inv(A))));
	res[A].first += sa==sb ? 1 : (sa>sb ? 3 : 0);
	res[A].second.first += sa-sb;
	res[A].second.second.first += sa;
	if(res.count(B)==0) res[B] = MP(0, MP(0, MP(0, inv(B))));
	res[B].first += sa==sb ? 1 : (sa<sb ? 3 : 0);
	res[B].second.first += sb-sa;
	res[B].second.second.first += sb;
	return res;
}

int main() {
	string s;
	string invBERLAND(inv("BERLAND"));
	while(1) {
		map<string, Score> res;
		map<string, int> oc;
		REP(loop, 5) {
			if(! getline(cin, s)) return 0;
			REP(i, s.size()) {
				if(s[i]==':') s[i]=' ';
			}
			stringstream ss(s);
			string A, B;
			int sa, sb;
			ss>>A>>B>>sa>>sb;
			//cout<<A<<B<<sa<<sb<<endl;
			res = add(res, A, B, sa, sb);
			
			oc[A]++;
			oc[B]++;
		}
		vector<string> yet;
		FOR(e, oc) if(e->second==2) yet.PB(e->first);
		string opp = yet[0]=="BERLAND" ? yet[1] : yet[0];
		//cout<<opp<<endl;
		
		vector< pair<int, pair<int, int> > > cond;
		REP(X, 100) REP(Y, 100) {
			if(!(X>Y)) continue;
			//cout<<X<<":"<<Y<<endl;
			map<string, Score> result = add(res, "BERLAND", opp, X, Y);
			vector<Score> aa;
			FOR(e, result) aa.PB(e->second);
			sort(ALLR(aa));
			//cout<<aa<<endl;
			if(aa[0].second.second.second==invBERLAND || aa[1].second.second.second==invBERLAND) cond.PB(MP(X-Y, MP(Y, X)));
		}
		sort(ALL(cond));
		
		if(cond.size()==0) {
			cout<<"IMPOSSIBLE"<<endl;
		} else {
			cout<<cond[0].second.second<<":"<<cond[0].second.first<<endl;
		}
	}
	return 0;
}
