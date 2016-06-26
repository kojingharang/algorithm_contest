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

int main() {
	vector<PII> lt; // (x, y)[]
	vector<vector<string> > pat;
	{
		vector<string> s;
		s.PB(".......");
		s.PB("...o...");
		s.PB("..o.o..");
		s.PB(".o...o.");
		s.PB(".ooooo.");
		s.PB(".o...o.");
		s.PB(".......");
		pat.PB(s);
		lt.PB(MP(3, 1));
		REP(i, 3) {
			PII ilt = lt[lt.size()-1];
			lt.PB(MP(ilt.second, 6-ilt.first));
			vector<string> ss(7, string(7, '.'));
			REP(y, 7) REP(x, 7) ss[y][x] = s[x][6-y];
			pat.PB(ss);
			s=ss;
		}
	}
	
	{
		vector<string> s;
		s.PB(".......");
		s.PB(".oooo..");
		s.PB(".o...o.");
		s.PB(".oooo..");
		s.PB(".o...o.");
		s.PB(".oooo..");
		s.PB(".......");
		pat.PB(s);
		lt.PB(MP(1, 1));
		REP(i, 3) {
			PII ilt = lt[lt.size()-1];
			lt.PB(MP(ilt.second, 6-ilt.first));
			vector<string> ss(7, string(7, '.'));
			REP(y, 7) REP(x, 7) ss[y][x] = s[x][6-y];
			pat.PB(ss);
			//cout<<lt[lt.size()-1]<<endl;
			//cout<<ss<<endl;
			s=ss;
		}
	}
	
	{
		vector<string> s;
		s.PB(".......");
		s.PB("..ooo..");
		s.PB(".o...o.");
		s.PB(".o.....");
		s.PB(".o...o.");
		s.PB("..ooo..");
		s.PB(".......");
		pat.PB(s);
		lt.PB(MP(2, 1));
		REP(i, 3) {
			PII ilt = lt[lt.size()-1];
			lt.PB(MP(ilt.second, 6-ilt.first));
			vector<string> ss(7, string(7, '.'));
			REP(y, 7) REP(x, 7) ss[y][x] = s[x][6-y];
			pat.PB(ss);
			s=ss;
		}
	}
	
	ll H, W;
	while(cin>>H>>W) {
		vector<string> w(H);
		string dum;
		getline(cin, dum);
		REP(i, H) getline(cin, w[i]);
		
		VI ans(3);
		REP(y, H) REP(x, W) {
			if(w[y][x]=='o') {
				int size=1;
				while(1) {
					int ok=1;
					REP(xx, size) REP(yy, size) if(w[y+yy][x+xx]!='o') {ok=0;break;}
					if(!ok)break;
					size++;
				}
				size--;
				//cout<<x<<" "<<y<<" "<<size<<endl;
				
				REP(pi, pat.size()) {
					int ox = lt[pi].first;
					int oy = lt[pi].second;
					int ok=1;
					//cout<<lt[pi]<<endl;
					
					if(y+(0-oy)*size < 0 || x+(0-ox)*size < 0 || y+(7-oy)*size > H || x+(7-ox)*size > W) ok=0;
					if(ok) REP(yy, 7) REP(xx, 7) {
						char ref = pat[pi][yy][xx];
						REP(yyy, size) {
							REP(xxx, size) {
								if(w[y+(yy-oy)*size+yyy][x+(xx-ox)*size+xxx]!=ref) {ok=0;break;}
							}
							if(!ok) break;
						}
						if(!ok) break;
					}
					if(ok) {
						ans[pi/4]++;
						REP(xx, 7) REP(yy, 7) REP(yyy, size) REP(xxx, size) w[y+(yy-oy)*size+yyy][x+(xx-ox)*size+xxx]='.';
						break;
					}
				}
			}
		}
		
		cout<<ans<<endl;
		//break;
	}
	
	return 0;
}
