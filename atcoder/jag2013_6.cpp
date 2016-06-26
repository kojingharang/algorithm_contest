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
#include <cstdio>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

int idx;
string s, flg;


int expr();

int term() {
//	cout<<"term "<<s.substr(idx)<<endl;
	while(idx<s.size() && s[idx]==' ') idx++;
	if(idx>=s.size()) assert(!"term must continue");
	if(isdigit(s[idx])) {
		ll v=0;
		while(idx<s.size() && isdigit(s[idx])) {
			v = v*10 + (s[idx]-'0');
			idx++;
		}
		return v;
	}
	if(s[idx]=='S') {
		idx++;
		while(idx<s.size() && s[idx]==' ') idx++;
		if(idx>=s.size()) assert(!"term must continue");
		idx++;
		ll v = expr();
		idx++;
		v = (v * v) % MOD;
		return v;
	}
	return -1;
}

/*
expr ::= term [>>term +]
term ::= number | S< expr >
*/
int expr() {
//	cout<<"expr "<<idx<<" "<<s.substr(idx, 10)<<endl;
	ll v = term();
	while(1) {
		while(idx<s.size() && s[idx]==' ') idx++;
		if(idx>=s.size()) break;
		if(s[idx]=='>') {
			if(idx+1<s.size() && s[idx+1]=='>' && flg[idx]=='!') {
				idx+=2;
				ll shi = term();
				if(shi>50) v=0;
				else REP(i, shi) v >>= 1;
			} else break;
		}
	}
	return v;
}

void mark(int& i) {
	while(1) {
		if(s[i]=='>') {
			i--;
			flg[i]='!';
			break;
		}
		if(s[i]=='<') break;
		i--;
	}
}

char buf[2000100];
int main() {
	ios::sync_with_stdio(false);
	while(1) {
		gets(buf);
		s=string(buf);
		
		if(s=="#") return 0;
		flg=s;
		for(int i=s.size()-1;i>=1;i--) {
			if(isdigit(s[i])) {
				if(!isdigit(s[i-1])) {
					i--;
					mark(i);
				}
			} else if(s[i]=='S') {
				mark(i);
			}
		}
		idx=0;
		cout<<expr()<<endl;
	}
	
	return 0;
}
