#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>
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
string YN(bool v) { return v ? "Yes":"No"; }
void uniq(VI& es) { sort(ALL(es)); es.erase(unique(ALL(es)), es.end()); }

#define INF (1LL<<60)

string ref(string s) {
	VI used(26);
	REP(i, s.size()) used[s[i]-'a']++;
	string ans;
	REP(i, 26) if(!used[i]) return s+string(1, i+'a');
	string t=s;
	if(s=="zyxwvutsrqponmlkjihgfedcba") return "-1";
	next_permutation(ALL(t));
	REP(i, s.size()) if(t[i]!=s[i]) {t=t.substr(0, i+1);break;}
	return t;
}
string solve(string s) {
	VI used(26);
	REP(i, s.size()) used[s[i]-'a']++;
	string ans;
	REP(i, 26) if(!used[i]) {ans=s+string(1, i+'a');break;}
	if(ans=="") REPR(i, s.size()) {
		VI used(26);
		REP(j, i) used[s[j]-'a']++;
//			DD(i);DD(used);
		ll j=s[i]-'a';
		RANGE(k, j+1, 26) if(!used[k]) {ans=s.substr(0, i)+string(1, k+'a');break;}
		if(ans!="") break;
	}
	if(ans=="") ans="-1";
	return ans;
}

int main() {
	if(0){
		string s(26, ' ');
		REP(i, 26) s[i]=i+'a';
		do{
			string a=ref(s);
			string b=solve(s);
			if(a!=b) {
				DD(s);
				DD(a);
				DD(b);
				return 0;
			}
		}while(next_permutation(ALL(s)));
	}
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	while(cin>>s) {
		string ans=solve(s);
		cout<<ans<<endl;
	}
	
	return 0;
}
