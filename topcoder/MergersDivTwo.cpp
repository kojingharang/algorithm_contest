// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Warning: This problem statement contains superscripts and/or subscripts. It may not display properly outside of the applet.

The candy industry is going through a hard time in Byteland. Some of the biggest companies in the business have decided to perform a series of mergers so as to become one company in the end. Due to the depression, each merger should join at least k companies at once. Surprisingly, empirical studies conducted by the economists of Byteland have shown that the revenue of a company that is created by simultainously merging m (m >= k) companies with revenues equal to r0, r1, ..., rm - 1 is equal to the average of these revenues, that is (r0 + r1 + ... + rm - 1) / m.


You are given a vector <int> revenues. The revenue of the i-th of the companies that want to merge is equal to revenues[i]. Return the maximum possible revenue of the final company that can be created in any series of mergers that joins all the companies.

DEFINITION
Class:MergersDivTwo
Method:findMaximum
Parameters:vector <int>, int
Returns:double
Method signature:double findMaximum(vector <int> revenues, int k)


NOTES
-The returned value must have an absolute or relative error less than 10-9.
-Please note that the revenue of a company may be negative; this means that the company is actually losing money.
-It is always possible to merge all companies into a single one: for example, by merging all of them in a single step.


CONSTRAINTS
-revenues will contain between 2 and 50 elements, inclusive.
-Each element of revenues will be between -1,000 and 1,000, inclusive.
-k will be between 2 and the number of elements in revenues, inclusive.


EXAMPLES

0)
{5, -7, 3}
2

Returns: 1.5

The optimal way is to first merge companies 1 and 2, obtaining a company with total revenue -2, and then merge that company with company 0.

1)
{5, -7, 3}
3

Returns: 0.3333333333333333

The respective revenues are the same as in the previous example, but because k = 3, we have to merge all companies at once.

2)
{1, 2, 2, 3, -10, 7}
3

Returns: 2.9166666666666665

The solution is to first merge companies 0, 1, 2 and 4, and then merge the resulting company with companies 3 and 5.

3)
{-100, -100, -100, -100, -100, 100}
4

Returns: -66.66666666666667

Note that we can't merge less than six companies in the first step, because otherwise we would be left with only two or three companies and we would be unable to finish the merging process.

4)
{869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 510, -965, -826, 808, 890,
 -233, -881, 255, -709, 506, 334, -184, 726, -406, 204, -912, 325, -445, 440, -368}
7

Returns: 706.0369290573373



*/
// END CUT HERE
#line 77 "MergersDivTwo.cpp"

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
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T> v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }


class MergersDivTwo {
	public:
	double findMaximum(vector <int> R, int K) {
		int N = R.size();
		sort(ALL(R));
		vector<double> dp(N);
		dp[0] = R[0];
		for(int i=1;i<N;i++) {
			double v = -10000;
			for(int k=K;k<=N;k++) {
				if(i-k+1>=0) {
					//cout<<i-k+1<<" "<<i-k+2<<" "<<i+1<<" "<<k<<endl;
					v = max(v, (dp[i-k+1]+accumulate(&R[i-k+2], &R[i+1], 0))/(double)k);
				}
			}
			dp[i] = v;
		}
		cout<<dp<<endl;
		return dp[N-1];
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
 { os << "{ ";
   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const double& Expected, const double& Received) {
 double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, MergersDivTwo().findMaximum(revenues, k));}
int main(){

CASE(0)
	int revenues_[] = {5, -7, 3};
	  vector <int> revenues(revenues_, revenues_+sizeof(revenues_)/sizeof(*revenues_)); 
	int k = 2; 
	double _ = 1.5; 
END
CASE(1)
	int revenues_[] = {5, -7, 3};
	  vector <int> revenues(revenues_, revenues_+sizeof(revenues_)/sizeof(*revenues_)); 
	int k = 3; 
	double _ = 0.3333333333333333; 
END
CASE(2)
	int revenues_[] = {1, 2, 2, 3, -10, 7};
	  vector <int> revenues(revenues_, revenues_+sizeof(revenues_)/sizeof(*revenues_)); 
	int k = 3; 
	double _ = 2.9166666666666665; 
END
CASE(3)
	int revenues_[] = {-100, -100, -100, -100, -100, 100};
	  vector <int> revenues(revenues_, revenues_+sizeof(revenues_)/sizeof(*revenues_)); 
	int k = 4; 
	double _ = -66.66666666666667; 
END
CASE(4)
	int revenues_[] = {869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 510, -965, -826, 808, 890, -233, -881, 255, -709, 506, 334, -184, 726, -406, 204, -912, 325, -445, 440, -368};
	  vector <int> revenues(revenues_, revenues_+sizeof(revenues_)/sizeof(*revenues_)); 
	int k = 7; 
	double _ = 706.0369290573373; 
END
CASE(4)
	int revenues_[] = {
869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 
869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 
869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 
869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 
869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 
};
	  vector <int> revenues(revenues_, revenues_+sizeof(revenues_)/sizeof(*revenues_)); 
	int k = 2; 
	double _ = 706.0369290573373; 
END

}
// END CUT HERE
/*



869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
2

*/

