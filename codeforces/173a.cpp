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

#define MOD 1000000007LL

int main() {
	int N;
	cin>>N;
	string A, B;
	cin>>A>>B;
	
	// RR RS RP SR SS SP PR PS PP
	int tA[9]={0,0,1,1,0,0,0,1,0};
	int tB[9]={0,1,0,0,0,1,1,0,0};
	int ansA=0;
	int ansB=0;
	int AB = A.size()*B.size();
	REP(i, AB) {
		char a = A[i%A.size()];
		char b = B[i%B.size()];
		// R > S > P
		int ai=0,bi=0;
		if(a=='S') ai=1;
		if(a=='P') ai=2;
		if(b=='S') bi=1;
		if(b=='P') bi=2;
		ansA += tA[ai*3+bi];
		ansB += tB[ai*3+bi];
	}
	ansA *= (N/AB);
	ansB *= (N/AB);
	for(int i=(N/AB)*AB;i<N;i++) {
		char a = A[i%A.size()];
		char b = B[i%B.size()];
		// R > S > P
		int ai=0,bi=0;
		if(a=='S') ai=1;
		if(a=='P') ai=2;
		if(b=='S') bi=1;
		if(b=='P') bi=2;
		ansA += tA[ai*3+bi];
		ansB += tB[ai*3+bi];
	}
	
	cout<<ansA<<" "<<ansB<<endl;
	
	return 0;
}
