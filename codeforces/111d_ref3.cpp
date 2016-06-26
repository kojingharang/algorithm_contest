#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::sort;
using std::min;

int n;
const int maxn = 100000;
int m;
const int maxm = 100000;

struct edge
{
	int u, v, w, id;
	edge() = default;
	edge(int _u, int _v, int _w, int _id)
	 : u(_u), v(_v), w(_w), id(_id) {}
};

struct cmp_weight
{
	bool operator()(const edge& lhs, const edge& rhs)
	{
		return lhs.w < rhs.w;
	}
};

vector<edge> e;
vector<int> result;

vector<int> father;
vector<int> rank;

int find_root(int p)
{
	return father[p] == p ? p : father[p] = find_root(father[p]);
}

void union_set(int lhs, int rhs)
{
	if (rank[lhs] < rank[rhs])
		father[rhs] = lhs;
	else if (rank[lhs] > rank[rhs])
		father[lhs] = rhs;
	else
	{
		father[rhs] = lhs;
		++rank[lhs];
	}
}

class graph
{
	public:
	struct edge
	{
		int v, id;
		edge() = default;
		edge(int _v, int _id) : v(_v), id(_id) {}
	};
	typedef vector<edge> edge_list;
	typedef edge_list::iterator edge_iterator;
	typedef unordered_map<int, edge_list> vertex_list;

	private:
	vertex_list header;

	public:
	void add_edge(int u, int v, int id)
	{
		header[u].push_back(edge(v, id));
		header[v].push_back(edge(u, id));
	}

	edge_list& fetch_edge(int u) { return header[u]; }
	vertex_list& fetch_vertex() { return header; }
	void clear() { header.clear(); }
};

graph g;
vector<int> dfn;
vector<int> low;
vector<int> chk;
int date;

void tarjan(int u)
{
	dfn[u] = low[u] = ++date;
	for (auto e : g.fetch_edge(u))
	{
		int v = e.v;
		if (dfn[v] == 0)
		{
			chk[e.id] = true;
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if (dfn[u] < low[v])
				result[e.id] = 2;
		}
		else if (!chk[e.id])
			low[u] = min(low[u], dfn[v]);
	}
}

int main()
{
	cin>>n>>m;
	e.resize(m); result.resize(m);
	father.resize(n); rank.resize(n);
	dfn.resize(n); low.resize(n);
	chk.resize(m);
	for (int i = 0; i != n; ++i) father[i] = i;
	for (int i = 0; i != m; ++i)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
		--e[i].u; --e[i].v;
		e[i].id = i;
	}
	sort(e.begin(), e.end(), cmp_weight());
	for (auto i = e.begin(); i != e.end(); )
	{
		g.clear();
		auto j = i;
		for ( ; j != e.end() && i->w == j->w; ++j)
		{
			int x = find_root(j->u);
			int y = find_root(j->v);
			if (x != y)
			{
				result[j->id] = 1;
				g.add_edge(x, y, j->id);
				dfn[x] = low[x] = 0;
				dfn[y] = low[y] = 0;
				chk[j->id] = false;
			}
		}
		date = 0;
		for (auto k : g.fetch_vertex())
			if (dfn[k.first] == 0)
				tarjan(k.first);
		for (auto k = i; k != j; ++k)
		{
			int x = find_root(k->u);
			int y = find_root(k->v);
			if (x != y)
				union_set(x, y);
		}
		i = j;
	}
	for (int i : result)
		switch (i)
		{
			case 0 : cout << "none" << endl; break;
			case 1 : cout << "at least one" << endl; break;
			case 2 : cout << "any" << endl; break;
			default : break;
		}
}
