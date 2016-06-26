// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
John and Brus just built some towers using toy bricks.
They now have n towers numbered 0 through n-1.
For each i, the height of the i-th tower (0-based index) is given in heights[i].



John and Brus want to arrange their towers into a line.
That is, the bottoms of the towers will all stand on the same line.
John and Brus don't like it when a tower falls down and knocks over another tower while falling.
To avoid this, they have to put their towers sufficiently far apart.
More precisely, the distance between any two neighboring towers must be at least equal to the maximum of their heights.
John and Brus would like to minimize the distance between the first and the last tower in the line.



You are given the vector <int> heights.
Return a vector <int> containing exactly n elements: the order in which the towers should be placed on the line.
For each i, the i-th element of the return value should be the number of the tower that will be placed i-th on the line.
If there is a tie (multiple solutions give the same minimal distance), return the lexicographically smallest order.



DEFINITION
Class:TheBrickTowerMediumDivOne
Method:find
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> find(vector <int> heights)


NOTES
-A vector <int> A is lexicographically smaller than a vector <int> B if it contains a smaller element at the first position where these vector <int>s differ.


CONSTRAINTS
-heights will contain between 1 and 47 elements, inclusive.
-Each element of heights will be between 1 and 47 inclusive.


EXAMPLES

0)
{4, 7, 5}

Returns: {0, 2, 1 }

There are six possible orderings, but only four of them have optimal distance 12 between the first and the last towers:

{0, 2, 1}
{1, 0, 2}
{1, 2, 0}
{2, 0, 1}

Among these ordirings {0, 2, 1} is the lexicographically smallest one.


1)
{4, 4, 4, 4, 4, 4, 4}

Returns: {0, 1, 2, 3, 4, 5, 6 }

Towers may have equal heights.

2)
{2, 3, 3, 2}

Returns: {0, 3, 1, 2 }

Towers of height 2 have to be neighboring in the optimal ordering.

3)
{13, 32, 38, 25, 43, 47, 6}

Returns: {0, 6, 3, 1, 2, 4, 5 }

*/
// END CUT HERE
#line 83 "TheBrickTowerMediumDivOne.cpp"

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
#include <cassert>
#include <cctype>
#include <iomanip>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VS vector<string>
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class TheBrickTowerMediumDivOne {
	public:
	vector <int> find(vector <int> H) {
		int N=H.size();
		//sort(ALL(H));
		//int mi=100000000;
		//do {
		//	int v=0;
		//	REP(i, H.size()-1) v+=max(H[i], H[i+1]);
		//	cout<<H<<" -> "<<v<<endl;
		//	mi=min(mi,v);
		//} while(next_permutation(ALL(H)));
		//cout<<mi<<endl;
		int prev=H[0];
		vector<int> ans;
		vector<PII> rest;
		ans.PB(0);
		RANGE(i, 1, N) {
			if(prev >= H[i]) { ans.PB(i); prev=H[i]; }
			else rest.PB(MP(H[i], i));
		}
		sort(ALL(rest));
		//cout<<rest<<endl;
		FOR(e, rest) {
			ans.PB(e->second);
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
void verify_case(const vector <int>& Expected, const vector <int>& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, TheBrickTowerMediumDivOne().find(heights));}
int main(){

CASE(0)
	int heights_[] = {4, 7, 5};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int __[] = {0, 2, 1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	int heights_[] = {4, 4, 4, 4, 4, 4, 4};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int __[] = {0, 1, 2, 3, 4, 5, 6 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	int heights_[] = {2, 3, 3, 2};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int __[] = {0, 3, 1, 2 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	int heights_[] = {13, 32, 38, 25, 43, 47, 6};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int __[] = {0, 6, 3, 1, 2, 4, 5 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	int heights_[] = {40, 32, 38, 25, 43, 47, 6};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int __[] = {0, 6, 3, 1, 2, 4, 5 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	int heights_[] = {5,1,2,3,3,2,4,3,4,2,3,4};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int __[] = {5,1,2,3,3,2,4,3,4,2,3,4};
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END

}
// END CUT HERE
