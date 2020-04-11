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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << "\n"; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }


struct bipartite_matching {
	VVI g;
	VI match;
	VI used;
	
	bipartite_matching(int N) {
		g = VVI(N);
	}
	
	int dfs(int v) {
		used[v]=1;
		for(int i=0;i<(int)g[v].size();i++) {
			int u=g[v][i], w=match[u];
			if(w<0 || (!used[w] && dfs(w))) {
				match[v]=u;
				match[u]=v;
				return 1;
			}
		}
		return 0;
	}
	
	int run() {
		int res=0;
		match=VI(g.size(), -1);
		for(int v=0;v<(int)g.size();v++){
			if(match[v]<0) {
				used=VI(g.size());
				if(dfs(v)) res++;
			}
		}
		return res;
	}
	
	void add_edge(int u, int v){
		g[u].push_back(v);
		g[v].push_back(u);
	}
};



#include <cstdio>
#include <cmath>
#include <limits>

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
using namespace std;
typedef vector<int> vi; 

//typedef long double Num; typedef vector<Num> Vec; typedef vector<Vec> Mat;
typedef double Num; typedef vector<Num> Vec; typedef vector<Vec> Mat;
const Num Inf = numeric_limits<Num>::infinity();
const Num NoSolution = numeric_limits<Num>::quiet_NaN();
#define IsSolution(x) (x == x)
const Num EPS = 1e-10;

// Maximize: c * x
// A * x <= b
// x     >= 0
// A : Mat[constraints][vars]
// b : Vec[constraints]
// c : Vec[vars]
// return: score, vars
pair<Num, Vec> simplex(const Mat& A, const Vec& b, const Vec& c) {
	const int m = A.size(), n = A[0].size();
	Mat D(m+1, Vec(n+1)); vi id(n+m+1);
	rer(i, 0, n+m) id[i] = i;
	rep(i, m) {
		rep(j, n) D[i][j] = -A[i][j];
		D[i][n] = b[i];
	}
	Vec names(m);
	REP(i, m) names[i] = n+i;

//	DD(id);
//	DD(names);
//	DD(D);

	rep(j, n) D[m][j] = c[j];
	while(1) {
//		DD(id);
//		DD(names);
//		DD(D);
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
		if(r == m) { /* Unbounded */ return make_pair<Num, Vec>(-7777, {}); }
		if(s == n + m) { /* NoSolution */ return make_pair<Num, Vec>(-7777, {}); }

//		DD(r);
//		DD(s);

		// r: 行 s: 列
		names[r] = id[s];

		swap(id[s], id[n+r]);
		D[r][s] = 1. / D[r][s];
		rer(j, 0, n) if(j != s) D[r][j] *= -D[r][s];
		rer(i, 0, m) if(i != r && abs(D[i][s]) > EPS) {
			rer(j, 0, n) if(j != s) D[i][j] += D[r][j] * D[i][s];
			D[i][s] *= D[r][s];
		}
	}
//	DD(id);
//	DD(names);
//	DD(D);
	Vec vs(n);
	REP(i, m) {
//		DD(names[i]);
//		DD(D[i][n]);
		if(names[i]<n) vs[names[i]] = D[i][n];
//		if(id[i]<m) vs[i] = D[id[i]][n];
	}
//	DD(vs);
	return make_pair(D[m][n], vs);
}

// 無限ループになって動かないことがある。だめ。
//	Maximize: c * x
//	A * x <= b
//	x     >= 0
pair<Num, Vec> simplex2(const Mat& A, const Vec& b, const Vec& c) {
	int vars = A[0].size();
	int cs = A.size();
	DD(vars);
	DD(cs);
	Mat a(cs+1, Vec(vars+cs+1));
	REP(y, cs) REP(x, vars) a[y][x]=A[y][x];
	REP(i, cs) a[i][vars+i]=1;
	REP(i, cs) a[i][vars+cs] = b[i];
	REP(i, vars) a[cs][i] = -c[i];
	DD(a);

	Vec names(cs);
	REP(i, cs) names[i] = vars+i;

	int N_ROW = a.size();
	int N_COL = a[0].size();
	int N_VAR = vars;

    while (1) {
		int x, y;
		Num Min;

        // 列選択
        Min = 9999;
        for (int k = 0; k < N_COL - 1; k++) {
//			if(a[N_ROW - 1][k] < 0) {
//				Min = a[N_ROW - 1][k];
//				y = k;
//			}
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
//            if (a[k][y] > 0 && p < Min) {
            if (p < Min) {
                Min = p;
                x = k;
            }
        }

		names[x] = y;

        // ピボット係数
        Num p = a[x][y];

        // 行の係数を p で除算して a[x][y] が 1 になるようにする
        for (int k = 0; k < N_COL; k++)
            a[x][k] = a[x][k] / p;

        // ピボット列の掃き出し. [x 以外][y] が 0 になるようにする
        for (int k = 0; k < N_ROW; k++) {
            if (k != x) {
                Num d = a[k][y];
                for (int j = 0; j < N_COL; j++)
                    a[k][j] = a[k][j] - d * a[x][j];
            }
        }
		DD(x);
		DD(y);
		DD(names);
		DD(a);
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
//			vs[k] = a[flag][N_COL - 1];
//            printf("x%d = %8.4Lf  flag %d\n", k, a[flag][N_COL - 1], flag);
        } else {
//			vs[k] = 0;
//            printf("x%d = %8.4f ??\n", k, 0.0);
		}
    }
	REP(i, cs) {
		vs[names[i]] = a[i][N_COL-1];
	}
	DD(names);
	REP(i, vars) {
//		cout<<"var "<<i<<" "<<vs[i]<<endl;
	}
