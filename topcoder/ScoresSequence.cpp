// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
A tournament is a directed graph on n vertices that can be obtained by taking an undirected complete graph on n vertices and assigning a direction to each edge.
The outdegree of a vertex is the number of directed edges that start at that vertex.
The score of a tournament is the list of the outdegrees of its vertices, in no particular order.



Alice used to have a tournament T but she lost it.
She only remembers its score.
You are given the score of T in the vector <int> s.



Determine and return the number of pairs of vertices (u,v) such that in the tournament T the vertex v was reachable from the vertex u.
Note that each vertex is reachable from itself.


You may assume that the answer can always be uniquely determined.


DEFINITION
Class:ScoresSequence
Method:count
Parameters:vector <int>
Returns:int
Method signature:int count(vector <int> s)


CONSTRAINTS
-s will contain between 1 and 100 elements, inclusive.
-s will be a valid score of some tournament.


EXAMPLES

0)
{2, 0, 1}

Returns: 6


There are three vertices. Let's call them A, B, and C, in the order in which they are mentioned in the score.
As the outdegree of A is 2, the tournament must contain the edges A -> B and A -> C.
As the outdegree of B is 0, the tournament must also contain the edge C -> B.



There are six pairs of vertices (u,v) such that there is a path from u to v.
These are the pairs (A,A), (B,B), (C,C), (A,B), (A,C), and (B,C).


1)
{1, 0, 2}

Returns: 6



2)
{1, 1, 1}

Returns: 9

This tournament must clearly be a cycle.
Hence, each vertex is reachable from each vertex.


3)
{0, 2, 8, 4, 3, 9, 1, 5, 7, 6}

Returns: 55



4)
{22,20,14,13,17,15,12,18,23,15,21,26,33,5,19,9,37,0,25,28,4,12,35,32,25,7,31,6,2,29,10,33,36,27,39,28,40,3,8,38,3}

Returns: 1422



*/
// END CUT HERE
#line 88 "ScoresSequence.cpp"

#include <vector>
#include <map>
#include <set>
#include <stack>
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
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


