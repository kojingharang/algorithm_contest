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
#define VVI vector<vector<int> >
#define PII pair<int, int> 
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

#define INF 100000000

ll GCD( ll a, ll b ) {
	if(a<b) {
		ll tmp=a;
		a=b; b=tmp;
	}
	ll c;
	while ( a != 0 ) {
		c = a; a = b%a;  b = c;
	}
	return b;
}
ll LCM( ll a, ll b ) {
	return a/GCD(a, b)*b;
}

int main() {
	int T;
	cin>>T;
	cin.ignore();
	REP(ttt, T) {
		int N, P1, W1, M, K, A, B, C, D;
		cin>>N>>P1>>W1>>M>>K>>A>>B>>C>>D;
		
		int ap=-1, aw=-1;
		{
			int p=P1, w=W1;
			for(int i=1;(ap==-1||aw==-1);i++) {
				//Pi+1 Wi+1
				p = ((A*p + B) % M) + 1;
				w = ((C*w + D) % K) + 1;
				if(p==P1) ap=i;
				if(w==W1) aw=i;
			}
			cout<<"period "<<ap<<" "<<aw<<endl;
		}
		
		VI mi(M, INF), ma(M);
		int p=P1, w=W1;
		mi[p-1]=min(mi[p-1], w);
		ma[p-1]=max(ma[p-1], w);
		cout<<p<<" "<<w<<endl;
		for(int i=1;i<N;i++) {
			p = ((A*p + B) % M) + 1;
			w = ((C*w + D) % K) + 1;
			cout<<p<<" "<<w<<endl;
			mi[p-1]=min(mi[p-1], w);
			ma[p-1]=max(ma[p-1], w);
		}
		cout<<mi<<endl;
		cout<<ma<<endl;
		
		int maxn=0, minn=0;
		int miw=INF, maw=0;
		REP(i, M) {
			if(mi[i]<miw) {
				minn++;
				miw=mi[i];
			}
		}
		for(int i=M-1;i>=0;i--) {
			if(ma[i]>maw) {
				maxn++;
				maw=ma[i];
			}
		}
		
		
		//cout<<"!!!!!!!!!!!!!!!!!!!!!!!! "<<ttt<<endl;
		//cout<<"M K "<<M<<" "<<K<<endl;
		//cout<<p<<" "<<w<<endl;
		//for(int i=1;i<N*10;i++) {
		//	//Pi+1 Wi+1
		//	p = ((A*p + B) % M) + 1;
		//	w = ((C*w + D) % K) + 1;
		//	cout<<p<<" "<<w<<endl;
		//}
		
		
		cout<<"Case #"<<ttt+1<<": "<<maxn<<" "<<minn<<endl;
break;
	}
	return 0;
}


