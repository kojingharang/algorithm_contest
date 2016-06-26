#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << "\n"; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

int paint(vector<string>& w) {
	REP(i, 8) REP(j, 8) {
		if(w[i][j]=='Q') {
			REP(y, 8) REP(x, 8) if(!(i==y&&j==x) && w[y][x]=='.' && (i==y || j==x || abs(i-y)==abs(j-x))) w[y][x]='X';
		}
	}
	return 0;
}
int unpaint(vector<string>& w) {
	REP(i, 8) REP(j, 8) {
		if(w[i][j]=='X') w[i][j]='.';
	}
	return 0;
}
int validate(vector<string>& w) {
	REP(i, 8) REP(j, 8) {
		if(w[i][j]=='Q') {
			REP(y, 8) REP(x, 8) if(!(i==y&&j==x) && w[y][x]=='Q' && (i==y || j==x || abs(i-y)==abs(j-x))) return 0;
		}
	}
	return 1;
}
int f(vector<string>& w, int rest) {
	if(rest==0) return 1;
	REP(y, 8) REP(x, 8) {
		paint(w);
		if(w[y][x]=='.') {
			w[y][x]='Q';
			paint(w);
			//cout<<x<<" "<<y<<" "<<rest<<endl;
			//cout<<w<<endl;
			if(f(w, rest-1)) return 1;
			w[y][x]='.';
			unpaint(w);
			//cout<<w<<endl;
		}
	}
	//cout<<"NO"<<endl;
	return 0;
}

int main() {
	vector<string> w(8);
	REP(i, 8) cin>>w[i];
	//REP(y, 8) REP(x, 8) {
	//	
	//}
	//cout<<w<<endl;
	if(!validate(w)) {
		cout<<"No Answer"<<endl;
		return 0;
	}
	if(f(w, 5)) {
		unpaint(w);
		if(!validate(w)) cout<<"ERROR"<<endl;
		cout<<w;
	} else {
		cout<<"No Answer"<<endl;
	}
}

