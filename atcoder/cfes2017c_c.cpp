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
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

#define MOD 1000000007LL
#define INF (1LL<<60)

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	while(cin>>s) {
		string sx;
		REP(i, s.size()) {
			if(s[i]!='x') sx.PB(s[i]);
		}
		bool ok = 1;
		ll ans = -1;
		REP(i, sx.size()/2) if(sx[i]!=sx[sx.size()-1-i]) ok=0;
//		DD(sx);
		if(ok) {
			bool allX = 1;
			REP(i, s.size()) if(s[i]!='x') allX=0;

			ans = 0;
			if(!allX) {
				ll l = -1, r = -1;
				{
					ll cnt=0;
					REP(i, s.size()) {
						if(s[i]!='x') cnt++;
						if(cnt-1==(sx.size()-1)/2 && l==-1) {
							l = i;
						}
						if(cnt-1==sx.size()-1-(sx.size()-1)/2 && r==-1) {
							r = i;
						}
					}
				}
	//			DD(l);
	//			DD(r);
				while(l!=0 && r!=s.size()-1) {
					// s[l] .. s[r]
					ll lx = 0, rx = 0;
					l--;
					while(l>0 && s[l]=='x') {
						lx++;
						l--;
					}
					r++;
					while(r<s.size()-1 && s[r]=='x') {
						rx++;
						r++;
					}
	//				DD(l);
	//				DD(r);
	//				DD(lx);
	//				DD(rx);
					ans += abs(lx-rx);
				}
				ll lx = 0, rx = 0;
				l--;
				while(l>=0 && s[l]=='x') lx++,l--;
				r++;
				while(r<s.size() && s[r]=='x') rx++,r++;
				ans += abs(lx-rx);
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