class Dinic {
public:
	struct Edge {
		int to, cap, rev;
	};
	int N;
	vector<vector<Edge>> g, orig;
	vector<int> level, iter;
	Dinic(int N) : N(N) {
		g = vector<vector<Edge>>(N);
		level = vector<int>(N);
		iter = vector<int>(N);
	}
	void add_edge(int from, int to, int cap) {
		g[from].push_back(Edge{to, cap, (int)g[to].size()});
		g[to].push_back(Edge{from, 0, (int)g[from].size()-1});
	}
	void bfs(int s) {
		level.assign(N, -1);
		queue<int> q;
		level[s] = 0;
		q.push(s);
		while(!q.empty()) {
			int v = q.front(); q.pop();
			for(int i=0;i<g[v].size(); i++) {
				Edge& e = g[v][i];
				if(e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
	}
	int dfs(int v, int t, int f) {
		if(v==t) return f;
		for(int& i=iter[v]; i<g[v].size(); i++) {
			Edge& e = g[v][i];
			if(e.cap > 0 && level[v] < level[e.to]) {
				int d = dfs(e.to, t, min(f, e.cap));
				if(d > 0) {
					e.cap -= d;
					g[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	int max_flow(int s, int t) {
		orig = g;
		int flow = 0;
		int INF = 1<<30;
		for(;;) {
			bfs(s);
			if(level[t] < 0) {
				REP(i, N) {
					REP(j, g[i].size()) {
						orig[i][j].cap = max(0, orig[i][j].cap - g[i][j].cap);
					}
				}
				return flow;
			}
			iter.assign(N, 0);
			int f;
			while((f=dfs(s, t, INF)) > 0) flow += f;
		}
		return -1;
	}
};
ostream& operator<<(ostream& os, const Dinic::Edge& e) {
	os<<"(Edge) to "<<e.to<<" cap "<<e.cap<<" rev "<<e.rev<<endl;
	return os;
}

void dinicTest() {
	// verified with:
	// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
	ll V, E, u, v, c;
	cin>>V>>E;
	Dinic d(V);
	REP(i, E) {
		cin>>u>>v>>c;
		d.add_edge(u, v, c);
	}
	DD(d.g);
	ll ans = d.max_flow(0, V-1);
	cout<<ans<<endl;
	DD(d.level);
	DD(d.iter);
	DD(d.g);
	DD(d.orig);
	// d.orig[i][j].cap ... flow in node i -> d.orig[i][j].to
//	REP(i, d.g.size()) {
//		for(auto& e : d.g[i]) {
//			DD(e);
//		}
//	}
}

class ScoresSequence {
	public:
	vector<int> t;
	int count(vector <int> s) {
		ll INF = 1LL<<60;
		int N = s.size();

		// Check by Landau's Theorem
		{
			sort(ALL(s));
			RANGE(i, 1, N) {
				if(accumulate(s.begin(), s.begin()+i, 0) < i*(i-1)/2) return -1;
			}
			if(accumulate(ALL(s), 0) != N*(N-1)/2) return -1;
		}

		sort(ALL(s));
//		DD(N);
//		DD(s);
		ll ans = 0;
		ll sum = 0;
		ll last = -1;
		REP(i, N) {
			sum += s[i];
			ll inside = i*(i+1)/2;
			if(sum==inside) {
				// sc 発見 (なぜ?)
				// outboundがここまでの頂点数と一致したらそれより右には出てるはずがない。
				// 一方右から左は基本行けるのでscとなる
				// 一致しなければ右のどこかに行けるはず。直近の右に行くのか？一番右に行くのか？で変わりそうだけど...
				ll sc = i-last;
//				DD(i);
//				DD(sc);
				ans += sc*sc;
//				DD(N-1-i);
				ans += (N-1-i)*sc;
				last=i;
			}
//			DD(ans);
//			ans += sc*(N-i-sc); // のこり全部への辺
//			DD(ans);
//			i += sc-1;
		}
		return ans;
	}
};



class ScoresSequenceFlow {
	public:
	vector<int> t;
	int count(vector <int> s) {
		ll INF = 1LL<<60;
		int N = s.size();

		// Check by Landau's Theorem
		{
			sort(ALL(s));
			RANGE(i, 1, N) {
				if(accumulate(s.begin(), s.begin()+i, 0) < i*(i-1)/2) return -1;
			}
			if(accumulate(ALL(s), 0) != N*(N-1)/2) return -1;
		}

		int M = N*N;
		Dinic d(M+N+2);
		ll si = M+N;
		ll ei = si+1;
		REP(i, M) d.add_edge(si, i, 1);
		REP(from, N) REP(to, N) if(from<to) {
			d.add_edge(from*N+to, M+from, 1);
			d.add_edge(from*N+to, M+to, 1);
		}
		REP(i, N) d.add_edge(M+i, ei, N-1-s[i]);
		ll flow = d.max_flow(si, ei);
		assert(flow==N*(N-1)/2);
//		DD(d.orig);
		VVI w(N, VI(N));
		REP(from, N) REP(to, N) {
			int mi = from*N+to;
			REP(j, d.orig[mi].size()) {
				int dst = d.orig[mi][j].to;
				dst-=M;
				if(0<=dst && dst<N) {
//					DD(from);
//					DD(to);
//					DD(dst);
					if(d.orig[mi][j].cap) {
						// edge of vertices from and to : direction is to dst
						int src = from==dst ? to : from;
//						cout<<" "<<src<<" -> "<<dst<<endl;
						w[src][dst] = 1;
						w[dst][src] = INF;
					}
				}
			}
		}

//		DD(w);
		{
			vector<int> ss(N);
			REP(i, N) REP(j, N) if(i!=j) if(w[i][j]<INF) ss[i]++;
//			DD(ss);
			assert(s==ss);
		}
		REP(k, N) REP(i, N) REP(j, N) w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
//		DD(w);
		ll ans = 0;
		REP(i, N) REP(j, N) if(w[i][j]<INF) ans++;
		return ans;
	}
};


class ScoresSequenceGreedy {
	public:
	vector<int> t;
	int count(vector <int> s) {
		int N = s.size();
		sort(ALL(s));
//		DD(1);
//		DD(s);
		ll INF = 1LL<<60;
		VVI w(N, VI(N));
		REP(i, N) {
			ll cnt = 0;
			REP(j, N) if(i!=j) {
				if(w[i][j]==1) cnt++;
				else if(w[i][j]==0) {
					if(cnt<s[i]) {
						w[i][j] = 1;
						w[j][i] = INF;
					} else {
						w[i][j] = INF;
						w[j][i] = 1;
					}
					cnt++;
				}
			}
		}
//		DD(w);
		{
			vector<int> ss(N);
			REP(i, N) REP(j, N) if(i!=j) if(w[i][j]<INF) ss[i]++;
//			DD(ss);
			assert(s==ss);
		}
		REP(k, N) REP(i, N) REP(j, N) w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
//		DD(w);
		ll ans = 0;
		REP(i, N) REP(j, N) if(w[i][j]<INF) ans++;
		return ans;
	}
};

class ScoresSequenceRef {
	public:
	int count(vector <int> s) {
		int N = s.size();
		sort(ALL(s));
		int res = N*N;
		int sum = 0;
		int skipped = 0;
		REP(i, N) {
			sum += s[i];
			int inside = i*(i+1)/2;
			assert(sum>=inside);
			if(sum==inside) {
				res -= (i+1-skipped)*(N-1-i);
				skipped = i+1;
			}
		}
		return res;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, ScoresSequence().count(s));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

//dinicTest();
//return 0;

CASE(0)
	int s_[] = {2, 0, 1};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 6; 
END
//return 0;
CASE(0)
	int s_[] = {5, 4, 4, 1, 1, 0};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = -1; 
END

//return 0;
CASE(1)
	int s_[] = {1, 0, 2};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 6; 
END
CASE(2)
	int s_[] = {1, 1, 1};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 9; 
END
CASE(3)
	int s_[] = {0, 2, 8, 4, 3, 9, 1, 5, 7, 6};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 55; 
END
//return 0;
CASE(4)
	int s_[] = {22,20,14,13,17,15,12,18,23,15,21,26,33,5,19,9,37,0,25,28,4,12,35,32,25,7,31,6,2,29,10,33,36,27,39,28,40,3,8,38,3};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int _ = 1422; 
END
#if 01  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10000;loop++) {
// param type: int
	vector <int> s; 
	{
		int N=UNIFORM_LL(1, 51);
		ll inf = 1LL<<60;
		VVI w(N, VI(N, inf));
		s = vector <int>(N); 
		REP(i, N) REP(j, N) if(i<j) {
			if(UNIFORM_LL(0, 1000) < 500) {
				s[i]++;
			} else {
				s[j]++;
			}
		}
		DD(s);
	}
	int _0 = ScoresSequence().count(s);
	int _1 = ScoresSequenceRef().count(s);
	if(!verify_case(_0, _1, true)) {
DD("wa");
print(s);
	}
}
#endif

}
// END CUT HERE
