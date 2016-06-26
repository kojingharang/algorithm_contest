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
#include <cassert>
#include <cctype>
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
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

enum {
	Zero,One,I,J,K
};

int s2i(char c) {
	switch(c) {
	case 'i': return I;
	case 'j': return J;
	case 'k': return K;
	}
	assert(false);
}
int i2s(int v) {
	switch(v) {
	case -One: return '-';
	case One: return '1';
	case -I: return 'I';
	case I: return 'i';
	case -J: return 'J';
	case J: return 'j';
	case -K: return 'K';
	case K: return 'k';
	}
	assert(false);
}

int table[] = {
	One,I,J,K,
	I,-One,K,-J,
	J,-K,-One,I,
	K,J,-I,-One,
};
inline int mul(int a, int b) {
	int sign = 1;
	if(a<0) {sign*=-1;a*=-1;}
	if(b<0) {sign*=-1;b*=-1;}
	return sign * table[(a-1)*4+(b-1)];
}

int main() {
	int test_cases;
	cin>>test_cases;
	ll L,X;
	string s;
//	cout<<"I*I "<<string(1, i2s(mul(I, I)))<<endl;
//	cout<<"I*J "<<string(1, i2s(mul(I, J)))<<endl;
//	cout<<"I*K "<<string(1, i2s(mul(I, K)))<<endl;
	REP(ttt, test_cases) {
		cin>>L>>X>>s;
//		cerr<<"BEGIN "<<L<<" "<<X<<endl;
		ll N=L*X;
		ll Cut = L*4+10;
//		cout<<"Cut "<<Cut<<endl;
		VI vs(s.size());
		REP(i, s.size()) vs[i] = s2i(s[i]);
		bool ans = false;
		if(N>=3) {
			int lall = One;
			REP(i, L) lall=mul(lall, vs[i]);
			ll x=X;
			int all = One;
			int po = lall;
			while(x) {
				if(x&1) all = mul(all, po);
				po=mul(po, po);
				x/=2;
			}
			int vi = One;
			REP(i, min(Cut, N-2)) {
				vi = mul(vi, vs[i%L]);
				if(vi==I) {
					int vj = One;
					RANGE(j, i+1, min(Cut, N-1)) {
						vj = mul(vj, vs[j%L]);
						if(vj==J) {
							// I*J*X=All
							if(mul(mul(I, J), K) == all) {
								ans = true;
								goto END;
							}
						}
					}
				}
			}
		}
END:
//		int pe = L*4;
//		RANGE(i, 1, (X+3)/4) {
//			REP(j, pe) {
//				int i0 = pe+j;
//				int i1 = i*pe+j;
//				if(i0<N-2 && i1<N-2) {
//					if(okI[i0]!=okI[i1]) {cout<<"!!! okI "<<i0<<" "<<i1<<" "<<okI<<endl;fflush(stdout);assert(0);}
//					if(okJ[i0]!=okJ[i1]) {cout<<"!!! okJ "<<i0<<" "<<i1<<" "<<okJ<<endl;fflush(stdout);assert(0);}
//					if(okK[i0]!=okK[i1]) {cout<<"!!! okK "<<i0<<" "<<i1<<" "<<okK<<endl;fflush(stdout);assert(0);}
//				}
//			}
//		}
//		cerr<<"okI "<<okI<<endl;
//		cerr<<"okJ "<<okJ<<endl;
//		cerr<<"okK "<<okK<<endl;
		cout<<"Case #"<<ttt+1<<": "<<(ans?"YES":"NO")<<endl;
//		return 0;
	}
	return 0;
}



