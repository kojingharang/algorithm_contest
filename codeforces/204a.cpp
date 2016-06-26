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

ll ff(ll d) {
	if(d==0) return 0;
	if(d==1) return 1;
	ll ans=1;
	REP(i, d-2) ans*=10;
	return ans;
}

ll ref(ll v) {
	ll co=0;
	for(int i=1;i<=v;i++) {
		ll msd=i;
		while(msd/10>0) {msd/=10;}
		if(msd==i%10) co++;
	}
	//cout<<"ref "<<v<<" "<<co<<endl;
	return co;
}

ll f(ll v) {
	if(v<10) return ref(v);
	if(v==0) return 0;
	ll msd=v, co=0;
	while(msd/10>0) {msd/=10;co++;}
	ll msdd=msd;
	REP(i, co) msd*=10;
	//cout<<"f "<<v<<" "<<msdd<<" "<<msd<<endl;
	ll t=v, di=0;
	while(t>0) {t/=10;di++;}
	ll X = 0;
	int xok=0;
	{
		ll mm = (v-msd)/10;
		//cout<<"mm "<<mm<<endl;
		while(msd+(mm*10+msdd) > v && mm > 0) {
			mm--;
		}
		X = msd+(mm*10+msdd);
		if(X<=v) xok = 1;
		//cout<<"X "<<X<<" xok "<<xok<<endl;
	}
	ll vv= xok ? (X-msd)/10 +1 : 0;
	ll lower=0;
	REP(i, di) lower += 9*ff(i);
	//cout<<"vv: "<<vv<<" "<<v%10<<endl;
	//cout<<di<<" "<<ff(di)<<endl;
	ll ans= vv+(msdd-1)*ff(di)+lower;
	//cout<<vv<<" "<<msdd-1<<" "<<ff(di)<<" "<<lower<<endl;
	//cout<<"ans "<<ans<<endl;
	return ans;
}

int main() {
	//REP(i, 10000) {
	//	ll ra=ref(i);
	//	ll fa=f(i);
	//	if(ra!=fa) {cout<<"ERR"<<i<<" "<<ra<<" "<<fa<<endl;return 0;}
	//}
	
	ll L,R;
	while(cin>>L>>R) {
		//cout<<f(47)<<endl;
		cout<<f(R)-f(L-1)<<endl;
	}
	
	return 0;
}
