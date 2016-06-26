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
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
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
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


bool isNum(const string& s, int& idx, int limit, int& out) {
	if(idx>=limit) return false;
	if(!isdigit(s[idx])) return false;
	out=0;
	int read=0;
	while(idx<limit && isdigit(s[idx])) {
		out=out*10+(s[idx]-'0');
		idx++;
		read++;
	}
	if(out==0 && read>1) return false;
	return true;
}

string realAns;
bool valid2(const string& s, int limit, bool final=false) {
	int idx=0;
	int v;
	if(idx>=limit) return !final;
	if(!isNum(s, idx, limit, v)) return false;
	if(!(1<=v&&v<=200)) return false;
	if(idx>=limit) return !final;
	if(s[idx++]!=0x0a) return false;
	int loop = v;
	stringstream ans;
	REP(i, loop) {
		int a, b;
		if(idx>=limit) return !final;
		if(!isNum(s, idx, limit, v)) return false;
		if(!(1<=v&&v<=10)) return false;
		if(idx>=limit) return !final;
		if(s[idx++]!=' ') return false;
		a=v;
		
		if(idx>=limit) return !final;
		if(!isNum(s, idx, limit, v)) return false;
		if(!(1<=v&&v<=10)) return false;
		if(idx>=limit) return !final;
		if(s[idx++]!=0x0a) return false;
		b=v;
		ans<<"ans.PB("<<(a^b)<<");";
	}
	if(final && idx!=limit) return false;
	if(final) realAns = ans.str();
	return true;
}


string src, validAns;
int cur[128];
int L=128;
void dfs(int idx) {
	if(validAns.size()) return;
	if(idx==L) {
		string ss=src;
		REP(j, ss.size()) ss[j]^=cur[j%L];
		if(valid2(ss, ss.size(), true)) {
			cout<<"//Found valid ans "<<endl;
			validAns=ss;
		}
		return;
	}
	REP(x, 256) {
		cur[idx]=x;
		bool go=true;
		{
			string ss=src;
			REP(j, ss.size()) ss[j]^=cur[j%L];
			if(!valid2(ss, idx+1)) go=false;
		}
		if(go) dfs(idx+1);
	}
}

int main(int argc, char**argv) {
	//ios::sync_with_stdio(false);
	int c;
	FILE* fin = fopen(argv[1], "rb");
	while((c=fgetc(fin))!=EOF) {
		src.PB(c);
	}
	dfs(0);
	
	cout<<realAns<<endl;
	
	return 0;
}
