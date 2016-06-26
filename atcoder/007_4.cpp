#include <vector>
#include <map>
#include <set>
#include <stack>
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
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

int validate(const string& s, int idx, int A0, int A1) {
	//cout<<"val "<<idx<<" "<<A0<<" "<<A1<<endl;
	if(A0>=A1) return 0;
	int dif = A1-A0;
	int AN = A1+dif;
	int pos = idx;
	REP(loop, 10) {
		stringstream w;
		w<<AN;
		string ww(w.str());
		//cout<<"AN "<<AN<<"  "<<ww<<"  "<<s[pos]<<endl;
		REP(i, ww.size()) {
			if(pos+i>=s.size()) return 1;
			if(ww[i]!=s[pos+i]) return 0;
		}
		pos += ww.size();
		AN += dif;
	}
	return 0;
}

int Pow(int a, int b) {
	int v = 1;
	REP(i, b) v*=a;
	return v;
}

int Digits(int v) {
	int r = 0;
	while(v) {
		v/=10;
		r++;
	}
	return r;
}

PII f(const string& s, int idx, int A0) {
	//cout<<"f "<<idx<<" "<<A0<<endl;
	if(s.size() <= idx) return MP(A0, 1);
	if(s[idx]=='0') return MP(INF, INF);
	PII ans = MP(INF, INF);
	RANGE(di, Digits(A0), s.size()-idx+1) {
		int A1 = 0;
		REP(i, di) {
			A1 = A1 * 10 + (s[idx+i]-'0');
		}
		int ok = validate(s, idx+di, A0, A1);
		//cout<<"                  --> "<<(ok?"OK" : "NG")<<endl;
		if(ok) {
			ans = min(ans, MP((ll)A0, (ll)A1-A0));
		}
	}
	int v = 0;
	RANGE(i, idx, s.size()) {
		v=v*10+(s[idx]-'0');
	}
	if(Digits(A0) > Digits(v)) {
		while(Digits(A0) > Digits(v)) {
			v*=10;
		}
		ans = min(ans, MP((ll)A0, max(1LL, (ll)v-A0)));
	}
	return ans;
}

int main() {
	string s;
	while(cin>>s) {
		int N=s.size();
		if(N>6) continue;
		PII ans = MP(INF, INF);
		RANGE(digit, 1, N+6) {
			RANGE(start, 1-digit, 1) {
				//cout<<"di "<<digit<<" "<<start<<endl;
				if(start<0) {
					RANGE(yet, Pow(10, -start-1), Pow(10, -start)) {
						int A0 = yet;
						REP(i, start+digit) {
							A0 = A0 * 10 + (s[i]-'0');
						}
						ans = min(ans, f(s, start+digit, A0));
					}
				} else {
					int A0 = 0;
					if(s[0]=='0') continue;
					REP(i, start+digit) {
						A0 = A0 * 10 + (s[i]-'0');
					}
					ans = min(ans, f(s, start+digit, A0));
				}
			}
			if(ans.first < INF) break;
		}
		
		cout<<ans.first<<" "<<ans.second<<endl;
		//return 0;
	}
	
	return 0;
}
