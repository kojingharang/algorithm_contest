#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cfloat>
#include <cmath>
#include <ctime>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

struct Node {
	int x;
	int y;
	int t;
	double v;
	Node() {}
	Node(int x, int y, int t, double v) : x(x), y(y), t(t), v(v) {
	}
	bool operator < (const Node& b) const {
		return v == b.v ? t > b.t : v < b.v ;
	}
};

int main() {
	int W,H;
	cin>>H>>W;
	vector<string> w(H);
	REP(y, H) cin>>w[y];
	priority_queue<Node> q;
	REP(y, H) REP(x, W) {
		if(w[y][x]=='s') q.push(Node(x, y, 0, 1e30));
	}
	
	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,1,-1};
	int ok=0;
	map<pair<int, int>, int> V;
	while(q.size()) {
		Node n = q.top();
		q.pop();
		if(V.count(MP(n.x, n.y)) && V[MP(n.x, n.y)] <= n.t) continue;
		V[MP(n.x, n.y)] = n.t;
		//cout<<n.x<<" "<<n.y<<" "<<n.t<<" "<<n.v<<endl;
		if(w[n.y][n.x]=='g') {
			cout<<setprecision(10)<<n.v<<endl;
			ok=1;
			break;
		}
		REP(dir, 4) {
			int X=n.x+dx[dir];
			int Y=n.y+dy[dir];
			if(0<=X && X<W && 0<=Y && Y<H && w[Y][X]!='#') {
				double nv = (double)(w[Y][X]-'0') * pow(0.99, n.t+1);
				nv = min(n.v, nv);
				if(V.count(MP(X, Y)) && V[MP(X, Y)] <= n.t+1) continue;
				q.push(Node(X, Y, n.t+1, w[Y][X]=='g' ? n.v : nv));
			}
		}
	}
	if(!ok) {
		cout<<-1<<endl;
	}
	
	return 0;
}
