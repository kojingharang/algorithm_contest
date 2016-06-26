// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are very happy because you advanced to the next round of a very important programming contest.
You want your best friend to know how happy you are.
Therefore, you are going to send him a lot of smile emoticons.
You are given an int smiles: the exact number of emoticons you want to send.

You have already typed one emoticon into the chat.
Then, you realized that typing is slow.
Instead, you will produce the remaining emoticons using copy, paste, and possibly some deleting.

You can only do three different operations:

Copy all the emoticons you currently have into the clipboard.
Paste all emoticons from the clipboard.
Delete one emoticon from the message.

Each operation takes precisely one second.
Copying replaces the old content of the clipboard.
Pasting does not empty the clipboard.
You are not allowed to copy just a part of the emoticons you already have.
You are not allowed to delete an emoticon from the clipboard.

Return the smallest number of seconds in which you can turn the one initial emoticon into smiles emoticons.

DEFINITION
Class:EmoticonsDiv1
Method:printSmiles
Parameters:int
Returns:int
Method signature:int printSmiles(int smiles)


CONSTRAINTS
-smiles will be between 2 and 1000, inclusive.


EXAMPLES

0)
2

Returns: 2

First use copy, then use paste. The first operation copies one emoticon into the clipboard, the second operation pastes it into the message, so now you have two emoticons and you are done.

1)
4

Returns: 4

One optimal solution is to copy the initial emoticon and then to paste it three times. Another optimal solution is to copy the one emoticon, paste it, copy the two emoticons you currently have, and paste two more.

2)
6

Returns: 5


Copy. This puts one emoticon into the clipboard.
Paste. You now have 2 emoticons in the message.
Copy. The clipboard now contains 2 emoticons.
Paste. You now have 4 emoticons in the message.
Paste. You now have 6 emoticons in the message and you are done.


3)
18

Returns: 8



4)
11

Returns: 8

Sometimes we actually do delete an emoticon in the optimal solution.

*/
// END CUT HERE
#line 85 "EmoticonsDiv1.cpp"

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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

