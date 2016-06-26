#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <functional>
using namespace std;

#define C(_a) memset(_a, 0, sizeof(_a))
#define ALL(_obj) (_obj).begin(),(_obj).end()
#define FORB(_i, _a, _b) for((_i) = (_a); (_i) < (_b); ++(_i))
#define FOR(_i, _n) FORB(_i, 0, _n)
#define ADJ(_i, _v) for((_i) = kick[_v]; (_i) >= 0; (_i) = foll[_i])

typedef long long i64;
typedef pair<int, int> pi;

template<typename T> inline void remin(T& cur, const T& prop) { if (cur > prop) cur = prop; }
template<typename T> inline void remax(T& cur, const T& prop) { if (cur < prop) cur = prop; }

// stuff cutline

const int N = 100005;
bool usedv[N], pheroe2[N];
int kick[N], foll[N * 2], dest[N * 2], tin[N], mic[N], snap = 0, last[N];


// dsu
int dsu[N];
int look(int a) {
	return a == dsu[a] ? a : dsu[a] = look(dsu[a]);
}
void unite(int a, int b) {
	a = look(a);
	b = look(b);
	if (a != b) {
		if (rand() % 2) {
			swap(a, b);
		}
		foll[last[a]] = kick[b];
		last[a] = last[b];
		dsu[b] = a;
	}
}

// misc
int anse2[N];
struct edge {
	int id, one, two, w;
	bool operator< (edge x) {
		return w < x.w;
	}
} graph[N];

// list graph
void bridfs(int v, int pe) {
	int dv, adje, nx;
	usedv[v] = true;
	tin[v] = mic[v] = snap++;
	ADJ(adje, v) {
		if (pheroe2[adje / 2] && adje / 2 != pe / 2) {
			dv = look(dest[adje]);
			if (usedv[dv]) {
				remin(mic[v], tin[dv]);
			} else {
				bridfs(dv, adje);
				remin(mic[v], mic[dv]);
				if (tin[v] < mic[dv]) {
					remax(anse2[adje / 2], 2);
				}
			}
		}
		while (nx = foll[adje], nx >= 0 && foll[nx] >= 0 && look(dest[nx]) == v) {
			foll[adje] = foll[nx];
		}
	}
}

void addEdge(int ed, int a, int b) {
	if (kick[a] < 0) last[a] = ed;
	foll[ed] = kick[a];
	dest[kick[a] = ed] = b;
}

int main() {
	int v, e, i, j, t;
	scanf("%d%d", &v, &e);
	
	fill(kick, kick + v, -1);
	fill(last, last + v, -1);
	FOR(i, v) dsu[i] = i;
	C(anse2);

	FOR(i, e) {
		edge& cur = graph[i];
		scanf("%d%d%d", &cur.one, &cur.two, &cur.w), --cur.one, --cur.two;
		cur.id = i;
		addEdge(i * 2, cur.one, cur.two);
		addEdge(i * 2 + 1, cur.two, cur.one);
	}

	C(usedv);
	sort(graph, graph + e);
	for (j = i = 0; i < e; i = j) {
		while (++j < e && graph[i].w == graph[j].w);
		FORB(t, i, j) {
			edge& cur = graph[t];
			cur.one = look(cur.one);
			cur.two = look(cur.two);
			if (cur.one != cur.two) {
				pheroe2[cur.id] = true;
				remax(anse2[cur.id], 1);
			}
		}
		FORB(t, i, j) {
			edge& cur = graph[t];
			if (!usedv[cur.one]) {
				bridfs(cur.one, -2);
			}
		}
		FORB(t, i, j) {
			edge& cur = graph[t];
			usedv[cur.one] = usedv[cur.two] = false;
			pheroe2[cur.id] = false;
			unite(cur.one, cur.two);
		}
	}
	FOR(i, e) puts(anse2[i] == 0 ? "none" : (anse2[i] == 1 ? "at least one" : "any"));
    return 0;
}
