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
#define VI vector<ll>
#define VVI vector<vector<ll> >
#define PII pair<int, int> 
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
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

#define INF 1000000000LL

int N;
string S;
int pos;
VI th(10000);
VI work(10000);

void merge(int s0, int e0, int s1, int e1) {
	int head=s0;
	int wpos=0;
	
	while(e0-s0>0 && e1-s1>0) {
		if(S[pos++]=='1') {
			work[wpos++] = th[s0++];
		} else {
			work[wpos++] = th[s1++];
		}
	}
	while(e0-s0>0) work[wpos++] = th[s0++];
	while(e1-s1>0) work[wpos++] = th[s1++];
	REP(i, wpos) th[head+i] = work[i];
}

// [s, e)
void merge_sort(int s, int e) {
	int L = e-s;
	if(L<=1) return;
	
	int mid = s+L/2;
	merge_sort(s, mid);
	merge_sort(mid, e);
	merge(s, mid, mid, e);
}
int checksum() {
	ll r = 1;
	REP(i, N) r = (31 * r + work[i]+1) % 1000003;
	return r;
}

int main() {
	int TT;
	cin>>TT;
	REP(tt, TT) {
		cin>>N>>S;
		pos = 0;
		REP(i, N) th[i]=i;
		merge_sort(0, N);
		REP(i, N) work[th[i]] = i;
		
		cout<<"Case #"<<tt+1<<": "<<checksum()<<endl;
	}
	return 0;
}


