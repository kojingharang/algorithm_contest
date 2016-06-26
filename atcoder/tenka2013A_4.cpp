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

int main() {
	//ios::sync_with_stdio(false);
	ll B, L, N;
	while(cin>>B>>L>>N) {
		string s;
		cin>>s;
		if(!(L<=100 && N<=100)) {
			cout<<"NG"<<endl;
			continue;
		}
		string ss;
		int _num=0;
		REP(i, s.size()) {
			if(s[i]=='(') {
				if(_num) ss.PB(':');
				_num=0;
			} else if(s[i]==')') {
				if(_num) ss.PB(':');
				_num=0;
			} else if('0'<=s[i] && s[i]<='9') {
				_num=1;
			} else {
				if(_num) ss.PB(':');
				_num=0;
			}
			ss.PB(s[i]);
		}
		s=ss;
//		cout<<"SRC "<<ss<<endl;
		deque<string> q;
		q.push_back("");
		int num=0;
		string S;
		int ng=0;
		REP(i, s.size()) {
			if(ng) break;
//			cout<<q.size()<<" "<<q<<" | "<<S<<endl;
//			cout<<"PROC: "<<s[i]<<endl;
			if(s[i]=='(') {
				q.PB("");
			} else if(s[i]==')') {
			} else if('0'<=s[i] && s[i]<='9') {
				num = num*10+(s[i]-'0');
			} else if(s[i]==':') {
				if(num) {
					string la = q.back();
					q.pop_back();
					REP(j, num) {if(S.size()>1000) {ng=1; break;} q.back() += la; }
					num=0;
				}
			} else {
				q.back()+=s[i];
			}
		}
		if(num) {
			string la = q.back();
			q.pop_back();
			REP(j, num) {if(S.size()>1000) {ng=1; break;} q.back() += la; }
			num=0;
		}
		S=q.back();
//		cout<<"END "<<S<<endl;
		string ans;
		if(ng) {cout<<"NG"<<endl;continue;}
		REP(i, L) ans += S[(B+i+S.size())%S.size()];
		cout<<ans<<endl;
	}
	
	return 0;
}
