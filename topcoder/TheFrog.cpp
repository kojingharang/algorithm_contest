// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Frog Jim is fond of jumping.
Moreover, all his jumps have the same length X.
Currently, he is standing at the point 0 on the real axis.
He needs to jump along the axis until he gets to point D or beyond it.

There are several pits between points 0 and D. 
For each valid i, there is a pit strictly between L[i] and R[i].
This means that Jim cannot step onto any point that is strictly between points L[i] and R[i].
(He is allowed to step onto the points L[i] and R[i]: as all pits are disjoint, the endpoints of each pit are always safe.)

Find the minimum length of jump X such that if Jim performs only jumps of length X, he can avoid every pit and get to point D or any point beyond it. Note that this length can be non-integer.

DEFINITION
Class:TheFrog
Method:getMinimum
Parameters:int, vector <int>, vector <int>
Returns:double
Method signature:double getMinimum(int D, vector <int> L, vector <int> R)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-D will be between 1 and 30,000, inclusive.
-L will contain between 1 and 50 elements, inclusive.
-Each element of L will be between 0 and D-1, inclusive.
-R will contain the same number of elements as L.
-The i-th element of R will be between L[i]+1 and D, inclusive.
-The intervals given by (L[i], R[i]) will not intersect.


EXAMPLES

0)
16
{2}
{7}

Returns: 7.0

Moving by jumps of length 7, Jim goes from point 0 to point 7, then to point 14 and then to point 21, which is beyond 16. If Jim chose a shorter jump, he would end up in the pit.

1)
25
{11, 3}
{21, 7}

Returns: 10.5

There are two pits. One of them is between points 11 and 21 and the other between points 3 and 7. By fixing jump length at 10.5, Jim successfully avoids them.

2)
100
{0}
{100}

Returns: 100.0

Jim has no other choice but to jump right to point 100.

3)
100
{0, 50}
{50, 100}

Returns: 50.0

In this case, point 50 is a suitable place to land, so Jim can choose X = 50.

4)
30000
{17, 25281, 5775, 2825, 14040}
{55, 26000, 5791, 3150, 14092}

Returns: 787.8787878787879



*/
// END CUT HERE
#line 87 "TheFrog.cpp"

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
#include <cassert>
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



class TheFrog {
	public:
	double getMinimum(int D, vector <int> L, vector <int> R) {
		double ans = D*2;
		REP(i, L.size()) { //50
			for(ll div=R[i];div>=1;div--) {//30000
				double mid=(double)R[i]/div;
				//if(mid < 1 || ans < mid) continue;
				int ok=1;
				REP(j, L.size()) {
					//double p0 = floor(L[j]/mid+1e-9)*mid;
					//if(p0+mid<L[j]-1e-9) p0+=mid;
					//double p0 = (int)(L[j]/mid)*mid;
					//ll lp1 = (L[j]*div/R[i]+1) * R[i];
					
					//int a0 = p0 + mid < R[j]-1e-9;
					//int a1 = lp1<R[j]*div;
					//if(a0!=a1) cout<<"DIFF "<<a0<<a1<<" "<<R[i]<<"/"<<div<<"="<<mid<<" ... LR[j] "<<L[j]<<" "<<R[j]<<" "<<p0<<" "<<floor(L[j]/mid+1e-9)*mid<<endl;
					
					//if(p0 + mid < R[j]-1e-9) {ok=0;break;}
					
					ll lp1 = (L[j]*div/R[i]+1) * R[i];
					if(lp1<R[j]*div) {ok=0;break;}
				}
				if(ok) {
					ans=min(ans, mid);
					break;
				}
			}
		}
		return ans;
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
void verify_case(const double& Expected, const double& Received) {
 double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, TheFrog().getMinimum(D, L, R));}
int main(){

CASE(0)
	int D = 16; 
	int L_[] = {2};
	  vector <int> L(L_, L_+sizeof(L_)/sizeof(*L_)); 
	int R_[] = {7};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	double _ = 7.0; 
END
CASE(1)
	int D = 25; 
	int L_[] = {11, 3};
	  vector <int> L(L_, L_+sizeof(L_)/sizeof(*L_)); 
	int R_[] = {21, 7};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	double _ = 10.5; 
END
CASE(2)
	int D = 100; 
	int L_[] = {0};
	  vector <int> L(L_, L_+sizeof(L_)/sizeof(*L_)); 
	int R_[] = {100};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	double _ = 100.0; 
END
CASE(3)
	int D = 100; 
	int L_[] = {0, 50};
	  vector <int> L(L_, L_+sizeof(L_)/sizeof(*L_)); 
	int R_[] = {50, 100};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	double _ = 50.0; 
END
CASE(4)
	int D = 30000; 
	int L_[] = {17, 25281, 5775, 2825, 14040};
	  vector <int> L(L_, L_+sizeof(L_)/sizeof(*L_)); 
	int R_[] = {55, 26000, 5791, 3150, 14092};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	double _ = 787.8787878787879; 
END
CASE(4)
	int D = 30000; 
	int L_[] = {
29949,29950,29951,29952,29953,29954,29955,29956,29957,29958,29959,29960,29961,29962,29963,29964,29965,29966,29967,29968,29969,29970,29971,29972,29973,29974,29975,29976,29977,29978,29979,29980,29981,29982,29983,29984,29985,29986,29987,29988,29989,29990,29991,29992,29993,29994,29995,29996,29997,29998,
	};
	  vector <int> L(L_, L_+sizeof(L_)/sizeof(*L_)); 
	int R_[] = {
29950,29951,29952,29953,29954,29955,29956,29957,29958,29959,29960,29961,29962,29963,29964,29965,29966,29967,29968,29969,29970,29971,29972,29973,29974,29975,29976,29977,29978,29979,29980,29981,29982,29983,29984,29985,29986,29987,29988,29989,29990,29991,29992,29993,29994,29995,29996,29997,29998,29999,
	};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	double _ = 1; 
END
CASE(3)
	int D = 6735;
	int L_[] = {4456, 6348, 103, 1096, 3495, 170, 5479};
	  vector <int> L(L_, L_+sizeof(L_)/sizeof(*L_)); 
	int R_[] = {4457, 6350, 107, 1100, 3498, 174, 5480};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	double _ = 4.473469387755102; 
END

}
// END CUT HERE
