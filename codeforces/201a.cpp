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
	int X;
	
	while(cin>>X) {
		for(int n=1;;n++) {
			//cout<<n<<endl;
			{
				int x = X;
				int n4 = (n-1)*(n-1)/2;
				int n2 = ((n-1)/2 + ((n-1)&1))*2;
				int n1 = 0;
				//cout<<n4<<" "<<n2<<" "<<n1<<endl;
				while(n4-->0 && x>=4) x-=4;
				while(n2-->0 && x>=2) x-=2;
				while(n1-->0 && x>=1) x-=1;
				if(x==0) { cout<<2*n-1<<endl; break; }
			}
			{
				int x = X;
				int n4 = (n-1)*(n-1)/2 + ((n-1)*(n-1)&1);
				int n2 = (n-1)/2*2;
				int n1 = 1;
				//cout<<n4<<" "<<n2<<" "<<n1<<endl;
				while(n4-->0 && x>=4) x-=4;
				while(n2-->0 && x>=2) x-=2;
				while(n1-->0 && x>=1) x-=1;
				if(x==0) { cout<<2*n-1<<endl; break; }
			}
		}
	}
	
	return 0;
}