int Ans[] = {
1, 0, 2, 3, 4, 5, 5, 7, 6, 6, 7, 8, 7, 10, 9, 8, 8, 9, 8, 10, 9, 10, 10, 10, 9, 10, 10, 9, 11, 11, 10, 11, 10, 11, 11, 11, 10, 13, 12, 12, 11, 13, 12, 13, 12, 11, 12, 12, 11, 13, 12, 12, 12, 12, 11, 13, 13, 13, 13, 13, 12, 14, 13, 13, 12, 14, 13, 14, 13, 13, 13, 13, 12, 15, 14, 13, 14, 14, 13, 14, 13, 12, 15, 15, 14, 14, 15, 14, 14, 14, 13, 15, 14, 14, 14, 14, 13, 16, 15, 14, 14, 15, 14, 15, 14, 14, 14, 14, 13, 16, 15, 16, 15, 16, 15, 15, 15, 15, 15, 15, 14, 17, 16, 16, 15, 15, 15, 15, 14, 16, 15, 16, 15, 16, 15, 14, 15, 16, 15, 16, 15, 15, 15, 15, 14, 16, 17, 16, 16, 16, 15, 17, 16, 15, 16, 16, 15, 17, 16, 15, 15, 15, 14, 18, 17, 16, 17, 17, 16, 17, 16, 16, 17, 17, 16, 16, 16, 16, 16, 16, 15, 18, 17, 17, 16, 17, 16, 17, 16, 16, 16, 16, 15, 19, 18, 17, 17, 17, 16, 17, 16, 17, 17, 17, 16, 18, 17, 16, 16, 17, 16, 17, 16, 16, 16, 16, 15, 18, 18, 18, 17, 18, 17, 18, 17, 16, 18, 18, 17, 18, 17, 17, 17, 17, 16, 17, 17, 17, 17, 17, 16, 17, 16, 15, 18, 18, 18, 18, 17, 18, 17, 18, 17, 18, 17, 17, 16, 19, 18, 18, 17, 17, 18, 18, 17, 17, 18, 17, 17, 17, 16, 18, 17, 18, 18, 18, 17, 19, 18, 17, 17, 18, 17, 18, 17, 17, 17, 17, 16, 19, 18, 19, 19, 19, 18, 18, 18, 17, 18, 18, 17, 20, 19, 18, 18, 18, 17, 19, 18, 18, 18, 18, 17, 19, 18, 17, 18, 18, 17, 18, 17, 17, 17, 17, 16, 19, 20, 19, 19, 19, 18, 20, 19, 19, 19, 19, 18, 20, 19, 19, 18, 19, 18, 20, 19, 18, 19, 19, 18, 19, 18, 18, 18, 19, 18, 18, 18, 18, 18, 18, 17, 21, 20, 20, 19, 20, 19, 19, 18, 19, 19, 19, 18, 20, 19, 18, 18, 19, 18, 19, 18, 18, 18, 18, 17, 19, 20, 19, 20, 19, 18, 20, 19, 19, 19, 19, 18, 20, 19, 19, 18, 19, 18, 19, 18, 17, 19, 19, 18, 21, 20, 19, 19, 19, 18, 19, 18, 19, 19, 19, 18, 20, 19, 18, 18, 19, 18, 19, 18, 18, 18, 18, 17, 21, 20, 19, 20, 21, 20, 20, 19, 19, 20, 20, 19, 19, 20, 19, 19, 19, 18, 21, 20, 20, 20, 20, 19, 20, 19, 18, 19, 20, 19, 20, 19, 19, 19, 19, 18, 20, 19, 20, 19, 20, 19, 19, 19, 18, 19, 19, 18, 20, 19, 18, 18, 18, 17, 21, 20, 21, 20, 21, 20, 21, 20, 19, 19, 20, 20, 20, 19, 20, 20, 20, 19, 20, 20, 20, 19, 20, 19, 19, 18, 19, 21, 20, 20, 21, 20, 20, 19, 20, 19, 21, 20, 19, 20, 20, 19, 20, 19, 19, 20, 20, 19, 19, 19, 19, 19, 19, 18, 21, 20, 20, 19, 21, 20, 21, 20, 20, 20, 20, 19, 21, 21, 20, 20, 20, 19, 20, 19, 20, 20, 20, 19, 21, 20, 19, 19, 20, 19, 20, 19, 19, 19, 19, 18, 22, 21, 21, 20, 22, 21, 22, 21, 20, 21, 21, 20, 21, 20, 20, 20, 20, 19, 20, 20, 20, 20, 20, 19, 22, 21, 20, 21, 21, 20, 21, 20, 20, 20, 20, 19, 22, 21, 21, 20, 21, 20, 21, 20, 19, 20, 20, 19, 20, 21, 20, 20, 20, 19, 21, 20, 20, 20, 20, 19, 21, 20, 19, 19, 20, 19, 20, 19, 19, 19, 19, 18, 21, 20, 21, 22, 22, 21, 21, 21, 21, 21, 21, 20, 23, 22, 21, 21, 21, 20, 22, 21, 21, 20, 21, 20, 21, 20, 19, 21, 22, 21, 21, 20, 21, 21, 21, 20, 21, 22, 21, 21, 21, 20, 22, 21, 20, 21, 21, 20, 22, 21, 20, 20, 20, 19, 21, 20, 20, 21, 21, 20, 21, 20, 20, 20, 21, 20, 20, 20, 20, 20, 20, 19, 22, 21, 20, 21, 20, 19, 20, 19, 18, 22, 22, 21, 22, 21, 21, 20, 22, 21, 22, 21, 21, 21, 21, 20, 21, 22, 21, 21, 21, 20, 21, 20, 21, 21, 21, 20, 22, 21, 21, 20, 21, 20, 21, 20, 20, 20, 20, 19, 22, 21, 22, 22, 22, 21, 21, 22, 21, 21, 21, 20, 22, 21, 20, 21, 22, 21, 22, 21, 21, 21, 21, 20, 22, 21, 20, 21, 22, 21, 21, 20, 20, 21, 21, 20, 20, 21, 20, 20, 20, 19, 22, 21, 21, 21, 21, 20, 23, 22, 21, 22, 22, 21, 22, 21, 21, 21, 21, 20, 22, 21, 21, 20, 22, 21, 22, 21, 20, 21, 21, 20, 23, 22, 21, 21, 21, 20, 21, 20, 21, 21, 21, 20, 22, 21, 20, 20, 21, 20, 21, 20, 20, 20, 20, 19, 22, 23, 22, 22, 22, 21, 23, 22, 22, 22, 21, 22, 23, 22, 22, 21, 22, 21, 23, 22, 21, 22, 22, 21, 22, 21, 20, 22, 22, 21, 21, 21, 21, 21, 21, 20, 24, 23, 23, 22, 23, 22, 23, 22, 21, 22, 22, 21, 23, 22, 21, 21, 21, 20, 22, 21, 22, 22, 22, 21, 22, 22, 21, 21, 22, 21, 22, 21, 21, 21, 21, 20, 23, 22, 22, 21, 22, 21, 22, 21, 20, 22, 22, 21, 22, 21, 21, 21, 21, 20, 21, 21, 21, 21, 21, 20, 22, 21, 20, 21, 21, 20, 21, 20, 20, 20, 20, 19, 23, 23, 22, 22, 24, 23, 23, 22, 22, 23, 23, 22, 22, 23, 22, 22, 22, 21, 22, 21, 23, 22, 22, 22, 23, 22, 22, 21,
};


