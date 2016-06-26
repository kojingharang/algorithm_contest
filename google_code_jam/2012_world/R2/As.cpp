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
#define VI vector<int>
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
		int N;
		cin>>N;
		
		VI D(N), L(N);
		REP(i, N) {
			cin>>D[i]>>L[i];
		}
		int TA;
		cin>>TA;
		
		//cout<<"---"<<N<<endl;
		int pos=0;
		int idx=0;
		int ok=1;
		int reach = min(L[idx], D[idx]);
		int npos=-1;
		while(1) {
			npos = -1;
			int ni=-1;
			//cout<<idx<<" "<<pos<<"  "<<reach<<"  "<<endl;
			for(int i=idx+1; i<N; i++) {
				if(D[i] > pos+reach*2) break;
				int np = D[i]+min(L[i], abs(D[i]-(pos+reach)));
				//cout<<"  cand "<<np<<"  reach "<<min(L[i], D[i]-(pos+reach))<<endl;
				if(npos < np) {
					ni = i;
					npos = np;
				}
			}
			if(npos >= TA) break;
			//cout<<" -> "<<ni<<" "<<npos<<endl;
			if(ni==-1) {ok=0;break;}
			reach = min(L[ni], abs(D[ni]-(pos+reach)));
			idx=ni;
			pos=D[ni] - reach;
		}
		if(npos < TA) ok=0;
		cout<<"Case #"<<ttt+1<<": "<<(ok?"YES":"NO")<<endl;
	}
	return 0;
}
