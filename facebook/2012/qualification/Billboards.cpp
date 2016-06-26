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



int main() {
	int T;
	cin>>T;
	REP(ttt, T) {
		int W, H;
		vector<string> vs;
		string s;
		cin>>W>>H;
		cin.ignore();
		getline(cin, s);
		stringstream ss(s);
		while(ss>>s) {
			vs.PB(s);
		}
		//REP(i, vs.size()) cout<<vs[i]<<endl;
		
		int fs = 2000;
		for(;fs>0;fs--) {
			int h=1,x=0,lfed=1;
			int ok=1;
			REP(i, vs.size()) {
				int si=vs[i].size()*fs;
				if(x+(1-lfed)*fs+si <= W) {
					x+=(1-lfed)*fs+si;
					lfed=0;
				} else if(si<=W) {
					x=si;
					h++;
					lfed=1;
				} else {
					ok=0;
					break;
				}
				//cout<<vs[i]<<" "<<x<<" "<<h<<endl;
			}
			//cout<<W<<" "<<H<<" "<<fs<<" "<<h<<endl;
			if(ok && h*fs<=H) break;
		}
		
		cout<<"Case #"<<ttt+1<<": "<<fs<<endl;
//break;
	}
	return 0;
}


