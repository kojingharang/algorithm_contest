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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

struct P{
	double x;
	double y;

	P(){
		x=0; y=0;
	}

	P(const double &s , const double &e)
		{ x=s; y=e;}

	P operator - (const P &t)
	{ return P(x-t.x , y-t.y); }

	P operator + (const P &t)
	{ return P(x+t.x , y+t.y); }

	P operator * (const double &d)
	{ return P(x*d , y*d); }

	void operator = (const P &t)
	{  x=t.x; y=t.y; }
};

double cross(P a,P b){
	return (a.x*b.y-a.y*b.x);
}

//const double eps = 1e-10;
//bool intersect_s(P a1 , P a2 , P b1 , P b2){
//	return ( cross(a2-a1 , b1-a1)*cross(a2-a1 , b2-a1) < eps) &&
//		   ( cross(b2-b1 , a1-b1)*cross(b2-b1 , a2-b1) < eps);
//}

int cross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
//	if((x1==x3 && y1==y3) || (x1==x4 && y1==y4) || (x2==x3 && y2==y3) || (x2==x4 && y2==y4)) return 1;
	// この最初のチェックがないと、(0 0 10 0) と (11 0 12 0) が交差と判定されてしまう。
	if(max(x1, x2) < min(x3, x4)) return 0;
	if(max(x3, x4) < min(x1, x2)) return 0;
	if(max(y1, y2) < min(y3, y4)) return 0;
	if(max(y3, y4) < min(y1, y2)) return 0;
	
	ll tc=(x1-x2)*(y3-y1)+(y1-y2)*(x1-x3);
	ll td=(x1-x2)*(y4-y1)+(y1-y2)*(x1-x4);
	ll ta=(x3-x4)*(y1-y3)+(y3-y4)*(x3-x1);
	ll tb=(x3-x4)*(y2-y3)+(y3-y4)*(x3-x2);
//	cout<<"XX "<<ta<<" "<<tb<<" "<<tc<<" "<<td<<endl;
	return tc*td<=0 && ta*tb<=0; // 接するときも交差とする
}

int main() {
	//ios::sync_with_stdio(false);
	ll N, NX, NY, QX, QY;
	while(cin>>N>>NX>>NY>>QX>>QY) {
//		cout<<"N "<<N<<endl;
		ll WAX, WAY, WBX, WBY;
		int ans = 1;
		REP(i, N-1) {
			cin>>WAX>>WAY>>WBX>>WBY;
			if(cross(NX, NY, QX, QY, WAX, WAY, WBX, WBY)) ans++;
//			if(intersect_s(P(NX, NY), P(QX, QY), P(WAX, WAY), P(WBX, WBY))) ans++;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
