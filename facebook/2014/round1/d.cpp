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
using namespace std;

#define EPS 1e-12
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

VI make_primes(int N) { // return all prime numbers less than N  memory: O(N) time: O(N^2)?
	VI p(N, 1), out;
	for(int i=2;i<N;i++) if(p[i]) { out.push_back(i); for(int j=i*2;j<N;j+=i) p[j]=0; }
	return out;
}

ll N, K, min_add;
VI w, nw, primes, bits;
ll co;

void f(int idx) {
	if(idx==N) {
		ll sum = 0;
//		cout<<"try "<<nw<<endl;
		co++;
		REP(i, N) sum += (nw[i]-w[i])*K;
		min_add = min(min_add, sum);
		return;
	}
	if(w[idx]==0 && idx==0) {
		f(idx+1);
		return;
	}
//	if(idx>0) nw[idx] = w[idx];
	if(idx>0) nw[idx] = max(nw[idx-1]+1, w[idx]);
	REP(ladd, 100) {
		int ok=1;
		REP(i, idx) {
			if(bits[nw[i]] & bits[nw[idx]]) ok=0;
		}
//		cout<<idx<<" "<<nw[idx]<<" "<<ok<<endl;
		if(ok) f(idx+1);
		if(ok && POPCOUNTLL(bits[nw[idx]])==1) break;
		nw[idx]++;
	}
}

// 任意のお年玉はKで割り切れないといけない。→そのように繰り上げ。さらに任意のx, yについてgcd(x/K,y/K)==1 じゃないといけない。
// 追加のコストの最小値を求めよ。
int main() {
	//ios::sync_with_stdio(false);
	if(0)
	{
		cout<<1000<<endl;
		REP(loop, 1000) {
			ll N=UNIFORM_LL(2, 21);
			ll K=UNIFORM_LL(1, 21);
			cout<<N<<" "<<K<<endl;
			REP(i, N) {
				cout<<UNIFORM_LL(1, 51)<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
	primes = make_primes(300);
	bits = VI(200);
	REP(i, bits.size()) {
		int v = i;
		REP(j, primes.size()) {
			if(v % primes[j]==0) { bits[i] |= 1LL<<j; v/=primes[j]; }
		}
	}
//	bits[0] = (1LL<<62)-1;
	bits[0] = 0;
	bits[1] = 1LL<<62;
//	cout<<bits<<endl;
//	cout<<primes.size()<<endl;
//	cout<<primes<<endl;
	int Cases;
	cin>>Cases;
	REP(CaseID, Cases) {
		cin>>N>>K;
		w = VI(N);
		REP(i, N) cin>>w[i];
		sort(ALL(w));
		ll pre=0;
		REP(i, N) {
			ll v = (w[i]+K-1)/K*K;
			pre += v - w[i];
			w[i] = v/K;
		}
//		cout<<"ans: "<<pre<<endl;
//		cout<<"w: "<<w<<endl;
		nw=w;
		min_add=1LL<<30;
		co=0;
		f(0);
		ll ref_ans = pre+min_add;
//		cerr<<co<<endl;
		
//		ll ans = 0;
//		{
//			nw=w;
//			REP(i, N) {
//				while(1) {
//					int ok=1;
//					REP(j, i) if(bits[nw[i]] & bits[nw[j]]) ok=0;
//					if(ok) break;
//					nw[i]++;
//				}
//			}
//			ll sum = 0;
//			REP(i, N) sum += (nw[i]-w[i])*K;
////			cout<<nw<<endl;
//			ans = pre + sum;
//		}
		cout<<"Case #"<<CaseID+1<<": "<<ref_ans<<endl;
//		cout<<"Case #"<<CaseID+1<<": "<<ans<<endl;
//		break;
	}
	
	return 0;
}
