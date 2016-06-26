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

string ref(int a1, int a2, int a3, int a4) {
	for(ll i=0;i<1000;i++) {
		stringstream ss;
		ss<<i;
		string s(ss.str());
		//cout<<s<<endl;
		int c1=0, c2=0, c3=0, c4=0;
		REP(j, s.size()) {
			if(s[j]=='4') c1++;
			if(s[j]=='7') c2++;
		}
		REP(j, s.size()-1) {
			if(s[j]=='4'&&s[j+1]=='7') c3++;
			if(s[j]=='7'&&s[j+1]=='4') c4++;
		}
		if(a1==c1 && a2==c2 && a3==c3 && a4==c4) {
			return s;
		}
	}
	return "-1";
}

string f(int a1, int a2, int a3, int a4) {
	stringstream ss;
	if(abs(a3-a4)>1) return "-1";
	if(a3==a4) {
		if(a1-(a3+1)<0 && a1-a3>=0 ) {
			a1-=a3;
			a2-=a3+1;
			if(a1<0 || a2<0) return "-1";
			REP(i, a3) {
				ss<<7;
				ss<<4;
				if(i==0) REP(j, a1) ss<<4;
			}
			ss<<7;
			REP(j, a2) ss<<7;
		} else {
			a1-=a3+1;
			a2-=a3;
			if(a1<0 || a2<0) return "-1";
			REP(i, a3) {
				ss<<4;
				if(i==0) REP(j, a1) ss<<4;
				ss<<7;
				if(i==a3-1) REP(j, a2) ss<<7;
			}
			ss<<4;
		}
	}
	if(a3>a4) {
		a1-=a3;
		a2-=a3;
		if(a1<0 || a2<0) return "-1";
		REP(i, a3) {
			ss<<4;
			if(i==0) REP(j, a1) ss<<4;
			ss<<7;
			if(i==a3-1) REP(j, a2) ss<<7;
		}
	}
	if(a3<a4) {
		a1-=a4;
		a2-=a4;
		if(a1<0 || a2<0) return "-1";
		REP(i, a4) {
			ss<<7;
			if(i==a4-1) REP(j, a2) ss<<7;
			ss<<4;
			if(i==0) REP(j, a1) ss<<4;
		}
	}
	return ss.str();
}

int main() {
	int a1, a2, a3, a4;
	cin>>a1>>a2>>a3>>a4;
	//cout<<ref(a1, a2, a3, a4)<<endl;
	cout<<f(a1, a2, a3, a4)<<endl;
	//int LIM=10;
	//for(int t1=1;t1<LIM;t1++)
	//for(int t2=1;t2<LIM;t2++)
	//for(int t3=1;t3<LIM;t3++)
	//for(int t4=1;t4<LIM;t4++) {
	//	string s0 = ref(t1, t2, t3, t4);
	//	string s1 = f(t1, t2, t3, t4);
	//	if(s0!=s1) cout<<"!!!!!!!!!!!!!"<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl<<s0<<endl<<s1<<endl;
	//	cout<<"OK "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl;
	//}
	return 0;
}
