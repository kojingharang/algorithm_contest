// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Fox Ciel has some items. The weight of the i-th (0-based) item is item[i]. She wants to put all items into bins.


The capacity of each bin is 300. She can put an arbitrary number of items into a single bin, but the total weight of items in a bin must be less than or equal to 300.


You are given the vector <int> item. It is known that the weight of each item is between 100 and 300, inclusive. Return the minimal number of bins required to store all items.


DEFINITION
Class:BinPacking
Method:minBins
Parameters:vector <int>
Returns:int
Method signature:int minBins(vector <int> item)


CONSTRAINTS
-item will contain between 1 and 50 elements, inclusive.
-Each element of item will be between 100 and 300, inclusive.


EXAMPLES

0)
{150, 150, 150, 150, 150}

Returns: 3

You have five items and each bin can hold at most two of them. You need at least three bins.

1)
{130, 140, 150, 160}

Returns: 2

For example, you can distribute the items in the following way:

Bin 1: 130, 150
Bin 2: 140, 160



2)
{100, 100, 100, 100, 100, 100, 100, 100, 100}

Returns: 3



3)
{100, 200, 100, 100, 100, 100, 200, 100, 200}

Returns: 4



4)
{157, 142, 167, 133, 135, 157, 143, 160, 141, 123, 162, 159, 165, 137, 138, 152}

Returns: 8



******************************/
// END CUT HERE
#line 71 "BinPacking.cpp"
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

class BinPacking {
	public:
	int minBins(vector <int> item) {
		int N=item.size();
		sort(ALLR(item));
		VI used(N);
		VI mI(3);
		int ans=0;
		REP(loop, 100) {
			int Min=100000;
			mI[0]=-1;
			REP(i, N) {
				if(used[i]) continue;
				RANGE(j, i+1, N+1) {
					if(j<N && used[j]) continue;
					RANGE(k, j+1, N+1) {
						if(k<N && used[k]) continue;
						int sum=item[i];
						if(j<N) sum+=item[j];
						if(k<N) sum+=item[k];
						if(sum <= 300 && 300-sum < Min) {
							cout<<sum<<" "<<Min<<endl;
							mI[0]=i;
							mI[1]=j;
							mI[2]=k;
							Min = 300-sum;
						}
					}
				}
			}
			cout<<mI<<endl;
			if(mI[0]==-1) break;
			ans++;
			REP(i, 3) if(mI[i]<N) used[mI[0]]=1;
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
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, BinPacking().minBins(item));}
int main(){

CASE(0)
	int item_[] = {200,70,50,50,45,45,45,45,25,25};
	  vector <int> item(item_, item_+sizeof(item_)/sizeof(*item_)); 
	int _ = 2; 
END
CASE(0)
	int item_[] = {150, 150, 150, 150, 150};
	  vector <int> item(item_, item_+sizeof(item_)/sizeof(*item_)); 
	int _ = 3; 
END
CASE(1)
	int item_[] = {130, 140, 150, 160};
	  vector <int> item(item_, item_+sizeof(item_)/sizeof(*item_)); 
	int _ = 2; 
END
CASE(2)
	int item_[] = {100, 100, 100, 100, 100, 100, 100, 100, 100};
	  vector <int> item(item_, item_+sizeof(item_)/sizeof(*item_)); 
	int _ = 3; 
END
CASE(3)
	int item_[] = {100, 200, 100, 100, 100, 100, 200, 100, 200};
	  vector <int> item(item_, item_+sizeof(item_)/sizeof(*item_)); 
	int _ = 4; 
END
CASE(4)
	int item_[] = {157, 142, 167, 133, 135, 157, 143, 160, 141, 123, 162, 159, 165, 137, 138, 152};
	  vector <int> item(item_, item_+sizeof(item_)/sizeof(*item_)); 
	int _ = 8; 
END

}
// END CUT HERE
