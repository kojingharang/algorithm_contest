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
#include <cassert>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cstdio>
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

bool check(vector<string>& w, int x1, int y1) {
    int N=w.size();
    w[x1][y1]='O';
    REP(x0, N) REP(y0, N) {
        if(x1==x0 || y1==y0) continue;
        int cnt=0;
        cnt += w[x0][y0]=='.';
        cnt += w[x0][y1]=='.';
        cnt += w[x1][y0]=='.';
        cnt += w[x1][y1]=='.';
        if(cnt==0) {
            w[x1][y1]='.';
            return false;
        }
    }
    return true;
}

bool checkAll(vector<string>& w) {
    int N=w.size();
    REP(x0, N) REP(y0, N) RANGE(x1, x0+1, N) RANGE(y1, y0+1, N) {
        int cnt=0;
        cnt += w[x0][y0]=='.';
        cnt += w[x0][y1]=='.';
        cnt += w[x1][y0]=='.';
        cnt += w[x1][y1]=='.';
        if(cnt==0) return false;
    }
    return true;
}

int main() {
	//ios::sync_with_stdio(false);
	ll N=150;
    srand(time(NULL));
    vector<string> w(N, string(N, '.'));
    int mode=0;
	REP(loop, 500000) {
        if(loop%1000==0) mode=(mode+1)%9;
        int X = mode%3*50;
        int Y = mode/3*50;
        int x = UNIFORM_LL(X, X+50);
        int y = UNIFORM_LL(Y, Y+50);
        if(check(w, x, y)) w[x][y]='O';
    }
    
    assert(checkAll(w));
    int cnt=0;
    REP(i, N) cnt+=count(ALL(w[i]), 'O');
    cerr<<cnt<<endl;
    
    cout<<N<<endl;
    REP(i, N) cout<<w[i]<<endl;
	return 0;
}






