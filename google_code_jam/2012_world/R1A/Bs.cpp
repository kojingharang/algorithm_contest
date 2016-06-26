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
#include <cfloat>
#include <cmath>
#include <ctime>
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

int ref(int N, vector<PII> a, vector<PII> b) {
	int ans = 2*N+1;
	REP(i, 1<<N) {
		vector<PII> w;
		int lans=2*N;
		REP(j, N) {
			if((i>>j)&1) {w.PB(MP(b[j].first,2));lans--;}
			else {w.PB(MP(a[j].first, 1));}
			w.PB(MP(b[j].first, 2));
		}
		sort(ALL(w));
		int ok=1;
		REP(j, N*2) if(w[j].first>j) ok=0;
		if(ok) ans=min(ans, lans);
		if(ok) {
//			cout<<w<<" "<<ok<<" "<<lans<<endl;
		}
	}
	return 2*N+1==ans ? -1 : ans;
}

int f(int N, vector<PII>& a, vector<PII>& b) {
	VI lvl(N);
//	sort(ALL(a));
	sort(ALL(b));
	int cur=0;
	int ok=1;
	int ans=0;
	REP(i, N) {
		REP(ai, N) {
			if(cur >= b[i].first) break;
			// find appropriate star1
			int idx=-1, maxb=-1;
			REP(j, N) {
				if(cur >= a[j].first && lvl[j]==0 && maxb < a[j].second) {
					idx=j;
					maxb = a[j].second;
				}
			}
			if(idx!=-1) {
				cur++;
				lvl[idx]=1;
//				cout<<"use 1 in "<<a[ai].first<<" "<<b[i].first<<endl;
				ans++;
			} else break;
		}
		if(cur < b[i].first) { ok=0; break; }
		cur+=lvl[b[i].second]==1 ? 1 : 2;
		lvl[b[i].second]=2;
	}
	return ok?N+ans:-1;
}

int main() {
	int test_cases;
	cin>>test_cases;
	REP(ttt, test_cases) {
		int N;
		cin>>N;
		vector<PII> a(N), b(N);
		REP(i, N) {
			cin>>a[i].first>>b[i].first;
			a[i].second = b[i].first;
			b[i].second=i;
		}
		int F = f(N, a, b);
//		int Ref = ref(N, a, b);
//		if(F!=Ref) {
//			cout<<"DIFF Case #"<<ttt+1<<" "<<F<<" "<<Ref<<endl;
//		}
		if(F!=-1) cout<<"Case #"<<ttt+1<<": "<<F<<endl;
		else cout<<"Case #"<<ttt+1<<": Too Bad"<<endl;
	}
	return 0;
}