//    printf("z  = %8.4Lf\n", a[N_ROW - 1][N_COL - 1]);
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

http://www.mk-mode.com/octopress/2014/02/21/cpp-linear-programming-by-simplex/
の実装を取り込んで割当が出るようになった。
初期配置から制約を生成、縦横斜めの制約も生成して実行してみたが、
縦横な斜めの制約が効かずにすべてのcellが o になってしまう。

14式に対して30変数ある
16変数0とすれば一意解

https://www.sist.ac.jp/~suganuma/kougi/other_lecture/SE/opt/linear/linear.htm
を参考に一意解の求め方をちゃんとした。

そしたら . かつ o という状態ではなくなったが、すべて o になってしまう。

条件が間違ってた。縦横は xo の合計 <= 2 としてたが 1 が正しい。
それで改めて計算すると今度は無限ループ。

新しい条件で simplex を使ったら想定通り 4 が返ってきた。
しかし変数復元ができていない。

値だけ出してみたら、sample2までは答えが合う。

simplex2 で実装した変数復元方法を simplex に移植。
.+xo で 1 こだけ 1 になるなどそれっぽい値になっているが
スコア4 と整合しない xooo がでてきた。
基底変数を置き換える時idをかます用にしたら正しくなった!

がsample3が7になる。
+があったところを.にしてしまっている。

制約を + -> +o >= 1 にしたら通った!

しかし N=100になると遅くて答えがでない。

30でもだめ。
vars: 3600
cs: 1078

100は
vars: 40000
cs: 10598

なのでおそらく想定解はsimplexではないのだと思う。
しかしsimplexで小さいサンプルに対して正答が出せたのは大きな収穫。

終了後

oは+とxが重なったものだとみなせるので+とxをそれぞれ別々に最適に置く、らしい。

13:55
solve2 でrook, bishopの配置問題を解いて D-small, D-large どちらも通った。やった!!!
右肩上がりの斜線IDと左肩上がりの斜線IDをマッチングさせるアイデアは思いつかなかった。
たしかに、左に対して候補の右がいくつもあり、右が対応したらそれ以外の左は対応できないという性質にうまく合致している。



*/


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

vector<string> solve2(const vector<string>& w) {
	int N = w.size();
	vector<string> xs(N, string(N, '.'));
	vector<string> ps(N, string(N, '.'));
	vector<string> rv(N, string(N, '.'));

	// put x
	{
		REP(y, N) REP(x, N) if(w[y][x]=='x' || w[y][x]=='o') xs[y][x] = 'x';
		vector<bool> Ys(N), Xs(N);
		REP(y, N) REP(x, N) if(xs[y][x]=='x') Ys[y]=Xs[x]=true;
		while(1) {
			REP(y, N) REP(x, N) if(xs[y][x]=='.' && !Xs[x] && !Ys[y]) {
				xs[y][x] = 'x';
				Ys[y]=Xs[x]=true;
			}
			if(count(ALL(Xs), true)==N && count(ALL(Xs), true)==N) break;
		}
//		DD(xs);
	}
	// put +
	{
		REP(y, N) REP(x, N) if(w[y][x]=='+' || w[y][x]=='o') ps[y][x] = '+';
		bipartite_matching bm((2*N-1)*2);
		VVI edges(2*N-1, VI(2*N-1));
		vector<bool> usedD0(2*N-1), usedD1(2*N-1);
		REP(y, N) REP(x, N) if(ps[y][x]=='+') {
			int d0 = x+y;
			int d1 = N-1-x+y;
			usedD0[d0] = 1;
			usedD1[d1] = 1;
		}
		REP(y, N) REP(x, N) {
			int d0 = x+y;
			int d1 = N-1-x+y;
			if(!usedD0[d0] && !usedD1[d1]) {
				edges[d0][d1] = 1;
			}
		}
		REP(d0, 2*N-1) REP(d1, 2*N-1) {
			if(edges[d0][d1]) bm.add_edge(d0, 2*N-1+d1);
		}
		int matched=bm.run();
//		DD(matched);
//		DD(bm.match);
		REP(i, 2*N-1) if(bm.match[i]!=-1) {
			// x+y
			int d0 = i;
			// (N-1-x)+y
			int d1 = bm.match[i]-(2*N-1);
//			DD(d0);DD(d1);
			// d0+d1 = N-1+2y
			// (d0+d1-N+1)/2 = y
			int y = (d0+d1-N+1)/2;
			int x = d0-y;
//			DD(x);DD(y);
			ps[y][x] = '+';
		}
//		DD(ps);
	}
	REP(y, N) REP(x, N) {
		rv[y][x] = xs[y][x];
		if(ps[y][x]=='+') rv[y][x] = rv[y][x]=='x' ? 'o' : '+';
	}
	return rv;
}

