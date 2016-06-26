#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <numeric>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(ll i=0,_n=(n);(i)<(int)_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool Union(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool Find(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};
// UnionFind uf(N);
// if(uf.Union(ei, ej)) ...
// if(uf.Find(ei, ej)) ...

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  int idx;
  int st;
  Edge(){}
  Edge(int src, int dst, Weight weight, int idx) :
    src(src), dst(dst), weight(weight), idx(idx), st(0) { }
};
struct CompareWeight {
	bool operator()(const Edge &e, const Edge &f) {
		return e.weight != f.weight ? e.weight < f.weight : 
			e.src != f.src ? e.src < f.src : e.dst < f.dst;
	}
};
struct CompareIndex {
	bool operator()(const Edge &e, const Edge &f) {
		return e.idx < f.idx;
	}
};
std::ostream& operator<<(std::ostream& os, const Edge& e) {
	os << e.src << " "<<e.dst<<" "<<e.weight<<" "<<e.st<<" "<<e.idx<<endl;
	return os;
}



/////////////////////// Graph (loop detection)

void get_loop_ud_sub(const VVI& g, int idx, int parent, int& t, VI& visit, VI& hi, VVI& loops) {
	//cout<<"Visit "<<idx<<endl;
	hi.PB(idx);
	visit[idx] = t++;
	REP(i, g[idx].size()) {
		int adj = g[idx][i];
		if(adj==parent) continue;
		if(visit[adj] > 0) {
			if(visit[adj] < t) {
				VI loop;
				for(int j=hi.size()-1; j>=0 && hi[j]!=adj; j--) loop.PB(hi[j]);
				loop.PB(adj);
				//cout<<"Loop found"<<endl;
				//cout<<" parent: "<<parent<<endl;;
				//cout<<" vis: "<<visit<<endl;;
				//cout<<" history: "<<hi<<endl;;
				//cout<<" loop: "<<loop<<endl;;
				//cout<<" idx: "<<idx<<endl;;
				//cout<<" adj: "<<adj<<endl;;
				//if(loop.size()>2)
				loops.PB(loop);
			}
		} else {
			get_loop_ud_sub(g, adj, idx, t, visit, hi, loops);
		}
	}
	t--;
	hi.pop_back();
}

// Get all loops of the undirected graph
VVI get_loop_ud(const VVI& g, int nodes) {
	VI visit(nodes), history;
	VVI loops;
	int t=1;
	REP(i, nodes) if(!visit[i]) get_loop_ud_sub(g, i, nodes, t, visit, history, loops);
	//REP(i, loops.size()) {
	//	REP(j, loops[i].size()) {
	//		int a = loops[i][j];
	//		int b = loops[i][(j+1)%loops[i].size()];
	//		int ok=0;
	//		REP(k, g[a].size()) if(g[a][k]==b) ok=1;
	//		if(!ok) {
	//			cout<<"Can't go "<<a<<" "<<b<<" in "<<loops[i]<<" graph "<<g[a]<<endl;
	//			cout<<"All graph"<<endl;
	//			REP(i, g.size()) cout<<i<<": "<<g[i]<<endl;
	//			cout<<"All loops"<<endl;
	//			cout<<loops<<endl;
	//		}
	//	}
	//}
	return loops;
}
VVI get_loop_ud(const VVI& g) {
	return get_loop_ud(g, g.size());
}

void get_loop_d_sub(const VVI& g, int idx, VI& visit, VI& hi, VVI& loops) {
	//cout<<"visit "<<idx<<" "<<visit<<endl;
	hi.PB(idx);
	visit[idx] = 1;
	REP(i, g[idx].size()) {
		int adj = g[idx][i];
		if(visit[adj]==1) {
			VI loop;
			//cout<<"HI "<<hi<<endl;
			for(int j=hi.size()-1; j>=0 && hi[j]!=adj; j--) loop.PB(hi[j]);
			loop.PB(adj);
			reverse(ALL(loop));
			loops.PB(loop);
		} else if(visit[adj]==0) {
			get_loop_d_sub(g, adj, visit, hi, loops);
		}
	}
	visit[idx] = 2;
	hi.pop_back();
}

