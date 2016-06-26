#include <vector>
#include <map>
#include <set>
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
#include <utility>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
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

int main() {
	int test_cases;
	cin>>test_cases;
	REP(ttt, test_cases) {
		int N, W, H;
		cin>>N>>W>>H;
		VI R(N);
		REP(i, N) cin>>R[i];
		//sort(ALLR(R));
		
		ll x=0, y=0;
		cout<<"Case #"<<ttt+1<<": ";
		ll ny=0, nym=-100000000;
		VI X(N), Y(N);
		REP(i, N) {
			if(x>W) {x=0;y=ny+R[i];}
			X[i]=x;
			if(y>0) y+=max(0LL, R[i]-(y-nym));
			Y[i]=y;
			//cout<<x<<" "<<y<<"   "<<max(ny, y+R[i])<<endl;
			x+=R[i];
			//cout<<"("<<x<<endl;
			if(i+1<N) x+=R[i+1];
			nym=ny;
			ny=max(ny, y+R[i]);
		}
		REP(i, N) REP(j, N) {
			if(i!=j && (X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]) < (R[i]+R[j])*(R[i]+R[j])) {
				cout<<"ERROR "<<i<<" "<<j<<"  ("<<X[i]<<"-"<<X[j]<<")**2 + ("<<Y[i]<<"-"<<Y[j]<<")**2 - ("<<R[i]<<"+"<<R[j]<<")**2"<<endl;
			}
		}
		REP(i, N) {
			if(X[i]>W || Y[i]>H) cout<<"ERROR "<<X[i]<<" "<<Y[i]<<endl;
		}
		REP(i, N) {
			cout<<X[i]<<" "<<Y[i];
			if(i+1<N) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
