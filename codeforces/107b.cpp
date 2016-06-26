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
#define VS vector<string>
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

int main() {
	int N, n;
	cin>>N;
	VS na(N);
	VI ta(N), pi(N), gi(N);
	REP(i, N) {
		cin>>n>>na[i];
		VS pb(n);
		REP(ii, n) {
			cin>>pb[ii];
		}
		//sort(ALL(pb));
		//pb.erase(unique(ALL(pb)), pb.end());
		REP(j, pb.size()) {
			string s(pb[j]);
			VI hi(10);
			int pizza=1;
			int last=-1;
			REP(k, 8) {
				if(k==2||k==5) continue;
				int cur = s[k]-'0';
				hi[cur]++;
				if(last!=-1 && last<=cur) pizza=0;
				last=cur;
			}
			//cout<<hi<<endl;
			int taxi=0;
			REP(k, 10) if(hi[k]==6) taxi=1;
			if(taxi) ta[i]++;
			if(pizza) pi[i]++;
			if(!taxi && !pizza) gi[i]++;
		}
	}
	int mt=-1, mp=-1, mg=-1;
	REP(i, N) {
		mt=max(mt, ta[i]);
		mp=max(mp, pi[i]);
		mg=max(mg, gi[i]);
	}
	
	int first=0;
	cout<<"If you want to call a taxi, you should call: ";
	first=1;
	REP(i, N) {
		if(mt==ta[i]) {
			if(!first) cout<<", ";
			cout<<na[i];
			first=0;
		}
	}
	cout<<"."<<endl;
	cout<<"If you want to order a pizza, you should call: ";
	first=1;
	REP(i, N) {
		if(mp==pi[i]) {
			if(!first) cout<<", ";
			cout<<na[i];
			first=0;
		}
	}
	cout<<"."<<endl;
	cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
	first=1;
	REP(i, N) {
		if(mg==gi[i]) {
			if(!first) cout<<", ";
			cout<<na[i];
			first=0;
		}
	}
	cout<<"."<<endl;
	
	return 0;
}
