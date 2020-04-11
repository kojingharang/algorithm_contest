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

//#define EPS 1e-12
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


#include <cstdio>
#include <cmath>
#include <limits>

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
using namespace std;
typedef vector<int> vi; 

typedef long double Num; typedef vector<Num> Vec; typedef vector<Vec> Mat;
const Num Inf = numeric_limits<Num>::infinity();
const Num NoSolution = numeric_limits<Num>::quiet_NaN();
#define IsSolution(x) (x == x)
const Num EPS = 1e-10;

//	Maximize: c * x
//	A * x <= b
//	x     >= 0
Num simplex(const Mat& A, const Vec& b, const Vec& c) {
	const int m = A.size(), n = A[0].size();
	Mat D(m+1, Vec(n+1)); vi id(n+m+1);
	rer(i, 0, n+m) id[i] = i;
	rep(i, m) {
		rep(j, n) D[i][j] = -A[i][j];
		D[i][n] = b[i];
	}
	rep(j, n) D[m][j] = c[j];
	while(1) {
		DD(id);
		DD(D);
		int r = m, s = n+m;
		rep(i, m) if(D[i][n] < -EPS && id[n+r] > id[n+i]) r = i;
		rep(j, n) if(D[m][j] > EPS && id[s] > id[j]) s = j;
		if(r == m && s == n + m) break;
		if(id[n + r] < id[s]) {
			s = n + m;
			rep(j, n) if(D[r][j] > EPS && id[s] > id[j]) s = j;
		}else {
			r = m;
			rep(i, m) if(D[i][s] < -EPS && id[n+r] > id[n+i]) r = i;
		}
		if(r == m) { /* Unbounded */ return NoSolution; }
		if(s == n + m) { /* NoSolution */ return NoSolution; }
		swap(id[s], id[n+r]);
		D[r][s] = 1. / D[r][s];
		rer(j, 0, n) if(j != s) D[r][j] *= -D[r][s];
		rer(i, 0, m) if(i != r && abs(D[i][s]) > EPS) {
			rer(j, 0, n) if(j != s) D[i][j] += D[r][j] * D[i][s];
			D[i][s] *= D[r][s];
		}
	}
	DD(id);
	DD(D);
	return D[m][n];
}

//	Maximize: c * x
//	A * x <= b
//	x     >= 0
pair<Num, Vec> simplex2(const Mat& A, const Vec& b, const Vec& c) {
	int vars = A[0].size();
	int cs = A.size();
	Mat a(cs+1, Vec(vars+cs+1));
	REP(y, cs) REP(x, vars) a[y][x]=A[y][x];
	REP(i, cs) a[i][vars+i]=1;
	REP(i, cs) a[i][vars+cs] = b[i];
	REP(i, vars) a[cs][i] = -c[i];
	DD(a);

	int N_ROW = a.size();
	int N_COL = a[0].size();
	int N_VAR = vars;

    while (1) {
		int x, y;
		Num Min;

        // 列選択
        Min = 9999;
        for (int k = 0; k < N_COL - 1; k++) {
            if (a[N_ROW - 1][k] < Min) {
                Min = a[N_ROW - 1][k];
                y = k;
            }
        }
        if (Min >= 0) break;

        // 行選択
        Min = 9999;
        for (int k = 0; k < N_ROW - 1; k++) {
            Num p = a[k][N_COL - 1] / a[k][y];
            if (a[k][y] > 0 && p < Min) {
                Min = p;
                x = k;
            }
        }

        // ピボット係数
        Num p = a[x][y];

        // ピボット係数を p で除算
        for (int k = 0; k < N_COL; k++)
            a[x][k] = a[x][k] / p;

        // ピボット列の掃き出し
        for (int k = 0; k < N_ROW; k++) {
            if (k != x) {
                Num d = a[k][y];
                for (int j = 0; j < N_COL; j++)
                    a[k][j] = a[k][j] - d * a[x][j];
            }
        }
    }

	DD(a);

    // 結果出力
	Vec vs(vars);
    for (int k = 0; k < N_VAR; k++) {
        int flag = -1;
        for (int j = 0; j < N_ROW; j++) {
            if (a[j][k] == 1) flag = j;
//            if (a[j][k] == 1) {
//                flag = j;
//            } else if (flag != -1 && a[j][k] != 0) {
//                flag = -1;
//                break;
//            }
        }
        if (flag != -1 && flag < N_ROW-1) {
			vs[k] = a[flag][N_COL - 1];
            printf("x%d = %8.4Lf  flag %d\n", k, a[flag][N_COL - 1], flag);
        } else {
			vs[k] = 0;
            printf("x%d = %8.4f ??\n", k, 0.0);
		}
    }
    printf("z  = %8.4Lf\n", a[N_ROW - 1][N_COL - 1]);
	return make_pair(a[N_ROW - 1][N_COL - 1], vs);
}

