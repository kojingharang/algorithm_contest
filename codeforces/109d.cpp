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

int main() {
	int N,M;
	cin>>N>>M;
	//map<int, int> pst;
	vector<int> pst(N+1);
	vector<char> st(N);
	//scanf("\n");
	REP(i, M) {
		char si;
		int k=0;
		//scanf("%c", &si);
		//scanf("%d", &k);
		//scanf("\n");
		cin>>si>>k;
		//cout<<"------ "<<si<<" "<<k<<endl;
		if(si=='-') {
			if(st[k-1]==0) {
				cout<<"Already off"<<endl;
			} else {
				for(int v=1;v*v<=k;v++) {
					if(k%v==0) {
						pst[v]=0;
						pst[k/v]=0;
					}
				}
				cout<<"Success"<<endl;
				st[k-1]=0;
			}
		} else {
			if(st[k-1]==1) {
				cout<<"Already on"<<endl;
			} else {
				int ok=1;
				for(int v=1;v*v<=k;v++) {
					if(k%v==0) {
						if((v!=1 && pst[v]) || (k/v!=1 && pst[k/v])) {
							ok=0;
							cout<<"Conflict with "<<((v!=1 && pst[v])?pst[v]:pst[k/v])<<endl;
							break;
						}
					}
				}
				if(ok) {
					for(int v=1;v*v<=k;v++) {
						if(k%v==0) {
							pst[v]=k;
							pst[k/v]=k;
						}
					}
					cout<<"Success"<<endl;
					st[k-1]=1;
				}
			}
		}
	}
	
	return 0;
}
