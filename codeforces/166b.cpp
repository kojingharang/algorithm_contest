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

#define INF 2000000000

class LessFoo {
public:
	bool operator()(const PII& a, const PII& b) const {
		return a.first < b.first;
	}
};

int main() {
	int N, M;
	cin>>N;
	
	vector<PII> A(N);
	int Axmin=INF, Axmax=-INF;
	REP(i, N) {
		cin>>A[i].first>>A[i].second;
		Axmin=min(Axmin, A[i].first);
		Axmax=max(Axmax, A[i].first);
	}
	cin>>M;
	vector<PII> B(M);
	int xmin=INF, xmax=-INF;
	REP(i, M) {
		cin>>B[i].first>>B[i].second;
		xmin=min(xmin, B[i].first);
		xmax=max(xmax, B[i].first);
	}
	if(xmin <= Axmin || Axmax <= xmax) {
		cout<<"NO"<<endl;
		return 0;
	}
	sort(ALL(B));
	
	REP(i, N) {
		int x0 = A[i].first;
		int x1 = A[(i+1)%N].first;
		int y0 = A[i].second;
		int y1 = A[(i+1)%N].second;
		if(x0==x1) continue;
		int i0 = distance(B.begin(), lower_bound(ALL(B), MP(x0, -INF), LessFoo()));
		int i1 = distance(B.begin(), lower_bound(ALL(B), MP(x1, -INF), LessFoo()));
		//cout<<i<<"   "<<A[i].first<<" "<<A[(i+1)%N].first<<" "<<i0<<" "<<i1<<endl;
		
		for(int i=i0;i<i1;i++) {
			double x = B[i].first;
			double y = B[i].second;
			if(!( y < ((double)y1-y0)/(x1-x0)*(x-x0)+y0 )) {
				cout<<"NO"<<endl;
				return 0;
			}
		}
		for(int i=i1;i<i0;i++) {
			double x = B[i].first;
			double y = B[i].second;
			//cout<<x<<" "<<y<<endl;
			//cout<<x0<<" "<<y0<<endl;
			//cout<<x1<<" "<<y1<<endl;
			//cout<<(y - y0)<<" "<<(y1-y0)*(x-x0)<<endl;
			if(!( y > ((double)y1-y0)/(x1-x0)*(x-x0)+y0 )) {
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	
	return 0;
}
