#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
using namespace std;

#define ll long long
#define VI vector<int>
#define VF vector<float>
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }


bool f(VF& L, int K, float l) {
	int z=0;
	FOR(v, L) z+=*v/l;
	return K<=z;
}


float solve(VF& L, int K) {
	float hi=100000000,lo=0;
	REP(ii, 100) {
		cout<<lo<<" "<<hi<<endl;
		float mid=(lo+hi)/2;
		if(f(L, K, mid)) {
			lo=mid;
		} else {
			hi=mid;
		}
	}
	return lo;
}

int main() {
	VF L;
	L.push_back(8.02);
	L.push_back(7.43);
	L.push_back(4.57);
	L.push_back(5.39);
	cout<<solve(L, 1000)<<endl;
}
