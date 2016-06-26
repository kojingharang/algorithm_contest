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
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
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
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define P(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")

ll naive(ll N, ll P, VI B) {
	ll ans = 0;
	REP(si, N) RANGE(ei, si+1, N+1) {
		ll lans = 0;
		RANGE(i, si, ei) lans+=B[i];
		if(lans<=P) {
//			cout<<"++ "<<si<<" "<<ei<<endl;
			ans++;
		}
	}
	return ans;
}

int main() {
	//ios::sync_with_stdio(false);
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		ll N, P;
		cin>>N>>P;
		VI B(N);
		REP(i, N) cin>>B[i];
		ll si=0, ei=0; // [si, ei)
		ll lastEi = 0;
		ll sum = 0;
		ll ans = 0;
		auto add = [&](int si, int ei) {
//			cout<<"fix "<<si<<" "<<ei<<" lastEi "<<lastEi<<endl;
			ll n = ei-si;
			ans += n * (n+1) / 2;
			ll nn = max(0LL, lastEi-si);
			ans -= nn*(nn+1)/2;
			lastEi = ei;
		};
		while(1) {
			// here sum <= P
			// expand
			while(1) {
				if(ei==N) {
					add(si, ei);
					ei++;
					break;
				}
				sum += B[ei];
				ei++;
				if(P<sum) {
					add(si, ei-1);
					break;
				}
			}
			if(N<ei) {
				break;
			}
			// here P<sum
			// shrink
			while(1) {
				assert(si<ei);
				sum -= B[si];
				si++;
				if(sum<=P) break;
			}
			// here sum <= P
		}
//		ll ref = naive(N, P, B);
//		if(ans!=ref) {
//			P(N);
//			P(P);
//			P(B);
//			P(ans);
//			P(ref);
//			assert(false);
//		}
		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		break;
	}
	
	return 0;
}
