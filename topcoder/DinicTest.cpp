#include <vector>
#include <queue>
#include <iostream>
#define NG (-1)

using namespace std;

// 最大流 Dinic O(EV^2)だけど、実際もっとはやい。
class Dinic
{
public:
	Dinic(int input_maxv) : maxv(input_maxv)
	{
		G.resize(input_maxv);
		level.resize(input_maxv);
		iter.resize(input_maxv);
	}

	void add_edge_both(int from, int to, int cap)
	{
		if(cap>0)
		{
			const int rev_from	= G[from].size();
			const int rev_to	= G[to].size();
			G[from].push_back(edge(to,cap,rev_to));
			G[to].push_back(edge(from,cap,rev_from));
		}
	}

	void add_edge(int from, int to, int cap)
	{
		if(cap>0)
		{
			const int rev_from	= G[from].size();
			const int rev_to	= G[to].size();
			G[from].push_back(edge(to,cap,rev_to));
			G[to].push_back(edge(from,0,rev_from));
		}
	}

	// sからtへの最大流を求める
	int max_flow(int s, int t)
	{
		int flow = 0;
		for(;;)
		{
			bfs(s);
			if(level[t]<0) break;
			fill(iter.begin(),iter.end(),0);
			int f;
			while( (f=dfs(s,t,DINIC_INF))>0)
			{
				flow += f;
			}
		}

		return flow;
	}

	//  ノードsから辿れる範囲を求める（これ以上流せないところcap=0は、リンクがなくなる）
	// （流し終わったあとsourceからたどれる範囲が、最小カット時のs側。たどれない法がt側。その境界がカットするところ。）
	vector <bool> get_nodes_in_group(int s)
	{
		vector <bool> ret(maxv);

		queue<int> que;
		que.push(s);
		while(!que.empty())
		{
			int v = que.front();
			que.pop();
			ret[v]=true;

			for(int i=0;i<G[v].size();i++)
			{
				edge &e = G[v][i];
				if(e.cap>0 && !ret[e.to])
				{
					que.push(e.to);
				}
			}
		}
		return ret;
	}

	void disp()
	{
		for (int v = 0; v < maxv; v++)
		{
			printf("%d:",v);
			for(int i=0;i<G[v].size();i++)
			{
				if(G[v][i].init_cap>0)
				{
					printf("->%d(%d),",G[v][i].to,G[v][i].init_cap);
				}
			}
			printf("\n");
		}
	}

private:
	// sからの最短距離をBFSで計算する
	void bfs(int s)
	{
		fill(level.begin(),level.end(),NG);
		queue<int> que;
		level[s]=0;
		que.push(s);
		while(!que.empty())
		{
			int v = que.front();
			que.pop();
			for(int i=0;i<G[v].size();i++)
			{
				edge &e = G[v][i];
				if(e.cap>0 && level[e.to]<0)
				{
					level[e.to] = level[v] + 1;
					que.push(e.to);
				}
			}
		}
	}

	// 増加パスをDFSで探す
	int dfs(int v, int t, int f)
	{
		if(v==t) return f;
		for (int &i=iter[v];i<G[v].size();i++)
		{
			edge& e = G[v][i];
			if(e.cap>0 && level[v]<level[e.to])
			{
				int d = dfs(e.to, t, min(f, e.cap));
				if(d>0)
				{
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	static const int DINIC_INF = INT_MAX; // 容量をllにしたいときは、ここも変える

	struct edge 
	{
		edge(int input_to, int input_cap, int input_rev) : to(input_to), cap(input_cap), rev(input_rev), init_cap(input_cap) {}
		int to;		// 行先
		int cap;	// 容量
		int rev;	// 逆辺
		int init_cap; // 初期容量（デバッグ用）
	};

	int	maxv;
	vector < vector <edge> > G;	// グラフの隣接リスト
	vector < int > level;		// sからの距離
	vector < int > iter;		// どこまで調べ終わったか
};

int main()
{
	int n;
	cin >> n;

	vector <int> moyasu(n), umeru(n);
	for (int i = 0; i < n; i++)
	{
		cin >> moyasu[i] >> umeru[i];
	}

	const int S = n;
	const int T = S+1;
	const int V = T+1;

	Dinic*	dinic = new Dinic(V);

	for (int i = 0; i < n; i++)
	{
		dinic->add_edge(S, i, moyasu[i]);
		dinic->add_edge(i, T, umeru[i]);
	}
	const int result = dinic->max_flow(S,T);
	cout << result << endl;


	delete dinic;
	return 0;
}
/*
3
50 100
60 100
130 100
*/
