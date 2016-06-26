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
#include <cstdio>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
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
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[x][y]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


int main() {
    int N, M, v;
        while(scanf("%d %d", &N, &M) != -1) {
                VI w(N);
                VI prev(N, -1);
                REP(i, N) scanf("%d", &w[i]);
                sort(ALL(w));
                int latest_prev = -1;
                RANGE(i, 1, N) {
                        if(w[i]!=w[i-1]) latest_prev=i-1;
                        prev[i] = latest_prev;
                }
//              cout<<w<<endl;
//              cout<<prev<<endl;
                REP(i, M) {
                        scanf("%d", &v);
                        int ans = 0;
                        // k<j and w[k] + w[j] <= v
                        int j = distance(w.begin(), upper_bound(ALL(w), v-10))-1;
                        // j==-1 ... w[kk] is too big -> give up
                        // j==N ... w[kk] is too small -> give up because w[j] is getting smaller.
                        // w[j] <= v-10
                        int k_min = 0;
//                      cout<<"j "<<j<<endl;
//                      cout<<"w "<<w<<endl;
                        if(0<=j && j<N) {
                                while(1) {
                                        int k = distance(&w[0], upper_bound(&w[k_min], &w[j], v-w[j]))-1;
                                        // k==k_min-1 ... w[kk] is too big for kk in [k_min, j) -> skip for j
                                        // k==j ... w[kk] is too small for kk in [k_min, j) -> give up since no j exist because w[j] is getting smaller.
                                        // w[k] <= v-w[j]
//                                      cout<<"jk "<<j<<" "<<k<<" "<<k_min<<endl;
                                        if(k==j) break;
                                        if(k_min<=k) {
                                                int sum=w[j]+w[k];
                                                if(v-sum < v-ans) {
													ans = sum;
													if(v-ans==0) break;
												}
                                                k_min = k+1;
                                        }
                                        j = prev[j];
                                        while(j<=k_min && w[k_min]+w[j] > v) j = prev[j]; // skip until w[k_min]+w[j] <= v
//                                      while(j-1>=k_min && w[j]==w[j-1]) j--;
                                        if(j<=k_min) break;


                                }
                        }
                        printf("%d\n", ans);
                }
        }

        return 0;
}
