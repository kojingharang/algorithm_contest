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
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

int ref(int A, int B) {
	stringstream ss;
	ss<<B;
	string BS(ss.str());
	//cout<<BS<<endl;
	for(int i=A+1;;i++) {
		string s;
		for(int j=i;j>0;j/=10) if(j%10==4 || j%10==7) s=string(1, '0'+j%10)+s;
		if(BS==s) return i;
	}
	return 0;
}

int f(int A, int B) {
	for(int i=A+1;;i++) {
		int k=i;
		int ok=1;
		for(int j=B;j>0;j/=10) {
			int lok=0;
			for(;k>0;k/=10) {
				if(k%10==j%10) {lok=1;k/=10;break;}
			}
			if(!lok) ok=0;
		}
		if(ok) {
			return i;
		}
	}
	return 0;
}

int main() {
	//int A, B;
	//cin>>A>>B;
	for(int B=4;B<5;B++) {
		int ok=1;
		for(int j=B;j>0;j/=10) if(j%10!=4&&j%10!=7) ok=0;
		if(!ok) continue;
		int rans=ref(740, B);
		int ans=f(740, B);
		if(rans!=ans) cout<<B<<" "<<rans<<" "<<ans<<endl;
		//cout<<B<<" OK"<<endl;
	}
	return 0;
}
