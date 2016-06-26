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
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

VVI tab;
VVI w;
VVI origw;
VI ans;
int done;

int check() {
	int N = tab.size();
	VVI tmp(tab);
	REP(loop, 2) {
		REP(y, N) REP(x, N-1) if(tmp[y][x]>=tmp[y][x+1]) return 0;
		REP(y, N) RANGE(x, y+1, N) swap(tmp[y][x], tmp[x][y]);
	}
	return 1;
}


void f(int N, int th) {
	if(done) return;
//	cout<<"--------- f "<<th<<endl;
	sort(ALL(w), [&](const VI& a, const VI& b) {
		return a[th]<b[th];
	});
//	cout<<"w "<<w<<endl;
	VVI put;
	put.PB(w[0]);
	if(w.size()>1 && put[0][th]==w[1][th]) put.PB(w[1]);

//	DD(put);

	REP(loop, 2) {
//		DD(loop);
//		cout<<"before"<<endl;
//		REP(i, N) cout<<tab[i]<<endl;

		bool ok=true;
		VVI oldtab(tab);
		VVI oldw(w);
		{
			int aru=0;
			REP(x, N) {
				ll y=th;
				if(tab[y][x]==0 || (tab[y][x]==put[0][x])) {
					tab[y][x] = put[0][x];

					RANGE(z, 0, w.size()) {
						int lok = 1;
						REP(y, th+1) if(tab[y][x]!=w[z][y]) {lok=0;break;}
						if(lok) {aru++;break;}
					}
				} else {
					ok=false;
					break;
				}
			}
			if(aru<N-1) ok=false;
		}
		if(ok && put.size()>1) {
			int aru=0;
			REP(y, N) {
				ll x=th;
				if(tab[y][x]==0 || (tab[y][x]==put[1][y])) {
					tab[y][x] = put[1][y];

					RANGE(z, 0, w.size()) {
						int lok = 1;
						REP(x, th+1) lok = lok && tab[y][x]==w[z][x];
						if(lok) {aru++;break;}
					}
				} else {
					ok=false;
				}
			}
			if(aru<N-1) ok=false;
		}
		if(ok) {
			if(th==N-1) {
				assert(check());
//				cout<<"found"<<endl;
//				REP(i, N) cout<<tab[i]<<endl;

				VVI ref;
				REP(i, N) ref.PB(tab[i]);
				REP(y, N) RANGE(x, y+1, N) swap(tab[y][x], tab[x][y]);
				REP(i, N) ref.PB(tab[i]);
//				DD(ref);
				VI seen(origw.size());
				int ok=0;
				REP(i, 2*N) {
					bool exists=false;
					REP(j, origw.size()) if(!seen[j] && origw[j]==ref[i]) {exists=true;seen[j]=1;break;}
					if(!exists) {
//						DD(ref[i]);
						ans=ref[i];
						done=1;
						ok=1;
						return;
					}
				}
				assert(ok);
//				DD(ref);
				return;
			} else {
//				cout<<"go ahead"<<endl;
//				REP(i, N) cout<<tab[i]<<endl;

				VVI nw;
				RANGE(i, put.size(), w.size()) {
					nw.PB(w[i]);
				}
				w = nw;
				f(N, th+1);
			}
		}
		tab=oldtab;
		w=oldw;
		REP(y, N) RANGE(x, y+1, N) swap(tab[y][x], tab[x][y]);
	}
}
void solve(int N, VVI w_) {
	done=0;
	tab = VVI(N, VI(N));
	ans = {};
	origw = w_;
	w = w_;
	f(N, 0);
}
void test() {
	int N = 50;
	VVI t(N, VI(N));
	REP(y, N) REP(x, N) t[y][x]=rand()%1000;
	REP(y, N) REP(x, N) {
		if(x-1>=0) t[y][x]=max(t[y][x], t[y][x-1]+1);
		if(y-1>=0) t[y][x]=max(t[y][x], t[y-1][x]+1);
	}
	DD(t);
	tab=t;
	assert(check());
	VVI ref;
	REP(i, N) ref.PB(tab[i]);
	REP(y, N) RANGE(x, y+1, N) swap(tab[y][x], tab[x][y]);
	REP(i, N) ref.PB(tab[i]);
	random_shuffle(ALL(ref));
	VVI r;
	VI ANS=ref[2*N-1];
	REP(i, 2*N-1) r.PB(ref[i]);
	DD(r);
	solve(N, r);
	DD(ANS);
	DD(ans);
	assert(ANS==ans);
}

int main() {
//	REP(i, 100) test();
//	return 0;
	
	int test_cases;
	cin>>test_cases;
	ll N;
	string s;
	REP(ttt, test_cases) {
		cin>>N;
		VI num(2525);
		ll x;
		REP(i, (2*N-1)*N) {cin>>x;num[x]++;}
		VI ans;
		REP(i, num.size()) if(num[i]%2)ans.PB(i);
//		VVI w(2*N-1, VI(N));
//		REP(y, 2*N-1) {
//			REP(x, N) cin>>w[y][x];
//		}
//		solve(N, w);
		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		return 0;
	}
	return 0;
}