/*
考察
行、列について + 以外のものは 1 こだけ
斜めについて x 以外のものは 1 こだけ

列が1この場合、+++++o とすれば score N+1
列が2この場合

++x+x+o
+x+o+x+

++++++o
+++++x+
++.....

.....x.
....x..
+++o+++
..x....
.x.....

o++.++++
.xo.....
..x.o...
...x..o.
....x...



oを含む斜め線上は必ずx
xを含む斜め線上は必ずx or o

oはたてよこ斜めに1こしかおけない

LP問題であろう
各cellについて、
	. or +
	. or x
	. or o
の3変数を定義。最大3万変数
0 <= xij0 + xij1 + xij2 <= 1
縦横について 0 <= xij1+xij2 <= 2
ななめについて 0 <= xij0+xij2 <= 2
のとき Σ xij0+xij1+2xij2
を最大化する

線形計画問題をsimplex法で解くライブラリ
http://d.hatena.ne.jp/anta1/20121223/1356258857

あとは経路復元をすれば原理上答えが求まりそう。

simplexの説明
http://www.mk-mode.com/octopress/2014/02/21/cpp-linear-programming-by-simplex/


↓牛ゲーテクはこの問題には使えない

牛ゲーの解説。両辺に変数が１こずつのときは最短路問題に帰着できるとか
http://miz-miz.biz/contests/k4pc/commentary/F.html
http://kmjp.hatenablog.jp/entry/2014/04/29/1200


2x2で +xo x4 マスの12変数に対して +xo <= 1 制約をいれて係数 +x:1 o:2 をいれて simplex を呼んだら 8 が返ってきた。
id, dを表示するも変数割当がわからん。

左上cellに対して x + o <= 0 制約を追加したら 7 になった。これはOK.






*/

bool cellOK(const vector<string>& w, int X, int Y) {
	int H = w.size();
	assert(H);
	int W = w[0].size();
//	DD(X);
//	DD(Y);
	{
		map<char, int> co;
		REP(x, W) co[w[Y][x]]++;
		if(2<=co['x']+co['o']) {
//			DD("2 xo in row");
			return false;
		}
	}
	{
		map<char, int> co;
		REP(y, H) co[w[y][X]]++;
		if(2<=co['x']+co['o']) {
//			DD("2 xo in row");
			return false;
		}
	}
	{
		int dx[] = {1,1};
		int dy[] = {1,-1};
		REP(dir, 2) {
			map<char, int> co;
			RANGE(i, -100, 101) {
				int px = X + i*dx[dir];
				int py = Y + i*dy[dir];
				if(IN_RANGE(px, 0, W) && IN_RANGE(py, 0, H)) {
//					DD(px);DD(py);
					co[w[py][px]]++;
				}
			}
//			DD(dir);
//			DD(co);
			if(2<=co['+']+co['o']) {
//				DD("2 +o in diag");
				return false;
			}
		}
	}
	return true;
}

bool mapOK(const vector<string>& w) {
	int H = w.size();
	assert(H);
	int W = w[0].size();
	REP(x, W) REP(y, H) if(!cellOK(w, x, y)) return false;
	return true;
}

int getScore(const vector<string>& w) {
	int H = w.size();
	assert(H);
	int W = w[0].size();
	map<char, int> score = {
		{'o', 2},
		{'+', 1},
		{'x', 1},
	};
	int ans = 0;
	REP(y, H) REP(x, W) ans += score[w[y][x]];
	return ans;
}

void print(const vector<string>& w) {
	int H = w.size();
	REP(y, H) cout<<w[y]<<endl;
}

vector<string> solve(const vector<string>& orig) {
	int H = orig.size();
	assert(H);
	int W = orig[0].size();

	string cands = "ox+";
	vector<pair<int, int>> poses;
	REP(y, H) REP(x, W) {
		poses.PB(MP(x, y));
	}
	vector<string> best;
	int bestS = 0;
	REP(i, 20) {
		auto w = orig;
		for(char c : cands) {
			for(auto& p : poses) {
				int x = p.first;
				int y = p.second;
				char t = w[y][x];
				if(w[y][x]=='.' || c=='o') {
					w[y][x]=c;
					if(!cellOK(w, x, y)) w[y][x]=t;
				}
			}
		}
		int sc = getScore(w);
		if(bestS<sc) {
			bestS=sc;
			best=w;
		}
		random_shuffle(ALL(poses));
//		break;
	}
	return best;
}

void test() {
	int N = 2;
	int vars = 3*N*N;
//	int cs = N*N + N + N + 2*(2*N-1);
//	int cs = N*N;
	int cs = N*N +1;
	Mat m(cs, Vec(vars));
	Vec b(cs);
	Vec c(vars);
	{
		REP(i, N*N) {
			REP(j, 3) m[i][3*i+j] = 1;
			b[i] = 1;
			REP(j, 3) c[3*i+j] = j==2 ? 2 : 1;
		}
	}
	{
		int base = N*N;
		m[base][1] = 1;
		m[base][2] = 1;
		b[base] = 0;
	}
	Num r = simplex(m, b, c);
	DD(r);
	auto p = simplex2(m, b, c);
	DD(p.first);
	DD(p.second);
}

int main() {
	test();
	return 0;

	if(0)
	{
		int H;
		cin>>H;
		vector<string> w(H);
		REP(i, w.size()) cin>>w[i];
		DD(w);
		cout<<mapOK(w)<<endl;
		return 0;
	}

	if(0)
	{
		int W=7, H=5;
		vector<string> w(H, string(W, '.'));
//		DD(w);
		w = solve(w);
		REP(i, w.size()) DD(w[i]);
		return 0;
	}

	int test_cases;
	cin>>test_cases;
	ll N,M, x, y;
	string s;
	REP(ttt, test_cases) {
		cin>>N>>M;
		vector<string> w(N, string(N, '.'));
		REP(i, M) {
			cin>>s>>x>>y;
			w[y-1][x-1]=s[0];
		}
		auto r = solve(w);

		int W=N, H=N;
		int ch = 0;
		REP(y, H) REP(x, W) {
			if(r[y][x]!=w[y][x]) {
				ch++;
			}
		}
		print(w);
		DD("after");
		print(r);
		int ans = getScore(r);
		cout<<"Case #"<<ttt+1<<": "<<ans<<" "<<ch<<endl;
		REP(y, H) REP(x, W) {
			if(r[y][x]!=w[y][x]) {
				cout<<r[y][x]<<" "<<x+1<<" "<<y+1<<endl;
			}
		}
//		return 0;
	}
	return 0;
}



