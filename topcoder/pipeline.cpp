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

int limit = 500;

float ref(VF& d) {
	int loop=10000;
	float ans = FLT_MAX;
	REP(i, loop) {
		float y = (float)i*limit/loop;
		float l = 0;
		FOR(v, d) l+=fabsf(*v-y);
		ans=min(ans, l);
		//cout<<l<<endl;
	}
	return ans;
}

float solve(VF& d) {
	VF dd(d);
	sort(ALL(dd));
	float y = dd[dd.size()/2];
	float ans = 0;
	FOR(v, d) ans+=fabsf(*v-y);
	return ans;
}

int main() {
	int n=100;
	VF d(n);
	srand(time(NULL));
	REP(i, n) d[i] = ((float)rand()/RAND_MAX)*limit;
	float a0 = ref(d);
	float a1 = solve(d);
	cout<<a0<<" "<<a1<<endl;
	return 0;
}