vector<string> solve(const vector<string>& w) {
	int N = w.size();
	int pre = 0;
	REP(y, N) REP(x, N) if(w[y][x]!='.') pre++;

	int vars = 4*N*N;
	int cs = N*N + pre + 2*N + 2*(2*N-1);
	DD(vars);
	DD(cs);
	Mat m(cs, Vec(vars));
	Vec b(cs);
	Vec c(vars);
	int base = 0;
	{
		// .+xo
		int score[4] = {0, 1, 1, 2};
		REP(i, N*N) {
			REP(j, 4) m[base][4*i+j] = 1;
			b[base] = 1;
			REP(j, 4) c[4*base+j] = score[j];
			base++;
		}
	}
	// pre
	{
		REP(y, N) REP(x, N) {
			int idx = y*N+x;
			if(w[y][x]=='+') {
				// must be + or o
				m[base][idx*4+1] = -1;
				m[base][idx*4+3] = -1;
				b[base] = -1;
				base++;
			}
			if(w[y][x]=='x') {
				// must be x or o
				m[base][idx*4+2] = -1;
				m[base][idx*4+3] = -1;
				b[base] = -1;
				base++;
			}
			if(w[y][x]=='o') {
				// must be o
				m[base][idx*4+3] = -1;
				b[base] = -1;
				base++;
			}
		}
	}
	// たて Σxo <= 1
	{
		REP(x, N) {
			REP(y, N) {
				int idx = y*N+x;
				m[base][idx*4+2] = 1;
				m[base][idx*4+3] = 1;
			}
			b[base] = 1;
			base++;
		}
	}
	// よこ Σxo <= 1
	{
		REP(y, N) {
			REP(x, N) {
				int idx = y*N+x;
				m[base][idx*4+2] = 1;
				m[base][idx*4+3] = 1;
			}
			b[base] = 1;
			base++;
		}
	}
	// ななめ Σ+o <= 1
	{
		REP(k, 2*N-1) {
			REP(y, N) {
				REP(x, N) {
					if(x+y==k) {
						int idx = y*N+x;
						m[base][idx*4+1] = 1;
						m[base][idx*4+3] = 1;
					}
				}
			}
			b[base] = 1;
			base++;

			REP(y, N) {
				REP(x, N) {
					if((N-1-x)+y==k) {
						int idx = y*N+x;
						m[base][idx*4+1] = 1;
						m[base][idx*4+3] = 1;
					}
				}
			}
			b[base] = 1;
			base++;
		}
	}
	auto p = simplex(m, b, c);
	DD(p.first);
	DD(p.second);

//	auto p = simplex2(m, b, c);
	auto vs = p.second;
	auto rv = w;
	REP(y, N) REP(x, N) {
		rv[y][x] = '.';
		ll sum = 0;
		REP(i, 4) sum += (ll)vs[(y*N+x)*4+i];
		assert(sum==1);
		if(vs[(y*N+x)*4+0]) rv[y][x] = '.';
		if(vs[(y*N+x)*4+1]) rv[y][x] = '+';
		if(vs[(y*N+x)*4+2]) rv[y][x] = 'x';
		if(vs[(y*N+x)*4+3]) rv[y][x] = 'o';
	}
	return rv;
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
	{
		auto p = simplex(m, b, c);
		DD(p.first);
	}
	{
		auto p = simplex2(m, b, c);
		DD(p.first);
		DD(p.second);
	}
}

void test2() {
	int N = 2;
	int vars = 3;
	int cs = 3;
	Mat m(cs, Vec(vars));
	m = {
		{3, 1},
		{2.5, 2},
		{1, 2},
	};
	Vec b(cs);
	b = {9, 12.5, 8};
	Vec c(vars);
	c = {3,2};
	{
		auto p = simplex(m, b, c);
		DD(p.first);
		DD(p.second);
	}
	{
		auto p = simplex2(m, b, c);
		DD(p.first);
		DD(p.second);
	}
}

int main() {
//	test();
//	return 0;

//	test2();
//	return 0;

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
//		auto r = solve(w);
		auto r = solve2(w);

		int W=N, H=N;
		int ch = 0;
		REP(y, H) REP(x, W) {
			if(r[y][x]!=w[y][x]) {
				ch++;
			}
		}
//		print(w);
//		DD("after");
//		print(r);
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



