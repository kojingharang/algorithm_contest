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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

struct Node {
	map<char, Node> nodes;
};

int cnt;
void add(Node& root, string s) {
	if(s.size()==0) return;
	if(!root.nodes.count(s[0])) {
		cnt++;root.nodes[s[0]] = Node();
	}
	add(root.nodes[s[0]], s.substr(1));
}


/*

*/
int main() {
	int test_cases;
	cin>>test_cases;
	ll M,N;
	string s;
	REP(ttt, test_cases) {
		cin>>M>>N;
		vector<string> w(M);
//		Node root;
//		cnt=1;
		string du;getline(cin, du);
		REP(i, M) {
			getline(cin, w[i]);
//			cout<<"start "<<w[i]<<endl;
//			add(root, w[i]);
		}
//		sort(ALL(w));
		VI as(M);
		VI co(N);
		ll worst=0, wc=0;
		REP(bit, 1<<(2*M)) {
			int ok=1;
			REP(i, M) as[i]=(bit>>(i*2))&3;
			REP(i, M) if(as[i]>=N) {ok=0;break;}
			if(!ok)continue;
			REP(i, N)co[i]=0;
			REP(i, M) co[as[i]]++;
			REP(i, N) if(co[i]==0) ok=0;
			if(!ok)continue;
			ll lans=0;
//			cout<<"BIT "<<as<<endl;
//			vector<vector<string> > all;
			REP(i, N) {
				cnt=1;
				Node root;
//				vector<string> one;
				REP(j, M) {
					if(as[j]==i) {
						add(root, w[j]);
//						one.PB(w[j]);
//						cout<<"Add "<<i<<" "<<w[j]<<endl;
					}
				}
//				all.PB(one);
				lans += cnt;
			}
//			cout<<all<<endl;
//			cout<<"lans "<<lans<<endl;
			if(worst == lans) wc++;
			if(worst < lans) worst=lans,wc=1;
		}
		cout<<"Case #"<<ttt+1<<": "<<worst<<" "<<wc<<endl;
//		return 0;
	}
	return 0;
}



