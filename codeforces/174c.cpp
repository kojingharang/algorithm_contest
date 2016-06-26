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
	int N;
	cin>>N;
	vector<PII> st(100010);
	vector<pair<PII, int> > ans(100010);
	int ansp=0;
	int anscount=0;
	int stp=0;
	REP(i, N) {
		int v;
		cin>>v;
		int push_pos=i;
		while(stp>0 && st[stp-1].second > v) {
			push_pos = st[stp-1].first;
			//cout<<"push_pos "<<push_pos<<endl;
			int prevH = max(v, stp-1>0 ? st[stp-2].second : 0);
			ans[ansp++] = MP(MP(st[stp-1].first+1, i), st[stp-1].second - prevH);
			anscount += st[stp-1].second - prevH;
			stp--;
		}
		if(stp==0) {
			if(v>0) st[stp++] = MP(push_pos, v);
		} else if(st[stp-1].second < v) {
			st[stp++] = MP(push_pos, v);
		}
		//REP(m, stp) cout<<st[m]<<" "; cout<<endl;
	}
	while(stp>0) {
		int prevH = stp-1>0 ? st[stp-2].second : 0;
		ans[ansp++] = MP(MP(st[stp-1].first+1, N), st[stp-1].second-prevH);
		anscount += st[stp-1].second-prevH;
		stp--;
	}
	
	cout<<anscount<<endl;
	REP(i, ansp) {
		REP(j, ans[i].second) {
			cout<<ans[i].first.first<<" "<<ans[i].first.second<<endl;
		}
	}
	
	return 0;
}
