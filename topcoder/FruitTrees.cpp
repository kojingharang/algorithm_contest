// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There is an infinitely long straight road.
Fox Ciel is going to plant trees of three kinds: apple trees, kiwi trees, and grape trees.
There will be infinitely many trees of each kind.
Trees of each kind will be placed along the entire road in regular intervals.


More precisely, you are given ints apple, kiwi, and grape with the following meaning:
The distance between any two consecutive apple trees must be apple, the distance between any two consecutive kiwi trees must be kiwi, and the distance between any two consecutive grape trees must be grape.


Ciel can only plant the trees at integer coordinates, but she gets to choose those coordinates as long as the above conditions are satisfied.
In other words, Ciel gets to choose three integers x, y, and z such that:

She plants apple trees at coordinates ..., x - 2 * apple, x - apple, x, x + apple, x + 2 * apple, ...
She plants kiwi trees at coordinates ..., y - 2 * kiwi, y - kiwi, y, y + kiwi, y + 2 * kiwi, ...
She plants grape trees at coordinates ..., z - 2 * grape, z - grape, z, z + grape, z + 2 * grape, ...

Ciel wants to maximize the distance between two closest trees (of any kind).
Return this distance.

DEFINITION
Class:FruitTrees
Method:maxDist
Parameters:int, int, int
Returns:int
Method signature:int maxDist(int apple, int kiwi, int grape)


CONSTRAINTS
-apple will be between 1 and 2,000, inclusive.
-kiwi will be between 1 and 2,000, inclusive.
-grape will be between 1 and 2,000, inclusive.


EXAMPLES

0)
1
5
8

Returns: 0

Apple trees will be planted at all integer coordinates, so at least two trees will be planted where a kiwi tree is planted.

1)
3
3
6

Returns: 1

One of the optimal solutions is as follows:

Plant apple trees at ..., -5, -2, 1, 4, ...
Plant kiwi trees at ..., -4, -1, 2, 5, ...
Plant grape trees at ..., -9, -3, 3, 9, ...




2)
40
30
20

Returns: 5



3)
899
1073
1147

Returns: 14



4)
2000
2000
2000

Returns: 666



*/
// END CUT HERE
#line 95 "FruitTrees.cpp"

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
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


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

class FruitTrees {
	public:
	int maxDist(int A, int K, int G) {
		VI w;
		cout<<"BEGIN"<<endl;
		w.PB(mD(A, K, G));
		w.PB(mD(A, G, K));
		w.PB(mD(K, A, G));
		w.PB(mD(K, G, A));
		w.PB(mD(G, A, K));
		w.PB(mD(G, K, A));
		sort(ALLR(w));
		return w[0];
	}
	int mD(int A, int K, int G) {
		ll lcm = LCM(A, LCM(K, G));
		cout<<"mD "<<lcm<<"  "<<A<<" "<<K<<" "<<G<<endl;
		
		int lo=0, hi=min(A, min(K, G))+1;
		while(lo+1<hi) {
			int mid = (lo+hi)/2;
			int ok=1;
			cout<<"mid: "<<mid<<endl;
			int Min=0;
			for(int a=lcm;a<2*lcm&&ok;a+=A) {
				int k0 = (a-mid)/K*K;
				Min = min(abs(k0+mid-a), abs(k0+K+mid-a));
				if(Min < mid) ok=0;
				cout<<"a-k "<<a<<" ... "<<k0+mid<<" "<<k0+mid+K<<" --- "<<Min<<endl;
				
				int g0 = (a-mid*2)/G*G;
				Min = min(abs(g0+mid*2-a), abs(g0+G+mid*2-a));
				if(Min < mid) ok=0;
				cout<<"a-g "<<a<<" ... "<<g0+mid*2<<" "<<g0+mid*2+G<<" --- "<<Min<<endl;
			}
			for(int k=lcm+mid;k<2*lcm+mid && ok;k+=K) {
				int g0 = (k-mid*2)/G*G;
				Min = min(abs(g0+mid*2-k), abs(g0+G+mid*2-k));
				if(Min < mid) ok=0;
				cout<<"k-g "<<k<<" ... "<<g0+mid*2<<" "<<g0+mid*2+G<<" --- "<<Min<<endl;
			}
			if(ok) lo=mid;
			else   hi=mid;
		}
		cout<<"ANS: "<<lo<<endl;
		return lo;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//mplate<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// os << "{ ";
// for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
// os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, FruitTrees().maxDist(apple, kiwi, grape));}
int main(){
CASE(3)
	int apple = 899; 
	int kiwi = 1073; 
	int grape = 1147; 
	int _ = 14; 
END
return 0;
CASE(0)
	int apple = 1; 
	int kiwi = 5; 
	int grape = 8; 
	int _ = 0; 
END
CASE(1)
	int apple = 3; 
	int kiwi = 3; 
	int grape = 6; 
	int _ = 1; 
END
//return 0;
CASE(2)
	int apple = 40; 
	int kiwi = 30; 
	int grape = 20; 
	int _ = 5; 
END
CASE(3)
	int apple = 899; 
	int kiwi = 1073; 
	int grape = 1147; 
	int _ = 14; 
END
CASE(4)
	int apple = 2000; 
	int kiwi = 2000; 
	int grape = 2000; 
	int _ = 666; 
END

}
// END CUT HERE
