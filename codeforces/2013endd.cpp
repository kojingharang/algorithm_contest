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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")



#define MOD 1000000007LL
#define INF (1LL<<60)

int main() {
	ios::sync_with_stdio(false);
	ll K,X,N,M;
	while(cin>>K>>X>>N>>M) {
		// ??? ???
		// ??A C??
		// C?? ??A
		// C?A C?A
		string fa, fb;
		int found=0;
		string tb="ZAC";
		REP(bits, 81) {
			int pat[4];
			int _bits=bits;
			REP(i, 4) {pat[i]=_bits%3; _bits/=3;}
			int restA=N-(bool)pat[0]-(bool)pat[1];
			int restB=M-(bool)pat[2]-(bool)pat[3];
			if(restA<0) continue;
			if(restB<0) continue;
			string tryA="XX";
			string tryB="XX";
			string htnxt="XX";
			string hta="XX";
			string htb="XX";
			REP(k, 2) tryA[k]=tb[pat[k]];
			REP(k, 2) tryB[k]=tb[pat[2+k]];
			if(N==1) tryA[tryA[0]=='X'?0:1] = tryA[tryA[0]=='X'?1:0];
			if(M==1) tryB[tryB[0]=='X'?0:1] = tryB[tryB[0]=='X'?1:0];
			REP(na, restA/2+1) REP(nb, restB/2+1) {
				REP(i, 2) hta[i]=tryA[i];
				REP(i, 2) htb[i]=tryB[i];
				ll ans=0;
				ll ca=na, cb=nb;
				RANGE(loop, 3, K+1) {
					ans = ca+cb;
					if(hta[1]=='A' && htb[0]=='C') ans++;
					htnxt[0] = hta[0];
					htnxt[1] = htb[1];
					
					ca=cb;
					cb=ans;
					REP(i, 2) hta[i]=htb[i];
					REP(i, 2) htb[i]=htnxt[i];
				}
//				cout<<"try "<<ans<<"   "<<tryA<<" "<<tryB<<" "<<na<<" "<<nb<<endl;
				if(ans==X) {
//					cout<<"OK "<<ans<<"   "<<tryA<<" "<<tryB<<" "<<na<<" "<<nb<<endl;
					string sa(N, 'Z'), sb(M, 'Z');
					sa[0]=tryA[0];
					sa[N-1]=tryA[1];
					sb[0]=tryB[0];
					sb[M-1]=tryB[1];
					REP(j, na) {sa[(bool)pat[0]+j*2]='A';sa[(bool)pat[0]+j*2+1]='C';}
					REP(j, nb) {sb[(bool)pat[2]+j*2]='A';sb[(bool)pat[2]+j*2+1]='C';}
					found=1;
					fa=sa,fb=sb;
					goto END;
				}
			}
		}
		END:
		if(found) cout<<fa<<endl<<fb<<endl;
		else cout<<"Happy new year!"<<endl;
		break;
	}
	
	return 0;
}





