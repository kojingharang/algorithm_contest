#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <ctype.h>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
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
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

#define MOD 1000000007LL
#define INF (1LL<<60)

// type caml 0
// type _    1
// err       2
// empty     3
int word(const string& s, int& pos, string& Caml, string& Us, int type) {
	int N = s.size();
	if(pos==N) return 3;
	if(type==0) {
		int first = 1;
		for(;pos<N;pos++) {
			if(first) {
				if(!('A' <= s[pos] && s[pos] <= 'Z')) return 2;
				Caml += toupper(s[pos]);
				Us += tolower(s[pos]);
			} else {
				if(!(  ('0' <= s[pos] && s[pos] <= '9') || ('a' <= s[pos] && s[pos] <= 'z') )) return type;
				Caml += s[pos];
				Us += s[pos];
			}
			first = 0;
		}
	}
	if(type==1) {
		int first = 1;
		if(s[pos]=='_') return 2;
		for(;pos<N;pos++) {
			if(s[pos]=='_') return type;
			if(first) {
				if(!(  ('a' <= s[pos] && s[pos] <= 'z') )) return 2;
				Caml += toupper(s[pos]);
				Us += tolower(s[pos]);
			} else {
				if(!(  ('0' <= s[pos] && s[pos] <= '9') || ('a' <= s[pos] && s[pos] <= 'z') )) return 2;
				Caml += s[pos];
				Us += s[pos];
			}
			first = 0;
		}
	}
	return type;
}

int main() {
	string s;
	while(cin>>s) {
		int N = s.size();
		int pos=0;
		int hd = 0;
		REP(i, N) {
			if(s[i]=='_') {
				hd++;
				pos++;
			} else break;
		}
		int tl = 0;
		for(int i=N-1;i>=pos;i--) {
			if(s[i]=='_') {
				tl++;
				N--;
			} else break;
		}
		
		string Caml, Us;
		int type = -1;
		
		// first word
		{
			int first = 1;
			while(pos<N && s[pos]!='_') {
				int ok=0;
				//cout<<"C "<<s[pos]<<endl;
				if(first && 'a' <= s[pos] && s[pos] <= 'z') ok=1;
				if(!first) ok=1;
				if(!first && !(('0' <= s[pos] && s[pos] <= '9') || ('a' <= s[pos] && s[pos] <= 'z') )) break;
				if(!ok) {
					type=2;
					//cout<<"%%"<<endl;
					break;
				}
				Caml += s[pos];
				Us += s[pos];
				pos++;
				first=0;
			}
		}
		if(pos==N) type=0;
		if(pos<N && type!=2) {
			if('A' <= s[pos] && s[pos] <= 'Z') type=0;
			if(s[pos]=='_') type=1;
			
			//cout<<"type "<<type<<endl;
			
			while(pos<N) {
				if(type==1) {
					if(s[pos++]!='_') {
						type=2;
						//cout<<"!!"<<endl;
						break;
					}
				}
				Us += "_";
				
				int ret = word(s, pos, Caml, Us, type);
				if(ret==3) {
					type=2;
					//cout<<"##"<<endl;
					break;
				}
				if(ret==2) {
					type=ret;
					//cout<<"$$"<<endl;
					break;
				}
				if(ret!=type) {type=2;break;}
			}
		}
		REP(i, hd) {
			Caml = "_"+Caml;
			Us = "_"+Us;
		}
		REP(i, tl) {
			Caml = Caml+"_";
			Us = Us+"_";
		}
		//cout<<"------"<<endl;
		//cout<<Caml<<endl;
		//cout<<Us<<endl;
		//cout<<s<<endl;
		
		if(type==0) cout<<Us<<endl;
		if(type==1) cout<<Caml<<endl;
		if(type==2) cout<<s<<endl;
	}
	
	return 0;
}
