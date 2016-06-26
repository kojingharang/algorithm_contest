// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// King Dengklek once planted N trees, conveniently numbered 0 through N-1, along the main highway in the Kingdom of Ducks. As time passed, the trees grew beautifully. Now, the height of the i-th tree is heights[i] units.

King Dengklek now thinks that the highway would be even more beautiful if the tree heights were in strictly ascending order. More specifically, in the desired configuration the height of tree i must be strictly smaller than the height of tree i+1, for all possible i. To accomplish this, King Dengklek will cast his magic spell. If he casts magic spell of level X, he can increase or decrease the height of each tree by at most X units. He cannot decrease the height of a tree into below 1 unit. Also, the new height of each tree in units must again be an integer.

Of course, a magic spell of a high level consumes a lot of energy. Return the smallest possible non-negative integer X such that King Dengklek can achieve his goal by casting his magic spell of level X.

DEFINITION
Class:KingdomAndTrees
Method:minLevel
Parameters:vector <int>
Returns:int
Method signature:int minLevel(vector <int> heights)


CONSTRAINTS
-heights will contain between 2 and 50 elements, inclusive.
-Each elements of heights will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{9, 5, 11}

Returns: 3

One possible solution that uses magic spell of level 3:

Decrease the height of the first tree by 2 units.
Increase the height of the second tree by 3 units.

The resulting heights are {7, 8, 11}.

1)
{5, 8}

Returns: 0

These heights are already sorted in strictly ascending order.

2)
{1, 1, 1, 1, 1}

Returns: 4

Since King Dengklek cannot decrease the heights of the trees below 1, the only possible solution is to cast his magic spell of level 4 to transform these heights into {1, 2, 3, 4, 5}.

3)
{548, 47, 58, 250, 2012}

Returns: 251



*/
// END CUT HERE
#line 61 "KingdomAndTrees.cpp"

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
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
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

#define INF (1LL<<60)

int N;
VI w;
ll ans;
void f(int idx) {
	ll d=0;
	for(int i=idx; i<N; i++) {
		d = max(d, w[idx]+(i-idx) - w[i]);
	}
	cout<<"f "<<idx<<" "<<d<<endl;
	ll off = d/2;
	off = min(off, w[idx]-1);
	//ans = max(ans, d-off);
	ans += d-off;
	w[idx] -= off;
	cout<<"d   "<<d<<endl;
	cout<<"off "<<off<<endl;
	cout<<"d-off "<<d-off<<endl;
	for(int i=idx+1; i<N; i++) {
		w[i] = max(w[i-1]+1, w[i]-off);
		//w[i] = w[i-1]+1;
	}
}

ll ABS(ll v) {
	return v>=0 ? v : -v;
}

class KingdomAndTrees {
	public:
	int minLevel(vector <int> H) {
		N = H.size();
		w = VI(N);
		ans = 0;
		REP(i, N) w[i] = H[i];
		VI ww(w);
		
		for(int i=N-2;i>=0;i--) {
			if(w[i]>w[i+1] || i==0) f(i);
		}
		cout<<w<<endl;
		ll an=0;
		REP(i, N) {
			an = max(an, ABS(w[i]-ww[i]));
		}
		return an;
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
#define END	 verify_case(_, KingdomAndTrees().minLevel(heights));}
int main(){

CASE(0)
	int heights_[] = {9, 5, 11};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int _ = 3; 
END
CASE(1)
	int heights_[] = {5, 8};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int _ = 0; 
END
CASE(2)
	int heights_[] = {1, 1, 1, 1, 1};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int _ = 4; 
END
CASE(3)
	int heights_[] = {548, 47, 58, 250, 2012};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int _ = 251; 
END
CASE(2)
	int heights_[] = {2, 1, 1, 1, 1};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int _ = 4; 
END
CASE(2)
	int heights_[] = {2, 10, 2, 2};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int _ = 5; 
END
CASE(2)
	int heights_[] = {
1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000
};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int _ = 25; 
END

}
// END CUT HERE
