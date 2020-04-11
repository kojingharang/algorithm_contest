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
#include <functional>
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

#define MOD 1000000007LL
#define INF (1LL<<60)

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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,M;
	string s;
	while(cin>>N>>M) {
		VI A(N);
		using T = priority_queue<int, vector<int>, greater<int>>;
		UnionFind uf(N);
		REP(i, N) {
			cin>>A[i];
		}
		REP(i, M) {
			ll a, b;
			cin>>a>>b;
			uf.Union(a, b);
		}
		vector<PII> w(N);
		REP(i, N) {
			w[i] = MP(A[i], uf.root(i));
		}
		ll add = (N-M-1)*2;
		sort(ALL(w));
		VI used(N);
		VI used2(N);
		vector<PII> use;
		REP(i, N) {
			ll a, idx;
			tie(a, idx) = w[i];
			if(!used[idx] && use.size()<add) {
				used[idx] = 1;
				used2[i]=1;
				use.PB(w[i]);
			}
		}
		ll ans = 0;
		if(add < use.size()) {
			ans=-1;
		} else {
			REP(i, N) {
				ll a, idx;
				tie(a, idx) = w[i];
				if(!used2[i] && used[idx] && use.size() < add) {
					use.PB(w[i]);
				}
			}
			if(use.size() < add) {
				ans=-1;
			} else {
				vector<T> qs(N);
				REP(i, use.size()) {
					ll a, idx;
					tie(a, idx) = use[i];
					qs[idx].push(a);
				}
				auto c = [](const T& a, const T& b) {
					return a.size() < b.size();
				};
				priority_queue<T, vector<T>, decltype(c)> mq(c);
				REP(i, N) {
					if(qs[i].size()) mq.push(qs[i]);
				}
				while(mq.size()>1) {
					auto a = mq.top();
					mq.pop();
					auto b = mq.top();
					mq.pop();
					ans += a.top() + b.top();
					a.pop(); b.pop();
					while(b.size()) {
						a.push(b.top());
						b.pop();
					}
					mq.push(a);
				}
			}
		}
		if(ans==-1) cout<<"Impossible"<<endl;
		else cout<<ans<<endl;
	}
	
	return 0;
}