// Get all loops of the undirected graph
VVI get_loop_d(const VVI& g) {
	VI visit(g.size()), history;
	VVI loops;
	REP(i, g.size()) if(visit[i]==0) get_loop_d_sub(g, i, visit, history, loops);
	return loops;
}

void make_graph_from_edge(vector<PII> edges, int directed, VVI& g) {
	REP(i, edges.size()) if(edges[i].first > edges[i].second) swap(edges[i].first, edges[i].second);
	sort(ALL(edges));
	edges.erase(unique(ALL(edges)), edges.end());
	//cout<<"edges "<<edges<<endl;
	REP(i, edges.size()) {
		int a=edges[i].first, b=edges[i].second;
		REP(j, directed ? 1 : 2) {
			while(a >= (int)g.size()) g.push_back(VI());
			g[a].push_back(b);
			swap(a, b);
		}
	}
}

// Case directed==0: edges==[0, 1, 2, 3] (means graph 0--1 2--3) -> [[1], [0], [3], [2]]
// Case else:        edges==[0, 1, 2, 3] (means graph 0->1 2->3) -> [[1], [], [3]]
void make_graph_from_edge(VI edges, int directed, VVI& g) {
	vector<PII> ne;
	
	REP(i, edges.size()/2) {
		ne.PB(MP(edges[i*2], edges[i*2+1]));
	}
	make_graph_from_edge(ne, directed, g);
}

void test_graph_loop() {
	// 1 -> 2 -> 0 -> 3 -> 4 -> 2
	// 5 -> 6 -> 5
	int edges_raw[] = { 1,2,   2,0,   0,3,   3,4,   4,2,   5,6,   6,5,   7,8,   8,9,   9,7, };
	VI edges = VI(&edges_raw[0], &edges_raw[sizeof(edges_raw)/sizeof(edges_raw[0])]);
	{
		VVI g;
		make_graph_from_edge(edges, 0, g);
		cout<<"Graph"<<endl;
		cout<<g<<endl;
		cout<<"loop of undirected graph"<<endl;
		cout<<get_loop_ud(g)<<endl;
	}
	{
		VVI g;
		make_graph_from_edge(edges, 1, g);
		cout<<"Graph"<<endl;
		cout<<g<<endl;
		cout<<"loop of directed graph"<<endl;
		cout<<get_loop_d(g)<<endl;
	}
}

void test_graph_loop2() {
/*
Can't go 0 3 in 1 0 3  graph 1 2
All graph
0: 1 2
1: 0 2 3
2: 0 1 3
3: 1 2
All loops
2 1 0
3 2 1
1 0 3
0 2
*/
	//int edges_raw[] = { 0,1,0,2,1,0,1,2,1,3,2,0,2,1,2,3,3,1,3,2, 3,2,3,2,3,2, };
	//VI edges = VI(&edges_raw[0], &edges_raw[sizeof(edges_raw)/sizeof(edges_raw[0])]);
	//get_loop_ud(make_graph_from_edge(edges, 0));
	//return;
	
	REP(lo, 100) {
		VI v;
		REP(i, 20) {
			int a = (int)(((float)rand()/RAND_MAX)*8);
			int b = (int)(((float)rand()/RAND_MAX)*8);
			v.PB(a);
			v.PB(b);
		}
		//cout<<v<<endl;
		VVI g;
		make_graph_from_edge(v, 0, g);
		get_loop_ud(g);
	}
}

/////////////////////// Graph (loop detection)

#define NONE 1
#define ANY  2
#define ONE  3

