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
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
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

// Return random integer in [s, e)
#define UNIFORM_INT(s, e)    ( s + (int)((e-s) * UNIFORM_FLOAT_01()) )

// Return random float in [s, e)
#define UNIFORM_FLOAT(s, e)  ( s + (e-s) * UNIFORM_FLOAT_01() )
#define UNIFORM_FLOAT_01()  ( (float)rand()/(1.0f+RAND_MAX) )



// X in [x0, x1]
// Y in [y0, y1]
struct Rect {
	int x0, y0, x1, y1;
	bool operator<(const Rect& o) const {
		return x0<o.x0;
	}
};

ostream& operator<<(ostream& os, const Rect& r) {
	os<<"[Rect "<<r.x0<<" "<<r.y0<<" "<<r.x1<<" "<<r.y1<<" ]";
	return os;
}

int W, H, P, Q, N, X, Y, A, B, C, D;

int naive() {
	if(!(W<100 && H<100 && P<=W && Q<=H)) return -1;
	
	int x=X, y=Y;
	vector<string> scr(H, string(W, ' '));
	REP(i, N) {
		scr[y][x] = 'x';
		assert(y<H);
		assert(x<W);
		int nx = (x * A + y * B + 1) % W;
		int ny = (x * C + y * D + 1) % H;
		x = nx; y = ny;
	}
	
	int ans = 0;
	REP(x, W) REP(y, H) if(x+P<=W && y+Q<=H) {
		int ok=1;
		REP(xx, P) REP(yy, Q) if(scr[y+yy][x+xx]=='x') {ok=0;break;}
		if(ok) ans++;
	}
	return ans;
}

int foo() {
	vector<Rect> rects(N);
	int x=X, y=Y;
	REP(i, N) {
		Rect r = (Rect){x-(P-1), y-(Q-1), x, y};
		r.x0 = max(r.x0, 0);
		r.y0 = max(r.y0, 0);
		r.x1 = min(r.x1, W-1);
		r.y1 = min(r.y1, H-1);
		rects[i] = r;
		int nx = (x * A + y * B + 1) % W;
		int ny = (x * C + y * D + 1) % H;
		x = nx; y = ny;
	}
	sort(ALL(rects));
//	cout<<rects<<endl;
	
	ll ng = 0;
	VI line(H);
	int ri=0;
	REP(scanx, W-P+1) {
		REP(y, H-Q+1) line[y] = max(line[y]-1, 0);
		for(;ri<N && rects[ri].x0==scanx;ri++) {
			int wi = rects[ri].x1 - rects[ri].x0 + 1;
			RANGE(y, rects[ri].y0, rects[ri].y1+1) {
				line[y] = max(line[y], wi);
			}
		}
		REP(y, H-Q+1) ng += line[y] ? 1 : 0;
	}
	int ans = (W-P+1)*(H-Q+1) - ng;
	return ans;
}

void random_test() {
	REP(n, 1000) {
		W = UNIFORM_INT(1, 100);
		H = UNIFORM_INT(1, 100);
		P = UNIFORM_INT(1, W+1);
		Q = UNIFORM_INT(1, H+1);
		N = min(W*H, UNIFORM_INT(1, 1000000));
		X = UNIFORM_INT(0, W);
		Y = UNIFORM_INT(0, H);
		A = UNIFORM_INT(1, 100);
		B = UNIFORM_INT(1, 100);
		C = UNIFORM_INT(1, 100);
		D = UNIFORM_INT(1, 100);
//		cout<<"[Begin] "<<W<<" "<<H<<" "<<P<<" "<<Q<<" "<<N<<" "<<X<<" "<<Y<<" "<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<endl;
		int r0 = naive();
		int r1 = foo();
		if(r0!=-1 && r0!=r1) {
			cout<<"[DIFF] "<<W<<" "<<H<<" "<<P<<" "<<Q<<" "<<N<<" "<<X<<" "<<Y<<" "<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<endl;
		}
	}
}

int main() {
//	random_test();
	
	int T;
	cin>>T;
	REP(ttt, T) {
		cin>>W>>H>>P>>Q>>N>>X>>Y>>A>>B>>C>>D;
		
		int r0 = naive();
		int r1 = foo();
		if(r0!=-1 && r0!=r1) {
			cout<<"[DIFF] "<<W<<" "<<H<<" "<<P<<" "<<Q<<" "<<N<<" "<<X<<" "<<Y<<" "<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<endl;
		}
		
		cout<<"Case #"<<ttt+1<<": "<<r1<<endl;
//		break;
	}
	return 0;
}


