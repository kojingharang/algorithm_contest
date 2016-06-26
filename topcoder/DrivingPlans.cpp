// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// You live in a city with N intersections, numbered 1 through N. There are some roads in the city. Each road is bidirectional and connects two intersections. There are no loops and each pair of intersections is connected by at most one road. The road network is connected - that is, one can travel between any two intersections.

A special feature of this city is that some of the roads have no speed limits, and everyone drives along those roads at an insane speed. For the purpose of this problem, we will simply assume that these roads can be traversed instantly, in zero time.

You are given the int N and three vector <int>s A, B, and C, each with the same number of elements. The vector <int>s A, B, and C describe the road network: For each valid i, there is a bidirectional road that connects the intersections A[i] and B[i], and it takes C[i] seconds to traverse that road in either direction.

You are currently at the intersection 1 and you want to travel to the intersection N as quickly as possible. Count all ways of doing so, and return that count modulo 1,000,000,009. If there are infinitely many ways, return -1 instead. (Two ways are considered different if the sequences of visited intersections differ. Note that it is allowed to enter any intersection, including intersections 1 and N, multiple times.)

DEFINITION
Class:DrivingPlans
Method:count
Parameters:int, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int count(int N, vector <int> A, vector <int> B, vector <int> C)


CONSTRAINTS
-N will be between 2 and 2,000, inclusive.
-A, B and C will contain between 1 and 2,000 elements, inclusive.
-A, B and C will contain the same number of elements.
-Each element of A and B will be between 1 and N, inclusive.
-Each element of C will be between 0 and 100,000, inclusive.
-For each valid i, A[i] will be different from B[i].
-No two roads will connect the same pair of intersections.
-The road network will be connected.


EXAMPLES

0)
4
{1,1,2,3}
{2,3,4,4}
{1,1,1,1}

Returns: 2

There are exactly two shortest ways of travel: 1-2-4 and 1-3-4.

1)
4
{1,1,2,3}
{2,3,4,4}
{1,1,1,0}

Returns: -1

Remember that each road can be used in both directions. In this case, there are infinitely many ways how to reach the intersection 4 in shortest time. For example, you can go 1-2-4, or 1-2-4-3-4, or 1-2-4-3-4-3-4, etc.

2)
7
{1,1,2,3,4,4,5,6}
{2,3,4,4,5,6,7,7}
{1,1,2,2,3,3,4,4}

Returns: 4



******************************/
// END CUT HERE
#line 66 "DrivingPlans.cpp"
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

struct Dijkstra {
    struct edge{int to,cost;};
    vector<vector<edge> > G;
    vector<ll> V;
    Dijkstra(int N) {
        G = vector<vector<edge> >(N);
        V = vector<ll>(N, 1<<30);
    }
    void add_edge(int v0, int v1, int cost) {
        if(v0<G.size() && v1<G.size()) G[v0].PB((edge){v1, cost});
    }
    int run(int S, int E) {
        V[S]=0;
        priority_queue<PII> q;
        q.push(make_pair(0, S));
        while(q.size()) {
            PII el = q.top(); q.pop();
            if(el.second==E) break;
            if(-el.first > V[el.second]) continue;
            for(int i=0;i<(int)G[el.second].size();i++){
                const edge& e=G[el.second][i];
                if(V[e.to]>V[el.second]+e.cost){
                    V[e.to]=V[el.second]+e.cost;
                    q.push(make_pair(-V[e.to], e.to));
                }
            }
        }
        if(E<0) return -1;
        return V[E]==1<<30?-1:V[E];
    }
};

class DrivingPlans {
	public:
	int count(int N, vector <int> A, vector <int> B, vector <int> C) {
		int M = A.size();
		Dijkstra d(N), r(N);
		REP(i, M) {
			d.add_edge(A[i]-1, B[i]-1, C[i]);
			d.add_edge(B[i]-1, A[i]-1, C[i]);
		}
		r=d;
		int co = d.run(0, N-1);
		r.run(N-1, 0);
		
		cout<<co<<endl;
		vector<PII> p(N);
		REP(i, N) p[i]=MP(d.V[i], i);
		sort(ALL(p));
//		cout<<p<<endl;
//		cout<<d.V<<endl;
//		cout<<r.V<<endl;
		VI ways(N);
		ways[0] = 1;
		REP(i, N) {
			int from = p[i].second;
			REP(j, d.G[from].size()) {
				int to=d.G[from][j].to;
//				if(d.V[from] == co - r.V[from] && d.V[to] == co - r.V[to] && d.V[from] + d.G[from][j].cost == d.V[to]) {
				if(d.V[from] + d.G[from][j].cost + r.V[to] == co) {
//					cout<<from<<" --> "<<to<<endl;
					ways[to] += ways[from];
					ways[to] %= 1000000009;
					REP(k, d.G[from].size()) if(d.G[from][k].cost==0) return -1;
					REP(k, d.G[to].size()) if(d.G[to][k].cost==0) return -1;
				}
			}
		}
//		cout<<ways<<endl;
		return ways[N-1];
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
#define END	 verify_case(_, DrivingPlans().count(N, A, B, C));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){
CASE(0)
	int N = 4; 
	int A_[] = {1, 1, 2};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {4, 2, 3};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {1, 1, 0};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	int _ = 1; 
END
CASE(0)
	int N = 3; 
	int A_[] = {1, 2};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {3, 3};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {1, 0};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	int _ = -1; 
END
CASE(0)
	int N = 4; 
	int A_[] = {1, 4, 3};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {4, 3, 2};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {1, 1, 0};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	int _ = 1; 
END
CASE(0)
	int N = 4; 
	int A_[] = {1,1,2,3};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,3,4,4};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {1,1,1,1};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	int _ = 2; 
END
//return 0;
CASE(1)
	int N = 4; 
	int A_[] = {1,1,2,3};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,3,4,4};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {1,1,1,0};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	int _ = -1; 
END
CASE(2)
	int N = 7; 
	int A_[] = {1,1,2,3,4,4,5,6};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,3,4,4,5,6,7,7};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	int C_[] = {1,1,2,2,3,3,4,4};
	  vector <int> C(C_, C_+sizeof(C_)/sizeof(*C_)); 
	int _ = 4; 
END
#if 0  // DO RANDOM TESTS

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
for(int loop=0;loop<100;loop++) {
// param type: int
	int N = UNIFORM_LL(0, 100); 
// param type: int
	vector <int> A; 
	{
		int N=UNIFORM_LL(1, 51);
		A = vector <int>(N); 
		REP(i, N) {
			A[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> B; 
	{
		int N=UNIFORM_LL(1, 51);
		B = vector <int>(N); 
		REP(i, N) {
			B[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> C; 
	{
		int N=UNIFORM_LL(1, 51);
		C = vector <int>(N); 
		REP(i, N) {
			C[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = DrivingPlans().count(N, A, B, C);
	int _1 = DrivingPlansRef().count(N, A, B, C);
	if(!verify_case(_0, _1, true)) {
print(N);
print(A);
print(B);
print(C);
	}
}
#endif

}
// END CUT HERE