struct Dijkstra {
    struct edge{int to,cost;};
    vector<vector<edge> > G;
    vector<int> V;
    Dijkstra(int N) {
        G = vector<vector<edge> >(N);
        V = vector<int>(N, 1<<30);
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


int dp[2][1050][1050];
class EmoticonsDiv1 {
	public:
    int f(int N) {
        int n=N+30;
        int V=n*n;
        Dijkstra d(V);
        // have, clipboard
        REP(i, n) REP(j, n) {
            d.add_edge(i*n+j, i*n+i, 1); // copy
            d.add_edge(i*n+j, (i+j)*n+j, 1); // paste
            d.add_edge(i*n+j, (i-1)*n+j, 1); // delete
        }
        d.run(1*n+0, -1);
        int ans=1<<30;
        REP(j, N+1) ans=min(ans, d.V[N*n+j]);
        return ans;
    }
    int g(int N) {
        int M=N+40;
        REP(k, 2) REP(i, M) REP(j, M) dp[k][i][j]=1<<30;
        int men=0;
        dp[men][1][0]=0;
        REP(k, 30) {
            REP(i, M) REP(j, M) {
                MIN_UPDATE(dp[men^1][i][j], dp[men][i][j]);
                MIN_UPDATE(dp[men^1][i][i], dp[men][i][j]+1);
                if(i+j<M) MIN_UPDATE(dp[men^1][i+j][j], dp[men][i][j]+1);
            }
            men^=1;
            RANGE_R(i, 0, M) REP(j, M) {
                MIN_UPDATE(dp[men^1][i][j], dp[men][i][j]);
                if(i>0) MIN_UPDATE(dp[men^1][i-1][j], dp[men][i][j]+1);
            }
            men^=1;
        }
//        PRINT2(dp[men], M, M);
        int ans=1<<30;
        REP(j, M) MIN_UPDATE(ans, dp[men][N][j]);
        return ans;
    }
	int printSmiles(int N) {
//        REP(i, 1001) assert(g(N)==Ans[N]);
        return g(N);
        return f(N);
        return Ans[N];
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
#define END	 verify_case(_, EmoticonsDiv1().printSmiles(smiles));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){
//EmoticonsDiv1().f(1000);
//return 0;

CASE(4)
	int smiles = 1000; 
	int _ = 21; 
END
CASE(4)
	int smiles = 768; 
	int _ = 19; 
END
//return 0;
CASE(0)
	int smiles = 2; 
	int _ = 2; 
END
//return 0;
CASE(1)
	int smiles = 4; 
	int _ = 4; 
END
CASE(2)
	int smiles = 6; 
	int _ = 5; 
END
CASE(3)
	int smiles = 18; 
	int _ = 8; 
END
CASE(4)
	int smiles = 11; 
	int _ = 8; 
END
CASE(4)
	int smiles = 33; 
	int _ = 11; 
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
	int smiles = UNIFORM_LL(0, 100); 
	int _0 = EmoticonsDiv1().printSmiles(smiles);
	int _1 = EmoticonsDiv1Ref().printSmiles(smiles);
	if(!verify_case(_0, _1, true)) {
print(smiles);
	}
}
#endif

}
// END CUT HERE