int main() {
	//test_graph_loop2();
	//return 0;
	
	int N,E;
	cin>>N>>E;
	UnionFind uf(N);
	VVI loopg(N);
	
	vector<Edge> ed(E);
	VI lop(E);
	REP(i, E) {
		int i0, i1, w;
		cin>>i0>>i1>>w;
		i0--;
		i1--;
		ed[i] = Edge(i0, i1, w, i);
	}
	
	int debug=ed[0].weight==365675;
	
	sort(ALL(ed), CompareWeight());
	//cout<<"sort done"<<endl;
	//cout<<ed<<endl;
	
	VI smallmap(N);
	
	REP(i, E) {
		if(debug && i%10000==0)
		cout<<"loop: "<<i<<endl;
		//cout<<"loop: "<<i<<" "<<ed[i].st<<endl;
		if(ed[i].st!=0) continue;
		
		if(uf.Find(ed[i].src, ed[i].dst)) {
			ed[i].st=NONE;
		} else {
			if(i==E-1 || ed[i].weight < ed[i+1].weight)
			{
				ed[i].st = ANY;
				uf.Union(ed[i].src, ed[i].dst);
				//cout<<"Union "<<ed[i].src<<" "<<ed[i].dst<<endl;
				continue;
			}
			//cout<<"Find loop..."<<endl;
			vector<PII> ne;
			map<PII, vector<Edge*> > n2o;
			
			//map<int, int> smallmap;
			int smallctr=0;
			//int smallclearctr=0;
			for(int j=i;j<E && ed[i].weight==ed[j].weight;j++) {
				if(!uf.Find(ed[j].src, ed[j].dst)) {
					int i0 = uf.root(ed[j].src);
					int i1 = uf.root(ed[j].dst);
					smallmap[i0] = -1;
					smallmap[i1] = -1;
				}
			}
			for(int j=i;j<E && ed[i].weight==ed[j].weight;j++) {
				if(!uf.Find(ed[j].src, ed[j].dst)) {
					int i0 = uf.root(ed[j].src);
					int i1 = uf.root(ed[j].dst);
					if(smallmap[i0]==-1) smallmap[i0] = smallctr++;
					i0 = smallmap[i0];
					if(smallmap[i1]==-1) smallmap[i1] = smallctr++;
					i1 = smallmap[i1];
					
					//cout<<" ud "<<ed[j].src<<" "<<ed[j].dst<<endl;
					//cout<<"    "<<i0<<" "<<i1<<endl;
					if(i0>i1) swap(i0, i1);
					ne.PB(MP(i0, i1));
					//cout<<"add "<<i0<<" "<<i1<<" "<<endl;
					n2o[MP(i0, i1)].PB(&ed[j]);
				}
			}
			REP(j, smallctr) {
				loopg[j].clear();
			}
			//cout<<" ne.size= "<<ne.size()<<endl;
			REP(j, ne.size()) {
				if(n2o[ne[j]].size()==1) n2o[ne[j]][0]->st=ANY;
				if(n2o[ne[j]].size()>1) {
					FOR(e, n2o[ne[j]]) {
						(*e)->st = ONE;
						//if(E==100) cout<<(*e)->idx<<" double edges"<<endl;
					}
				}
				FOR(e, n2o[ne[j]]) {
					uf.Union((*e)->src, (*e)->dst);
				}
			}
			//cout<<" union done"<<endl;
			make_graph_from_edge(ne, 0, loopg);
			//cout<<" graph create done"<<endl;
			VVI loops = get_loop_ud(loopg, smallctr);
			//cout<<" loops.size= "<<loops.size()<<endl;
			//cout<<"loops "<<loops<<endl;
			REP(j, loops.size()) {
				REP(k, loops[j].size()) {
					int i0 = loops[j][k];
					int i1 = loops[j][(k+1)%loops[j].size()];
					if(i0>i1) swap(i0, i1);
					//cout<<"map "<<i0<<" "<<i1<<" "<<n2o.count(MP(i0, i1))<<endl;
					if(n2o.count(MP(i0, i1))) {
						FOR(e, n2o[MP(i0, i1)]) {
							(*e)->st = ONE;
						}
					}
				}
			}
		}
	}
	//cout<<ed<<endl;
	sort(ALL(ed), CompareIndex());
	//cout<<ed<<endl;
	REP(i, ed.size()) {
		if(ed[i].st==NONE) cout<<"none"<<endl;
		if(ed[i].st==ANY) cout<<"any"<<endl;
		if(ed[i].st==ONE) cout<<"at least one"<<endl;
	}
	
	return 0;
}
