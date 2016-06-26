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

int main() {
	ll N,K;
	cin>>N>>K;
	vector<ll> w(N);
	REP(i, N) {
		cin>>w[i];
	}
	sort(ALL(w));
	
	int B=(K-1)/N,E=(K-1)/N;
	for(int i=(K-1)/N;i>=0;i--) {
		if(w[i]!=w[(K-1)/N]) { B=i+1; break; }
	}
	for(int i=(K-1)/N;i<N*N;i++) {
		if(w[i]!=w[(K-1)/N]) { E=i-1; break; }
	}
	//cout<<B<<" "<<E<<endl;
	int i2 = ( ((K-1)/N-B)*N + (K-1)%N ) / (E-B+1);
	//cout<<w[(K-1)/N]<<" "<<w[i2]<<" "<<i2<<" "<<B<<" "<<E<<endl;
	cout<<w[(K-1)/N]<<" "<<w[i2]<<endl;
	
	return 0;
}
