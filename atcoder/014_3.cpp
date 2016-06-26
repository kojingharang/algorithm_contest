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

int naive(ll N, string s) {
	int ans = 10000;
	REP(bit, 1<<N) {
		string w;
		REP(i, N) {
			if((bit>>i)&1) w+=s[i]; else w=s[i]+w;
			if(w.size()>=2 && w[0]==w[1]) w=w.substr(2, w.size()-2);
			if(w.size()>=2 && w[w.size()-1]==w[w.size()-2]) w=w.substr(0, w.size()-2);
		}
		ans = min(ans, (int)w.size());
	}
	return ans;
}

int f(ll N, string s) {
	string w;
	REP(i, N) {
		if(w.size()==0) {
			w+=s[i];
			continue;
		}
		if(w[0]==s[i]) w=s[i]+w;
		else if(w[w.size()-1]==s[i]) w+=s[i];
		else if(i<N-1) {
			if(w[0]==s[i+1]) w+=s[i];
			else if(w[w.size()-1]==s[i+1]) w=s[i]+w;
			else w+=s[i];
		} else w+=s[i];
		if(w.size()>=2 && w[0]==w[1]) w=w.substr(2, w.size()-2);
		if(w.size()>=2 && w[w.size()-1]==w[w.size()-2]) w=w.substr(0, w.size()-2);
	}
	return w.size();
}

int rnd(int a, int b) {
	double r01 = (double)rand()/RAND_MAX;
	return (int)(r01*(b-a)+a);
}

int main() {
	//ios::sync_with_stdio(false);
	ll N;
	
	//string tb("RGB");
	//REP(loop, 1000) {
	//	int N = rnd(1, 15);
	//	string s;
	//	REP(i, N) s+=tb[rnd(0, 3)];
	//	int ref = naive(N, s);
	//	int ans = f(N, s);
	//	cout<<"try "<<s<<" : "<<ref<<" "<<ans<<endl;
	//	if(ref!=ans) {
	//		cout<<"!!! "<<s<<" : "<<ref<<" "<<ans<<endl;
	//	}
	//}
	
	while(cin>>N) {
		string s;
		cin>>s;
		//int ans = naive(N, s);
		int ans = f(N, s);
		cout<<ans<<endl;
	}
	
	return 0;
}
