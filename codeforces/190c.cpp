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

vector<string> S;
int err=0;
string ans = "";
int f(int i) {
	if(err) return S.size();
	if(i>=S.size()) {err=1;return -1;}
	
	//cout<<i<<endl;
	if(S[i]=="int") {ans+="int";return i+1;}
	if(S[i]=="pair") {
		ans += "pair<";
		int a = f(i+1);
		if(err) return -1;
		ans +=",";
		int b = f(a);
		if(err) return -1;
		ans += ">";
		return b;
	}
	return 0;
}

int main() {
	int N;
	cin>>N;
	string s;
	int n=0;
	while(cin>>s) {
		S.PB(s);
		if(s=="int") n++;
	}
	//cout<<S<<endl;
	if(n!=N) {cout<<"Error occurred"<<endl;return 0;}
	int ret = f(0);
	//cout<<ret<<" "<<S.size()<<endl;
	if(err || ret!=S.size()) {cout<<"Error occurred"<<endl;return 0;}
	
	cout<<ans<<endl;
	
	return 0;
}
