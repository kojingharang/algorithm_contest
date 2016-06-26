/*
// BEGIN CUT HERE
// PROBLEM STATEMENT
// A binary matrix is a matrix in which each element is either 0 or 1. There is a secret binary matrix with R rows and C columns. Your task is to determine its elements from two partial descriptions.

The first description is given as a vector <string> rows with R elements. Each element of rows will be a string of C characters. Element i of rows describes the i-th row of the secret matrix. Each character in each element of rows is either '0', '1', or '?'. The meaning of '?' is that the corresponding element of the matrix may be either 0 or 1.

The second description is given as a vector <string> columns with C elements. Each element of columns will be a string of R characters. Each element of columns describes one column of the secret matrix. Different elements of columns represent different columns, but not necessarily in the correct order. Again, each character in each element of columns is either '0', '1', or '?'.

You may assume that there is at least one binary matrix that corresponds to both descriptions: its rows match the elements of rows (in the same order) and its columns match the elements of columns (after a suitable permutation is applied on columns). Your method must find the lexicographically smallest of all such matrices. Return that matrix formatted as a vector <string>.

DEFINITION
Class:P8XMatrixRecovery
Method:solve
Parameters:vector <string>, vector <string>
Returns:vector <string>
Method signature:vector <string> solve(vector <string> rows, vector <string> columns)


NOTES
-Given two different matrices A and B, let i be the first row on which they differ, and let j be the first element in that row on which they differ. If A[i,j] &lt B[i,j], we say that A is lexicographically smaller than B, and vice versa.


CONSTRAINTS
-rows will contain between 1 and 30 elements, inclusive.
-Each element of rows will contain between 1 and 30 characters, inclusive.
-All the elements of rows will contain the same number of character.
-Each character in each element of rows will be either '0', '1', or '?'.
-columns will contain exactly C elements, where C is the number of elements in rows[0].
-Each element of columns will contain exactly R characters, where R is the number of elements in rows.
-Each character in each element of columns will be '0', '1', or '?'.
-There will be at least one binary matrix that corresponds to both rows and columns in the way described in the problem statement.


EXAMPLES

0)
{"10?"
,"?11"}
{"01"
,"10"
,"1?"}


Returns: {"101", "011" }

Note that columns[0] describes column 1 of the secret matrix, columns[1] describes column 0 and columns[2] describes column 2.

1)
{"0"
,"?"
,"1"}
{"0?1"}

Returns: {"0", "0", "1" }

There are two matrices that match both descriptions. We return the lexicographically smaller one.

2)
{"10"
,"01"}
{"10"
,"01"}

Returns: {"10", "01" }



3)
{"??0"
,"11?"
,"?01"
,"1?1"}
{"1???"
,"?111"
,"0?1?"}

Returns: {"010", "110", "101", "101" }



// END CUT HERE
#line 83 "P8XMatrixRecovery.cpp"
*/
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
using namespace std;

#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

/////////////////////// maximumFlow
#define INF 1000000
typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Weight maximumFlow(const Graph &g, int s, int t) {
  int n = g.size();
  Matrix flow(n, Array(n)), capacity(n, Array(n));
  REP(u,n) FOR(e,g[u]) capacity[e->src][e->dst] += e->weight;

  Weight total = 0;
  while (1) {
    queue<int> Q; Q.push(s);
    vector<int> prev(n, -1); prev[s] = s;
    while (!Q.empty() && prev[t] < 0) {
      int u = Q.front(); Q.pop();
      FOR(e,g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
        prev[e->dst] = u;
        Q.push(e->dst);
      }
    }
    if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
    Weight inc = INF;
    for (int j = t; prev[j] != j; j = prev[j])
      inc = min(inc, RESIDUE(prev[j], j));
    for (int j = t; prev[j] != j; j = prev[j])
      flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
    VI path;
    for (int j = t; prev[j] != j; j = prev[j]) path.push_back(j);
    path.push_back(s);
    reverse(ALL(path));
    total += inc;
    //cout<<"Update "<<path<<" -> total "<<total<<endl;
  }
}
void add_edge(Graph& g, int s, int e, int w) {
	g[s].push_back(Edge(s, e, w));
	g[e].push_back(Edge(e, s, 0));
}
/////////////////////// maximumFlow

class P8XMatrixRecovery {
	public:
	vector <string> solve(vector <string> rows, vector <string> col) {
		int R = rows.size();
		int C = rows[0].size();
		REP(yy, R) {
			REP(xx, C) {
				if(rows[yy][xx]!='?') continue;
				rows[yy][xx] = '0';
				int t = C*2+2-1;
				//cout<<"BEGIN "<<xx<<" "<<yy<<endl;
				Graph g(C*2+2, Edges());
				REP(x, C) add_edge(g, 0, 1+x, 1);
				REP(x, C) add_edge(g, 1+C+x, t, 1);
				REP(x, C)
				REP(x1, C) {
					int ee = 1;
					REP(y, R) {
						//cout<<rows[y][x]<<" "<<col[x1][y]<<endl;
						if(rows[y][x]=='?' || col[x1][y]=='?' || rows[y][x]==col[x1][y]) {
						} else ee=0;
					}
					if(ee) add_edge(g, 1+x, 1+C+x1, 1);
				}
				if(C!=maximumFlow(g, 0, t)) {
					rows[yy][xx] = '1';
				}
				//cout<<"RESULT "<<rows[yy][xx]<<endl;
			}
		}
		return rows;
	}
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"10?"
,"?11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"01"
,"10"
,"1?"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"101", "011" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0"
,"?"
,"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0?1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0", "0", "1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"10"
,"01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10"
,"01"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"10", "01" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"??0"
,"11?"
,"?01"
,"1?1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1???"
,"?111"
,"0?1?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"010", "110", "101", "101" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  P8XMatrixRecovery ___test;
  ___test.run_test(-1);
  //___test.run_test(0);
}
// END CUT HERE
