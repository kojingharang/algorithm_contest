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
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define MIN_UPDATE(target, value) target = min(target, value)
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v);
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
struct Point{
	int x, y;
	bool operator<(const Point& a) const {
		if(x==a.x) return y<a.y;
		return x<a.x;
	}
	bool operator==(const Point& a) const {
		return x==a.x && y==a.y;
	}
};
Point operator+(const Point&a, const Point& b) {return {a.x+b.x, a.y+b.y};}
Point operator-(const Point&a, const Point& b) {return {a.x-b.x, a.y-b.y};}
std::ostream& operator<<(std::ostream& os, const Point& v) { os << "("<<v.x<<" "<<v.y << ")"<<endl; return os; }

vector<vector<vector<Point>>> shapesN;

void printShape(vector<Point> sh) {
	int L = 7;
	vector<string> s(2*L, string(2*L, ' '));
	for(auto& p : sh) {
//		cout<<":: "<<p.x<<" "<<p.y<<endl;
		s[p.y+L][p.x+L] = '*';
	}
	for(auto line : s) cerr<<line<<endl;
}


bool sameShapeTranslate(const vector<Point>& a, const vector<Point>& b) {
	Point tr;
	REP(i, a.size()) {
		Point ltr = b[i]-a[i];
		if(i==0) {
			tr = ltr;
		} else {
			if(!(tr==ltr)) return false;
		}
	}
	return true;
}

// 回転/反転したshapeをすべて返す.
vector<vector<Point>> refRotShapes(const vector<Point>& sh) {
	vector<vector<Point>> rv;
	rv.PB(sh);
	REP(r, 2) {
		vector<Point> neu(sh);
		// reflection
		if(r) for(auto& p : neu) p.x*=-1;
		REP(i, 3) {
			// rotation
			for(auto& p : neu) {
				swap(p.x, p.y);
				p.y*=-1;
			}
			sort(ALL(neu));
			if(!sameShapeTranslate(sh, neu)) {
				rv.PB(neu);
			}
		}
	}
	return rv;
}

bool sameShape(const vector<Point>& a, const vector<Point>& b) {
	for(auto& sh : refRotShapes(b)) {
		if(sameShapeTranslate(a, sh)) return true;
	}
	return false;
}

bool dup(vector<Point>& shape, vector<vector<Point>>& shapes) {
	for(auto& orig : shapes) {
		if(sameShape(shape, orig)) return true;
	}
	return false;
}

// Generate Polynomios of 1 to N-blocks.
void makePolynomios(int N) {
	if(N==1) {
		vector<Point> shape;
		shape.PB({0, 0});
		shapesN[0].PB(shape);
		return;
	}
	makePolynomios(N-1);
	vector<vector<Point>> ns;
	auto& shapes = shapesN[N-2];
	for(auto& orig : shapes) {
//		cout<<"For orig "<<orig<<endl;
		for(auto& p : orig) {
			REP(dir, 4) {
				Point np = {dx[dir]+p.x, dy[dir]+p.y};
				vector<Point> neu(orig);
				if(find(ALL(neu), np)==neu.end()) {
					neu.PB(np);
					sort(ALL(neu));
					if(!dup(neu, ns)) ns.PB(neu);
				}
//				cout<<"Add "<<neu<<endl;
			}
		}
	}
	shapesN[N-1] = ns;
}

ll X,R,C;
vector<vector<bool>> m;

void showMap() {
	REP(y, R){
		REP(x,C) {
			cerr<<(m[y][x]?'*':'_');
		}
		cerr<<endl;
	}
	cerr<<endl;
}

vector<vector<bool>> vis;
int paintConnected(int x, int y) {
	int v=1;
	vis[y][x]=true;
	REP(dir, 4) {
		int nx = x+dx[dir];
		int ny = y+dy[dir];
		if(IN_RANGE(nx, 0, C) && IN_RANGE(ny, 0, R) && !m[ny][nx] && !vis[ny][nx]) {
			v+=paintConnected(nx, ny);
		}
	}
	return v;
}

bool validRest() {
	vis = vector<vector<bool>>(R, vector<bool>(C));
	REP(y, R) REP(x, C) if(!m[y][x] && !vis[y][x]) {
		int n = paintConnected(x, y);
		if(n%X) return false;
	}
	return true;
}

bool solve() {
	if(X>=7) return true;
	if((R*C)%X) {
		return true;
	}

	m = vector<vector<bool>>(R, vector<bool>(C));
	// 全形の全置き方について
	// １こおく→残り領域がすべてXの倍数ならlans=false, そうでなければans=true
	auto& shapes = shapesN[X-1];
	bool canFillAll = true;
	REP(i, shapes.size()) {
		auto& osh = shapes[i];
		// R selected a shape.

		bool canFill = false;
		// 置き方すべてについて
		for(auto& sh : refRotShapes(osh)) {
			cerr<<"Try to put rotated shape"<<endl;
			printShape(sh);

			REP(y, R) REP(x, C) REP(pei, X) {
				// put sh[pei] point to (x, y)
				auto tr = Point{x, y}-sh[pei];
				bool canPut = true;
				REP(ei, X) {
					auto p = sh[ei]+tr;
					if(!IN_RANGE(p.x, 0, C)||!IN_RANGE(p.y, 0, R)) canPut = false;
				}
				if(canPut) {
					REP(y, R) m[y].assign(C, false);
					REP(ei, X) {
						auto p = sh[ei]+tr;
		//				cout<<p<<endl;
						m[p.y][p.x]=true;
					}
					showMap();
					if(validRest()) {
						canFill = true;
						cerr<<"Okeru"<<endl;
						goto OneShapePutEnd;
					}
				}
			}
		}
OneShapePutEnd:
		if(!canFill) {canFillAll = false;break;}
	}
	return !canFillAll;
}

int main() {
	int maxX = 6;
	shapesN = vector<vector<vector<Point>>>(maxX);
	makePolynomios(shapesN.size());
	REP(i, shapesN.size()) {
//		cout<<"ShapesN "<<i+1<<" count "<<shapesN[i].size()<<endl;
//		for(auto& sh : shapesN[i]) printShape(sh);
	}

	int test_cases;
	cin>>test_cases;
	string s;

	if(0)
	{
		RANGE(x, 3, 4) RANGE(r, 1, 20) RANGE(c, 1, 20)
//		if(r>=c)
		{
			X=x; R=r; C=c;
			cerr<<"XRC "<<x<<" "<<r<<" "<<c<<": ..."<<endl;
			bool rwin = solve();
			cerr<<"XRC "<<x<<" "<<r<<" "<<c<<": "<<(rwin?"RICHARD":"GABRIEL")<<endl;
		}
		return 0;
	}

	REP(ttt, test_cases) {
		cin>>X>>R>>C;
		bool rwin = solve();
		cout<<"Case #"<<ttt+1<<": "<<(rwin?"RICHARD":"GABRIEL")<<endl;
//		return 0;
	}
	return 0;
}



