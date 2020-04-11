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
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cassert>
#include <fstream>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define VVVI vector<vector<vector<ll>>>
#define VVVVI vector<vector<vector<vector<ll>>>>
#define REP(i,n) for(ll i=0,_n=(n);(i)<(ll)_n;++i)
#define REPR(i,n) for(ll i=(ll)(n)-1;0<=(i);--i)
#define RANGE(i,a,b) for(ll i=(ll)a,_b=(ll)(b);(i)<_b;++i)
#define RANGER(i,a,b) for(ll i=(ll)(b)-1,_a=(ll)(a);(_a)<=i;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
#define FI first
#define SE second
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}

#define MOD 1000000007LL
#define INF (1LL<<60)

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int test_cases;
	ll F;
	string s;
	cin>>test_cases>>F;
//	ofstream ofs("log.txt");
	auto& ofs = cerr;
	
	ofs<<test_cases<<" "<<F<<endl;
//	return 0;
	REP(ttt, test_cases) {
		ofs<<"TC "<<ttt<<endl;
		vector<string> ss(119, string(5, ' '));
		map<char, ll> co;
		REP(i, 119) {
			int q = i*5+0+1;
			assert(1<=q && q<=595);
			cout<<q<<endl;
			cin>>s;
			ss[i][0]=s[0];
			co[s[0]]++;
//			ofs<<"got "<<s<<endl;
			assert(s!="N");
		}
		char c0=0;
		for(auto kv : co) if(kv.second==23) c0=kv.first;
		co.clear();
		REP(i, ss.size()) if(ss[i][0]==c0) {
			int q = i*5+1+1;
			assert(1<=q && q<=595);
			cout<<q<<endl;
			cin>>s;
			co[s[0]]++;
			ss[i][1]=s[0];
		}
		char c1=0;
		for(auto kv : co) if(kv.second==5) c1=kv.first;
		co.clear();
		REP(i, ss.size()) if(ss[i][0]==c0 && ss[i][1]==c1) {
			int q = i*5+2+1;
			assert(1<=q && q<=595);
			cout<<q<<endl;
			cin>>s;
			co[s[0]]++;
			ss[i][2]=s[0];
		}
		char c2=0;
		for(auto kv : co) if(kv.second==1) c2=kv.first;
		co.clear();
		REP(i, ss.size()) if(ss[i][0]==c0 && ss[i][1]==c1 && ss[i][2]==c2) {
			int q = i*5+3+1;
			assert(1<=q && q<=595);
			cout<<q<<endl;
			cin>>s;
			VI used(5);
			used[c0-'A']=1;
			used[c1-'A']=1;
			used[c2-'A']=1;
			used[s[0]-'A']=1;
			string ans(5, ' ');
			ans[0]=c0;
			ans[1]=c1;
			ans[2]=c2;
			ans[4]=s[0];
			REP(j, 5) if(!used[j]) ans[3]='A'+j;
			cout<<ans<<endl;
			ofs<<ans<<endl;
			break;
		}
		cin>>s;
		ofs<<"GOT "<<s<<endl;
		assert(s=="Y");
//		return 0;
	}
	return 0;
}



